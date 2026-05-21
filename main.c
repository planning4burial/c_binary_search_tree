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
	
	in_order(root);
	printf("\n");

	root = delete_node(root, 12);
	
	in_order(root);
	printf("\n");
	
	return 0;
}