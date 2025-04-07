#include "linked.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk memeriksa apakah linked list kosong
boolean isEmpty(address p) {
    return (p == NULL);
}

// Fungsi untuk membuat node baru
void Create_Node(address *p) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->next = NULL;
        (*p)->prev = NULL;  // Inisialisasi pointer prev
    } else {
        printf("Gagal mengalokasikan memori untuk node baru.\n");
    }
}

// Fungsi untuk mengisi node dengan nilai tertentu
void Isi_Node(address *p, infotype nilai) {
    if (*p != NULL) {
        (*p)->info = nilai;
        (*p)->next = NULL;
        (*p)->prev = NULL;
    }
}

// Fungsi untuk menampilkan seluruh isi linked list
void Tampil_List(address p) {
    address current = p;
    while (current != NULL) {
        printf("%d <-> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}

// Fungsi untuk menyisipkan node di awal linked list
void Ins_Awal(address *p, address PNew) {
    if (PNew != NULL) {
        PNew->next = *p;
        if (*p != NULL) {
            (*p)->prev = PNew;
        }
        PNew->prev = NULL;
        *p = PNew;
    }
}

// Fungsi untuk menyisipkan node di akhir linked list
void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew;
        PNew->prev = NULL;
    } else {
        address current = *p;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = PNew;
        PNew->prev = current;
    }
    PNew->next = NULL;
}

// Fungsi untuk mencari node dengan nilai tertentu
address Search(address p, infotype nilai) {
    address current = p;
    while (current != NULL) {
        if (current->info == nilai) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Fungsi untuk menyisipkan node setelah node tertentu
void InsertAfter(address *pBef, address PNew) {
    if (*pBef != NULL && PNew != NULL) {
        PNew->next = (*pBef)->next;
        PNew->prev = *pBef;
        if ((*pBef)->next != NULL) {
            (*pBef)->next->prev = PNew;
        }
        (*pBef)->next = PNew;
    }
}

// Fungsi untuk menghapus node di awal linked list
void Del_Awal(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p;
        *X = temp->info;
        *p = (*p)->next;
        if (*p != NULL) {
            (*p)->prev = NULL;
        }
        free(temp);
    }
}

// Fungsi untuk menghapus node di akhir linked list
void Del_Akhir(address *p, infotype *X) {
    if (*p != NULL) {
        address current = *p;
        while (current->next != NULL) {
            current = current->next;
        }
        
        *X = current->info;
        if (current->prev != NULL) {
            current->prev->next = NULL;
        } else {
            *p = NULL;
        }
        free(current);
    }
}

// Fungsi untuk menghapus node setelah node tertentu
void Del_After(address *pBef, infotype *X) {
    if (*pBef != NULL && (*pBef)->next != NULL) {
        address temp = (*pBef)->next;
        *X = temp->info;
        (*pBef)->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = *pBef;
        }
        free(temp);
    }
}

// Fungsi untuk dealokasi node
void DeAlokasi(address *p) {
    if (*p != NULL) {
        free(*p);
        *p = NULL;
    }
}

// Fungsi untuk menghitung jumlah elemen dalam linked list (recursive)
int NbElmt(address p) {
    if (p == NULL) {
        return 0;
    } else {
        return 1 + NbElmt(p->next);
    }
}

// Fungsi untuk mencari nilai minimum dalam linked list (recursive)
infotype Min(address p) {
    if (p->next == NULL) {
        return p->info;
    } else {
        infotype minRest = Min(p->next);
        return (p->info < minRest) ? p->info : minRest;
    }
}

// Fungsi untuk menghitung rata-rata nilai dalam linked list (recursive)
infotype Rerata(address p) {
    int sum = 0;
    int count = 0;
    address current = p;
    while (current != NULL) {
        sum += current->info;
        count++;
        current = current->next;
    }
    return (count == 0) ? 0 : sum / count;
}

// Fungsi untuk membalik linked list
address BalikList(address p) {
    address prev = NULL;
    address current = p;
    address next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;  // Perubahan untuk DLL
        prev = current;
        current = next;
    }
    return prev;
}

// Fungsi untuk mengubah nilai node pertama
void ModifyFirst(address p, infotype newValue) {
    if (p != NULL) {
        p->info = newValue;
    }
}

// Fungsi untuk mengubah nilai node terakhir
void ModifyLast(address p, infotype newValue) {
    if (p != NULL) {
        while (p->next != NULL) {
            p = p->next;
        }
        p->info = newValue;
    }
}

// Fungsi untuk mengubah nilai node setelah node tertentu
void ModifyAfter(address pBef, infotype newValue) {
    if (pBef != NULL && pBef->next != NULL) {
        pBef->next->info = newValue;
    }
}

// Fungsi untuk menukar dua nilai dalam linked list
void SwapValues(address p, infotype value1, infotype value2) {
    address node1 = NULL, node2 = NULL, temp = p;
    while (temp != NULL) {
        if (temp->info == value1) {
            node1 = temp;
        }
        if (temp->info == value2) {
            node2 = temp;
        }
        temp = temp->next;
    }
    if (node1 != NULL && node2 != NULL) {
        infotype tempValue = node1->info;
        node1->info = node2->info;
        node2->info = tempValue;
    }
}

// Fungsi untuk menghitung jumlah semua elemen dalam linked list
infotype SumList(address p) {
    if (p == NULL) {
        return 0;
    } else {
        return p->info + SumList(p->next);
    }
}

// Fungsi untuk menghapus semua elemen bernilai ganjil dalam linked list
void HapusGanjil(address *p) {
    address current = *p;
    while (current != NULL) {
        if (current->info % 2 != 0) {
            address toDelete = current;
            current = current->next;
            
            if (toDelete->prev != NULL) {
                toDelete->prev->next = toDelete->next;
            } else {
                *p = toDelete->next;
            }
            
            if (toDelete->next != NULL) {
                toDelete->next->prev = toDelete->prev;
            }
            
            free(toDelete);
        } else {
            current = current->next;
        }
    }
}

// Fungsi untuk menghapus semua elemen dalam linked list
void HapusSemua(address *p) {
    address current = *p;
    while (current != NULL) {
        address temp = current;
        current = current->next;
        free(temp);
    }
    *p = NULL;
}
