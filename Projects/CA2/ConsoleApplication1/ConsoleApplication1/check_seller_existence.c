#include <stdio.h>
#include <string.h>

#include "Headers.h"

int check_seller_existence(struct Seller* Sellers, char* username){
	// Check whether the seller already exists or not
	// Changed a bit because of linked list implementation
	struct Seller* traverse_seller = Sellers;
	while (traverse_seller != NULL){
		if (!strcmp(traverse_seller->username, username)){
			return 1;
		}
		traverse_seller = traverse_seller->next;
	}
	return 0;
}