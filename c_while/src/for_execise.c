#include <stdio.h>
/*The program reads in a positive 3-digit number each time, and then outputs the number in reverse order of its digits. Note: If the input number ends with a zero, the output should not have leading zeros. For example, if the input is 700, the output should be 7.*/
// int main(){
// 	int g=1,a,b,c;
// 	printf("Please enter a positive three-digit number.\n");
// 	scanf_s("%d",&g);

// 	a=g/100;
// 	b=g/10%10;
// 	c=g%10;

// 	printf("%d%d%d",c,b,a);
// }


/*The Euclidean algorithm for finding the greatest common divisor*/
// int main(){
// 	int a,b,t;
// 	printf("Please enter a number a.\n");
// 	scanf_s("%d",&a);
// 	printf("Please enter a number b.\n");
// 	scanf_s("%d",&b);

// 	while (b!=0){
// 		t=a%b;
// 		a=b;
// 		b=t;
// 	}

// 	printf("The greatest common divisor of a and b is%d\n",a);
	
// 	return 0;
// }



/*Given a positive integer A that is no more than 6, consider the four consecutive numbers starting from A. Please output all the 3-digit numbers composed of these numbers without repetition.*/
// int main(){
// 	int a,d;
// 	int i,j,k;
// 	int cut=0;
// 	printf("Please enter a positive integer A that is no more than 6.\n");
// 	scanf_s("%d",&a);

// 	for (i=a; i<=a+3 ; i++){
// 		for (j=a; j<=a+3 ; j++){
// 			for (k=a; k<=a+3 ; k++){
// 				if(i!=j && j!=k && i!=k){
// 					d=i*100+j*10+k;
// 					printf("%d ",d);
// 					cut++;
// 					if (cut==6){
// 						printf("\n");
// 						cut=0;
// 					}
// 				}
// 			}
// 		}	
// 	}
// }



/*The Narcissistic Number refers to a positive integer with N digits (where N >= 3), whose sum of the Nth powers of each digit equals the number itself.*/
// int main(){
// 	int n,x;
// 	int i=1,e=9;
// 	int a,b,c,d;
// 	printf("Please enter N\n");
// 	scanf_s("%d",&n);
// 	b=n-1;
// 	do{
// 		i=i*10;
// 		b--;
// 	}while (b>0);
//  	e=i*10;

// 	for (; i<e; i++){
// 		a=0;
// 		x=i;
// 		while (x>0){
// 			d=x%10;
// 			x/=10;
// 			do{
// 				b--;
// 				c=c*d;
// 			}while (b>0);
// 			a=a+c;
// 			c=1;
// 			b=n;
// 		}
// 		if (i==a){
// 			printf("%d\n",i);
// 		}
// 	}
		
// }



/*Output the multiplication table of 9 times 9*/
// int main(){
// 	int i,j,k;

// 	for (i=1; i<10; i++){
// 		for (j=1; j<=i ; j++){
// 			k=i*j;
// 			if (k>9){
// 				printf("%d*%d=%d  ",j,i,k);
// 			}else{
// 				printf("%d*%d=%d   ",j,i,k);
// 			}
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }



/*Sum of prime numbers*/
// int main(){
// 	int n,m;
// 	int i,k,is;
// 	int cnt=0,sum=0;
// 	scanf_s("%d %d",&n,&m);
// 	if(n==1){n=2;}

// 	for(i=n;i<=m;i++){
// 		is=1;
// 		for(k=2;k<i-1;k++){
// 			if(i%k==0){
// 				is=0;
// 				break;
// 			}
// 		}
// 		if(is){
// 			cnt++;
// 			sum+=i;
// 		}
// 	}

// 	printf("The number is %d, and the sum is %d.",cnt,sum);
// 	return 0;
// }



/*Reduce to the simplest fraction*/
// int main(){
// 	int m,s;
// 	int a,b,t=1;
// 	printf("Please enter the fraction that needs to be simplified\n(Format: a/b)\n");
// 	scanf_s("%d/%d",&s,&m);
// 	a=m;b=s;

// 	while (b>0){
// 		t=a%b;
// 		a=b;
// 		b=t;
// 	}
// 	m/=a;
// 	s/=a;
// 	printf("%d/%d",s,m);
// }
