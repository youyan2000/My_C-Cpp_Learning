# 运算符重载 Operator Overloading
overloading本质上就是赋予一个运算符以一个新的含义
我们用这个功能，只是为了让代码变得更好读，而不是让他变得更不可思议：如果你把`&`重载为除法，那是和意味啊
在没有这个功能时，我们只能用函数来实现

## 基础语法
`<返回值类型> operator<重载目标运算符>(<参数列表>) const{<函数实现>}`

e.g.
### 重载`+`
```cpp
Vector operator+(const Vector& other) const {
  return Vector(x + other.x , y + other.y);
}
```

### 重载`<<`和`>>`
```cpp
ostream& operator<<(ostream& os, const Vector& other) const {
  os << " ( " << other.x << " , " << other.y << " ) ";
  return os;
}

istream& operator>>(istream& is, Vector& other) {
  cout << "Please enter your vector: ";
  is >> other.x >> other.y;
  return is;
}
```

### 重载`==`和`!=`
```cpp
bool operator==(const Vector& other) const {
  return x == other.x && y == other.y;
}

bool operator!=(const Vector& other) const {
  return !(*this == other);
}
```

## 使用范围
### 可以重载的运算符

| 类别 | 运算符 |
|------|--------|
| 算术 | `+ - * / %` |
| 关系 | `== != < > <= >=` |
| 逻辑 | `&& || !` |
| 位运算 | `& | ^ ~ << >>` |
| 赋值 | `= += -= *= /= %= &= |= ^= <<= >>=` |
| 自增自减 | `++ --` |
| 下标 | `[]` |
| 函数调用 | `()` |
| 成员访问 | `-> ->*` |
| 逗号 | `,` |
| 解引用 | `* &` |

### 不能重载的运算符

| 运算符 | 说明 |
|--------|------|
| `::` | 作用域解析 |
| `.` | 成员访问（点运算符） |
| `.*` | 成员指针访问 |
| `?:` | 条件运算符 |
| `sizeof` | 大小运算符 |
| `typeid` | 类型信息 |
| `static_cast` 等 | 类型转换 |