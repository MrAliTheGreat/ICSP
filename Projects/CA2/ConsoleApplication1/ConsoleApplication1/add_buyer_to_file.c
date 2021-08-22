#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void add_buyer_to_file(struct Buyer* buyer){
	// address buyer from Users' folder
	char* address = malloc(strlen(".//Users//") + strlen(buyer->username) + strlen("_buyer.txt") + 1);
	strcpy(address, ".//Users//");
	strcat(address, buyer->username);
	strcat(address, "_buyer.txt");

	// Making the file empty for updating
	fclose(fopen(address, "w"));

	FILE* file_users = fopen(address, "a");
	if (file_users == NULL){
		// File didn't open successfully
		printf("Writing to file failed!\n");
	}
	else{
		// Reading from program's info and writing it in text file
		fprintf(file_users, "%s,%s,%f,%d\n", buyer->username, buyer->password, buyer->money, buyer->num_products);
		struct Product* traverse_product = buyer->buyer_products;
		while (traverse_product != NULL){
			// Needed info
			fprintf(file_users, "%s,%s,%d,%f,%d,%f,%d,%d\n", traverse_product->name, traverse_product->seller_username, traverse_product->quantity, traverse_product->price , traverse_product->num_ratings , traverse_product->rating , traverse_product->is_available , traverse_product->has_been_rated_by_buyer);
			traverse_product = traverse_product->next;
		}
		fclose(file_users);
		printf("Writing to buyer file was successfully done!\n");
	}
}