#include <stdio.h>

int main(){
	// Getting text until user hits enter (\n) max size input = 1000
	// Getting word from user max size input = 100
	char text[1000];
	char word[100];
	scanf("%[^\n]", text);
	scanf(" %s", word);

	int i = 0, j = 0, matched = 1 , counter = 0;
	while (text[i] != '\0'){
		if (text[i] == word[j]){
			// If the previous character is an alphabetic character it's not going to count
			// Range lowercase letters 97 to 122 ascii code
			// Range uppercase letters 65 to 90 ascii code
			if (((int)text[i - 1] >= 97 && (int)text[i - 1] <= 122) || ((int)text[i - 1] >= 65 && (int)text[i - 1] <= 90)){
				i++;
				j = 0;
				matched = 1;
				continue;
			}
			i++;
			j++;
			// Checking the word
			while (word[j] != '\0'){
				if (word[j] != text[i]){
					matched = 0;
					j = 0;
					break;
				}
				i++;
				j++;
			}
			// If the next character is an alphabetic character it's not going to count
			if (matched && !(((int)text[i] >= 97 && (int)text[i] <= 122) || ((int)text[i] >= 65 && (int)text[i] <= 90))){
				j = 0;
				counter++;
			}
			matched = 1;
			j = 0;
		}
		i++;
		j = 0;
		matched = 1;
	}

	printf("%d\n", counter);
	return 0;
}