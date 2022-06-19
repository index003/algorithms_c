#include <stdio.h>
#include <stdlib.h>
#include "hash_separate_chaining.h"

#define MIN_TABLE_SIZE 5


struct ListNode {
    ElementType element;
    Position next;
};

struct HashTbl {
    int table_size;
    List *the_lists;
};

int main() {
    
    Position p;
    HashTable table;

    table = initialize_table(10);

    insert_table(19, table);
    insert_table(18, table);
    insert_table(17, table);
    insert_table(9, table);
    insert_table(8, table);
    insert_table(7, table);
    insert_table(10, table);
    insert_table(11, table);
    insert_table(3, table);
    print_table(table);
}

int is_prime(int num) {   // 是否是一个素数 
    
    for (int i = 2; i * i < num +1; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int next_prime(int num) { // 返回下一个素数

    while(1 == 1) {
        if (is_prime(num)) {
            return num;
        } else {
            num++;
        }
    }
}

int hash(ElementType key, int table_size) { // 简单散列函数
    
    return key % table_size;
}

HashTable initialize_table(int table_size) {
    
    HashTable h;
    int i;

    if (table_size < MIN_TABLE_SIZE) {
        printf("Table size too small!\n");
        return NULL;
    }

    /* Allocate table */
    h = malloc(sizeof(struct HashTbl));

    if (h == NULL) {
        printf("Out of space!\n");
        return NULL;
    }

    h->table_size = next_prime(table_size);

    /* Allocate array of lists */
    h->the_lists = malloc(h->table_size * sizeof(List));

    if (h->the_lists == NULL) {
        printf("Out of space!\n");
        return NULL;
    }

    /* Allocate list header */
    for (i = 0; i < h->table_size; i++) {
        h->the_lists[i] = malloc(sizeof(struct ListNode));

        if (h->the_lists[i] == NULL) {
            printf("Out of space!\n");
            return NULL;
        } else {
            h->the_lists[i]->next == NULL;
        }
    }

    return h;
}

void destroy_table(HashTable h) {
}

Position find_element(ElementType key, HashTable h) {
    
    Position p;
    List l;

    l = h->the_lists[hash(key, h->table_size)];
    p = l->next;

    while(p != NULL && p->element != key) {
        p = p->next;
    }

    return p;
}

void insert_table(ElementType key, HashTable h) {
    
    Position pos, new_cell;
    List l;

    pos = find_element(key, h);
    if (pos == NULL) {
        new_cell = malloc(sizeof(struct ListNode));
        if (new_cell == NULL) {
            printf("Out of space!!!\n");
            return;
        } else {
            l = h->the_lists[hash(key, h->table_size)];
            new_cell->next = l->next;
            new_cell->element = key;
            l->next = new_cell;
        }
    }
}

int delete_table(ElementType key, HashTable h) {
}

void print_table(HashTable h) {
    
    Position p;
    List l;

    for (int i = 0; i < h->table_size; i++) {
        l = h->the_lists[i];
        p = l->next;
        printf("下标 %d: ", i);
        
        while (p != NULL) {
            printf("%d ", p->element);
            p = p->next;
        }
    printf("\n");
    }
}




