// STRUCTS

struct Product
{
	char* name;
	char* seller_username;
	int quantity;
	float price;
	int num_ratings;
	float rating;
	int is_available;
	int has_been_rated_by_buyer;
	struct Product* next;
};

struct Seller
{
	char* username;
	char* password;
	float money;
	struct Product* seller_products;
	int num_products;
	struct Seller* next;
};

struct Buyer
{
	char* username;
	char* password;
	float money;
	struct Product* buyer_products;
	int num_products;
	struct Buyer* next;
};

struct Shop
{
	struct Seller* Sellers;
	struct Buyer* Buyers;
	struct Product* Products;
	struct Buyer* online_buyer;
	struct Seller* online_seller;
	int num_buyers, num_sellers, num_products;
};

// FUNCTIONS

char** get_input();

struct Shop* create_shop();

void signup(struct Shop* UTKala , char* username, char* password, char* user_type);

void login(struct Shop* UTKala, char* username, char* password, char* user_type);

void logout(struct Shop* UTKala);

void deposit(struct Shop* UTKala, int deposit_amount);

void add_goods(struct Shop* UTKala, char* goods_name, int goods_price, int goods_count);

void buy(struct Shop* UTKala, char* goods_name, int goods_count, char* seller_username);

void show_goods(struct Shop* UTKala);

void view(struct Shop* UTKala);

void exit_shop(struct Shop* UTKala);

int check_buyer_existence(struct Buyer* Buyers, char* username);

int check_seller_existence(struct Seller* Sellers, char* username);

int check_product_existence(struct Product* Products, char* goods_name, char* online_seller_username);

void increse_seller_money(struct Shop* UTKala, char* seller_username, float amount);

void add_buyer_to_file(struct Buyer* buyer);

void add_buyer_to_users_file(struct Buyer* buyer);

void add_seller_to_file(struct Seller* seller);

void add_seller_to_users_file(struct Seller* seller);

void add_good_to_file(struct Product* Products);

char** get_input_text(char* file_address);

void read_previous_data(struct Shop* UTKala);

void remove_goods(struct Shop* UTKala , char* goods_name);

void change_goods_price(struct Shop* UTKala , char* goods_name , int new_price);

struct Product* find_product(struct Product* products, char* goods_name, char* seller_username);

void rate_goods(struct Shop* UTKala , char* goods_name , char* seller_username , int rating);

struct Product* make_copy(struct Product* products);

void determine_product_status(struct Shop* UTKala, char* goods_name, char* seller_username, int rating);

struct Product* make_sorted_list(struct Product* products);

void search(struct Shop* UTKala , int num_conditions);