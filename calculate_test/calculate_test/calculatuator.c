#include <stdio.h>


///*时间差计时器*/
//int main(){
//	int hour1,minute1,hour2,minute2;
//	int t1,t2;
//
//	printf("输入第一个时间（示例：小时:分钟）\n");
//	scanf_s("%d:%d",&hour1,&minute1);
//	printf("输入第二个时间（示例：小时:分钟）\n");
//	scanf_s("%d:%d",&hour2,&minute2);
//
//	t1=hour1*60+minute1;
//	t2=hour2*60+minute2;
//
//	printf("时间差为%d分钟",t1-t2);
//}


/*时间差计时器*/
int main(){
	int hour1,minute1,hour2,minute2;
	int ih,im;

	printf("输入第一个时间（示例：小时:分钟）\n");
	scanf_s("%d:%d",&hour1,&minute1);
	printf("输入第二个时间（示例：小时:分钟）\n");
	scanf_s("%d:%d",&hour2,&minute2);

	ih=hour2-hour1;
	im=minute2-minute1;
	if(im<0){
		im = 60 + im;
		ih--;
	}

	printf("时间差为%d小时%d分钟",ih,im);
}



/*平均数计时器*/
//int main(){
//	double a,b;
//	double c;
//
//	printf("输入第一个数\n");
//	scanf_s("%lf",&a);
//	printf("输入第二个数\n");
//	scanf_s("%lf",&b);
//
//	c=(a+b)/2.0;
//	printf("%lf和%lf的平均值为%lf",a,b,c);
//
//}

///*交换器*/
//int main(){
//	int a,b;
//	int c;
//
//	printf("输入a\n");
//	scanf_s("%d",&a);
//	printf("输入b\n");
//	scanf_s("%d",&b);
//
//	c=b;
//	b=a;
//	a=c;
//	printf("a=%d\nb=%d",a,b);
//
//}