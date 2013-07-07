#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUBBLE "bubble"
#define SHELL "shell"
#define HEAP "heap"
#define QUICK "quick"
#define MERGE "merge"

#define SORT_OPTION_MAX_SIZE 10

#define SORT_OPTION "--sort"

struct linked_list {
    struct linked_list* next;
    int val;
};

typedef struct linked_list linked_list;

linked_list* alloc_node(linked_list* l, int val) {
    linked_list* node;
    node = (linked_list*)malloc( sizeof(linked_list) );
    node->val = val;
    node->next = l;
    return node;
}

void append(linked_list* node, int val) {
    if( node->next != NULL ) {

        /* If we are not at the end of the list, keep looking for the end */

        append(node->next, val);

    } else {
        node->next = alloc_node(NULL, val);
    }
}

void print_list(linked_list* l) {
    if ( l->next == NULL ) {
        printf("(%d)\n", l->val);
    } else {
        printf("(%d) -> ", l->val);
        print_list(l->next);
    }
}

void dump_nodes(linked_list* l) {
    if ( l->next == NULL ) {
        printf("\n");
    } else {
        printf("(%d): %p\n", l->val, l->next);
        dump_nodes(l->next);
    }
}

void free_list(linked_list** l) {
    /* Free all of the memory allocated with new_node (no leaking) */
    printf("Freeing the list...\n");
    linked_list *to_delete, *tmp_buff;
    to_delete = *l;
    while (to_delete->next != NULL) {
        tmp_buff = to_delete;
        to_delete = to_delete->next;
        free(tmp_buff);
    }
}

void swap_nodes(linked_list *a, linked_list *b) {
	int tmp;
	printf("a is %p, b is %p\n", a, b);
	//printf("Swapping . . . a->next is %p, b->next is %p\n", a->next, b->next);
	tmp = a->val;
	a->val = b->val;
	b->val = tmp;
	printf("a is %p, b is %p\n", a, b);
	//printf("Swapping . . . a->next is %p, b->next is %p\n", a->next, b->next);
}

void bubble_sort(linked_list *l) {
	printf("bubble sorting...\n");
	linked_list *head;
	int sorted = 0;
	while(!sorted) {
		head = l;
		sorted = 1;
		while(head->next != NULL) {
			printf("head->next is %p\n", head->next);
			printf("head->val is %d\n", head->val);
			if (head->val > head->next->val) {
				swap_nodes(head, head->next);
				sorted = 0;
			} 			
			head = head->next;
			sleep(1);
			print_list(l);
		}
		dump_nodes(l);
	}
}

void shell_sort(linked_list* l) {

}

void heap_sort(linked_list* l) {

}

void quick_sort(linked_list* l) {

}

void merge_sort(linked_list* l) {

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
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {

    linked_list* my_ll;
    int i;

    int WE_SHOULD_SORT = 0;
    int sort_option_index;
	char chosen_sorting_algorithm[SORT_OPTION_MAX_SIZE];

    if ( argc > 1 ) {
        sort_option_index = parse_sorting_algorithm_from_args(argc, argv);

        /** TODO:  Make this sort option index code way less annoying.
         *	 	   I think if I made the option into one arg, i.e. --sort=quick
         *		   that might help.
         **/
        if (sort_option_index != -1) {
            if (valid_sorting_algorithm(argv[sort_option_index+1])) {
				strcpy(chosen_sorting_algorithm, argv[sort_option_index+1]);	
                printf("The sorting algorithm selected is : %s\n", chosen_sorting_algorithm);
                WE_SHOULD_SORT = 1;
            } else {
                printf("Unrecognized algorithm for sort.  Ignoring...\n");
            }
        } else {
            printf("No sorting algorithm selected. \n");
            WE_SHOULD_SORT = 0;
        }

        /* allocate the first node in the linked list
           use the first command line arg for the value */

        if (sort_option_index != 1) {
            my_ll = alloc_node(NULL, atoi(argv[1]));
        } else {
            my_ll = alloc_node(NULL, atoi(argv[3]));
        }

        /* start appending at the second command line argument */

        for(i=2; i < argc; i++) {
            if ( i == sort_option_index || i == sort_option_index + 1) {
                /* skip our --sort [type] args if we have them */
                continue;
            }
            append(my_ll, atoi(argv[i]));
            print_list(my_ll);
            printf("\n");
            dump_nodes(my_ll);
        }


        print_list(my_ll);

		if (WE_SHOULD_SORT) {
			if (strcmp(chosen_sorting_algorithm, BUBBLE) == 0) {
				bubble_sort(my_ll);
			}	
		}

        free_list(&my_ll);

    } else {
        printf("Dude, no arguments?  Not cool.\n");
    }

    return 0;
}
