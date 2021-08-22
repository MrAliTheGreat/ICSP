#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fileptr;
	char temp;
	fileptr = fopen("TextFile.txt", "w");
	while ((temp = fgetc(fileptr)) != EOF){
		printf("%c", temp);
	}
	printf(" Done\n");
	fclose(fileptr);
	return 0;
}

