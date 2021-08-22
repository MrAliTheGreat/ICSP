#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

struct Seller* find_seller(struct Seller* sellers , char* seller_username){
	struct Seller* traverse_seller = sellers;
	// Traversing the sellers' list and finding wanted seller
	while (traverse_seller != NULL){
		if (!strcmp(traverse_seller->username , seller_username)){
			return traverse_seller;
		}
		traverse_seller = traverse_seller->next;
	}
	return NULL;
}

void determine_product_status(struct Shop* UTKala, char* goods_name, char* seller_username, int rating){
	// Finding the product
	struct Product* found_shop_product = find_product(UTKala->Products, goods_name, seller_username);
	// Updadting the rating
	found_shop_product->rating = (found_shop_product->num_ratings * found_shop_product->rating + rating);
	found_shop_product->num_ratings++;
	found_shop_product->rating /= found_shop_product->num_ratings;
	// Check the rating for making it either avaliable or unavaliable due to rating
	if (found_shop_product->rating < 2 && found_shop_product->num_ratings >= 5){
		found_shop_product->is_available = 0;
	}
	else{
		found_shop_product->is_available = 1;
	}
	// Updating Goods.txt
	add_good_to_file(UTKala->Products);
	
	// Finding seller
	struct Seller* found_seller = find_seller(UTKala->Sellers, seller_username);
	// Finding the seller's product
	struct Product* found_seller_product = find_product(found_seller->seller_products, goods_name, seller_username);
	// Updating rating in seller's products
	found_seller_product->rating = (found_seller_product->num_ratings * found_seller_product->rating + rating);
	found_seller_product->num_ratings++;
	found_seller_product->rating /= found_seller_product->num_ratings;
	// Check the rating for making it either avaliable or unavaliable due to rating
	if (found_seller_product->rating < 2 && found_seller_product->num_ratings >= 5){
		found_seller_product->is_available = 0;
	}
	else{
		found_seller_product->is_available = 1;
	}
	// Update seller text file
	add_seller_to_file(found_seller);
	printf("Determined Product's Availability Successfully!\n");
	// Updating buyer's products would be pointless since it doesn't matter
}