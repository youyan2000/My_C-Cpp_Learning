#include <stdio.h>

/*Reverse Integer*/
int main(){
	int number=0;
	int numbern=0;
	int digit=0;

	printf("Please enter the target number: ");
	scanf("%d",&number);

	while(number>0){
		digit=number%10;
		printf("%d",digit);
		numbern=10*numbern+digit;
		number/=10;
	}

	printf("\n%d",numbern);
	
	return 0;
}
