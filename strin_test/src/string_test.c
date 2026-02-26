/*数组测试*/
// #include <stdio.h>
// int main(){
//     int i=0;
//     char *s1="Hello World";
//     char *s2="Hello World";
//     char* s3="Hello World";
//     char s4[]="Hello World";

//     printf("&i=%p\n",&i);
//     printf("s1=%p\n",s1);
//     printf("s2=%p\n",s2);
//     printf("s3=%p\n",s3);
//     printf("s4=%p\n",s4);

//     s4[0]='B';
//     printf("s4=%s\n",s4);
//     printf("s4[0]=%c\n",s4[0]);

//     return 0;
// }



/*月份读数*/
// #include <stdio.h>
// int main(){
//     printf("请输入月份：");
//     int monthnum;
//     char *monthname[] = {
//     "January", "February", "March", "April",
//     "May", "June", "July", "August",
//     "September", "October", "November", "December"};
//     scanf_s("%d",&monthnum);
//     printf("C'est %s\n",monthname[monthnum-1]);
//     return 0;
// }



/*单字符读写测试*/
// #include <stdio.h>
// int main(){
//     int ch;

//     while ((ch=getchar())!=EOF){
//         putchar(ch);
//     }

//     printf("END");
//     return 0;
// }



/*string函数以及我的string函数*/
// #include <stdio.h>
// #include <string.h>

// int mylen(const char* s){
//     int idx=0;
//     while (s[idx]!='\0'){
//         idx++;
//     }
//     return idx;
// }

// int mycmp(const char*s1,const char*s2){
//     int idx=0;
//     while (*s1==*s2 && *s1!='\0'){
//         *s1++;
//         *s2++;
//     }
//     return *s1-*s2;
//     // while (s1[idx]==s2[idx] && s1[idx]!='\0'){
//     //     idx++;
//     // }
//     // return s1[idx]-s2[idx];
// }

// char* mycpy(char * __restrict__ dst,const char * __restrict__ src){
//     // int idx=0;
//     // while (src[idx]!='\0'){
//     //     dst[idx]=src[idx];
//     //     idx++;
//     // }
//     // dst[idx]='\0';
//     char* ret=dst;
//     while (*dst++=*src++)
//     *dst='\0';
//     return ret;
// }

// int main(){
//     char s1[]="abc";
//     char s2[]="Abc";
//     printf("strlen:%lu\n",strlen(s1));
//     printf("mystrlen:%lu\n",mylen(s1));
//     printf("sizeof:%lu\n",sizeof(s1));
//     printf("compare:%d\n",strcmp(s1,s2));
//     printf("mycompare:%d\n",mycmp(s1,s2));
//     printf("copy:%s\n",strcpy(s1,s2));
//     printf("mycopy:%s\n",mycpy(s1,s2));
//     printf("search:%s\n",strchr(s1,'b'));
// }