#include <stdio.h>

int main() {

    int numeroAlunos = 0; // variavel que recebe a quantidade de alunos, será usada como tamanho de vetor
    int i, j, k; // Variaveis utilizadas dentro do loop for, j e k serão utilizadas em específico no algoritmo de ordenamento
    
    printf("Entre com o numero de alunos da turma: ");
    scanf("%d", &numeroAlunos); // atribuiçao de valor ao numeroAlunos
    
    
    /* O while será utilizado para o tratamento de erro na entrada de dados, enquanto a condição nao for satisfeita o loop de registro continua
    até que o mesmo seja válido! */
    while(numeroAlunos <= 0 || numeroAlunos > 50) {
        printf("\nO numero de alunos na turma deve ser maior do que zero e menor ou igual a 50\n\n");
        printf("Entre com o numero de alunos da turma: ");
        scanf("%d", &numeroAlunos);
        }
    
    /* Cada nota será um vetor estabelecido pela quantidade de alunos na turmma, ou seja, o aluno 1 terá a nota primeiraNota[0] por exemplo. */
    float primeiraNota[numeroAlunos], segundaNota[numeroAlunos], terceiraNota[numeroAlunos], quartaNota[numeroAlunos];
    
    /* A média final seguirá a mesma base que a nota dos alunos, também será atribuído uma variavel extra notas[4] para obter os valores das notas
    já ordenadas, a varAux participa no loop de ordenamento. */
    float mediaFinal[numeroAlunos], notas[4], varAux;
    
    /* o loop geral do programa, a princípio ele recebe as entradas e atribui aos vetores, formando assim, as 4 notas de cada aluno. O loop while
    é novamente utilizado para tratamento de erro na entrada de dados, enquanto as notas forem inválidas o valor não é atribuído. */
    for (i = 0; i < numeroAlunos; i++) {
        
        printf("\n");
        printf("Notas aluno %d: ", i + 1); 
        scanf("%f %f %f %f", &primeiraNota[i], &segundaNota[i], &terceiraNota[i], &quartaNota[i]);
        
        while (primeiraNota[i] < 0 || primeiraNota[i] > 10 || segundaNota[i] < 0 || segundaNota[i] > 10 || terceiraNota[i] < 0 || terceiraNota[i] > 10 || quartaNota[i] < 0 || quartaNota[i] > 10) {
            printf("\nTodas as notas do aluno devem ser maiores ou iguais a zero e menores ou iguais a 10\n\n");
            printf("Notas aluno %d: ", i + 1); 
            scanf("%f %f %f %f", &primeiraNota[i], &segundaNota[i], &terceiraNota[i], &quartaNota[i]);
        }
        
        
        /* Após o preenchimento do vetor, este se encontra desornado, para facilitar a lógica seguinte será implementado um algoritmo de ordenamento
        em ordem decrescente. (Ex: 10 2 5 1 --->  10 5 2 1) */
        float notas[4] = {primeiraNota[i], segundaNota[i], terceiraNota[i], quartaNota[i]};
        for (j = 0; j < 4; j++) {
            for ( k= j + 1; k < 4; k++) {
                if (notas[j] < notas[k]) {
                    varAux = notas[j];
                    notas[j] = notas[k];
                    notas[k] = varAux;
                }
            }
        }
       
        /* A lógica do programa consiste em um diagrama de árvore, dada as seguintes condições:
        
        a --> 3ª nota = 4ª nota
        b --> 1ª nota = 2ª nota
        c --> 2ª nota = 3ª nota (irrelevante para os 3 primeiros casos)!
        
        Se 'a' for V e 'b' for V, teremos o caso 2 - onde não é possível determinar maior nota nem menor, desse modo os pesos serão: 2.5*(todas notas)
        Se 'a' for V e 'b' for F, teremos o caso 3 - onde é possível determinar apenas a MAIOR nota, desse modo, os pesos serão 4*(Maior nota) e 2*(demais notas)
        Se 'a' for F e 'b' for V, teremos o caso 4 - onde é possível determinar apenas a MENOR nota, desse modo, os pesos serão 1*(Menor nota) e 3*(demais notas)
        Se 'a' for F e 'b' for F, teremos 2 possíveis casos:
            |  Se 'c' for V, teremos o caso 5 - onde temos MENOR e MAIOR nota e notas do meio distintas, foi aplicada media simples.
            |  Se 'c' for F, teremos o caso 1 - onde todas notas sao distintas, desse modo, os pesos serão, 4*(Maior nota), 3*(2ª Maior nota), 2*(3ª Maior nota) e 1*(Menor nota)
        */
        if(notas[2] == notas[3]) {
            
            if(notas[0] == notas[1]) {
                mediaFinal[i] = ((notas[0]*2.5) + (notas[1]*2.5) + (notas[2]*2.5) + (notas[3]*2.5)) / 10;
            }
            else {
                mediaFinal[i] = ((notas[0]*4) + (notas[1]*2) + (notas[2]*2) + (notas[3]*2)) / 10;
            }
        }
        
        if(notas[2] != notas[3]) {
        
            if(notas[0] == notas[1]) {
            mediaFinal[i] = ((notas[0]*3) + (notas[1]*3) + (notas[2]*3) + (notas[3]*1)) / 10;
            }
            
            else if(notas[1] == notas[2]) {
                mediaFinal[i] = (notas[0] + notas[1] + notas[2] + notas[3]) / 4;
            }
                else {
                mediaFinal[i] = ((notas[0]*4) + (notas[1]*3) + (notas[2]*2) + notas[3]) / 10;
            }
        }
        
        
        /* ainda no loop for será impressa a média de cada aluno antes do reset do loop*/
        printf("\n");
        printf("Media final do aluno %d: %.1f\n", i+ 1, mediaFinal[i]);
    }
    
    
    /* As variaveis seguintes participam do calculo da média relacionada a turma. */
    float somatoriaMedias = 0;
    float mediaTurma = 0;
    
    /* somatoriaMedias recebe e armazena o valor da media de cada aluno */
    for (i = 0; i < numeroAlunos; i++) {
        somatoriaMedias += mediaFinal[i];
    }
    
    /* Ao fim do processo anterior, dividiremos a somatoria de todas as medias pelo numero de alunos, obtendo a media da turma */
    mediaTurma = somatoriaMedias / numeroAlunos;
   
    /* A variavel seguintes serão utilizadas para descobrir qual aluno obteve a maior média. */
    float maiorMedia = 0;
    
    maiorMedia = mediaFinal[0]; // a princípio, a maior media será a do 1º aluno.
    
    /* Nesse loop, toda vez que for encontrada uma média maior que a do 1º aluno, a variável maiorMedia guardará esse novo valor. */
    for (i = 1; i < numeroAlunos; i++) {
        if (mediaFinal[i] > maiorMedia) {
            maiorMedia = mediaFinal[i];
        }
    }
    
    /* A lógica aplicada anteriormente se repete. Todavia, dessa vez buscamos a MENOR media. */
    float menorMedia = 0;

    menorMedia = mediaFinal[0];
    
    for (i = 1; i < numeroAlunos; i++) {
        if (mediaFinal[i] < menorMedia) {
            menorMedia = mediaFinal[i];
        }
    }
    
    printf("\nMedia geral da turma: %.1f ", mediaTurma); // Impressão da media da turma 
    printf("\n");
  
    /* Impressão do resultado final, imprimindo a maior media da turma juntamente com os alunos que a obtiveram. */
    printf("\nMaior media da turma: %.1f (Alunos:", maiorMedia);
   
    /* Esse loop é responsável por buscar o indíce do aluno que obteve a maior media, por exemplo: se o aluno 1 obteve a maior media, o valor de sua nota estará na posição 0 do vetor
    por isso será imprimido, i+1 */
    for (i = 0; i < numeroAlunos; i++) {
        if (mediaFinal[i] == maiorMedia) {
            printf(" %d", i + 1);
        }
        
    }
    printf(")");
    printf("\n");
    
    printf("\nMenor media da turma: %.1f (Alunos:", menorMedia);
   
    
    /* A mesma lógica do loop anterior, só que para a menor media. */
    for (i = 0; i < numeroAlunos; i++) {
        if (mediaFinal[i] == menorMedia) {
            printf(" %d", i + 1);
        }
        
    }
    printf(")");
    
    return 0;
}
