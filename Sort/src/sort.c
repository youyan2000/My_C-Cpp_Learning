#include <stdio.h>
#include "sort.h"

ARR CreateSort(){
    int i;
    ARR arr;
    arr.len = 0;
    for(i=0; i<100; i++){
        arr.data[i] = 0;
    }
    printf("please enter the elements (enter -1 to stop):\n");
    for(i=0; i<100; i++){
        scanf("%d", &arr.data[i]);
        if (arr.data[i] == -1) {
            break;
        }
        arr.len++;
    }
    return arr;
}

ARR BubbleSort(ARR arr) {
    
    if (arr.len <= 1) return arr;
    for (int i = 0; i < arr.len - 1; i++) {
        int swapped = 0; 
        
        for (int j = 0; j < arr.len - 1 - i; j++) {
            if (arr.data[j] > arr.data[j + 1]) {
                int temp = arr.data[j];
                arr.data[j] = arr.data[j + 1];
                arr.data[j + 1] = temp;
                swapped = 1;
            }
        }
        
        if (swapped == 0) {
            break;
        }
    }
    return arr;
}

ARR StalinSort(ARR arr){
    if (arr.len <= 1) return arr;

    ARR sortedArr;
    sortedArr.data[0] = arr.data[0];
    sortedArr.len = 1;

    for (int i = 1; i < arr.len; i++) {
        if (arr.data[i] >= sortedArr.data[sortedArr.len - 1]) {
            sortedArr.data[sortedArr.len] = arr.data[i];
            sortedArr.len++;
        }
    }
    
    return sortedArr;
}

ARR GnomeSort(ARR arr){
    if (arr.len <= 1) return arr;

    int index = 1;
    
    while (index < arr.len) {

        if (index == 0) {
            index++;
        }

        if (arr.data[index] >= arr.data[index - 1]) {
            index++;
        } else {
            int temp = arr.data[index];
            arr.data[index] = arr.data[index - 1];
            arr.data[index - 1] = temp;
            index--;
        }
    }
    
    return arr;
}

ARR CocktailSort(ARR arr){
    if (arr.len <= 1) return arr;

    int start = 0;
    int end = arr.len - 1;
    int swapped = 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            if (arr.data[i] > arr.data[i + 1]) {
                int temp = arr.data[i];
                arr.data[i] = arr.data[i + 1];
                arr.data[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = 0;
        end--;

        for (int i = end; i >= start; i--) {
            if (arr.data[i] > arr.data[i + 1]) {
                int temp = arr.data[i];
                arr.data[i] = arr.data[i + 1];
                arr.data[i + 1] = temp;
                swapped = 1;
            }
        }

        start++;
    }

    return arr;
}

ARR ShellSort(ARR arr){
    for (int gap = arr.len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arr.len; i++) {
            int temp = arr.data[i];
            int j;
            for (j = i; j >= gap && arr.data[j - gap] > temp; j -= gap) {
                arr.data[j] = arr.data[j - gap];
            }
            arr.data[j] = temp;
        }
    }
    return arr;
}

ARR MaoSort(ARR arr){
    if (arr.len <= 1) return arr;
    int sum = 0;
    for (int i = 0; i < arr.len; i++) {
        sum += arr.data[i];
    }
    int standard = sum;
    for (int i = 0; i < arr.len; i++) {
        if (arr.data[i] != standard) {
            arr.data[i] = standard;
        }
    }
    return arr;
}

void PrintArr(ARR arr){
    for (int i = 0; i < arr.len; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}
