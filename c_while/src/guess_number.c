#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(0));
	int x = rand()%100;

	int a=0;
	int count=0;

	printf("Try to guess the random number between 1 and 100.\n");

	scanf("%d",&a);
	while (x!=a){
		printf("WRONG ANSWER!BITCH!!\n");
	
		if (a>x){
			printf("TOO BIG\nhave another try\n");
		}else if(a<x){
			printf("TOO SMALL\nhave another try\n");
		}
		scanf("%d",&a);
		
		count++;
	}
	printf("FANTASTIC！It only took %d guesses to get it right.!",count);
	
	return 0;
}
