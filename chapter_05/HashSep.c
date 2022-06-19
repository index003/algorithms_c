#include <stdio.h>
#include <stdlib.h>
#include "HashSep.h"

#define MINTABLESIZE 5

struct ListNode {
    ElementType Element;
    Position Next;
};

struct HashTbl {
    int TableSize;
    List *TheLists;
};

int main() {
    
    Position p;
    HashTable table;

    table = InitializeTable(10);

    Insert(19, table);
    Insert(18, table);
    Insert(17, table);
    Insert(9, table);
    Insert(8, table);
    Insert(7, table);
    Insert(10, table);
    Insert(11, table);
    Insert(3, table);
    PrintList(table);
}

int IsPrime(int num) {   // 是否是一个素数 
    
    for (int i = 2; i * i < num +1; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int NextPrime(int num) { // 返回下一个素数

    while(1 == 1) {
        if (IsPrime(num)) {
            return num;
        } else {
            num++;
        }
    }
}

int Hash(ElementType key, int TableSize) {
    return key % TableSize;
}

HashTable InitializeTable(int TableSize) {

    HashTable H;
    int i;

    if (TableSize < MINTABLESIZE) {
        return NULL;
    }

    //H = (HashTable)malloc(sizeof(struct HashTbl));
    H = (struct HashTbl *)malloc(sizeof(struct HashTbl));

    if (H == NULL) {
        printf("Error! Out of memory!\n");
        return NULL;
    }

    H->TableSize = NextPrime(TableSize);
    //H->TheLists = (Position *)malloc(H->TableSize * sizeof(Postion));
    H->TheLists = (List *)malloc(H->TableSize * sizeof(List));

    if (H->TheLists == NULL) {
        printf("Error! Out of memory!\n");
        return NULL;
    }

    for (i = 0; i < H->TableSize; i++) {
        //if ((H->TheLists[i] = (List)malloc(sizeof(struct ListNode))) == NULL) {
        if ((H->TheLists[i] = (struct ListNode*)malloc(sizeof(struct ListNode))) == NULL) {
            printf("Error! Out of memory!\n");
            return NULL;
        }
        H->TheLists[i]->Next = NULL;
    }
    return H;
}


void DestroyTable(HashTable H) {
}

Position Find(ElementType key, HashTable H) {
    Position P;
    List L;

    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->Next;

    while(P != NULL && P->Element != key) {
        P = P->Next;
    }

    return P;
}

void Insert(ElementType key, HashTable H) {
    Position pos, new_cell;
    List l;

    pos = Find(key, H);
    if (pos == NULL) {
        new_cell = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (new_cell == NULL) {
            printf("Out of space!!!\n");
            exit(0);
            //return;
        } else {
            l = H->TheLists[Hash(key, H->TableSize)];
            new_cell->Next = l->Next;
            new_cell->Element = key;
            l->Next = new_cell;
        }
    }
}

int Delete(ElementType Key, HashTable H) {
}

void PrintList(HashTable H) {
    Position P;
    List L;

    for (int i = 0; i < H->TableSize; i++) {
        L = H->TheLists[i];
        P = L->Next;
        printf("下标 %d :", i);

        while (P != NULL) {
            printf("%d ", P->Element);
            P = P->Next;
        }

        printf("\n");
    }
}




