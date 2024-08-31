#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int i, n;
	
	//obtendo o valor de 'n'
	printf ("Entre com um numero: ");
	scanf ("%d", &n);
	
	for (i=2;i<=n;i+=2)
	{
		printf ("%d ", i);
	}
}