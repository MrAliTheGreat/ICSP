#include <stdio.h>
#include <stdlib.h>

#define SIZE_ARRAY 7

typedef struct TNode TNode;

struct TNode
{
	int data;
	struct TNode* left;
	struct TNode* right;
};

// Recursive function for creating binary tree
TNode* create_binary_tree(int* arr , int start , int end){
	// Base condition
	if (start >= end){
		return NULL;
	}
	// Middle of array
	int mid = (int)((end + start) / 2);
	// Allocating memory and creating new node
	TNode* new_node = malloc(sizeof(TNode));
	new_node->data = arr[mid];
	// Find left and right children recursively
	new_node->left = create_binary_tree(arr, start, mid);
	new_node->right = create_binary_tree(arr, mid + 1, end);
	return new_node;
}

int main(){
	// Test values
	// In this test size of arr is 7 which is defined
	int arr[SIZE_ARRAY] = { 8, 10, 12, 15, 16, 20, 25 };
	TNode* root = create_binary_tree(arr, 0, SIZE_ARRAY);
	return 0;
}