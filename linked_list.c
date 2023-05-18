#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

////////////////////////////////////////////////////////////////////
int check_pvector(int first, int second) {

	return first < second ? 1 : 0;

}

////////////////////////////////////////////////////////////////////
int print_list (struct node *in_list) {

	if (in_list == NULL)
		return 1;
	
	
	while (in_list != NULL) {
		printf("%d", in_list->data);
		if (in_list->next != NULL)
			printf(", ");
		in_list = in_list->next;
	}
	
	putchar('\n');

	return 0;
}


////////////////////////////////////////////////////////////////////
struct node *init_list () {
	struct node *list;
	list = (struct node*)malloc(sizeof(struct node)); 
	
	list->data = 0;
	list->next = NULL;

	return list;
}

////////////////////////////////////////////////////////////////////
int len_list (struct node *in_list) {
	int i;
	
	if (in_list == NULL)
		return 0;
	
	for (i = 0; in_list != NULL; ++i)
		in_list = in_list->next;
	
	return i;
}

////////////////////////////////////////////////////////////////////
struct node *pick_node (struct node *in_list, int step) {
	int i;
	
	if (in_list == NULL)
		return 0;
	
	for (i = 0; i < step; i++) {
		in_list = in_list->next;
	}
	return in_list;

}


////////////////////////////////////////////////////////////////////
int change_node (struct node *in_list, int step, int value) {
	if (in_list == NULL)
		return 1;

	in_list = pick_node(in_list, step);
	
	in_list->data = value;
	
	return 0;
}



////////////////////////////////////////////////////////////////////
int add_node (struct node *in_list) {
	struct node *new_node = NULL;
	
	if (in_list == NULL)
		return 1;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	
	in_list = pick_node(in_list, len_list(in_list)-1);		
	in_list->next = new_node;
	
	return 0;
}


int add_nodes (struct node *in_list, unsigned int size) {
        int i, r;
	r = 0;

	if (in_list == NULL)
		return 1;

	for (i = 0; i < size && r != 1; ++i)
		r = add_node(in_list);

	return r;

}


////////////////////////////////////////////////////////////////////
struct node *delete_first_node (struct node *in_list) {
	struct node *next = NULL;

	if (in_list == NULL)
		return NULL;
	
	next = in_list->next;
	
	in_list->data = 0;
	in_list->next = NULL;

	free(in_list);
	in_list = NULL;
	return next;
}


////////////////////////////////////////////////////////////////////
struct node *delete_last_node (struct node *in_list) {
	struct node *last = NULL;
	
	if (in_list == NULL)
		return NULL;

	last = pick_node(in_list, len_list(in_list)-2);

	last->next->data = 0;
	free(last->next);

	last->next = NULL;

	return last;
}

////////////////////////////////////////////////////////////////////
struct node *delete_all_nodes (struct node *in_list) {

	if (in_list == NULL)
		return NULL;

	while (in_list != NULL) 
		in_list = delete_first_node(in_list);
	
	return in_list;
}


////////////////////////////////////////////////////////////////////
struct node *delete_node (struct node *in_list, int step) {
	struct node *last = NULL;
	struct node *next = NULL;
	
	if (in_list == NULL)
		return NULL;

	last = pick_node(in_list, step - 1);

	next = last->next->next;

	last->next->data = 0;
	last->next->next = NULL;
	free(last->next);

	last->next = next;
	
	return last;
}


////////////////////////////////////////////////////////////////////
struct node *delete_n_nodes (struct node *in_list, int first, int second) {
	int dif;
	struct node *last;

	if (!check_pvector(first, second))
		return NULL;

	dif = second - first;

	for (int i = 0; i <= dif; i++) 
		last = delete_node(in_list, first);

	return last;
}

////////////////////////////////////////////////////////////////////
int debug_nodes(struct node *in_list) {
	
	int i = 0;

	if (in_list == NULL)
		return 1;

	for (; in_list != NULL; i++) {
		printf("Step: %d | Pointer:  %p \n", i, (void *)in_list);
		in_list = in_list->next;
	}
	
	return 0;
}
