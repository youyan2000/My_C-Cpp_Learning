/*File Read*/
// #include <stdio.h>

// int main() {
//     FILE *file = fopen("H:\\C_program\\C_learning_homework\\file_test\\lib\\read.txt", "r"); 
//     if (!file) {
//         printf("Cannot open the file.\n");
//         return 1;
//     }

//     /*-------fgetc-------*/
//     // int c= 1;
//     // while (c != -1){
//     //     c =fgetc(file);
//     //     printf("%c", c);
//     // }

//     /*-------fgets-------*/
//     // char lines[3][100]; 
//     // int count = 0;
//     // for (int i = 0; i < 3; i++) {
//     //     if (fgets(lines[i], 100, file) == NULL) {
//     //         break; 
//     //     }
//     //     count++; 
//     // }
//     // printf("Read %d lines from the file.\n", count);
//     // for (int round = 0; round < 10; round++) { 
//     //     for (int k = 0; k < count; k++) { 
//     //         printf("%s", lines[k]);
//     //     }
//     //     printf("\n"); 
//     // }

//     /*-------fread-------*/
//     char arr[1024];
//     int bytesRead = fread(arr, sizeof(char), 1024, file);
//     arr[bytesRead] = '\0';
//     printf("Read %d bytes from the file:\n%s\n", bytesRead, arr);
    
//     fclose(file);
//     return 0;
// }



/*File Write*/
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
    //     printf("Error writing to the file.\n");
    // } else {
    //     printf("Successfully wrote to the file.\n");
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