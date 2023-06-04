#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"

int main(void) {

	struct node *head = init_list();
	struct node *foo = NULL;
	int values[3] = {5, 6, 7};
	int r;



	print_list(head);
	printf("Test len: %d\n", len_list(head));
	
	add_node(head);
	printf("Test add: %d\n", len_list(head));	
	
	printf("Test change: \n");
	change_node(head, 1, 1);
	print_list(head);
	
	print_list(head);

	add_node(head);
	add_node(head);
	add_node(head);
	add_nodes(head, 3);
	
	change_node(head, 2, 2);
	change_node(head, 3, 3);
	change_node(head, 4, 4);
	change_nodes(head, 5, 7, values);
	r =change_nodes(head, 7, 5, values);
	printf("FOO: %d\n//\n", r);

	debug_nodes(head);
	print_list(head);
	printf("Nodes: %d\n", len_list(head));

	printf("\n------------------------\n");
	//printf("Test deleting the first node: \n");
	//head = delete_first_node(head);
	//print_list(head);
	print_list(head);
	delete_n_nodes(head, 2, 5);	
	print_list(head);
	printf("\n------------------------\n");
	//printf("Test deleting the last node: \n");
	//foo = delete_last_node(head);
	//print_list(head);
	//print_list(foo);
	
	printf("\n------------------------\n");
	printf("Test deleting the node: \n");
	delete_node(head, 2);
	print_list(head);
	
	printf("\n------------------------\n");
	printf("Test deleting all nodes: \n");
	head = delete_all_nodes(head);	
	print_list(head);
	debug_nodes(head);
	print_list(head);
	printf("All testing is done!\n");

}
