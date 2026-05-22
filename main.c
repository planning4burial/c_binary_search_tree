#include "binary_search_tree.h"

int main() {
	node * root = NULL;
	
	int to_be_added[15] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
	
	for (int i = 0; i < 15; ++i) {
		root = add_node(root, to_be_added[i]);
	}
	
	/*
							 8
            /     \
          4         12
         / \       /  \
        2   6     10   14
       /\   /\    /\   /\
      1  3 5  7  9 11 13 15
	
	*/
	printf("in order traversal: ");
	in_order(root);
	printf("\n");

	printf("is strictly binary?: ");
	printf("%d\n", is_strictly_binary(root));
	
	printf("number of nodes: ");
	printf("%d\n", num_of_nodes(root));
	
	printf("tree height: ");
	printf("%d\n", tree_height(root));
	
	return 0;
}