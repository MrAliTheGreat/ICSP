#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

#define USER_FILE_ADDRESS ".//Users.txt"

void add_seller_to_users_file(struct Seller* seller){
	// address users' file for storing all users' file name
	FILE* file_names = fopen(USER_FILE_ADDRESS, "a");
	if (file_names == NULL){
		// File didn't open successfully
		printf("Writing To File Failed!\n");
	}
	else{
		// Writing the name in the right format in users' file
		fprintf(file_names, "%s_seller.txt\n", seller->username);
		fclose(file_names);
		printf("Writing to users file was successfully done!\n");
	}
}