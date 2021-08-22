#include <stdio.h>
#define True 1
#define False 0

int main(){
	float num_people_float = -1, money_person_float = -1;
	int num_people = 0, money_person = 0;
	int num_seller_40s = 0, num_seller_20s = 0, num_seller_10s = 0;
	int status = True , quit = False;

	scanf("%f", &num_people_float);
	if (num_people_float < 0 || num_people_float != (int)num_people_float){
		// Checking whether the number of people is valid or not
		printf("Invalid Number of People!\n");
	}
	else{
		num_people = (int)num_people_float;
		for (int i = 0; i < num_people; i++){
			// Main loop for checking the line
			// status shows that if we can do what question wants or not
			scanf("%f", &money_person_float);
			if (money_person_float < 0 || money_person_float != (int) money_person_float){
				// Checking for being character or float number
				printf("Invalid Input!\n");
				quit = True;
				break;
			}
			money_person = (int)money_person_float;
			if (money_person != 10 && money_person != 20 && money_person != 40){
				// Checking whether the money of each person is 10 20 40 or not if not then it's invalid
				printf("Invalid Input!\n");
				quit = True;
				break;
			}
			if (status){
				if (money_person == 10){
					// num_seller_10s will increase by 1
					num_seller_10s++;
				}
				else if (money_person == 20){
					if (num_seller_10s >= 1){
						num_seller_10s--;
					}
					else{
						status = False;
					}
					// num_seller_20s will increase by 1
					num_seller_20s++;
				}
				else if (money_person == 40){
					// There will be 2 possible outcome
					if (num_seller_10s >= 3){
						num_seller_10s -= 3;
					}
					else if (num_seller_20s >= 1 && num_seller_10s >= 1){
						num_seller_20s--;
						num_seller_10s--;
					}
					else{
						status = False;
					}
					// num_seller_40s will increase by 1
					num_seller_40s++;
				}
			}
		}
		//Finally if the program hasn't quitted already then print out the desirable answer
		if (!quit){
			if (status){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}