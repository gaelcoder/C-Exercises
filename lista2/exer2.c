#include <stdio.h>

int main(void) {
  //peso da pessoa na terra
  float peso;
  // numero do planeta
  int planeta;

  float gravidade;
  
  printf("\n Digite seu peso: \n");
  
  scanf("%f", &peso);
  
  printf("Digite o número de um planeta: \n");
  
  printf("\n1- Mercurio, 2- Venus, 3- Marte, 4- Jupiter, 5- Saturno, 6- Urano: ");
  scanf("%d", &planeta);
  if (planeta == 1) {
    gravidade = 0.37;
  } else if (planeta == 2) {
    gravidade = 0.88;
  } else if (planeta == 3) {
    gravidade = 0.38;
  } else if (planeta == 4) {
    gravidade = 2.64;
  } else if (planeta == 5) {
    gravidade = 1.15;
  } else if (planeta == 6){
    gravidade = 1.17;
  }
  peso = (peso/10) * gravidade;
  printf("Seu peso no planeta escolhido é de %.2lf KGs", peso);
  //.....
  
  return 0;
}