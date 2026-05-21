#include "binary_search_tree.h"

int main() {
	node * root = NULL;
	root = add_node(root, 13);
	root = add_node(root, 10);
	root = add_node(root, 1);
	root = add_node(root, 5);
	root = add_node(root, 11);
	root = add_node(root, 15);
	root = add_node(root, 17);
	root = add_node(root, 14);
	
	in_order(root);
	printf("\n");

	root = delete_node(root, 13);
	
	in_order(root);
	printf("\n");
	
	//printf("%d", (find_min(root)->key));
	
	return 0;
}