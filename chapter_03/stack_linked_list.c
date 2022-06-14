#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

Stack create_stack();

int is_empty(Stack s);
void dispose_stack(Stack s);
void make_empty(Stack s);

void push(int x, Stack s);
int top(Stack s);
void pop(Stack s);

struct Node {
    int element;
    struct Node *next;
};

int main() {
    
    int val;
    Stack s;
    // 创建一个栈
    s = create_stack();

    // 压栈
    push(5, s);
    push(2, s);

    // 显示栈中元素
    dispose_stack(s);
    printf("====================\n");

    // 查看栈顶元素
    val = top(s);
    printf("top val is : %d\n", val);
    printf("====================\n");

    // 栈顶元素出栈
    pop(s);
    val = top(s);
    printf("top val is : %d\n", val);
    printf("====================\n");

    push(6, s);
    push(7, s);
    dispose_stack(s);
    printf("====================\n");
    
    // 清空栈
    make_empty(s);
    printf("stack is empty : %d\n", is_empty(s));
    printf("====================\n");
}

Stack create_stack() {

    Stack s;
    s = malloc(sizeof(struct Node));
    if (s == NULL) {
        printf("Out of space\n");
        return NULL;
    }
    s -> next = NULL;
    return s;
}

int is_empty(Stack s) {

    return s -> next == NULL;
}
void dispose_stack(Stack s) {

    Stack tmp;
    tmp = s -> next;
    while (tmp != NULL) {
        printf("Element is : %d\n", tmp -> element);
        tmp = tmp -> next;
    }
    
}

void make_empty(Stack s) {

    if (s == NULL) {
        printf("Must use create_stack first.\n");
        return;
    } else {
        while (!is_empty) {
            pop(s);
        }
    }
}

void push(int x, Stack s) {

    Stack tmp;
    tmp = malloc(sizeof(struct Node));
    if (tmp == NULL) {
        printf("Out of space!\n");
        return;
    } else {
        tmp -> element = x;
        tmp -> next = s -> next;
        s -> next = tmp;
    }
}

int top(Stack s) {
    
    if (!is_empty(s)) {
        return s -> next -> element;
    }

    printf("empty stack\n");
    return 0;
}

void pop(Stack s) {

    Stack tmp;
    if (is_empty(s)) {
        printf("empty stack!\n");
        return;
    } 
    tmp = s -> next;
    s -> next = s -> next -> next;
    free(tmp);
    
}
