# 选择结构

## 基础语法
**注**：
`{}`不是语法，不是运算，不是指令，它只是：编译器用来划定「一条指令」还是「多条指令」的范围标记。
CPU 根本看不到`{}`，只看到指令数量。
如果你只有一行命令需要执行，且程序简洁短小，不加`{}`是完全没有问题的。

### **if语句**
```c
if(boolean_expression){
  /* 如果布尔表达式为真将执行的语句 */
}
```

### **if-else语句**
```c
if(boolean_expression){
  /* 如果布尔表达式为真将执行的语句 */
}else{
  /* 如果布尔表达式为假将执行的语句 */
}
```

### **if-elseif语句**
```c
if(boolean_expression_1){
  /* 如果布尔表达式1为真将执行的语句 */
}else if(boolean_expression_2){
  /* 如果布尔表达式1为假且布尔表达式2为真将执行的语句 */
}else{
  /* 如果所有布尔表达式为假将执行的语句 */
}
```
**注**：
事实上，我们不能把elseif当做一种语法，他只是一个巧妙的省略了“{}”结构
`if{}else if{}`可以完全等同于`if{}else{if{}}`

### switch语句
```c
switch(expression){
  case constant-expression-1 :
    /* 如果 constant-expression-1 == expression实际值 将跳转至此 */
    break; // 可选的离开switch结构
  case constant-expression-2 :
    /* constant-expression-2 == expression实际值 将跳转至此 */
    break; // 可选的
  /* 可以有任意数量的switch */
  default : 
    /* 不满足任意情况将跳转至此 */
}
```

### 嵌套语句
任何条件判断选择语句都可以相互嵌套，
但**不建议**：因为条件判断语句在底层实现时需要复杂的运算，减缓程序速度；过多的嵌套会严重降低程序的可读性

## 实现原理
以代码 if(a == 5){ 语句A; }else{ 语句B; } 为例：

### 1. 执行比较操作
CPU 取出变量 a 的值，执行比较指令：
```asm
cmp dword ptr [a], 5
```
比较结果自动存入标志寄存器，不修改任何变量值。

### 2. 判断标志位，执行条件跳转
根据比较结果（ZF 标志位）决定跳转方向：
```asm
je LABEL_A    ; 若 a==5（ZF=1），跳转到语句A
jmp LABEL_B  ; 否则无条件跳转到语句B
```
跳转本质：直接修改 EIP 寄存器的值，改变指令执行顺序。

### 3. 执行 if 分支代码
若跳转到 LABEL_A：
  CPU 顺序执行 if 大括号内的所有指令（语句 A）
  执行完成后，强制跳转到统一结束标签，不执行 else 代码

### 4. 执行 else 分支代码
若未进入 if，直接执行 LABEL_B：
  顺序执行 else 大括号内的所有指令（语句 B）
  执行完成后，跳转到统一结束标签

### 5. 分支汇合，恢复顺序执行
if/else 执行完毕后，都跳转到共同的结束位置：
```asm
END_LABEL:
; 继续执行 if 语句之后的代码
```
