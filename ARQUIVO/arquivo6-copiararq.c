//importação de bibliotecas
#include <stdio.h>

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
	char nomeOrigem[30], nomeDestino[30];
	
	//lendo os nomes dos arquivos
	printf ("Nome do arquivo de origem: ");
	fflush (stdin);
	gets (nomeOrigem);
	
	printf ("Nome do arquivo de destino: ");
	fflush (stdin);
	gets (nomeDestino);
	
    //chamando a função
	if (copiarArquivo (nomeDestino, nomeOrigem) == 0)
	{
		printf ("\nErro na abertura dos arquivos!\n");
	}
	else
	{
		printf ("\nCopia realizada com sucesso!\n");
	}
}
