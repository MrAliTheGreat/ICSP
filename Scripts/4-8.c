#include <stdio.h>

int main(){
	// Getting two words from user max size = 100
	char word_1[100], word_2[100];
	scanf(" %s", word_1);
	scanf(" %s", word_2);

	int i = 0, j = 0, result = 0;
	while (word_1[i] != '\0' && word_2[j] != '\0'){
		// if ascii code of first word is smaller then the first word comes first
		if ((int)word_1[i] < (int)word_2[j]){
			result = 1;
			printf("%d\n", result);
			break;
		}
		// if ascii code of second word is smaller then the second word comes first
		else if ((int)word_1[i] > (int)word_2[j]){
			result = 2;
			printf("%d\n", result);
			break;
		}
		i++;
		j++;
	}

	// If equal then print 0
	if (!result){
		printf("%d\n", result);
	}

	return 0;
}