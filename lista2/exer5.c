#include <stdio.h>

int main(void) {
  int cod_item;
  int quant;
  float valor;
  float total;

  printf("CÓDIGOS DOS PRODUTOS\n"); 
  printf(
      "100- Cachorro Quente, 101- Bauru simples, 102- Bauru com ovo, 103- "
      "Hambúrguer, 104- Cheeseburger, 105- Refrigerante. \n");
  printf("\nDigite o código do produto: ");
  scanf("%d", &cod_item);

  printf("\nDigite a quantidade a ser comprada: ");
  scanf("%d", &quant);

  if (cod_item == 100) {
    valor = 3.50;
  } else if (cod_item == 101) {
    valor = 4.50;
  } else if (cod_item == 102) {
    valor = 5.20;
  } else if (cod_item == 103) {
    valor = 3.00;
  } else if (cod_item == 104) {
    valor = 4.00;
  } else {
    valor = 2.50;
  }

  total = valor * quant;
  printf("\n Total = %.2lf", total);

  return 0;
}