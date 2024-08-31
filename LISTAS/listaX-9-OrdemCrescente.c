/*
    QUESTÃO 09:
	Implementar uma função que, dada uma lista dinâmica do tipo 
	TLista, verifique se os elementos da estrutura encontram-se 
	ordenados de forma crescente ou não.
*/

#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;

int verificarOrdenacao (TLista L)
{
	//declaração de variáveis
	TLista aux1, aux2;	
	
	//verificando se a lista está vazia
	if (!L)
	{
		return 1;
	}
	else
	{
		//inicializando os auxiliares
		aux1 = L;
		aux2 = L->prox;  //ou    aux2 = aux1->prox;
		
		//percorrendo a lista
		while (aux2)
		{
			//verificando se dois elementos vizinhos estão desordenados
			if (aux2->valor < aux1->valor)
			{
				return 0;
			}
			
			//atualizando os auxiliares
			aux1 = aux2;  //ou   aux1 = aux1->prox;
			aux2 = aux2->prox;   //ou   aux2 = aux1->prox;
		}	
		
		return 1;	
	}
}

int inserir (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocar memória para o novo elemento
	aux = (TLista) malloc (sizeof(TNo));   //malloc - memory allocation
	
	//verificando se houve erro na alocação
	if (!aux)
	{
		return 0;
	}
	else
	{
		//Passo 2: armazenando 'numero' na posição recém-alocada
		aux->valor = numero;
		
		//Passo 3: fazer o novo nó apontar para o "antigo primeiro nó"
		aux->prox = *L;
		
		//Passo 4: fazer com que *L aponte para o novo Nó
		*L = aux;
		
		return 1;
	}
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux = L;
	
	//verificando se a lista está vazia
	if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Lista: ");
	
		//while (aux != NULL)
		while (aux)
		{
			printf ("%d ", aux->valor);
			//ou:    printf ("%d ", (*aux).valor);
			
			aux = aux->prox;
		}
		
		printf ("\n");
	}
}

//main
void main ()
{
	//declaração de variáveis
	TLista L1 = NULL, L2 = NULL;
	
	//inserindo elementos em L1
	inserir (&L1, 5);
	inserir (&L1, 4);
	inserir (&L1, 3);
	inserir (&L1, 3);
	inserir (&L1, 1);
	
	//exibindo a lista L1
	exibir (L1);
	
	//chamando a função para L1
	if (verificarOrdenacao (L1))
	{
		printf ("\nL1 esta ordenada crescentemente!\n");
	}
	else
	{
		printf ("\nL1 esta NAO ordenada crescentemente!\n");
	}
	
	//inserindo elementos em L2
	inserir (&L2, 8);
	inserir (&L2, 5);
	inserir (&L2, 6);
	inserir (&L2, 3);
		
	//exibindo a lista L2
	exibir (L2);
	
	//chamando a função para L2
	if (verificarOrdenacao (L2))
	{
		printf ("\nL2 esta ordenada crescentemente!\n");
	}
	else
	{
		printf ("\nL2 esta NAO ordenada crescentemente!\n");
	}
}