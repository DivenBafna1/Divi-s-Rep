#include <stdio.h>
#include <stdlib.h>

int* stack;
int top = 0;
int max_size;

void push(int element)
{
    if (top == max_size)
    {
        printf("Stack Overflow: Cannot push element '%d'. Stack is full.\n", element);
        return;
    }
    stack[top++] = element;
    printf("Element '%d' pushed onto the stack.\n", element);
}

int pop()
{
    if (top == 0)
    {
        printf("Stack Underflow: Cannot pop element. Stack is empty.\n");
        return -1;
    }
    return stack[--top];
}

void display()
{
    if (top == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top - 1; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice, element;

    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max_size);
    stack = (int*)malloc(max_size * sizeof(int));

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
       printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1)
                {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                free(stack);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
