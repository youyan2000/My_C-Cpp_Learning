# 类 class
类本质上是一套采用封装的管理代码的方案，他把一部分管理工作交给编译器，而非人工的标识和说明

传参：
- C中通过结构体给函数传参
- C++中一个类中的变量就被当作一个结构体传入类中的函数

访问限制：
- C中通过.h文件中放公开的声明，.c文件中用static放私有的变量
- C++中可以在类里面的public放公开声明，private里放私有变量和函数

命名空间：
- C中靠函数名的区别区分不同物实体的构造实现和析构函数
- C++中可以通过不同的类的命名空间区分不同的物理实体

e.g.
c语言封装实现
```c
typedef struct{
  int32_t pin_num;
  bool light_level;
}led_t
static void pin_write(){};
void led_on(led_t *me){
  pin_write(me->p
---

in_num,
            me->light_level);
}
led_t red = {15 , 1};
led_on(&red);
```
c++封装实现
```cpp
class Led{
  private:
    void pin_write(){};
  public:
    int32_t pin_num;
    bool light_level;
    void on(){
      pin_write(this->pin_num,
                this->light_level);
    }
}
Led red (15 , 1);
red.on();
```

---

## 基本概念
**类 Class** 是把数据和功能组合在一起的一种方法
**对象 Object** 是类构成的变量
**实例 Instance** 是属于某个类的具体的变量

柏拉图意义上：
**Class** 是抽象的**理念 Form**
**Object** 是具体的**具体事物 Particular**
Particular **分有 participate** Form。
**Instance** 就是 **分有理念的个体**
（实例不对象，因为白马非马）

**class与structure的区别**
- class的成员默认是private；structure的成员默认是public
- structure常用于表达一种变量结构（如向量类）
- class常用 **继承 inheritance**

## 访问限制 setting limits(可见性 visiblity)
- public 全局课被调用
- private 仅在成员函数内可以被调用
- protected 子类和成员函数课调用

可见性不会影响代码本身的编译链接和可执行文件，只会影响人类读者和编辑者的读写

---

## static
### 结构体/类中的class static
控制**归属**
不属于任何对象（实例），只属于类本身
内存中只有一份，所有对象共用这一个
调用方式：`类名::对象名`

### 结构体/类外的class static
控制**可见性**
在链接阶段时，只在当前 .cpp 文件可见，别的文件看不见的私有全局变量
（`extern`在别的.cpp找定义去吧，这里仅仅是做一个声明）

### 函数内部的local static
**lifetime和scope**
变量的生存期**lifetime** : 变量实际存在的时间
变量的作用域**scope** : 可以访问变量的范围

local static : 生存期在整个程序，作用域在局部

---

##  构造函数Constructor 和 析构函数Destructor
### 构造函数 Constructor（战吼）
每构造一个类时，都自动会调用，以初始化对象

### 析构函数 Destructor（亡语）
每清除一个类时，卸载变量并清除内存
事实上并不常用，因为一般而言类离开了自己的生命周期会自己析构，但是当我们用new动态分配内存时，需要在析构函数中手动free内存

### e.g.
```c
#include <iostream>
using namespace std;
class Line{
  public:
    void setLength( double len );
    double getLength( void );
    Line();   // 构造函数声明
    ~Line();  // 析构函数声明
 
  private:
    double length;
};
// 成员函数定义
Line::Line(void){
    cout << "Object is being created" << endl;
}
Line::~Line(void){
    cout << "Object is being deleted" << endl;
}
void Line::setLength( double len ){
    length = len;
}
double Line::getLength( void ){
    return length;
}
int main( )
{
   Line line;
   // 设置长度
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
   return 0;
}
```

---

## 继承 inheritance
### 复用 reuse
允许一个相互关联的类的层次结构，防止代码重复
- parent / base / super class : 一个具有基本功能的基类
- child / derived / sub class : 从基类分离出来的派生类
`<子类名> : <父类名>`

### 虚函数 virtual function
#### 底层实现
Dynamic Dispatch 动态联编 通过**虚函数表**实现编译
虚函数表(v表) 包含基类所有虚函数的映射 ；编译时将他们映射到正确的 override function 复写函数

#### 实现成本
1. 额外的内存储蓄v表，基类中需要一个成员指针指向v表
2. 调用虚函数时需要遍历v表，以确定映射的函数

#### 定义方式
在基类函数前加入`virtual`，标记为虚函数，将函数加入虚函数表

#### 纯虚函数
基类的虚函数也必须要定义，除非它是**纯虚函数** pure virtual function
纯虚函数允许我们在基类不进行定义，并强制我们在派生类中实现它
纯虚函数的声明必须等于0
在其他语言，我们一般称之为**接口函数**interface function

衍生类的衍生类1，不可以重定义基类的纯虚函数，但是可以调用衍生类重写的函数

## 成员初始化列表 member initializer list
本质是为了简化初始化成员的过程,让初始化的过程变得更加清晰
```cpp
class Example {
  private:
    int a;
    const int b;   
  public:
    // 这里的 : a(x), b(y) 就是 member initializer list
    Example(int x, int y) : a(x), b(y) {
      // 构造函数体
    }
};
```
事实上，即使我们不使用成员初始化列表，而在构造函数内进行初始化，那么这个对象会被初始化两遍

---

## 初始化对象 intiial object
### 在栈上创建
#### 创建：
- 调用默认初始化函数创建，形如`<对象类型> <对象名>`
  e.g.
  ```cpp
  Entity entity
  ```
- 调用用户自定义初始化函数创建，形如`<对象类型> <对象名> = <对象类型> (<初始化参数>)`或`<对象类型> <对象名> (<初始化参数>)`
  e.g.
  ```cpp
  Entity entity = Entity (2026)
  //Entity entity (2026)
  ```

#### 利弊
优点：便捷，直观，自动分配和释放内存
弊端：不能在生存期外被调用，栈的内存有限需要节约

### 在堆上创建
我们总是需要在某个代码块外调用在代码块内建立的对象，所以需要在堆上手动创建和分配对象

#### 创建：
- 调用默认初始化函数创建，形如`<对象类型>* <对象名> = new <对象类型>`
  e.g.
  ```cpp
  Entity* entity = new Entity
  ```
- 调用用户自定义初始化函数创建，形如`<对象类型>* <对象名> = new <对象类型> (<初始化参数>)`
  e.g.
  ```cpp 
  Entity* entity = new Entity (2026)
  ```
  
#### 释放：`delete <对象名>`
  e.g.
  ```cpp
  delete entity
  ```

#### 隐式转换 Implicit Conversion
隐式转换就是程序员不进行显式指定时，编译器自动将一种类型转换为另一种类型
比方说
```cpp
/*整型提升*/
char c = 'A';
int i = c;           // char → int，'A'的ASCII码65
short s = 100;
int sum = s + c;     // short和char都提升为int

/*算术转换*/
int a = 10;
double b = 3.14;
double c = a + b;    // int → double，13.14
unsigned int u = 10;
int i = -20;
auto result = u + i; // i → unsigned int，结果很大
```
我们可以用此功能实现更直观地创建单参数的类，或者调用输入单参数类的函数
本质上是隐式转换调用了单参数的构造函数，传入了正确的参数
比方说
```cpp
class Entity {
private:
  int value;
public:
  Entity(int v) : value(v) { }  // 单参数构造函数
  int getValue() const { return value; }
};

void printEntity(const Integer& obj) {
  cout << obj.getValue() << endl;
}

int main() {
  Entity i = 100;    // 隐式转换：int → Integer

  printInteger(42);   // 隐式转换：int → Integer
  // 等价于：printInteger(Integer(42)) 
  return 0;
}
```

**explicit** : 禁用implicit
隐式转换有巨大的风险，为了避免风险，我们经常用explicit实现保护

---

## this
`this` 是一个隐式指针，指向当前对象本身。在每个非静态成员函数内部，编译器都会自动传入这个指针
`this` 本身是常量指针，不能修改它的指向

### 主要用途
#### a 区分参数和成员变量
```cpp
class Person {
  private:
    string name;
    int age;
    
  public:
    // 参数名和成员变量名相同时，必须用 this 区分
    void setName(string name) {
      this->name = name;  // this->name 是成员，name 是参数
    }
    
    void setAge(int age) {
      this->age = age;
    }
};

```

#### b 链式调用
```cpp
class Calculator {
  private:
    int value;
    
  public:
    Calculator() : value(0) {}
    
    Calculator& add(int x) {
      this->value += x;
      return *this;  // 返回当前对象的引用
    }
    
    Calculator& subtract(int x) {
      this->value -= x;
      return *this;
    }
    
    void display() {
      cout << "Value: " << value << endl;
    }
};

int main() {
  Calculator calc;
  calc.add(5).subtract(2).add(10);  // 链式调用
  calc.display();  // Value: 13
}
```

#### c 在成员函数中获取对象地址
```cpp
class Node {
public:
  Node* getAddress() {
    return this;  // 返回当前对象的地址
  }

  void compare(Node* other) {
    if (this == other) {
      cout << "同一个对象" << endl;
    }
  }
};
```

#### d 在赋值运算符中检测自赋值
```cpp
class String {
private:
    char* data;
    
public:
  String& operator=(const String& other) {
    if (this == &other) {  // 检测是否是自赋值
      return *this;
    }
    
    delete[] data;
    data = new char[strlen(other.data) + 1];
    strcpy(data, other.data);
    return *this;
  }
};
```

