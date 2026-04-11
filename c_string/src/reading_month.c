#include <stdio.h>

int main(){
  printf("Please enter the month number: ");
  int monthnum;
  char *monthname[] = {
  "January", "February", "March", "April",
  "May", "June", "July", "August",
  "September", "October", "November", "December"};
  scanf_s("%d",&monthnum);
  printf("C'est %s\n",monthname[monthnum-1]);
  return 0;
}
