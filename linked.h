#ifndef LINKED_H
#define LINKED_H

#include "boolean.h"  // boolean

// Definisi tipe data
typedef int infotype;
typedef struct tElmtList *address;

typedef struct tElmtList {
    infotype info;
    address next;
    address prev;  //untuk DLL
} ElmtList;

// Fungsi dan prosedur
boolean isEmpty(address p);
void Create_Node(address *p);
void Isi_Node(address *p, infotype nilai);
void Tampil_List(address p);
void Ins_Awal(address *p, address PNew);
void Ins_Akhir(address *p, address PNew);
address Search(address p, infotype nilai);
void InsertAfter(address *pBef, address PNew);
void Del_Awal(address *p, infotype *X);
void Del_Akhir(address *p, infotype *X);
void Del_After(address *pBef, infotype *X);
void DeAlokasi(address *p);
int NbElmt(address p);
infotype Min(address p);
infotype Rerata(address p);
address BalikList(address p);
void ModifyFirst(address p, infotype newValue);
void ModifyLast(address p, infotype newValue);
void ModifyAfter(address pBef, infotype newValue);
void SwapValues(address p, infotype value1, infotype value2);
infotype SumList(address p);
void HapusGanjil(address *p);
void HapusSemua(address *p);

#endif
