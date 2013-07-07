#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUBBLE "bubble"
#define SHELL "shell"
#define HEAP "heap"
#define QUICK "quick"
#define MERGE "merge"

#define SORT_OPTION "--sort"

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


void bubble_sort(struct linked_list* l) {

}

void shell_sort(struct linked_list* l) {

}

void heap_sort(struct linked_list* l) {

}

void quick_sort(struct linked_list* l) {

}

void merge_sort(struct linked_list* l) {

}

int valid_sorting_algorithm(char* option_entered) {
	if (strcmp(option_entered, BUBBLE) == 0  || 
		strcmp(option_entered, SHELL)  == 0  || 
		strcmp(option_entered, HEAP)   == 0  || 
		strcmp(option_entered, QUICK)  == 0  || 
		strcmp(option_entered, MERGE)  == 0) {
		return 1;
	} else {
		return 0;
	}
}

/* Return index of the "--sort" option */
int parse_sorting_algorithm_from_args(int argc, char** argv) {
	int i;
	for (i=1; i < argc; i++) {
		if (strcmp(argv[i], SORT_OPTION) == 0 && (i+1 < argc)) {
			/* and next arg in vector is one of our supported search algorithms */
			if (valid_sorting_algorithm(argv[i+1])) {
				return i+1;
			}
		}
	}
	return -1;
}

int main(int argc, char* argv[]) {

	struct linked_list* my_ll;
	int i;
	
	int SHOULD_WE_SORT = 0;
	int sort_option_index;

	if ( argc > 1 ) {
		sort_option_index = parse_sorting_algorithm_from_args(argc, argv);
		if (sort_option_index != -1) {
			printf("The sorting algorithm selected is : %s\n", argv[sort_option_index]);
			SHOULD_WE_SORT = 1;
		} else {
			printf("No sorting algorithm selected. \n");
			SHOULD_WE_SORT = 0;
		}

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
