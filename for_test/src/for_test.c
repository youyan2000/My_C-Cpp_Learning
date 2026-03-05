#include <stdio.h>

/*Calculate factorial in ascending order*/
// int main(){
// 	int n;
// 	int fact=1;
// 	int i=1;

// 	scanf("%d",&n);

// 	for(i=1; i<=n; i++){
// 		fact*=i;
// 	}

// 	printf("%d!=%d\n",n, fact);
// }



/*Calculate factorial in reverse order*/
// int main(){
// 	int n;
// 	int fact=1;
// 	int i=1;

// 	scanf("%d",&n);

// 	for(; n>=2; n--){
// 		fact*=n;
// 		i++;
// 	}

// 	printf("%d!=%d\n",i, fact);
// }



/*Calculate prime numbers*/
// int main(){
// 	int x;
// 	int i=2;
// 	int isprime=1;

// 	scanf("%d",&x);

// 	for (; i <x; i++){
// 		if(x%i==0){
// 			isprime=0;
// 			break;
// 		}
// 	continue;
// 	printf("fuck");
// 	}
// 	if (isprime==0){
// 		printf("%d is not a prime number",x);
// 	}else{
// 		printf("%d is a prime number",x);
// 	}
// }




/*List the prime numbers*/
// int main(){
// 	int x=2;
// 	int i;
// 	int isprime;
// 	int cut=1;

// 	for (; x < 10000; x++){
// 		isprime=1;
// 		i=2;
// 		for (; i <x; i++){
// 			if(x%i==0){
// 				isprime=0;
// 				break;
// 			}
// 		}
// 		if (isprime!=0){
// 		printf("%d\n",x);
// 		cut++;
// 		}
		
// 	}
// 	printf("There are %d prime numbers\n",cut);
// }



/* RMB Calculator*/
// int main(){
// 	int x,cunt=0;
// 	int one=1, five=1,ten=1,twenty=1,fifty=1,hundred=1;

// 	scanf_s("%d",&x);

// 	for(one=0;one<=x;one++){
// 		for(five=0;five<=x;five++){
// 			for(ten=0;ten<=x;ten++){
//                 for(twenty=0;twenty<=x;twenty++){
//                     for(fifty=0;fifty<=x;fifty++){
//                         for(hundred=0;hundred<=x;hundred++){
//                             if (one+10*ten+5*five+20*twenty+50*fifty+100*hundred==x){
//                                 printf("%d one-yuan coins, plus %d five-yuan coins, plus %d ten-yuan coins, plus %d twenty-yuan coins, plus %d fifty-yuan coins, plus %d hundred-yuan coins equal %d yuan.\n"
//                                        ,one, five,ten,twenty,fifty,hundred,x);
//                                 cunt++;
//                             }
//                         }
//                     }
//                 }
// 			}
// 		}
// 	}
//     printf("一共有%d种方法",cunt);
// }



/*Summation of Fractions*/
// int main(){
// 	int n,i,j;
// 	double sum=0.0,sum1=0.0;
	
// 	for(n=100000000;n<=100000000;n++){
// 		for(i=1;i<=n;i++){
// 			sum=sum+1.0/i;
// 		}

// 		for(j=1;j<=n;j++){
// 			if(j%2==0){sum1=sum1-1.0/j;}
// 			else{sum1=sum1+1.0/j;}
// 		}

// 		printf("f(%d)=%f\ng(%d)=%f\n",n,sum,n,sum1);
// 		sum=0.0,sum1=0.0;

// 	}
// }



/*round-off number*/
// int main(){
// 	int x;
// 	int mask=1;
// 	int t,d,m;

// 	scanf_s("%d",&x);
// 	t=x;
// 	m=x;

// 	while (t>9){
// 		t/=10;
// 		mask*=10;
// 	}

// 	do{
// 		d=m/mask;
// 		printf("%d",d);
// 		if(mask>9){
// 			printf(" ");
// 		}
// 		m%=mask;
// 		mask/=10;
// 	} while (mask>0);
	
// 	printf("\n%d",x);
// }



/*Calculate the sum of the first N terms of the sequence 2/1+3/2+5/3+8/5+...; starting from the second term, each term's numerator is the sum of the previous term's numerator and denominator, and the denominator is the previous term's numerator*/
int main(){
    double m=1,s=2,t;
    int n,i;
    double num,sum=0;
    scanf_s("%d",&n);

    for(i=1;i<=n;i++){
        num=s/m;
        sum+=num;
        t=s;
        s=s+m;
        m=t;
    }

    printf("%.2f",sum);
}