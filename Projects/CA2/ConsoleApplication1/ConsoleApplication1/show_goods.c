#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void show_goods(struct Shop* UTKala){
	// Some user has to be logged in for this command to work
	if (UTKala->online_buyer != NULL || UTKala->online_seller != NULL){
		struct Product* traverse_product = UTKala->Products;
		struct Product* printing_list_products = malloc(sizeof(struct Product));
		printing_list_products = NULL;
		while (traverse_product != NULL){
			// Showing the products that are buyable
			if (traverse_product->is_available == 1 && traverse_product->quantity > 0){
				struct Product* new_product = malloc(sizeof(struct Product));
				new_product->name = traverse_product->name;
				new_product->price = traverse_product->price;
				new_product->quantity = traverse_product->quantity;
				new_product->seller_username = traverse_product->seller_username;
				new_product->num_ratings = traverse_product->num_ratings;
				new_product->rating = traverse_product->rating;
				new_product->is_available = traverse_product->is_available;
				new_product->has_been_rated_by_buyer = traverse_product->has_been_rated_by_buyer;
				new_product->next = printing_list_products;
				printing_list_products = new_product;
			}
			traverse_product = traverse_product->next;
		}

		// Sorting the products that are buyable
		traverse_product = make_sorted_list(printing_list_products);
		// Printing an indicator
		printf("Seller Name | Product Name | Product Unit Price | Product Quantity | Average Rating\n");
		while (traverse_product != NULL){
			// Printing the info
			printf("%s | %s | %.2f | %d | %.2f\n", traverse_product->seller_username, traverse_product->name, traverse_product->price, traverse_product->quantity , traverse_product->rating);
			traverse_product = traverse_product->next;
		}
	}
	// No user is logged in
	else{
		printf("No User Has Logged In!\n");
	}
}