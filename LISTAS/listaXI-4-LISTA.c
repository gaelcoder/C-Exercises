#include <stdio.h>
#include <stdlib.h>

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

int elementoExiste(TLista L, int valor) {
    TLista aux = L;
    while (aux != NULL) {
        if (aux->valor == valor) {
            return 1; // Retorna verdadeiro se o elemento já existe na lista
        }
        aux = aux->prox;
    }
    return 0; // Retorna falso se o elemento não existe na lista
}

// Função para criar uma nova lista sem repetições a partir da lista L
TLista novaListaSemRepeticoes(TLista L) {
    TLista novaLista = NULL; // Inicializa a nova lista vazia
    TLista aux = L; // Auxiliar para percorrer a lista L
    
    while (aux != NULL) {
        // Verifica se o elemento já existe na nova lista
        if (!elementoExiste(novaLista, aux->valor)) {
            inserir(&novaLista, aux->valor); // Insere o elemento na nova lista se não existir
        }
        aux = aux->prox;
    }
    
    return novaLista;
}

int remover (TLista *L, int numero)
{
	//declaração de variáveis
	TLista pre, pos;
	int cont = 0;
	
	while ((*L) && ((*L)->valor == numero))
	{
		//aux1 guardando o endereço do nó que será removido
		pre = *L;   
			
		//fazendo *L apontar para o "antigo segundo nó"
		*L = pre->prox;       //ou   *L = (*L)->prox;
			
		//liberando a memória do nó a ser removido
		free (pre);
			
		//atualizando a quantidade de remoções
		cont++;	
	} 

	//se a lista ainda possuir elementos
	if (*L)
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

				//atualizando a quantidade de remoções
				cont++;	
				
				//fazendo 'pos' apontar para o próximo nó da lista
				pos = pre->prox;
			}
			else
			{
				pre = pos;
				pos = pos->prox;   //ou: pos = pre->prox;
			}
		}
	}
	
	//retornando a quantidade de remoções realizadas
	return cont;
}

int contarOcorrencias(TLista L, int X) {
    // Caso base: se a lista estiver vazia, retorna 0
    if (L == NULL) {
        return 0;
    }
    
    // Verifica se o valor do nó atual é igual a X
    if (L->valor == X) {
        // Se sim, retorna 1 + o resultado da recursão no restante da lista
        return 1 + contarOcorrencias(L->prox, X);
    } else {
        // Se não, retorna apenas o resultado da recursão no restante da lista
        return contarOcorrencias(L->prox, X);
    }
}

int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista aux = L;
	int cont = 0;

	//percorrendo os elementos da lista	
	while (aux)
	{
		//verificando se foi encontrado o número a ser alterado
		if (aux->valor == velho)
		{
			aux->valor = novo;
			cont++;
		}
			
		aux = aux->prox;
	}
	
	//retornando a quantidade de alterações realizadas
	return cont;
}

int buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;

	//percorrendo os elementos da lista	
	while (aux)
	{
		//verificando se 'numero' foi encontrado
		if (aux->valor == numero)
		{
			return 1;
		}
			
		aux = aux->prox;
	}
	
	//'numero' não se encontra na lista
	return 0;
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

void removerRepeticoes(TLista L) {
    TLista atual, comp, anterior;
    
    atual = L; // Inicializa o nó atual
    while ((atual != NULL) && ((atual->prox) != NULL)) {
        comp = atual; // Inicializa o nó comparado
        
        while ((comp->prox) != NULL) {
            if ((atual->valor) == (comp->prox->valor)) {
                TLista removido = comp->prox; // Guarda o nó repetido
                comp->prox = comp->prox->prox; // Remove o nó repetido da lista
                free(removido); // Libera a memória do nó removido
            } else {
                comp = comp->prox; // Move para o próximo nó
            }
        }
        
        atual = atual->prox; // Move para o próximo nó na lista
    }
    exibir(atual);
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
    printf ("(6) Contagem\n");
    printf ("(7) Lista nova s/ repeticao\n");
    printf ("(8) Mesma lista s/ repeticao\n");
	printf ("(9) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

//main
void main ()
{
	//declaração de variáveis
	TLista L = NULL;  //representando a lista inicialmente vazia
	int num1, num2, op, resp, x;	
	
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
			        resp = remover (&L, num1);
			        
					if (resp > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", resp);
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
			        resp = alterar (L, num1, num2);
			        
			        if (resp > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", resp);
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
			        resp = buscar (L, num1);
			        
					if (resp)
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
            
            case 6: 
                    printf("Digite numero a ser contado: ");
                    scanf("%d", &x);
                    resp = contarOcorrencias(L, x);
                    if(resp > 0){
                        printf("Foram encontradas %d ocorrencias do numero %d", resp, x);
                    } else {
                        printf("Nenhuma ocorrência encontrada.");
                    }
                    break;
			case 7:
                    printf("Lista nova sem repeticoes: ");
                    TLista ListaNova = novaListaSemRepeticoes(L);
                    exibir(ListaNova);
                    break;
			//Saída
            case 8: 
                    printf("Mesma lista sem repeticoes: ");
                    removerRepeticoes(L);
                    break;

			case 9: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 9);
}