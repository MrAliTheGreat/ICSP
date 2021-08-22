#include <stdio.h>

int main()
{
	// Maximum size of text = 1000
	char text[1000];
	// Getting text until \n is pressed
	scanf("%[^\n]", text);
	// The key is deined in the question
	char key[1000] = { 'i', 'c', 's', 'p', 'h', 'w', 'f', 'o', 'u', 'r' };

	int text_size = 0 , i = 0 , key_size = 10;
	// Finding text size
	while (text[i] != '\0'){
		i++;
		if (text[i] == '.' || text[i] == ',' || text[i] == ' '){
			continue;
		}
		text_size++;
	}

	// Genrating key for decrypting
	for (int i = 0;; i++){
		if (text_size == i)
			i = 0;
		if (text_size == key_size)
			break;
		key[10 + i] = key[i];
		key_size++;
	}

	int x , j = 0;
	i = 0;
	// Decrypting the text
	while(j < key_size){
		if (text[i] == '.' || text[i] == ',' || text[i] == ' '){
			printf("%c", text[i]);
			i++;
			continue;
		}
		x = ((int)text[i] - (int)key[j] + 26) % 26;
		x += 97;
		printf("%c" , (char)x);
		i++;
		j++;
	}
	printf("\n");

	return 0;
}