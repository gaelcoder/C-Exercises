//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int i;
	FILE* arq;	//passo 1: criar uma variável do tipo FILE
	
	//passo 2: abrir o arquivo + associar a variável FILE* a um arquivo em disco
	arq = fopen ("teste.txt", "w");  //w - write / r - read / a - append
	
	//verificar se ocorreu erro na abertura do arquivo
	if (arq == NULL)
	{
		printf ("\nERRO: arquivo nao foi aberto!\n");
	}
	else
	{
		//passo 3: manipulação do arquivo
		for (i=1;i<=1000;i++)
		{
			fprintf (arq, "%d\n", i);     //f - file
		}
		
		//passo 4: fechar o arquivo
		fclose (arq);
	}
}