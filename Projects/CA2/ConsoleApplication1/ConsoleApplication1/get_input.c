#include <stdio.h>
#include <stdlib.h>

char** get_input(){
	// Defining
	char** input = NULL;
	char in_char;
	int len_word = 0, index_word = 0 , num_words = 1;

	// Allocating memory for the input starting with size of 0
	input = realloc(input, num_words * sizeof(char*));
	input[num_words - 1] = NULL;

	while (1){
		// Get input from user character by character
		in_char = getc(stdin);
		// \n means that we are at the end of user's input
		if (in_char == '\n'){
			input[num_words - 1] = realloc(input[num_words - 1], len_word + sizeof(char));
			input[num_words - 1][index_word++] = '\0';
			break;
		}
		// The interval between user's inputs
		if (in_char == ' '){
			// Making each word a string and putting it in input and making it ready for the next word
			input[num_words - 1] = realloc(input[num_words - 1] , len_word + sizeof(char));
			input[num_words - 1][index_word++] = '\0';
			num_words++;
			len_word = 0;
			index_word = 0;
			input = realloc(input, num_words * sizeof(char*));
			input[num_words - 1] = NULL;
			continue;
		}
		// Updating the size of the new character
		len_word += sizeof(char);
		input[num_words - 1] = realloc(input[num_words - 1], len_word);
		input[num_words - 1][index_word++] = in_char;
	}
	// All the words from user's input
	return input;
}