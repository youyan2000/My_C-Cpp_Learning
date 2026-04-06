#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Blindly Guess an random number*/
int main(){
	srand(time(0));
	int x = rand()%10;

	int a=0;
	int count=0;

	do{
		printf("current");
		scanf("%d",&a);
		count++;
	}while (x!=a);
	printf("perfect！");

	return 0;
}