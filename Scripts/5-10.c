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
	struct polygon* new_polygon = malloc(sizeof(struct polygon));
	new_polygon->n = n;

	new_polygon->points = malloc(n * sizeof(struct point*));

	for (int i = 0; i < n; i++){
		new_polygon->points[i] = malloc(sizeof(struct point));
		new_polygon->points[i] = *(points + i);
	}
	return new_polygon;
}

struct polygon* copyPolygon(struct polygon *p1){
	// Getting p1 values
	int n = p1->n;
	struct point** points = p1->points;

	struct polygon* copy_polygon = malloc(sizeof(struct polygon));
	copy_polygon->n = n;

	copy_polygon->points = malloc(n * sizeof(struct point*));

	for (int i = 0; i < n; i++){
		// Copying every point
		copy_polygon->points[i] = malloc(sizeof(struct point));
		*copy_polygon->points[i] = **(points + i);
	}
	return copy_polygon;
}

void change_polygon_values(struct polygon* copy_polygon){
	for (int i = 0; i < copy_polygon->n; i++){
		// Changing the polygon by adding 10 to each of the coordinates
		copy_polygon->points[i]->x += 10;
		copy_polygon->points[i]->y += 10;
	}
}

void print_polygons(struct polygon* primary_polygon, struct polygon* copy_polygon){
	printf("Primary Polygon:\n");
	printf("n = %d\n", primary_polygon->n);
	for (int i = 0; i < primary_polygon->n; i++){
		printf("Point %d: x = %d , y = %d\n", i + 1, primary_polygon->points[i]->x, primary_polygon->points[i]->y);
	}

	printf("\nCopy Polygon:\n");
	printf("n = %d\n", copy_polygon->n);
	for (int i = 0; i < copy_polygon->n; i++){
		printf("Point %d: x = %d , y = %d\n", i + 1, copy_polygon->points[i]->x, copy_polygon->points[i]->y);
	}
}

int main(){
	// Test values
	struct point* primary_points[] = { new_Point(1, 6), new_Point(2, 5), new_Point(3, 7), new_Point(9, 4), new_Point(5, 8) };

	struct polygon* primary_polygon = new_polygon(5, primary_points);

	struct polygon* copy_polygon = copyPolygon(primary_polygon);
	// Changing copy_polygon's values
	change_polygon_values(copy_polygon);

	// Printing both of the polygons
	print_polygons(primary_polygon, copy_polygon);
	return 0;
}