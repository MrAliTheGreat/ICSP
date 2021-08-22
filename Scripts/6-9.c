#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

struct List{
	int data;
	List* next;
};

void add_to_list(List* head_of_list, List* new_item) {
	// Adding to list
	if (new_item == NULL || head_of_list == NULL)
		return;
	new_item->next = head_of_list->next;
	head_of_list->next = new_item;
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

List* remove_repetition(List* list){
	List* current = list->next;
	List* temp;
	while (current->next != NULL){
		// Traversing and checking the condition for duplicates
		if (current->data == current->next->data){
			temp = current->next->next;
			free(current->next);
			current->next = temp;
		}
		// Only go to next of current if there's no repetition
		else{
			current = current->next;
		}
	}
	// Returning the updated list
	return list;
}

int main(){
	// Test values
	int arr[] = { 12, 10, 10, 10, 10, 3, 3, 1 };

	// Allocating memory and creating head of linked list
	List* head1 = malloc(sizeof(List));
	head1->next = NULL;

	// Putting test values in linked list
	List* new_item;
	for (int i = 0; i < 8; i++){
		new_item = malloc(sizeof(List));
		new_item->data = arr[i];
		add_to_list(head1, new_item);
	}

	// Printing and Testing remove_repetition function
	print_list(remove_repetition(head1));

	return 0;
}