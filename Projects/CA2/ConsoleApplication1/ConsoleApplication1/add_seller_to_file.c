#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void add_seller_to_file(struct Seller* seller){
	// address seller from Users' folder
	char* address = malloc(strlen(".//Users//") + strlen(seller->username) + strlen("_seller.txt") + 1);
	strcpy(address, ".//Users//");
	strcat(address, seller->username);
	strcat(address, "_seller.txt");

	// Making the file empty for updating
	fclose(fopen(address, "w"));

	FILE* file_users = fopen(address, "a");
	if (file_users == NULL){
		// File didn't open successfully
		printf("Writing to file failed!\n");
	}
	else{
		// Reading from program's info and writing it in text file
		fprintf(file_users, "%s,%s,%f,%d\n", seller->username, seller->password, seller->money, seller->num_products);
		struct Product* traverse_product = seller->seller_products;
		while (traverse_product != NULL){
			// Needed info
			fprintf(file_users, "%s,%s,%d,%f,%d,%f,%d\n", traverse_product->name, traverse_product->seller_username, traverse_product->quantity, traverse_product->price , traverse_product->num_ratings , traverse_product->rating , traverse_product->is_available);
			traverse_product = traverse_product->next;
		}
		fclose(file_users);
		printf("Writing to seller file was successfully done!\n");
	}
}