#include <stdio.h>

/*数组求和*/
// int main(){
//     int x,n;
//     double sum=0;
//     int cnt=0;
    
//     printf("请输入需要求和的数组的个数n\n");
//     scanf_s("%d",&n);
//     int number[n];

//     do{
//         scanf_s("%d",&x);
//         number[cnt]=x;
//         sum+=x;
//         cnt++;
//     }while (cnt<n);

//     if (cnt>0){
//         int i;
//         double average = sum/cnt;
//         printf("%lf\n",average);
//         for ( i=0; i<cnt; i++){
//             if (number[i]>average){
//                 printf("%d\n",number[i]);
//             }
//         }
//     }
//     return 0;
// }



/*统计个数*/
// int main(){
//     #define NUMBER 10  
//     int i,x,n,cnt=0;
//     int count[NUMBER]={0};
    
//     // for ( i=0; i<NUMBER; i++){
//     //     count[i]=0;
//     // }
//     printf("请输入数字总数\n");
//     scanf_s("%d",&n);

//     do{
//         scanf_s("%d",&x);
//         if (x>=0 && x<=9){
//             count[x]++;
//             cnt++;
//         }else{
//             printf("出错请重新输入\n");
//         }
        
//     }while (cnt<n);

//     for ( i=0; i<NUMBER; i++){
//         printf("%d出现了%d次\n",i,count[i]);
//     }
    
//     return 0;
// }



/*找前1000位素数*/
// int isprime(int x,int knwon[],int numberknown){
//     int ret=1;
//     int i;
//     if (x==1 || (x%2==0 && x!=2)){
//        ret=0;}
//     for ( i=1 ; i<numberknown ; i++){
//         if(x%knwon[i]==0){
//             ret=0;
//             break;
//         }
//     }
//     return ret;
// }

// int main(){
//     const int number=1000;
//     int prime[number];
//     prime[0]=2;
//     int count=1;
//     int i;
//     for ( i=3 ; count<number ; i++){
//         if (isprime(i,prime,count)){
//             prime[count++]=i;
//         }
//     }

//     for (i=0; i<number; i++){
//         printf("%d",prime[i]);
//         if ((i+1)%5){printf("\t");}
//         else{printf("\n");}
//     }
// }



/*井字棋胜利判断*/
const int size=3;

int win1(int i,int j,int board[size][size],int num0fx,int num0fo,int result){
    for( i=0 ; i<size && result==-1 ; i++){
        num0fo=num0fx=0;
        for ( j=0; j<size ; j++){
            if (board[i][j]==1){
                num0fx++;
            }else{
                num0fo++;
            }  
        }
        if(num0fo==size){
            result=0;
        }else if (num0fx==size){
            result=1;
        }
    }
    return result;
}

int win2(int i,int j,int board[size][size],int num0fx,int num0fo,int result){
    num0fo=num0fx=0;
    for ( i=0; i<size && result==-1 ; i++){
        if (board[i][j]==1){
            num0fx++;
        }else{
            num0fo++;
        }  
    }
    if(num0fo==size){
        result=0;
    }else if (num0fx==size){
        result=1;
    }
    return result;
}

int main(){
    int board[size][size];
    int i,j;
    int num0fx,num0fo;
    int result=-1;/*-1为没人赢，1为x赢，0为o赢*/

    /*读取数组*/
    for ( i=0; i<size ; i++){
        for ( j=0; j<size ; j++){
            scanf_s("%d",&board[i][j]);
        }
    }

    /*检查行列*/
    result=win1(i,j,board,num0fx,num0fo,result);
    result=win1(j,i,board,num0fx,num0fo,result);
    /*检查对角线*/
    result=win2(i,i,board,num0fx,num0fo,result);
    result=win2(i,size-i-1,board,num0fx,num0fo,result);

    printf("\n%d",result);
}