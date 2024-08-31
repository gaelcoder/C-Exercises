/*
    QUESTÃO 07:
	Desenvolver uma função que insira um número inteiro N na 
	i-ésima posição de uma lista encadeada L. 
	
	Observação: caso a posição i informada seja inválida, a função 
	deverá retornar o valor 0; caso contrário, o retorno será 
	igual a 1.
*/

#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;


//implementação das funções
int inserirNaPosicao (TLista *L, int numero, int posicao)
{
	//declaração de variáveis
	TLista novo, aux1, aux2;
	int cont = 1;
	
	//verificando se a posição é menor do que 1 (e, portanto, inválida)
	if (posicao < 1)
	{
		return 0;
	}
	else
	{
		//inserindo na primeira posição da lista
		if (posicao == 1)
		{
			//alocando memória para o novo nó
			novo = (TLista) malloc (sizeof (TNo));
			
			//verificando se a memória foi alocada
			if (novo)
			{
				novo->valor = numero;
				
				novo->prox = *L;
				*L = novo;
				
				return 1;
			}			
			else	//a memória não foi alocada
			{
				return 0;
			}	
		}
		else  //posicão é maior do que 1
		{
			//se a lista for vazia, e a posição maior do que 1, 
			//a inserção torna-se impossível
			if (!(*L))
			{
				return 0;
			}
			
			//se chegou aqui, temos que a lista possui, pelo menos
			//1 elemento e a posição é maior do que 1
			aux1 = *L;
			aux2 = aux1->prox;
			
			//andando até chegar ao final da lista ou alcançar
			//a posição desejada
			while ((aux2) && (cont < posicao-1))
			{
				//atualizando cont
				cont++;
				
				//atualizando os ponteiros auxiliares
				aux1 = aux2;
				aux2 = aux2->prox;
			}
			
			//se chegou à posição desejada, tenta-se inserir
			if (cont == posicao-1)
			{			
				//alocando memória para o novo nó
				novo = (TLista) malloc (sizeof (TNo));
				
				//verificando se a memória foi alocada
				if (novo)
				{
					novo->valor = numero;
					
					//inserindo o novo nó entre os nós apontados por aux1 e aux2
					aux1->prox = novo;
					novo->prox = aux2;
					
					return 1;
				}
				else  //memória não foi alocada
				{
					return 0;
				}
			}
			else //posição inválida, por ser grande demais
			{
				return 0;
			}
		}
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
	TLista L = NULL;
	
	//inserindo elementos em L
	if (inserirNaPosicao (&L, 10, 2))
	{
		printf ("\nO valor 10 foi inserido na lista!\n");
	}
	else
	{
		printf ("\nO valor 10 NAO foi inserido na lista!\n");
	}
	
	if (inserirNaPosicao (&L, 4, 1))
	{
		printf ("\nO valor 4 foi inserido na lista!\n");
	}
	else
	{
		printf ("\nO valor 4 NAO foi inserido na lista!\n");
	}
	
	if (inserirNaPosicao (&L, 3, 2))
	{
		printf ("\nO valor 3 foi inserido na lista!\n");
	}
	else
	{
		printf ("\nO valor 3 NAO foi inserido na lista!\n");
	}
	
	if (inserirNaPosicao (&L, 5, 0))
	{
		printf ("\nO valor 5 foi inserido na lista!\n");
	}
	else
	{
		printf ("\nO valor 5 NAO foi inserido na lista!\n");
	}
	
	if (inserirNaPosicao (&L, 6, 2))
	{
		printf ("\nO valor 6 foi inserido na lista!\n");
	}
	else
	{
		printf ("\nO valor 6 NAO foi inserido na lista!\n");
	}
	
	if (inserirNaPosicao (&L, 15, 4))
	{
		printf ("\nO valor 15 foi inserido na lista!\n");
	}
	else
	{
		printf ("\nO valor 15 NAO foi inserido na lista!\n");
	}
	
	//exibindo a lista L
	exibir (L);
}