#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

int main()
{
	List *lista;
	Node *aux;
	char *palavra;


	lista = create_list();

	palavra = (char *) "ola";
	insert(lista, palavra);

	palavra = (char *) ",";
	insert(lista, palavra);

	palavra = (char *) "mundo";
	insert(lista, palavra);

	palavra = (char *) "!";
	insert(lista, palavra);



	palavra = (char *) "mundo";
	printf("Posicao palavra buscada: %d\n\n", get_pos(lista, palavra));

	
	
	printf("Conteudo: ");
	print_list(lista);


	palavra = (char *) ",";
	delete_elem(lista, palavra);
	
	printf("Conteudo: ");
	print_list(lista);

	system("pause");

	delete_list(lista);

	return 0;
}