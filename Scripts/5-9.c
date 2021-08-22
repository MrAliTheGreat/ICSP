#include <stdio.h>
#include <stdlib.h>

struct point{
	int x, y;
};

struct polygon{
	int n;
	struct point** points;
};

struct point* new_Point(int x, int y){
	struct point* new_p = malloc(sizeof(struct point));
	new_p->x = x;
	new_p->y = y;
	return new_p;
}

struct polygon* new_polygon(int n, struct point **points){
	// Creating new polygon
	struct polygon* new_polygon = malloc(sizeof(struct polygon));
	new_polygon->n = n;

	// The polygon has array of point pointers
	new_polygon->points = malloc(n * sizeof(struct point*));

	for (int i = 0; i < n; i++){
		// Each of the points
		new_polygon->points[i] = malloc(sizeof(struct point));
		// Setting the point values
		new_polygon->points[i] = *(points + i);
	}
	return new_polygon;
}

int main(){
	// Test values
	struct point* test_points[] = { new_Point(1, 1), new_Point(2, 5), new_Point(3, 7), new_Point(9, 4), new_Point(5, 8) };
	struct polygon* test_polygon = new_polygon(5, test_points);
	return 0;
}