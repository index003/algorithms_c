#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 50

// 多项式ADT的数组实现的类型声明
typedef struct Pol{
    int coeff_array[MAX_DEGREE + 1];
    int high_power;
} * Polynomial;

void zero_polynomial(Polynomial poly); 
void add_polynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polySum);
void multi_polynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polyProd);
void print_poly(Polynomial poly);

int main() {
    // poly1 = 4x^6 + 2x^4 + 7x^2 + 9
    Polynomial poly1 = malloc(sizeof(struct Pol));
    zero_polynomial(poly1);
    poly1 -> high_power = 6;
    poly1 -> coeff_array[6] = 4;
    poly1 -> coeff_array[4] = 2;
    poly1 -> coeff_array[2] = 7;
    poly1 -> coeff_array[0] = 9;
    printf("poly1 = ");
    print_poly(poly1);

    // poly2 = 5x^7 + 3x^5 + x^3 + 9x^2
    Polynomial poly2 = malloc(sizeof(struct Pol));
    zero_polynomial(poly2);
    poly2 -> high_power = 7;
    poly2 -> coeff_array[7] = 5;
    poly2 -> coeff_array[5] = 3;
    poly2 -> coeff_array[3] = 1;
    poly2 -> coeff_array[2] = 9;
    printf("poly2 = ");
    print_poly(poly2);

    Polynomial poly_sum = malloc(sizeof(struct Pol));
    zero_polynomial(poly_sum);
    add_polynomial(poly1, poly2, poly_sum);
    printf("poly_sum = ");
    print_poly(poly_sum);

    Polynomial poly_prod = malloc(sizeof(struct Pol));
    zero_polynomial(poly_prod);
    multi_polynomial(poly1, poly2, poly_prod);
    printf("poly_prod = ");
    print_poly(poly_prod);
}

int max(int a, int b) {
    int max = a > b ? a : b;
    return max;
}

// 打印多项式
void print_poly(Polynomial poly) {
    int i, j;
    for (i = poly -> high_power; i >= 0; i--) {
        j = poly -> coeff_array[i];
        if (j == 0) {
            continue;
        } else if (j == 1) {

        } else {
            printf("%d", j);
        }
        
        if (i == 0) {

        } else if (i == 1){
            printf("x + ");
        } else {
            printf("x^%d + ", i);
        }
    }
    printf("\n");
}

// 将多项式初始化为0的过程
void zero_polynomial(Polynomial poly) {
    int i;

    for (i = 0; i <= MAX_DEGREE; i++) {
        poly -> coeff_array[i] = 0;
    }
    poly -> high_power = 0;
}

// 两个多项式相加的过程
void add_polynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polySum) {
    int i;

    zero_polynomial(polySum);
    polySum -> high_power = max(poly1 -> high_power, poly2 -> high_power);

    for (i = polySum -> high_power; i >= 0; i--) {
        polySum -> coeff_array[i] = poly1 -> coeff_array[i] + poly2 -> coeff_array[i]; 
    }
}

// 两个多项式相乘的过程
void multi_polynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polyProd) {
    int i, j;

    zero_polynomial(polyProd);
    polyProd -> high_power = poly1 -> high_power + poly2 -> high_power;

    if (polyProd -> high_power > MAX_DEGREE) {
        printf("Exceeded array size\n");
        exit(1);
    } else {
        for (i = 0; i <= poly1 -> high_power; i++) {
            for (j = 0; j<= poly2 -> high_power; j++) {
                polyProd -> coeff_array[i + j] += poly1 -> coeff_array[i] * poly2 -> coeff_array[j]; 
            }
        }
    }
}




