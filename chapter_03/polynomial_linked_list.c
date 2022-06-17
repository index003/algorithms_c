#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;

Polynomial create_empty_polynomial();
void add_term(Polynomial poly, int coeff, int power);
void print_polynomial(Polynomial poly);
void add_polynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_sum); 
void mutli_polynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_prod); 
int max_poly_high_power(Polynomial poly); 
int max_value(int a, int b);

struct Node {
    int coeff;
    int high_power;
    struct Node *next;
};

int main() {

    Polynomial poly1;
    Polynomial poly2;
    Polynomial poly_sum;
    poly1 = create_empty_polynomial();
    poly2 = create_empty_polynomial();
    poly_sum = create_empty_polynomial();

    add_term(poly1, 3, 3);
    add_term(poly1, 1, 2);
    add_term(poly1, 3, 1);
    add_term(poly1, 3, 0);
    print_polynomial(poly1);
    printf("=============\n");
    
    add_term(poly2, 3, 3);
    add_term(poly2, 1, 2);
    add_term(poly2, 3, 1);
    add_term(poly2, 3, 0);
    print_polynomial(poly2);
    printf("=============\n");
    
    add_polynomial(poly_sum, poly1, poly2);
    print_polynomial(poly_sum);
    printf("=============\n");
}

Polynomial create_empty_polynomial() {

    Polynomial p;
    p = malloc(sizeof(struct Node));
    
    if (p == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    p->next = NULL;
    return p;
}

void add_term(Polynomial poly, int coeff, int power) {
    
    Polynomial tmp;

    tmp = malloc(sizeof(struct Node));
    if (tmp == NULL) {
        printf("内存分配失败\n");
        return;
    }
    tmp->coeff = coeff;
    tmp->high_power = power;
    tmp->next = poly->next;
    poly->next = tmp;

    return;
}
 
void print_polynomial(Polynomial poly) {
    
    Polynomial tmp;
    tmp = poly->next;

    while (tmp != NULL) {
        if (tmp->coeff == 1) {
            
        } else {
            printf("%d", tmp->coeff);
        }

        if (tmp->high_power == 0) {
            
        } else if (tmp->high_power == 1){
            printf("x");
        } else {
            printf("x^%d", tmp->high_power);
        }

        tmp = tmp->next;
        if (tmp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void add_polynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_sum) {

    int max_php1 = max_poly_high_power(poly1);
    int max_php2 = max_poly_high_power(poly2);
    poly_sum->high_power = max_value(max_php1, max_php2);

    for (int i = poly_sum->high_power; i >= 0; i--) {
        // 这块的逻辑不对，还要找到poly1，poly2对应的位置，要写个find函数，后续补充
        add_term(poly_sum, poly1->coeff + poly2->coeff, i);
    }
}

int max_poly_high_power(Polynomial poly) {

    Polynomial tmp;
    tmp = poly->next;
    int max_high_power = 0;
    
    while (tmp != NULL) {
        if (max_high_power < tmp->high_power) {
            max_high_power = tmp->high_power;
        }
        tmp = tmp->next;
    }
    return max_high_power;
}

int max_value(int a, int b) {

    return a > b ? a : b;
}

void multi_polynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_prod) {
    // to do
}



