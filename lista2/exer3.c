#include <stdio.h>

int main(void) {

  float valor;
  int tipo_pag;
  float valorfinal;

  printf("Digite o valor do produto: ");
  scanf("%f", &valor);

  printf("\n Digite o tipo de pagamento: \n");

  printf("1- À vista, 2- Parcelado em 5x, 3- Parcelado em 10x \n");
  scanf("%d", &tipo_pag);

  // x = y != x == y

  if (tipo_pag == 1) {
    valorfinal = valor - (valor * 0.1);
    // printf
  } else if (tipo_pag == 2) {
    valorfinal = valor / 5;
  } else {
    valor = (valor + (valor * 0.2));
    valorfinal = valor / 10;
  }

  printf("Valor Original: %.2lf \nValor final: %.2lf", valor, valorfinal);

  return 0;
}