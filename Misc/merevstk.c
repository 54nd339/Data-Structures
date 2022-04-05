<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int top, *arr;
    unsigned n;
}Stack;
 
Stack *create(int n){
    Stack *stack = malloc(sizeof(Stack));
    stack->n = n; stack->top = -1;
    stack->arr = (int*)malloc(stack->n * sizeof(int));
    return stack;
}
void push(Stack *stack,int x){
    if(stack->top == stack->n-1)
        printf("stack Overflow\n");
    else
        stack->arr[++stack->top] = x;
}
void add(Stack *stack){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        push(stack, in);
    }
}
void display(Stack *stack){
    if(stack->top == -1) printf("Underflow");
    for(int i=stack->top; i>=0; i--)  
        printf("%d ",stack->arr[i]);
    printf("\n");
}
int pop(Stack *stack){
    if(stack->top == -1) return INT_MIN;
    return stack->arr[stack->top--];
}

Stack *merge(Stack *stack1, Stack *stack2){
    Stack *stack = create(stack1->n+stack2->n);
    while(stack1->top>-1 && stack2->top>-1){
        push(stack, pop(stack1));
        push(stack, pop(stack2));
    }
    while(stack1->top > -1)
        push(stack, pop(stack1));
    while(stack2->top > -1)
        push(stack, pop(stack2));
    return stack;
}

void insbot(Stack *stack, int item){
    if(stack->top == -1)
        push(stack, item);
    else{
        int temp = pop(stack);
        insbot(stack, item);
        push(stack, temp);
    }
}
void reverse(Stack *stack){
    if(stack->top != -1){
        int item = pop(stack);
        reverse(stack);
        insbot(stack, item);
    }
}

int main (){
    printf("\nEnter capacity of the stack 1 : ");   
    int in; scanf("%d",&in);
    Stack *stack1 = create(in);
    add(stack1);
    printf("Stack 1 : "); display(stack1);
    
    printf("\nEnter capacity of the stack 2 : ");   
    scanf("%d",&in);
    Stack *stack2 = create(in);
    add(stack2);
    printf("Stack 2 : "); display(stack2);
    
    Stack *out = merge(stack2,stack1);
    printf("\nMerged : "); display(out);
    reverse(out);
    printf("Reversed : "); display(out);
    return 0;
=======
#include <stdio.h>
#include <stdlib.h>
struct Stack {
    int top, *arr;
    unsigned n;
};
 
struct Stack *create(int n){
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->n=n; stack->top = -1;
    stack->arr = (int*)malloc(stack->n * sizeof(int));
    return stack;
}
void push(struct Stack *stack,int x){
    if(stack->top == stack->n-1)
        printf("stack Overflow\n");
    else
        stack->arr[++stack->top]=x;
}
void add(struct Stack *stack){
    int in;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        push(stack,in);
    }
}
void display(struct Stack *stack){
    if(stack->top == -1) printf("Underflow");
    for(int i=stack->top;i>=0;i--)  
        printf("%d ",stack->arr[i]);
    printf("\n");
}
int pop(struct Stack *stack){
    if(stack->top==-1) return INT_MIN;
    return stack->arr[stack->top--];
}

struct Stack *merge(struct Stack *stack1, struct Stack *stack2){
    struct Stack *stack=create(stack1->n+stack2->n);
    while(stack1->top>-1 && stack2->top>-1){
        push(stack,pop(stack1));
        push(stack,pop(stack2));
    }
    while(stack1->top>-1)
        push(stack,pop(stack1));
    while(stack2->top>-1)
        push(stack,pop(stack2));
    return stack;
}

void insbot(struct Stack *stack, int item){
    if(stack->top == -1)
        push(stack,item);
    else{
        int temp=pop(stack);
        insbot(stack,item);
        push(stack,temp);
    }
}
void reverse(struct Stack *stack){
    if(stack->top != -1){
        int item=pop(stack);
        reverse(stack);
        insbot(stack,item);
    }
}

int main (){
    int in;
    printf("\nEnter capacity of the stack 1 : ");   
    scanf("%d",&in);
    struct Stack *stack1=create(in);
    add(stack1);
    printf("Stack 1 : "); display(stack1);
    
    printf("\nEnter capacity of the stack 2 : ");   
    scanf("%d",&in);
    struct Stack *stack2=create(in);
    add(stack2);
    printf("Stack 2 : "); display(stack2);
    
    struct Stack *out=merge(stack2,stack1);
    printf("\nMerged : "); display(out);
    reverse(out);
    printf("Reversed : "); display(out);
    return 0;
>>>>>>> c14086eac1b9db45c2ade3ab55c20ad590ceb675
}