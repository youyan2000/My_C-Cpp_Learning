/*Structure Output Test*/
#include "stdio.h"

struct date
{
  int month;
  int day;
  int year;
};

int main(){
  struct date today={2,21,2026};
  struct date tomorrow,yesterday,day;
  struct date thismonth={.month=2,.year=2026};
  tomorrow=(struct date){2,20,2026};
  yesterday=(struct date){2,22,2026};
  struct date *pDate = &today; 

  day=tomorrow;
  tomorrow=yesterday;
  yesterday=day;

  printf("Today's date is %i-%i-%i\n",
    today.year,today.month,today.day);
  printf("Today's month is %i-%i\n",
    thismonth.year,thismonth.month);
  printf("Yesterday's date is %i-%i-%i\n",
    yesterday.year,yesterday.month,yesterday.day);
  printf("Tomorrow's date is %i-%i-%i\n",
    tomorrow.year,tomorrow.month,tomorrow.day);
  printf("Today's address is %p\n",*pDate);
  
  return 0;
}