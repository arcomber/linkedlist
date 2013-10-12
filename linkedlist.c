#include <stdlib.h>  /* malloc/free */
#include <stdio.h>   /* printf */

#include "linkedlist.h"

/* head will thus change so return new head */
node_ptr push_front(node_ptr head, node_ptr to_add) {
	if(head)
		to_add->next = head;

	return to_add;
}

/* this is like adding to a queue */
node_ptr push_back(node_ptr head, node_ptr to_add) {
	/* go to end of ll and append on end */
	if(head) {
		node_ptr curr = head;
		while(curr->next)
			curr = curr->next;

		curr->next = to_add;
	} else {
		printf("push_back - no head element so cannot add\n");
	}
	return head;
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

node_ptr find_by_value(node_ptr head, stackdata value) {
	while(head && head->val != value)
		head = head->next;

	return head;
}

size_t length(node_ptr head) {
	size_t len = 0;
	while(head){
		head = head->next;
		++len;
	}
	return len;
}

node_ptr make_node(stackdata value) {
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
		if(head->next == NULL)
			break;

		head = head->next;
	}
	return head;
}

void printlist(node_ptr head) {
	while(head) {
		head = head->next;
	}
}

/* ex3.1 given ptr to ll, returns 1 if list sorted (asc), otherwise 0 */
int is_sorted(node_ptr head) {
	stackdata tmp  = 0;
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
		nextnext = next->next;
		next->next = curr;     /* point next to previous element */
		curr = next;           /* move current to be next */
		next = nextnext;       /* move next to next along */
	}
	return curr;
}

void reverse_print(node_ptr p) {
	if(!p)
		return;

	reverse_print(p->next);
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

/* ascending - swaps nodes */
node_ptr selection_sort(node_ptr head)
{
	node_ptr p, q, r, s, temp;

	p = r = head;

	while (p->next != NULL)
	{
		s = q = p->next;
		while (q != NULL)
		{
			/* left value > right value */ 
			if (p ->val > q->val)
			{
				if (p->next == q) /* if adjacent nodes */
				{
					if (p == head)  /* special case where we are at head */
					{
						p->next = q->next;
						q->next = p;
                        /* general swap - could use general swap function */
						temp = p;
						p = q;
						q = temp;

						head = p;
						r = p;
						s = q;
						q = q->next;
					}
					else /* not at head */
					{
						p->next = q->next;
						q->next = p;
						r->next = q;

						temp = p;
						p = q;
						q = temp;

						s = q;
						q = q->next;
					}
				}
				else
				{
					if (p == head)
					{
						temp = q->next;
						q->next = p->next;
						p->next = temp;

						s->next = p;

						temp = p;
						p = q;
						q = temp;

						s = q;
						q = q->next;
						head = p;
					}
					else
					{
						temp = q->next;
						q->next = p->next;
						p->next = temp;

						r->next = q;
						s->next = p;

						temp = p;
						p = q;
						q = temp;

						s = q;
						q = q->next;
					}
				}
			}
			else
			{
				s = q;
				q = q->next;
			}
		}
		r = p;
		p = p->next;
	}
	return head;
}

/* insert n after j - return new ll */
node_ptr insert(node_ptr head, int n, int j) {
	node_ptr curr = head, prev = NULL;
	node_ptr newnode = make_node(n);
	while(curr && j--) {
		prev = curr;
        curr = curr->next;
	}
	if(curr) { /* not at end */
		if(prev == NULL) {
			newnode->next = head;
			head = newnode;
		} else {
			prev->next = newnode;
			newnode->next = curr;
		}
	} else { /* push onto tail */
		prev->next = newnode;
	}
	   
	return head;
}


/* convert n to binary number and store in new ll, least significant bit at head 
Just a practice item - not really a generally useful linked list function */
node_ptr insert_binary(int n) {
    node_ptr head = NULL, np;

	while(n) {
		np = make_node(n & 1 ? 1 : 0);
		head = push_front(head, np);
		n >>= 1;
	}
    return head;
}

/* convert binary from insert_binary function back to decimal */
unsigned binary2decimal(node_ptr head) {
	unsigned tmp, i;
	tmp=i=0;
	/* reverse list first */
	head = reverse_r(head, 0);
	while(head) {
		tmp += head->val << i;
		++i;
		head = head->next;
	}
	return tmp;
}
