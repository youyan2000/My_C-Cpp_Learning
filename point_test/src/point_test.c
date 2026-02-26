/*指针读取实验*/
// #include <stdio.h>
// void f(int *p);
// void g(int i);

// int main(){
//     int i=6;
//     int num[10]={2};
//     printf("&i=%p\n",&i);
//     printf("i=%d\n\n",i);
//     f(&i);
//     g(i);
//     f(num);
//     g(*num);
//     printf("sizeof(&num)=%d\n",sizeof(num));
// }

// void f(int *p){
//     printf("p=%p\n",p);
//     printf("*p=%d\n\n",*p);
//     // *p=26;
// }

// void g(int i){
//     printf("&i=%p\n",&i);
//     printf("i=%d\n\n",i);
// }



/*变量交换实验*/
// #include <stdio.h>
// void swap(int *pa,int *pb);

// int main(){
//     int a=5;
//     int b=6;
//     printf("&a=%p\n&b=%p\n",&a,&b);
//     printf("a=%d\nb=%d\n\n",a,b);
//     swap(&a,&b);
//     printf("&a=%p\n&b=%p\n",&a,&b);
//     printf("a=%d\nb=%d\n",a,b);
//     return 0;
// }

// void swap(int *pa,int *pb){
//     int t=*pa;
//     *pa=*pb;
//     *pb=t;
// }




/*返回两个变量值*/
// #include <stdio.h>
// void minmax(int a[],int len,int *max,int *min);

// int main(){
//     int a[]={1,2,3,4,5,6,7,8,453,9,-156,3,2,5346,};
//     int min=a[0],max=a[0];
//     minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
//     printf("min=%d\nmax=%d\n",min,max);
//     return 0;
// }

// void minmax(int a[],int len,int *max,int *min){
//     int i;
//     for ( i=0 ; i<len ; i++){
//         if (a[i]<*min){
//             *min=a[i];
//         }
//         if (a[i]>*max)
//         {
//             *max=a[i];
//         }
//     }
// }




/*高级除法*/
// #include <stdio.h>
// int divide(int a,int b,double *result);

// int main(){
//     int a,b;
//     double c;
//     printf("请输入被除数");
//     scanf_s("%d",&a);
//     printf("请输入除数");
//     scanf_s("%d",&b);

//     if (divide(a,b,&c)){
//         printf("%d/%d=%lf",a,b,c);
//     }else{
//         printf("%d/%d=inf",a,b);
//     }
// }

// int divide(int a,int b,double *result){
//     int ret=1;
//     if (b==0){
//         ret=0;
//     }else{
//         *result=0.1*a/b;
//     }
//     return ret;
// }



/*动态内存分配*/
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     int number;
//     int* a;
//     int i;
//     printf("请输入数量：\n");
//     scanf_s("%d",&number);
//     a=(int*)malloc(number*sizeof(int));
//     for ( i=0 ; i<number ; i++){
//         scanf_s("%d",&a[i]);
//     }
//     for ( i=number-1 ; i<number ; i--){
//         printf("%d\n",a[i]);
//     }
//     free(a);
//     return 0;
// }


/*最大可分配内存测试*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    void *p;
    int cnt=0;
    while ((p=malloc(100*1024*1024))){
        cnt++;
    }
    printf("分配了%d00MB的空间\n",cnt);
    free(p);
    return 0;
}