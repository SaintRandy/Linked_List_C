/*
* TODO LIST:
* 1. Make a proper header file.
* 2. Refactor quick sort function.
* 3. Clean up the test file.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

////////////////////////////////////////////////////////////////////
size_t check_pvector(size_t first, size_t second) {

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
struct node *pick_node (struct node *in_list, size_t step) {
	size_t i;
	
	if (in_list == NULL)
		return 0;
	
	for (i = 0; i < step; i++) {
		in_list = in_list->next;
	}
	return in_list;
}


////////////////////////////////////////////////////////////////////
int change_node (struct node *in_list, size_t step, int value) {
	if (in_list == NULL)
		return 1;

	in_list = pick_node(in_list, step);
	
	in_list->data = value;
	
	return 0;
}

////////////////////////////////////////////////////////////////////
int change_nodes (struct node *in_list, size_t step_one, size_t step_two, int *values) {
	int r;

	if (in_list == NULL)
		return 1;

	if (check_pvector(step_one, step_two) == 0)
		return 1;

	for (size_t i = 0; step_one <= step_two && r != 1; ++i && ++step_one)
		r = change_node(in_list, step_one, values[i]);
	
	return 0;
}

////////////////////////////////////////////////////////////////////
int add_node (struct node *in_list) {
	struct node *new_node = NULL;
	
	if (in_list == NULL)
		return 1;
	
	
	new_node = init_list();

	in_list = pick_node(in_list, len_list(in_list)-1);		
	in_list->next = new_node;
	
	return 0;
}


////////////////////////////////////////////////////////////////////
int add_nodes (struct node *in_list, size_t size) {
        size_t i;
	int r;
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
struct node *delete_node (struct node *in_list, size_t step) {
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
struct node *delete_n_nodes (struct node *in_list, size_t first, size_t second) {
	size_t dif;
	struct node *last;

	if (!check_pvector(first, second))
		return NULL;

	dif = second - first;

	for (size_t i = 0; i <= dif; i++) 
		last = delete_node(in_list, first);

	return last;
}



////////////////////////////////////////////////////////////////////
struct node *insert_node (struct node *in_list, int value, size_t step) {
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


struct node *insert_nodes (struct node *in_list, int values[], size_t arr_size, size_t step) {
	
	size_t i;
	struct node *new;

	if (in_list == NULL)
		return NULL;

	for (i = 0; i < arr_size; i++)
		new = insert_node(in_list, values[i], step + i);	

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

void swap_ints(int *first, int *second) {
	
	*first += *second; 
	*second = *first - *second; 
	*first = *first - *second; 

}

struct node *sort_list(struct node *in_list) {

	if (in_list == NULL)
		return NULL;

	size_t i, j;
	struct node *fp, *sp;

	size_t len = (size_t) (len_list(in_list));

	for (fp = in_list; fp != NULL; fp = fp->next) {
		for (sp = fp; sp != NULL; sp = sp->next) {
			if (fp->data > sp->data)
				swap_ints(&fp->data, &sp->data);
		}
	}

	return in_list;

}

struct node *connect_nodes(struct node *first_list, struct node *second_list) {

	struct node *tmp = NULL;

	if (first_list == NULL)
		return second_list;		

	tmp = pick_node(first_list, len_list(first_list)-1);

	if (tmp->next != NULL)
		return NULL;

	tmp->next = second_list;

	return first_list;
}


struct node *disconnect_node(struct node *in_list, size_t step) {

	struct node *tmp;

	if (in_list == NULL)
		return NULL;

	tmp = pick_node(in_list, step);

	pick_node(in_list, step-1)->next = tmp->next;

	tmp->next = NULL;

	return tmp;

}


struct node *quick_sort_list(struct node *in_list) {

	size_t i;
	size_t list_size;

	struct node *anchor;
	struct node *pivot;
	struct node *tmp;
	struct node *lesser_list = NULL;
	struct node *greater_list = NULL;

	if (in_list == NULL)
		return NULL;

	if (len_list(in_list) < 2)
		return in_list;


	anchor = in_list;
	pivot = pick_node(in_list, 1);
	list_size = len_list(in_list) - 1;

	for (i = 0; i < list_size; i++) {

		tmp = disconnect_node(in_list, 1);
		
		if (anchor->data >  tmp->data) {
			lesser_list = connect_nodes(lesser_list, tmp);
		} else {
			greater_list = connect_nodes(greater_list, tmp);
		}


	}

	
	lesser_list = quick_sort_list(lesser_list);
	greater_list = quick_sort_list(greater_list);

	return connect_nodes(connect_nodes(lesser_list, anchor), greater_list);


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
