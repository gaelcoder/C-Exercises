/*
- arqA e arqB contém números reais, um por linha, 
	  ordenados crescentemente e sem repetição no arquivo; 
	- arqC deve conter apenas os números comuns aos dois arquivos 
	  originais;
	- Assim como arqA e arqB, arqC também não possuirá repetições 
	de elementos e estes deverão estar ordenados de forma crescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

//implementação das funções
int intersecao (char nomeArqA[], char nomeArqB[], char nomeArqC[])
{
	//declaração de variáveis
	FILE *arqA, *arqB, *arqC;
	int fimA = 0, fimB = 0;
	float numA, numB;
	
	//abrindo os três arquivos
	arqA = fopen (nomeArqA, "r");
	arqB = fopen (nomeArqB, "r");
	arqC = fopen (nomeArqC, "w");
	
	//verificando se houve erro na abertura dos arquivos
	if (!arqA || !arqB || !arqC)
	{
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 0;
	}
	else
	{
		fscanf (arqA, "%f", &numA);
		fscanf (arqB, "%f", &numB);
		
		while (!fimA && !fimB)
		{
			//comparando os elementos dos dois arquivos
			if (numA < numB)
			{
				if (fscanf (arqA, "%f", &numA) == EOF)
				{
					fimA = 1;
				}
			}
			else
			{
				if (numB < numA)
				{
					if (fscanf (arqB, "%f", &numB) == EOF)
					{
						fimB = 1;
					}
				}
				else
				{
					fprintf (arqC, "%.1f\n", numA);
				
					if (fscanf (arqA, "%f", &numA) == EOF)
					{
						fimA = 1;
					}
					
					if (fscanf (arqB, "%f", &numB) == EOF)
					{
						fimB = 1;
					}
				}
			}
		}
		
		//fechando os arquivos
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 1;
	}
}

//main
void main ()
{
	intersecao ("teste1.txt", "teste2.txt", "intersecao.txt");
}
