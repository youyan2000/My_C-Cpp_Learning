/*Find the first 1000 prime numbers*/

#include <stdio.h>

int isprime(int x,int knwon[],int numberknown){
  int ret=1;
  int i;
  if (x==1 || (x%2==0 && x!=2)){
     ret=0;}
  for ( i=1 ; i<numberknown ; i++){
    if(x%knwon[i]==0){
      ret=0;
      break;
    }
  }
  return ret;
}

int main(){
  const int number=1000;
  int prime[number];
  prime[0]=2;
  int count=1;
  int i;

  for ( i=3 ; count<number ; i++){
    if (isprime(i,prime,count)){
      prime[count++]=i;
    }
  }

  for (i=0; i<number; i++){
    printf("%d",prime[i]);
    if ((i+1)%5){printf("\t");}
    else{printf("\n");}
  }

  return 0;
}
