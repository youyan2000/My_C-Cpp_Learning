#include <stdio.h>
#include <string.h>

int main() {
  FILE *file = fopen("H:\\C_program\\C_learning_homework\\file_test\\lib\\read.txt", "w"); 
  if (!file) {
    printf("Cannot open the file.\n");
    return 1;
  }

  /*-------fputc-------*/
  // int c = fputc('S', file);
  // printf("%c\n", c);

  /*-------fputs-------*/
  // int c = fputs("So do I.", file);
  // if(c == EOF) {
  //   printf("Error writing to the file.\n");
  // } else {
  //   printf("Successfully wrote to the file.\n");
  // }

  /*-------fread-------*/
  char arr[100] = {
    "I love you too.\nJe t'aime aussi.\n我也喜欢你。\n"
  };
  int writtenBytes = fwrite(arr, sizeof(char), strlen(arr), file);
  printf("Successfully wrote %d bytes to the file.\n", writtenBytes);
  
  fclose(file);
  return 0;
}