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

struct Node {
    int coeff;
    int high_power;
    struct Node *next;
};

int main() {

    Polynomial p;
    p = create_empty_polynomial();

    add_term(p, 3, 2);
    print_polynomial(p);
}

Polynomial create_empty_polynomial() {

    Polynomial p;
    p = malloc(sizeof(struct Node));
    
    if (p == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    p -> next = NULL;
    return p;
}

void add_term(Polynomial poly, int coeff, int power) {
    
    Polynomial tmp;

    tmp = malloc(sizeof(struct Node));
    if (tmp == NULL) {
        printf("内存分配失败\n");
        return;
    }
    tmp -> coeff = coeff;
    tmp -> high_power = power;
    tmp -> next = poly -> next;
    poly -> next = tmp;

    return;
}
 
void print_polynomial(Polynomial poly) {
    
    Polynomial tmp;
    tmp = poly -> next;

    while (tmp != NULL) {
        printf("poly element is: %dx^%d", tmp -> coeff, tmp -> high_power);
        tmp = tmp -> next;
    } 
    printf("\n");
}

void add_polynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_sum) {
    
}

void multi_polynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_prod) {
    // to do
}
