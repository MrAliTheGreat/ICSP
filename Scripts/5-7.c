#include <stdio.h>
#include <stdlib.h>

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

int main(){
	int start_x = 2, start_y = 3, end_x = 4, end_y = 5;
	struct line* final_line = new_line(new_Point(start_x, start_y), new_Point(end_x, end_y));
	// Testing the structs
	printf("start_x = %d , start_y = %d , end_x = %d , end_y = %d\n", final_line->start.x, final_line->start.y, final_line->end.x, final_line->end.y);
	return 0;
}