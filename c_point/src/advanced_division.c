#include <stdio.h>

int divide(int a,int b,double *result);

int main(){
    int a,b;
    double c;
    printf("Please enter the dividend:");
    scanf("%d",&a);
    printf("Please enter the divisor");
    scanf("%d",&b);

    if (divide(a,b,&c)){
        printf("%d/%d=%lf\n",a,b,c);
    }else{
        printf("%d/%d=inf\n",a,b);
    }
}

int divide(int a,int b,double *result){
    int ret=1;
    if (b==0){
        ret=0;
    }else{
        *result=0.1*a/b;
    }
    return ret;
}
