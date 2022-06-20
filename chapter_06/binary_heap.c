#include <stdio.h>
#include <stdlib.h>
#include "binary_heap.h"

#define Min_PQSize 5
#define Min_Data -1

struct HeapStruct {

    int capacity;
    int size;
    ElementType *elements;
};

int main() {
    
    PriorityQueue pq;
    pq = initialize_heap(20);
    insert_heap(7, pq);
    print_heap(pq);
    printf("====================\n");
    for (int i = 10; i < 20; i = i + 2) {
        insert_heap(i, pq);
    }
    print_heap(pq);
    printf("====================\n");
    insert_heap(5, pq);
    print_heap(pq);
    printf("====================\n");
    insert_heap(9, pq);
    print_heap(pq);
    printf("====================\n");
    insert_heap(6, pq);
    print_heap(pq);
    printf("====================\n");
    

}

PriorityQueue initialize_heap(int max_elements) {
    
    PriorityQueue h;

    if (max_elements < Min_PQSize) {
        printf("PriourtyQueue size is too small\n");
        return NULL;
    }

    h = malloc(sizeof(struct HeapStruct));

    if (h == NULL) {
        printf("Out of space!!!\n");
        return NULL;
    }
    
    h->elements = malloc(sizeof(ElementType) * (max_elements + 1));

    if (h->elements == NULL) {
        printf("Out of space!!!\n");
        return NULL;
    }

    h->capacity = max_elements;
    h->size = 0;
    h->elements[0] = Min_Data;

    return h;
}

void destroy_heap(PriorityQueue h) {
}

void make_empty(PriorityQueue h) {

    h->size = 0;
}

void insert_heap(ElementType x, PriorityQueue h) {

    int i;
    if (is_full(h)) {
        printf("PriorityQueue is full\n");
        exit(0);
    }

    for (i = ++h->size; h->elements[i/2] > x; i/=2) {
        h->elements[i] = h->elements[i/2];
    }

    h->elements[i] = x;
}

ElementType delete_min(PriorityQueue h) {
}

ElementType find_min(PriorityQueue h) {
}

int is_empty(PriorityQueue h) {

    return h->size == 0;
}

int is_full(PriorityQueue h) {

    return h->size == h->capacity;
}

void print_heap(PriorityQueue h) {
    
    printf("PQ Elements is: ");
    for (int i = 1; i <= h->size; i++) {
        printf("%d ", h->elements[i]);
    }
    printf("\n");
}





