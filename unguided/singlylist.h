#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);

address alokasi(infotype data);

void dealokasi(address P);

void insertFirst(List &L, address P);

void printInfo(List L);

void deleteFirst(List &L, address &P);

void deleteLast(List &L, address &P);

void deleteAfter(List &L, address prev, address &P);

int nbList(List L);

void deleteList(List &L);

#endif
