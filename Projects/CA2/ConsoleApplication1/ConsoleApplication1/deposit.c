#include <stdio.h>
#include <stdlib.h>

#include "Headers.h"

void deposit(struct Shop* UTKala, int deposit_amount){
	// Only buyer can do this command
	if (UTKala->online_buyer != NULL){
		// negative deposit amount is invalid this part is checking it
		if (deposit_amount >= 0){
			// Adding the money to balance
			UTKala->online_buyer->money += (float)deposit_amount;
			// Updating user
			add_buyer_to_file(UTKala->online_buyer);
			
			// Success Message
			printf("Deposit Successfully Done!\n");
		}
		// Negative amount entered which is invalid
		else{
			printf("Invalid Deposit Amount!\n");
		}
	}
	// Someone other than buyer is doing this command so fail command is shown
	else{
		printf("Buyer Not Logged In!\n");
	}
}