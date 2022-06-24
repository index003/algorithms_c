#include <stdio.h>

#define left_child(i) (2 * (i) + 1) // 宏函数

typedef int ElementType;

void percolate_down(ElementType [], int, int);
void heap_sort(ElementType [], int); 
void swap(int *, int *); 
void print_array(int [], int); 

int main() {

    int a[] = {9, 8, 1, 4, 3, 2, 5, 7, 6, 0};
    printf("before sort:\n");
    print_array(a, 10);

    printf("after sort:\n");
    heap_sort(a, 10);
    print_array(a, 10);
}

/* 下沉，构造堆 */
void percolate_down(ElementType arr[], int i, int n) {
    
    int child;
    ElementType tmp;

    for (tmp = arr[i]; left_child(i) < n; i = child) {

        child = left_child(i);

        if (child != n - 1 && arr[child + 1] > arr[child]) {
            child++;
        }

        if (tmp < arr[child]) {
            arr[i] = arr[child];
        } else {
            break;
        }
    }
    arr[i] = tmp;
}

/* 堆排序逻辑 */
void heap_sort(ElementType arr[], int n) {
    
    int i;
    for (i = n / 2; i >= 0; i--) { /* build heap */
        percolate_down(arr, i, n);
    }

    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); /* delete max */ 
        percolate_down(arr, 0, i);
    }

}

void swap(int *px, int *py) {

    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

void print_array(int arr[], int len) {
    
    for (int i = 0; i < len; i++) {
        printf("array element is: %d\n", arr[i]);
    }
    printf("=====================\n");
}
