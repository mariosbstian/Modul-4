
# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (4)</h1>
<p align="center">Mario Sebastian Barus</p>

## Dasar Teori
Kode yang telah dibuat merepresentasikan penerapan konsep dasar pemrograman terstruktur dalam bahasa C++, yang mencakup penggunaan fungsi, struktur data (struct), array, serta pointer. Prinsip modularitas diterapkan untuk menjadikan program lebih efisien, terstruktur, dan mudah dipahami. Pemanfaatan struct berfungsi untuk mengelompokkan data secara sistematis, sementara array dan pointer digunakan untuk mempelajari pengelolaan memori serta manipulasi data.
## Guided 

### main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

### list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

### list.h

```C++
#ifndef LISH_H
#define LiSH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};
// dekralasi isi data 
typedef mahasiswa dataMahasiswa;
typedef struct node *address; // alamat addres pada pointer

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};
// smua procedure da func yang dipakai
bool isEmpty (linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

### main2.cpp

```C++
#include "list2.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deletList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

### list2.cpp

```C++
#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke -: " << i+1 << endl;
    }
}

int main() {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```

### list2.h

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

```
Program ini dibuat untuk menerapkan dan menguji penggunaan struktur data singly linked list dalam bahasa C++ pada pengolahan data mahasiswa. Kode mencakup pembuatan list penambahan dan penghapusan elemen, pengelolaan memori, penghitungan jumlah node, serta penampilan data. Program utama berfungsi untuk menjalankan dan memverifikasi bahwa seluruh operasi linked list berjalan dengan baik sesuai konsep struktur data.

## Unguided 

### 1. [main.cpp]

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);


    //       NOMOR 2

    address P;

  
    deleteFirst(L, P);
    dealokasi(P);

    deleteLast(L, P);
    dealokasi(P);

    deleteAfter(L, L.First, P); 
    dealokasi(P);

    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);

    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}

```
Kode ini merupakan file implementasi yang mendefinisikan fungsi-fungsi Singly Linked List sesuai deklarasi pada file header. File tersebut berfungsi mendukung pengelolaan data list sehingga dapat dijalankan dengan baik oleh program utama.
#### Full code Screenshot:
<img width="352" height="578" alt="image" src="https://github.com/user-attachments/assets/cd8a83fd-c2ad-48bf-82b0-7564f6283410" />

### [singlylist.cpp]

```C++
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

```

Kode tersebut merupakan file implementasi yang berisi realisasi fungsi-fungsi Singly Linked List sesuai dengan deklarasi pada header file. File ini berfungsi mengatur operasi dasar list, seperti pembuatan, penambahan, penghapusan, penelusuran, dan perhitungan jumlah elemen, sehingga struktur data dapat digunakan dengan baik oleh program utama.
#### Full code Screenshot:
<img width="210" height="465" alt="image" src="https://github.com/user-attachments/assets/145f98d5-bf08-4c10-a059-e09bfd924540" />
<img width="235" height="572" alt="image" src="https://github.com/user-attachments/assets/1337ac44-f51c-4719-a0fa-4e67ec450229" />




### [singlylist.h]

```C++
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

```

#### Output:
<img width="292" height="78" alt="image" src="https://github.com/user-attachments/assets/70c06400-d4ce-4e57-84a1-4efdfcff427e" />

Kode ini merupakan file header yang berisi deklarasi struktur data dan prototipe fungsi untuk mengimplementasikan Singly Linked List. File ini mendefinisikan tipe data, node, serta operasi dasar pada list yang digunakan sebagai acuan dalam file implementasi dan program utama agar pengelolaan data dapat berjalan secara terstruktur.

#### Full code Screenshot:
<img width="277" height="387" alt="image" src="https://github.com/user-attachments/assets/9f4e6ca6-f8f1-4acc-820b-f58429503680" />




## Kesimpulan
Kode program yang sudah dibuat kita bisa melihat gambaran  penerapan konsep dasar pemrograman terstruktur menggunakan bahasa C++. Program tersebut menunjukkan bagaimana berbagai elemen penting dalam pemrograman seperti fungsi, struktur data (struct), array, pointer, dan modularisasi kode  dapat diintegrasikan untuk membentuk sistem yang rapi, efisien, serta mudah dipahami.
Melalui penggunaan struct, data yang memiliki keterkaitan, seperti data mahasiswa dan pelajaran, dapat dikelompokkan dengan teratur.
## Referensi
[1] Budiarto, A., & Hidayat, R. (2021). Penerapan Konsep Modular dan Struktur Data dalam Pembelajaran Pemrograman. Jurnal Teknologi dan Sistem Komputer, 9(2), 123–130.
[2] Setiawan, D., & Pramono, H. (2020). Penerapan Bahasa Pemrograman C++ untuk Penguatan Konsep Algoritma dan Struktur Data. Jurnal Ilmu Komputer dan Informatika, 6(1), 45–52.
[3] Sukamto, A., & Shalahuddin, M. (2018). Rekayasa Perangkat Lunak: Terstruktur dan Berorientasi Objek. Informatika Bandung.
[4] Deitel, P. J., & Deitel, H. M. (2017). C++ How to Program (10th Edition). Pearson Education.
