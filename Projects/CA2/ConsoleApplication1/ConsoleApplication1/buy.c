#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void decrease_seller_product_quantity(struct Seller* sellers, char* goods_name, int goods_count, char* seller_username){
	// This part is added for phase 2 because of linked list implementation
	struct Seller* traverse_seller = sellers;
	while (strcmp(traverse_seller->username , seller_username)){
		// Finding the seller
		traverse_seller = traverse_seller->next;
	}
	struct Product* traverse_product = traverse_seller->seller_products;
	while (strcmp(traverse_product->name , goods_name)){
		// Finding the product of the seller
		traverse_product = traverse_product->next;
	}
	// Decreasing target good's quantity
	traverse_product->quantity -= goods_count;
}

void buy(struct Shop* UTKala, char* goods_name, int goods_count, char* seller_username){
	// Checking status of product
	int product_status = check_product_existence(UTKala->Products, goods_name, seller_username);
	// Adding product
	if (product_status >= 0){
		// Checking for negative value
		if (goods_count >= 0){
			// checking whether the quantity that buyer wants is available or not
			int index = 0;
			struct Product* traverse_product = UTKala->Products;
			while (index != product_status){
				traverse_product = traverse_product->next;
				index++;
			}
			if (traverse_product->quantity >= goods_count){
				// Checking if buyer's money is enough of not
				if (UTKala->online_buyer->money >= traverse_product->price * goods_count){
					// This part is added for phase 2
					// If according to the ratings the product is avaliable you can buy it
					if (traverse_product->is_available == 1){
						// New product
						struct Product* new_buyer_product = malloc(sizeof(struct Product));
						new_buyer_product->name = goods_name;
						new_buyer_product->price = traverse_product->price;
						new_buyer_product->quantity = goods_count;
						new_buyer_product->seller_username = seller_username;
						// New info of phase 2
						new_buyer_product->num_ratings = traverse_product->num_ratings;
						new_buyer_product->rating = traverse_product->rating;
						new_buyer_product->is_available = traverse_product->is_available;
						new_buyer_product->has_been_rated_by_buyer = 0;

						// Updating memory and adding product to buyer's bought list 
						UTKala->online_buyer->num_products++;
						new_buyer_product->next = UTKala->online_buyer->buyer_products;
						UTKala->online_buyer->buyer_products = new_buyer_product;

						// Decreasing buyer money
						UTKala->online_buyer->money -= new_buyer_product->price * goods_count;
						// Updating buyer file
						add_buyer_to_file(UTKala->online_buyer);


						// Decreasing product quantity
						traverse_product->quantity -= goods_count;
						// Update Goods.txt
						add_good_to_file(UTKala->Products);


						decrease_seller_product_quantity(UTKala->Sellers, goods_name, goods_count, seller_username);
						// increasing seller money
						increse_seller_money(UTKala, seller_username, traverse_product->price * goods_count);

						// Success message
						printf("Transaction Done Successfully!\n");
					}
					else{
						printf("This Product is Unavailable Due to Low rating!\n");
					}
				}
				// Not enough money
				else{
					printf("You Don't Have Enough Money!\n");
				}
			}
			// Quantity is less than wanted
			else{
				printf("Product Quantity Is Less Than Your Request!\n");
			}
		}
		// Negative value is invalid
		else{
			printf("Invalid Product Quantity For Buying!\n");
		}
	}
	// Product doesn't exist
	else{
		printf("Product Not Found!\n");
	}
}