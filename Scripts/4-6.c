#include <stdio.h>
#include <stdlib.h>

int main(){
	// Maximum number of input characters is 100
	char letters[100];
	int k , letter;
	// Get everything until enter (\n)
	scanf("%[^\n]", letters);
	scanf(" %d", &k);
	
	int i = 0;
	// Last character is \0 that means the string has ended
	while (letters[i] != '\0'){
		// '.' ' ' ',' we don't do anything with them
		if (letters[i] == ' ' || letters[i] == '.' || letters[i] == ','){
			printf("%c", letters[i]);
			i++;
			continue;
		}
		// Calculating new ascii code
		letter = ((int)letters[i] - 97 - k) % 26;
		if (letter < 0){
			letter += 26;
		}
		// Printing new character
		printf("%c" , (char)(letter + 97));
		i++;
	}
	printf("\n");
	return 0;
}