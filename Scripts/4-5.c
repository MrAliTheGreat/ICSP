#include <stdio.h>
#include <stdlib.h>

// Function for insertion sort
void insertionSort(int numbers[], int len)
{
	// Inserting new value at the right place
	int i, value, j;
	for (i = 1; i < len; i++) {
		value = numbers[i];
		j = i - 1;
		while (j >= 0 && numbers[j] > value) {
			numbers[j + 1] = numbers[j];
			j = j - 1;
		}
		numbers[j + 1] = value;
	}
}

int main(){
	// Getting len from user
	int len;
	scanf(" %d", &len);
	// Use malloc for creating space with user's input
	int* numbers = malloc(len * sizeof(int));
	for (int i = 0; i < len; i++){
		scanf(" %d", numbers + i);
	}
	// Sort the array
	insertionSort(numbers, len);

	// Printing array
	for (int i = 0; i < len; i++){
		printf("%d ", numbers[i]);
	}
	printf("\n");

	return 0;
}