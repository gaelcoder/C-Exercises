#include <stdio.h>

//protótipos das funções
int escreverArquivo (char nomeArq[], int A, int B)
{
	//declaração de variáveis
	int i;
	FILE* arq;	//passo 1: criar uma variável do tipo FILE
	
	//passo 2: abrir o arquivo + associar a variável FILE* a um arquivo em disco
	arq = fopen (nomeArq, "w");  //w - write / r - read / a - append
	
	//verificar se ocorreu erro na abertura do arquivo
	if (arq == NULL)
	{
		return 0;
	}
	else
	{
		//passo 3: manipulação do arquivo
		for (i=A;i<=B;i++)
		{
			fprintf (arq, "%d\n", i);     //f - file
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
	int inf, sup;
	
	//lendo o nome do arquivo
	printf ("Nome do arquivo: ");
	fflush (stdin);
	gets (nome);
	
	//obtendo o intervalo
	printf ("Intervalo dos números: ");
	scanf ("%d %d", &inf, &sup);
	
	//chamando a função
	if (escreverArquivo (nome, inf, sup) == 0)
	{
		printf ("\nERRO: o arquivo %s nao foi aberto!\n", nome);
	}
	else
	{
		printf ("\nO arquivo %s foi criado!", nome);
	}
}
