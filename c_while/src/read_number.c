#include <stdio.h>

int main(){
	int in,z,x,num,mask=1;
	scanf_s("%d",&in);
	if (in<0){printf("fu " );in=-in;}
	x=in;
	
	while(x>9){
		x/=10;
		mask*=10;
	}
	x=in;
	do{
		num=x/mask;
		switch (num)
		{
		case 0:printf("ling");break;
		case 1:printf("yi");break;
		case 2:printf("er");break;
		case 3:printf("san");break;
		case 4:printf("si");break;
		case 5:printf("wu");break;
		case 6:printf("liu");break;
		case 7:printf("qi");break;
		case 8:printf("ba");break;
		case 9:printf("jiu");break;
		}
		x = x%mask;
		mask/=10;
		if (mask>0){
			printf(" ");
		}
	}while(mask>0);

	return 0;
}