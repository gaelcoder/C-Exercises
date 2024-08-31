//importação de bibliotecas
#include <stdio.h>

//implementação das funções
int lerArquivo (char nomeArq[])
{
	//declaração de variáveis
	char ch;
	FILE* arq;	//passo 1: criar uma variável do tipo FILE
	
	//passo 2: abrir o arquivo + associar a variável FILE* a um arquivo em disco
	arq = fopen (nomeArq, "r");  //w - write / r - read / a - append
	
	//verificar se ocorreu erro na abertura do arquivo
	if (arq == NULL)
	{
		return 0;
	}
	else
	{
		//passo 3: manipulação do arquivo
		while (fscanf(arq, "%c", &ch) != EOF)   //end of file
		{
			printf ("%c", ch);
		}
		
		//passo 4: fechar o arquivo
		fclose (arq);
		
		return 1;
	}
}
//main
void main ()
{
	//declaração de variáveis
	char nome[30];
	
	//lendo o nome do arquivo
	printf ("Nome do arquivo: ");
	fflush (stdin);
	gets (nome);
	
    //chamando a função
	if (lerArquivo (nome) == 0)
	{
		printf ("\nERRO: o arquivo %s nao foi aberto!\n", nome);
	}
}
