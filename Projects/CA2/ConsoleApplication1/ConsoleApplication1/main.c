#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

int main(){
	struct Shop* UTKala = create_shop();
	char** input;

	read_previous_data(UTKala);

	while (1){
		// Getting input from user
		input = get_input();

		// Different commands
		
		// signup command
		if (!strcmp(input[0], "signup")){
			// Role checking
			if (!strcmp(input[3], "buyer") || !strcmp(input[3], "seller")){
				// Doing signup command
				signup(UTKala, input[1], input[2], input[3]);
			}
			// Wrong Input
			else{
				printf("User Role Not Found\n");
			}
		}
		// login command
		else if (!strcmp(input[0], "login")){
			// Role checking
			if (!strcmp(input[3], "buyer") || !strcmp(input[3], "seller")){
				// Doing login command
				login(UTKala, input[1], input[2], input[3]);
			}
			// Wrong Input
			else{
				printf("User Role Not Found\n");
			}
		}
		// logout command
		else if (!strcmp(input[0], "logout")){
			logout(UTKala);
		}
		// deposit command
		else if (!strcmp(input[0], "deposit")){
			// Only buyer can do this command
			deposit(UTKala , atoi(input[1]));
		}
		// add_goods command
		else if (!strcmp(input[0], "add_goods")){
			// Only seller can do this command
			if (UTKala->online_seller != NULL){
				add_goods(UTKala, input[1], atoi(input[2]), atoi(input[3]));
			}
			// Fail message Buyer is trying to this command which it can't
			else{
				printf("No Seller Has Logged In So You Can't Add Any Goods!\n");
			}
		}
		// buy command
		else if (!strcmp(input[0], "buy")){
			// Only buyer can do this command
			if (UTKala->online_buyer != NULL){
				buy(UTKala, input[1], atoi(input[2]), input[3]);
			}
			// Fail message seller is trying to this command which it can't
			else{
				printf("No Buyer Has Logged In So You Can't Buy Any Goods!\n");
			}
		}
		// show_goods command
		else if (!strcmp(input[0], "show_goods")){
			show_goods(UTKala);
		}
		// view command
		else if (!strcmp(input[0], "view")){
			view(UTKala);
		}
		// remove_goods command
		else if (!strcmp(input[0], "remove_goods")){
			// Only seller can do this command
			if (UTKala->online_seller != NULL){
				remove_goods(UTKala, input[1]);
			}
			// Fail message buyer is trying to this command which it can't
			else{
				printf("No Seller Has Logged In So You Can't Remove Any Goods!\n");
			}
		}
		// change_goods_price command
		else if (!strcmp(input[0], "change_goods_price")){
			// Only seller can do this command
			if (UTKala->online_seller != NULL){
				change_goods_price(UTKala, input[1] , atoi(input[2]));
			}
			// Fail message buyer is trying to this command which it can't
			else{
				printf("No Seller Has Logged In So You Can't Change Any Good's Price!\n");
			}
		}
		// rate_goods command
		else if (!strcmp(input[0], "rate_goods")){
			// Only buyer can do this command
			if (UTKala->online_buyer != NULL){
				rate_goods(UTKala, input[1], input[2], atoi(input[3]));
			}
			// Fail message seller is trying to this command which it can't
			else{
				printf("No Buyer Has Logged In So You Can't Rate Any Good!\n");
			}
		}
		// search command
		else if (!strcmp(input[0], "search")){
			search(UTKala, atoi(input[1]));
		}
		// Exit command this part is for freeing all the used memory
		// The command is -> exit_shop
		else if (!strcmp(input[0], "exit_shop")){
			// Freeing used memory
			exit_shop(UTKala);
			// Freeing input memory
			free(input[0]);
			free(input);
			// Exit Message
			printf("Thank You For Shopping At UT Kala Hope To See You Soon!\n");
			break;
		}
		// Unknown command
		else{
			printf("Command Not Found\n");
		}
	}

	return 0;
}