#include <stdio.h>
#include "sort.h"

int main(){
    
    ARR MYarr = CreateSort();
    printf("Original Array:\n");
    PrintArr(MYarr);

    printf("Bubble Sort:\n");
    PrintArr(BubbleSort(MYarr));
    printf("Stalin Sort:\n");
    PrintArr(StalinSort(MYarr));
    printf("Gnome Sort:\n");
    PrintArr(GnomeSort(MYarr));
    printf("Cocktail Sort:\n");
    PrintArr(CocktailSort(MYarr));
    printf("Mao Sort:\n");
    PrintArr(MaoSort(MYarr));
    printf("Shell Sort:\n");
    PrintArr(ShellSort(MYarr));

    return 0;
}
