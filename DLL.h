#ifndef ARRAY_SLL_H
#define ARRAY_SLL_H

#include "linked.h"
#include <string.h>

#define MAX_KOTA 6
#define MAX_NAMA 50

// Menggunakan ElmtList dari linked.h sebagai dasar
typedef struct tElmtList NamaNode;

// Mapping untuk kompatibilitas
#define infotype int  
#define address NamaNode*

typedef struct {
    char kt[MAX_NAMA];
    address head;
    address tail;  // DLL
} Kota;

// Deklarasi fungsi khusus untuk DLL
address DLL_SearchString(address p, const char *nama);
void DLL_IsiNodeString(address *p, const char *nama);
void DLL_TampilListString(address p);

// Deklarasi fungsi utama
void clearScreen();
void pressAnyKeyToContinue();
void initKotaArray(Kota A[]);
void tambahKota(Kota A[], int *jumlahKota);
void tambahNama(Kota A[], int jumlahKota);
void hapusKota(Kota A[], int *jumlahKota);
void hapusNama(Kota A[], int jumlahKota);
void tampilkanSemua(Kota A[], int jumlahKota);
void tampilkanPerKota(Kota A[], int jumlahKota);
void freeAll(Kota A[], int jumlahKota);

#endif
