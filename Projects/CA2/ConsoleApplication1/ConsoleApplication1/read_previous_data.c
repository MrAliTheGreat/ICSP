#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

#define GOODS_FILE_ADDRESS ".//Goods.txt"
#define USER_FILE_ADDRESS ".//Users.txt"

char* determine_user_type(char* file_name){
	// determining whether the user is buyer or seller
	// Decoding the format and name of the file
	int index = 0;
	while (file_name[index] != '_'){
		index++;
	}
	index++;
	int index_word = 1;
	char* word = NULL;
	while (file_name[index] != '.'){
		word = realloc(word , index_word);
		word[index_word - 1] = file_name[index];
		index_word++;
		index++;
	}
	word[index_word - 1] = '\0';
	// Returning the type
	return word;
}

void read_previous_data(struct Shop* UTKala){
	// This part is for when we restart the program and we have to retrieve the past information

	// Reading Goods.txt
	char** input = get_input_text(GOODS_FILE_ADDRESS);
	// Decoding info and updating parameters of the program accordingly
	if (input[0] != NULL){
		int index = 0;
		while (input[index] != NULL){
			index += 7;
		}
		struct Product* new_product;
		for (int i = index; i != 0; i -= 7){
			// Updating UTKala
			new_product = malloc(sizeof(struct Product));
			new_product->name = input[i - 7];
			new_product->seller_username = input[i - 6];
			new_product->quantity = atoi(input[i - 5]);
			new_product->price = (float)atoi(input[i - 4]);
			new_product->num_ratings = atoi(input[i - 3]);
			new_product->rating = (float)atof(input[i - 2]);
			new_product->is_available = atoi(input[i - 1]);
			new_product->has_been_rated_by_buyer = 0;
			new_product->next = UTKala->Products;
			UTKala->num_products++;
			UTKala->Products = new_product;
		}
		printf("All previous goods restored successfully!\n");
	}

	// Reading Users.txt
	input = get_input_text(USER_FILE_ADDRESS);
	char* address;
	char* user_type;
	char** user_file_input;
	if (input[0] != NULL){
		for (int i = 0; input[i] != NULL; i++){
			// Decoding Users.txt and for every user read from his or her file
			address = malloc(strlen(".//Users//") + strlen(input[i]) + 1);
			strcpy(address, ".//Users//");
			strcat(address, input[i]);
			user_file_input = get_input_text(address);
			if (user_file_input[0] != NULL){
				user_type = determine_user_type(input[i]);
				if (!strcmp(user_type, "buyer")){
					// Updating program parameters if the user is buyer
					struct Buyer* new_buyer = malloc(sizeof(struct Buyer));
					new_buyer->username = user_file_input[0];
					new_buyer->password = user_file_input[1];
					new_buyer->money = (float)atoi(user_file_input[2]);
					new_buyer->num_products = atoi(user_file_input[3]);
					new_buyer->buyer_products = malloc(sizeof(struct Product));
					new_buyer->buyer_products = NULL;
					// Decoding
					for (int j = (new_buyer->num_products * 8) + 4; j != 4 ; j -= 8){
						struct Product* new_buyer_product = malloc(sizeof(struct Product));
						new_buyer_product->name = user_file_input[j - 8];
						new_buyer_product->seller_username = user_file_input[j - 7];
						new_buyer_product->quantity = atoi(user_file_input[j - 6]);
						new_buyer_product->price = (float)atoi(user_file_input[j - 5]);
						new_buyer_product->num_ratings = atoi(user_file_input[j - 4]);
						new_buyer_product->rating = (float)atof(user_file_input[j - 3]);
						new_buyer_product->is_available = atoi(user_file_input[j - 2]);
						new_buyer_product->has_been_rated_by_buyer = atoi(user_file_input[j - 1]);
						new_buyer_product->next = new_buyer->buyer_products;
						new_buyer->buyer_products = new_buyer_product;
					}
					UTKala->num_buyers++;
					new_buyer->next = UTKala->Buyers;
					UTKala->Buyers = new_buyer;
				}
				else{
					// Updating program parameters if the user is sller
					struct Seller* new_seller = malloc(sizeof(struct Seller));
					new_seller->username = user_file_input[0];
					new_seller->password = user_file_input[1];
					new_seller->money = (float)atoi(user_file_input[2]);
					new_seller->num_products = atoi(user_file_input[3]);
					new_seller->seller_products = malloc(sizeof(struct Product));
					new_seller->seller_products = NULL;
					// Decoding
					for (int j = (new_seller->num_products * 7) + 4; j != 4; j -= 7){
						struct Product* new_seller_product = malloc(sizeof(struct Product));
						new_seller_product->name = user_file_input[j - 7];
						new_seller_product->seller_username = user_file_input[j - 6];
						new_seller_product->quantity = atoi(user_file_input[j - 5]);
						new_seller_product->price = (float)atoi(user_file_input[j - 4]);
						new_seller_product->num_ratings = atoi(user_file_input[j - 3]);
						new_seller_product->rating = (float)atof(user_file_input[j - 2]);
						new_seller_product->is_available = atoi(user_file_input[j - 1]);
						new_seller_product->has_been_rated_by_buyer = 0;
						new_seller_product->next = new_seller->seller_products;
						new_seller->seller_products = new_seller_product;
					}
					UTKala->num_sellers++;
					new_seller->next = UTKala->Sellers;
					UTKala->Sellers = new_seller;
				}
			}
		}
		printf("All previous buyers and sellers restored successfully!\n");
	}
}