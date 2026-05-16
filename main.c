#include "binary_search_tree.h"

int main() {
	node * root = NULL;
	root = add_node(root, 13);
	root = add_node(root, 10);
	root = add_node(root, 9);
	root = add_node(root, 5);
	root = add_node(root, 11);
	root = add_node(root, 15);
	
	pre_order(root);
	
	return 0;
}