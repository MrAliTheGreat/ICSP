#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void change_price_seller_product(struct Seller* sellers, char* goods_name , char* seller_username, int new_price){
	struct Seller* traverse_seller = sellers;
	while (strcmp(traverse_seller->username, seller_username)){
		// Finding the seller
		traverse_seller = traverse_seller->next;
	}
	struct Product* traverse_product = traverse_seller->seller_products;
	while (strcmp(traverse_product->name, goods_name)){
		// Finding seller's product
		traverse_product = traverse_product->next;
	}
	// Changing price of the product
	traverse_product->price = (float)new_price;
	// Updating seller's info in text file
	add_seller_to_file(traverse_seller);
}

void change_goods_price(struct Shop* UTKala, char* goods_name, int new_price){
	// Checking product's existence
	int remove_status = check_product_existence(UTKala->Products, goods_name, UTKala->online_seller->username);
	if (remove_status >= 0){
		// changing the good in shop products list
		struct Product* traverse_product = UTKala->Products;
		int index = 0;
		while (index != remove_status){
			traverse_product = traverse_product->next;
			index++;
		}
		traverse_product->price = (float)new_price;
		// Updating Goods.txt
		add_good_to_file(UTKala->Products);

		// Changing price in seller product list
		change_price_seller_product(UTKala->Sellers, goods_name, traverse_product->seller_username, new_price);
		printf("Product's Price Was Changed Successfully!\n");
	}
	else if (remove_status == -1){
		// Exists but it's for some other seller
		printf("Can't Change Price of Other Seller's Product!\n");
	}
	else{
		// Doesn't exist
		printf("Product Not Found!\n");
	}
}