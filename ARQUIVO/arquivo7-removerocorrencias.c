#include <stdio.h>
//implementação das funções
int remover (char nomeArq[], int numero)
{
	//declaração de variáveis
	FILE *arq, *temp;
	int valor, cont = 0;
	
	//abrindo os arquivos
	arq = fopen (nomeArq, "r");
	temp = fopen ("temp.txt", "w");
	
	//testando se houve erro na abertura
	if (!arq || !temp)
	{
		fclose (arq);
		fclose (temp);
		
		return -1;
	}
	else
	{
		//lendo todos os valores do arquivo
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			//verificando se não é 'valor' não é o número a ser removido
			if (valor != numero)
			{
				fprintf (temp, "%d\n", valor);
			}
			else
			{
				cont++;
			}
		}
		
		//fechando os arquivos
		fclose (arq);
		fclose (temp);
		
		//copiando o arquivo temporário para o original		
		copiarArquivo (nomeArq, "temp.txt");
		
		//retornando a quantidade de remoções realizadas
		return cont;
	}
}

int copiarArquivo (char nomeArqD[], char nomeArqO[])
{
	//declaração de variáveis
	char ch;
	FILE *arqO, *arqD;
	
	//abrindo os arquivos
	arqO = fopen (nomeArqO, "r");
	arqD = fopen (nomeArqD, "w");
	
	//verificar se ocorreu erro na abertura dos arquivos
	//if ((arqO == NULL) || (arqD == NULL))
	if (!arqO || !arqD)
	{
		//fechando os arquivos que podem ter sido abertos
		fclose (arqO);
		fclose (arqD);
		
		return 0;
	}
	else
	{
		//copiando o conteúdo do arquivo de origem para o de destino
		while (fscanf(arqO, "%c", &ch) != EOF)   //end of file
		{
			fprintf (arqD, "%c", ch);
		}
		
		//fechar os arquivos
		fclose (arqO);
		fclose (arqD);
		
		return 1;
	}
}

void main ()
{
	//declaração de variáveis
	char nomeArq[30];
	int valor, retorno;
	
	//obtendo o nome do arquivo
	printf ("Nome do arquivo: ");
	fflush (stdin);
	gets (nomeArq);
	
	//obtendo o valor a ser removido
	printf ("\nValor a ser removido: ");
	scanf ("%d", &valor);
	
	//chamado a função
	retorno = remover (nomeArq, valor);
	
	switch (retorno)
	{
		case -1: printf ("Erro na abertura do arquivo!\n");
		         break;
		         
		case 0:  printf ("O valor %d nao foi encontrado no arquivo!\n", valor);
		         break;
		
		default: printf ("%d ocorrencias do valor foram removidas", retorno);
	}
}