#include <stdio.h>

int max_subsequence_sum1(int a[], int len);
int max_subsequence_sum2(int a[], int len);
int max_subsequence_sum3(int a[], int len);
int max_subsequence_sum4(int a[], int len);

int main() {
    int a[] = {4, -3, 5, -2, -1, 2, 6, -2};

    int max_sum1 = max_subsequence_sum1(a, 8);
    printf("%d\n", max_sum1);

    int max_sum2 = max_subsequence_sum2(a, 8);
    printf("%d\n", max_sum2);
    
    int max_sum3 = max_subsequence_sum3(a, 8);
    printf("%d\n", max_sum3);

    int max_sum4 = max_subsequence_sum4(a, 8);
    printf("%d\n", max_sum4);
}


int max_subsequence_sum1(int a[], int len) {

    int this_sum, max_sum;
    max_sum = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            this_sum = 0;
            for (int k = i; k <= j; k++) {
                this_sum += a[k];
            }
            if (this_sum > max_sum) {
                max_sum = this_sum;
            }
        }
    }
    return max_sum;
}

int max_subsequence_sum2(int a[], int len) {

    int this_sum, max_sum;
    max_sum = 0;
    for (int i = 0; i < len; i++) {
        this_sum = 0;
        for (int j = i; j < len; j++) {
            this_sum += a[j];

            if (this_sum > max_sum) {
                max_sum = this_sum;
            }

        }
    }
    return max_sum;
}

int max_sub_sum(int [], int, int);
int max_subsequence_sum3(int a[], int len) {
    return max_sub_sum(a, 0, len - 1);
}

int max3(int, int, int);
int max_sub_sum(int a[], int left, int right) {

    int max_left_sum, max_right_sum;
    int max_left_border_sum, max_right_border_sum;
    int left_border_sum, right_border_sum;
    int center, i;

    if (left == right) {
        if(a[left] > 0) {
            return a[left];
        } else {
            return 0;
        }
    }

    center = (left + right) / 2;

    max_left_sum = max_sub_sum(a, left, center);
    max_right_sum = max_sub_sum(a, center+1, right);

    max_left_border_sum = 0;
    left_border_sum = 0;
    
    for (i = center; i >= left; i--) {
        left_border_sum += a[i];
        if (left_border_sum > max_left_border_sum) {
            max_left_border_sum = left_border_sum;
        }
    }

    max_right_border_sum = 0;
    right_border_sum = 0;

    for (i = center + 1; i <= right; i++) {
        right_border_sum += a[i];
        if (right_border_sum > max_right_border_sum) {
            max_right_border_sum = right_border_sum;
        }
    }

    return max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);

}

int max3(int a, int b, int c) { 
    int max;
    max = a > b ? a : b;
    max = max > c ? max : c;
    return max;
}

int max_subsequence_sum4(int a[], int len) {

    int this_sum, max_sum;
    this_sum = 0;
    max_sum = 0;
    for (int i = 0; i < len; i++) {
        this_sum += a[i];
        if (this_sum > max_sum) {
            max_sum = this_sum;
        } else if (this_sum < 0) {
            this_sum = 0;
        }
    }
    return max_sum;
}















