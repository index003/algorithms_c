<< Data Structures and Algorithm Analysis in C >>  Mark Allen

抽象数据类型(ADT abstract data type)是一些操作的集合。

如：表、集合、图和他们的操作一起可以看做是抽象数据类型，就像整数、实数和布尔量是数据类型一样。
整数、实数和布尔量有与他们相关的操作，而抽象数据类型也有与它们自己的操作。

第三章 表、栈和队列

3.2 表ADT

链表、单链表 (linked list)

struct Node {

    int element;    // node value
    struct Node *next; // next node point
};

双链表 (double linked list)

struct Node {

    int element;    // node value
    struct Node *previous; // previous node point
    struct Node *next; // next node point
};

3.3 栈ADT

栈 (stack)

栈是限制插入和删除只能在一个位置上进行的表，该位置是表的末端，叫做栈顶(top)
栈有时又叫后进先出(LIFO)表，它的两个基本操作是进栈(Push)和出栈(Pop)。

栈的链表实现

struct Node {

    int element;
    struct Node *next;
};

栈的数组实现

struct StackRecord {

    int capacity;   // 栈的容量
    int top_of_stack; // 栈顶脚标
    ElementType *arr; // 数组首元素地址
};

栈的应用：逆波兰表示法，递归调用，程序调用

3.4 队列ADT

队列 (Queue)

像栈一样，队列也是表。使用队列时插入在一端进行，而删除在另一端进行
队列是先进先出(FIFO),它的两个基本操作是:
入队(Enqueue) 它是在表的末端(叫做队尾(rear))插入一个元素
出队(Dequeue) 它是删除(或返回)在表的开头(叫做队头(front))的元素

队列的链表实现

struct QueueNode {

    int element;  
    Queue next;  
};

队列的数组实现

struct QueueRecord {

    int capacity;   // 队列容量
    int size;   // 队列有效数据的大小
    int front;  // 队列头的脚标
    int rear;   // 队列尾的脚标
    int *arr;   // 指针，指向数组首元素的地址（即数组地址）
};


第四章 树

表、栈、队列操作都是线性的，时间和空间复杂度都较高，所以引入树ADT

4.1 树的基本概念

定义树的一种自然的方式是递归的方法。
一棵树是一些节点的集合，一个非空集，则一颗树由称作树根(root)的节点r以及
0个或多个非空的(子)树T1,T2,...Tk组成,
这些子树中每一颗的根都来自根r的一条有向的边(edge)所连接。

一个典型的应用：文件结构

// 树的节点说明

typedef struct TreeNode *PtrToNode;

typedef int element;

struct TreeNode {

    ElementType Element;
    PtrToNode FirstChild;   // 指向第一个孩子节点
    PtrToNode NextSibling;  // 指向兄弟的节点
}

4.2 二叉树

二叉树(binary tree),是一种特殊的树，其中每个节点不能有多于两个的孩子(child)



// 二叉树的节点说明

typedef struct TreeNode *PtrToNode;

typedef PtrToNode Tree;

typedef int element;

struct TreeNode {

    ElementType Element;
    Tree Left;
    Tree Right;
}

4.3 查找树ADT-二叉查找树

二叉查找树(search tree)

二叉树成为二叉查找树的性质是：对于树中的每个节点X，它的左子树中所有关键字值
小于X的关键字值，而它的右子树中所有关键字值大于X的关键字值。即：该树所有的元素
可以用某种统一的方式排序。

struct TreeNode;

typedef struct TreeNode *Position; //给struct Node取一个别名

typedef struct TreeNode *SearchTree; //给struct Node取一个别名

typedef int ElementType;

struct TreeNode {

    ElementType element;
    SearchTree left;
    SearchTree right;
};

// 树的遍历

/*
先序遍历：先处理根节点，再处理左节点，最后处理右节点    (根->左->右)

中序遍历：先处理左节点，再处理中节点，最后处理右节点    (左->根->右) 

后续遍历：先处理左节点，再处理有节点，最后处理中节点    (左->右->根 )
*/

4.4 AVL树

AVL(Adelson-Velskii和Landis)树是带有平衡条件的二叉查找树。
这个平衡条件就是：AVL树每个节点左子树和右子树的高度最多差1的二叉查找树。
空树的高度定义为-1.

struct AvlTreeNode;

typedef struct AvlTreeNode *Position; //给struct Node取一个别名

typedef struct AvlTreeNode *AvlTree; //给struct Node取一个别名

typedef int ElementType;

struct AvlTreeNode {

    ElementType element;
    AvlTree left;
    AvlTree right;
    int height;
};

为了保持平衡，左左，右右，需要单旋转；左右，右左，需要双旋转。

4.5 伸展树

查询一次，开始调整树的结构

4.6 B-树

非二叉树，2-3-4树，2-3数
MySql底层使用的是B+Tree的ADT

第五章 散列

二叉查找树里面的元素有序，而散列表里面的元素无序
散列表的实现常常叫散列(hashing),它是一种以常数平均时间执行插入、删除和查找的技术。

散列表数据结构只不过是一个包含有关键字的具有固定大小的数组。每个关键字被映射到
从0到TableSize - 1这个范围中的某个数，并且被放到适当的单元中。
这个映射就叫做散列函数(hash function),即常见的Hash函数。
如： h(x) = x % table_size;

但是输入的关键字是无限的，而散列表的单元是有限的，就会导致不同的关键字会映射到同一个位置，即为冲突。

我们要解决这个冲突。

5.3 分离链接法

就是数组+链表的形式，将散列到同一个值的所有单元保留到一个链表中

typedef int ElementType;

struct ListNode;

typedef struct ListNode *Position;

typedef Position List;

struct HashTbl;

typedef struct HashTbl *HashTable;

struct ListNode {

    ElementType element;
    Position next;
};

struct HashTbl {

    int table_size;
    List *the_lists;
};

第六章 堆

堆(heap) 也叫 优先队列(priority queue)

两种操作：
insert(插入)等价于Enqueue(入队)
Deletemin(删除最小)等价于Dequeue(出队)

6.3 二叉对

堆是一颗被完全填满的二叉树，有可能例外的是在底层，底层上的元素从左到有填入，即完全二叉树(complete binary tree)

堆的实现是使用数组,对于数组中任一位置i上的元素，其左孩子在位置2i上，右孩子在位置2i + 1上，父亲则在[i/2]上


typedef int ElementType;

typedef struct HeapStruct *PriorityQueue;

struct HeapStruct {

    int capacity;
    int size;
    ElementType *elements;
};











































































