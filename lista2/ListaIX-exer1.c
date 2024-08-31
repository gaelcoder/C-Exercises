#include <stdio.h>

//Desenvolver uma função que exiba os múltiplos de N compreendidos no intervalo 
//definido por A e B.

void quesum (int n, int a, int b){
     
     int i;
     
     for (i=a;i<=b;i++)
     {
                      if(i % n == 0){
                           
                           printf("%d ", i);
                      
                           }
     }
}

void main(){
     
     int numero, inicial, limite;
     
     printf("Digite um numero: ");
     scanf("%d", &numero);
     
     printf("Entre com os limites inicial e final do intervalo: ");
	scanf("%d", &inicial);
	scanf("%d", &limite);
	

	quesum(numero, inicial, limite);
     
 }
