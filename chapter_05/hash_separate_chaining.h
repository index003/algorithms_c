#ifndef _HashSep_H

typedef int ElementType;
struct ListNode;
typedef struct ListNode *Position;
typedef Position List;

struct HashTbl;
typedef struct HashTbl *HashTable;

int is_prime(int num);    // 是否是一个素数 
int next_prime(int num);    // 返回下一个素数 

int hash(ElementType key, int table_size);

HashTable initialize_table(int table_size);

void destroy_table(HashTable h);

Position find_element(ElementType key, HashTable h);

void insert_table(ElementType key, HashTable h);
int delete_table(ElementType key, HashTable h);
void print_table(HashTable h);

#endif  /* _HashSep_H */

