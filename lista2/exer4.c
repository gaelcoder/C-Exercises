#include <stdio.h>

int main(void) {
  int km_viagem;
  float km_litro;
  float preco_combustivel;
  float litragem;
  float total_combustivel;

  printf("Digite quantos KMs tem o percurso: \n");
  scanf("%d", &km_viagem);

  printf("\nDigite quantos KM por litro o carro faz: \n");
  scanf("%f", &km_litro);

  printf("\nDigite o preço do combustível: \n");
  scanf("%f", &preco_combustivel);

  litragem = km_viagem / km_litro;
  total_combustivel = litragem * preco_combustivel;
    
  printf("\n O percurso requer um total de %.2lf litros de combustível, e essa quantidade custará %.2lf", litragem, total_combustivel);
  
  return 0;
}