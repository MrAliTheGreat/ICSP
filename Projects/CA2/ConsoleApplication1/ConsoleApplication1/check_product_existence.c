#include <stdio.h>
#include <string.h>

#include "Headers.h"

int check_product_existence(struct Product* Products, char* goods_name , char* online_seller_username){
	// Check whether the product already exists or not
	// -2: Product doesn't exist
	// -1: Product exists but the seller doesn't match
	// >0 : Index of the product that exists and also the seller matches with its seller username

	// Changed a bit because of linked list implementation
	struct Product* traverse_product = Products;
	int i = 0;
	while (traverse_product != NULL){
		if (!strcmp(traverse_product->name, goods_name)){
			if (!strcmp(traverse_product->seller_username, online_seller_username)){
				return i;
			}
			else{
				return -1;
			}
		}
		i++;
		traverse_product = traverse_product->next;
	}
	return -2;
}