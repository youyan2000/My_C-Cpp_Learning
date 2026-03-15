#ifndef _SORT_H_
#define _SORT_H_

#define SORT_LEN 100

typedef struct {
	int data[SORT_LEN];
	int len;
} ARR;

ARR CreateSort();

ARR BubbleSort(ARR arr);
ARR StalinSort(ARR arr);
ARR GnomeSort(ARR arr);
ARR MaoSort(ARR arr);
ARR CocktailSort(ARR arr);
ARR ShellSort(ARR arr);

void PrintArr(ARR arr);

#endif
