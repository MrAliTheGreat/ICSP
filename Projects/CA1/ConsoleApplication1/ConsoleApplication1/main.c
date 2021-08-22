#include <stdio.h>
#include "print_board.h"
#include "check_game_status.h"
#include "is_valid_pos.h"
#include "is_valid_square.h"
#include "is_valid_direction.h"
#include "rotate_subboard.h"

int main(){
	char board[6][6] = { { '.', '.', '.', '.', '.', '.' }, { '.', '.', '.', '.', '.', '.' }, { '.', '.', '.', '.', '.', '.' }, { '.', '.', '.', '.', '.', '.' }, { '.', '.', '.', '.', '.', '.' }, { '.', '.', '.', '.', '.', '.' } };
	int position, square_num, b_turn = 1, w_turn = 0 , status;
	char rotate_dir;

	// Checking whether the game has a winner or not
	while (!check_game_status(board)){
		print_board(board);
		// Determining who is going to play
		if (b_turn){
			printf("BLACK player's turn\n");
		}
		else if (w_turn){
			printf("WHITE player's turn\n");
		}

		// Getting the postion from user
		while (1){
			printf("Position: ");
			scanf(" %d", &position);
			// Checking if the position is valid or not
			if (is_valid_pos(board, position)){
				// Placing the player's letter in the given positon in the array
				if (b_turn){
					board[((position - (position % 10)) / 10) - 1][(position % 10) - 1] = 'b';
				}
				else if (w_turn){
					board[((position - (position % 10)) / 10) - 1][(position % 10) - 1] = 'w';
				}
				break;
			}
			// Print a message if the input is not valid
			else{
				printf("INVALID INPUT: Your Coordinates Weren't Valid Please Try Again!\n");
			}
		}
		// Getting the number of the square that the user wants to rotate
		while (1){
			printf("Squre Number: ");
			scanf(" %d", &square_num);
			// Checking the validity
			if (is_valid_square(square_num)){
				break;
			}
			// Print a message if the input is not valid
			else{
				printf("INVALID INPUT: Your Square Number Wasn't Valid Please Try Again!\n");
			}
		}

		// Getting the rotate direction from user
		while (1){
			printf("Rotation Direction: ");
			scanf(" %c", &rotate_dir);
			// Checking the validity
			if (is_valid_direction(rotate_dir)){
				// Rotate the determined square with the given direction
				rotate_subboard(board, square_num, rotate_dir);
				break;
			}
			// Print a message if the input is not valid
			else{
				printf("INVALID INPUT: Your Direction Wasn't Valid Please Try Again!\n");
			}
		}
		// Changing the players turn now it's the other player's turn 
		b_turn = !b_turn;
		w_turn = !w_turn;
	}
	// Printing the board on last time before ending to see the final board
	print_board(board);
	// Since there is multiple conditions so we compute check_game_status once and use it as variable status in the conditions
	status = check_game_status(board);
	// Game results:
	if (status == 1){
		printf("BLACK player has won!\n");
	}
	else if (status == 2){
		printf("WHITE player has won!\n");
	}
	else{
		printf("All Spaces Are Occupied But There's no Winner It's a DRAW\n");
	}
	return 0;
}