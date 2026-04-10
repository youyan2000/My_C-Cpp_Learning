# 循环
循环本质上是为了解决重复的问题
## loops 基础语法
### for语句
```c
for ( init ; condition ; increment ){
  statement(s);
}
```
`init`初始化和声明变量，`condition`是判断是否继续循环的条件，`increment`是每次循环改变的计算式

### while语句
```c
while( condition ){
  statement(s);
}
```

### do语句
```c
do{
  statement(s);
}while( condition );
```

### 嵌套语句
所有的循环都可以进行嵌套，但是不建议，理由和条件控制相同。

## control flow 基础语法
### break语句
立即离开当前`{}`

### continue语句
跳过当前循环中的代码，强迫开始下一次循环

### goto语句
把控制无条件转移到同一函数内的被标记的语句，它可以设置在程序中 goto 语句的前面或者后面

### return语句
离开当前函数，并返回值

