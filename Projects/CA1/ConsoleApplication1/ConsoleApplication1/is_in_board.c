int is_in_board(int x, int y){
	// Checking if the position is in board
	if (x < 6 && x >= 0 && y < 6 && y >= 0){
		return 1;
	}
	return 0;
}