#include <stdio.h>
#define SIZE 5
int main() {
	int n[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++){
		for (int j = SIZE; j > 0; j--){
			n[i][j - 1] = j - i;
		}
	}
	for (int i = 1; i < SIZE; i+=2){
		printf("%d", n[i - 1][i + 1]);
	}
}