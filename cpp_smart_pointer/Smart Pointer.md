下面我们用 **相同功能的几个典型场景**，把智能指针版和裸指针版放在一起对比，这样能直观看出代码层面的差异以及安全性的区别。

---

## 场景一：简单对象创建与释放

### 功能描述
在函数中创建一个动态对象，并在函数结束时释放。

#### 裸指针实现（需手动 `delete`）
```cpp
void raw_example() {
    Test* ptr = new Test();
    
    // ... 使用 ptr ...
    
    delete ptr;  // 必须手动释放，一旦忘了就泄漏
}
```
**潜在问题：**
- 如果中间部分提前 `return` 或抛出异常，`delete` 就执行不到 → 内存泄漏。

#### 智能指针实现（`unique_ptr`）
```cpp
void smart_example() {
    auto ptr = std::make_unique<Test>();
    
    // ... 使用 ptr ...
    
    // 离开作用域自动 delete，即使提前 return 或异常也安全
}
```

---

## 场景二：异常安全

### 功能描述
创建对象后调用一个可能抛出异常的函数，要求资源无论是否异常都必须释放。

#### 裸指针实现（需要 `try/catch` 补救）
```cpp
void raw_exception_unsafe() {
    Test* ptr = new Test();
    risky_operation();   // 可能 throw
    delete ptr;          // ❌ 若上面 throw，这行永远执行不到
}

// 想安全必须这样写：
void raw_exception_safe() {
    Test* ptr = new Test();
    try {
        risky_operation();
    } catch (...) {
        delete ptr;
        throw;           // 重新抛出
    }
    delete ptr;
}
```
**问题：** 代码臃肿，容易忘记 `catch` 中的清理。

#### 智能指针实现（自动安全）
```cpp
void smart_exception() {
    auto ptr = std::make_unique<Test>();
    risky_operation();   // 即使抛出异常，栈展开时 ptr 自动释放
}
```

---

## 场景三：所有权转移

### 功能描述
一个工厂函数创建对象，把所有权交给调用者。

#### 裸指针实现（语义不清晰，易错）
```cpp
Test* createRaw() {
    return new Test();   // 谁负责 delete？调用者容易忘记
}

void useRaw() {
    Test* p = createRaw();
    // 用 p ...
    delete p;   // 一旦忘记就泄漏；如果被返回/传递，管理混乱
}
```

#### 智能指针实现（`unique_ptr`，所有权明确）
```cpp
std::unique_ptr<Test> createSmart() {
    return std::make_unique<Test>();   // 所有权转移给调用者
}

void useSmart() {
    auto p = createSmart();   // 获得独占所有权，自动释放
}
```
**语义优势：** 返回值类型 `unique_ptr` 明确告诉调用者“你拥有它，且你是唯一的拥有者”。

---

## 场景四：共享所有权（多个使用者）

### 功能描述
多个对象共同持有一份资源，最后一个使用者负责释放。

#### 裸指针实现（需要手动引用计数）
```cpp
struct SharedRaw {
    Test* data;
    int* ref_count;   // 手动管理引用计数

    SharedRaw(Test* p) : data(p), ref_count(new int(1)) {}
    SharedRaw(const SharedRaw& other) 
        : data(other.data), ref_count(other.ref_count) {
        ++(*ref_count);
    }
    ~SharedRaw() {
        if (--(*ref_count) == 0) {
            delete data;
            delete ref_count;
        }
    }
};
```
**问题：**
- 需要自己实现拷贝构造、析构、赋值运算符（三/五法则）。
- 容易出错（例如忘记处理自赋值，或线程安全问题）。

#### 智能指针实现（`shared_ptr`，一行搞定）
```cpp
std::shared_ptr<Test> sp1 = std::make_shared<Test>();
std::shared_ptr<Test> sp2 = sp1;   // 引用计数增加
// 离开作用域自动减计数，归零时自动释放
```

---

## 场景五：循环引用处理

### 功能描述
两个对象互相引用，需要保证最终都能正确释放。

#### 裸指针实现（容易泄漏或需要手动打破循环）
```cpp
struct A;
struct B {
    A* a_ptr;
    ~B() { /* 需要知道是否该 delete a_ptr？混乱 */ }
};
struct A {
    B* b_ptr;
    ~A() { delete b_ptr; }  // 假如 A 拥有 B，但 B 又指回 A
};

// 创建后如果不手动断开引用，谁先析构都会有问题（二次delete或悬垂指针）
```

#### 智能指针实现（`shared_ptr` + `weak_ptr`）
```cpp
struct B;  // 前向声明
struct A {
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};
struct B {
    std::weak_ptr<A> a_ptr;   // 关键：weak_ptr 不增加强引用计数
    ~B() { std::cout << "B destroyed\n"; }
};

void test() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
    // 离开作用域，a 和 b 的强引用计数正确归零，均被销毁
}
```

---

## 场景六：容器中存放多态对象

### 功能描述
`vector` 里存放基类指针，指向派生类对象，要求容器销毁时自动释放所有对象。

#### 裸指针实现（必须遍历 `delete`）
```cpp
std::vector<Base*> vec;
vec.push_back(new Derived1());
vec.push_back(new Derived2());

// 容器销毁前必须手动清理
for (auto p : vec) {
    delete p;
}
vec.clear();
```
**问题：** 容易忘记清理；如果容器因为异常提前销毁，清理代码不会执行。

#### 智能指针实现（`unique_ptr` 自动清理）
```cpp
std::vector<std::unique_ptr<Base>> vec;
vec.push_back(std::make_unique<Derived1>());
vec.push_back(std::make_unique<Derived2>());

// 容器销毁时，每个 unique_ptr 自动 delete 所管理的对象
// 不需要任何额外代码
```

---

## 场景七：函数返回动态分配的数组

### 功能描述
函数返回一个在堆上分配的数组，长度由参数决定。

#### 裸指针实现（返回 `new[]` 的指针）
```cpp
int* createArrayRaw(int size) {
    return new int[size];   // 调用者必须记得 delete[]
}

void caller() {
    int* arr = createArrayRaw(10);
    // 用 arr ...
    delete[] arr;   // 必须用 delete[]，而不是 delete
}
```
**问题：**
- 容易混淆 `delete` 和 `delete[]`。
- 忘记释放就内存泄漏。

#### 智能指针实现（`unique_ptr` 支持数组）
```cpp
std::unique_ptr<int[]> createArraySmart(int size) {
    return std::make_unique<int[]>(size);
}

void caller() {
    auto arr = createArraySmart(10);
    arr[0] = 42;   // 支持下标访问
    // 自动调用 delete[]
}
```

---

## 总结对比表（功能场景角度）

| 功能场景 | 裸指针写法 | 智能指针写法 | 裸指针额外风险 |
|---------|-----------|-------------|--------------|
| 简单创建/销毁 | 必须配对 `new` / `delete` | `make_unique` / `make_shared` 自动 | 忘记 `delete`、异常不安全 |
| 异常安全 | 需要 `try/catch` 包裹 | 天然异常安全 | 代码膨胀，易遗漏清理 |
| 所有权转移 | 裸指针传递，语义不明 | `unique_ptr` 移动语义清晰 | 调用者不知道是否该释放 |
| 共享所有权 | 手动实现引用计数 | `shared_ptr` | 实现复杂，线程不安全 |
| 循环引用 | 需手动打破，极易泄漏 | `weak_ptr` 优雅解决 | 几乎无法安全手动管理 |
| 容器存放多态对象 | 遍历 `delete` | `vector<unique_ptr>` 自动 | 容器销毁时忘记清理 |
| 返回数组 | `new[]` / `delete[]` 易混淆 | `unique_ptr<T[]>` | 可能误用 `delete` 而非 `delete[]` |

### 现代 C++ 核心建议
> **只要能用智能指针，就不要写裸 `new` 和 `delete`。**  
> 这不仅是“偷懒”，而是从根本上消除了一整类内存管理 bug，让代码更简洁、更安全。