#include <stdio.h>

int main(){
	float num_tribo_numbers = -1;
	float a_float = -1, b_float = -1, c_float = -1;
	int a = 0, b = 0, c = 0, new_num = 0;
	int i = 0;

	// Getting all the inputs
	scanf("%f", &num_tribo_numbers);
	// Checking whether the first input number is valid or not
	if (num_tribo_numbers < 0 || num_tribo_numbers != (int)num_tribo_numbers){
		printf("Invalid Input!\n");
	}
	else{
		scanf("%f %f %f", &a_float , &b_float , &c_float);
		// Checking whether 3 input values are valid or not
		if (a_float != (int)a_float || a_float < 0 || b_float != (int)b_float || b_float < 0 || c_float != (int)c_float || c_float < 0){
			printf("Invalid Input!\n");
		}
		else{
			a = (int)a_float;
			b = (int)b_float;
			c = (int)c_float;

			// Printing the desirable output for the base part (n = 1 , 2 , 3)
			// n = 0
			if (num_tribo_numbers == 0){
				printf("\n");
			}
			// n = 1
			else if (num_tribo_numbers == 1){
				printf("%d\n", a);
			}
			// n = 2
			else if (num_tribo_numbers == 2){
				printf("%d, %d\n", a, b);
			}
			// n = 3
			else if (num_tribo_numbers == 3){
				printf("%d, %d, %d\n", a, b, c);
			}
			else{
				// Printing the output for the sequence of numbers
				printf("%d, %d, %d, ", a, b, c);

				while (i < num_tribo_numbers - 3){
					new_num = a + b + c;
					// This if is for making the last number in the sequence be printed out in the desirable format
					if (i + 1 >= num_tribo_numbers - 3){
						printf("%d\n", new_num);
					}
					else{
						printf("%d, ", new_num);
					}
					// Putting values in the right order for the next run
					a = b;
					b = c;
					c = new_num;
					i++;
				}
			}
		}
	}
	return 0;
}