#include <stdio.h>
#include <stdlib.h>

#define ARR1_SIZE 5
#define ARR2_SIZE 3

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
	List* current = head;
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

List* merge(List* list1, List* list2){
	// Base condition
	if (list1 == NULL){
		return list2;
	}
	if (list2 == NULL){
		return list1;
	}

	// Recursive part for moving one element at a time
	if (list1->data < list2->data){
		list1->next = merge(list1->next, list2);
		return list1;
	}
	else{
		list2->next = merge(list1, list2->next);
		return list2;
	}
}

int main(){
	int arr1[ARR1_SIZE] = { 10, 5, 4, 3, 1 };
	int arr2[ARR2_SIZE] = { 8, 4, 2 };
	// Allocating memory and creating head of linked list 1
	List* head1 = malloc(sizeof(List));
	head1->next = NULL;

	// Allocating memory and creating head of linked list 2
	List* head2 = malloc(sizeof(List));
	head2->next = NULL;

	// Putting test values in linked list 1
	List* new_item;
	for (int i = 0; i < ARR1_SIZE; i++){
		new_item = malloc(sizeof(List));
		new_item->data = arr1[i];
		add_to_list(head1, new_item);
	}
	// Putting test values in linked list 2
	for (int i = 0; i < ARR2_SIZE; i++){
		new_item = malloc(sizeof(List));
		new_item->data = arr2[i];
		add_to_list(head2, new_item);
	}
	// Printing and Testing merge function
	print_list(merge(head1->next, head2->next));

	return 0;
}