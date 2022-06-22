#include <stdio.h>

void shell_sort(int [], int); 
void print_array(int [], int);

int main() {

    int a[] = {9, 8, 1, 4, 3, 2, 5, 7, 6, 0};
    printf("before sort:\n");
    print_array(a, 10);

    printf("after sort:\n");
    shell_sort(a, 10);
    print_array(a, 10);

}

void shell_sort(int arr[], int n) {
    
    int i, j, increment;
    int tmp;

    for (increment = n / 2; increment > 0; increment /= 2) {
        for (i = increment; i < n; i++) {
            tmp = arr[i];
            for (j = i; j >= increment; j -= increment) {
                if (tmp < arr[j - increment]) {
                    arr[j] = arr[j - increment];
                } else {
                    break;
                }
            }
            arr[j] = tmp;
        }
        printf("===============\n");
    }
}

void print_array(int arr[], int len) {
    
    for (int i = 0; i < len; i++) {
        printf("array element is: %d\n", arr[i]);
    }
    printf("=====================\n");
}
