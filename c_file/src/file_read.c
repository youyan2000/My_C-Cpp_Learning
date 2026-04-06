#include <stdio.h>

int main() {
  FILE *file = fopen(".\\lib\\read.txt", "r"); 
  if (!file) {
    printf("Cannot open the file.\n");
    return 1;
  }

  /*-------fgetc-------*/
  // int c= 1;
  // while (c != -1){
  //  c =fgetc(file);
  //  printf("%c", c);
  // }

  /*-------fgets-------*/
  // char lines[3][100]; 
  // int count = 0;
  // for (int i = 0; i < 3; i++) {
  //   if (fgets(lines[i], 100, file) == NULL) {
  //     break; 
  //   }
  //   count++; 
  // }
  // printf("Read %d lines from the file.\n", count);
  // for (int round = 0; round < 10; round++) { 
  //   for (int k = 0; k < count; k++) { 
  //     printf("%s", lines[k]);
  //   }
  //   printf("\n"); 
  // }

  /*-------fread-------*/
  char arr[1024];
  int bytesRead = fread(arr, sizeof(char), 1024, file);
  arr[bytesRead] = '\0';
  printf("Read %d bytes from the file:\n%s\n", bytesRead, arr);
  
  fclose(file);
  return 0;
}