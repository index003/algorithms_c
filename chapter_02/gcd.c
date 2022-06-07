#include <stdio.h>

int gcd(int m, int n);

int main() {
    int i = gcd(45, 18);
    printf("%d\n", i);
}

int gcd(int m, int n) {
    
    int rem;
    while (n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }

    return m;
}
