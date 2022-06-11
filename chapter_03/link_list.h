#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode; //给struct Node取一个别名
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

// 创建表头
List MakeEmpty();
// 判断表是否为空
int IsEmpty(List L);
// 判断是否最后一个
int IsLast(List L);

// 查找x，如果没有找到，返回NULL
Position Find(List L, ElementType X);
// 查找位置为y的结点,如果没有找到，返回NULL
Position FindKth(List L, int y);
// 查找当前结点的前一个位置
Position FindPrevious(ElementType X, List L);

// 从表头插入
void insertFirst(List L, int x);
// 从表尾插入
void insertLast(List L, int x);
// 指定位置插入
void Insert(ElementType X, List L, Position P);

// 删除第一个值匹配的结点
void Delete(List L, ElementType X);
// 删除表中所有的结点
void DeleteList(List L);

Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
// 表中结点个数
int size(List L);
// 打印表中元素
void printList(List L);
#endif  /* _List_H */

