#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

struct Product* find_product(struct Product* products, char* goods_name, char* seller_username){
	// Finding product with input info
	// Added for phase 2
	struct Product* traverse_product = products;
	while (traverse_product != NULL){
		if (!strcmp(traverse_product->name, goods_name) && !strcmp(traverse_product->seller_username, seller_username)){
			return traverse_product;
		}
		traverse_product = traverse_product->next;
	}
	return NULL;
}