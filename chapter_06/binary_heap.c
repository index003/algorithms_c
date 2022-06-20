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
    int min;

    pq = initialize_heap(20);
    insert_heap(7, pq);
    min = find_min(pq);
    print_heap(pq);
    printf("min = %d\n", min);
    printf("====================\n");

    for (int i = 10; i < 20; i = i + 2) {
        insert_heap(i, pq);
    }
    delete_min(pq);

    min = find_min(pq);
    print_heap(pq);
    printf("min = %d\n", min);
    printf("====================\n");

    insert_heap(5, pq);
    min = find_min(pq);
    print_heap(pq);
    printf("min = %d\n", min);
    printf("====================\n");

    insert_heap(9, pq);
    print_heap(pq);
    min = find_min(pq);
    printf("min = %d\n", min);
    printf("====================\n");

    insert_heap(6, pq);
    print_heap(pq);
    min = find_min(pq);
    printf("min = %d\n", min);
    printf("====================\n");

    make_empty(pq);    
    print_heap(pq);
    min = find_min(pq);
    printf("min = %d\n", min);
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
    
    int i, child;
    ElementType min_element, last_element;

    if (is_empty(h)) {
        printf("Heap is empty!!!\n");
        return h->elements[0];
    } 

    min_element = h->elements[1];
    last_element = h->elements[h->size--];

    for (i = 1; i * 2 <= h->size; i = child) {
        child = i * 2;

        if (child != h->size && h->elements[child + 1] < h->elements[child]) {
            child++;
        }

        if (last_element > h->elements[child]) {
            h->elements[i] = h->elements[child];
        } else {
            break;
        }
    }

    h->elements[i] = last_element;

    return min_element;
}

ElementType find_min(PriorityQueue h) {
    
    if (is_empty(h)) {
        printf("Heap is empty!!!\n");
        return 0;
    } else {
        return h->elements[1];
    }
}

int is_empty(PriorityQueue h) {

    return h->size == 0;
}

int is_full(PriorityQueue h) {

    return h->size == h->capacity;
}

void print_heap(PriorityQueue h) {

    if (is_empty(h)) {
        printf("The heap is empty!!!\n");
        exit(0);
    } else {
        printf("PQ Elements is: ");
        for (int i = 1; i <= h->size; i++) {
            printf("%d ", h->elements[i]);
        }
        printf("\n");
    }
}


