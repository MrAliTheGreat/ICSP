#include <stdio.h>
#include <stdlib.h>

// Slightly different that code 8 this one uses pointers
int find_first(char* word_1 , char*word_2){
	int i = 0, j = 0;
	while (*(word_1 + i) != '\0' && *(word_2 + j) != '\0'){
		// if ascii code of first word is smaller then the first word comes first
		if ((int)*(word_1 + i) < (int)*(word_2 + j)){
			return 1;
		}
		// if ascii code of second word is smaller then the second word comes first
		else if ((int)*(word_1 + i) > (int)*(word_2 + j)){
			return 2;
		}
		i++;
		j++;
	}
	return 0;
}

// Different insertionSort from code 5 this one will use find_first for comparing two pointers
void insertionSort(char** student_names, int len)
{
	int i, j;
	char* value;
	for (i = 1; i < len; i++) {
		value = student_names[i];
		j = i - 1;
		while (j >= 0 && find_first(value , student_names[j]) == 1) {
			student_names[j + 1] = student_names[j];
			j = j - 1;
		}
		student_names[j + 1] = value;
	}
}

void print_name(char* student){
	int k = 0;
	while (*(student + k) != '\0'){
		printf("%c", *(student + k));
		k++;
	}
	printf("\n");
}

int main(){
	int len , quit = 0;
	scanf(" %d" , &len);
	// Array of pointers to char
	char** student_names = malloc(len * sizeof(char*));
	// Length of each name is maximum 100
	for (int i = 0; i < len; i++){
		student_names[i] = malloc(100 * sizeof(char));
	}

	// Getting names from user
	for (int i = 0; i < len; i++){
		scanf(" %s", student_names[i]);
	}
	
	// Do the insertion sort
	insertionSort(student_names, len);

	// Printing the list of students alphabetically
	int j = 0;
	for (int i = 0; i < len; i++){
		while (*(student_names[i] + j) != '\0'){
			printf("%c" , *(student_names[i] + j));
			j++;
		}
		j = 0;
		printf("\n");
	}
	return 0;
}