#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

struct AvlTreeNode {
    ElementType element;
    AvlTree left;
    AvlTree right;
    int height;
};

int main() {
    AvlTree min;
    AvlTree max;
    AvlTree node;
    AvlTree root;
    root = insert_tree(6, NULL);
    root = insert_tree(4, root);
    root = insert_tree(3, root);
    root = insert_tree(2, root);
    root = insert_tree(1, root);
    root = insert_tree(8, root);
    printf("root node is : %d\n", root -> element);
    print_tree(root);
    printf("=============\n");

    node = find(4, root);
    printf("find node element is : %d\n", node->element);
    printf("=============\n");

    min = find_min(root);
    printf("min node element is : %d\n", min->element);
    printf("=============\n");

    max = find_max(root);
    printf("max node element is : %d\n", max->element);
    printf("=============\n");

    delete_tree(3, root);
    printf("root node is : %d\n", root -> element);
    print_tree(root);
    printf("=============\n");
}


static int get_height(Position p) {

    if (p == NULL) {
        return -1;
    } else {
        return p->height;
    }
}

// 查找x，如果没有找到，返回NULL
Position find(ElementType x, AvlTree t) {

    if (t == NULL) {
        return NULL;
    }

    if (x < t->element) {
        return find(x, t->left);
    } else if (x > t->element) {
        return find(x, t->right);
    } else {
        return t;
    }
}

Position find_min(AvlTree t) {

    if (t == NULL) {
        return NULL;
    } else if (t->left == NULL){
        return t;
    } else {
        return find_min(t->left);
    }
}

Position find_max(AvlTree t) {

    if (t != NULL) {
        while (t->right != NULL) {
            t = t->right;
        }
    }

    return t;
}

int max (int a, int b) {
    return a > b ? a : b;
}
/* This function can be called only if k2 has a left child */
/* Perform a rotate between a node (k2) and its left child */
/* Update heights, then return new root */

Position single_rotate_with_left(Position k2) {
    
    Position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(get_height(k2->left), get_height(k2->right)) + 1;
    k1->height = max(get_height(k1->left), k2->height) + 1;
    return k1;  /* new root */
}

static Position single_rotate_with_right(Position k2) {

    Position k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->height = max(get_height(k2->left), get_height(k2->right)) + 1;
    k1->height = max(get_height(k1->right), k2->height) + 1;

    return k1;  /* new root */
}

/* This function can be called only if k3 has a left */
/* child and k3's left child has a right child */
/* Do the left-right double rotation */
/* Update heights, then return new root */

static Position double_rotate_with_left(Position k3) {
    
    /* Rotate between k1 and k2 */
    k3->left = single_rotate_with_right(k3->left);

    /* Rotate between k3 and k2 */
    return single_rotate_with_left(k3);
}

static Position double_rotate_with_right(Position k3) {

    /* Rotate between k1 and k2 */
    k3->left = single_rotate_with_left(k3->right);

    /* Rotate between k3 and k2 */
    return single_rotate_with_right(k3);
}

AvlTree insert_tree(ElementType x, AvlTree t) {
    if (t == NULL) {
        /* Create and return a one-node tree */
        t = malloc(sizeof(struct AvlTreeNode));
        if (t == NULL) {
            printf("Out of space!!!\n");
        } else {
            t->element  = x;
            t->height = 0;
            t->left = NULL;
            t->right = NULL;
        }
    } else if (x < t->element) {
        t->left = insert_tree(x, t->left);
        if (get_height(t->left) - get_height(t->right) == 2) {
            if (x < t->left->element) {
                t = single_rotate_with_left(t);
            } else {
                t = double_rotate_with_left(t);
            }
        }
        
    } else if (x > t->element) {
        t->right = insert_tree(x, t->right);
        if (get_height(t->right) - get_height(t->left) == 2) {
            if (x > t->right->element) {
                t = single_rotate_with_right(t);
            } else {
                t = double_rotate_with_right(t);
            }
        }
    } 
    /* else x is in the tree already; we'll do nothing */

    t->height = max(get_height(t->left), get_height(t->right)) + 1;
    return t;
}

AvlTree delete_tree(ElementType x, AvlTree t) {
    
    Position tmp;
    if (t == NULL) {
        printf("empty tree!!\n");
        return NULL;
    } else if (x < t->element) {
        t->left = delete_tree(x, t->left);
    } else if (x > t->element) {
        t->right = delete_tree(x, t->right);
    } else if (t->left != NULL && t->right != NULL) {
        tmp = find_min(t->right);
        t->element = tmp->element;
        t->right = delete_tree(t->element, t->right);
    } else {
        tmp = t;
        if (t->left == NULL) {
            t = t->right;
        } else if (t->right == NULL) {
            t = t->left;
        }
        free(tmp);
    }
    return t;
}

void print_tree(AvlTree t) {

    if (t == NULL) {
        printf("Empty Tree!\n");
        return;
    }

    // 打印左子树
    if (t->left != NULL) {
        print_tree(t->left);
    }

    // 打印根节点
    printf("tree element is : %d\n", t->element);

    // 打印右子树
    if (t->right != NULL) {
        print_tree(t->right);
    }
}



