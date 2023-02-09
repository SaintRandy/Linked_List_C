struct node {
	int data;
	struct node *next;
};


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
	
	for (i = 0; i < step; ++i)
		in_list = in_list->next;

	return in_list;

}

////////////////////////////////////////////////////////////////////
int change_node (struct node *in_list, int step, int value) {
	struct node *tmp;
	
	if (in_list == NULL)
		return 1;

	tmp = pick_node(in_list, step);
	
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
	int len;

	len = len_list(in_list);	

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
int debug_nodes(struct node *in_list) {
	
	int i = 0;

	if (in_list == NULL)
		return 1;

	for (; in_list != NULL; i++) {
		printf("Step: %d | Pointer:  %p \n", i, (void *)in_list);
		in_list = in_list->next;
	}

}

