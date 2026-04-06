#include <stdio.h>


/*sum function*/
int sum(int begin,int end){
    int i,sum=0;
    for (i=begin ; i<end ; i++){
        sum+=i;
    }
    return sum;
}

int main(){
    int a,b,c;
    a=sum(1,10);
    b=sum(20,30);
    c=sum(35,45);
    printf("%d,%d,%d",a,b,c);
    return 0;
}
