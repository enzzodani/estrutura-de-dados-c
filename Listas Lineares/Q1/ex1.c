#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente {
    int hora;
    int minuto;
    int tRestante;
    struct Paciente *proxPaciente;
}Paciente;

typedef struct {
    Paciente *inicio;
    Paciente *fim;
}Fila;

Fila *criarFila() {
    Fila *fila = malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("Alocacao falhou");
        return 0;
    }
    // cria a fila inicialmente vazia
    fila->inicio = NULL; 
    fila->fim = NULL;

    return fila;
}

void enfileirar(Fila *fila, int hora, int minuto, int tRes) {
    Paciente *novoPaciente = malloc(sizeof(Paciente));
    if (novoPaciente == NULL) {
        printf("Alocacao falhou");
    }

    novoPaciente->hora = hora;
    novoPaciente->minuto = minuto;
    novoPaciente->tRestante = tRes;
    novoPaciente->proxPaciente = NULL; // no momento esse é o último paciente, então não existe um ponteiro para um próximo paciente

    if (fila->inicio == NULL) {
        //Verifica se a fila está vazia, caso esteja, os ponteiros para o inicio e fim da fila serão justamente o ponteiro para esse novo paciente adicionado que por enquanto é o único da fila
        fila->inicio = novoPaciente;
        fila->fim = novoPaciente;
    }
    else { // caso a fila não esteja vazia, o próximo paciente deve ser inserido ao final da fila
        fila->fim->proxPaciente = novoPaciente; // o paciente que estava no fim da fila agora recebe um ponteiro para esse novo paciente que agora será o último da fila
        fila->fim = novoPaciente; // o ponteiro para o fim da fila é atualizado para o endereço de memória desse novo paciente

    }
}

Paciente *desenfileirar(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A fila ja esta vazia");
    }

    Paciente *pacienteRemovido = fila->inicio; // pega o primeiro paciente da fila 
    fila->inicio = fila->inicio->proxPaciente; // o segundo paciente agora se torna o primeiro da fila

    //free(pacienteRemovido); // o espaço de memória será liberado depois que o paciente for atendido

    return pacienteRemovido;
}

int qtPacientes(Fila *fila) {
    Paciente *p = fila->inicio; // pega o primeiro da fila
    int qt = 0;

    while (p != NULL) {

        qt++;
        p = p->proxPaciente;

    }

    return qt; // retorna a quantidade de pacientes presentes nessa fila
}


void normalizaHorario(int *vetor) {
    // essa função normaliza os horários para ficarem de acordo com as regras de que as consultas são feitas apenas em horários como 8h0, 8h30, 9h0, 9h30 e assim segue

    if (vetor[1] >= 1 && vetor[1] <= 30) {
        vetor[1] = 30;
    }
    else if (vetor[1] > 30) {
        vetor[0] = vetor[0] + 1;
        vetor[1] = 0;
    }
    
}

int pacientesCriticos(Fila *fila) {
    int nPacientes = qtPacientes(fila);
    int nPacientesAtendidos = 0;
    int nPacientesCriticos = 0;
    int h, m;
    int horarioAtend[2]; // [h:m]
    int tempoEspera;
    int sair = 0;

    horarioAtend[0] = fila->inicio->hora; // atribui o horário de chegada do primeiro paciente para sabermos quando será o primeiro atendimento
    horarioAtend[1] = fila->inicio->minuto;
    normalizaHorario(horarioAtend); // pega o horário do primeiro atendimento de acordo com o horário de chegada do paciente e também seguindo a regra que os atendimentos são feitos apenas em momentos como por exemplo, 8h0, 8h30, 9h0, 9h30 e assim segue

    h = horarioAtend[0]; // os laços iniciam com o horário de atendimento do primeiro paciente e assim seguem até o final da fila
    m = horarioAtend[1];

    while (h <= 19) {
        while (m < 60) {

            Paciente *p = desenfileirar(fila); // a cada iteração é chamado o primeiro da fila
            
            tempoEspera = (h - p->hora)*60 + (m - p->minuto);

            if (tempoEspera < 0){
                int aux[2];
                aux[0] = p->hora;
                aux[1] = p->minuto;
                normalizaHorario(aux);
                h = aux[0];
                m = aux[1];

                tempoEspera = (h - p->hora)*60 + (m - p->minuto);
            }

            if (tempoEspera > p->tRestante) { // caso o tempo de espera para o atendimento for maior que o tempo restante então o paciente entra em estado crítico
                nPacientesCriticos++;
            }

            if (nPacientesAtendidos+1 < nPacientes) {// pega o horário do próximo paciente até o penúltimo da fila, pois o último da fila não terá informações do próximo paciente a ele já que esse não existe 
                horarioAtend[0] = p->proxPaciente->hora;
                horarioAtend[1] = p->proxPaciente->minuto;
                normalizaHorario(horarioAtend);

                if (h >= horarioAtend[0] && m >= horarioAtend[1]) {
                    horarioAtend[1] = p->proxPaciente->minuto + 30;
                    normalizaHorario(horarioAtend);
                }
            } // a nova iteração do laço já parte do horário de atendimento do próximo paciente

            

            //printf("%dh%d  %d  %dh%d  %d   horario previsto: %dh%d\n", p->hora, p->minuto, p->tRestante, h, m, tempoEspera, horarioAtend[0], horarioAtend[1]);
            
            nPacientesAtendidos++; // mais um paciente foi atendido
            free(p); // depois de atendido esse paciente sai da fila, e consequentemente o espaço de memória e liberado

            if (nPacientesAtendidos == nPacientes) { // quando é atingido o número de pacientes presentes na fila
                sair = 1;
                break;
            }

            m+=30; // é incrementado mais 30min
        }

        h = horarioAtend[0];
        m = horarioAtend[1];
        
        if (sair) {
            break;
        }
        
    }

    return nPacientesCriticos;
}

int main() {

    Fila *fila = criarFila();

    int nPacientes;
    int h, m, c;
    int i=0;

    scanf("%d", &nPacientes);

    while (i < nPacientes) {
        scanf("%d %d %d", &h, &m, &c);
        enfileirar(fila, h, m, c);

        i++;
    }

    printf("%d", pacientesCriticos(fila));


    return 0;
}