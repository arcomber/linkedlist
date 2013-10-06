#include <stdlib.h>  /* malloc/free */
#include <stdio.h>   /* printf */

#include "linkedlist.h"


/* this is like adding to a queue */
void push_back(node_ptr head, node_ptr to_add) {
	/* go to end of ll and append on end */
	if(head) {
		node_ptr curr = head;
		while(curr->next)
			curr = curr->next;

		curr->next = to_add;
	} else {
		printf("push_back - no head element so cannot add\n");
	}
}

/* We add node by num in ascending order */
void add_sorted_node(node_ptr head, node_ptr to_add) {
	node_ptr prev = head;

	while(head && head->val < to_add->val) {
		prev = head;
		head = head->next;
	}
	prev->next = to_add;
	to_add->next = head;
}

/* TODO : make return type void to make consistent with push_back */
node_ptr push_front(node_ptr head, node_ptr to_add) {
	if(head)
		to_add->next = head;

	return to_add;
}

node_ptr find_by_value(node_ptr head, int value) {
	while(head && head->val != value)
		head = head->next;

	return head;
}

int length(node_ptr head) {
	int len = 0;
	while(head){
		head = head->next;
		++len;
	}
	return len;
}

node_ptr make_head(int value) {
	node_ptr head = malloc(sizeof(node));
	head->val = value;
	head->next = '\0';
	return head;
}

node_ptr make_node(int value) {
	node_ptr newnode = malloc(sizeof(node));
	newnode->val = value;
	newnode->next = NULL;
	return newnode;
}

void free_list(node_ptr head) {
	node_ptr curr = head;
	node_ptr next = 0;
	while(curr) {
		next = curr->next;
		printf("About to free node %p, val %u\n", curr, curr->val);
		free(curr);
		curr = next;
	}
}

/* return new head */
node_ptr delete_node(node_ptr head, node_ptr to_delete) {

	node_ptr orig_head = head;
	node_ptr prev = head;
	while(head) {
		if(head == to_delete) {
			prev->next = to_delete->next;
			if(orig_head == head)
				orig_head = prev->next;

			free(to_delete);
			return orig_head;
		}
		prev = head;
		head = head->next;
	}
	return 0;
}

node_ptr get_last_node(node_ptr head) {
	while(head) {
		if(head->next == '\0')
			break;

		head = head->next;
	}
	return head;
}

void printlist(node_ptr head) {
	while(head) {
		printf("node_ptr address: %p, value: %u\n", head, head->val);
		head = head->next;
	}
}


/* ex3.1 given ptr to ll, returns 1 if list sorted (asc), otherwise 0 */
int is_sorted(node_ptr head) {
	int tmp  = 0;
	while(head) {
		if(head->val >= tmp)
			tmp = head->val;
		else
			return 0;

		head = head->next;
	}
	return 1;
}

/* three tmp variables. current, next, next-next.  on each one you simply change next to point to previous
 rather than next node
*/
node_ptr reverse_nodes(node_ptr head) {
	node_ptr curr = 0, next = 0, nextnext = 0;

	if(head == 0)
		return head;

	/* setup.  point curr to start of list.  next to next element and re-point next field of first element */
	curr = head;
	next = head->next;
	head->next = 0;

	while(next != '\0') {
		printf("curr=%p, val=%u, next ptr = %s\n", curr, curr->val, curr->next == NULL ? "null" : "valid");
		nextnext = next->next;
		next->next = curr;     /* point next to previous element */
		curr = next;           /* move current to be next */
		next = nextnext;       /* move next to next along */
	}
	printf("curr=%p, val=%u, next ptr = %s\n", curr, curr->val, curr->next == NULL ? "null" : "valid");
	return curr;
}

node_ptr reverse_nodes_angus_try(node_ptr head) {
	node_ptr curr = 0, next = 0, nextnext = 0;

	if(head == 0)
		return head;

	/*setup.  point curr to start of list.  next to next element and re-point next field of first element */
	curr = head;
	next = head->next;
	head->next = 0;

	while(next != '\0') {
		printf("curr=%p, val=%u, next ptr = %s\n", curr, curr->val, curr->next == NULL ? "null" : "valid");
		nextnext = next->next;
		next->next = curr;     /*reverse link */
		curr = next;
		next = nextnext;
	}
	printf("curr=%p, val=%u, next ptr = %s\n", curr, curr->val, curr->next == NULL ? "null" : "valid");
	return curr;
}

void reverse_print(node_ptr p) {
	if(!p)
		return;

	reverse_print(p->next);
	printf("curr=%p, val=%u, next ptr = %s\n", p, p->val, p->next == NULL ? "null" : "valid");
}

node_ptr reverse_r(node_ptr pivot, node_ptr backward) {
	node_ptr rest;

	if (pivot == 0)
		return backward; 
	/* flip the head of pivot from forward to backward */
	rest = pivot->next;
	pivot->next = backward;
	/* continue */
	return reverse_r(rest, pivot);
}
