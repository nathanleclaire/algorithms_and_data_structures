#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	struct linked_list* next;
	int val;
};

struct linked_list* alloc_node(struct linked_list* l, int val) {
	struct linked_list* node;
    node = (struct linked_list*)malloc( sizeof(struct linked_list) );
	node->val = val;
	node->next = l;
	return node;
}

void append(struct linked_list* node, int val) {
	if( node->next != NULL ) {

		/* If we are not at the end of the list, keep looking for the end */
		
		append(node->next, val);
	
	} else {
		node->next = alloc_node(NULL, val); 
	}
}

void print_list(struct linked_list* l) {
	if ( l->next == NULL ) {
		printf("(%d)\n", l->val);
	} else {
		printf("(%d) -> ", l->val);
		print_list(l->next);
	}
}

void dump_nodes(struct linked_list* l) {
	if ( l->next == NULL ) {
		printf("\n");
	} else {
		printf("(%d): %p\n", l->val, l->next);
		dump_nodes(l->next);
	}
}

int main(int argc, char* argv[]) {

	struct linked_list* my_ll;
	int i;

	if ( argc > 1 ) {

		// allocate the first node in the linked list
		// use the first command line arg for the value
	
		my_ll = alloc_node(NULL, atoi(argv[1])); 	

		// start appending at the second command line argument

		for(i=2; i < argc; i++) {
			append(my_ll, atoi(argv[i]));
			print_list(my_ll);
			printf("\n");
			dump_nodes(my_ll);
		}

		print_list(my_ll);

	} else {
		printf("Dude, no arguments?  Not cool.\n");
	}

	return 0;
}	
