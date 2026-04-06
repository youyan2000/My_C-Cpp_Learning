#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <limits.h>
#include "sort.h"

ARR CreateSort(){
    int i;
    ARR arr;
    arr.len = 0;
    for(i=0; i< MAX_SORT_LEN; i++){
        arr.data[i] = 0;
    }
    printf("please enter the elements (enter -1 to stop):\n");
    for (i = 0; i < MAX_SORT_LEN; i++) {
        int input_val;
        
        if (scanf("%d", &input_val) != 1) {
            printf("\n[Error] Invalid input detected. Stopping input.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF); 
            break;
        }

        if (input_val == -1) {
            break;
        }

        arr.data[i] = input_val;
        arr.len++;
    }
    return arr;
}

ARR BubbleSort(ARR arr) {
    if (arr.len <= 1) return arr;
    if (is_sorted(&arr)) return arr;

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
    if (is_sorted(&arr)) return arr;

    ARR sortedArr;
    sortedArr.len = 0;

    bool first_element = true;
    int current_max = 0; 

    for (int i = 0; i < arr.len; i++) {
        int val = arr.data[i];
        if (first_element || val >= current_max) {
            if (sortedArr.len < MAX_SORT_LEN) {
                sortedArr.data[sortedArr.len] = val;
                sortedArr.len++;
                
                current_max = val;
                first_element = false;
            }
        }
    }
    if (sortedArr.len == 0) {
        printf("No alive elements found.\n");
    }
    return sortedArr;
}

ARR GnomeSort(ARR arr){
    if (arr.len <= 1) return arr;
    if (is_sorted(&arr)) return arr;

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
    if (is_sorted(&arr)) return arr;

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
    if (arr.len <= 1) return arr;
    if(is_sorted(&arr)) return arr;

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
        if (arr.data[i] > 0) {
            sum += arr.data[i];
        }
    }
    int standard = sum;
    for (int i = 0; i < arr.len; i++) {
        if (arr.data[i] != standard) {
            arr.data[i] = standard;
        }
    }
    return arr;
}

ARR BogoSort(ARR arr){
    if (arr.len <= 1) return arr;
    if (is_sorted(&arr)) return arr;
    int time = 0;

    while (!is_sorted(&arr)) {
        shuffle(&arr);
        time++;
    }
    
    printf("BogoSort took %d times.\n", time);
    return arr;
}

ARR SlackSort(ARR arr){
    if (arr.len <= 1) return arr;

    int min_val = INT_MAX;

    for (int i = 0; i < arr.len; i++) {
        if (arr.data[i] < min_val) {
            min_val = arr.data[i];
        }
    }

    ARR sortedArr;
    sortedArr.len = arr.len;
    sortedArr.data[0] = min_val;

    for (int i = 1; i < arr.len; i++){
        sortedArr.data[i] = min_val + i;
    }
    
    return sortedArr;
}

ARR DenSort(ARR arr){
    if (arr.len <= 1) return arr;

    int max_val = arr.data[0];
    for (int i = 1; i < arr.len; i++) {
        if (arr.data[i] > max_val) max_val = arr.data[i];
    }

    int rich_count = arr.len / 4;
    if (rich_count == 0) rich_count = 1;

    int* positions = (int*)malloc(arr.len * sizeof(int));
    for (int i = 0; i < arr.len; i++) positions[i] = i;

    for (int i = arr.len - 1; i > arr.len - 1 - rich_count; i--) {
        int j = rand() % (i + 1);
        int temp = positions[i];
        positions[i] = positions[j];
        positions[j] = temp;
    }

    for (int i = arr.len - rich_count; i < arr.len; i++) {
        arr.data[positions[i]] = max_val;
    }

    int* remain = (int*)malloc((arr.len - rich_count) * sizeof(int));
    int k = 0;
    for (int i = 0; i < arr.len; i++) {
        int is_rich = 0;
        for (int j = arr.len - rich_count; j < arr.len; j++) {
            if (positions[j] == i) {
                is_rich = 1;
                break;
            }
        }
        if (!is_rich) remain[k++] = arr.data[i];
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (remain[j] > remain[j + 1]) {
                int temp = remain[j];
                remain[j] = remain[j + 1];
                remain[j + 1] = temp;
            }
        }
    }

    k = 0;
    for (int i = 0; i < arr.len; i++) {
        int is_rich = 0;
        for (int j = arr.len - rich_count; j < arr.len; j++) {
            if (positions[j] == i) {
                is_rich = 1;
                break;
            }
        }
        if (!is_rich) {
            arr.data[i] = remain[k++];
        }
    }

    return arr;
    free(positions);
    free(remain);
}

void* sleep_thread_func(void* arg) {
    int n = *(int*)arg;
    free(arg); 

    if (n < 0) {
        printf("[skip negative %d] ", n);
        fflush(stdout);
        return NULL;
    }

    if (n == 0) {
        usleep(1000); 
    } else {
        sleep(n);
    }

    printf("%d ", n);
    fflush(stdout);
    return NULL;
}

void SleepSort(ARR arr) {
    if (arr.len <= 1) {
        PrintArr(arr);
        return;
    }
    
    if (is_sorted(&arr)) {
        PrintArr(arr); 
        return;
    }

    pthread_t* threads = malloc(sizeof(pthread_t) * arr.len);
    if (!threads) {
        perror("Failed to allocate threads array");
        return;
    }

    int create_cnt = 0;

    for (int i = 0; i < arr.len; i++) {
        int* num = malloc(sizeof(int));
        if (!num) {
            perror("malloc failed");
            continue;
        }
        *num = arr.data[i];

        if (pthread_create(&threads[create_cnt], NULL, sleep_thread_func, num) == 0) {
            create_cnt++;
        } else {
            perror("Pthread Create failed");
            free(num); 
        }
    }

    for (int i = 0; i < create_cnt; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\n"); 
    free(threads); 
}

void GeneralSort(ARR arr){
    printf("General said: This is the order.\n");
    PrintArr(arr);
}

void shuffle(ARR *arr) {
    if (arr->len <= 1) return;
    for (int i = arr->len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr->data[i];
        arr->data[i] = arr->data[j];
        arr->data[j] = temp;
    }
    printf("Shuffled Array:\n");
    PrintArr(*arr);
}

bool is_sorted(const ARR *arr) {
    if (arr->len <= 1) return true;
    for (int i = 0; i < arr->len - 1; i++) {
        if (arr->data[i] > arr->data[i + 1]) {
            return false;
        }
    }
    return true;
}

void PrintArr(ARR arr){
    if (arr.len <= 1) return;
    for (int i = 0; i < arr.len; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}
