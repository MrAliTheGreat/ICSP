#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

#define GOODS_FILE_ADDRESS ".//Goods.txt"

void add_good_to_file(struct Product* products){
	// Emptying the file for update
	fclose(fopen(GOODS_FILE_ADDRESS, "w"));

	// Opening the goods' file
	FILE* file_goods = fopen(GOODS_FILE_ADDRESS, "a");
	if (file_goods == NULL){
		// Goods' file didn't open successfully
		printf("Writing to file failed!\n");
	}
	else{
		// Writing info in goods' file
		struct Product* traverse_product = products;
		while (traverse_product != NULL){
			// Needed info
			fprintf(file_goods, "%s,%s,%d,%f,%d,%f,%d\n", traverse_product->name, traverse_product->seller_username, traverse_product->quantity, traverse_product->price , traverse_product->num_ratings , traverse_product->rating , traverse_product->is_available);
			traverse_product = traverse_product->next;
		}
		// Success message
		printf("Writing to Goods file was successfully done!\n");
		fclose(file_goods);
	}
}