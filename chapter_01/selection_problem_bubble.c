#include <stdio.h>

void bubble_sort(int [], int); 

int main() {
    int a[] = {33, 42, 17, 14, 23, 89, 25, 100, 99, 8};
    int a_len = sizeof(a) / sizeof(int);
    //int a_len = sizeof(a) / sizeof(a[0]);

    for (int k = 0; k < a_len; k++) {
        printf("%d ", a[k]);
    }
    printf("\n\n");

    bubble_sort(a, a_len);

    for (int k = 0; k < a_len; k++) {
        printf("%d ", a[k]);
    }
    printf("\n\n");
    
    printf("10-3 = %d\n", a[2]);
    printf("\n\n");
}

void bubble_sort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
}
