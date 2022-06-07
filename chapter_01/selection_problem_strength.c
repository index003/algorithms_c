#include <stdio.h>

void top3_sort(int []);

int main() {
    int a[] = {33, 42, 17, 14, 23, 89, 25, 100, 99, 8};
    int a_length = sizeof(a) / sizeof(int);
    //int a_length = sizeof(a) / sizeof(a[0]);

    for (int k = 0; k < a_length; k++) {
        printf("%d ", a[k]);
    }
    printf("\n\n");
    
    top3_sort(a);

    for(int i = 3; i < a_length - 1; i++) {
        if (a[i] > a[2]) {
            a[2] = a[i];
            top3_sort(a);
        }
    }

    for (int k = 0; k < a_length; k++) {
        printf("%d ", a[k]);
    }
    printf("\n\n");
    
    printf("10-3 = %d", a[2]);
    printf("\n\n");
}

void top3_sort(int a[]) {
    for(int j = 0; j < 2; j++) {
        for (int k = 0; k < 2- j; k++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
