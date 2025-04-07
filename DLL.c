#include "DLL.h"
#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
    system("cls"); 
}

void pressAnyKeyToContinue() {
    printf("\nTekan Enter untuk kembali ke menu...");
    while(getchar() != '\n'); 
    getchar(); 
}

// Fungsi untuk mengisi node dengan data string
void DLL_IsiNodeString(address *p, const char *nama) {
    if (*p != NULL) {
        // Mengalokasikan memori untuk string
        char *data = (char*)malloc(strlen(nama) + 1);
        strcpy(data, nama);
        (*p)->info = (infotype)data; // Cast pointer ke infotype
    }
}

// Fungsi untuk mencari string dalam list
address DLL_SearchString(address p, const char *nama) {
    address current = p;
    while (current != NULL) {
        char *data = (char*)current->info;
        if (strcmp(data, nama) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Fungsi untuk menampilkan list string
void DLL_TampilListString(address p) {
    address current = p;
    while (current != NULL) {
        printf("%s", (char*)current->info);
        current = current->next;
        if (current != NULL) printf(" <-> ");
    }
}

void initKotaArray(Kota A[]) {
    int i;
    for (i = 0; i < MAX_KOTA; i++) {
        A[i].kt[0] = '\0';
        A[i].head = NULL;
        A[i].tail = NULL;  // Inisialisasi tail
    }
}

void tambahKota(Kota A[], int *jumlahKota) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Array kota sudah penuh!\n");
        return;
    }
    
    printf("Masukkan nama kota: ");
    scanf("%49s", A[*jumlahKota].kt);
    A[*jumlahKota].head = NULL;
    A[*jumlahKota].tail = NULL;  // Inisialisasi tail
    (*jumlahKota)++;
    printf("Kota berhasil ditambahkan.\n");
}

void tambahNama(Kota A[], int jumlahKota) {
    char kotaCari[MAX_NAMA];
    printf("Masukkan kota tujuan: ");
    scanf("%49s", kotaCari);
    
    int i;
    int found = 0;
    for (i = 0; i < jumlahKota; i++) {
        if (strcmp(A[i].kt, kotaCari) == 0) {
            found = 1;
            
            address newNode;
            Create_Node(&newNode);
            
            char nama[MAX_NAMA];
            printf("Masukkan nama: ");
            scanf("%49s", nama);
            
            DLL_IsiNodeString(&newNode, nama);
            
            printf("Tambahkan nama di:\n1. Awal\n2. Akhir\nPilihan: ");
            int posisi;
            scanf("%d", &posisi);
            
            if (posisi == 1) {
                // Insert di awal
                if (A[i].head == NULL) {
                    A[i].head = newNode;
                    A[i].tail = newNode;
                } else {
                    newNode->next = A[i].head;
                    A[i].head->prev = newNode;
                    A[i].head = newNode;
                }
            } else {
                // Insert di akhir
                if (A[i].tail == NULL) {
                    A[i].head = newNode;
                    A[i].tail = newNode;
                } else {
                    A[i].tail->next = newNode;
                    newNode->prev = A[i].tail;
                    A[i].tail = newNode;
                }
            }
            
            printf("Nama berhasil ditambahkan ke kota %s.\n", A[i].kt);
            break;
        }
    }
    
    if (!found) {
        printf("Kota tidak ditemukan!\n");
    }
}

void hapusKota(Kota A[], int *jumlahKota) {
    char kotaHapus[MAX_NAMA];
    printf("Masukkan kota yang akan dihapus: ");
    scanf("%49s", kotaHapus);
    
    int i;
    int found = 0;
    for (i = 0; i < *jumlahKota; i++) {
        if (strcmp(A[i].kt, kotaHapus) == 0) {
            found = 1;
            
            // Hapus semua node
            address current = A[i].head;
            while (current != NULL) {
                address temp = current;
                current = current->next;
                free((void*)temp->info);
                free(temp);
            }
            
            // Geser elemen array
            int j;
            for (j = i; j < *jumlahKota - 1; j++) {
                strcpy(A[j].kt, A[j+1].kt);
                A[j].head = A[j+1].head;
                A[j].tail = A[j+1].tail;
            }
            
            (*jumlahKota)--;
            printf("Kota %s dan semua namanya berhasil dihapus.\n", kotaHapus);
            break;
        }
    }
    
    if (!found) {
        printf("Kota tidak ditemukan!\n");
    }
}

void hapusNama(Kota A[], int jumlahKota) {
    char kotaCari[MAX_NAMA];
    printf("Masukkan kota tempat nama yang akan dihapus: ");
    scanf("%49s", kotaCari);
    
    char namaHapus[MAX_NAMA];
    printf("Masukkan nama yang akan dihapus: ");
    scanf("%49s", namaHapus);
    
    int i;
    int foundKota = 0;
    for (i = 0; i < jumlahKota; i++) {
        if (strcmp(A[i].kt, kotaCari) == 0) {
            foundKota = 1;
            
            if (isEmpty(A[i].head)) {
                printf("Kota %s tidak memiliki nama.\n", kotaCari);
                return;
            }
            
            // Cari node yang akan dihapus
            address toDelete = DLL_SearchString(A[i].head, namaHapus);
            
            if (toDelete != NULL) {
                if (toDelete == A[i].head && toDelete == A[i].tail) {
                    // Hapus satu-satunya node
                    free((void*)toDelete->info);
                    free(toDelete);
                    A[i].head = NULL;
                    A[i].tail = NULL;
                } else if (toDelete == A[i].head) {
                    // Hapus node pertama
                    A[i].head = toDelete->next;
                    A[i].head->prev = NULL;
                    free((void*)toDelete->info);
                    free(toDelete);
                } else if (toDelete == A[i].tail) {
                    // Hapus node terakhir
                    A[i].tail = toDelete->prev;
                    A[i].tail->next = NULL;
                    free((void*)toDelete->info);
                    free(toDelete);
                } else {
                    // Hapus node di tengah
                    toDelete->prev->next = toDelete->next;
                    toDelete->next->prev = toDelete->prev;
                    free((void*)toDelete->info);
                    free(toDelete);
                }
                printf("Nama '%s' berhasil dihapus dari kota %s.\n", namaHapus, kotaCari);
            } else {
                printf("Nama '%s' tidak ditemukan di kota %s.\n", namaHapus, kotaCari);
            }
            break;
        }
    }
    
    if (!foundKota) {
        printf("Kota %s tidak ditemukan!\n", kotaCari);
    }
}

void tampilkanSemua(Kota A[], int jumlahKota) {
    printf("\nData Kota dan Nama:\n");
    int i;
    for (i = 0; i < jumlahKota; i++) {
        printf("Kota: %s\n", A[i].kt);
        printf("Nama-nama: ");
        DLL_TampilListString(A[i].head);
        printf("\n\n");
    }
}

void tampilkanPerKota(Kota A[], int jumlahKota) {
    char kotaCari[MAX_NAMA];
    printf("Masukkan kota yang dicari: ");
    scanf("%49s", kotaCari);
    
    int i;
    int found = 0;
    for (i = 0; i < jumlahKota; i++) {
        if (strcmp(A[i].kt, kotaCari) == 0) {
            found = 1;
            printf("\nData untuk Kota %s:\n", A[i].kt);
            printf("Nama-nama: ");
            DLL_TampilListString(A[i].head);
            printf("\n");
            break;
        }
    }
    
    if (!found) {
        printf("Kota tidak ditemukan!\n");
    }
}

void freeAll(Kota A[], int jumlahKota) {
    int i;
    for (i = 0; i < jumlahKota; i++) {
        address current = A[i].head;
        while (current != NULL) {
            address temp = current;
            current = current->next;
            free((void*)temp->info);
            free(temp);
        }
        A[i].head = NULL;
        A[i].tail = NULL;
    }
}
