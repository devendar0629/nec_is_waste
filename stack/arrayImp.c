#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void push(struct Stack* st, int val) {
    if(st->top == MAX_SIZE - 1) {
        printf("Stack overflow !\n");
        return;
    }
    printf("Pushed element: %d\n",val);
    st->top++;
    st->data[st->top] = val;
}

void pop(struct Stack* st) {
    if(st->top == -1) {
        printf("Stack underflow !\n");
        return;
    }
    printf("Popped element: %d\n",st->data[st->top]);
    st->top = st->top - 1;
}

void top(struct Stack* st) {
    if(st->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n",st->data[st->top]);
}

int main() {
    struct Stack* st = (struct Stack*) malloc(sizeof(struct Stack));
    st->top = -1;

    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    top(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    top(st);

    return 0;
}