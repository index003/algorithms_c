#ifndef _BinHeap_H

typedef int ElementType;

typedef struct HeapStruct *PriorityQueue;

PriorityQueue initialize_heap(int max_elements);

void destroy_heap(PriorityQueue h);

void make_empty(PriorityQueue h);

void insert_heap(ElementType x, PriorityQueue h);

ElementType delete_min(PriorityQueue h);

ElementType find_min(PriorityQueue h);

int is_empty(PriorityQueue h);

int is_full(PriorityQueue h);

void print_heap(PriorityQueue h);

#endif  /* _BinHeap_H */

