#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};


////////////////////////////////////////////////////////////////////
int print_list (const struct node *in_list) {
	struct node *list;
	list = in_list;
	
	if (in_list == NULL)
		return 1;
	
	
	while (list != NULL) {
		printf("%d, ", list->data);
		list = list->next;
	}
	
	printf("\n");
	
	return 0;
}



int len_list (struct node *in_list) {
	int i;
	
	if (in_list == NULL)
		return 0;
	
	for (i = 0; in_list != NULL; ++i)
		in_list = in_list->next;
	
	return i;
}


////////////////////////////////////////////////////////////////////
int change_node (struct node *in_list, int step, int value) {
	struct node *tmp;
	
	if (in_list == NULL)
		return 1;

	tmp = in_list;

	for (int i = 0; i < step; ++i)
		tmp = tmp->next;
	
	tmp->data = value;
	
	return 0;
}



////////////////////////////////////////////////////////////////////
int add_node (const struct node *in_list) {
	struct node *new_node = NULL;
	struct node *tmp;
	
	if (in_list == NULL)
		return 1;
	
	tmp = in_list;
	new_node = (struct node*)malloc(sizeof(struct node));
	
	while (tmp->next != NULL)
		tmp = tmp->next;
	
	tmp->next = new_node;
	
	return 0;
}


////////////////////////////////////////////////////////////////////
struct node *delete_node (struct node *in_list, int num){ //Takes the pointer to the linked list and number of the node to delete

	struct node *next = NULL;
	if (in_list == NULL)
		return 1;
	
	if (len_list == num)
		return 2;

	if (len_list == 0)
//		in_list = delete_first_node(next);


	return in_list;
}




////////////////////////////////////////////////////////////////////
struct node *delete_first_node (struct node *in_list) {

	struct node *next = NULL;

	if (in_list == NULL)
		return 1;
	
	next = in_list->next;

	in_list->data = 0;
	in_list->next = NULL;

	free(in_list);

	return next;
}


////////////////////////////////////////////////////////////////////
int delete_nodes (struct node *in_list) {
	struct node *tmp;
	
	if (in_list == NULL)
		return 1;
	
	while (in_list != NULL) {
		tmp = in_list;
		in_list = in_list->next;
		free(tmp);
	}
	
	return 0;
}


////////////////////////////////////////////////////////////////////
int debug_nodes(struct node *in_list) {
	
	int i = 0;

	if (in_list == NULL)
		return 1;

	for (; in_list != NULL; i++) {
		printf("Step: %d | Pointer: %p \n", i, (void *)in_list);
		in_list = in_list->next;
	}

}


////////////////////////////////////////////////////////////////////
int main(void) {

	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;
	
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	head->data = 0;
	head->next = second;
	
	second->data = 1;
	second->next = third;
	
	third->data = 2;
	third->next = NULL;

	print_list(head);
	printf("Test len: %d\n", len_list(head));
	!add_node(head);
	printf("Test add: %d\n", len_list(head));	
	printf("Test change: \n");
	change_node(head, 3, 3);
	print_list(head);
	
	printf("Test deleting the first node: \n");
	head = delete_first_node(head);
	print_list(head);
	
	printf("Test delete: \n");
	debug_nodes(head);	
	delete_nodes(head);
	print_list(head);	
	printf("Test len: %d\n", len_list(head));
	debug_nodes(head);	
}
