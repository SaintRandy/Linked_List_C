#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"

int main(void) {

	struct node *head = init_list();


	print_list(head);
	printf("Test len: %d\n", len_list(head));
	
	add_node(head);
	printf("Test add: %d\n", len_list(head));	
	
	printf("Test change: \n");
	change_node(head, 1, 1);
	print_list(head);
	
	printf("Test deleting the first node: \n");
	head = delete_first_node(head);
	print_list(head);
	
	debug_nodes(head);

}
