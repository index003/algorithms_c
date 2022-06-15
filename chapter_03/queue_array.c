#include <stdio.h>
#include <stdlib.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;

Queue create_queue(int max_elements);

int is_empty(Queue q);
int is_full(Queue q);

void dispose_queue(Queue q); // 释放队列内存空间

void make_empty(Queue q);

void en_queue(int x, Queue q); // 入队
void de_queue(Queue q); // 出队

int succ(int index, Queue q);  // 循环数组的脚标计算

int front(Queue q);
int front_and_dequeue(Queue q);

void print_queue(Queue q);

struct QueueRecord {
    int capacity;   // 队列容量
    int size;   // 队列有效数据的大小
    int front;  // 队列头的脚标
    int rear;   // 队列尾的脚标
    int *arr;   // 指针，指向数组首元素的地址（即数组地址）
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
    printf("===========\n");

    // 释放队列
    dispose_queue(q);

    return 0;
}

Queue create_queue(int max_elements) {
    
    Queue q;
    q = malloc(sizeof(struct QueueRecord));
    if (q == NULL) {
        printf("Out of space\n");
        return NULL;
    }
    
    q -> arr = malloc(sizeof(int) * max_elements);
    if (q -> arr == NULL) {
        printf("Out of space\n");
        return NULL;
    }

    q -> capacity = max_elements;
    make_empty(q);

    return q;
}

// 判断队列是否空
int is_empty(Queue q) {
    
    return q -> size == 0;
}

// 判读队列是否满
int is_full(Queue q) {

    return q -> size == q -> capacity;
}

void dispose_queue(Queue q) { // 释放队列内存空间

    if (q != NULL) {
        free(q -> arr);
        free(q);
    }
}

// 清空队列
void make_empty(Queue q) {

    q -> size = 0;
    q -> front = 1;
    q -> rear = 0;
}

void en_queue(int x, Queue q) { // 队尾入队

    if (is_full(q)) {
        printf("full queue!\n");
        return;
    } else {
        q -> size++;
        q -> rear = succ(q -> rear, q);
        q -> arr[q -> rear] = x;
    }
}

void de_queue(Queue q) { // 队头出队
    
    if (is_empty(q)) {
        printf("empty queue\n");
        return;
    } else {
        q -> size--;
        q -> front = succ(q -> front, q);
    }
}

int succ(int index, Queue q) {  // 循环数组的脚标计算
    index++;
    return index % q -> capacity;
}

// 获取表头元素值
int front(Queue q) {
    
    if (is_empty(q)) {
        printf("empty queue\n");
        return 0;
    } else {
        return q -> arr[q -> front];
    }
}

int front_and_dequeue(Queue q) {

    int element;

    if (is_empty(q)) {
        printf("empty queue\n");
        return 0;
    } else {
        element = q -> arr[q -> front];
        q -> size--;
        q -> front = succ(q -> front, q);
    }
    return element;
}

// 打印队列中的元素
void print_queue(Queue q) {

    int i;
    int front = q -> front;
    int rear = q -> rear;
    int size = q -> size;
    int capacity = q -> capacity;

    for (i = front; i < front + size; i++) {
        printf("queue elment is : %d\n", q -> arr[i % capacity]);
    }
}







