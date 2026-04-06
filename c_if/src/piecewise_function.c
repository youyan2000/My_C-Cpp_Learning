#include <stdio.h>

int main(){
  float f=0;
  float x;

  printf("Please input the value of x:");
  scanf_s("%f",&x);

  if (x<0){
    f=-1;
  }else if (x==0){
    f=0;
  }else{
    f=2*x;
  }  
  printf("f=%f",f);  
}