#include <stdio.h>

int main(void){
    int peso;
    float altura;
    float imc;

    printf("Digite seu peso: \n");
    scanf("%d", &peso);
    printf("\nDigite sua altura (em metros): \n");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
    
    if (imc < 18.5){
        printf("Abaixo do peso");
    }else{
        if (imc < 25){
        printf("Peso ideal");
        } else {
         if (imc < 30){
        printf("Acima do peso");
        } else {
            if (imc < 35){
            printf("Obesidade Grau I");
            }else{
                if (imc < 40){
                printf("Obesidade Grau II");
                } else {
                    printf("Obesidade Grau III");
                }
                }
            }
            }
        }
  return 0;
}