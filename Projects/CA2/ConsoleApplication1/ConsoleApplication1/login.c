#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void login(struct Shop* UTKala, char* username, char* password, char* user_type){
	// Checking role , existence for uniqueness and if a user is online or not
	if (!strcmp(user_type, "buyer") && check_buyer_existence(UTKala->Buyers, username) && (UTKala->online_buyer == NULL && UTKala->online_seller == NULL)){
		// Finding the buyer
		struct Buyer* traverse_buyer = UTKala->Buyers;
		while (traverse_buyer != NULL){
			// making the buyer go online
			if (!strcmp(traverse_buyer->username, username)){
				if (!strcmp(traverse_buyer->password, password)){
					UTKala->online_buyer = traverse_buyer;
					// Success Message
					printf("Buyer Logged In Successfully!\n");
				}
				// Password not matching the input of function
				else{
					printf("Entered Password Doesn't Match!\n");
				}
			}
			traverse_buyer = traverse_buyer->next;
		}
	}
	// Checking role , existence for uniqueness and if a user is online or not for the seller
	else if (!strcmp(user_type, "seller") && check_seller_existence(UTKala->Sellers, username) && (UTKala->online_buyer == NULL && UTKala->online_seller == NULL)){
		// Finding the seller
		struct Seller* traverse_seller = UTKala->Sellers;
		while (traverse_seller != NULL){
			// making the seller go online
			if (!strcmp(traverse_seller->username, username)){
				if (!strcmp(traverse_seller->password, password)){
					UTKala->online_seller = traverse_seller;
					// Success Message
					printf("Seller Logged In Successfully!\n");
				}
				else{
					// Password not matching the input of function
					printf("Entered Password Doesn't Match!\n");
				}
			}
			traverse_seller = traverse_seller->next;
		}
	}
	// If another user is online we can't login until that user logs out so printing fail message
	else if (UTKala->online_buyer != NULL || UTKala->online_seller != NULL){
		printf("A User Has Logged In You Can't Log In!\n");
	}
	// Not finding the message 
	else{
		printf("User Not Found!\n");
	}
}