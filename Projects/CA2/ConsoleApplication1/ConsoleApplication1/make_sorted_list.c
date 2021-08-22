#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

int find_first(char* word_1, char*word_2){
	// 0: words are the same
	// 1: word_1 comes first
	// 2: word_2 comes first
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

struct Product* insertion_sort(struct Product* sorted_list , struct Product* inserting_product){
	struct Product* traverse_product;
	// The list is empty or there is insertion point at the start
	if (sorted_list == NULL || find_first(sorted_list->name , inserting_product->name) == 2){
		inserting_product->next = sorted_list;
		sorted_list = inserting_product;
	}
	else{
		// find the place for insertion
		traverse_product = sorted_list;
		while (traverse_product->next != NULL && find_first(traverse_product->next->name , inserting_product->name) == 1){
			traverse_product = traverse_product->next;
		}
		inserting_product->next = traverse_product->next;
		traverse_product->next = inserting_product;
	}
	// Now it's put at the right place and sorted_list is sorted
	return sorted_list;
}

struct Product* make_sorted_list(struct Product* products){
	// This part is for show_goods so that we show the products in alphabetic order
	struct Product* sorted_list = malloc(sizeof(struct Product));
	sorted_list = NULL;
	struct Product* traverse_product = products;
	while (traverse_product != NULL){
		// Take every product and use insertion sort to put it in alphabetic order
		// At the end the list will be sorted

		// Making a copy of the product so that the next attribute doesn't get messed up in the main list
		struct Product* copy_product = malloc(sizeof(struct Product));
		copy_product->name = traverse_product->name;
		copy_product->price = traverse_product->price;
		copy_product->quantity = traverse_product->quantity;
		copy_product->seller_username = traverse_product->seller_username;
		copy_product->num_ratings = traverse_product->num_ratings;
		copy_product->rating = traverse_product->rating;
		copy_product->is_available = traverse_product->is_available;
		copy_product->has_been_rated_by_buyer = traverse_product->has_been_rated_by_buyer;
		copy_product->next = NULL;
		sorted_list = insertion_sort(sorted_list , copy_product);
		traverse_product = traverse_product->next;
	}
	return sorted_list;
}