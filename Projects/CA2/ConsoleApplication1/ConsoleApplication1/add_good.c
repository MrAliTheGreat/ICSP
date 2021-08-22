#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void add_goods(struct Shop* UTKala, char* goods_name, int goods_price, int goods_count){
	// Find the status of product
	int add_status = check_product_existence(UTKala->Products, goods_name, UTKala->online_seller->username);
	// Only seller can do this command
	if (UTKala->online_seller != NULL && add_status == -2){
		// Checking negative value
		if (goods_price >= 0 && goods_count >= 0){
			// New product
			struct Product* new_product = malloc(sizeof(struct Product));
			new_product->name = goods_name;
			new_product->price = (float)goods_price;
			new_product->quantity = goods_count;
			new_product->seller_username = UTKala->online_seller->username;
			// The info below is added for phase 2 of the project
			new_product->num_ratings = 0;
			new_product->rating = (float)0;
			new_product->is_available = 1;
			new_product->has_been_rated_by_buyer = 0;
			new_product->next = UTKala->Products;
			// Updating memory size and adding to shop products
			UTKala->num_products++;
			UTKala->Products = new_product;
			// Updating memory size and adding to seller products so their pointers are alike and equal
			struct Product* new_seller_product = malloc(sizeof(struct Product));
			new_seller_product->name = goods_name;
			new_seller_product->price = (float)goods_price;
			new_seller_product->quantity = goods_count;
			new_seller_product->seller_username = UTKala->online_seller->username;
			new_seller_product->next = UTKala->online_seller->seller_products;
			// The info below is added for phase 2 of the project
			new_seller_product->num_ratings = 0;
			new_seller_product->rating = (float)0;
			new_seller_product->is_available = 1;
			new_seller_product->has_been_rated_by_buyer = 0;
			UTKala->online_seller->num_products++;
			UTKala->online_seller->seller_products = new_seller_product;
			
			// Update seller
			add_seller_to_file(UTKala->online_seller);
			// Add goods to Goods.txt
			add_good_to_file(UTKala->Products);

			// Success message
			printf("New Product Added Successfully!\n");
		}
		// Negative value is invalid so fail message is shown
		else{
			printf("Invalid Value For The Product!\n");
		}
	}
	// Another seller is trying to change or add other seller's product which is violation of uniqueness so fail message is shown
	else if (UTKala->online_seller != NULL && add_status == -1){
		printf("Can't Change Other Seller's Product!\n");
	}
	// Seller is trying to increase quantity of its product which there's no problem with it
	else if (UTKala->online_seller != NULL && add_status >= 0){
		// Checking for negative value
		if (goods_count >= 0){
			// Increasing product quantity
			int index = 0;
			struct Product* traverse_product = UTKala->Products;
			while (add_status != index){
				traverse_product = traverse_product->next;
				index++;
			}
			traverse_product->quantity += goods_count;
			// Add goods to Goods.txt
			add_good_to_file(UTKala->Products);

			traverse_product = UTKala->online_seller->seller_products;
			while (strcmp(traverse_product->name , goods_name)){
				traverse_product = traverse_product->next;
			}
			traverse_product->quantity += goods_count;

			// Update seller
			add_seller_to_file(UTKala->online_seller);

			// Success Message
			printf("Quantity Increased Successfully By The Rightful Seller!\n");
		}
		// Negative value is invalid so fail message is shown
		else{
			printf("Invalid Quantity For Product!\n");
		}
	}
	// A user other than seller is doing this command so fail message is shown
	else{
		printf("Seller Not Logged In!\n");
	}
}