#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
  int type;

  /*say hello*/
  scanf_s("%d",&type);

  switch (type){
  case 1:
    printf("Hello");
    break;
  case 2:
    printf("Bonjour");
    break;
  case 3:
    printf("Au revoir");
    break;
  case 4:
    printf("À demain");
    break;
  default:
    printf("What are you saying?");
    break;
  }

  /*say fisk you*/
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

  return 0;
}


