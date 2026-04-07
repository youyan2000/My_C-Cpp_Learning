#include <stdio.h>

enum COLOR{RED,YELLOW,GREEN,NumCOLORS};

int main(){
  int color=-1;
  char *ColorNames[NumCOLORS]={
    "red","yellow","green",
  };
  char *ColorName =NULL;

  printf("Please enter the color code you like: ");
  scanf_s("%d",&color);
  if (color>=0 && color<NumCOLORS){
    ColorName=ColorNames[color];
  }else{
    ColorName="unknown";
  }
  printf("The color you like is %s\n",ColorName);
  return 0;

}
