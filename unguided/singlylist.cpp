#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype data) {
    address baru = new ElmList;
    baru->info = data;
    baru->next = Nil;
    return baru;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (P != Nil) {
        P->next = L.First;
        L.First = P;
    }
}

void printInfo(List L) {
    address penunjuk = L.First;
    while (penunjuk != Nil) {
        cout << penunjuk->info << " ";
        penunjuk = penunjuk->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

void deleteLast(List &L, address &P) {
    address current = L.First;

    if (current == Nil) {
        P = Nil;
        return;
    }

    if (current->next == Nil) {
        P = current;
        L.First = Nil;
        return;
    }

    while (current->next->next != Nil) {
        current = current->next;
    }

    P = current->next;
    current->next = Nil;
}

void deleteAfter(List &L, address prev, address &P) {
    if (prev != Nil && prev->next != Nil) {
        P = prev->next;
        prev->next = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

int nbList(List L) {
    int jumlah = 0;
    address iterasi = L.First;

    while (iterasi != Nil) {
        jumlah++;
        iterasi = iterasi->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    address hapus;

    while (L.First != Nil) {
        deleteFirst(L, hapus);
        dealokasi(hapus);
    }
}
