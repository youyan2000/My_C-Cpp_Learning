#include <stdio.h>

enum COLOR{RED,YELLOW,GREEN,NumCOLORS};

int main(){
    int color=-1;
    char *ColorNames[NumCOLORS]={
        "red","yellow","green",
    };
    char *ColorName =NULL;

    printf("请输入你喜欢的颜色代码：");
    scanf_s("%d",&color);
    if (color>=0 && color<NumCOLORS){
        ColorName=ColorNames[color];
    }else{
        ColorName="unknown";
    }
    printf("你喜欢的颜色是%s\n",ColorName);
    return 0;

}
