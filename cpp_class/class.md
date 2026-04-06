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

## 可见性 visible

public 在类对象作用域内，公共成员在类的外部是可访问的
private 
protected 

**class与structure的区别**
- class的成员默认是private；structure的成员默认是public
- structure常用于表达一种变量结构（如向量类）
- class常用 **继承 inheritance**

## static

### 结构体/类中的static
控制归属
不属于任何对象（实例），只属于类本身
内存中只有一份，所有对象共用这一个

### 结构体/类外的static
控制可见性
在链接阶段时，只在当前 .cpp 文件可见，别的文件看不见的私有全局变量
（`extern`在别的.cpp找定义去吧，这里仅仅是做一个声明）

### local static