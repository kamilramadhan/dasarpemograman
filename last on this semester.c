#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char judul_tugas[50];
    char tipe_tugas[20];
    char deadline[20];
    char selesai[10];
} Tugas;

Tugas tugas[100];
int count = 0;

void add_tugas() {
    Tugas new_tugas;
    new_tugas.id = count + 1;
    printf("Masukkan judul tugas: ");
    scanf("%s", new_tugas.judul_tugas);
    printf("Masukkan tipe tugas: ");
    scanf("%s", new_tugas.tipe_tugas);
    printf("Masukkan deadline (DD-MM-YYYY): ");
    scanf("%s", new_tugas.deadline);
    printf("Masukkan status selesai (Ya/Tidak): ");
    scanf("%s", new_tugas.selesai);
    tugas[count++] = new_tugas;
}

void remove_tugas() {
    int id, i, j;
    printf("Masukkan ID tugas yang ingin dihapus: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (tugas[i].id == id) {
            for (j = i; j < count - 1; j++) {
                tugas[j] = tugas[j + 1];
            }
            count--;
            printf("Tugas berhasil dihapus\n");
            return;
        }
    }
    printf("Tugas dengan ID %d tidak ditemukan\n", id);
}

void edit_tugas() {
    int id, i;
    Tugas new_data;
    printf("Masukkan ID tugas yang ingin diedit: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (tugas[i].id == id) {
            printf("Masukkan data baru untuk tugas ini:\n");
            printf("Masukkan judul tugas: ");
            scanf("%s", new_data.judul_tugas);
            printf("Masukkan tipe tugas: ");
            scanf("%s", new_data.tipe_tugas);
            printf("Masukkan deadline (DD-MM-YYYY): ");
            scanf("%s", new_data.deadline);
            printf("Masukkan status selesai (Ya/Tidak): ");
            scanf("%s", new_data.selesai);
            tugas[i] = new_data;
            printf("Tugas berhasil diedit\n");
            return;
        }
    }
    printf("Tugas dengan ID %d tidak ditemukan\n", id);
}

void preview_all_task() {
    int i;
    printf("\n");
    printf("|%-5s|%-15s|%-15s|%-20s|%-10s|\n", "ID", "Judul Tugas", "Tipe Tugas", "Deadline", "Selesai");
    for (i = 0; i < count; i++) {
        printf("|%-5d|%-15s|%-15s|%-20s|%-10s|\n", tugas[i].id, tugas[i].judul_tugas, tugas[i].tipe_tugas, tugas[i].deadline, tugas[i].selesai);
    }
    printf("\n");
}

void search_by_judul_tugas() {
    int i;
    char judul_tugas[50];
    printf("Masukkan judul tugas yang ingin dicari: ");
    scanf("%s", judul_tugas);
    printf("\n");
    printf("|%-5s|%-15s|%-15s|%-20s|%-10s|\n", "ID", "Judul Tugas", "Tipe Tugas", "Deadline", "Selesai");
    for (i = 0; i < count; i++) {
        if (strcmp(tugas[i].judul_tugas, judul_tugas) == 0) {
            printf("|%-5d|%-15s|%-15s|%-20s|%-10s|\n", tugas[i].id, tugas[i].judul_tugas, tugas[i].tipe_tugas, tugas[i].deadline, tugas[i].selesai);
        }
    }
    printf("\n");
}

void search_by_tipe_tugas() {
    int i;
    char tipe_tugas[50];
    printf("Masukkan nama tipe tugas yang ingin dicari: ");
    scanf("%s", tipe_tugas);
    printf("\n");
    printf("|%-5s|%-15s|%-15s|%-20s|%-10s|\n", "ID", "Judul Tugas", "Tipe Tugas", "Deadline", "Selesai");
    for (i = 0; i < count; i++) {
        if (strcmp(tugas[i].tipe_tugas, tipe_tugas) == 0) {
            printf("|%-5d|%-15s|%-15s|%-20s|%-10s|\n", tugas[i].id, tugas[i].judul_tugas, tugas[i].tipe_tugas, tugas[i].deadline, tugas[i].selesai);
        }
    }
    printf("\n");
}

void sort_by_deadline() {
    int i, j;
    Tugas temp;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(tugas[j].deadline, tugas[j + 1].deadline) > 0) {
                temp = tugas[j];
                tugas[j] = tugas[j + 1];
                tugas[j + 1] = temp;
            }
        }
    }
    printf("Tugas berhasil diurutkan berdasarkan deadline\n");
}

void sort_by_judul_tugas() {
    int i, j;
    Tugas temp;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(tugas[j].judul_tugas, tugas[j + 1].judul_tugas) > 0) {
                temp = tugas[j];
                tugas[j] = tugas[j + 1];
                tugas[j + 1] = temp;
            }
        }
    }
    printf("Tugas berhasil diurutkan berdasarkan judul tugas\n");
}

void sort_by_selesai() {
    int i, j;
    Tugas temp;
    char status[5];
    printf("Masukkan status (selesai/belum): ");
    scanf("%s", status);
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(status, "selesai") == 0) {
                if (strcmp(tugas[j].selesai, "Tidak") == 0) {
                    temp = tugas[j];
                    tugas[j] = tugas[j + 1];
                    tugas[j + 1] = temp;
                }
            } else if (strcmp(status, "belum") == 0) {
                if (strcmp(tugas[j].selesai, "Ya") == 0) {
                    temp = tugas[j];
                    tugas[j] = tugas[j + 1];
                    tugas[j + 1] = temp;
                }
            }
        }
    }
    printf("Tugas berhasil diurutkan berdasarkan status selesai\n");
}

void main() {
    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Tambah Tugas\n");
        printf("2. Hapus Tugas\n");
        printf("3. Edit Tugas\n");
        printf("4. Preview Semua Tugas\n");
        printf("5. Cari Tugas berdasarkan Judul\n");
        printf("6. Cari Tugas berdasarkan Tipe\n");
        printf("7. Urutkan berdasarkan Deadline\n");
        printf("8. Urutkan berdasarkan Judul\n");
        printf("9. Urutkan berdasarkan Selesai\n");
        printf("10. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_tugas();
                break;
            case 2:
                remove_tugas();
                break;
            case 3:
                edit_tugas();
                break;
            case 4:
                preview_all_task();
                break;
            case 5:
                search_by_judul_tugas();
                break;
            case 6:
                search_by_tipe_tugas();
                break;
            case 7:
                sort_by_deadline();
                break;
            case 8:
                sort_by_judul_tugas();
                break;
            case 9:
                sort_by_selesai();
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("Pilihan tidak valid\n");
        }
    }
}
