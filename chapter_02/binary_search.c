#include <stdio.h>

int binary_search(int [], int, int); 

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = binary_search(a, 18, 10);
    printf("%d\n", i);
}

int binary_search(int a[], int x, int len) {
    int low, mid, high;
    low = 0;
    high = len - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] < x) {
            low = mid + 1;
        } else if (a[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
