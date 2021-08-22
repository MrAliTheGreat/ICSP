#include <stdio.h>

float fact(int n){
	// This function calculates the factorial of n --> n!
	float result = 1;
	for (int i = 1; i <= n; i++){
		result *= i;
	}
	return result;
}

float calculate_sum_of_sequence(int n){
	// This function calculates sum of the sequence by the given n by the user
	float result = 0;
	for (int i = 0; i < n; i++){
		// If the position of the number in the sequence is even then we add the new value
		if (i % 2 == 0){
			result += (1 / fact(i + 1));
		}
		// If it's odd then we subtract the new value 
		else{
			result -= (1 / fact(i + 1));
		}
	}
	return result;
}

int main(){
	// Getting n from user and giving it to the function
	int n;
	printf("Please Enter n: ");
	scanf("%d", &n);
	printf("%f\n", calculate_sum_of_sequence(n));
	return 0;
}