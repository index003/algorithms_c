#include <stdio.h>

#define Cutoff (3)

typedef int ElementType;

ElementType median3(ElementType arr[], int left, int right); 

void quick_select_sort(ElementType arr[], int k, int n); 
void q_select_sort(ElementType arr[], int k, int left, int right); 

void insertion_sort(int [], int); 
void print_array(int [], int);
void swap(int *px, int *py); 

int main() {
    int a[] = {9, 8, 1, 4, 3, 2, 5, 7, 6, 0};
    printf("before sort:\n");
    print_array(a, 10);

    printf("after sort:\n");
    quick_select_sort(a, 4, 10);
    print_array(a, 10);
}

void quick_select_sort(ElementType arr[], int k, int n) {

    q_select_sort(arr, k, 0, n - 1);
}

/* Return median of left, center, and right */
/* Order these and hide the pivot */
ElementType median3(ElementType arr[], int left, int right) {

    int center = (left + right) / 2;

    if (arr[left] > arr[center]) {
        swap(&arr[left], &arr[center]);
    }

    if (arr[left] > arr[right]) {
        swap(&arr[left], &arr[right]);
    }

    if (arr[center] > arr[right]) {
        swap(&arr[center], &arr[right]);
    }

    swap(&arr[center], &arr[right -1]); /* Hide pivot */

    return arr[right - 1];/* Return pivot */
}

void q_select_sort(ElementType arr[], int k, int left, int right) {
    
    int i, j;
    ElementType pivot;

    if (left + Cutoff <= right) {
        pivot = median3(arr, left, right);

        i = left;
        j = right - 1;

        for( ; ; ) {

            while (arr[++i] < pivot) { printf("i => arr[%d] = %d\n", i, arr[i]);}
            while (arr[--j] > pivot) {printf("j => arr[%d] = %d\n", j, arr[j]);}

            if (i < j) {
                swap(&arr[i], &arr[j]);
            } else {
                break;
            }
        }
        swap(&arr[i], &arr[right - 1]); /* Restore pivot */

        if (k <= i) {
            q_select_sort(arr, k, left, i - 1);
        } else if (k > i + 1) {
            q_select_sort(arr, k, i + 1, right);
        }
    } else { /* Do an insertion sort on the subarray */
        // arr + left 数组首元素地址移动
        insertion_sort(arr + left, right - left + 1);
    }
}

void insertion_sort(int arr[], int n) {
    
    int p;
    int i;
    int tmp;

    for (p = 1; p < n; p++) {
        tmp = arr[p];
        for (i = p; i > 0 && arr[i - 1] > tmp; i--) {
            arr[i] = arr[i - 1];
        }
        arr[i] = tmp;
    }
}

void print_array(int arr[], int len) {
    
    for (int i = 0; i < len; i++) {
        printf("array element is: %d\n", arr[i]);
    }
    printf("=====================\n");
}


void swap(int *px, int *py) {

    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}


