#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void merge_sort(ElementType arr[], int n);
void m_sort(ElementType arr[], ElementType tmp_arr[], int left, int right); 
void merge(ElementType arr[], ElementType tmp_arr[], int lpos, int rpos, int right_end);
void print_array(int [], int);

int main() {

    int a[] = {9, 8, 1, 4, 3, 2, 5, 7, 6, 0};
    printf("before sort:\n");
    print_array(a, 10);

    printf("after sort:\n");
    merge_sort(a, 10);
    print_array(a, 10);
}

// 递归 分治法
void m_sort(ElementType arr[], ElementType tmp_arr[], int left, int right) {
    
    int center;

    if (left < right) {
        center = (left + right) / 2;
        m_sort(arr, tmp_arr, left, center);
        m_sort(arr, tmp_arr, center + 1, right);
        merge(arr, tmp_arr, left, center + 1, right);
    }
}

void merge_sort(ElementType arr[], int n) {
    
    ElementType *tmp_arr;

    tmp_arr = malloc(n * sizeof(ElementType));

    if (tmp_arr != NULL) {
        m_sort(arr, tmp_arr, 0, n-1);
        free(tmp_arr);
    } else {
        printf("No space for tmp array!!!\n");
    }
}

/* lpos = start of left half, rpos = start of right half */
void merge(ElementType arr[], ElementType tmp_arr[], int lpos, int rpos, int right_end) {

    int i, left_end, num_elements, tmp_pos;

    left_end = rpos - 1;
    tmp_pos = lpos;
    num_elements = right_end - lpos + 1;

    /* main loop */
    while (lpos <= left_end && rpos <= right_end) {
        if (arr[lpos] <= arr[rpos]) {
            tmp_arr[tmp_pos++] = arr[lpos++];
        } else {
            tmp_arr[tmp_pos++] = arr[rpos++];
        }
    }

    while (lpos <= left_end) { /* copy rest of first half */
        tmp_arr[tmp_pos++] = arr[lpos++];
    }

    while (rpos <= right_end) { /* copy rest of second half */
        tmp_arr[tmp_pos++] = arr[rpos++];
    }

    /* copy tmp_arr back */
    for (i = 0; i < num_elements; i++, right_end--) {
        arr[right_end] = tmp_arr[right_end];
    }
}

void print_array(int arr[], int len) {
    
    for (int i = 0; i < len; i++) {
        printf("array element is: %d\n", arr[i]);
    }
    printf("=====================\n");
}

