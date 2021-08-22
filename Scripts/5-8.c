#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point{
	int x, y;
};

struct line{
	struct point start;
	struct point end;
};

struct point* new_Point(int x, int y){
	struct point* new_p = malloc(sizeof(struct point));
	new_p->x = x;
	new_p->y = y;
	return new_p;
}

struct line* new_line(struct point *start, struct point *end){
	struct line* new_l = malloc(sizeof(struct line));
	new_l->start = *start;
	new_l->end = *end;
	return new_l;
}

float distance(struct point* x0, struct line* l0){
	// Calculating the slope
	float slope = (float)(l0->end.y - l0->start.y) / (l0->end.x - l0->start.x);
	// Using formula to calculate the distance
	return (float)fabs(slope * x0->x - (float)x0->y + (float)l0->start.y - slope * l0->start.x) / sqrt(pow(slope, 2) + 1);
}

int main(){
	// Test values to check if it's working correctly and printing the distance
	printf("%f\n", distance(new_Point(1, 1), new_line(new_Point(2, 3), new_Point(4, 6))));
	return 0;
}