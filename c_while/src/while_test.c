#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Digit Counting(while)*/
// int main(){
// 	int x;
// 	int n=0;

// 	scanf("%d",&x);
// 	n++;
// 	x/=10;
// 	while (x>0){
// 		n++;
// 		x/=10;
// 	}
// 	printf("%d\n",n);

// 	return 0;
// }



/*Digit Counting(do_while)*/
// int main(){
// 	int x;
// 	int n=0;

// 	scanf("%d",&x);

// 	do{
// 		n++;
// 		x/=10;
// 	}while (x>0);
// 	printf("%d\n",n);

// 	return 0;
// }



/*Blind Guessing Game*/
// int main(){
// 	srand(time(0));
// 	int x = rand()%10;

// 	int a=0;
// 	int count=0;

// 	do{
// 		printf("current");
// 		scanf("%d",&a);
// 		count++;
// 	}while (x!=a);
// 	printf("perfect！");

// 	return 0;
// }



// /*Guessing Game*/
// int main(){
// 	srand(time(0));
// 	int x = rand()%100;

// 	int a=0;
// 	int count=0;

// 	printf("Try to guess the random number between 1 and 100.\n");

// 	scanf("%d",&a);
// 	while (x!=a){
// 		printf("WRONG ANSWER!BITCH!!\n");
	
// 		if (a>x){
// 			printf("TOO BIG\nhave another try\n");
// 		}else if(a<x){
// 			printf("TOO SMALL\nhave another try\n");
// 		}
// 		scanf("%d",&a);
		
// 		count++;
// 	}
// 	printf("FANTASTIC！It only took %d guesses to get it right.!",count);
	
// 	return 0;
// }



/*Calculate the Average*/
// int main(){
// 	int number=0;
// 	int sum=0;
// 	int count=0;

// 	scanf("%d",&number);
// 	while(number!=-1){
// 			sum+=number;
// 			count++;
// 			scanf("%d",&number);
// 		}
	
// 		printf("%f",1.0*sum/count);

// 	return 0;
// }



/*Reverse Integer*/
int main(){
	int number=0;
	int numbern=0;
	int digit=0;

	printf("Please enter the target number: ");
	scanf_s("%d",&number);

	while(number>0){
			digit=number%10;
			printf("%d",digit);
			numbern=10*numbern+digit;
			number/=10;
		}

	printf("\n%d",numbern);
	
	return 0;
}
