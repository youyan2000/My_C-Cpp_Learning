# 循环语句

## 基础语法

### while语句```
```c
while(condition){
  statement(s);
}
```

### for语句
```c
for ( init; condition; increment ){
  statement(s);
}
```
`init`初始化和声明变量，`condition`是判断是否继续循环的条件，`increment`是每次循环改变的计算式

### do语句
```c
do{
  statement(s);
}while( condition );
```

### 嵌套语句
所有的循环都可以进行嵌套，但是不建议，理由和条件控制相同。