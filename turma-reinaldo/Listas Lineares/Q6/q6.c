#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LENGTH 100

// Definindo a estrutura de pilha para o algoritmo do Shunting Yard
typedef struct
{
    char stack[MAX_EXPR_LENGTH];
    int top;
} Stack;

// Funções para operar na pilha
void stack_init(Stack *s)
{
    s->top = -1;
}

void stack_push(Stack *s, char c)
{
    s->top++;
    s->stack[s->top] = c;
}

char stack_pop(Stack *s)
{
    if (s->top == -1)
        return '\0';
    char c = s->stack[s->top];
    s->top--;
    return c;
}

char stack_top(Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->stack[s->top];
}

int is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix)
{
    Stack stack;
    stack_init(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        if (isalnum(c))
        { // Se for operando (número ou variável)
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            stack_push(&stack, c);
        }
        else if (c == ')')
        {
            while (stack_top(&stack) != '(')
            {
                postfix[j++] = stack_pop(&stack);
            }
            stack_pop(&stack); // Remover '(' da pilha
        }
        else if (is_operator(c))
        {
            while (stack.top != -1 && precedence(stack_top(&stack)) >= precedence(c))
            {
                postfix[j++] = stack_pop(&stack);
            }
            stack_push(&stack, c);
        }
    }

    // Despejar todos os operadores restantes na pilha
    while (stack.top != -1)
    {
        postfix[j++] = stack_pop(&stack);
    }
    postfix[j] = '\0';
}

int main()
{
    int num_cases;
    char infix[MAX_EXPR_LENGTH];
    char postfix[MAX_EXPR_LENGTH];

    printf("Digite o número de casos de teste (entre 1 e 10): ");
    scanf("%d", &num_cases);
    getchar(); // Captura o newline após o scanf

    if (num_cases < 1 || num_cases > 10)
    {
        printf("Número de casos de teste inválido.\n");
        return 1;
    }

    for (int i = 0; i < num_cases; i++)
    {
        printf("Digite a expressão infixa para o caso %d: ", i + 1);
        fgets(infix, sizeof(infix), stdin);

        // Remover o newline inserido pelo fgets, se existir
        infix[strcspn(infix, "\n")] = '\0';

        // Verificar se a expressão infixa está bem-formada (simplificação: só verificar parênteses)
        int open_paren = 0, close_paren = 0;
        int valid = 1;

        for (int j = 0; infix[j] != '\0'; j++)
        {
            if (infix[j] == '(')
            {
                open_paren++;
            }
            else if (infix[j] == ')')
            {
                close_paren++;
            }
            if (close_paren > open_paren)
            {
                valid = 0;
                break;
            }
        }

        if (open_paren != close_paren)
        {
            valid = 0;
        }

        if (!valid)
        {
            printf("Expressão malformada.\n");
            continue;
        }

        // Converter para pós-fixa e imprimir
        infix_to_postfix(infix, postfix);
        printf("Expressão pós-fixa equivalente: %s\n", postfix);
    }

    return 0;
}
