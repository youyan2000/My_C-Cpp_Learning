#include <stdio.h>

int main(){
  int x,n;
  double sum=0;
  int cnt=0;
  
  printf("Please enter the number of arrays that need to be summed n\n");
  scanf_s("%d",&n);
  int number[n];

  do{
    scanf_s("%d",&x);
    number[cnt]=x;
    sum+=x;
    cnt++;
  }while (cnt<n);

  if (cnt>0){
    int i;
    double average = sum/cnt;
    printf("%lf\n",average);
    for ( i=0; i<cnt; i++){
      if (number[i]>average){
        printf("%d\n",number[i]);
      }
    }
  }
  return 0;
}