#include "is_in_board.h"

int check_game_status(char board[6][6]){
	// Possible moves and final moves for checking the victory pattern
	int moves_x[8] = { 0, 0, -1, 1, -1, -1, 1, 1 }, final_move_x[8][2] = { { -1, 1 }, { -1, 1 }, { 0, 0 }, { 0, 0 }, { 1, -1 }, { -1, 1 }, { 1, -1 }, { -1, 1 } };
	int moves_y[8] = { 1, -1, 0, 0, 1, -1, -1, 1 }, final_move_y[8][2] = { { 0, 0 }, { 0, 0 }, { -1, 1 }, { -1, 1 }, { 1, -1 }, { 1, -1 }, { 1, -1 }, { 1, -1 } };
	int count_b = 1, count_w = 1, pos_x, pos_y, win_b = 0, win_w = 0 , num_empty = 0;

	// Checking all tiles in the board for possible victory pattern
	// Return Values:
	// 0: No one is winning and the game can go on
	// 1: BLACK player wins
	// 2: WHITE player wins
	// 3: There's no tile left in the board and it's a draw

	for (int i = 0; i < 36; i++){
		// Converting index to x and y
		pos_x = i / 6;
		pos_y = i % 6;
		// Checking for the BLACK player
		if (board[pos_x][pos_y] == 'b'){
			for (int k = 0; k < 8; k++){
				pos_x = i / 6;
				pos_y = i % 6;
				// Moving 4 tiles to see if the first part of victory pattern is made
				for (int t = 0; t < 3; t++){
					if (is_in_board(pos_x + moves_x[k], pos_y + moves_y[k])){
						if (board[pos_x + moves_x[k]][pos_y + moves_y[k]] == 'b'){
							count_b++;
						}
						// Moving to the next tile
						pos_x += moves_x[k];
						pos_y += moves_y[k];
					}
					// If there's no victory pattern start over
					else{
						count_b = 1;
						break;
					}
				}

				// checking the final part of victory pattern (2 possible moves)
				if (count_b == 4 && is_in_board(pos_x + final_move_x[k][0], pos_y + final_move_y[k][0])){
					if (board[pos_x + final_move_x[k][0]][pos_y + final_move_y[k][0]] == 'b'){
						win_b = 1;
						break;
					}
				}
				if (count_b == 4 && is_in_board(pos_x + final_move_x[k][1], pos_y + final_move_y[k][1])){
					if (board[pos_x + final_move_x[k][1]][pos_y + final_move_y[k][1]] == 'b'){
						win_b = 1;
						break;
					}
					else{
						count_b = 1;
					}
				}
				else{
					count_b = 1;
				}

			}
			// If the victory pattern was made then declare the black player as the winner
			if (win_b){
				return 1;
			}
		}

		// The same  for the WHITE player 
		else if (board[pos_x][pos_y] == 'w'){
			for (int k = 0; k < 8; k++){
				pos_x = i / 6;
				pos_y = i % 6;
				for (int t = 0; t < 3; t++){
					if (is_in_board(pos_x + moves_x[k], pos_y + moves_y[k])){
						if (board[pos_x + moves_x[k]][pos_y + moves_y[k]] == 'w'){
							count_w++;
						}
						pos_x += moves_x[k];
						pos_y += moves_y[k];
					}
					else{
						count_w = 1;
						break;
					}
				}
				if (count_w == 4 && is_in_board(pos_x + final_move_x[k][0], pos_y + final_move_y[k][0])){
					if (board[pos_x + final_move_x[k][0]][pos_y + final_move_y[k][0]] == 'w'){
						win_w = 1;
						break;
					}
				}
				if (count_w == 4 && is_in_board(pos_x + final_move_x[k][1], pos_y + final_move_y[k][1])){
					if (board[pos_x + final_move_x[k][1]][pos_y + final_move_y[k][1]] == 'w'){
						win_w = 1;
						break;
					}
					else{
						count_w = 1;
					}
				}
				else{
					count_w = 1;
				}

			}
			if (win_w){
				return 2;
			}
		}
		// Checking if there is no tile left in the board to put player's letter
		else if (board[pos_x][pos_y] == '.'){
			num_empty++;
		}
	}
	// If there is no space left then there's a draw
	if (num_empty == 0){
		return 3;
	}
	// There's no win but the game can go on
	return 0;
}