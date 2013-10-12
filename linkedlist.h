/* linked-list learning exercise.  Define data type in linkedlistdata.h */
#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

#include "linkedlistdata.h"

typedef struct node_ {
	stackdata val;
	struct node_* next;
} node, * node_ptr;

/* returns new head
this one is like adding to a stack
head will thus change so return new head */
node_ptr push_front(node_ptr head, node_ptr to_add);

/* this is like adding to a queue */
node_ptr push_back(node_ptr head, node_ptr to_add);

/* We add node by num in ascending order */
void add_sorted_node(node_ptr head, node_ptr to_add);

/* find by value */
node_ptr find_by_value(node_ptr head, stackdata value);

/* return length of ll */
size_t length(node_ptr head);

/* create a linked list node */
node_ptr make_node(stackdata value);

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
   
/* reverse nodes in list - iterative method */
node_ptr reverse_nodes(node_ptr head);
/* print from end back */
void reverse_print(node_ptr p);
/* recursive reversal of ll nodes */
node_ptr reverse_r(node_ptr pivot, node_ptr backward);

/* ascending - swaps nodes */
node_ptr selection_sort(node_ptr head);

/* insert n after j - return new ll */
node_ptr insert(node_ptr head, int n, int j);

/* functions below are learning exercises rather than useful linked list functions */

/* convert n to binary number and store in new ll, least significant bit at head */
node_ptr insert_binary(int n);

/* convert binary from insert_binary function back to decimal */
unsigned binary2decimal(node_ptr head);

#endif /* LINKEDLIST_H__ */
