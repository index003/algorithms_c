#ifndef _Tree_H

struct TreeNode;
typedef struct TreeNode *Position; //给struct Node取一个别名
typedef struct TreeNode *SearchTree; //给struct Node取一个别名
typedef int ElementType;

// 创建表头
SearchTree make_empty(SearchTree T);

// 查找x，如果没有找到，返回NULL
Position find(ElementType X, SearchTree T);

Position find_min(SearchTree T);
Position find_max(SearchTree T);

SearchTree insert_tree(ElementType X, SearchTree T);
SearchTree delete_tree(ElementType X, SearchTree T);

void print_tree(SearchTree T);
int is_binary_tree(SearchTree T);
#endif  /* _Tree_H */

