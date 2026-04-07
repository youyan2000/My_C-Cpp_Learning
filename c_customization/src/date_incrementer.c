/*Structure and Function*/
#include <stdio.h>
#include <stdbool.h>

struct date{
  int day;
  int month;
  int year;
};

bool isLeap(struct date d);
int numberOfDays(struct date d);

#include <stdio.h>
#include <stdbool.h>

struct date{
  int day;
  int month;
  int year;
};

bool isLeap(struct date d);
int numberOfDays(struct date d);

int main(){
  struct date today,tomorrow;

  printf("Please enter today's date(dd-mm-yyyy):\n");
  scanf_s("%i-%i-%i",&today.day,&today.month,&today.year);

  if (today.day <= numberOfDays(today) && today.month <=12){
    if (today.day != numberOfDays(today)){
      tomorrow.day=today.day+1;
      tomorrow.month=today.month;
      tomorrow.year=today.year;
    }else if (today.month == 12){
      tomorrow.day=1;
      tomorrow.month=1;
      tomorrow.year=today.year+1;
    }else if (today.day == numberOfDays(today)){
      tomorrow.day=1;
      tomorrow.month=today.month+1;
      tomorrow.year=today.year;
    }
    printf("Tomorrow is %i-%i-%i.\n",
      tomorrow.day, tomorrow.month,tomorrow.year);
    printf("Today is %i-%i-%i.\n",
      today.day, today.month,today.year);
  }else{
    printf("error: invalid date.\n");
  }
  
  return 0;
}

int numberOfDays(struct date d){
  int days;
  const int daysPerMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

  if (d.month == 2 && isLeap(d)){
    days =29;
  }else{
    days=daysPerMonth[d.month-1];
  }
  return days;
}

bool isLeap(struct date d){
  bool leap=false;
  if ((d.year%4==0 && d.year%100!=0) || d.year%400 == 0){
    leap=true;
  }
  return leap;
}
