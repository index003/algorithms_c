#include <stdio.h>
#include <stdlib.h>

#define EMPTY_TOS -1
#define MIN_STACK_SIZE 5
struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int is_empty(Stack s);
int is_full(Stack s);
Stack create_stack(int max_elements);
void dispose_stack(Stack s);
void make_empty(Stack s);
void push(ElementType x, Stack s);
ElementType top(Stack s);
void pop(Stack s);
ElementType top_and_pop(Stack s);
void print_stack(Stack s);

struct StackRecord {
    int capacity;   // 栈的容量
    int top_of_stack; // 栈顶脚标
    ElementType *arr; // 数组首元素地址
};

int main() {
    int val;
    Stack s;
    // 创建一个栈
    s = create_stack(10);

    // 压栈
    push(5, s);
    push(2, s);

    // 显示栈中元素
    print_stack(s);
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
    print_stack(s);
    printf("====================\n");
    
    // 清空栈
    make_empty(s);
    printf("stack is empty : %d\n", is_empty(s));
    printf("====================\n");

    // 释放栈
    dispose_stack(s);
}

Stack create_stack(int max_elements) {

    Stack s;
    if (max_elements < MIN_STACK_SIZE) {
        printf("stack size is to small!\n");
        return NULL;
    }

    s = malloc(sizeof(struct StackRecord));
    if (s == NULL) {
        printf("Out of space!\n");
        return NULL;
    }

    s -> arr = malloc(sizeof(ElementType) * max_elements);
    if (s -> arr == NULL) {
        printf("Out of space!\n");
        return NULL;
    }

    s -> capacity = max_elements;
    s -> top_of_stack = EMPTY_TOS;

    return s;
}

int is_empty(Stack s) {

    return s -> top_of_stack == EMPTY_TOS;
}

int is_full(Stack s) {

    return s -> capacity == s -> top_of_stack + 1;
}

void dispose_stack(Stack s) {

    if (s != NULL) {
        free(s -> arr);
        free(s);
    }
}

void make_empty(Stack s) {

    s -> top_of_stack = EMPTY_TOS;
}

void push(ElementType x, Stack s) {
    
    if (is_full(s)) {
        printf("full stack.\n");
        return;
    } else {
        s -> arr[++s -> top_of_stack] = x;
    }
}

int top(Stack s) {
    
    if (!is_empty(s)) {
        return s -> arr[s -> top_of_stack];
    }

    printf("empty stack\n");
    return 0;
}

void pop(Stack s) {

    Stack tmp;
    if (is_empty(s)) {
        printf("empty stack!\n");
        return;
    } else { 
        s -> top_of_stack--;
    }
    
}

ElementType top_and_pop(Stack s) {
    
    if(!is_empty(s)) {
        return s -> arr[s -> top_of_stack--];
    }

    printf("empty stack\n");
    return 0;
}
void print_stack(Stack s) {
    
    for (int i = 0; i < s -> top_of_stack + 1; i++) {
        printf("stack elements is : %d\n", s -> arr[i]);
    }
}


