/* Questão 06:
   Desenvolver uma função que, dados dois arquivos textos arqA 
   e arqB, crie um novo arquivo arqC, considerando que:

	- arqA e arqB contém números reais, um por linha, ordenados 
	  crescentemente e sem repetição no arquivo; 
	- arqC deve conter todos os números dos dois arquivos originais;
	- Assim como arqA e arqB, arqC também não possuirá repetições 
	  de elementos e estes deverão estar ordenados de forma 
	  crescente.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int uniao (char nomeArqA[], char nomeArqB[], char nomeArqC[])
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
				fprintf (arqC, "%.1f\n", numA);
				
				if (fscanf (arqA, "%f", &numA) == EOF)
				{
					fimA = 1;
				}
			}
			else
			{
				if (numB < numA)
				{
					fprintf (arqC, "%.1f\n", numB);
				
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
		
		//se chegou aqui, um (ou os dois) dos arquivos terminou
		//é necessário copiar os remanescentes do outro arquivo
		
		//verificar se A terminou, porém B contém elementos
		if (fimA && !fimB)
		{
			fprintf (arqC, "%.1f\n", numB);
			
			while (fscanf (arqB, "%f", &numB) != EOF)
			{
				fprintf (arqC, "%.1f\n", numB);
			}
		}

		//verificar se B terminou, porém A contém elementos
		if (fimB && !fimA)
		{
			fprintf (arqC, "%.1f\n", numA);
			
			while (fscanf (arqA, "%f", &numA) != EOF)
			{
				fprintf (arqC, "%.1f\n", numA);
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
	uniao ("teste1.txt", "teste2.txt", "uniao.txt");
}
