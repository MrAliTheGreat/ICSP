#include <stdio.h>

void print_rhombus(int n){
	// Declaring new parameter so that abs of i doesn't interfere with the loop
	int k = n;
	for (int i = n; i >= -n; i--){
		// These 2 conditions are for getting the abs of i and putting it in k
		if (i < 0){
			k = -i;
		}
		else if (i >= 0){
			k = i;
		}
		
		// These are for printing the spaces and the stars
		for (int j = 0; j < k; j++){
			printf(" ");
		}
		for (int j = 0; j < 2*n + 1 - 2*k; j++){
			printf("*");
		}
		for (int j = 0; j < k; j++){
			printf(" ");
		}
		// Going to a new line for the next line of spaces and stars
		printf("\n");
	}
}

int main(){
	int num;
	// Getting a value from user and giving it to the function
	printf("Please Enter n: ");
	scanf("%d", &num);
	print_rhombus(num);
	return 0;
}
