#include <stdio.h>
#include <stdlib.h>

struct linkedList {
	struct linkedList* next;
	int val;
};

struct linkedList* alloc_node(struct linkedList* l, int val) {
	struct linkedList* node;
    node = (struct linkedList*)malloc( sizeof(struct linkedList) );
	node->val = val;
	node->next = l;
	return node;
}

void append(struct linkedList* node, int val) {
	if( node->next != NULL ) {

		/* If we are not at the end of the list, keep looking for the end */
		
		append(node->next, val);
	
	} else {
		node->next = alloc_node(NULL, val); 
	}
}

void printList(struct linkedList* l) {
	if ( l->next == NULL ) {
		printf("(%d)\n", l->val);
	} else {
		printf("(%d) -> ", l->val);
		printList(l->next);
	}
}

void dumpNodes(struct linkedList* l) {
	if ( l->next == NULL ) {
		printf("\n");
	} else {
		printf("(%d): %p\n", l->val, l->next);
		dumpNodes(l->next);
	}
}

int main(int argc, char* argv[]) {

	struct linkedList* myLL;
	int i;

	if ( argc > 1 ) {

		// allocate the first node in the linked list
		// use the first command line arg for the value
	
		myLL = alloc_node(NULL, atoi(argv[1])); 	

		// start appending at the second command line argument

		for(i=2; i < argc; i++) {
			append(myLL, atoi(argv[i]));
			printList(myLL);
			printf("\n");
			dumpNodes(myLL);
		}

		printList(myLL);

	} else {
		printf("Dude, no arguments?  Not cool.\n");
	}

	return 0;
}	
