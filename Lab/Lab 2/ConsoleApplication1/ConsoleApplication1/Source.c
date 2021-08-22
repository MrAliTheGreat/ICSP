#include <stdio.h>
#include <stdlib.h>

int main(){
	srand(810196688);
	int random_number = rand() % 100, guess = -1;

	printf("Welcome to the Game!\n");
	while (1){
		printf("Enter Your Guess:\n");
		scanf("%d", &guess);

		if (guess == random_number){
			printf("Congratulations! You have Guessed The Correct Number.\n");
			break;
		}
		else if (guess > random_number) {
			printf("Your guess was greater than the number in my mind!\n");
		}
		else {
			printf("Your guess was less than the number in my mind!\n");
		}
	}
	return 0;
}
