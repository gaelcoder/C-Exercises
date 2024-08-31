#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;

int empilhar (TLista *P, int numero)
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
		aux->prox = *P;
		
		//Passo 4: fazer com que *P aponte para o novo Nó
		*P = aux;
		
		return 1;
	}
}

int desempilhar (TLista *P, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a pilha possui elementos
	if (*P)
	{
		//aux guardando o endereço do nó que será removido
		aux = *P;   
			
		//fazendo *P apontar para o "antigo segundo nó"
		*P = aux->prox;       //ou   *P = (*P)->prox;
			
		//armazenando no parâmetro 'numero' o valor que estava no topo da pilha
		*numero = aux->valor;
		
		//liberando a memória do nó a ser removido
		free (aux);			
		
		return 1;
	} 
	else
	{
		return 0;
	}
}
  
int reempilhando(TLista *P, int x) {
    TLista aux = NULL;  // Pilha auxiliar para armazenar elementos válidos
    int valor, cont = 0;

    // Desempilhar elementos da pilha original e empilhar na pilha auxiliar os valores diferentes de x
   
    if(*P){
    while (*P != NULL) {
        desempilhar(P, &valor);  // Desempilha da pilha original

        // Se o valor desempilhado for diferente de x, empilha na pilha auxiliar
        if (valor == x){
            cont++;
        } else {
            empilhar(&aux, valor);
        }
    }

    // Transferir os elementos da pilha auxiliar de volta para a pilha original
    while (aux != NULL) {
        desempilhar(&aux, &valor);  // Desempilha da pilha auxiliar
        empilhar(P, valor);         // Empilha na pilha original
    }

    return cont; 
} else {
    return cont;
}
}

int topo (TLista P, int *t)
{
	//verificando se a pilha possui elementos
	if (P)
	{
		//armazenando em 't' o valor que está no topo da pilha
		*t = P->valor;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
    printf ("(4) Remover valor X\n");
	printf ("(5) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

void main()
{
	//declaração de variáveis
	TLista P = NULL;  //representando a pilha inicialmente vazia
	int num, op, x, res;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser inserido na pilha: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (empilhar (&P, num) == 1)   //ou apenas: if (empilhar (&P, num))			        
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Desempilhar
			case 2: //chamando a função
			        if (desempilhar (&P, &num))
			        {
			        	printf ("\n\tO valor %d foi removido da pilha!", num);
					}
					else
					{
						printf ("\n\tERRO: Pilha vazia!");
					}
					break;

			//Topo
			case 3: //chamando a função
			        if (topo (P, &num))
			        {
			        	printf ("\n\tTopo da pilha: %d", num);
					}
					else
					{
						printf ("\n\tERRO: Pilha vazia!");
					}
					break;
            case 4:
                    printf("Insira numero a ser removido da pilha: ");
                    scanf("%d", &x);
                    res = reempilhando(&P, x);

                    if(res > 0){
                        printf("Houveram %d alteracoes na pilha.", res);
                    } else {
                        printf("Nao houve alteracoes na pilha.");
                    }
					
			//Saída
			case 5: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 5);
}