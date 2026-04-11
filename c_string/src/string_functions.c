/*The std string function and My string function*/
#include <stdio.h>
#include <string.h>

int mylen(const char* s){
  int idx=0;
  while (s[idx]!='\0'){
    idx++;
  }
  return idx;
}

int mycmp(const char*s1,const char*s2){
  int idx=0;
  while (*s1==*s2 && *s1!='\0'){
    *s1++;
    *s2++;
  }
  return *s1-*s2;
  // while (s1[idx]==s2[idx] && s1[idx]!='\0'){
  //     idx++;
  // }
  // return s1[idx]-s2[idx];
}

char* mycpy(char * __restrict__ dst,const char * __restrict__ src){
  // int idx=0;
  // while (src[idx]!='\0'){
  //     dst[idx]=src[idx];
  //     idx++;
  // }
  // dst[idx]='\0';
  char* ret=dst;
  while (*dst++=*src++)
    *dst='\0';
  return ret;
}

int main(){
  char s1[]="abc";
  char s2[]="Abc";
  printf("strlen:%lu\n",strlen(s1));
  printf("mystrlen:%lu\n",mylen(s1));
  printf("sizeof:%lu\n",sizeof(s1));
  printf("compare:%d\n",strcmp(s1,s2));
  printf("mycompare:%d\n",mycmp(s1,s2));
  printf("copy:%s\n",strcpy(s1,s2));
  printf("mycopy:%s\n",mycpy(s1,s2));
  printf("search:%s\n",strchr(s1,'b'));

}
