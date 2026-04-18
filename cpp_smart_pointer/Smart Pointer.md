# 智能指针
智能指针 Smart Pointer 是一种包装了原始指针的对象。它们通过 RAII（资源获取即初始化）机制，自动管理指针生命周期，从而有效防止内存泄漏和野指针(悬空指针)
要使用他，你需要`# include <memory>`

## 核心优势
- 自动释放：超出作用域时自动析构并释放内存
- 异常安全：函数抛异常时也能确保资源被释放   
- 引用计数：通过内部计数器管理共享所有权（unique_ptr除外）

## 主要类型
### 1️⃣ unique_ptr 独占式拥有指针
与裸指针大小相同（8 字节），无额外性能损失
用法：
```cpp
std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
```
一个 `unique_ptr` 拥有一个对象的唯一所有权(`std::unique_ptr<MyClass> ptr0 = ptr;`是非法的)
不可拷贝,但可移动 move

### 2️⃣ shared_ptr 共享式拥有指针
为两个指针的大小：一个指向对象，一个指向控制块(储存引用计数)
引用计数：计算被引用的次数，当次数归零时指针死亡
用法：
```cpp
auto sp = std::make_shared<MyClass>();
/*或者*/
std::shared_ptr<MyClass> sharedptr = std::make_shared<MyClass>();
```
多个 `shared_ptr` 可以共享同一个对象，或者说，他是可引用的(`std::shared_ptr<MyClass> ptr0 = sharedptr;`是合法的)

### 3️⃣ weak_ptr 弱引用指针
`shared_ptr`的引用是一种强引用，他在引用的同时，增加引用计数，可以保障被引用指针不死亡
而 `weak_ptr` 是弱引用的，不增加引用计数，即使被引用指针死亡了，他也不会死亡 (所以使用弱引用指针时，我们通常需要时刻询问对象是否还存在)
用法：
```cpp
auto sp = std::make_shared<MyClass>();
std::weak_ptr<MyClass> wp = sp;
```
