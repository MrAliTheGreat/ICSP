#include <stdio.h>
#include <stdlib.h>

// Size for the input strings
#define DEFAULT 100

char** get_n_string(int n){
	// Having n strings
	char** strings = malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++){
		// Each one of the n strings
		strings[i] = malloc(DEFAULT * sizeof(char));
		// Input string
		scanf(" %s", *(strings + i));
	}
	return strings;
}

int main(){
	int n;
	scanf("%d", &n);
	get_n_string(n);
	return 0;
}