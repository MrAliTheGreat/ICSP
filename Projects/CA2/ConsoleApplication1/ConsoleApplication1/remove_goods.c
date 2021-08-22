#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers.h"

void remove_product_from_seller_products(struct Shop* UTKala , char* goods_name){
	struct Product* traverse_product = UTKala->online_seller->seller_products;
	struct Product* previous_product;
	// Finding the product from seller's product list and removing it in linked list way
	while (strcmp(traverse_product->name , goods_name)){
		previous_product = traverse_product;
		traverse_product = traverse_product->next;
	}
	if (traverse_product == UTKala->online_seller->seller_products){
		UTKala->online_seller->seller_products = traverse_product->next;
	}
	else{
		previous_product->next = traverse_product->next;
	}
	free(traverse_product->name);
	free(traverse_product);
	UTKala->online_seller->num_products--;
	// Updating seller's text file
	add_seller_to_file(UTKala->online_seller);
}

void remove_goods(struct Shop* UTKala, char* goods_name){
	int remove_status = check_product_existence(UTKala->Products, goods_name, UTKala->online_seller->username);
	if (remove_status >= 0){
		// Everything is valid for removing
		struct Product* traverse_product = UTKala->Products;
		struct Product* previous_product;
		int index = 0;
		// Finding the product from products' list and removing it in linked list way
		while (index != remove_status){
			previous_product = traverse_product;
			traverse_product = traverse_product->next;
			index++;
		}
		if (index == 0){
			UTKala->Products = traverse_product->next;
		}
		else{
			previous_product->next = traverse_product->next;
		}
		UTKala->num_products--;
		free(traverse_product);
		// Now it's time for the product to be removed for seller's list of products
		remove_product_from_seller_products(UTKala, goods_name);
		// Updating Goods.txt
		add_good_to_file(UTKala->Products);
		printf("Product Was Removed Successfully!\n");
	}
	else if (remove_status == -1){
		// Product exists but it's for another seller
		printf("Can't Remove Other Seller's Product!\n");
	}
	else{
		// Product doesn't exist
		printf("Product Not Found!\n");
	}
}