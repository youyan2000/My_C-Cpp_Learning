#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*位数判断while*/
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



/*位数判断do_while*/
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



/*盲猜游戏*/
// int main(){
// 	srand(time(0));
// 	int x = rand()%10;

// 	int a=0;
// 	int count=0;

// 	do{
// 		printf("萝卜");
// 		scanf("%d",&a);
// 		count++;
// 	}while (x!=a);
// 	printf("真棒！");

// 	return 0;

// }




// /*猜数游戏*/
// int main(){
// 	srand(time(0));
// 	int x = rand()%100;

// 	int a=0;
// 	int count=0;

// 	printf("猜那个1到100之间的随机数吧");

// 	scanf("%d",&a);
// 	while (x!=a){
// 		printf("傻逼猜错了\n");
	
// 		if (a>x){
// 			printf("大了\n再猜\n");
// 		}else if(a<x){
// 			printf("小了\n再猜\n");
// 		}
// 		scanf("%d",&a);
		
// 		count++;
// 	}
// 	printf("真棒！猜了%d次就对了!",count);
	
// 	return 0;

// }



/*求平均数*/
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



/*整数取逆*/
int main(){
	int number=0;
	int numbern=0;
	int digit=0;

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
