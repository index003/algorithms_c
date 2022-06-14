#include <stdio.h>

struct Node {
    int coeff;
    int high_power;
    struct Node *next;
};

int main() {
}

struct Node *make_empty() {

    struct Node *p;
    p = malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }

    p -> next = NULL;

    return p;
}

void zero_polynomial(struct Node *poly) {
}

void add_polynomial(struct Node *poly1, struct Node *poly2, struct Node *poly_sum) {
}

void multi_polynomial(struct Node *poly1, struct Node *poly2, struct Node *poly_prod) {
}
