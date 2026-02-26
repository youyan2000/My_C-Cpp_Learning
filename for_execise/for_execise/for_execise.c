#include <stdio.h>

/*有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？*/
//int main(){
//	int a=1,b=1,c=1,number=1;
//
//	while(a<=4){
//		while(b<=4){
//			while(c<=4){
//				if(a!=b&&a!=c&&b!=c){
//					printf("%d%d%d\n",a,b,c);
//					number++;
//					}
//				c++;
//			}
//			c=1;
//			b++;
//		}
//		c=1,b=1;
//		a++;
//	}
//	printf("一共有%d个\n",number);
//}



/*程序每次读入一个正3位数，然后输出按位逆序的数字。注意：当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。*/
// int main(){
// 	int g=1,a,b,c;
// 	printf("请输入一个正三位数\n");
// 	scanf_s("%d",&g);

// 	a=g/100;
// 	b=g/10%10;
// 	c=g%10;

// 	printf("%d%d%d",c,b,a);
// }


/*辗转相除法求最大公因数*/
// int main(){
// 	int a,b,t;
// 	printf("请输入第一个数a\n");
// 	scanf_s("%d",&a);
// 	printf("请输入第一个数b\n");
// 	scanf_s("%d",&b);

// 	while (b!=0){
// 		t=a%b;
// 		a=b;
// 		b=t;
// 	}

// 	printf("a与b的最小公倍数为%d\n",a);
	
// 	return 0;
// }



/*给定不超过6的正整数A，考虑从A开始的连续4个数字。请输出所有由它们组成的无重复数字的3位数*/
// int main(){
// 	int a,d;
// 	int i,j,k;
// 	int cut=0;
// 	printf("请输入不超过6的正整数A\n");
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



/*水仙花数是指一个N位正整数（N>=3），它的每个位上的数字的N次幂之和等于它本身*/
// int main(){
// 	int n,x;
// 	int i=1,e=9;
// 	int a,b,c,d;
// 	printf("请输入N\n");
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



/*输出九九乘法表*/
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



/*素数求和*/
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

// 	printf("个数为%d,和为%d",cnt,sum);
// 	return 0;
// }



/*约分最简分数*/
// int main(){
// 	int m,s;
// 	int a,b,t=1;
// 	printf("请输入需要约分的分数\n（格式为a/b）\n");
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



/*读数字*/
// int main(){
	// int in,z,x,num,mask=1;
	// scanf_s("%d",&in);
	// if (in<0){printf("fu " );in=-in;}
	// x=in;
	
	// while(x>9){
	// 	x/=10;
	// 	mask*=10;
	// }
	// x=in;
	// do{
	// 	num=x/mask;
	// 	switch (num)
	// 	{
	// 	case 0:printf("ling");break;
	// 	case 1:printf("yi");break;
	// 	case 2:printf("er");break;
	// 	case 3:printf("san");break;
	// 	case 4:printf("si");break;
	// 	case 5:printf("wu");break;
	// 	case 6:printf("liu");break;
	// 	case 7:printf("qi");break;
	// 	case 8:printf("ba");break;
	// 	case 9:printf("jiu");break;
	// 	}
	// 	x = x%mask;
	// 	mask/=10;
	// 	if (mask>0){
	// 		printf(" ");
	// 	}
	// }while(mask>0);

	// return 0;
}