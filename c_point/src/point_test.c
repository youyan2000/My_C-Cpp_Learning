/*Variable Swapping Experiment*/
// #include <stdio.h>
// void swap(int *pa,int *pb);

// int main(){
//     int a=5;
//     int b=6;
//     printf("&a=%p\n&b=%p\n",&a,&b);
//     printf("a=%d\nb=%d\n\n",a,b);
//     swap(&a,&b);
//     printf("&a=%p\n&b=%p\n",&a,&b);
//     printf("a=%d\nb=%d\n",a,b);
//     return 0;
// }

// void swap(int *pa,int *pb){
//     int t=*pa;
//     *pa=*pb;
//     *pb=t;
// }

/*Return and Compare the Values of Two Variables*/
// #include <stdio.h>
// void minmax(int a[],int len,int *max,int *min);

// int main(){
//     int a[]={1,2,3,4,5,6,7,8,453,9,-156,3,2,5346,};
//     int min=a[0],max=a[0];
//     minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
//     printf("min=%d\nmax=%d\n",min,max);
//     return 0;
// }

// void minmax(int a[],int len,int *max,int *min){
//     int i;
//     for ( i=0 ; i<len ; i++){
//         if (a[i]<*min){
//             *min=a[i];
//         }
//         if (a[i]>*max)
//         {
//             *max=a[i];
//         }
//     }
// }

/*Dynamic Memory Allocation*/
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     int number;
//     int* a;
//     int i;
//     printf("Please enter the quantity：\n");
//     scanf("%d",&number);
//     a=(int*)malloc(number*sizeof(int));
//     for ( i=0 ; i<number ; i++){
//         scanf("%d",&a[i]);
//     }
//     for ( i=number-1 ; i<number ; i--){
//         printf("%d\n",a[i]);
//     }
//     free(a);
//     return 0;
// }

