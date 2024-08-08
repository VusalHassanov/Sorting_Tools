
#include "Lab2Lib.h"

void main() {
	
	int myArray[MAX_SIZE];
	int count = 0;
	
	printf("--------------------\nUnsortedArray\n");
	initArray(myArray, 10);
	printArray(myArray);

	
	printf("--------------------\nInsertionSort\n");
	count = insertionSort(myArray);
	printArray(myArray);
	printf("count = %d\n", count);
	
	printf("--------------------\nSelectionSort\n");
	selectionSort(myArray, &count);
	printArray(myArray);
	printf("count = %d\n", count);
	

	printf("--------------------\nShellSort\n");
	count = shellSort(myArray);
	printArray(myArray);
	printf("count = %d\n", count);
	
	printf("--------------------\nMergeSort\n");
	count = mergesort(myArray, 0, MAX_SIZE-1);
	printArray(myArray);
	printf("count = %d\n", count);

	printf("--------------------\nMergeSortButtomUp\n");
	count = mergesortBU(myArray, MAX_SIZE);
	printArray(myArray);
	printf("count = %d\n", count);
	

	
	printf("--------------------\nQuickSort\n");
	quicksort(myArray, 0, MAX_SIZE-1);
	printArray(myArray);
	
	
	

	
		/*
	for (int k = 20; k < MAX_SIZE; k = 2 * k) {
		printf("--------------------\nUnsortedArray\n");
		initArray(myArray, k);
		printArray(myArray);

		
		printf("--------------------\nInsertionSort\n");
		count = insertionSort(myArray);
		printArray(myArray);
		printf("count = %d\n", count);

		printf("--------------------\nSelectionSort\n");
		count = selectionSort(myArray);
		printArray(myArray);
		printf("count = %d\n", count);

		printf("--------------------\nShellSort\n");
		count = shellSort(myArray);
		printArray(myArray);
		printf("count = %d\n", count);

		printf("--------------------\nMergeSort\n");
		count = mergesort(myArray, 0, MAX_SIZE - 1);
		printArray(myArray);
		printf("count = %d\n", count);

		printf("--------------------\nMergeSortButtomUp\n");
		count = mergesortBU(myArray, MAX_SIZE);
		printArray(myArray);
		printf("count = %d\n", count);

		printf("--------------------\nQuickSort\n");
		quicksort(myArray, 0, MAX_SIZE - 1);
		printArray(myArray);
	}
		*/

	
	

}