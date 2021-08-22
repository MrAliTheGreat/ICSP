#include <stdio.h>

// This Function is for knowing if the input of the function (num) is prime or not
int is_prime(int num){
	for (int i = 2; i <= num / 2; i++){
		if (num % i == 0){
			return 0;
		}
	}
	return 1;
}

void prime_factors(int n){
	int new_prime;
	// We continue until n is equal to one meaning that we found all the prime factors
	while (n != 1){
		// Looping through all numbers that are less than n so that we can find the prime factors
		for (int i = 2; i <= n; i++){
			// If the number is prime and also n can be divided by that number then this means that we have a prime factor
			if (is_prime(i) && n % i == 0){
				printf("%d ", i);
				new_prime = i;
				break;
			}
		}
		// Dividing n by the prime factor so that we can search for new prime factors in the new n
		n /= new_prime;
	}
	printf("\n");
}

int main(){
	// Getting n from user and giving it to the function
	int n;
	printf("Please Enter n: ");
	scanf("%d", &n);
	prime_factors(n);
	return 0;
}