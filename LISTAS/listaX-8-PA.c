/*
    QUESTÃO 08:
	Implementar uma função que crie uma lista encadeada (dinâmica) 
	com os N primeiros termos de uma PA (progressão aritmética) 
	de razão R e primeiro termo igual a A1.
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
void criarPA (TLista *L, int a1, int r, int n)
{
	//declaração de variáveis
	int i, termo;
	
	//incializando a lista
	*L = NULL;
	
	//calculando o último termo da PA (uma vez que a inserção se dará no início da lista)
	termo = a1 + (n-1)*r;
	
	//inserindo na lista os 'n' elementos da PA
	for (i=1;i<=n;i++)
	{
		//inserir (&(*L), termo);
		inserir (L, termo);
		
		//atualizando o termo a ser inserido na lista
		termo -= r;
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
	TLista L;
	int a1, n, razao;
	
	//obtendo os dados que definem a PA
	printf ("Primeiro termo: ");
	scanf ("%d", &a1);

	printf ("Razao: ");
	scanf ("%d", &razao);

	printf ("Quantidade de termos: ");
	scanf ("%d", &n);
	
	//chamando a função
	criarPA (&L, a1, razao, n);
	
	//exibindo a PA
	exibir (L);
		
}