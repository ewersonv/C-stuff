#pragma once
/* Definição */
typedef struct node
{
	char *info;
	struct node *next;
}Node;

typedef struct list
{
	int size;
	node *first;
	node *last;
}List;

Node *create_node(); /* create empty node */
List *create_list(); /* create empty list */
List *insert(List *list, char *word); /* insert new word at the end of the list */
int get_pos(List *list, char *word); /* returns the position of the word if it exists in the list or -1 if it doesn't */
void delete_list(List *list); /* delete the list and free the memory space where the list is */
void delete_elem(List *list, char *word); /* delete the first element in the list that matches the word value */
void print_list(List *list); /* show the list elements on the screen */