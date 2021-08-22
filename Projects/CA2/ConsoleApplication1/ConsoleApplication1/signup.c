#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void signup(struct Shop* UTKala , char* username, char* password, char* user_type){
	// Checking the role , examining existence of the username for checking uniqueness and checking if a user is online or not
	if (!strcmp(user_type, "buyer") && !check_buyer_existence(UTKala->Buyers, username) && (UTKala->online_buyer == NULL && UTKala->online_seller == NULL)){
		// Creating a new buyer
		struct Buyer* new_buyer = malloc(sizeof(struct Buyer));
		new_buyer->username = username;
		new_buyer->password = password;
		new_buyer->money = 0;
		new_buyer->buyer_products = malloc(sizeof(struct Product));
		new_buyer->buyer_products = NULL;
		new_buyer->num_products = 0;
		// Updating memory size for the new Buyer and adding the Buyer to shop's buyers
		UTKala->num_buyers++;
		new_buyer->next = UTKala->Buyers;
		UTKala->Buyers = new_buyer;

		// Adding buyer to txt file
		add_buyer_to_file(new_buyer);
		// Adding new user to Users.txt
		add_buyer_to_users_file(new_buyer);

		// Printing success message
		printf("New Buyer Signed Up Successfully!\n");
	}
	else if (!strcmp(user_type, "seller") && !check_seller_existence(UTKala->Sellers, username) && (UTKala->online_buyer == NULL && UTKala->online_seller == NULL)){
		// Creating a new seller
		struct Seller* new_seller = malloc(sizeof(struct Seller));
		new_seller->username = username;
		new_seller->password = password;
		new_seller->money = 0;
		new_seller->seller_products = malloc(sizeof(struct Product));
		new_seller->seller_products = NULL;
		new_seller->num_products = 0;
		// Updating memory size for the new Seller and adding the Seller to shop's sellers
		UTKala->num_sellers++;
		new_seller->next = UTKala->Sellers;
		UTKala->Sellers = new_seller;

		// Adding seller to txt file
		add_seller_to_file(new_seller);
		add_seller_to_users_file(new_seller);

		// Printing success message
		printf("New Seller Signed Up Successfully!\n");
	}
	// If a user is online you can't signup the online user has to sign out so fail message is shown 
	else if (UTKala->online_buyer != NULL || UTKala->online_seller != NULL){
		printf("A User Has Logged In, You Can't Sign Up Until That User Logs Out!\n");
	}
	// Already existing user violation of uniqueness
	else{
		printf("User Already Exists!\n");
	}
}