#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void increse_seller_money(struct Shop* UTKala, char* seller_username, float amount){
	// Finding the seller by username and increasing its balance
	struct Seller* traverse_seller = UTKala->Sellers;
	while (traverse_seller != NULL){
		if (!strcmp(traverse_seller->username, seller_username)){
			traverse_seller->money += amount;
			// Updatind file
			add_seller_to_file(traverse_seller);
		}
		traverse_seller = traverse_seller->next;
	}
}