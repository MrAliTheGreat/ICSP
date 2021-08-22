#include <stdio.h>

void a(int* b){
	(*b)++;
	printf("%d\n", *b);
}

int main(){
	int num[3][4];
	printf("%d\n", num);
	printf("%d\n", &num[1][2]);
	return 0;
}