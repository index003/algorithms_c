#include <stdio.h>
#include <stdlib.h>

struct QueueNode;
typedef struct QueueNode *Queue;

Queue create_queue(int max_elements);

int is_empty(Queue q);

void make_empty(Queue q);

void en_queue(int x, Queue q); // 入队
void de_queue(Queue q); // 出队

int front(Queue q);
int front_and_dequeue(Queue q);

void print_queue(Queue q);

struct QueueNode {
    int element;  
    Queue next;  
};

int main() {
    
    int val;
    Queue q;

    // 创建队列
    q = create_queue(5);

    // 入队
    en_queue(1, q);
    en_queue(2, q);
    en_queue(3, q);
    en_queue(4, q);
    en_queue(5, q);

    // 打印队列
    print_queue(q);
    printf("===========\n");

    // 出队
    de_queue(q);
    de_queue(q);

    print_queue(q);
    printf("===========\n");

    en_queue(9, q);

    print_queue(q);
    printf("===========\n");

    // 获取队头元素
    val = front(q);
    printf("front element is : %d\n", val);
    print_queue(q);
    printf("===========\n");

    // 获取队头元素并删除
    val = front_and_dequeue(q);
    printf("front element is : %d\n", val);
    print_queue(q);
    printf("===========\n");

    return 0;
}

Queue create_queue(int max_elements) {
    
    Queue q;
    q = malloc(sizeof(struct QueueNode));
    if (q == NULL) {
        printf("Out of space\n");
        return NULL;
    }
    
    q->next = NULL;

    return q;
}

// 判断队列是否空
int is_empty(Queue q) {
    
    return q->next == NULL;
}

// 清空队列
void make_empty(Queue q) {

    q->next = NULL;
}

void en_queue(int x, Queue q) { // 队尾入队,linked_list.firstInsert

    Queue tmp;
    tmp = malloc(sizeof(struct QueueNode));

    if (tmp == NULL) {
        printf("内存不足\n");
        return;
    }

    tmp->element = x; //给结点赋值
    tmp->next = q->next;

    q->next = tmp;

    return;
}

void de_queue(Queue q) { // 队头出队,linked_list.lastDelete
    
    Queue previous;
    Queue tmp;

    previous = q;
    tmp = q->next; 

    while (tmp != NULL) {
        if (tmp->next == NULL) {
            previous->next = NULL;
            free(tmp);
            break;
        } else {
            previous = tmp;
            tmp = tmp->next;
        }
    }
}

// 获取表头元素值
int front(Queue q) {
    
    if (is_empty(q)) {
        printf("empty queue\n");
        return 0;
    } else {
        return q->next->element;
    }
}


int front_and_dequeue(Queue q) {

    int element;
    Queue tmp;
    tmp = q->next;

    if (is_empty(q)) {
        printf("empty queue\n");
        return 0;
    } else {
        element = q->next->element;
        q->next = tmp->next;
        free(tmp);
    }
    return element;
}

// 打印队列中的元素
void print_queue(Queue q) {

    Queue tmp;
    tmp = q->next;

    while (tmp != NULL) {
        printf("node element = %d\n", tmp->element);
        tmp = tmp->next;
    }

    return;
}







