#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 函数原型声明
// 创建表头
struct Node *createHeaderNode();

// 从表头插入
void insertFirst(struct Node *header, int x);

// 从表尾插入
void insertLast(struct Node *header, int x);

// 查找x，如果没有找到，返回NULL
struct Node *find(struct Node *header, int x);

// 查找位置为position的结点,如果没有找到，返回NULL
struct Node *findKth(struct Node *header, int position);

// 删除第一个值匹配的结点
void delete(struct Node *header, int x);

// 判断表是否为空
bool isEmpty(struct Node *header);

// 表中结点个数
int size(struct Node *header);

void printList(struct Node *header);

struct Node {
    int element;    // node value
    struct Node *next; // next node point
};

int main() {
    
    struct Node *node;
    struct Node *header;

    // 创建表头
    header = createHeaderNode();

    // 判断表是否为空
    printf("List is empty?: %d\n", isEmpty(header));
    printf("================================");
    printf("\n");

    // 从表头插入
    insertFirst(header, 1);
    insertFirst(header, 2);

    printList(header);
    printf("================================");
    printf("\n");

    // 从表尾插入
    insertLast(header, 3);
    insertLast(header, 4);

    printList(header);
    printf("================================");
    printf("\n");

    // 查找结点值为3的结点
    node = find(header, 3);
    if (node == NULL) {
        printf("not find...\n");
    } else {
        printf("find node element: %d\n", node->element);
    }
    printf("================================");
    printf("\n");

    // 查找表中第2个结点
    node = findKth(header, 2);
    if (node == NULL) {
        printf("not find...\n");
    } else {
        printf("find node element: %d\n", node->element);
    }
    printf("================================");
    printf("\n");

    // 删除结点值为3的结点
    delete(header, 3);
    printList(header);
    printf("================================");
    printf("\n");

    // 打印表中结点个数，即表的大小
    printf("List size: %d\n", size(header));
    printf("================================");
    printf("\n");
}


// 创建表头
struct Node *createHeaderNode() {

    struct Node *p;
    p = malloc(sizeof(struct Node));

    if (p == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }

    p->next = NULL;

    return p;
}

// 判断表是否为空
bool isEmpty(struct Node *header) {
    return header->next == NULL;
}

// 从表头插入
void insertFirst(struct Node *header, int x) {

    struct Node *tmp;

    tmp = malloc(sizeof(struct Node));

    if (tmp == NULL) {
        printf("内存不足\n");
        return;
    }

    tmp->element = x; //给结点赋值
    tmp->next = header->next;

    header->next = tmp;

    return;
}

// 从表尾插入
void insertLast(struct Node *header, int x) {
    
    struct Node *p;
    struct Node *tmp;

    tmp = malloc(sizeof(struct Node));

    if (tmp == NULL) {
        printf("内存不足\n");
        return;
    }

    tmp->element = x; //给结点赋值
    tmp->next = NULL;

    p = header;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = tmp;

    return;
}

// 查找x，如果没有找到，返回NULL
struct Node *find(struct Node *header, int x) {
    
    struct Node *p;

    p = header->next;

    while (p != NULL && p->element != x) {
        p = p->next;
    }

    return p;
}

// 查找位置为position的结点,如果没有找到，返回NULL
struct Node *findKth(struct Node *header, int position) {
    
    int count = 1;
    struct Node *p;

    if (position <= 0) {
        printf("position 不能为负数\n");
        return NULL;
    }

    p = header->next;

    while (p != NULL) {
        if (count == position) {
            return p;
        }

        p = p->next;
        count++;
    }

    return NULL;
}

// 删除第一个值匹配的结点
void delete(struct Node *header, int x) {
    
    struct Node *previous; // 被删除结点的前一个结点的指针
    struct Node *p;

    previous = header;
    p = header->next;

    while (p != NULL) {
        if (p->element == x) {
            previous->next = p->next;
            free(p);
            break;
        } else {
            previous = p;
            p = p->next;
        }
    }
    return;
}

// 表中结点个数
int size(struct Node *header) {

    int count = 0;
    struct Node *p;

    p = header->next;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

// 
void printList(struct Node *header) {
    
    struct Node *p;
    p = header->next;

    while (p != NULL) {
        printf("node element = %d\n", p->element);
        p = p->next;
    }

    return;
}


