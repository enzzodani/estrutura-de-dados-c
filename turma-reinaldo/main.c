#include <stdio.h> 
#include <stdlib.h>

// Estrutura para o nó da lista duplamente encadeada
typedef struct Empregado {
    int matricula; // matrícula "m" do funcionário
    int salario; // salário "s" do funcionário
    struct Empregado *anterior; // ponteiro para o nó anterior na lista
    struct Empregado *proximo; // ponteiro para o próximo nó na lista
} Empregado;

// Estrutura para o nó da árvore de busca binária
typedef struct NóArvore {
    int matricula; // matrícula "m" do funcionário
    Empregado *empregado; // ponteiro para o nó da lista que contém informações do empregado
    struct NóArvore *esquerda; // ponteiro para o filho da esquerda na árvore
    struct NóArvore *direita; // ponteiro para o filho da direita na árvore
} NóArvore;

// Cabeçalho da lista, inicializado como NULL
Empregado *lista_head = NULL;

// Cabeçalho da árvore, inicializado como NULL
NóArvore *arvore_raiz = NULL;

// Função para criar um novo nó da lista
Empregado* criarEmpregado(int matricula, int salario) {
    Empregado *novo = (Empregado*)malloc(sizeof(Empregado)); // Aloca memória para um novo nó
    novo->matricula = matricula; // Define a matrícula do novo empregado
    novo->salario = salario; // Define o salário do novo empregado
    novo->anterior = NULL; // Inicializa o ponteiro anterior como NULL
    novo->proximo = NULL; // Inicializa o ponteiro próximo como NULL
    return novo; // Retorna o novo nó criado
}

// Função para adicionar um empregado ao final da lista
void adicionarNaLista(int matricula, int salario) {
    Empregado *novo = criarEmpregado(matricula, salario); // Cria um novo empregado
    if (lista_head == NULL) { // Se a lista está vazia
        lista_head = novo; // Define o novo empregado como o início da lista
    } else {
        Empregado *atual = lista_head; // Inicia a partir do início da lista
        while (atual->proximo != NULL) { // Navega até o final da lista
            atual = atual->proximo;
        }
        atual->proximo = novo; // Adiciona o novo empregado ao final da lista
        novo->anterior = atual; // Define o ponteiro anterior do novo empregado
    }
}

// Função para criar um novo nó da árvore
NóArvore* criarNóArvore(int matricula, Empregado *empregado) {
    NóArvore *novo = (NóArvore*)malloc(sizeof(NóArvore)); // Aloca memória para um novo nó da árvore
    novo->matricula = matricula; // Define a matrícula do nó da árvore
    novo->empregado = empregado; // Define o ponteiro para o empregado associado
    novo->esquerda = NULL; // Inicializa o ponteiro para o filho da esquerda como NULL
    novo->direita = NULL; // Inicializa o ponteiro para o filho da direita como NULL
    return novo; // Retorna o novo nó da árvore criado
}

// Função para inserir um nó na árvore
NóArvore* inserirNaArvore(NóArvore *raiz, int matricula, Empregado *empregado) {
    if (raiz == NULL) { // Se a árvore está vazia
        return criarNóArvore(matricula, empregado); // Cria um novo nó e retorna
    }
    if (matricula < raiz->matricula) { // Se a matrícula é menor que a do nó atual
        raiz->esquerda = inserirNaArvore(raiz->esquerda, matricula, empregado); // Insere no filho da esquerda
    } else if (matricula > raiz->matricula) { // Se a matrícula é maior que a do nó atual
        raiz->direita = inserirNaArvore(raiz->direita, matricula, empregado); // Insere no filho da direita
    }
    return raiz; // Retorna a raiz da árvore
}

// Função para buscar um nó na árvore
NóArvore* buscarNaArvore(NóArvore *raiz, int matricula) {
    if (raiz == NULL || raiz->matricula == matricula) { // Se a árvore está vazia ou encontrou o nó
        return raiz; // Retorna o nó encontrado (ou NULL se não encontrado)
    }
    if (matricula < raiz->matricula) { // Se a matrícula é menor que a do nó atual
        return buscarNaArvore(raiz->esquerda, matricula); // Busca no filho da esquerda
    } else { // Se a matrícula é maior
        return buscarNaArvore(raiz->direita, matricula); // Busca no filho da direita
    }
}

// Função para encontrar o nó mínimo da árvore
NóArvore* encontrarMinimo(NóArvore *raiz) {
    while (raiz->esquerda != NULL) { // Navega para o nó mais à esquerda
        raiz = raiz->esquerda;
    }
    return raiz; // Retorna o nó mínimo
}

// Função para remover um nó da árvore
NóArvore* removerDaArvore(NóArvore *raiz, int matricula) {
    if (raiz == NULL) { // Se a árvore está vazia
        return NULL; // Retorna NULL
    }
    if (matricula < raiz->matricula) { // Se a matrícula é menor que a do nó atual
        raiz->esquerda = removerDaArvore(raiz->esquerda, matricula); // Remove do filho da esquerda
    } else if (matricula > raiz->matricula) { // Se a matrícula é maior
        raiz->direita = removerDaArvore(raiz->direita, matricula); // Remove do filho da direita
    } else { // Se encontrou o nó a ser removido
        if (raiz->esquerda == NULL) { // Se não tem filho à esquerda
            NóArvore *temp = raiz->direita; // Salva o filho à direita
            free(raiz); // Libera a memória do nó atual
            return temp; // Retorna o filho à direita
        } else if (raiz->direita == NULL) { // Se não tem filho à direita
            NóArvore *temp = raiz->esquerda; // Salva o filho à esquerda
            free(raiz); // Libera a memória do nó atual
            return temp; // Retorna o filho à esquerda
        }
        NóArvore *temp = encontrarMinimo(raiz->direita); // Encontra o nó mínimo da subárvore à direita
        raiz->matricula = temp->matricula; // Substitui a matrícula do nó atual
        raiz->empregado = temp->empregado; // Substitui o ponteiro do empregado
        raiz->direita = removerDaArvore(raiz->direita, temp->matricula); // Remove o nó mínimo da subárvore à direita
    }
    return raiz; // Retorna a raiz atualizada
}

// Função para adicionar um empregado
void incluirEmpregado(int matricula, int salario) {
    if (buscarNaArvore(arvore_raiz, matricula) != NULL) { // Se o empregado já existe na árvore
        printf("empregado repetido\n"); // Mensagem de erro
        return; // Retorna sem fazer nada
    }
    adicionarNaLista(matricula, salario); // Adiciona o empregado à lista
    Empregado *empregado = lista_head; // Inicia a partir do início da lista
    while (empregado->matricula != matricula) { // Navega até encontrar o empregado com a matrícula fornecida
        empregado = empregado->proximo;
    }
    arvore_raiz = inserirNaArvore(arvore_raiz, matricula, empregado); // Insere o empregado na árvore
    printf("empregado inserido\n"); // Mensagem de sucesso
}

// Função para excluir um empregado
void excluirEmpregado(int matricula) {
    NóArvore *Nó = buscarNaArvore(arvore_raiz, matricula); // Busca o empregado na árvore
    if (Nó == NULL) { // Se o empregado não existe na árvore
        printf("empregado inexistente\n"); // Mensagem de erro
        return; // Retorna sem fazer nada
    }
    // Remove da lista
    Empregado *empregado = Nó->empregado; // Obtém o empregado associado ao nó
    if (empregado->anterior != NULL) { // Se o empregado não é o primeiro da lista
        empregado->anterior->proximo = empregado->proximo; // Atualiza o ponteiro próximo do nó anterior
    }
    if (empregado->proximo != NULL) { // Se o empregado não é o último da lista
        empregado->proximo->anterior = empregado->anterior; // Atualiza o ponteiro anterior do próximo nó
    }
    if (empregado == lista_head) { // Se o empregado é o primeiro da lista
        lista_head = empregado->proximo; // Atualiza o início da lista
    }
    free(empregado); // Libera a memória do empregado

    // Remove da árvore
    arvore_raiz = removerDaArvore(arvore_raiz, matricula); // Remove o nó da árvore
    printf("empregado removido\n"); // Mensagem de sucesso
}

// Função para alterar o salário do empregado
void alterarSalario(int matricula, int novoSalario) {
    NóArvore *Nó = buscarNaArvore(arvore_raiz, matricula); // Busca o empregado na árvore
    if (Nó == NULL) { // Se o empregado não existe
        printf("empregado inexistente\n"); // Mensagem de erro
        return; // Retorna sem fazer nada
    }
    Empregado *empregado = Nó->empregado; // Obtém o empregado associado ao nó
    empregado->salario = novoSalario; // Atualiza o salário do empregado
    printf("empregado alterado\n"); // Mensagem de sucesso
}

// Função para consultar o salário do empregado
void consultarEmpregado(int matricula) {
    NóArvore *Nó = buscarNaArvore(arvore_raiz, matricula); // Busca o empregado na árvore
    if (Nó == NULL) { // Se o empregado não existe
        printf("empregado inexistente\n"); // Mensagem de erro
        return; // Retorna sem fazer nada
    }
    printf("%d\n", Nó->empregado->salario); // Imprime o salário do empregado
}

// Função para listar empregados em ordem de matrícula
void listarEmpregados(NóArvore *raiz) {
    if (raiz != NULL) { // Se a raiz não é NULL
        listarEmpregados(raiz->esquerda); // Lista os empregados do filho da esquerda
        printf("%d %d\n", raiz->matricula, raiz->empregado->salario); // Imprime a matrícula e o salário do empregado
        listarEmpregados(raiz->direita); // Lista os empregados do filho da direita
    }
}

// Função para listar empregados em ordem de matrícula, com verificação de lista vazia
void listarEmpregadosComVerificacao() {
    if (lista_head == NULL) { // Se a lista está vazia
        printf("nao existem empregados cadastrados\n"); // Mensagem de erro
    } else {
        listarEmpregados(arvore_raiz); // Lista os empregados da árvore
    }
}

// Função principal
int main() {
    int operacao, matricula, salario;

    while (1) { // Loop infinito para processar as operações
        scanf("%d", &operacao); // Lê a operação desejada

        switch (operacao) { // Executa a operação correspondente
            case 1: // Incluir empregado
                scanf("%d %d", &matricula, &salario); // Lê a matrícula e o salário
                incluirEmpregado(matricula, salario); // Adiciona o empregado
                break;
            case 2: // Excluir empregado
                scanf("%d", &matricula); // Lê a matrícula
                excluirEmpregado(matricula); // Remove o empregado
                break;
            case 3: // Alterar salário
                scanf("%d %d", &matricula, &salario); // Lê a matrícula e o novo salário
                alterarSalario(matricula, salario); // Altera o salário
                break;
            case 4: // Consultar empregado
                scanf("%d", &matricula); // Lê a matrícula
                consultarEmpregado(matricula); // Consulta o salário
                break;
            case 5: // Listar empregados
                listarEmpregadosComVerificacao(); // Lista os empregados com verificação de lista vazia
                break;
            case 0: // Encerrar execução
                printf("fim\n"); // Mensagem de encerramento
                return 0; // Encerra o programa
        }
    }
}
