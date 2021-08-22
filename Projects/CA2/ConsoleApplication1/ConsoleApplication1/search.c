#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

struct Product* remove_undesired_product(struct Product* products, char* goods_name , char* seller_username){
	// Removing undesired product from the list so that the desired products remain
	int remove_status = check_product_existence(products, goods_name, seller_username);
	if (remove_status >= 0){
		// Finding the product
		struct Product* traverse_product = products;
		struct Product* previous_product;
		int index = 0;
		while (index != remove_status){
			previous_product = traverse_product;
			traverse_product = traverse_product->next;
			index++;
		}
		// Removing found product in linked list way
		if (index == 0){
			products = traverse_product->next;
		}
		else{
			previous_product->next = traverse_product->next;
		}
	}
	// Returning the list with undesired product removed
	return products;
}

struct Product* update_desired_products_max_price(struct Product* products, float max_price){
	struct Product* traverse_product = products;
	struct Product* temp;
	while (traverse_product != NULL){
		// Traversing the list a removing the undesired products
		if (traverse_product->price > max_price || !traverse_product->is_available || traverse_product->quantity <= 0){
			// Keeping the desired product by checking the attribute, availability and quantity
			products = remove_undesired_product(products , traverse_product->name , traverse_product->seller_username);
			temp = traverse_product;
			traverse_product = traverse_product->next;
			free(temp);
			continue;
		}
		traverse_product = traverse_product->next;
	}
	// Returning the list with desired products
	return products;
}

struct Product* update_desired_products_min_price(struct Product* products, float min_price){
	struct Product* traverse_product = products;
	struct Product* temp;
	while (traverse_product != NULL){
		// Traversing the list a removing the undesired products
		if (traverse_product->price < min_price || !traverse_product->is_available || traverse_product->quantity <= 0){
			// Keeping the desired product by checking the attribute, availability and quantity
			products = remove_undesired_product(products, traverse_product->name, traverse_product->seller_username);
			temp = traverse_product;
			traverse_product = traverse_product->next;
			free(temp);
			continue;
		}
		traverse_product = traverse_product->next;
	}
	// Returning the list with desired products
	return products;
}

struct Product* update_desired_products_name(struct Product* products, char* name){
	struct Product* traverse_product = products;
	struct Product* temp;
	while (traverse_product != NULL){
		// Traversing the list a removing the undesired products
		if (strcmp(traverse_product->name, name) || !traverse_product->is_available || traverse_product->quantity <= 0){
			// Keeping the desired product by checking the attribute, availability and quantity
			products = remove_undesired_product(products, traverse_product->name, traverse_product->seller_username);
			temp = traverse_product;
			traverse_product = traverse_product->next;
			free(temp);
			continue;
		}
		traverse_product = traverse_product->next;
	}
	// Returning the list with desired products
	return products;
}

struct Product* update_desired_products_seller_username(struct Product* products, char* seller_username){
	struct Product* traverse_product = products;
	struct Product* temp;
	while (traverse_product != NULL){
		// Traversing the list a removing the undesired products
		if (strcmp(traverse_product->seller_username, seller_username) || !traverse_product->is_available || traverse_product->quantity <= 0){
			// Keeping the desired product by checking the attribute, availability and quantity
			products = remove_undesired_product(products, traverse_product->name, traverse_product->seller_username);
			temp = traverse_product;
			traverse_product = traverse_product->next;
			free(temp);
			continue;
		}
		traverse_product = traverse_product->next;
	}
	// Returning the list with desired products
	return products;
}

void show_desired_products(struct Product* products){
	struct Product* traverse_product = products;
	// Printing an indicator
	printf("Seller Name | Product Name | Product Unit Price | Product Quantity | Average Rating\n");
	while (traverse_product != NULL){
		// Printing the info
		printf("%s | %s | %.2f | %d | %.2f\n", traverse_product->seller_username, traverse_product->name, traverse_product->price, traverse_product->quantity, traverse_product->rating);
		traverse_product = traverse_product->next;
	}
}

void search(struct Shop* UTKala, int num_conditions){
	char** input;
	// A user has to be online for search to work and be valid
	if (UTKala->online_buyer != NULL || UTKala->online_seller != NULL){
		// Check if the number of conditions is valid meaning it must be between 1 to 4
		if (num_conditions >= 1 && num_conditions <= 4){
			int max_price_chosen = 0, min_price_chosen = 0, name_chosen = 0, seller_username_chosen = 0;
			// Making a copy so that next parameter for each element doesn't get messed up in the main list
			struct Product* desired_products = make_copy(UTKala->Products);
			for (int i = 0; i < num_conditions; i++){
				input = get_input();
				if (!strcmp(input[0] , "max_price")){
					// Check whether this attribute has already been used
					if (!max_price_chosen){
						// Keeping desired product each time by eliminating the unmatched products from desired_products
						desired_products = update_desired_products_max_price(desired_products, (float)atof(input[1]));
						max_price_chosen = 1;
					}
					else{
						printf("Attribute Already Chosen!\n");
					}
				}
				else if (!strcmp(input[0], "min_price")){
					// Check whether this attribute has already been used
					if (!min_price_chosen){
						// Keeping desired product each time by eliminating the unmatched products from desired_products
						desired_products = update_desired_products_min_price(desired_products, (float)atof(input[1]));
						min_price_chosen = 1;
					}
					else{
						printf("Attribute Already Chosen!\n");
					}
				}
				else if (!strcmp(input[0], "name")){
					// Check whether this attribute has already been used
					if (!name_chosen){
						// Keeping desired product each time by eliminating the unmatched products from desired_products
						desired_products = update_desired_products_name(desired_products, input[1]);
						name_chosen = 1;
					}
					else{
						printf("Attribute Already Chosen!\n");
					}
				}
				else if (!strcmp(input[0], "seller_username")){
					// Check whether this attribute has already been used
					if (!seller_username_chosen){
						// Keeping desired product each time by eliminating the unmatched products from desired_products
						desired_products = update_desired_products_seller_username(desired_products, input[1]);
						seller_username_chosen = 1;
					}
					else{
						printf("Attribute Already Chosen!\n");
					}
				}
				else{
					printf("Good's Attribute Not Valid!\n");
				}
			}
			// Sorting final desired_products for printing
			struct Product* sorted_desired_products = make_sorted_list(desired_products);
			// Showing (printing) the final desired and soted list
			show_desired_products(sorted_desired_products);
		}
		else{
			printf("Number of Conditions Isn't Valid It Must Be Between 1 to 4!\n");
		}
	}
	else{
		printf("No User Has Logged In!\n");
	}
}