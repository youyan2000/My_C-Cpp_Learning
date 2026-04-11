#include <stdio.h>

int main(){
  #define NUMBER 10  
  int i,x,n,cnt=0;
  int count[NUMBER]={0};
  
  // for ( i=0; i<NUMBER; i++){
  //   count[i]=0;
  // }
  printf("Please enter the total number of digits\n");
  scanf_s("%d",&n);

  do{
    scanf_s("%d",&x);
    if (x>=0 && x<=9){
      count[x]++;
      cnt++;
    }else{
      printf("Error please re-enter\n");
    }
  }while (cnt<n);

  for ( i=0; i<NUMBER; i++){
    printf("Number %d appeared %d times\n",i,count[i]);
  }
  
  return 0;
}