#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

struct Product* make_copy(struct Product* products){
	// Making a copy of products' list and returning it
	struct Product* traverse_product = products;
	struct Product* copy_list = malloc(sizeof(struct Product));
	copy_list = NULL;
	while (traverse_product != NULL){
		struct Product* copy_product = malloc(sizeof(struct Product));
		copy_product->name = traverse_product->name;
		copy_product->price = traverse_product->price;
		copy_product->quantity = traverse_product->quantity;
		copy_product->seller_username = traverse_product->seller_username;
		copy_product->num_ratings = traverse_product->num_ratings;
		copy_product->rating = traverse_product->rating;
		copy_product->is_available = traverse_product->is_available;
		copy_product->has_been_rated_by_buyer = traverse_product->has_been_rated_by_buyer;
		copy_product->next = copy_list;
		copy_list = copy_product;
		traverse_product = traverse_product->next;
	}
	return copy_list;
}