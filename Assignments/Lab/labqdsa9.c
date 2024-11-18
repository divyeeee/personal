#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For isdigit()
#include <string.h> // For string handling

#define MAX 100  // Maximum size for stack

// Stack structure using an array
int stack[MAX];
int top = -1;

// 1. Stack operations: PUSH, POP, PEEP, DISPLAY
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int peep() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top];
}

// 2. Convert Infix to Postfix
int precedence(char operator) {
    switch (operator) {
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

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

void convert_infix_postfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char temp_stack[MAX];
    int temp_top = -1;
    
    while (infix[i] != '\0') {// terminates when the null character is encountered
        char symbol = infix[i];
        
        if (isalnum(symbol)) {
            postfix[j++] = symbol;  // Operand
        }
        else if (symbol == '(') {
            temp_stack[++temp_top] = symbol;  // Left parenthesis
        }
        else if (symbol == ')') {
            while (temp_stack[temp_top] != '(') {
                postfix[j++] = temp_stack[temp_top--];  // Pop until '('
            }
            temp_top--;  // Remove '(' from the stack
        }
        else if (isOperator(symbol)) {
            while (temp_top != -1 && precedence(temp_stack[temp_top]) >= precedence(symbol)) {
                postfix[j++] = temp_stack[temp_top--];  // Pop higher precedence operators
            }
            temp_stack[++temp_top] = symbol;  // Push current operator
        }
        i++;
    }
    
    // Pop remaining operators from the stack
    while (temp_top != -1) {
        postfix[j++] = temp_stack[temp_top--];
    }
    
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// 3. Evaluate Postfix Expression
int eval_postfix(char postfix[]) {
    int i = 0;
    while (postfix[i] != '\0') {
        char symbol = postfix[i];
        
        if (isdigit(symbol)) {
            push(symbol - '0');  // Convert char to integer and push it to stack
        }
        else if (isOperator(symbol)) {
            int val2 = pop();
            int val1 = pop();
            switch (symbol) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
            }
        }
        i++;
    }
    return pop();  // Final result of postfix evaluation
}

// Main function to test the code
int main() {
    int choice, value;
    char infix[MAX], postfix[MAX];
    
    do {
        printf("\nMenu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. DISPLAY\n");
        printf("5. Convert Infix to Postfix\n");
        printf("6. Evaluate Postfix\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
                
            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
                
            case 3:
                value = peep();
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                convert_infix_postfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;
                
            case 6:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                value = eval_postfix(postfix);
                printf("Result of postfix evaluation: %d\n", value);
                break;
                
            case 7:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);
    
    return 0;
}
