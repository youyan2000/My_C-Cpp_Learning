/*Array test*/
#include <stdio.h>
int main(){
  char *s1="Hello World";
  const char *s2="Hello World";
  char* s3="Hello World";
  char s4[]="Hello World";
  char s5[12]={'H','e','l','l','o',' ','W','o','r','l','d','\0'};

  printf("ps1=%p\n",s1);
  printf("ps2=%p\n",s2);
  printf("ps3=%p\n",s3);
  printf("ps4=%p\n",s4);
  printf("ps5=%p\n",s5);

  printf("s1=%s\n",s1);
  printf("s2=%s\n",s2);
  printf("s3=%s\n",s3);
  printf("s4=%s\n",s4);
  printf("s5=%s\n",s5);

  //s1[0]='B';
  //s2[0]='B';
  //s3[0]='B';
  s4[0]='B';
  // printf("s1[0]=%c\n",s1[0]);
  // printf("s1=%s\n",s1); 
  // printf("s2[0]=%c\n",s2[0]);
  // printf("s2=%s\n",s2);
  // printf("s3[0]=%c\n",s3[0]);
  // printf("s3=%s\n",s3);
  printf("s4[0]=%c\n",s4[0]);
  printf("s4=%s\n",s4);

  return 0;
}
