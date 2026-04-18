# 拷贝构造函数
## 为什么需要**拷贝构造函数**
当我们需要复制一个实体类时
我们如果之间新建一个实体类使得他等于旧的字符串，那么我们复制的不仅仅是原实体类的内容，还有原实体类的指针，这是**浅复制**
**浅复制**的危险在于我们实际上只有同一件东西，只是在两个地方存储了他们，当我们修改任意一个时，另一个也会被修改
而**深复制**是复制其内容，不复制其指针，我们可以通过**拷贝构造函数 copy constructor**实现
**拷贝构造函数 copy constructor**就是一个构造函数，当我们复制实体类时，他会被调用

## 默认**拷贝构造函数**
**浅复制**是在调用c++默认的**拷贝构造函数**，他形如：
```cpp
String(const String& other)
  : m_Buffer(other.m_Buffer), m_Size(other.m_Size){
}
/*或者*/
String(const String& other){
  memcpy(this, &other, sizeof(String));
}
```

## 拒绝默认**拷贝构造函数**
如果我们仅仅是想要拒绝这样**浅复制**的发生，我们可以做形如：
```cpp
String(const String& other) = delete;
```
这就仿佛我们的的`unqiue_ptr`

## 写自己的**拷贝构造函数**
```cpp
MyString::MyString(const MyString& other)
    : m_Size(other.m_Size){
  m_Buffer = new char[m_Size + 1];
  memcpy(m_Buffer, other.m_Buffer, m_Size+1);
}
```
