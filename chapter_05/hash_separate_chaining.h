#ifndef _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
typedef struct *Position List;

struct HashTbl;
typedef struct HashTbl *HashTable;
typedef int ElementType;

HashTable initialze_table(int table_size);

void destroy_table(HashTable h);

Position find(ElementType key, HashTable h);

void insert_table(ElementType key, HashTable h);

#endif  /* _HashSep_H */

