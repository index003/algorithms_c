#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

// 函数原型声明
// 创建表头
struct List *createList();

// 从表头插入
void insertFirst(struct List *p, int x);

// 从表尾插入
void insertLast(struct List *p, int x);

// 返回x所在数组的脚标
int find(struct List *p, int x);

// 返回position位置上的元素值
int findKth(struct List *p, int position);

// 删除第一个值匹配的结点
void delete(struct List *p, int x);

// 判断表是否为空
bool isEmpty(struct List *p);

// 表中结点个数
int size(struct List *p);

void printList(struct List *p);

struct List {
    int elements[SIZE];    // 表的元素都存储在数组里
    int length;            // 表中元素的长度（即个数），实际存储的有效元素个数
};

int main() {
    
    int index;
    int element;

    // 创建一个空表
    struct List *list = createList();

    // 判断表是否为空
    printf("List is empty?: %d\n", isEmpty(list));
    printf("================================");
    printf("\n");

    // 从表头插入
    insertFirst(list, 1);
    insertFirst(list, 2);

    printList(list);
    printf("================================");
    printf("\n");

    // 从表尾插入
    insertLast(list, 3);
    insertLast(list, 4);

    printList(list);
    printf("================================");
    printf("\n");

    // 查找结点值为3的结点
    index = find(list, 3);
    if (index == -1) {
        printf("not find...\n");
    } else {
        printf("find index element: %d\n", index);
    }
    printf("================================");
    printf("\n");

    // 查找表中第2个结点
    element = findKth(list, 2);
    printf("find element: %d\n", element);
    printf("================================");
    printf("\n");

    // 删除结点值为3的结点
    delete(list, 3);
    printList(list);
    printf("================================");
    printf("\n");

    // 打印表中结点个数，即表的大小
    printf("List size: %d\n", size(list));
    printf("================================");
    printf("\n");
}


// 创建新表
struct List *createList() {

    struct List *p;
    p = malloc(sizeof(struct List));

    p -> length = 0;

    return p;
}

// 判断表是否为空
bool isEmpty(struct List *p) {
    return p -> length == 0;
}

// 从表头插入
void insertFirst(struct List *p, int x) {
    
    int i;

    if (p -> length >= SIZE) {
        printf("表已满\n");
        return;
    }

    for (i = p -> length; i > 0; i--) {
        p -> elements[i] = p -> elements[i - 1];
    }

    p -> elements[0] = x;
    p -> length++;

    return;
}

// 从表尾插入
void insertLast(struct List *p, int x) {
    
    int len = p -> length;
    if (len >= SIZE) {
        printf("表已满\n");
        return;
    }

    p -> elements[len] = x;
    p -> length++;

    return;
}

// 查找x，如果找到，返回x对应的数组脚标，如果没有找到，返回-1
int find(struct List *p, int x) {
    
    int i;
    for (i = 0; i < p -> length; i++) {
        if (p -> elements[i] == x) {
            return i;
        }
    }

    return -1;
}

// 查找位置为position的结点,如果没有找到，返回NULL
int findKth(struct List *p, int position) {
    
    if (position <= 0) {
        printf("position 不能为负数\n");
        exit(1);
    }

    if (position > p -> length) {
        printf("position  超出表的长度\n");
        exit(1);
    }

    return p -> elements[position - 1];
}

// 删除第一个值匹配的结点
void delete(struct List *p, int x) {
    
    int i;

    for (i = 0; i < p -> length; i++) {
        if (p -> elements[i] == x) {
            for ( ; i < p -> length - 1; i++) {
                p -> elements[i] = p -> elements[i + 1];
            }

            p -> length--;
            break;
        }
    }
}

// 表中结点个数
int size(struct List *p) {

    return p -> length;
}

// 
void printList(struct List *p) {

    int i;

    for (i = 0; i < p -> length; i++) {
        printf("list element is : %d\n", p -> elements[i]);
    }
}


