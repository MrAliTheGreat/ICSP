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

List* create_linked_list(int n, int* arr){
	// Allocating memory for head and creating head
	List* head = malloc(sizeof(List));
	head->next = NULL;
	List* new_element;
	for (int i = n - 1; i >= 0; i--){
		// Allocating memory for new item and creating it and adding it to the list
		new_element = malloc(sizeof(List));
		new_element->data = arr[i];
		add_to_list(head, new_element);
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
	// Creating linked list and printing it
	print_list(create_linked_list(n, arr));
	return 0;
}