#include <stdio.h>

int main(){
	float height_ball = 0, height_mom = 0, b_factor = 0;
	int count_observe = 1;
	
	scanf("%f %f %f" , &height_ball , &b_factor , &height_mom);
	
	// Checking for invalid input
	// Also if the height of asghar's mom is 0 then the result will be infinity so it's considered invalid input
	if (height_mom <= 0){
		printf("Invalid Input!\n");
	}
	else{
		// Checking whether the conditions of the question are satisfied or not
		if (height_ball > 0 && (b_factor > 0 && b_factor < 1) && height_mom < height_ball){
			while (height_ball * b_factor >= height_mom){
				// The while should continue until the height of the ball is smaller the height of asghar's mom
				// Since there are 2 observances of the ball 2 is added to count_observe each time
				height_ball *= b_factor;
				count_observe += 2;
			}
			// Print out number of observances
			printf("%d\n", count_observe);
		}
		else{
			// If the conditions are not satisfied then -1 must be printed out
			printf("-1\n");
		}
	}
	return 0;
}