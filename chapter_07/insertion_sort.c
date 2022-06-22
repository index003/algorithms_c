#include <stdio.h>

void insertion_sort(int [], int); 
void print_array(int [], int);

int main() {

    int a[] = {9, 8, 1, 4, 3, 2, 5, 7, 6, 0};
    printf("before sort:\n");
    print_array(a, 10);

    printf("after sort:\n");
    insertion_sort(a, 10);
    print_array(a, 10);

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
