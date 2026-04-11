# 常量 CONST
const只是一个承诺，遵守承诺在编程这个规则的世界是好的，但是不遵守也并非完全不可以

## 常规定义
`const <变量类型> <变量名> = <变量值>` 全局不可再改动，必须初始化
`extern const <变量类型> <变量名>` 此地此变量不可改变

## 指针常量和常量指针
- const在*后，指针是const
```cpp
char * const q = "abc"; //q is const
*q = 'c';//OK
q++; //ERROR
```

- const在*前，变量是const
```cpp
char const * p = "abc"; //(*p) is const
*q = 'b';//ERROR
q++; //OK,but *p! = "abc"
```

## 常量成员函数
类里面定义的const成员函数，声称传给它的东西是只读的，即他不会修改传给它的东西

### 定义方法
```cpp
class entity{
  private:
    int m_X
  public:
    int GetX() const {
      return m_X;
    }
}
```

### 使用场景：常量引用作为函数参数 const Reference Parameter
当我们获得一个**常量对象 Const Object**，只能调用常量函数
```cpp
// 定义一个函数，参数是常量引用
void PrintEntity(const Entity& e) {
  e.GetX(); // 在这里调用成员函数 GetX()
}

class Entity {
    int m_X;
public:
    int GetX() const{ // 必须定义为const成员函数
        return m_X;
    }
};
```

### 特例
**mutable** 变量可以在 const 函数中修改
```cpp
class Entity {
  private:
    mutable int access_count;
    int m_X;
  public:
    int GetX() const {
      access_count++; // mutable 变量可以在 const 函数中修改
      return m_X;
    }
};
```

【番外】 **mutable**在**lambda**中的使用
```cpp
int x =8;
auto f = [=]() mutable{
  x++;
  std::cout << x << std::endl;
}
f();
//此时会输出9，但是x的值依旧为8
```