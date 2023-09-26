/*
* TODO LIST:
* 1. Add sorting to the list.
* 2. Make a proper header file. 
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

////////////////////////////////////////////////////////////////////
int check_pvector(int first, int second) {

	return first <= second ? 1 : 0;

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
int change_nodes (struct node *in_list, int step_one, int step_two, int *values) {
	int r;

	if (in_list == NULL)
		return 1;

	if (check_pvector(step_one, step_two) == 0)
		return 1;

	for (int i = 0; step_one <= step_two && r != 1; ++i && ++step_one)
		r = change_node(in_list, step_one, values[i]);
	
	return 0;
}

////////////////////////////////////////////////////////////////////
int add_node (struct node *in_list) {
	struct node *new_node = NULL;
	
	if (in_list == NULL)
		return 1;
	
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = 0;
	
	in_list = pick_node(in_list, len_list(in_list)-1);		
	in_list->next = new_node;
	
	return 0;
}


////////////////////////////////////////////////////////////////////
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
struct node *insert_node (struct node *in_list, int value, unsigned int step) {
	struct node *before;
	struct node *new;
	struct node *after;

	if (in_list == NULL)
		return NULL;

	before = pick_node(in_list, step - 1);
	after = pick_node(in_list, step);

	new = (struct node*)malloc(sizeof(struct node));	

	new->data = value;
	
	before->next = new;
	new->next = after;

	return new;
	
}


struct node *insert_nodes (struct node *in_list, int values[], size_t arr_size, unsigned int first, 
			   unsigned int second) {
	
	size_t i;
	struct node *new;

	if (!check_pvector(first, second))
		return NULL;

	if (arr_size != (second - first + 1))
		return NULL;

	for (i = 0; i < arr_size; i++)
		new = insert_node(in_list, values[i], first + i);	

	return new;
}

struct node *copy_list (struct node *in_list) {

	if (in_list == NULL)
		return NULL;


	struct node *new;
	struct node *ret;

	size_t i;
	int len;

	len = (int) (len_list(in_list) - 1);

	new = init_list();
	ret = new;

	add_nodes(new, len);
	
	for (i = 0; i < len + 1; i++){
		new->data = in_list->data;
		new = new->next;
		in_list = in_list->next;
	}


	return ret; 
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
