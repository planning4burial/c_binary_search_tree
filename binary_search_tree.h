#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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
	if (x < root->key)
		root->left = add_node(root->left, x);
	return root;
}

node * find_min(node * root) {
	if (root != NULL && root->left != NULL) {
		return find_min(root->left);
	}
	return root;
}

node * delete_node(node * root, int x) {
	if (root == NULL)
		return root;
	if (x > root->key)
		root->right = delete_node(root->right, x);
	else if (x < root->key)
		root->left = delete_node(root->left, x);
	else {
			// if node is a leaf 
			if (root->left == NULL && root->right == NULL) {
				free(root);
				return NULL;
			}
			// if node has only one child
			else if (root->left == NULL || root->right == NULL) {
				node * temp;
				if (root->left == NULL)
					temp = root->right;
				else
					temp = root->left;
				free(root);
				return temp;
			}
			// if node has two childs
			else {
				node * temp = find_min(root->right);
				root->key = temp->key;
				root->right = delete_node(root->right, temp->key);
			}
	}
	return root;
}

void pre_order(node * root) {
	if (root != NULL) {
		printf("%d ", root->key);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(node * root) {
	if (root != NULL) {
		in_order(root->left);
		printf("%d ", root->key);
		in_order(root->right);
	}
}

int tree_height(node * root) {
	if (root == NULL)
		return -1;
	int left_height = tree_height(root->left);
	int right_height = tree_height(root->right);
	
	if (left_height > right_height)
		return 1 + left_height;
	return 1 + right_height;
}

int num_of_nodes(node * root) {
	if (root == NULL)
		return 0;
	return 1 + num_of_nodes(root->left) + num_of_nodes(root->right);
}

bool is_valid_BST(node * node, int low, int high) {
	if(node == NULL)
		return true;
	return node->key > low
		&& node->key < high
		&& is_valid_BST(node->left, low, node->key)
		&& is_valid_BST(node->right, node->key, high);
}

bool is_search_tree(node * root) {
	return is_valid_BST(root, INT_MIN, INT_MAX);
}

bool is_strictly_binary(node * root) {
	if (root == NULL)
		return true;
	else {
		if ((root->left != NULL && root->right != NULL) || (root->left == NULL && root->right == NULL))
			return true && is_strictly_binary(root->left) && is_strictly_binary(root->right);
		return false;
	}
}

#endif