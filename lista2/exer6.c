#include <stdio.h>

int main(void) {

  int i, a, b, c;

  printf("Digite um valor 1, 2, 3 para i: ");
  scanf("%d", &i);

  printf("\nDigite 3 números: \n");
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if (i == 1) {
    if (a > b && b > c && a > c) {
      printf("\nOrdem crescente: %d, %d, %d", c, b, a);
    } else if (b > a && b > c && a > c) {
      printf("\nOrdem crescente: %d, %d, %d", c, a, b);
    } else if (c > a && c > b && b > a) {
      printf("\nOrdem crescente: %d, %d, %d", a, b, c);
    } else if (a > b && a > c && c > b) {
      printf("\nOrdem crescente: %d, %d, %d", b, c, a);
    } else if (b > a && b > c && c > a) {
      printf("\nOrdem crescente: %d, %d, %d", a, c, b);
    } else if (c > a && a > b && c > b) {
      printf("\nOrdem crescente: %d, %d, %d", b, a, c);
    }
  }

  if (i == 2) {
    if (a < b && a < c && b < c) {
      printf("\nOrdem decrescente: %d, %d, %d", c, b, a);
    } else if (b < a && b < c && a < c) {
      printf("\nOrdem decrescente: %d, %d, %d", c, a, b);
    } else if (c < a && c < b && b < a) {
      printf("\nOrdem decrescente: %d, %d, %d", a, b, c);
    } else if (a < b && c < b && a < c) {
      printf("\nOrdem decrescente: %d, %d, %d", b, c, a);
    } else if (b < a && b < c && c < a) {
      printf("\nOrdem decrescente: %d, %d, %d", a, c, b);
    } else if (c < a && a < b && c < b) {
      printf("\nOrdem decrescente: %d, %d, %d", b, a, c);
    }
  }

  if (i == 3) {
    if (b > a && a > c && b > c) {
      printf("\nMaior no meio: %d, %d, %d", c, b, a);
    } else if (a > b && b > c && a > c) {
      printf("\nMaior no meio: %d, %d, %d", c, a, b);
    } else if (c > a && b > c && b > a) {
      printf("\nMaior no meio: %d, %d, %d", a, b, c);
    } else if (a > b && c > b && c > a) {
      printf("\nMaior no meio: %d, %d, %d", b, c, a);
    } else if (b > a && c > b && c > a) {
      printf("\nMaior no meio: %d, %d, %d", a, c, b);
    } else if (a > c && a > b && c > b) {
      printf("\nMaior no meio: %d, %d, %d", b, a, c);
    }
  }

  return 0;
}