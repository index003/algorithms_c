#ifndef HASH_H_

typedef int ElementType;
struct ListNode;
typedef struct ListNode *Position;
typedef Position List;

struct HashTbl;
typedef struct HashTbl *HashTable;

int IsPrime(int x);
int NextPrime(int y);
int Hash(ElementType key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType key, HashTable H);
void Insert(ElementType Key, HashTable H);
int Delete(ElementType Key, HashTable H);
void PrintList(HashTable H);

#endif /* HASH_H_ */
