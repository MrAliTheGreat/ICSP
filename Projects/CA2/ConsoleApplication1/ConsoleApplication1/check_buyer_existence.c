#include <stdio.h>
#include <string.h>

#include "Headers.h"

int check_buyer_existence(struct Buyer* Buyers, char* username){
	// Check whether seller already exists or not
	// Changed a bit because of linked list implementation
	struct Buyer* traverse_buyer = Buyers;
	while (traverse_buyer != NULL){
		if (!strcmp(traverse_buyer->username, username)){
			return 1;
		}
		traverse_buyer = traverse_buyer->next;
	}
	return 0;
}