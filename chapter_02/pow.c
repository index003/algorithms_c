#include <stdio.h>

int p_pow(int x, int n);

int main() {

    int i = p_pow(2, 8);
    printf("%d\n", i);
}

int p_pow(int x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    if (n % 2 == 0) {
        return p_pow(x * x, n / 2);
    } else {
        return p_pow(x * x, n / 2) * x;
    }
}
