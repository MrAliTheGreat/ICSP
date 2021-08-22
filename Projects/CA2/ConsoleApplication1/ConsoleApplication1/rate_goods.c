#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void rate_goods(struct Shop* UTKala, char* goods_name, char* seller_username, int rating){
	// Find buyer's target product
	struct Product* found_buyer_product = find_product(UTKala->online_buyer->buyer_products, goods_name, seller_username);
	// Check if buyer has bought the product
	if (found_buyer_product != NULL){
		// Check if rating number is valid
		if (rating >= 1 && rating <= 5){
			// Check if the product has already been rated by the buyer
			if (!found_buyer_product->has_been_rated_by_buyer){
				// Update the availability of the product
				determine_product_status(UTKala , goods_name , seller_username , rating);
				// Now user has rated the product
				found_buyer_product->has_been_rated_by_buyer = 1;
				// Update buyer text file
				add_buyer_to_file(UTKala->online_buyer);
				// Success message
				printf("Product Was Rated Successfully!\n");
			}
			else{
				printf("Buyer Product Has Already Been Rated Can't Rate Anymore!\n");
			}
		}
		else{
			printf("Rating Number Isn't Valid Must Be Between 1 to 5!\n");
		}
	}
	else{
		printf("Product Not Found In Buyer's Bought Products!\n");
	}
}