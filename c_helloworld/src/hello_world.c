#include <stdio.h>

int main(){
	int price = 0;
	const int amount=1000;
	int change;
	double a;
	printf("HELLO WORLD!??\n");
	printf("请输入金额\n");
	scanf_s("%d",&price);
	printf("小a\n");
	scanf_s("%lf",&a);
	price=price+30;
	change = amount - price;
	printf("您的零钱为%d\n%lf\n",change,(a/2.32));

	return 0;
}