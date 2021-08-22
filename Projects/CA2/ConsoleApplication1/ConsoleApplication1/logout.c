#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void logout(struct Shop* UTKala){
	// If buyer is online buyer logs out
	if (UTKala->online_buyer != NULL && UTKala->online_seller == NULL){
		UTKala->online_buyer = NULL;
		// Success message
		printf("Buyer Logged Out!\n");
	}
	// If seller is online seller logs out
	else if (UTKala->online_buyer == NULL && UTKala->online_seller != NULL){
		UTKala->online_seller = NULL;
		// Success message
		printf("Seller Logged Out!\n");
	}
	// No user is logged in so fail message is shown
	else{
		printf("No User Has Logged In!\n");
	}
}