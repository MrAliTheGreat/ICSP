#include <stdio.h>

int convert_date(int m, int d){
	// These conditions are for -1 value
	// If the day or the month is negative or the day is more than 31 or the month is more than 12 then it's invalid
	if (m <= 0 || m >= 13 || d >= 32 || d <= 0){
		return -1;
	}
	// If for the second 6 months the day is more than 30 then it's invalid
	if ((m == 7 || m == 8 || m == 9 || m == 10 || m == 11) && d >= 31){
		return -1;
	}
	// If the last month has more than 29 days then it's invalid
	if (m == 12 && d >= 30){
		return -1;
	}
	
	// Calculating the result with the valid inputs
	if (m - 6 > 0){
		return (m - 7) * 30 + d + 6 * 31;
	}
	return (m - 1) * 31 + d;
}

int main(){
	// Getting day and month from user and giving it to the function
	int m, d;
	printf("Please Enter m , d:\n");
	scanf("%d %d", &m, &d);
	printf("%d\n", convert_date(m, d));
	return 0;
}