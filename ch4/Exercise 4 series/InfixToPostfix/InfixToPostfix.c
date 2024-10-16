#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>  // for isdigit()
#include <string.h>

#define MAXSTACK 100
#define MAXEXPR 100

// Stack implementation
char stack[MAXSTACK];
int top = -1;

void push(char x) {
    if (top >= MAXSTACK - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // Append numbers (operands) directly to the output
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            // Push '(' onto the stack
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            // Pop until '(' is found
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        else {
            // Operator encountered
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop the remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAXEXPR], postfix[MAXEXPR];

    printf("Enter infix expression: ");
    scanf("%[^\n]", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
