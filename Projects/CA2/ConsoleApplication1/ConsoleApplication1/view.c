#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void view(struct Shop* UTKala){
	// Changed a little bit because of linked list implementation
	// buyer is online
	if (UTKala->online_buyer != NULL && UTKala->online_seller == NULL){
		// Printing an indicator
		printf("Username | Role | Balance\n");
		// Printing info
		printf("%s | buyer | %.2f\n" , UTKala->online_buyer->username , UTKala->online_buyer->money);
		// Printing an indicator
		printf("\nProduct Name | Product Unit Price | Bought Product Quantity | Seller Name\n");
		struct Product* traverse_product = UTKala->online_buyer->buyer_products;
		while (traverse_product != NULL){
			// Printing info
			printf("%s | %.2f | %d | %s\n", traverse_product->name, traverse_product->price, traverse_product->quantity, traverse_product->seller_username);
			traverse_product = traverse_product->next;
		}
	}
	// seller is online
	else if (UTKala->online_buyer == NULL && UTKala->online_seller != NULL){
		// Printing an indicator
		printf("Username | Role | Balance\n");
		// Printing info
		printf("%s | seller | %.2f\n", UTKala->online_seller->username, UTKala->online_seller->money);
		// Printing an indicator
		printf("\nProduct Name | Product Unit Price | Product Quantity\n");
		struct Product* traverse_product = UTKala->online_seller->seller_products;
		while (traverse_product != NULL){
			// Printing info
			printf("%s | %.2f | %d\n", traverse_product->name, traverse_product->price, traverse_product->quantity);
			traverse_product = traverse_product->next;
		}
	}
	// No user is online
	else{
		printf("No User Has Logged In!\n");
	}
}