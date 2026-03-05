#include <stdio.h>

///*Time difference timer*/
//int main(){
//	int hour1,minute1,hour2,minute2;
//	int t1,t2;
//
//	printf("Enter the first time (example: hours:minutes)\n");
//	scanf_s("%d:%d",&hour1,&minute1);
//	printf("Enter the second time (example: hours:minutes)\n");
//	scanf_s("%d:%d",&hour2,&minute2);
//
//	t1=hour1*60+minute1;
//	t2=hour2*60+minute2;
//
//	printf("The time difference is %d minutes",t1-t2);
//}


/*Time difference timer*/
// int main(){
// 	int hour1,minute1,hour2,minute2;
// 	int ih,im;

// 	printf("Enter the first time (example: hours:minutes)\n");
// 	scanf_s("%d:%d",&hour1,&minute1);
// 	printf("Enter the second time (example: hours:minutes)\n");
// 	scanf_s("%d:%d",&hour2,&minute2);

// 	ih=hour2-hour1;
// 	im=minute2-minute1;
// 	if(im<0){
// 		im = 60 + im;
// 		ih--;
// 	}

// 	printf("The time difference is %d hours and %d minutes",ih,im);
// }



/*Average timer*/
//int main(){
//	double a,b;
//	double c;
//
//	printf("Please enter the first number a\n");
//	scanf_s("%lf",&a);
//	printf("Please enter the second number b\n");
//	scanf_s("%lf",&b);
//
//	c=(a+b)/2.0;
//	printf("The average of %lf and %lf is %lf",a,b,c);
//
//}



///*exchanger*/
//int main(){
//	int a,b;
//	int c;
//
//	printf("Please enter a\n");
//	scanf_s("%d",&a);
//	printf("Please enter b\n");
//	scanf_s("%d",&b);
//
//	c=b;
//	b=a;
//	a=c;
//	printf("a=%d\nb=%d",a,b);
//
//}



/*Decimal to binary conversion*/
int main(){
	int number;
	scanf_s("%d",&number);
	unsigned int mask = 1u<<31;
	for ( ; mask ; mask>>=1){
		printf("%d",number & mask?1:0);
	}
	printf("\n");

	return 0;
}
