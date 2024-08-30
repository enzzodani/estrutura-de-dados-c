#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LENGTH 100
#define MAX_CASES 10

typedef struct
{
    char stack[MAX_EXPR_LENGTH];
    int top;
} Stack;

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
    int i;
    int j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
            postfix[j++] = ' ';
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
                postfix[j++] = ' ';
            }
            stack_pop(&stack);
        }
        else if (is_operator(c))
        {
            while (stack.top != -1 && precedence(stack_top(&stack)) >= precedence(c))
            {
                postfix[j++] = stack_pop(&stack);
                postfix[j++] = ' ';
            }
            stack_push(&stack, c);
        }
    }

    while (stack.top != -1)
    {
        postfix[j++] = stack_pop(&stack);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

int main()
{
    int num_cases;
    char infix[MAX_EXPR_LENGTH];
    char postfix[MAX_EXPR_LENGTH];
    char results[MAX_CASES][MAX_EXPR_LENGTH];
    int result_count = 0;
    int i, j, k;

    scanf("%d", &num_cases);
    getchar(); 

    if (num_cases < 1 || num_cases > MAX_CASES)
    {
        return 1;
    }

    for (i = 0; i < num_cases; i++)
    {
        fgets(infix, sizeof(infix), stdin);

        infix[strcspn(infix, "\n")] = '\0';

        if (isspace(infix[0]) || isspace(infix[strlen(infix) - 1]))
        {
            strcpy(results[result_count++], "mal-formada");
            continue;
        }

        int contains_consecutive_digits = 0;
        for (k = 0; infix[k] != '\0'; k++)
        {
            if (isdigit(infix[k]) && isdigit(infix[k + 1]))
            {
                contains_consecutive_digits = 1;
                break;
            }
        }

        if (contains_consecutive_digits)
        {
            strcpy(results[result_count++], "mal-formada");
            continue;
        }

        int contains_lowercase = 0;
        for (k = 0; k < strlen(infix); k++)
        {
            if (islower(infix[k]))
            {
                contains_lowercase = 1;
                break;
            }
        }

        if (contains_lowercase)
        {
            strcpy(results[result_count++], "mal-formada");
            continue;
        }

        int open_paren = 0, close_paren = 0;
        int valid = 1;

        for (j = 0; infix[j] != '\0'; j++)
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
            strcpy(results[result_count++], "mal-formada");
            continue;
        }

        valid = 1;
        for (j = 0; infix[j] != '\0'; j++)
        {
            if (is_operator(infix[j]))
            {
                if (j == 0 || j == strlen(infix) - 1 || !isspace(infix[j - 1]) || !isspace(infix[j + 1]))
                {
                    valid = 0;
                    break;
                }
            }
        }

        if (!valid)
        {
            strcpy(results[result_count++], "mal-formada");
            continue;
        }

        infix_to_postfix(infix, postfix);
        strcpy(results[result_count++], postfix);
    }

    for (i = 0; i < result_count; i++)
    {
        printf("%s\n", results[i]);
    }

    return 0;
}
