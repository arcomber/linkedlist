#include <stdlib.h>  //malloc
#include <stdio.h>   //printf

#include "linkedlist.h"

int main() {


	node_ptr head = make_node(30);
	node_ptr newnode = make_node(20);
	node_ptr fnd = 0;
	node_ptr np=0;

	fnd = insert_binary(254);
    printlist(fnd);
	printf("binary2decimal = %u\n", binary2decimal(fnd));

	fnd = insert_binary(17);
	printlist(fnd);
	printf("binary2decimal = %u\n", binary2decimal(fnd));
	free_list(fnd);
	fnd = 0;

	push_back(head, newnode);
	push_back(head, make_node(22));
	push_back(head, make_node(27));

    //add_sorted_node(head, newnode);
	//add_sorted_node(head, make_node(22));
	//add_sorted_node(head, make_node(27));

	//head = push_front(head, newnode);
    //head = push_front(head, make_node(3));
	//head = push_front(head, make_node(4));
	printf("length of linked list: %lu\n", length(head));

	printf("linked list is %s\n", is_sorted(head) == 1 ? "sorted" : "not sorted");

	printf("BEFORE sort\n");
	printlist(head);

	head = insert(head, 55, 0);  
	fnd = find_by_value(head, 55);
	if(fnd) head=delete_node(head, fnd);
	head = insert(head, 56, 1);  
	fnd = find_by_value(head, 56);
	if(fnd) head=delete_node(head, fnd);
	head = insert(head, 57, 2);  
	fnd = find_by_value(head, 57);
	if(fnd) head=delete_node(head, fnd);
	head = insert(head, 58, 3); 
	fnd = find_by_value(head, 58);
	if(fnd) head=delete_node(head, fnd);
	head = insert(head, 59, 4); 
	fnd = find_by_value(head, 59);
	if(fnd) head=delete_node(head, fnd);
	head = insert(head, 60, 17);
	fnd = find_by_value(head, 60);
	if(fnd) head=delete_node(head, fnd);

	head = selection_sort(head);
	printf("AFTER sort\n");
	printlist(head);

	printf("linked list is %s\n", is_sorted(head) == 1 ? "sorted" : "not sorted");

    np = 0;
	head = reverse_r(head, np);

	reverse_print(head);

	free_list(head);


	return 0;
}
