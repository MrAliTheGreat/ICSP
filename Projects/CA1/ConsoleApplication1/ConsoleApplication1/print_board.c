#include <stdio.h>

void print_board(char board[6][6]){
	//printing first row of numbers (column indicators)
	for (int i = 0; i < 6; i++){
		// Vertical space between two 3*3 squares
		if (i == 3){
			printf("\t|");
		}
		printf("\t%d", i + 1);
	}
	printf("\n");

	for (int i = 0; i < 6; i++){
		// horizontal space between two 3*3 squares
		if (i == 3){
			printf("--\t--\t--\t--\t\t--\t--\t--\n");
		}
		// Row indicators
		printf("%d\t", i + 1);
		for (int j = 0; j < 6; j++){
			if (j == 3){
				printf("|\t");
			}
			printf("%c\t", board[i][j]);
		}
		printf("\n");
	}
}