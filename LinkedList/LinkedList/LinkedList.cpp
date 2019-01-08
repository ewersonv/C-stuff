#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LinkedList.h"

Node *create_node() /* create empty node */
{
	Node * node;
	node = (Node *) malloc(sizeof(Node));
	node->info = NULL;
	node->next = NULL;
	return node;
}

List *create_list() /* create empty list */
{
	List * list;
	list = (List *) malloc(sizeof(List));
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return list;
}

List *insert(List *list, char *word) /* insert new word at the end of the list */
{
	Node *aux, *new_node;

	if (list->first == NULL) /* if the list is empty */
	{
		new_node = create_node();
		new_node->info = word;
		list->first = new_node;
		list->last = new_node;
		list->size++;
	}
	else /* list not empty */
	{
		new_node = create_node();
		new_node->info = word;

		aux = list->last;
		aux->next = new_node;
		list->last = new_node;
		list->size++;
	}
	return list;
}

int get_pos(List *list, char *word) /* returns the position of the word if it exists in the list or -1 if it doesn't */
{
	Node *aux;
	int pos = 0;

	aux = list->first;
	while (aux != NULL)
	{
		if (strcmp(word, aux->info) == 0) /* if the word is in the list */
		{
			return pos;
		}

		aux = aux->next;
		pos++;
	}
	return -1; /* if the word doesn't exist */
}

void delete_list(List *list) /* delete the list and free the memory space where the list is */
{
	Node *aux, *auxNext;

	if (list->size != 0) /* list NOT empty */
	{
		aux = list->first;
		while (aux != NULL)
		{
			if (aux->next != NULL) /* if there is another element in the list */
			{
				auxNext = aux->next;
				free(aux);
				aux = auxNext;
			}
			else /* if it is the last element in the list */
			{
				free(aux);
				free(list);
				aux = NULL;
				list = NULL;
			}
		}
	}
	else /* empty list */
	{
		free(list);
		list = NULL;
	}
}

void delete_elem(List *list, char *word) /* delete the first element in the list that matches the word value */
{
	Node *node, *aux;

	node = list->first;
	aux = list->first;

	while (node != NULL)
	{
		if (strcmp(node->info, word) == 0)
		{
			if (node == list->first)
			{
				list->first = node->next;
				free(node);
				node = NULL;
			}
			else
			{
				aux->next = node->next;
				free(node);
				node = NULL;
			}
		}
		else
		{
			aux = node;
			node = node->next;
		}
	}
}

void print_list(List *list)
{
	Node *node;

	node = list->first;

	while (node->next != NULL)
	{
		printf("%s, ", node->info);
		node = node->next;
	}
	printf("%s\n\n", node->info);
}
