#include <stdio.h>
#include <locale.h>
#include <string.h>


// /*分段函数*/
// int main(){
//     float f=0;
//     float x;

//     printf("请输入x的值");
//     scanf_s("%f",&x);

//     if (x<0){
//         f=-1;
//     }else if (x==0){
//         f=0;
//     }else{
//         f=2*x;
//     }  
//     printf("f=%f",f);  
// }


// /*打招呼*/
// int main(){
//     int type;

//     scanf_s("%d",&type);

//     switch (type){
//     case 1:
//         printf("你好");
//         break;
//     case 2:
//         printf("早上好");
//         break;
//     case 3:
//         printf("再见");
//         break;
//     case 4:
//         printf("明天见");
//         break;
//     default:
//         printf("什么意思？");
//         break;
//     }

// }


/*丝滑小连招*/
int main(){
    
    int type;
    char say[16]="";

    printf("what are you saying？");

    fgets(say, sizeof(say), stdin);
    say[strcspn(say, "\n")] = '\0';

    if (strcmp(say, "你挫") == 0){
        type = 1;
    } else if (strcmp(say, "你不行") == 0){
        type = 2;
    } else if (strcmp(say, "你蛇皮") == 0){
        type = 3;
    } else if (strcmp(say, "你脑残") == 0){
        type = 4;
    } else if (strcmp(say, "你低智商") == 0){
        type = 5;
    } else if (strcmp(say, "你不够灵性") == 0){
        type = 6;
    } else {
        type = 7;
    }
    
    

    switch (type){
    case 1:
        printf("你挫\n");
    case 2:
        printf("你不行\n");
    case 3:
        printf("你蛇皮\n");
    case 4:
        printf("你脑残\n");
    case 5:
        printf("你低智商\n");
    case 6:
        printf("你不够灵性\n");
    default:
        printf("你没慧根\n");
        break;
    }



}

