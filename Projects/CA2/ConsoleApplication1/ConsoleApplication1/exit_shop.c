#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void exit_shop(struct Shop* UTKala){
	// Freeing all the memory used for products in the shop
	// Freeing all Products of shop will also free the pointers in seller's Products because they're the same
	struct Product* traverse_product = UTKala->Products;
	struct Product* temp_product;
	while (traverse_product != NULL){
		temp_product = traverse_product;
		traverse_product = traverse_product->next;
		free(temp_product);
	}

	// Freeing all the memory used for buyers in the shop
	struct Buyer* traverse_buyer = UTKala->Buyers;
	struct Buyer* temp_buyer;
	while (traverse_buyer != NULL){
		temp_buyer = traverse_buyer;
		traverse_product = traverse_buyer->buyer_products;
		while (traverse_product != NULL){
			temp_product = traverse_product;
			free(traverse_product->name);
			traverse_product = traverse_product->next;
			free(temp_product);
		}
		free(traverse_buyer->username);
		free(traverse_buyer->password);
		traverse_buyer = traverse_buyer->next;
		free(temp_buyer);
	}

	// Freeing all the memory used for sellers in the shop
	struct Seller* traverse_seller = UTKala->Sellers;
	struct Seller* temp_seller;
	while(traverse_seller != NULL){
		temp_seller = traverse_seller;
		traverse_product = traverse_seller->seller_products;
		while (traverse_product != NULL){
			temp_product = traverse_product;
			free(traverse_product->name);
			traverse_product = traverse_product->next;
			free(temp_product);
		}
		free(traverse_seller->username);
		free(traverse_seller->password);
		traverse_seller = traverse_seller->next;
		free(temp_seller);
	}

	// Freeing all the memory used for online users in the shop already done in above
	// Success Message
	printf("\nFreed All Memory and Exited Successfully!\n");
}