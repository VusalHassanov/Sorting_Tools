#include "Lab2Lib.h"

void initArray(int myArray[], int k) {
	int number;
	srand(time(0));

	if (k > MAX_SIZE) {
		k = MAX_SIZE;
	}

	for (int i = 0; i < MAX_SIZE - k; i++) {
		myArray[i] = i + 1;
	}

	for (int j = MAX_SIZE-k; j < MAX_SIZE; j++) {
		number = rand() % 50;
		myArray[j] = number;
	}
}



void printArray(int myArray[]) {
	
	printf("[");
	for (int i = 0; i < MAX_SIZE; i++) {
		printf(" %d ", myArray[i]);
	}
	printf("]\n");
}

void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int insertionSort(int array[]) {
	int i = 1;
	int j = 0;
	int count = 0;

	while (i < MAX_SIZE) {
		j = i;
		count++;
		while ((j > 0) && (array[j - 1] > array[j])) {
			swap(array, j, j - 1);
			j = j - 1;
			count++;
		}
		i = i + 1;
	}
	return count;
}

int less(int a, int b) {
	if (a < b) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void selectionSort(int array[], int *count) {
	for (int i = 0; i < MAX_SIZE; i++) {
		int min = i;
		for (int j = i + 1; j < MAX_SIZE; j++) {
			if (less(array[j], array[min])) {
				min = j;
			}
			*count++;
		}
		swap(array, i, min);
		*count++;
	}
}


/*
int selectionSort(int array[]) {
	int count = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		int min = i;
		for (int j = i + 1; j < MAX_SIZE; j++) {
			if (less(array[j], array[min])) {
				min = j;
			}
			count++;
		}
		swap(array, i, min);
		count++;
	}
	return count;
}
*/
int isSorted(int array[]) {
	for (int i = 1; i < MAX_SIZE; i++) {
		if (less(array[i], array[i - 1]))
			return FALSE;
	}
	return TRUE;
}

int mergesort(int array[], int l, int r) {
	// End of recursion reached?
	if (l >= r)
		return;

	int m = l + (r - l) / 2;
	mergesort(array, l, m);
	mergesort(array, m + 1, r);
	int count = merge(array, l, m, r);
	return count;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
int merge(int array[], int l, int m, int r) {
	int i, j, k;
	int count = 0;
	int leftSize = m - l + 1;
	int rightSize = r - m;

	/* create temp arrays */
	int leftArray[MAX_SIZE], rightArray[MAX_SIZE];

	/* Copy data to temp arrays leftArray[] and rightArray[] */
	for (i = 0; i < leftSize; i++)
		leftArray[i] = array[l + i];
	for (j = 0; j < rightSize; j++)
		rightArray[j] = array[m + 1 + j];

	/* Merge the temp arrays back into array[l..r]*/
	// Initial index of first subarray
	i = 0;
	// Initial index of second subarray
	j = 0;
	// Initial index of merged subarray
	k = l;

	while ((i < leftSize) && (j < rightSize)) {
		count++;
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of left side[], if there	are any */
	while (i < leftSize) {
		array[k] = leftArray[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < rightSize) {
		array[k] = rightArray[j];
		j++;
		k++;
	}
	return count;
}

int minimum(int x, int y) {
	return (x < y) ? x : y;
}

/* Iterative mergesort function to sort arr[0...n-1] */
int mergesortBU(int array[], int arraySize) {
	int count;
	// For current size of subarrays to be merged
	// curr_size varies from 1 to n/2
	int currSize;
	// For picking starting index of left subarray
	// to be merged
	int leftStart;

	// Merge subarrays in bottom up manner. First merge subarrays of
	// size 1 to create sorted subarrays of size 2, then merge subarrays
	// of size 2 to create sorted subarrays of size 4, and so on.
	for (currSize = 1; currSize <= arraySize - 1; currSize = 2 * currSize) {
		// Pick starting point of different subarrays of current size
		for (leftStart = 0; leftStart < arraySize - 1; leftStart += 2 * currSize) {
			// Find ending point of left subarray. mid+1 is starting
			// point of right
			int mid = minimum(leftStart + currSize - 1, arraySize - 1);

			int right_end = minimum(leftStart + 2 * currSize - 1, arraySize - 1);

			// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
			count = mergeBU(array, leftStart, mid, right_end);
		}
	}
	return count;
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
int mergeBU(int array[], int l, int m, int r) {
	int i, j, k;
	int count = 0;
	int leftSize = m - l + 1;
	int rightSize = r - m;

	/* create temp arrays */
	int leftPart[MAX_SIZE], rightPart[MAX_SIZE];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < leftSize; i++)
		leftPart[i] = array[l + i];
	for (j = 0; j < rightSize; j++)
		rightPart[j] = array[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < leftSize && j < rightSize) {
		count++;
		if (leftPart[i] <= rightPart[j]) {
			array[k] = leftPart[i];
			i++;
		}
		else {
			array[k] = rightPart[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < leftSize) {
		array[k] = leftPart[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < rightSize) {
		array[k] = rightPart[j];
		j++;
		k++;
	}
	return count;
}

void quicksort(int array[], int l, int r) {
	if (r - l <= 0)
		return;
	int m = partition(array, l, r);
	quicksort(array, l, m - 1);
	quicksort(array, m + 1, r);
}

int partition(int array[], int l, int r) {
	int i = l - 1;
	int j = r;
	while (TRUE) {
		// find item on left
		while (less(array[++i], array[r]))
			if (i == r)
				// to swap
				break;
		// find item on right
		while (less(array[r], array[--j]))
			// to swap
			if (j == l)
				break;
		// do pointers cross ?
		if (i >= j)
			break;
		// otherwise do swap
		swap(array, i, j);
	}
	// final swap
	swap(array, i, r);
	// return index of cross point
	return i;
}

int shellSort(int array[]) {
	int count=0;
	for (int interval = MAX_SIZE / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < MAX_SIZE; i += 1) {
			int temp = array[i];
			int j;
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
				array[j] = array[j - interval];
			}
			array[j] = temp;
			count++;
		}
	}
	return count;
}

/*void bubbleSort(int array, int sortable) {
	int swapped;
	while (swapped == TRUE) {
		swapped = FALSE;
		for (int i = 1; i < MAX_SIZE - 1; i++) {
			if (array[i - 1] > array[i]) {

			}
		}
	}
}
*/