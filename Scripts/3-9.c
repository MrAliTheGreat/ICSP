#include <stdio.h>

int gcd(int a, int b){
	int result = 1;
	// Starting from 2 and going up to the smallest between a and b
	for (int i = 2; i <= a && i <= b; i++){
		// If both a and b can be divided by that number then it's a new common divisior
		// By updating the value of common divisor as we go higher, at the end of the loop we will get to the greatest common divisor
		if (a % i == 0 && b % i == 0){
			result = i;
		}
	}
	return result;
}

int main(){
	// Getting a and b from user and giving it to the function
	int a, b;
	printf("Please Enter a , b: \n");
	scanf("%d %d", &a, &b);
	printf("gcd = %d\n" , gcd(a,b));
	return 0;
}