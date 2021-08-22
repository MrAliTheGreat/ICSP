#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

struct List{
	int data;
	List* next;
};

List* create_sorted_linked_list(int n, int* arr){
	// Allocating memory and creating head of the list
	List* head = malloc(sizeof(List));
	head->next = NULL;

	List* new_element;
	List* current;
	for (int i = n - 1; i >= 0; i--){
		current = head->next;
		// Allocating memory and creating new item
		new_element = malloc(sizeof(List));
		new_element->data = arr[i];
		// condition for inserting at the start of the list
		if (current == NULL || current->data > new_element->data){
			new_element->next = current;
			head->next = new_element;
		}
		else{
			// Finding the right place for insertion
			while (current->next != NULL && current->next->data < new_element->data){
				current = current->next;
			}
			// Updating list
			new_element->next = current->next;
			current->next = new_element;
		}
	}
	return head;
}

void print_list(List* head){
	// Print linked list function for testing
	List* current = head->next;
	// Creating the format of in the question
	printf("{");
	while (current != NULL){
		if (current->next == NULL){
			printf("%d", current->data);
		}
		else{
			printf("%d -> ", current->data);
		}
		current = current->next;
	}
	printf("}");
	printf("\n");
}

int main(){
	int n;
	// Getting n from user
	scanf("%d", &n);
	int* arr = malloc(n * sizeof(List));
	for (int i = 0; i < n; i++){
		// Getting numbers from user
		scanf(" %d", arr + i);
	}
	// Creating sorted linked list
	print_list(create_sorted_linked_list(n, arr));

	return 0;
}