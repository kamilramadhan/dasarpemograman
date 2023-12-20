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

typedef struct {
    int id;
    char nama_transaksi[50];
    char jenis_transaksi[10];
    float jumlah;
    char tanggal[20];
    float sisa_saldo;
} Tabungan;

typedef struct {
    int id;
    char nama_teman[50];
    int umur;
    char tanggal_lahir[20];
    char asal_kota[50];
    char masih_berteman[3];
} Teman;

typedef struct {
    int id;
    char nama_produk[50];
    float harga;
    char kadaluarsa[20];
    int stok;
    char jenis_produk[50];
} Produk;

Tabungan tabungan[100];
int count_tabungan = 0;

Teman daftar_teman[100];
int count_teman = 0;

Produk daftar_produk[100];
int count_produk = 0;

Tugas tugas[100];
int count_tugas = 0;

void savekefiletask(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error bro\n");
        return;
    }

    for (int i = 0; i < count_tugas; i++) {
        fprintf(file, "%d,%s,%s,%s,%s\n", tugas[i].id, tugas[i].judul_tugas, tugas[i].tipe_tugas, tugas[i].deadline, tugas[i].selesai);
    }

    fclose(file);
    printf("File berhasil tersimpan di %s\n", filename);
}
void loadfiletask(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }

    count_tugas = 0;
    while (fscanf(file, "%d,%49[^,],%19[^,],%19[^,],%9[^\n]\n",
                  &tugas[count_tugas].id, tugas[count_tugas].judul_tugas, tugas[count_tugas].tipe_tugas, tugas[count_tugas].deadline, tugas[count_tugas].selesai) == 5) {
        count_tugas++;
        if (count_tugas >= 100) {
            printf("Terlalu banyak task, hanya menampilkan 100 task\n");
            break;
        }
    }

    fclose(file);
    printf("Tasks successfully loaded from %s\n", filename);
}

void savekefiletabungan(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error bro\n");
        return;
    }

    for (int i = 0; i < count_tabungan; i++) {
        fprintf(file, "%d,%s,%s,%.2f,%s,%.2f\n", tabungan[i].id, tabungan[i].nama_transaksi, tabungan[i].jenis_transaksi,
                tabungan[i].jumlah, tabungan[i].tanggal, tabungan[i].sisa_saldo);
    }

    fclose(file);
    printf("File tabungan berhasil tersimpan di %s\n", filename);
}
void loadfiletabungan(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }

    count_tabungan = 0;
    while (fscanf(file, "%d,%49[^,],%9[^,],%f,%19[^,],%f\n",
                  &tabungan[count_tabungan].id, tabungan[count_tabungan].nama_transaksi, tabungan[count_tabungan].jenis_transaksi,
                  &tabungan[count_tabungan].jumlah, tabungan[count_tabungan].tanggal, &tabungan[count_tabungan].sisa_saldo) == 6) {
        count_tabungan++;
        if (count_tabungan >= 100) {
            printf("Terlalu banyak transaksi, hanya menampilkan 100 transaksi\n");
            break;
        }
    }

    fclose(file);
    printf("Transaksi successfully loaded from %s\n", filename);
}

void savekefileteman(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error bro\n");
        return;
    }

    for (int i = 0; i < count_teman; i++) {
        fprintf(file, "%d,%s,%d,%s,%s,%s\n", daftar_teman[i].id, daftar_teman[i].nama_teman, daftar_teman[i].umur,
                daftar_teman[i].tanggal_lahir, daftar_teman[i].asal_kota, daftar_teman[i].masih_berteman);
    }

    fclose(file);
    printf("File daftar teman berhasil tersimpan di %s\n", filename);
}
void loadfileteman(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }

    count_teman = 0;
    while (fscanf(file, "%d,%49[^,],%d,%19[^,],%49[^,],%3[^\n]\n",
                  &daftar_teman[count_teman].id, daftar_teman[count_teman].nama_teman, &daftar_teman[count_teman].umur,
                  daftar_teman[count_teman].tanggal_lahir, daftar_teman[count_teman].asal_kota, daftar_teman[count_teman].masih_berteman) == 6) {
        count_teman++;
        if (count_teman >= 100) {
            printf("Terlalu banyak teman, hanya menampilkan 100 teman\n");
            break;
        }
    }

    fclose(file);
    printf("Teman successfully loaded from %s\n", filename);
}

void savekefileproduk(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error bro\n");
        return;
    }

    for (int i = 0; i < count_produk; i++) {
        fprintf(file, "%d,%s,%.2f,%s,%d,%s\n", daftar_produk[i].id, daftar_produk[i].nama_produk, daftar_produk[i].harga,
                daftar_produk[i].kadaluarsa, daftar_produk[i].stok, daftar_produk[i].jenis_produk);
    }

    fclose(file);
    printf("File daftar harga produk berhasil tersimpan di %s\n", filename);
}
void loadfileproduk(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }

    count_produk = 0;
    while (fscanf(file, "%d,%49[^,],%f,%19[^,],%d,%49[^\n]\n",
                  &daftar_produk[count_produk].id, daftar_produk[count_produk].nama_produk, &daftar_produk[count_produk].harga,
                  daftar_produk[count_produk].kadaluarsa, &daftar_produk[count_produk].stok, daftar_produk[count_produk].jenis_produk) == 6) {
        count_produk++;
        if (count_produk >= 100) {
            printf("Terlalu banyak produk, hanya menampilkan 100 produk\n");
            break;
        }
    }

    fclose(file);
    printf("Produk successfully loaded from %s\n", filename);
}
//pilihan create
void add_tugas() {
    Tugas new_tugas;
    new_tugas.id = count_tugas + 1;
    printf("Masukkan judul tugas: ");
    scanf("%s", new_tugas.judul_tugas);
    printf("Masukkan tipe tugas: ");
    scanf("%s", new_tugas.tipe_tugas);
    printf("Masukkan deadline (DD-MM-YYYY): ");
    scanf("%s", new_tugas.deadline);
    printf("Masukkan status selesai (Y/N): ");
    scanf("%s", new_tugas.selesai);
    tugas[count_tugas++] = new_tugas;
}
void add_tabungan() {
    Tabungan new_tabungan;
    new_tabungan.id = count_tabungan + 1;
    printf("Masukkan nama transaksi: ");
    scanf("%s", new_tabungan.nama_transaksi);
    printf("Masukkan jenis transaksi (kredit/debit): ");
    scanf("%s", new_tabungan.jenis_transaksi);
    printf("Masukkan jumlah: ");
    scanf("%f", &new_tabungan.jumlah);
    printf("Masukkan tanggal (DD-MM-YYYY): ");
    scanf("%s", new_tabungan.tanggal);
    printf("Masukkan sisa saldo: ");
    scanf("%f", &new_tabungan.sisa_saldo);
    tabungan[count_tabungan++] = new_tabungan;
}
void add_teman() {
    Teman new_teman;
    new_teman.id = count_teman + 1;
    printf("Masukkan nama teman: ");
    scanf("%s", new_teman.nama_teman);
    printf("Masukkan umur teman: ");
    scanf("%d", &new_teman.umur);
    printf("Masukkan tanggal lahir teman (DD-MM-YYYY): ");
    scanf("%s", new_teman.tanggal_lahir);
    printf("Masukkan asal kota teman: ");
    scanf("%s", new_teman.asal_kota);
    printf("Masukkan masih berteman atau tidak (Y/N): ");
    scanf("%s", new_teman.masih_berteman);
    daftar_teman[count_teman++] = new_teman;
}
void add_produk() {
    Produk new_produk;
    new_produk.id = count_produk + 1;
    printf("Masukkan nama produk: ");
    scanf("%s", new_produk.nama_produk);
    printf("Masukkan harga produk: ");
    scanf("%f", &new_produk.harga);
    printf("Masukkan tanggal kadaluarsa (DD-MM-YYYY): ");
    scanf("%s", new_produk.kadaluarsa);
    printf("Masukkan stok produk: ");
    scanf("%d", &new_produk.stok);
    printf("Masukkan jenis produk: ");
    scanf("%s", new_produk.jenis_produk);
    daftar_produk[count_produk++] = new_produk;
}
//pilihan delete
void remove_tugas() {
    int id, i, j;
    printf("Masukkan ID tugas yang ingin dihapus: ");
    scanf("%d", &id);
    for (i = 0; i < count_tugas; i++) {
        if (tugas[i].id == id) {
            for (j = i; j < count_tugas - 1; j++) {
                tugas[j] = tugas[j + 1];
            }
            count_tugas--;
            printf("Tugas berhasil dihapus\n");
            return;
        }
    }
    printf("Tugas dengan ID %d tidak ditemukan\n", id);
}
void remove_tabungan() {
    int id, i, j;
    printf("Masukkan ID transaksi yang ingin dihapus: ");
    scanf("%d", &id);
    for (i = 0; i < count_tabungan; i++) {
        if (tabungan[i].id == id) {
            for (j = i; j < count_tabungan - 1; j++) {
                tabungan[j] = tabungan[j + 1];
            }
            count_tabungan--;
            printf("Transaksi berhasil dihapus\n");
            return;
        }
    }
    printf("Transaksi dengan ID %d tidak ditemukan\n", id);
}
void remove_teman() {
    int id, i, j;
    printf("Masukkan ID teman yang ingin dihapus: ");
    scanf("%d", &id);
    for (i = 0; i < count_teman; i++) {
        if (daftar_teman[i].id == id) {
            for (j = i; j < count_teman - 1; j++) {
                daftar_teman[j] = daftar_teman[j + 1];
            }
            count_teman--;
            printf("Teman berhasil dihapus\n");
            return;
        }
    }
    printf("Teman dengan ID %d tidak ditemukan\n", id);
}
void remove_produk() {
    int id, i, j;
    printf("Masukkan ID produk yang ingin dihapus: ");
    scanf("%d", &id);
    for (i = 0; i < count_produk; i++) {
        if (daftar_produk[i].id == id) {
            for (j = i; j < count_produk - 1; j++) {
                daftar_produk[j] = daftar_produk[j + 1];
            }
            count_produk--;
            printf("Produk berhasil dihapus\n");
            return;
        }
    }
    printf("Produk dengan ID %d tidak ditemukan\n", id);
}
//pilihan update
void edit_tugas() {
    int id, i;
    Tugas new_data;
    printf("Masukkan ID tugas yang ingin diedit: ");
    scanf("%d", &id);
    for (i = 0; i < count_tugas; i++) {
        if (tugas[i].id == id) {
            printf("Masukkan data baru untuk tugas ini:\n");
            new_data.id = id;
            printf("Masukkan judul tugas: ");
            scanf("%s", new_data.judul_tugas);
            printf("Masukkan tipe tugas: ");
            scanf("%s", new_data.tipe_tugas);
            printf("Masukkan deadline (DD-MM-YYYY): ");
            scanf("%s", new_data.deadline);
            printf("Masukkan status selesai (Y/N): ");
            scanf("%s", new_data.selesai);
            tugas[i] = new_data;
            printf("Tugas berhasil diedit\n");
            return;
        }
    }
    printf("Tugas dengan ID %d tidak ditemukan\n", id);
}
void edit_tabungan() {
    int id, i;
    Tabungan new_data;
    printf("Masukkan ID transaksi yang ingin diupdate: ");
    scanf("%d", &id);
    for (i = 0; i < count_tabungan; i++) {
        if (tabungan[i].id == id) {
            printf("Masukkan data baru untuk transaksi ini:\n");
            new_data.id = id;
            printf("Masukkan nama transaksi: ");
            scanf("%s", new_data.nama_transaksi);
            printf("Masukkan jenis transaksi (kredit/debit): ");
            scanf("%s", new_data.jenis_transaksi);
            printf("Masukkan jumlah: ");
            scanf("%f", &new_data.jumlah);
            printf("Masukkan tanggal (DD-MM-YYYY): ");
            scanf("%s", new_data.tanggal);
            printf("Masukkan sisa saldo: ");
            scanf("%f", &new_data.sisa_saldo);
            tabungan[i] = new_data;
            printf("Transaksi berhasil diupdate\n");
            return;
        }
    }
    printf("Transaksi dengan ID %d tidak ditemukan\n", id);
}
void edit_teman() {
    int id, i;
    Teman new_data;
    printf("Masukkan ID teman yang ingin diedit: ");
    scanf("%d", &id);
    for (i = 0; i < count_teman; i++) {
        if (daftar_teman[i].id == id) {
            printf("Masukkan data baru untuk teman ini:\n");
            new_data.id = id;
            printf("Masukkan nama teman: ");
            scanf("%s", new_data.nama_teman);
            printf("Masukkan umur teman: ");
            scanf("%d", &new_data.umur);
            printf("Masukkan tanggal lahir teman (DD-MM-YYYY): ");
            scanf("%s", new_data.tanggal_lahir);
            printf("Masukkan asal kota teman: ");
            scanf("%s", new_data.asal_kota);
            printf("Masukkan masih berteman atau tidak (Y/N): ");
            scanf("%s", new_data.masih_berteman);
            daftar_teman[i] = new_data;
            printf("Teman berhasil diedit\n");
            return;
        }
    }
    printf("Teman dengan ID %d tidak ditemukan\n", id);
}
void edit_produk() {
    int id, i;
    Produk new_data;
    printf("Masukkan ID produk yang ingin diedit: ");
    scanf("%d", &id);
    for (i = 0; i < count_produk; i++) {
        if (daftar_produk[i].id == id) {
            printf("Masukkan data baru untuk produk ini:\n");
            new_data.id = id;
            printf("Masukkan nama produk: ");
            scanf("%s", new_data.nama_produk);
            printf("Masukkan harga produk: ");
            scanf("%f", &new_data.harga);
            printf("Masukkan tanggal kadaluarsa (DD-MM-YYYY): ");
            scanf("%s", new_data.kadaluarsa);
            printf("Masukkan stok produk: ");
            scanf("%d", &new_data.stok);
            printf("Masukkan jenis produk: ");
            scanf("%s", new_data.jenis_produk);
            daftar_produk[i] = new_data;
            printf("Produk berhasil diedit\n");
            return;
        }
    }
    printf("Produk dengan ID %d tidak ditemukan\n", id);
}
//pilihan read
void preview_all_task() {
    int i;
    printf("\n");
    printf("|%-3s|%-15s|%-15s|%-10s|%-10s|\n", "ID", "Judul Tugas", "Tipe Tugas", "Deadline", "Selesai");
    for (i = 0; i < count_tugas; i++) {
        printf("|%-3d|%-15s|%-15s|%-10s|%-10s|\n", tugas[i].id, tugas[i].judul_tugas, tugas[i].tipe_tugas, tugas[i].deadline, tugas[i].selesai);
    }
    printf("\n");
}
void preview_all_tabungan() {
    int i;
    printf("\n");
    printf("|%-3s|%-15s|%-15s|%-10s|%-10s|%-10s|\n", "ID", "Transaksi", "Kredit/Debit", "Jumlah", "Tanggal", "Sisa Saldo");
    for (i = 0; i < count_tabungan; i++) {
        printf("|%-3d|%-15s|%-15s|%-10.2f|%-10s|%-10.2f|\n", tabungan[i].id, tabungan[i].nama_transaksi, tabungan[i].jenis_transaksi,
               tabungan[i].jumlah, tabungan[i].tanggal, tabungan[i].sisa_saldo);
    }
    printf("\n");
}
void preview_all_teman() {
    int i;
    printf("\n");
    printf("|%-3s|%-15s|%-5s|%-15s|%-15s|%-5s|\n", "ID", "Nama Teman", "Umur", "Tanggal Lahir", "Asal Kota", "Berteman");
    for (i = 0; i < count_teman; i++) {
        printf("|%-3d|%-15s|%-5d|%-15s|%-15s|%-5s|\n", daftar_teman[i].id, daftar_teman[i].nama_teman, daftar_teman[i].umur,
               daftar_teman[i].tanggal_lahir, daftar_teman[i].asal_kota, daftar_teman[i].masih_berteman);
    }
    printf("\n");
}
void preview_all_produk() {
    int i;
    printf("\n");
    printf("|%-3s|%-15s|%-10s|%-15s|%-5s|%-15s|\n", "ID", "Nama Produk", "Harga", "Kadaluarsa", "Stok", "Jenis Produk");
    for (i = 0; i < count_produk; i++) {
        printf("|%-3d|%-15s|%-10.2f|%-15s|%-5d|%-15s|\n", daftar_produk[i].id, daftar_produk[i].nama_produk, daftar_produk[i].harga,
               daftar_produk[i].kadaluarsa, daftar_produk[i].stok, daftar_produk[i].jenis_produk);
    }
    printf("\n");
}

//di bawah ini punyanya si task/tugas saja heheh
void search_by_judul_tugas() {
    int i;
    char judul_tugas[50];
    printf("Masukkan judul tugas yang ingin dicari: ");
    scanf("%s", judul_tugas);
    printf("\n");
    printf("|%-3s|%-15s|%-15s|%-10s|%-10s|\n", "ID", "Judul Tugas", "Tipe Tugas", "Deadline", "Selesai");
    for (i = 0; i < count_tugas; i++) {
        if (strcmp(tugas[i].judul_tugas, judul_tugas) == 0) {
            printf("|%-3d|%-15s|%-15s|%-10s|%-10s|\n", tugas[i].id, tugas[i].judul_tugas, tugas[i].tipe_tugas, tugas[i].deadline, tugas[i].selesai);
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
    printf("|%-3s|%-15s|%-15s|%-10s|%-10s|\n", "ID", "Judul Tugas", "Tipe Tugas", "Deadline", "Selesai");
    for (i = 0; i < count_tugas; i++) {
        if (strcmp(tugas[i].tipe_tugas, tipe_tugas) == 0) {
            printf("|%-3d|%-15s|%-15s|%-10s|%-10s|\n", tugas[i].id, tugas[i].judul_tugas, tugas[i].tipe_tugas, tugas[i].deadline, tugas[i].selesai);
        }
    }
    printf("\n");
}
int dmy(char* date1, char* date2) {
    int d1, m1, y1, d2, m2, y2;
    sscanf(date1, "%d-%d-%d", &d1, &m1, &y1);
    sscanf(date2, "%d-%d-%d", &d2, &m2, &y2);
    if (y1 != y2)
        return y1 - y2;
    else if (m1 != m2)
        return m1 - m2;
    else
        return d1 - d2;
}
void sort_by_deadline() {
    int i, j;
    Tugas temp;
    for (i = 0; i < count_tugas - 1; i++) {
        for (j = 0; j < count_tugas - i - 1; j++) {
            if (dmy(tugas[j].deadline, tugas[j + 1].deadline) > 0) {
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
    for (i = 0; i < count_tugas - 1; i++) {
        for (j = 0; j < count_tugas - i - 1; j++) {
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
    for (i = 0; i < count_tugas - 1; i++) {
        for (j = 0; j < count_tugas - i - 1; j++) {
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

//pilihan menu
void taskmain() {
    loadfiletask("listtask.txt");
    int choice;
    while (1) {
        printf("Menu Data Tugas:\n");
        printf("1. Buat Tugas\n");
        printf("2. Hapus Tugas\n");
        printf("3. Update Tugas\n");
        printf("4. Lihat Semua Tugas\n");
        printf("5. Cari Tugas berdasarkan Judul\n");
        printf("6. Cari Tugas berdasarkan Tipe\n");
        printf("7. Urutkan berdasarkan Deadline\n");
        printf("8. Urutkan berdasarkan Judul\n");
        printf("9. Urutkan berdasarkan Selesai\n");
        printf("10. Keluar dan simpan file\n");
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
                savekefiletask("listtask.txt");
                main();
                break;
            default:
                printf("Pilihan tidak valid\n");
        }
    }
}
void tabunganmain() {
    loadfiletabungan("tabungan.txt");
    int choice;
    while (1) {
        printf("Menu Data Tabungan:\n");
        printf("1. Buat transaksi\n");
        printf("2. Hapus transaksi\n");
        printf("3. Update transaksi\n");
        printf("4. Lihat semua transaksi\n");
        printf("5. Keluar dan simpan\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_tabungan();
                break;
            case 2:
                remove_tabungan();
                break;
            case 3:
                edit_tabungan();
                break;
            case 4:
                preview_all_tabungan();
                break;
            case 5:
                savekefiletabungan("tabungan.txt");
                main();
                break;
            default:
                printf("Pilihan tidak valid\n");
        }
    }
}
void temanmain() {
    loadfileteman("daftar_teman.txt");
    int choice;
    while (1) {
        printf("Menu Data Teman:\n");
        printf("1. Tambah Teman\n");
        printf("2. Hapus Teman\n");
        printf("3. Edit Teman\n");
        printf("4. Lihat Semua Teman\n");
        printf("5. Keluar dan Simpan\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_teman();
                break;
            case 2:
                remove_teman();
                break;
            case 3:
                edit_teman();
                break;
            case 4:
                preview_all_teman();
                break;
            case 5:
                savekefileteman("daftar_teman.txt");
                main();
                break;
            default:
                printf("Pilihan tidak valid\n");
        }
    }
}
void produkmain() {
    loadfileproduk("daftar_produk.txt");
    int choice;
    while (1) {
        printf("Menu Data Produk:\n");
        printf("1. Tambah Produk\n");
        printf("2. Hapus Produk\n");
        printf("3. Edit Produk\n");
        printf("4. Lihat Semua Produk\n");
        printf("5. Keluar dan Simpan\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_produk();
                break;
            case 2:
                remove_produk();
                break;
            case 3:
                edit_produk();
                break;
            case 4:
                preview_all_produk();
                break;
            case 5:
                savekefileproduk("daftar_produk.txt");
                main();
                break;
            default:
                printf("Pilihan tidak valid\n");
        }
    }
}

void main(){
    int choice;
    while (1) {
        printf("Pilih Menu Data:\n");
        printf("1. Tugas\n");
        printf("2. Tabungan\n");
        printf("3. Teman\n");
        printf("4. Produk\n");
        printf("Masukkan pilihan: ");
        scanf("%d",&choice);
        switch (choice) {
        case 1:
            taskmain();
            break;
        case 2:
            tabunganmain();
            break;
        case 3:
            temanmain();
            break;
        case 4:
            produkmain();
            break;
        default:
            printf("Pilihan tidak valid\n");
    }
    }

}
