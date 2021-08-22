void rotate_subboard(char board[6][6], int square_num, char rotate_dir){
	// New array to help store new rotated values in board
	// There are 4 different square and 2 different so there are 8 different ways of rotating
	// Every way of rotation is coded based on their place and rotation direction
	char new_sub_board[3][3];
	if (rotate_dir == '+'){
		if (square_num == 1){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					new_sub_board[i][j] = board[2 - j][3 + i];
				}
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					board[i][j + 3] = new_sub_board[i][j];
				}
			}
		}
		else if (square_num == 2){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					new_sub_board[i][j] = board[2 - j][i];
				}
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					board[i][j] = new_sub_board[i][j];
				}
			}
		}
		else if (square_num == 3){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					new_sub_board[i][j] = board[5 - j][i];
				}
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					board[i + 3][j] = new_sub_board[i][j];
				}
			}
		}
		else if (square_num == 4){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					new_sub_board[i][j] = board[5 - j][3 + i];
				}
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					board[i + 3][j + 3] = new_sub_board[i][j];
				}
			}
		}
	}

	// The second possible rotation direction
	else if (rotate_dir == '-'){
		if (square_num == 1){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					new_sub_board[i][j] = board[j][5 - i];
				}
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					board[i][j + 3] = new_sub_board[i][j];
				}
			}
		}
		else if (square_num == 2){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					new_sub_board[i][j] = board[j][2 - i];
				}
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					board[i][j] = new_sub_board[i][j];
				}
			}
		}
		else if (square_num == 3){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					new_sub_board[i][j] = board[3 + j][2 - i];
				}
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					board[i + 3][j] = new_sub_board[i][j];
				}
			}
		}
		else if (square_num == 4){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					new_sub_board[i][j] = board[3 + j][5 - i];
				}
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					board[i + 3][j + 3] = new_sub_board[i][j];
				}
			}
		}
	}
}