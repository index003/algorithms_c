#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"


struct Node {
    int element;    // node value
    struct Node *next; // next node point
};

int main() {
    
    // struct Node *node;
    List node;
    // struct Node *header;
    List header;

    // 创建表头
    header = makeEmpty();

    // 判断表是否为空
    if (isEmpty(header)) {
        printf("struct Node is empty ? : Yes\n");
    } else {
        printf("struct Node is empty ? : No\n");
    }

    printf("struct Node is empty ? : %d\n", isEmpty(header));

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

    // 指定位置插入
    insert(5, header, 3); 
    printList(header);
    printf("================================");
    printf("\n");

    // 更新element为1的值为10
    update(1, 10, header);

    // 更新position为1的值为20
    updateKth(1, 20, header); 
                
    // 查找结点值为3的结点
    node = find(header, 3);
    if (node == NULL) {
        printf("not find...\n");
    } else {
        printf("find node element by element: %d\n", node->element);
    }
    printf("================================");
    printf("\n");

    // 查找表中第2个结点
    node = findKth(header, 2);
    if (node == NULL) {
        printf("not find...\n");
    } else {
        printf("find node element by position: %d\n", node->element);
    }
    printf("================================");
    printf("\n");

    // 删除结点值为3的结点
    delete(header, 3);
    printList(header);
    printf("================================");
    printf("\n");

    // 打印表中结点个数，即表的大小
    printf("struct Node size: %d\n", size(header));
    printf("================================");
    printf("\n");
}


// 创建表头
// struct Node *makeEmpty() {
List makeEmpty() {

    // struct Node *p;
    List p;
    p = malloc(sizeof(struct Node));

    if (p == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }

    p->next = NULL;

    return p;
}

// 判断表是否为空
// int isEmpty(struct Node *header) {
int isEmpty(List header) {
    return header->next == NULL;
}

// 判断是否最后一个
int isLast(List L) {
    
}

// 从表头插入
// void insertFirst(struct Node *header, int x) {
void insertFirst(List header, ElementType x) {

    // struct Node *tmp;
    List tmp;

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
// void insertLast(struct Node *header, int x) {
void insertLast(List header, ElementType x) {
    
    // struct Node *p;
    // struct Node *tmp;
    List p;
    List tmp;

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

// 指定位置插入
void insert(ElementType x, List l, ElementType position) {
    // struct Node *p;
    // struct Node *tmp;
    List tmp;
    List previous;

    if (position <= 0) {
        printf("position 不能为负数\n");
        return;
    }

    tmp = malloc(sizeof(struct Node));

    if (tmp == NULL) {
        printf("内存不足\n");
        return;
    }

    previous = findKth(l, position - 1);
    tmp->element = x; //给结点赋值
    tmp->next = previous->next;
    previous->next = tmp;

    return;
}

// 更新element为x的值为y
void update(ElementType x, ElementType y, List l) {
    
    List tmp;
    tmp = find(l, x);
    tmp->element = y;
}

// 更新position为x的值为y
void updateKth(ElementType x, ElementType y, List l) {

    List tmp;
    tmp = findKth(l, x);
    tmp->element = y;

}
// 查找x，如果没有找到，返回NULL
// struct Node *find(struct Node *header, int x) {
List find(List header, ElementType x) {
    
    // struct Node *p;
    List p;

    p = header->next;

    while (p != NULL && p->element != x) {
        p = p->next;
    }

    return p;
}

// 查找位置为position的结点,如果没有找到，返回NULL
// struct Node *findKth(struct Node *header, int position) {
List findKth(List header, int position) {
    
    int count = 1;
    // struct Node *p;
    List p;

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
// void delete(struct Node *header, int x) {
void delete(List header, int x) {
    
    // struct Node *previous; // 被删除结点的前一个结点的指针
    // struct Node *p;
    List previous; // 被删除结点的前一个结点的指针
    List p;

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
// int size(struct Node *header) {
int size(List header) {

    int count = 0;
    // struct Node *p;
    List p;

    p = header->next;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

// 
// void printList(struct Node *header) {
void printList(List header) {
    
    // struct Node *p;
    List p;
    p = header->next;

    while (p != NULL) {
        printf("printList:node element = %d\n", p->element);
        p = p->next;
    }

    return;
}


