#include "DLL.h"
#include <stdio.h>
#include <stdlib.h> 


int main() {
    Kota A[MAX_KOTA];
    int jumlahKota = 0;
    int pilihan;
    
    initKotaArray(A);
    
    do {
        clearScreen();
        printf("\n=== PROGRAM MANAJEMEN KOTA DAN NAMA ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Nama ke Kota\n");
        printf("3. Hapus Kota\n");
        printf("4. Hapus Nama dari Kota\n");
        printf("5. Tampilkan Semua Data\n");
        printf("6. Tampilkan Data per Kota\n");
        printf("7. Keluar\n");
        printf("\nPilihan Anda: ");
        scanf("%d", &pilihan);
        
        clearScreen();
        
        switch (pilihan) {
            case 1:
                printf("=== TAMBAH KOTA ===\n");
                tambahKota(A, &jumlahKota);
                pressAnyKeyToContinue();
                break;
            case 2:
                printf("=== TAMBAH NAMA KE KOTA ===\n");
                tambahNama(A, jumlahKota);
                pressAnyKeyToContinue();
                break;
            case 3:
                printf("=== HAPUS KOTA ===\n");
                hapusKota(A, &jumlahKota);
                pressAnyKeyToContinue();
                break;
            case 4:
                printf("=== HAPUS NAMA DARI KOTA ===\n");
                hapusNama(A, jumlahKota);
                pressAnyKeyToContinue();
                break;
            case 5:
                printf("=== SEMUA DATA KOTA DAN NAMA ===\n");
                tampilkanSemua(A, jumlahKota);
                pressAnyKeyToContinue();
                break;
            case 6:
                printf("=== DATA PER KOTA ===\n");
                tampilkanPerKota(A, jumlahKota);
                pressAnyKeyToContinue();
                break;
            case 7:
                printf("Terima kasih telah menggunakan program.\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan pilih 1-7.\n");
                pressAnyKeyToContinue();
        }
    } while (pilihan != 7);
    
    freeAll(A, jumlahKota);
    
    return 0;
}
