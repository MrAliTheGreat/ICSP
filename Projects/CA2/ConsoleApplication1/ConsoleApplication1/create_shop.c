#include <stdio.h>
#include <stdlib.h>

#include "Headers.h"

struct Shop* create_shop(){
	// Allocating memory for the shop and initializing everyone of them
	struct Shop* UTKala = malloc(sizeof(struct Shop));
	UTKala->num_buyers = 0;
	UTKala->num_sellers = 0;
	UTKala->num_products = 0;
	UTKala->Buyers = malloc(sizeof(struct Buyer));
	UTKala->Buyers = NULL;
	UTKala->Sellers = malloc(sizeof(struct Seller));
	UTKala->Sellers = NULL;
	UTKala->Products = malloc(sizeof(struct Product));
	UTKala->Products = NULL;
	UTKala->online_buyer = NULL;
	UTKala->online_seller = NULL;
	// Returning the created shop
	return UTKala;
}