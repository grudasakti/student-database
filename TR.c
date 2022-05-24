#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

struct mahasiswa{
    int nim, angkatan;
    char nama[50], progdi[50];
    float ipk;
    struct mahasiswa *next;
}*head, *tail, *current;

struct riwayat{
    char aktivitas[50];
    struct riwayat *selanjutnya;
}*kepala, *akhir, *sekarang;

insertData(int nimMhs, char namaMhs[50], float ipkMhs, char progdiMhs[50], int angkatanMhs){
    current = (struct mahasiswa*)malloc(sizeof(struct mahasiswa));
    current->nim = nimMhs;
    strcpy(current->nama, namaMhs);
    current->ipk = ipkMhs;
    strcpy(current->progdi, progdiMhs);
    current->angkatan = angkatanMhs;

    if(head==NULL){
        head = tail = current;
    }else{
        tail->next = current;
        tail = current;
    }
    tail->next = NULL;
}

insertRiwayat(char aktivitasAdmin[50]){
    sekarang = (struct riwayat*)malloc(sizeof(struct riwayat));
    strcpy(sekarang->aktivitas, aktivitasAdmin);

    if(kepala==NULL){
        kepala = akhir = sekarang;
    }else{
        akhir->selanjutnya = sekarang;
        akhir = sekarang;
    }
    akhir->selanjutnya = NULL;
}

int searchNim(int nimMhs){
    current = head;
    while(current!=NULL){
        if(current->nim==nimMhs){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int searchNama(char cariNama[50]){
    current = head;
    while(current!=NULL){
        if(strcmp(current->nama,cariNama)==0){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int searchIPK(float cariIPK){
    current = head;
    while(current!=NULL){
        if(current->ipk==cariIPK){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int searchProgdi(char cariProgdi[50]){
    current = head;
    while(current!=NULL){
        if(strcmp(current->progdi,cariProgdi)==0){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int searchAngkatan(int cariAngkatan){
    current = head;
    while(current!=NULL){
        if(current->angkatan==cariAngkatan){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

updateNama(int nimMhs, char namaMhs[50]){
    current = head;
    while(current!=NULL){
        if(current->nim==nimMhs){
            strcpy(current->nama, namaMhs);
        }
        current = current->next;
    }
}

updateIPK(int nimMhs, float ipkMhs){
    current = head;
    while(current!=NULL){
        if(current->nim==nimMhs){
            current->ipk = ipkMhs;
        }
        current = current->next;
    }
}

updateProgdi(int nimMhs, char progdiMhs[50]){
    current = head;
    while(current!=NULL){
        if(current->nim==nimMhs){
            strcpy(current->progdi, progdiMhs);
        }
        current = current->next;
    }
}

updateAngkatan(int nimMhs, int angkatanMhs){
    current = head;
    while(current!=NULL){
        if(current->nim==nimMhs){
            current->angkatan = angkatanMhs;
        }
        current = current->next;
    }
}

hapusKepala(){
    current = head;
    if(head==tail){
        head = tail = NULL;
        free(current);
    }else{
        head = head->next;
        free(current);
    }
}

hapusAkhir(){
    if(head==tail){
        head = tail = NULL;
        free(current);
    }else{
        struct mahasiswa *temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        current = tail;
        tail = temp;
        free(current);
        tail->next = NULL;
    }
}

hapusNim(int nimMhs){
    if(head->nim==nimMhs){
        hapusKepala();
    }else if(tail->nim==nimMhs){
        hapusAkhir();
    }else {
        struct mahasiswa *temp = head;
        while(temp->next->nim!=nimMhs && temp!=tail){
            temp = temp->next;
        }
        current = temp->next;
        temp->next = temp->next->next;
        free(current);
    }
}

hapusSemua(){
    while(head!=NULL){
        hapusKepala();
    }
}

void sortNIM(){
    int temp;

    current = head;
    while(current!=NULL){
        tail = current->next;
        while(tail!=NULL){
            if(current->nim > tail->nim){
                temp = current->nim;
                current->nim = tail->nim;
                tail->nim = temp;
            }
        tail = tail->next;
        }
    current = current->next;
    }
}

void sortNama(){
    char temp[50];

    current = head;
    while(current!=NULL){
        tail = current->next;
        while(tail!=NULL){
            if(strcmp(current->nama,tail->nama)>0){
                strcpy(temp, current->nama);
                strcpy(current->nama, tail->nama);
                strcpy(tail->nama, temp);
            }
        tail = tail->next;
        }
    current = current->next;
    }
}

void sortIPK(){
    float temp;

    current = head;
    while(current!=NULL){
        tail = current->next;
        while(tail!=NULL){
            if(current->ipk > tail->ipk){
                temp = current->ipk;
                current->ipk = tail->ipk;
                tail->ipk = temp;
            }
        tail = tail->next;
        }
    current = current->next;
    }
}

void sortProgdi(){
    char temp[50];

    current = head;
    while(current!=NULL){
        tail = current->next;
        while(tail!=NULL){
            if(strcmp(current->progdi,tail->progdi)>0){
                strcpy(temp, current->progdi);
                strcpy(current->progdi, tail->progdi);
                strcpy(tail->progdi, temp);
            }
        tail = tail->next;
        }
    current = current->next;
    }
}

void sortAngkatan(){
    int temp;

    current = head;
    while(current!=NULL){
        tail = current->next;
        while(tail!=NULL){
            if(current->angkatan > tail->angkatan){
                temp = current->angkatan;
                current->angkatan = tail->angkatan;
                tail->angkatan = temp;
            }
        tail = tail->next;
        }
    current = current->next;
    }
}

void tampil(){
    int baris=9;

    gotoxy(24,2);printf("+==================================================================================+");
    gotoxy(48,4);printf("----:::: Database Mahasiswa ::::----\n");
    gotoxy(24,6);printf("+==================================================================================+");
    printf("\n\t\t\t NIM\t\tNama Lengkap\t\tIPK\tProgram Studi\t\tAngkatan");
    printf("\n\t\t\t+----------------------------------------------------------------------------------+");

    current = head;
    if(head==NULL){
        printf("\n\t\t\t\t\t\t      ---- Tidak ada data ----");
    }
    while(current!=NULL){
        gotoxy(25,baris);printf("%i", current->nim);
        gotoxy(40,baris);printf("%s", current->nama);
        gotoxy(64,baris);printf("%.1f", current->ipk);
        gotoxy(72,baris);printf("%s", current->progdi);
        gotoxy(96,baris);printf("%i", current->angkatan);
        current = current->next;
        baris++;
    }
    printf("\n\t\t\t+----------------------------------------------------------------------------------+\n");
}

void tampilRiwayat(){
    int nomer=1;

    gotoxy(32,2);printf("+===========================================================================+");
    gotoxy(65,4);printf("MENU 7");
    gotoxy(52,5);printf("=== RIWAYAT AKTIVITAS YANG DILAKUKAN ===");
    gotoxy(32,7);printf("+---------------------------------------------------------------------------+");
    printf("\n\t\t\t\t  NO.\t\tAKTIVITAS");
    printf("\n\t\t\t\t+---------------------------------------------------------------------------+");

    sekarang = kepala;
    if(kepala==NULL){
        printf("\n\n\t\t\t\t\t\t      ---- Tidak ada data ----");
    }
    while(sekarang!=NULL){
        printf("\n\t\t\t\t  %i.\t\t%s", nomer, sekarang->aktivitas);
        sekarang = sekarang->selanjutnya;
        nomer++;
    }
}

void login() {
	char username[20], password[20];

	struct tm *Sys_T;
    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);

	system("cls");
   	gotoxy(45,10);printf("SELAMAT DATANG DI DATABASE MAHASISWA");
   	gotoxy(43,12);printf("=========================================");
   	gotoxy(43,16);printf("=========================================");
    gotoxy(45,17);printf("%s\t\t  %s",__DATE__, __TIME__);
    gotoxy(45,13);printf("Masukkan Username\t\t: ");
    gets(username);
    gotoxy(45,15);printf("Masukkan Password\t\t: ");

    char ch;
    int i = 0;
    while((ch=(char) _getch()) != '\r'){
        password[i]=ch;
        printf("*");
        i++;
    }

	if(strcmp(username,"admin")== 0){
		if(strcmp(password,"admin")== 0){
            gotoxy(57,19);printf("Login Success!");
            gotoxy(52,22);printf("Klik terserah untuk lanjut");
            getch();
            menu_utama();
		}else{
            gotoxy(54,19);printf("Password Salah!\n");
            getch();
            login();
		}
	}else{
		gotoxy(54,19);printf("Username Salah!\n");
		getch();
		login();
	}
}

void menu_utama (){
    int menu=1, n=0, m, nimMhs, angkatanMhs, edit, pilih, cariNim, cariAngkatan, temp, baris=18;
    char namaMhs[50], progdiMhs[50], hapus, cariNama[50], cariProgdi[50], aktivitasAdmin[50];
    float ipkMhs, cariIPK;

    char text1[]="SELAMAT DATANG DI DATABASE MAHASISWA";
    char text2[]="AUTHOR";
    char text3[]="GRUDA SAKTI KRIDA PRASTYA";
    char text4[]="672019252";
    char text5[]="Thanks for using this database...";

    pilihan:
    setcolor(112);
    while(menu!=9){
        system("cls");
        gotoxy(32,3);printf("+========================================================+");
        printf("\n\n\t\t\t\t\t    ");
        for(int x=0; text1[x]!=NULL; x++){
            printf("%c", text1[x]);
            for(int y=0; y<=8888888; y++);
        }

        gotoxy(46,6);printf("=== MENU DATABASE MAHASISWA ===");
        printf("\n\n\t\t\t\t+--------------------------------------------------------+");
        printf("\n\n\t\t\t\t|                                                        |");
        printf("\n\t\t\t\t|  Tekan 1. Membuat database mahasiswa                   |");
        printf("\n\t\t\t\t|  Tekan 2. Menampilkan isi database mahasiswa           |");
        printf("\n\t\t\t\t|  Tekan 3. Menambahkan data baru ke database mahasiswa  |");
        printf("\n\t\t\t\t|  Tekan 4. Menghapus data di database mahasiswa         |");
        printf("\n\t\t\t\t|  Tekan 5. Mengedit data di database mahasiswa          |");
        printf("\n\t\t\t\t|  Tekan 6. Mencari data di database mahasiswa           |");
        printf("\n\t\t\t\t|  Tekan 7. Riwayat aktivitas                            |");
        printf("\n\t\t\t\t|  Tekan 8. Mengurutkan data di database mahasiswa       |");
        printf("\n\t\t\t\t|  Tekan 9. Keluar dari program                          |");
        printf("\n\t\t\t\t|                                                        |");
        gotoxy(32,23);printf("+========================================================+");
        gotoxy(32,21);printf("|  Masukkan pilihan Anda :                               |");
        gotoxy(59,21);scanf("%i", &menu);

        switch(menu){
        case 1:
            menu1:
            setcolor(79);
            hapusSemua();
            system("cls");
            gotoxy(30,2);printf("+=================================================================+");
            gotoxy(63,4);printf("MENU 1");
            gotoxy(50,5);printf("=== MEMBUAT DATABASE MAHASISWA ===");
            gotoxy(30,7);printf("+-----------------------------------------------------------------+");
            gotoxy(45,8);printf("Data maksimum yang bisa diinput\t: 5");
            gotoxy(30,10);printf("+=================================================================+");
            gotoxy(45,9);printf("Banyak data yang ingin diinput\t: ");
            scanf("%i", &n);

            if(n>5){
                gotoxy(58,12);printf("Maksimal 5 gan");
                getch();
                goto menu1;
            }else{
                for(int i=0; i<n; i++){
                    printf("\n\t\t\t\t\t    ::DATA MAHASISWA KE-%i", i+1);
                    fflush(stdin);
                    printf("\n\t\t\t\t\t    ::NIM                 : ");
                    scanf("%i", &nimMhs);
                    fflush(stdin);
                    printf("\t\t\t\t\t    ::Nama Lengkap        : ");
                    gets(namaMhs);
                    printf("\t\t\t\t\t    ::IPK                 : ");
                    scanf("%f",&ipkMhs);
                    fflush(stdin);
                    printf("\t\t\t\t\t    ::Program Studi       : ");
                    gets(progdiMhs);
                    printf("\t\t\t\t\t    ::Angkatan            : ");
                    scanf("%i", &angkatanMhs);
                    fflush(stdin);
                    insertData(nimMhs, namaMhs, ipkMhs, progdiMhs, angkatanMhs);
                }
                sprintf(aktivitasAdmin,"Admin menambahkan %i data", n);
                insertRiwayat(aktivitasAdmin);
            }
            printf("\n\t\t\t\t\t\tTekan apa saja untuk kembali ke menu");
            getch();
            goto pilihan;
            break;

        case 2:
            setcolor(3);
            system("cls");
            insertRiwayat("Admin melihat data");
            tampil();
            printf("\n\t\t\t\t\t\tTekan apa saja untuk kembali ke menu");
            getch();
            goto pilihan;
            break;

        case 3:
            menu3:
            setcolor(30);
            system("cls");
            gotoxy(30,2);printf("+=================================================================+");
            gotoxy(63,4);printf("MENU 3");
            gotoxy(50,5);printf("=== MENAMBAHKAN DATA MAHASISWA ===");
            gotoxy(30,7);printf("+-----------------------------------------------------------------+");
            gotoxy(45,8);printf("Data maksimum yang bisa diinput\t: 4");
            gotoxy(30,10);printf("+=================================================================+");
            gotoxy(45,9);printf("Banyak data yang ingin diinput\t: ");
            scanf("%i", &m);

            current = head;
            if(head==NULL){
                printf("\n\n\t\t\t\t    ---- Silahkan buat database terlebih dahulu di Menu 1 ----\n");
            }else{
                if(m>4){
                    gotoxy(58,12);printf("Maksimal 4 gan");
                    getch();
                    goto menu3;
                }else{
                    for(int i=0; i<m; i++){
                        printf("\n\t\t\t\t\t    ::DATA MAHASISWA KE-%i", n+1);
                        fflush(stdin);
                        printf("\n\t\t\t\t\t    ::NIM                 : ");
                        scanf("%i", &nimMhs);
                        fflush(stdin);
                        printf("\t\t\t\t\t    ::Nama Lengkap        : ");
                        gets(namaMhs);
                        printf("\t\t\t\t\t    ::IPK                 : ");
                        scanf("%f",&ipkMhs);
                        fflush(stdin);
                        printf("\t\t\t\t\t    ::Program Studi       : ");
                        gets(progdiMhs);
                        printf("\t\t\t\t\t    ::Angkatan            : ");
                        scanf("%i", &angkatanMhs);
                        fflush(stdin);
                        insertData(nimMhs, namaMhs, ipkMhs, progdiMhs, angkatanMhs);
                    }
                    sprintf(aktivitasAdmin,"Admin menambahkan %i data", m);
                    insertRiwayat(aktivitasAdmin);
                }
            }
            printf("\n\t\t\t\t\t\tTekan apa saja untuk kembali ke menu");
            getch();
            goto pilihan;
            break;

        case 4:
            setcolor(48);
            system("cls");
            gotoxy(30,2);printf("+=================================================================+");
            gotoxy(63,4);printf("MENU 4");
            gotoxy(50,5);printf("=== MENGHAPUS DATA MAHASISWA ===");
            gotoxy(30,7);printf("+-----------------------------------------------------------------+");
            gotoxy(30,9);printf("+-----------------------------------------------------------------+");
            gotoxy(46,8);printf("Masukan NIM yang akan dihapus : ");
            scanf("%i", &nimMhs);

            if((searchNim(nimMhs))==0){
                gotoxy(55,11);printf("Data tidak ditemukan!");
                gotoxy(48,12);printf("Tekan apa saja untuk kembali ke menu");
            }else{
                current = head;
                while(current!=NULL){
                    if(current->nim==nimMhs){
                        gotoxy(48,11);printf(":: DATA");
                        gotoxy(48,12);printf(":: NIM            : %i", current->nim);
                        gotoxy(48,13);printf(":: Nama Lengkap   : %s", current->nama);
                        gotoxy(48,14);printf(":: IPK            : %.1f", current->ipk);
                        gotoxy(48,15);printf(":: Program Studi  : %s", current->progdi);
                        gotoxy(48,16);printf(":: Angkatan       : %i", current->angkatan);
                    }
                    current = current->next;
                }
                fflush(stdin);
                gotoxy(48,18);printf("Yakin ingin menghapus data ini?(y/n)");
                scanf("%c", &hapus);

                if(hapus=='y' || hapus=='Y'){
                    hapusNim(nimMhs);
                    gotoxy(55,20);printf("Data berhasil dihapus");
                    gotoxy(48,21);printf("Tekan apa saja untuk kembali ke menu");
                }else{
                    gotoxy(48,20);printf("Tekan apa saja untuk kembali ke menu");
                }
                sprintf(aktivitasAdmin,"Admin menghapus data dengan NIM : %i", nimMhs);
                insertRiwayat(aktivitasAdmin);
            }
            getch();
            goto pilihan;
            break;

        case 5:
            setcolor(95);
            system("cls");
            gotoxy(30,2);printf("+=================================================================+");
            gotoxy(63,4);printf("MENU 5");
            gotoxy(50,5);printf("=== MENGUBAH DATA MAHASISWA ===");
            gotoxy(30,7);printf("+-----------------------------------------------------------------+");
            gotoxy(43,8);printf("Apa yang ingin Anda edit?");
            gotoxy(43,9);printf("1. Nama Lengkap\t\t 3. Program Studi");
            gotoxy(43,10);printf("2. IPK\t\t\t 4. Angkatan");
            gotoxy(30,14);printf("+-----------------------------------------------------------------+");
            gotoxy(43,12);printf("Pilihan Anda\t\t: ");
            scanf("%i", &edit);
            gotoxy(43,13);printf("Masukkan NIM\t\t: ");
            scanf("%i", &nimMhs);
            gotoxy(30,14);printf("+-----------------------------------------------------------------+");

            if((searchNim(nimMhs))==0){
                gotoxy(55,16);printf("Data tidak ditemukan!");
            }else{
                switch(edit){
                case 1:
                    current = head;
                    while(current!=NULL){
                        if(current->nim==nimMhs){
                            gotoxy(48,16);printf(":: UBAH DATA NAMA");
                            gotoxy(48,17);printf(":: Data Semula    : %s", current->nama);
                        }
                        current = current->next;
                    }
                    fflush(stdin);
                    gotoxy(48,18);printf(":: Data Diubah    : ");
                    gets(namaMhs);
                    updateNama(nimMhs,namaMhs);
                    sprintf(aktivitasAdmin,"Nama mahasiswa dengan NIM %i diubah menjadi %s", nimMhs, namaMhs);
                    insertRiwayat(aktivitasAdmin);
                    gotoxy(58,20);printf("Berhasil diubah");
                    break;

                case 2:
                    current = head;
                    while(current!=NULL){
                        if(current->nim==nimMhs){
                            gotoxy(48,16);printf(":: UBAH DATA IPK");
                            gotoxy(48,17);printf(":: Data Semula    : %.1f", current->ipk);
                        }
                        current = current->next;
                    }
                    fflush(stdin);
                    gotoxy(48,18);printf(":: Data Diubah    : ");
                    scanf("%f", &ipkMhs);
                    updateIPK(nimMhs,ipkMhs);
                    sprintf(aktivitasAdmin,"IPK mahasiswa dengan NIM %i diubah menjadi %.1f", nimMhs, ipkMhs);
                    insertRiwayat(aktivitasAdmin);
                    gotoxy(58,20);printf("Berhasil diubah");
                    break;

                case 3:
                    current = head;
                    while(current!=NULL){
                        if(current->nim==nimMhs){
                            gotoxy(48,16);printf(":: UBAH DATA PORGRAM STUDI");
                            gotoxy(48,17);printf(":: Data Semula    : %s", current->progdi);
                        }
                        current = current->next;
                    }
                    fflush(stdin);
                    gotoxy(48,18);printf(":: Data Diubah    : ");
                    gets(progdiMhs);
                    updateProgdi(nimMhs,progdiMhs);
                    sprintf(aktivitasAdmin,"Progdi mahasiswa dengan NIM %i diubah menjadi %s", nimMhs, progdiMhs);
                    insertRiwayat(aktivitasAdmin);
                    gotoxy(58,20);printf("Berhasil diubah");
                    break;

                case 4:
                    current = head;
                    while(current!=NULL){
                        if(current->nim==nimMhs){
                            gotoxy(48,16);printf(":: UBAH DATA ANGKATAN");
                            gotoxy(48,17);printf(":: Data Semula    : %i", current->angkatan);
                        }
                        current = current->next;
                    }
                    fflush(stdin);
                    gotoxy(48,18);printf(":: Data Diubah    : ");
                    scanf("%i", &angkatanMhs);
                    updateAngkatan(nimMhs,angkatanMhs);
                    sprintf(aktivitasAdmin,"Angkatan mahasiswa dengan NIM %i diubah menjadi %i", nimMhs, angkatanMhs);
                    insertRiwayat(aktivitasAdmin);
                    gotoxy(58,20);printf("Berhasil diubah");
                    break;

                default:
                    printf("Pilihan tidak ada\n");
                    getch();
                    goto pilihan;
                    break;
                }
            }
            printf("\n\t\t\t\t\t\tTekan apa saja untuk kembali ke menu");
            getch();
            goto pilihan;
            break;

        case 6:
            setcolor(96);
            system("cls");
            gotoxy(30,2);printf("+=================================================================+");
            gotoxy(63,4);printf("MENU 6");
            gotoxy(50,5);printf("=== MENCARI DATA MAHASISWA ===");
            gotoxy(30,7);printf("+-----------------------------------------------------------------+");
            gotoxy(43,8);printf("Apa yang ingin Anda cari?");
            gotoxy(43,9);printf("1. NIM\t\t\t 4. Program Studi");
            gotoxy(43,10);printf("2. Nama Lengkap\t\t 5. Angkatan");
            gotoxy(43,11);printf("3. IPK");
            gotoxy(30,15);printf("+-----------------------------------------------------------------+");
            gotoxy(43,13);printf("Pilihan Anda\t\t\t: ");
            scanf("%i", &pilih);

            switch(pilih){
            case 1:
                gotoxy(43,14);printf("NIM yang ingin dicari\t: ");
                scanf("%i", &cariNim);

                if(searchNim(cariNim)==0){
                    gotoxy(55,17);printf("Data tidak ditemukan!");
                }else{
                    printf("\n\t\t\t NIM\t\tNama Lengkap\t\tIPK\tProgram Studi\t\tAngkatan");
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+");
                    current = head;
                    while(current!=NULL){
                        if(current->nim==cariNim){
                            gotoxy(25,baris);printf("%i", current->nim);
                            gotoxy(40,baris);printf("%s", current->nama);
                            gotoxy(64,baris);printf("%.1f", current->ipk);
                            gotoxy(72,baris);printf("%s", current->progdi);
                            gotoxy(96,baris);printf("%i", current->angkatan);
                            baris++;
                        }
                        current = current->next;
                    }
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+\n");
                }
                sprintf(aktivitasAdmin,"Admin mencari NIM mahasiswa : %i", cariNim);
                insertRiwayat(aktivitasAdmin);
                break;

            case 2:
                fflush(stdin);
                gotoxy(43,14);printf("Nama yang ingin dicari\t: ");
                gets(cariNama);

                if(searchNama(cariNama)==0){
                    gotoxy(55,17);printf("Data tidak ditemukan!");
                }else{
                    printf("\n\t\t\t NIM\t\tNama Lengkap\t\tIPK\tProgram Studi\t\tAngkatan");
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+");
                    current = head;
                    while(current!=NULL){
                        if(strcmp(current->nama,cariNama)==0){
                            gotoxy(25,baris);printf("%i", current->nim);
                            gotoxy(40,baris);printf("%s", current->nama);
                            gotoxy(64,baris);printf("%.1f", current->ipk);
                            gotoxy(72,baris);printf("%s", current->progdi);
                            gotoxy(96,baris);printf("%i", current->angkatan);
                            baris++;
                        }
                        current = current->next;
                    }
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+\n");
                }
                sprintf(aktivitasAdmin,"Admin mencari nama mahasiswa : %s", cariNama);
                insertRiwayat(aktivitasAdmin);
                break;

            case 3:
                gotoxy(43,14);printf("IPK yang ingin dicari\t: ");
                scanf("%f", &cariIPK);

                if(searchIPK(cariIPK)==0){
                    gotoxy(55,17);printf("Data tidak ditemukan!");
                }else{
                    printf("\n\t\t\t NIM\t\tNama Lengkap\t\tIPK\tProgram Studi\t\tAngkatan");
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+");
                    current = head;
                    while(current!=NULL){
                        if(current->ipk==cariIPK){
                            gotoxy(25,baris);printf("%i", current->nim);
                            gotoxy(40,baris);printf("%s", current->nama);
                            gotoxy(64,baris);printf("%.1f", current->ipk);
                            gotoxy(72,baris);printf("%s", current->progdi);
                            gotoxy(96,baris);printf("%i", current->angkatan);
                            baris++;
                        }
                        current = current->next;
                    }
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+\n");
                }
                sprintf(aktivitasAdmin,"Admin mencari IPK mahasiswa : %.1f", cariIPK);
                insertRiwayat(aktivitasAdmin);
                break;

            case 4:
                fflush(stdin);
                gotoxy(43,14);printf("Progdi yang ingin dicari\t: ");
                gets(cariProgdi);

                if(searchProgdi(cariProgdi)==0){
                    gotoxy(55,17);printf("Data tidak ditemukan!");
                }else{
                    printf("\n\t\t\t NIM\t\tNama Lengkap\t\tIPK\tProgram Studi\t\tAngkatan");
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+");
                    current = head;
                    while(current!=NULL){
                        if(strcmp(current->progdi,cariProgdi)==0){
                            gotoxy(25,baris);printf("%i", current->nim);
                            gotoxy(40,baris);printf("%s", current->nama);
                            gotoxy(64,baris);printf("%.1f", current->ipk);
                            gotoxy(72,baris);printf("%s", current->progdi);
                            gotoxy(96,baris);printf("%i", current->angkatan);
                            baris++;
                        }
                        current = current->next;
                    }
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+\n");
                }
                sprintf(aktivitasAdmin,"Admin mencari progdi mahasiswa : %s", cariProgdi);
                insertRiwayat(aktivitasAdmin);
                break;

            case 5:
                gotoxy(43,14);printf("Angkatan yang ingin dicari\t: ");
                scanf("%i", &cariAngkatan);

                if(searchAngkatan(cariAngkatan)==0){
                    gotoxy(55,17);printf("Data tidak ditemukan!");
                }else{
                    printf("\n\t\t\t NIM\t\tNama Lengkap\t\tIPK\tProgram Studi\t\tAngkatan");
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+");
                    current = head;
                    while(current!=NULL){
                        if(current->angkatan==cariAngkatan){
                            gotoxy(25,baris);printf("%i", current->nim);
                            gotoxy(40,baris);printf("%s", current->nama);
                            gotoxy(64,baris);printf("%.1f", current->ipk);
                            gotoxy(72,baris);printf("%s", current->progdi);
                            gotoxy(96,baris);printf("%i", current->angkatan);
                            baris++;
                        }
                        current = current->next;
                    }
                    printf("\n\t\t\t+----------------------------------------------------------------------------------+\n");
                }
                sprintf(aktivitasAdmin,"Admin mencari angkatan mahasiswa : %i", cariAngkatan);
                insertRiwayat(aktivitasAdmin);
                break;

            default :
                printf("Pilihan tidak ada\n");
                getch();
                goto pilihan;
                break;
            }
            printf("\n\t\t\t\t\t\tTekan apa saja untuk kembali ke menu");
            getch();
            goto pilihan;
            break;

        case 7:
            setcolor(176);
            system("cls");
            tampilRiwayat();
            printf("\n\n\t\t\t\t\t\tTekan apa saja untuk kembali ke menu");
            getch();
            goto pilihan;
            break;

        case 8:
            setcolor(144);
            system("cls");
            gotoxy(30,2);printf("+=================================================================+");
            gotoxy(63,4);printf("MENU 8");
            gotoxy(50,5);printf("=== MENGURUTKAN DATA MAHASISWA ===");
            gotoxy(30,7);printf("+-----------------------------------------------------------------+");
            gotoxy(43,8);printf("Apa yang ingin Anda urutkan?");
            gotoxy(43,9);printf("1. NIM\t\t\t 4. Program Studi");
            gotoxy(43,10);printf("2. Nama Lengkap\t\t 5. Angkatan");
            gotoxy(43,11);printf("3. IPK");
            gotoxy(30,15);printf("+-----------------------------------------------------------------+");
            gotoxy(43,13);printf("Pilihan Anda\t\t\t: ");
            scanf("%i", &pilih);

            switch(pilih){
            case 1:
                system("cls");
                sortNIM();
                tampil();
                insertRiwayat("Admin mengurutkan data berdasarkan NIM");
                break;

            case 2:
                system("cls");
                sortNama();
                tampil();
                insertRiwayat("Admin mengurutkan data berdasarkan nama");
                break;

            case 3:
                system("cls");
                sortIPK();
                tampil();
                insertRiwayat("Admin mengurutkan data berdasarkan IPK");
                break;

            case 4:
                system("cls");
                sortProgdi();
                tampil();
                insertRiwayat("Admin mengurutkan data berdasarkan progdi");
                break;

            case 5:
                system("cls");
                sortAngkatan();
                tampil();
                insertRiwayat("Admin mengurutkan data berdasarkan angkatan");
                break;

            default:
                printf("Pilihan tidak ada\n");
                getch();
                goto pilihan;
                break;
            }
            printf("\n\t\t\t\t\t\tTekan apa saja untuk kembali ke menu");
            getch();
            goto pilihan;
            break;

        case 9:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
            for(int x=0; text2[x]!=NULL; x++){
                printf("%c", text2[x]);
                for(int y=0; y<=8888888; y++);
            }
            printf("\n\t\t\t\t\t\t");
            for(int x=0; text3[x]!=NULL; x++){
                printf("%c", text3[x]);
                for(int y=0; y<=8888888; y++);
            }
            printf("\n\t\t\t\t\t\t");
            for(int x=0; text4[x]!=NULL; x++){
                printf("%c", text4[x]);
                for(int y=0; y<=8888888; y++);
            }
            sleep(3);
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
            for(int x=0; text5[x]!=NULL; x++){
                printf("%c", text5[x]);
                for(int y=0; y<=8888888; y++);
            }
            sleep(2);
            system("cls");
            printf("This program will close in");
            for(int i=3; i>=0; i--){
                gotoxy(27,0);printf("%i...", i);
                sleep(1);
            }
            exit(0);
            break;

        default :
            printf("Menu tidak ada");
            getch();
            break;
        }
    }
}

void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void main(){
    setcolor(4);
    login();
    menu_utama();
}
