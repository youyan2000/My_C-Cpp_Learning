#include <stdio.h>

int main(){
	int number=0;
	int sum=0;
	int count=0;

  printf("Please enter the numbers you want to calculate the average of (enter -1 to stop):\n");
  
  /*while version*/
	scanf("%d",&number);
	while(number!=-1){
		sum+=number;
		count++;
		scanf("%d",&number);
	}

  /*do-while version*/
	scanf("%d",&number);
	do{
    scanf("%d",&number);
		sum+=number;
		count++;
	}while(number!=-1);
	
	printf("%f",1.0*sum/count);

	return 0;
}