// 树的节点说明
typedef struct TreeNode *PtrToNode;
typedef int element;

struct TreeNode {
    ElementType Element;
    PtrToNode FirstChild;   // 指向第一个孩子节点
    PtrToNode NextSibling;  // 指向兄弟的节点
}

// 二叉树的节点说明

typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef int element;

struct TreeNode {
    ElementType Element;
    Tree Left;
    Tree Right;
}

// 树的遍历

/*
先序遍历：先处理根节点，再处理左节点，最后处理右节点    (根 -> 左 -> 右)

中序遍历：先处理左节点，再处理中节点，最后处理右节点    (左 -> 根 -> 右) 

后续遍历：先处理左节点，再处理有节点，最后处理中节点    (左 -> 右 -> 根 )
*/
