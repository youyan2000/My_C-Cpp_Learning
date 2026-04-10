# 类
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

## 访问限制 setting limits(可见性)
public 全局课被调用
private 仅在成员函数内可以被调用
protected 子类和成员函数课调用

**class与structure的区别**
- class的成员默认是private；structure的成员默认是public
- structure常用于表达一种变量结构（如向量类）
- class常用 **继承 inheritance**

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

