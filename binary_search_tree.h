#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int key;
	struct node * left;
	struct node * right;
} node;

node * new_node(int x) {
		node * new_node = (node *)malloc(sizeof(node));
		if (new_node == NULL)
			return NULL;
		new_node->key = x;
		new_node->right = NULL;
		new_node->left = NULL;
		return new_node;
}

node * add_node(node * root, int x) {
	if (root == NULL)
		return new_node(x);
	if (x > root->key)
		root->right = add_node(root->right, x);
	else if (x < root->key)
		root->left = add_node(root->left, x);
	return root;
}

void pre_order(node * root) {
	if (root != NULL) {
		printf("%d ", root->key);
		pre_order(root->left);
		pre_order(root->right);
	}
}

#endif