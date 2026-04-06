/*Pointer Reading Experiment*/
#include <stdio.h>

void f(int *p);
void g(int i);

int main(){
    int i=6;
    int num[10]={2};
    printf("&i=%p\n",&i);
    printf("i=%d\n\n",i);
    f(&i);
    g(i);
    f(num);
    g(*num);
    printf("sizeof(&num)=%d\n",sizeof(num));
}

void f(int *p){
    printf("p=%p\n",p);
    printf("*p=%d\n\n",*p);
    // *p=26;
}

void g(int i){
    printf("&i=%p\n",&i);
    printf("i=%d\n\n",i);
}