#include <stdio.h>

int main(){
   
    int ano = 0;
    int mes = 0;
    int quantidadeDias = 0;
    int Contador;
    int maiorTemperatura = -101;
    float somaTemperatura = 0;
   
    do {
        printf("Entre com o ano da medicao das temperaturas: ");
        scanf("%d", &ano);
        printf("\n");
   
        if(ano <= 2000 || ano > 2024){
            printf("Ano deve ser maior ou igual a 2000 e menor ou igual a 2024\n\n");
        }
    } while(ano <= 2000 || ano > 2024);
       
    do {
        printf("Entre com o mes da medicao das temperaturas: ");
        scanf("%d", &mes);
        printf("\n");
   
        if(mes < 1 || mes > 12){
            printf("Mes deve ser maior do que zero e menor ou igual a 12\n\n");
        }
    } while(mes < 1 || mes > 12);
   
    switch(mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            quantidadeDias = 31;
            break;
           
        case 4:
        case 6:
        case 9:
        case 11:
            quantidadeDias = 30;
            break;
           
        case 2:
            if ((ano % 4) == 0) {
                quantidadeDias = 29;
            } else {
                quantidadeDias = 28;
            }
            break;
    }
   
    int temperaturas[quantidadeDias];
   
    printf("Temperaturas medidas (em graus Celsius):\n\n");
   
    for(Contador = 0; Contador < quantidadeDias; Contador++){
        do {
            printf("Dia %d: ", (Contador + 1));
            scanf("%d", &temperaturas[Contador]);
            printf("\n");
           
            if(temperaturas[Contador] > 100 || temperaturas[Contador] < -100){
                printf("Temperatura deve ser maior ou igual a -100 graus e menor ou igual a 100 graus\n\n");
            }
           
        } while(temperaturas[Contador] > 100 || temperaturas[Contador] < -100);
           
        if(temperaturas[Contador] > maiorTemperatura){
            maiorTemperatura = temperaturas[Contador];
        }
           
        somaTemperatura = somaTemperatura + temperaturas[Contador];
    }
   
    printf("A maior temperatura maxima do mes foi de %d e aconteceu nos dias:", maiorTemperatura);
   
    for(Contador = 0; Contador < quantidadeDias; Contador++){
        if(temperaturas[Contador] == maiorTemperatura){
            printf(" %d", (Contador + 1));
        }
    }
   
    printf("\n\n");
    printf("A temperatura maxima media no mes foi de: %.1f graus Celsius", (somaTemperatura/quantidadeDias));

    return 0;
}
