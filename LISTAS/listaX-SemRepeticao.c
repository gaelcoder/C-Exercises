#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;


//implementação das funções
int inserir (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se o número já existe na lista
	//if (buscar (*L, numero) != NULL)
	if (buscar (*L, numero))
	{
		return 0;
	}
	else
	{
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
}

int remover (TLista *L, int numero)
{
	//declaração de variáveis
	TLista pre, pos;
	
	if (*L)
	{
		if ((*L)->valor == numero)
		{
			//aux1 guardando o endereço do nó que será removido
			pre = *L;   
				
			//fazendo *L apontar para o "antigo segundo nó"
			*L = pre->prox;       //ou   *L = (*L)->prox;
				
			//liberando a memória do nó a ser removido
			free (pre);
				
			return 1;
		} 
		else
		{
			//'pos' aponta para o segundo nó
			pos = (*L)->prox;
			
			//'pre' aponta para o primeiro nó
			pre = *L;
			
			//percorrendo a lista com 'pos'
			while (pos)
			{
				//verificando se o valor a ser removido foi encontrado
				if (pos->valor == numero)
				{
					//fazendo o nó anterior apontar para o próximo
					pre->prox = pos->prox;
					
					//liberando o nó que contém o valor a ser removido
					free (pos);
	
					return 1;
				}
				else
				{
					pre = pos;
					pos = pos->prox;   //ou: pos = pre->prox;
				}
			}
		}
	}
	
	return 0;
}

int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista posNovo, posVelho;

	//buscando o elemento a ser alterado
	posVelho = buscar (L, velho);
	
	//se o 'velho' for encontrado
	if (posVelho)
	{
		//buscando o novo elemento na lista
		posNovo = buscar (L, novo);
		
		//se o 'novo não existir na lista, a alteração poderá ser realizada
		if (!posNovo)
		{
			//alterando os elementos
			posVelho->valor = novo;
			
			return 1;
		}
	}
	
	return 0;
}

TLista buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;

	//percorrendo os elementos da lista	
	while (aux)
	{
		//verificando se 'numero' foi encontrado
		if (aux->valor == numero)
		{
			return aux;
		}
			
		aux = aux->prox;
	}
	
	//'numero' não se encontra na lista
	return NULL;
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

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

void main ()
{
	//declaração de variáveis
	TLista L = NULL;  //representando a lista inicialmente vazia
	int num1, num2, op;
	TLista pos;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&L, num1) == 1)   //ou apenas: if (inserir (&L, num1))			        
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
					if (remover (&L, num1))
			        {
			        	printf ("\n\tRemocao realizada!");
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função
			        if (alterar (L, num1, num2))
			        {
			        	printf ("\n\tAlteracao realizada!");
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        pos = buscar (L, num1);
			        
					if (pos)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}