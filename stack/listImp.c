#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* st,int item) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->val = item;
    newNode->next = st->top;
    st->top = newNode;

    printf("Pushed element: %d\n",st->top->val);
}

void pop(struct Stack* st) {
    if(st->top == NULL) {
        printf("Stack overflow !\n");
        return;
    }
    struct Node* node = st->top;
    st->top = st->top->next;
    printf("Popped element: %d\n",node->val);
    free(node);
}

void top(struct Stack* st) {
    if(st->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n",st->top->val);
}

int main() {
    struct Stack* st = (struct Stack*) malloc(sizeof(struct Stack));
    st->top = NULL;

    push(st,1);
    push(st,2);
    push(st,3);
    top(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    top(st);

    return 0;
}