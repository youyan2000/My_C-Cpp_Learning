#include <stdio.h>
#include "sort.h"

int main(){
    
    ARR MYarr = CreateSort();
    printf("========Original Array========\n");
    PrintArr(MYarr);
    shuffle(&MYarr);

    printf("========Bubble Sort========\n");
    PrintArr(BubbleSort(MYarr));
    shuffle(&MYarr);

    printf("========Stalin Sort========\n");
    PrintArr(StalinSort(MYarr));
    shuffle(&MYarr);

    printf("========Gnome Sort========\n");
    PrintArr(GnomeSort(MYarr));
    shuffle(&MYarr);

    printf("========Cocktail Sort========\n");
    PrintArr(CocktailSort(MYarr));
    shuffle(&MYarr);

    printf("========Mao Sort========\n");
    PrintArr(MaoSort(MYarr));
    shuffle(&MYarr);

    printf("========Shell Sort========\n");
    PrintArr(ShellSort(MYarr));
    shuffle(&MYarr);
    
    printf("========Slack Sort========\n");
    PrintArr(SlackSort(MYarr));
    shuffle(&MYarr);
    
    printf("========General Sort========\n");
    GeneralSort(MYarr);
    shuffle(&MYarr);

    printf("========Den Sort========\n");
    PrintArr(DenSort(MYarr));
    shuffle(&MYarr);

    printf("========Bogo Sort========\n");
    PrintArr(BogoSort(MYarr));
    shuffle(&MYarr);

    printf("========Sleep Sort========\n");
    SleepSort(MYarr);

    return 0;
}
