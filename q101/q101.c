#include <stdio.h>
#include <string.h>
#define MAX 24

typedef struct{
        int s[MAX];
        int top;
}Stack;

Stack blocks[MAX];
int tracer[MAX];

Stack tmpStack;

char op[3];


int isFull(Stack*);
int isEmpty(Stack*);
int push(Stack*,int);
int pop(Stack*);
int clean(Stack*);

int main() {
    int i;
    
    for (i=0;i<MAX;i++) {
        blocks[i].top = 0;
    }
    
    memset(tracer,0,sizeof(int)*MAX);

    
}

int isFull(Stack *S) {
    if (S->top == MAX) {
       return 1;
    } else {
      return 0;
    }
}

int isEmpty(Stack *S) {
    if (S->top == 0) {
       return 1;
    } else {
      return 0;
    }
}

int push(Stack *S,int data) {
    if (!isFull(S)) {
       S->s[++S->top] = data;
       return 0;
    } else {
      return 1;
    }
}

int pop(Stack *S) {
    if (isEmpty(S)) {
       return 1;
    } else {
      S->top--;
      return 0;
    }
}

int clean(Stack *S) {
    S->top = 0;
    return 0;
}
