#include <stdio.h>

int main(int argc, char *argv[])
{
    
    int studentNumber = 0;
    int i, j, k; 
    
  //Recebe o numero de alunos
    printf("Entre com o numero de alunos da turma: ");
    scanf("%d", &studentNumber);
    
  //Verifica o número de alunos
    while(studentNumber <= 0 || studentNumber > 50) {
        printf("\nO numero de alunos na turma deve ser maior do que zero e menor ou igual a 50\n\n");
        printf("Entre com o numero de alunos da turma: ");
        scanf("%d", &studentNumber);
        }
    
    //declara os vetores de notas
    float p1[studentNumber], p2[studentNumber], p3[studentNumber], p4[studentNumber];
    float final[studentNumber], notas[4], varAux;
    
    //Recebe a nota dos alunos
    for (i = 0; i < studentNumber; i++) {
        
        printf("\n");
        printf("Notas aluno %d: ", i + 1); 
        scanf("%f %f %f %f", &p1[i], &p2[i], &p3[i], &p4[i]);
        
      //Verifica 
        while (p1[i] < 0 || p1[i] > 10 || p2[i] < 0 || p2[i] > 10 || p3[i] < 0 || p3[i] > 10 || p4[i] < 0 || p4[i] > 10) {
            printf("\nTodas as notas do aluno devem ser maiores ou iguais a zero e menores ou iguais a 10\n\n");
            printf("Notas aluno %d: ", i + 1); 
            scanf("%f %f %f %f", &p1[i], &p2[i], &p3[i], &p4[i]);
        }
        
        float notas[4] = {p1[i], p2[i], p3[i], p4[i]};
        for (j = 0; j < 4; j++) {
            for ( k= j + 1; k < 4; k++) {
                if (notas[j] < notas[k]) {
                    varAux = notas[j];
                    notas[j] = notas[k];
                    notas[k] = varAux;
                }
            }
        }
       
      //Verifica casos
        if(notas[2] == notas[3]) {
            
            if(notas[0] == notas[1]) {
                final[i] = ((notas[0]*2.5) + (notas[1]*2.5) + (notas[2]*2.5) + (notas[3]*2.5)) / 10;
            }
            else {
                final[i] = ((notas[0]*4) + (notas[1]*2) + (notas[2]*2) + (notas[3]*2)) / 10;
            }
        }
        
        
        
        if(notas[2] != notas[3]) {
        
            if(notas[0] == notas[1]) {
            final[i] = ((notas[0]*3) + (notas[1]*3) + (notas[2]*3) + (notas[3]*1)) / 10;
            }
            
            else if(notas[1] == notas[2]) {
                final[i] = (notas[0] + notas[1] + notas[2] + notas[3]) / 4;
            }
                else {
                final[i] = ((notas[0]*4) + (notas[1]*3) + (notas[2]*2) + notas[3]) / 10;
            }
        }
        
        printf("\n");
        printf("Media final do aluno %d: %.1f\n", i+ 1, final[i]);
    }
    
    float mediaSum = 0;
    float mediaClass = 0;
    
    for (i = 0; i < studentNumber; i++) {
        mediaSum += final[i];
    }
    
   mediaClass = mediaSum / studentNumber;
   
   
    float greatMedia = 0;
    int iGreatMedia = 0;
    
    greatMedia = final[0];
    
    for (i = 1; i < studentNumber; i++) {
        if (final[i] > greatMedia) {
            greatMedia = final[i];
            iGreatMedia = i;
        }
    }
    
    float lowMedia = 0;
    int iLowMedia = 0;
    
    lowMedia = final[0];
    
    for (i = 1; i < studentNumber; i++) {
        if (final[i] < lowMedia) {
            lowMedia = final[i];
            iLowMedia = i;
        }
    }
    
    printf("\nMedia geral da turma: %.1f ", mediaClass);
    printf("\n");
  

    printf("\nMaior media da turma: %.1f (Alunos:", greatMedia);
   
    
    for (i = 0; i < studentNumber; i++) {
        if (final[i] == greatMedia) {
            printf(" %d", i + 1);
        }
        
    }
    printf(")");
    printf("\n");
    
    printf("\nMenor media da turma: %.1f (Alunos:", lowMedia);
   
    
    for (i = 0; i < studentNumber; i++) {
        if (final[i] == lowMedia) {
            printf(" %d", i + 1);
        }
        
    }
    printf(")");
    
    return 0;
}

