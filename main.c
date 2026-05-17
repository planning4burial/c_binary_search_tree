#include "binary_search_tree.h"

int main() {
	node * root = NULL;
	root = add_node(root, 13);
	root = add_node(root, 10);
	root = add_node(root, 9);
	root = add_node(root, 5);
	root = add_node(root, 11);
	root = add_node(root, 15);
	
	in_order(root);
	printf("\n");
	printf("%d\n", is_search_tree(root));
	printf("%d\n", num_of_nodes(root));
	
	return 0;
}