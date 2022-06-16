#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

struct TreeNode {
    ElementType element;
    SearchTree left;
    SearchTree right;
};

int main() {

    SearchTree min;
    SearchTree max;
    SearchTree node;
    SearchTree root;

    root = insert_tree(6, NULL);
    insert_tree(4, root);
    insert_tree(3, root);
    insert_tree(2, root);
    insert_tree(1, root);
    insert_tree(8, root);

    print_tree(root);
    printf("=============\n");

    node = find(4, root);
    printf("find node element is : %d\n", node -> element);
    printf("=============\n");

    min = find_min(root);
    printf("min node element is : %d\n", min -> element);
    printf("=============\n");

    max = find_max(root);
    printf("max node element is : %d\n", max -> element);
    printf("=============\n");
    
    delete_tree(2, root);
    printf("delete_tree(2, root)\n");
    print_tree(root);
    printf("=============\n");

    make_empty(root);
    print_tree(root);
}
// 清空树
SearchTree make_empty(SearchTree t) {
    
    if (t) {
        make_empty(t -> left);
        make_empty(t -> right);
        free(t);
    }
    return NULL;
}

// 查找x，如果没有找到，返回NULL
Position find(ElementType x, SearchTree t) {

    if (t == NULL) {
        return NULL;
    }

    if (x < t -> element) {
        return find(x, t -> left);
    } else if (x > t -> element) {
        return find(x, t -> right);
    } else {
        return t;
    }
    
}

Position find_min(SearchTree t) {

    if (t == NULL) {
        return NULL;
    } else if (t -> left == NULL){
        return t;
    } else {
        return find_min(t -> left);
    }
}

Position find_max(SearchTree t) {

    if (t != NULL) {
        while (t -> right != NULL) {
            t = t -> right;
        }
    }

    return t;
}

SearchTree insert_tree(ElementType x, SearchTree t) {
    
    if (t == NULL) {
        t = malloc(sizeof(struct TreeNode));
        if (t == NULL) {
            printf("Out of space!\n");
            return NULL;
        } else {
            t -> element = x;
            t -> left = NULL;
            t -> right = NULL;
        }
    } else if (x < t -> element) {
        t -> left = insert_tree(x, t -> left);
    } else if (x > t -> element) {
        t -> right = insert_tree(x, t -> right);
    } else {
        return t;
    }
}

SearchTree delete_tree(ElementType x, SearchTree t) {

    Position tmp;

    if (t == NULL) {
        printf("Empty Tree!\n");
        return NULL;
    } else if (x < t -> element) {
        t -> left = delete_tree(x, t -> left);
    } else if (x > t -> element) {
        t -> right = delete_tree(x, t -> left);
    } else if (t -> left && t -> right) {
        tmp = find_min(t -> right);
        t -> element = tmp -> element;
        t -> right = delete_tree(t -> element, t -> right);
    } else {
        tmp = t;
        if (t -> left == NULL) {
            t = t -> right;
        } else if (t -> right == NULL) {
            t = t -> left;
        }
        free(tmp);
    }

    return t;
}

// 使用中序遍历，打印树中元素
void print_tree(SearchTree t) {

    if (t == NULL) {
        printf("Empty Tree!\n");
        return;
    }

    // 打印左子树
    if (t -> left != NULL) {
        print_tree(t -> left);
    }

    // 打印根节点
    printf("tree element is : %d\n", t -> element);

    // 打印右子树
    if (t -> right != NULL) {
        print_tree(t -> right);
    }
}




