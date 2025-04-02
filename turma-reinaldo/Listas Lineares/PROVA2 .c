#include <stdlib.h>  // Inclui a biblioteca padrão para funções de alocação de memória, como malloc()
#include <stdio.h>   // Inclui a biblioteca padrão para entrada e saída, como printf() e scanf()

// Estrutura que representa um cliente na fila
typedef struct Cliente {
    char Preferencial;          // Indica se o cliente é do grupo P (preferencial) ou N (normal)
    int senha;                  // Número da senha do cliente
    struct Cliente *proxCliente;  // Ponteiro para o próximo cliente na fila
} Cliente;

// Estrutura que representa a fila
typedef struct {
    Cliente *inicio;   // Ponteiro para o primeiro cliente na fila
    Cliente *fim;      // Ponteiro para o último cliente na fila
} Fila;

// Função para criar uma nova fila
Fila *criarFila() {
    Fila *fila = malloc(sizeof(Fila));  // Aloca memória para a fila
    if (fila == NULL) {  // Verifica se a alocação foi bem-sucedida
        printf("Alocacao falhou\n");  // Exibe uma mensagem de erro se a alocação falhar
        exit(1);  // Encerra o programa com código de erro 1 se a alocação falhar
    }

    fila->inicio = NULL;  // Inicializa o ponteiro de início como NULL (fila vazia)
    fila->fim = NULL;     // Inicializa o ponteiro de fim como NULL (fila vazia)
    return fila;  // Retorna o ponteiro para a fila criada
}

// Função para adicionar um cliente à fila
void enfileirar(Fila *fila, char grupo, int senha) {
    Cliente *novoCliente = malloc(sizeof(Cliente));  // Aloca memória para um novo cliente
    if (novoCliente == NULL) {  // Verifica se a alocação foi bem-sucedida
        printf("Alocacao falhou\n");  // Exibe uma mensagem de erro se a alocação falhar
        exit(1);  // Encerra o programa com código de erro 1 se a alocação falhar
    }
    
    novoCliente->Preferencial = grupo;  // Define o grupo do cliente (P ou N)
    novoCliente->senha = senha;         // Define a senha do cliente
    novoCliente->proxCliente = NULL;    // Inicializa o ponteiro para o próximo cliente como NULL

    if (fila->inicio == NULL) {  // Se a fila está vazia
        fila->inicio = novoCliente;  // O novo cliente é o início da fila
        fila->fim = novoCliente;     // E também é o fim da fila
    } else {  // Se a fila não está vazia
        fila->fim->proxCliente = novoCliente;  // O último cliente aponta para o novo cliente
        fila->fim = novoCliente;              // O novo cliente se torna o fim da fila
    }
}

// Função para remover e retornar um cliente da fila
Cliente *desenfileirar(Fila *fila, int numero_caixa) {
    if (fila->inicio == NULL) {  // Verifica se a fila está vazia
        printf("fila vazia\n");  // Exibe uma mensagem indicando que a fila está vazia
        return NULL;  // Retorna NULL se a fila está vazia
    }

    Cliente *clienteRemovido = NULL;  // Inicializa o ponteiro para o cliente que será removido

    // Verifica se é o caixa 1 e se há cliente preferencial na fila
    if (numero_caixa == 1) {
        Cliente *anterior = NULL;  // Para rastrear o cliente anterior ao preferencial
        clienteRemovido = fila->inicio;  // Inicia com o primeiro cliente da fila

        // Procura pelo próximo cliente preferencial na fila
        while (clienteRemovido != NULL && clienteRemovido->Preferencial != 'P') {
            anterior = clienteRemovido;  // Atualiza o cliente anterior
            clienteRemovido = clienteRemovido->proxCliente;  // Avança para o próximo cliente
        }

        // Se encontrou um cliente preferencial
        if (clienteRemovido != NULL && clienteRemovido->Preferencial == 'P') {
            if (anterior == NULL) {
                fila->inicio = clienteRemovido->proxCliente;  // Atualiza o início da fila
            } else {
                anterior->proxCliente = clienteRemovido->proxCliente;  // Remove o cliente preferencial da fila
            }

            if (fila->inicio == NULL) {  // Se a fila ficou vazia após a remoção
                fila->fim = NULL;  // Atualiza o fim da fila para NULL também
            }
            return clienteRemovido;  // Retorna o cliente preferencial removido
        }
    }

    // Se não é o caixa 1, ou se não encontrou cliente preferencial, remove o próximo cliente na fila
    clienteRemovido = fila->inicio;  // Remove o próximo cliente da fila
    fila->inicio = fila->inicio->proxCliente;  // Atualiza o início da fila
    
    if (fila->inicio == NULL) {  // Se a fila ficou vazia após a remoção
        fila->fim = NULL;  // Atualiza o fim da fila para NULL também
    }
    return clienteRemovido;  // Retorna o cliente removido (preferencial ou normal)
}

// Função para mostrar a configuração atual da fila
void mostrarFila(Fila *fila) {
    if (fila->inicio == NULL) {  // Verifica se a fila está vazia
        printf("fila vazia\n");  // Exibe uma mensagem indicando que a fila está vazia
        return;  // Retorna se a fila está vazia
    }
    
    Cliente *atual = fila->inicio;  // Inicia com o primeiro cliente da fila
    while (atual != NULL) {  // Percorre a fila até o último cliente
        printf("%c %d\n", atual->Preferencial, atual->senha);  // Imprime as informações do cliente
        atual = atual->proxCliente;  // Avança para o próximo cliente
    }
}

int main() {
    Fila *fila = criarFila();  // Cria a fila inicialmente vazia
    
    char operacao;  // Variável para armazenar a operação do usuário
    char grupo;  // Variável para armazenar o grupo do cliente (P ou N)
    int senha = 1;  // Variável para gerar a senha do cliente automaticamente
    int numero_caixa;  // Variável para armazenar o número do caixa para atendimento
    
    while (1) {  // Loop infinito para interagir com o usuário
        scanf(" %c", &operacao);  // Lê a operação desejada pelo usuário
        
        if (operacao == 'I') {  // Se a operação for 'I' (inserir cliente na fila)
            scanf(" %c", &grupo);  // Lê o grupo do cliente (P ou N)
            enfileirar(fila, grupo, senha);  // Insere o cliente na fila
            senha++;  // Incrementa a senha para o próximo cliente
        } else if (operacao == 'C') {  // Se a operação for 'C' (chamar próximo cliente para atendimento)
            scanf(" %d", &numero_caixa);  // Lê o número do caixa para atendimento
            if (fila->inicio == NULL) {  // Verifica se a fila está vazia
                printf("fila vazia\n");  // Exibe uma mensagem indicando que a fila está vazia
            } else {
                // Remove o próximo cliente da fila para o caixa específico
                Cliente *prox_cliente = desenfileirar(fila, numero_caixa);
                if (prox_cliente != NULL) {
                    // Exibe as informações do cliente removido e o número do caixa
                    printf("%c %d %d\n", prox_cliente->Preferencial, prox_cliente->senha, numero_caixa);
                    free(prox_cliente);  // Libera a memória alocada para o cliente removido
                }
            }
        } else if (operacao == 'M') {  // Se a operação for 'M' (mostrar a fila atual)
            mostrarFila(fila);  // Mostra a configuração atual da fila
        } else if (operacao == 'E') {  // Se a operação for 'E' (encerrar atendimento)
            if (fila->inicio == NULL) {  // Verifica se a fila está vazia
                printf("fim atendimento\n");  // Exibe uma mensagem indicando o fim do atendimento
                break;  // Encerra o loop
            } else {
                printf("fila ainda cheia\n");  // Exibe uma mensagem indicando que ainda há clientes na fila
            }
        } else {
            printf("Operacao invalida\n");  // Se a operação for inválida, exibe uma mensagem de erro
        }
    }
    
    // Libera a memória da fila antes de encerrar o programa
    while (fila->inicio != NULL) {  // Enquanto houver clientes na fila
        Cliente *removido = desenfileirar(fila, 0);  // Remove o próximo cliente da fila (sem priorização)
        free(removido);  // Libera a memória alocada para o cliente removido
    }
    free(fila);  // Libera a memória alocada para a estrutura da fila
    
    return 0;  // Retorna 0 para indicar que o programa encerrou com sucesso
}
