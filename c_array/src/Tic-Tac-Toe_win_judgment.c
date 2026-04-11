#include <stdio.h>

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
  int result=-1;//-1 indicates no winner, 1 indicates x wins, and 0 indicates o wins.

  /*Read the array*/
  for ( i=0; i<size ; i++){
    for ( j=0; j<size ; j++){
      scanf_s("%d",&board[i][j]);
    }
  }

  /*Check rows and columns*/
  result=win1(i,j,board,num0fx,num0fo,result);
  result=win1(j,i,board,num0fx,num0fo,result);

  /*Check diagonals*/
  result=win2(i,i,board,num0fx,num0fo,result);
  result=win2(i,size-i-1,board,num0fx,num0fo,result);

  printf("\n%d",result);
}
