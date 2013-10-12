/* Beginning - int linked-list.  To be changed so caller can specify data type */

typedef struct node_ {
	int val;
	struct node_* next;
} node, * node_ptr;

/* this is like adding to a queue */
void push_back(node_ptr head, node_ptr to_add);

/* We add node by num in ascending order */
void add_sorted_node(node_ptr head, node_ptr to_add);

/* returns new head
this one is like adding to a stack
this is a push_front
TODO: to make consistent with push_front, make return type void */
node_ptr push_front(node_ptr head, node_ptr to_add);

/* find by value */
node_ptr find_by_value(node_ptr head, int value);

/* return length of ll */
int length(node_ptr head);
/* TODO - should only need make_node to do this. create head element */
node_ptr make_head(int value);
/* TODO - consider hiding this - implementation details???  create a linked list node */
node_ptr make_node(int value);

/* free all nodes */
void free_list(node_ptr head);

//return new head
node_ptr delete_node(node_ptr head, node_ptr to_delete);

/* return last node in ll */
node_ptr get_last_node(node_ptr head);
/* print ll */
void printlist(node_ptr head);
/* is sorted by value */
int is_sorted(node_ptr head);
   

node_ptr reverse_nodes(node_ptr head);

node_ptr reverse_nodes_angus_try(node_ptr head);

void reverse_print(node_ptr p);

node_ptr reverse_r(node_ptr pivot, node_ptr backward);

node_ptr selection_sort(node_ptr head);
