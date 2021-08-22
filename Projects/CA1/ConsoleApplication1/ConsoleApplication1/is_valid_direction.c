int is_valid_direction(char direction){
	// The value can be + or -
	if (direction == '+' || direction == '-'){
		return 1;
	}
	return 0;
}