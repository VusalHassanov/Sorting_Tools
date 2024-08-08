#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 20

void swap(int array[], int i, int j);
int insertionSort(int array[]);
void printArray(int myArray[]);
void initArray(int myArray[], int k);
//int selectionSort(int array[]);
void selectionSort(int array[], int *counter);
int less(int a, int b);
int merge(int array[], int l, int m, int r);
int isSorted(int array[]);
int mergesort(int array[], int l, int r);
int minimum(int x, int y);
int mergesortBU(int array[], int arraySize);
int mergeBU(int array[], int l, int m, int r);
void quicksort(int array[], int l, int r);
int partition(int array[], int l, int r);
int shellSort(int array[]);