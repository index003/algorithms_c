#ifndef _AvlTree_H

struct AvlTreeNode;
typedef struct AvlTreeNode *Position; //给struct Node取一个别名
typedef struct AvlTreeNode *AvlTree; //给struct Node取一个别名
typedef int ElementType;

// 创建表头
AvlTree make_empty(AvlTree T);

static int get_height(Position P);
// 查找x，如果没有找到，返回NULL
Position find(ElementType X, AvlTree T);

Position find_min(AvlTree T);
Position find_max(AvlTree T);

int max (int a, int b);

static Position single_rotate_with_left(Position k2);
static Position single_rotate_with_right(Position k2);
static Position double_rotate_with_left(Position k3);
static Position double_rotate_with_right(Position k3);

AvlTree insert_tree(ElementType X, AvlTree T);
AvlTree delete_tree(ElementType X, AvlTree T);

void print_tree(AvlTree T);

#endif  /* _AvlTree_H */
