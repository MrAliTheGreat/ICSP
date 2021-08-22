int is_valid_pos(char board[6][6], int pos){
	// Converting pos to x and y
	int x = (pos - (pos % 10)) / 10, y = pos % 10;
	// Checking if x and y are in range and also the position isn't already occupied
	if (x >= 1 && x <= 6 && y >= 1 && y <= 6 && board[x - 1][y - 1] == '.'){
		return 1;
	}
	return 0;
}