#include <stdio.h>
#include <stdlib.h> // Agar bisa menggunakan cls
#include <string.h>
#include <time.h>

void BuatAkun();
int  Login(); 
void create();
int  LoginA();
void Profil();
void ProfileA();
void UpdateAkunP();
void UpdateAkunA();
void tambah_buku_pinjam();
void tambah_buku_beli();
void daftar_buku_pinjam();
void daftar_buku_beli();
void daftar_peminjam();
void daftar_pembelian();
void MenuA();
void Menu();
void Cari();
void Peminjaman();
void Pembelian();
void Pengembalian();

typedef struct{
	char nama[50];
	char username[20];
	int  umur;
	char telepon[13];
	char pendidikan[50];
	char password[20];
}Biodata;

typedef struct{
	char nama[50];
	char username[20];
	int  umur;
	char telepon[13];
	char pendidikan[50];
    char jabatan[50];
	char password[20];
}Admin;

typedef struct{
	char judul[50];
	char penerbit[50];
	char pengarang[50];
	char isbn[20];
	int  no;
	int  jmlh;
    int  harga;
}BukuT;

FILE*PENGUNJUNG;
FILE*ADMIN;
FILE*BUKU;
FILE*BUKU_BELI;
FILE*PEMINJAMAN;
FILE*PEMBELIAN;

int main(){
	system("cls");
	char pilihan, pilihan2;
	char ulangi = 'y';
	int login, loginA;
	int kode;
	do{
		printf("==================================================================\n");
		printf("======================PERPUSTAKAAN SARASWATI======================\n");
		printf("==================================================================\n");
		printf("Anda ingin masuk sebagai?\n");
		printf("1. Pengunjung \n2. Admin \n");
		printf("Masukkan Pilihan : ");
		scanf("%c", &pilihan); fflush(stdin);
		system("cls");
		switch (pilihan) {
			case '1':
				printf("________________________________________________________________________\n");
				printf("|                     Anda masuk sebagai Pengunjung                    |\n");
				printf("|______________________________________________________________________|\n");
				printf("1. Login \n2. Register \n");
				printf("Masukkan Pilihan : ");
				scanf("%c", &pilihan2); fflush(stdin);
				system("cls");
				switch (pilihan2) {
					case '1':
						printf("________________________________________________________________________\n");
						printf("|                                 Login                                |\n");
						printf("|______________________________________________________________________|\n");
						login = Login();
						if(login == 1){
							Menu();
						}
						else{
      					  	printf("Username atau Password salah! \n");
      					  	system("pause");
      						exit(0);
   						} 
						break;
					case '2':
						printf("________________________________________________________________________\n");
						printf("|                                Register                              |\n");
						printf("|______________________________________________________________________|\n");
						BuatAkun();
						break;
					default:
						printf("~Pilihan yang anda masukkan salah~\n");
				}
				break;
			case '2':
				printf("________________________________________________________________________\n");
				printf("|                        Anda masuk sebagai Admin                      |\n");
				printf("|______________________________________________________________________|\n");
				printf("1. Login \n2. Register \n");
				printf("Masukkan Pilihan : ");
				scanf("%c", &pilihan2); fflush(stdin);
				system("cls");
				switch (pilihan2) {
					case '1':
						printf("________________________________________________________________________\n");
						printf("|                                 Login                                |\n");
						printf("|______________________________________________________________________|\n");
						loginA = LoginA();
						if(loginA == 1){
							MenuA();
						}
						else{
      					  	printf("Username atau Password salah! \n");
      					  	system("pause");
      						exit(0);
   						} 
						break;
					case '2':
					printf("Untuk mendaftar sebagai admin, anda harus memasukkan kode unik terlebih dahulu.\n");
					printf("Silahkan masukkan kode disini >> ");
					scanf("%d", &kode); fflush(stdin);
					if(kode == 61105){
						printf("________________________________________________________________________\n");
						printf("|                                Register                              |\n");
						printf("|______________________________________________________________________|\n");
						create();
					}
					else printf("Kode yang anda masukkan salah!\n");
						break;
					default:
						printf("~Pilihan yang anda masukkan salah~\n");
				}
				break;
				break;
			default:
				printf("~Pilihan yang anda masukkan salah~\n");	
		}
	printf("Apakah anda ingin mengulang? (y/t) :"); 
	scanf("%c",&ulangi); fflush(stdin);
	} while(ulangi == 'y');
}

void BuatAkun(){
	Biodata Pengunjung;
	PENGUNJUNG=fopen("pengunjung.txt","a+");
	printf("Nama \t\t\t: "); scanf("%[^\n]",&Pengunjung.nama); fflush(stdin);
	printf("Username \t\t: "); scanf("%[^\n]",&Pengunjung.username); fflush(stdin);
	printf("Umur \t\t\t: "); scanf("%i",&Pengunjung.umur); fflush(stdin);
	printf("No Telepon \t\t: "); scanf("%[^\n]",&Pengunjung.telepon); fflush(stdin);
	printf("Nama Sekolah/Instansi \t: "); scanf("%[^\n]",&Pengunjung.pendidikan); fflush(stdin);
	printf("Password \t\t: "); scanf("%[^\n]",&Pengunjung.password); fflush(stdin);
	printf("Tunggu Sebentar...\n");
	fprintf(PENGUNJUNG,"%s_%s_%i_%s_%s_%s\n", Pengunjung.nama, Pengunjung.username, Pengunjung.umur, Pengunjung.telepon, Pengunjung.pendidikan, Pengunjung.password);
	printf("Selamat! Akun Anda sudah berhasil dibuat.\n");
	fclose(PENGUNJUNG);
}

void create(){
	Admin Admin;
	ADMIN=fopen("admin.txt","a+");
	printf("Nama \t\t\t: "); scanf("%[^\n]",&Admin.nama); fflush(stdin);
	printf("Username \t\t: "); scanf("%[^\n]",&Admin.username); fflush(stdin);
	printf("Umur \t\t\t: "); scanf("%i",&Admin.umur); fflush(stdin);
	printf("No Telepon \t\t: "); scanf("%[^\n]",&Admin.telepon); fflush(stdin);
	printf("Nama Sekolah/Instansi \t: "); scanf("%[^\n]",&Admin.pendidikan); fflush(stdin);
	printf("Jabatan\t\t\t: "); scanf("%[^\n]", &Admin.jabatan); fflush(stdin);
	printf("Password \t\t: "); scanf("%[^\n]",&Admin.password); fflush(stdin);
	printf("Tunggu Sebentar...\n");
	fprintf(ADMIN,"%s_%s_%i_%s_%s_%s_%s\n", Admin.nama, Admin.username, Admin.umur, Admin.telepon, Admin.pendidikan, Admin.jabatan,Admin.password);
	printf("Selamat! Akun Anda sudah berhasil dibuat.\n");
	fclose(ADMIN);
}

int Login(){
	char user[20], pass[20];
	Biodata Pengunjung;
	PENGUNJUNG=fopen("pengunjung.txt","r");
    printf("Username : "); scanf("%s",&user); fflush(stdin);
    printf("Password : "); scanf("%s",&pass); fflush(stdin);
	while (!feof(PENGUNJUNG)){
		fscanf(PENGUNJUNG,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pengunjung.nama, &Pengunjung.username, &Pengunjung.umur, &Pengunjung.telepon, &Pengunjung.pendidikan, &Pengunjung.password);
		fflush(stdin);
		if(strcmp(user,Pengunjung.username)==0 && strcmp(pass,Pengunjung.password)== 0) {
			system("cls");
			return 1;;
		}
	}
}

int LoginA(){
	char user[20], pass[20];
	Admin Admin;
	ADMIN=fopen("admin.txt","r");
    printf("Username : "); scanf("%s",&user); fflush(stdin);
    printf("Password : "); scanf("%s",&pass); fflush(stdin);
	while (!feof(ADMIN)){
		fscanf(ADMIN,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^_]_%[^\n]\n",&Admin.nama, &Admin.username, &Admin.umur, &Admin.telepon, &Admin.pendidikan, &Admin.jabatan ,&Admin.password);
		fflush(stdin);
		if(strcmp(user,Admin.username)==0 && strcmp(pass,Admin.password)== 0) {
			system("cls");
			return 1;
		} 
	}
}

void Menu(){
	char pilihan, ulangi;
	printf("________________________________________________________________________\n");
	printf("|                       Anda sudah berhasil Login                      |\n");
	printf("|______________________________________________________________________|\n");
	do {
		printf("~MENU~ \t: \n");
		printf("1. Profil \n2. Daftar Buku \n3. Cari Buku \n4. Peminjaman Buku \n5. Pengembalian Buku \n6. Pembelian Buku \n7. Keluar \n");
		printf("Masukkan Pilihan :");
		scanf("%c", &pilihan); fflush(stdin);
		system("cls");
		switch (pilihan){
			case '1':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                                Profil                                |\n");
				printf("|______________________________________________________________________|\n");
				Profil();
				break;
			case '2':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                              Daftar Buku                             |\n");
				printf("|______________________________________________________________________|\n");
				daftar_buku_pinjam();
				break;
			case '3':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                               Cari Buku                              |\n");
				printf("|______________________________________________________________________|\n");
				Cari();
				break;
			case '4':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Peminjaman Buku                           |\n");
				printf("|______________________________________________________________________|\n");
				Peminjaman();
				break;
			case '5':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                           Pengembalian Buku                          |\n");
				printf("|______________________________________________________________________|\n");
				Pengembalian();
				break;
			case '6':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Pembelian Buku                            |\n");
				printf("|______________________________________________________________________|\n");
				Pembelian();
				break;
			case '7':
				system("pause");
      			exit(0);
				break;
			default:
				printf("~Pilihan yang anda masukkan salah~\n");
		}
	printf("Kembali ke menu ? (y/t) :"); 
	scanf("%c",&ulangi); fflush(stdin);
	system("cls");
	} while(ulangi == 'y');
}

void MenuA(){
	char pilihan, ulangi;
	printf("________________________________________________________________________\n");
	printf("|                       Anda sudah berhasil Login                      |\n");
	printf("|______________________________________________________________________|\n");
	do {
		printf("~MENU~ \t: \n");
		printf("1. Profil \n2. Daftar Buku Pinjaman\n3. Tambah Buku Pinjaman\n4. Daftar Buku Beli\n5. Tambah Buku Beli \n6. Daftar Peminjam Buku \n7. Daftar Pembelian Buku \n8. Keluar\n");
		printf("Masukkan Pilihan :");
		scanf("%c", &pilihan); fflush(stdin);
		switch (pilihan){
			case '1':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                                Profil                                |\n");
				printf("|______________________________________________________________________|\n");
				ProfileA();
				break;
			case '2':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                         Daftar Buku Pinjaman                         |\n");
				printf("|______________________________________________________________________|\n");
				daftar_buku_pinjam();
				break;
			case '3':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                         Tambah Buku Pinjaman                         |\n");
				printf("|______________________________________________________________________|\n");
				tambah_buku_pinjam();
				break;
			case '4':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                           Daftar Buku Beli                           |\n");
				printf("|______________________________________________________________________|\n");
				daftar_buku_beli();
				break;
			case '5':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                           Tambah Buku Beli                           |\n");
				printf("|______________________________________________________________________|\n");
				tambah_buku_beli();
				break;
			case '6':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                         Daftar Peminjam Buku                         |\n");
				printf("|______________________________________________________________________|\n");
				daftar_peminjam();
				break;
			case '7':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                        Daftar Pembelian Buku                         |\n");
				printf("|______________________________________________________________________|\n");
				daftar_pembelian();
				break;
			case '8':
				system("pause");
      			exit(0);
				break;
			default:
				printf("~Pilihan yang anda masukkan salah~\n");
			}
	printf("Kembali ke menu ? (y/t) :"); 
	scanf("%c",&ulangi); fflush(stdin);
	system("cls");
	} while(ulangi == 'y');
}

void Profil(){
	Biodata Pengunjung;
	char id[20], pilihan;
	PENGUNJUNG=fopen("pengunjung.txt","r");
	printf("Masukan Username sekali lagi \t: ");scanf("%s",&id);fflush(stdin);
	while (!feof(PENGUNJUNG)){
		fscanf(PENGUNJUNG,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pengunjung.nama, &Pengunjung.username, &Pengunjung.umur, &Pengunjung.telepon, &Pengunjung.pendidikan, &Pengunjung.password);
		fflush(stdin);
		if(strcmp(id,Pengunjung.username)==0){
			printf("Nama \t\t\t: %s\n", Pengunjung.nama);
			printf("Umur \t\t\t: %i\n", Pengunjung.umur);
			printf("No Telepon \t\t: %s\n", Pengunjung.telepon);
			printf("Nama Sekolah/Instansi \t: %s\n", Pengunjung.pendidikan);
		}
	}
	fclose(PENGUNJUNG);
	printf("Apakah anda ingin update akun?\n");
	printf("Masukkan Pilihan (y/n): ");
	scanf("%c", &pilihan); fflush(stdin);
	if(pilihan == 'y' || pilihan == 'Y'){
			system("cls");
			printf("________________________________________________________________________\n");
			printf("|                             Update Akun                              |\n");
			printf("|______________________________________________________________________|\n");
			UpdateAkunP();
	}
}

void ProfileA() {
	Admin Admin;
	char id[20], pilihan;
	ADMIN = fopen("admin.txt", "r");
	printf("Masukan Username sekali lagi \t: ");scanf("%s",&id);fflush(stdin);
	while (!feof(ADMIN)){
	fscanf(ADMIN,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^_]_%[^\n]\n",&Admin.nama, &Admin.username, &Admin.umur, &Admin.telepon, &Admin.pendidikan, &Admin.jabatan ,&Admin.password);
		fflush(stdin);
		if(strcmp(id,Admin.username)==0){
			printf("Nama \t\t\t: %s\n", Admin.nama);
			printf("Umur \t\t\t: %i\n", Admin.umur);
			printf("No Telepon \t\t: %s\n", Admin.telepon);
			printf("Nama Sekolah/Instansi \t: %s\n", Admin.pendidikan);
			printf("Jabatan \t\t: %s\n", Admin.jabatan);
		}
	}
	fclose(ADMIN);
	printf("Apakah anda ingin update akun?\n");
	printf("Masukkan Pilihan (y/n): ");
	scanf("%c", &pilihan); fflush(stdin);
	if(pilihan == 'y' || pilihan == 'Y'){
			system("cls");
			printf("________________________________________________________________________\n");
			printf("|                             Update Akun                              |\n");
			printf("|______________________________________________________________________|\n");
			UpdateAkunA();
	}
}

void tambah_buku_pinjam() {
	BukuT Buku;
	BUKU = fopen("buku.txt", "a+");
	printf("Judul Buku \t\t: "); scanf("%[^\n]",&Buku.judul); fflush(stdin);
	printf("Penerbit \t\t: "); scanf("%[^\n]",&Buku.penerbit); fflush(stdin);
	printf("Pengarang \t\t: "); scanf("%[^\n]",&Buku.pengarang); fflush(stdin);
	printf("ISBN \t\t\t: "); scanf("%[^\n]",&Buku.isbn); fflush(stdin);
	printf("No Buku \t\t: "); scanf("%i",&Buku.no); fflush(stdin);
	printf("Jumlah Buku \t\t: "); scanf("%i", &Buku.jmlh); fflush(stdin);
	printf("Tunggu Sebentar...\n");
	fprintf(BUKU,"%s_%s_%s_%s_%i_%i\n", Buku.judul, Buku.penerbit, Buku.pengarang, Buku.isbn, Buku.no, Buku.jmlh);
	printf("Selamat! Buku sudah berhasil ditambahkan.\n");
	fclose(BUKU);
}

void daftar_buku_pinjam(){
    BukuT Buku;
    BUKU = fopen("buku.txt", "r");
	printf("=====================================================================================================================================\n");
    printf("No Buku \t"); 
	printf("Judul Buku \t\t\t");
    printf("Penerbit \t\t");
    printf("Pengarang \t\t"); 
    printf("ISBN \t\t\t");
    printf("Jumlah Buku \t");
    printf("\n=====================================================================================================================================\n");
	while (!feof(BUKU)){
    fscanf(BUKU,"%[^_]_%[^_]_%[^_]_%[^_]_%i_%i\n", &Buku.judul, &Buku.penerbit, &Buku.pengarang, &Buku.isbn, &Buku.no, &Buku.jmlh);
		fflush(stdin);
			printf("|%-2i| \t", Buku.no); 
			printf("|%-30s|", Buku.judul);
			printf("|%-25s|", Buku.penerbit);
			printf("|%-25s|", Buku.pengarang); 
			printf("|%-20s|\t", Buku.isbn);
			printf("|%-4i|\n", Buku.jmlh);
        }
    fclose(BUKU);
}

void tambah_buku_beli() {
	BukuT Buku_beli;
	BUKU_BELI = fopen("buku_beli.txt", "a+");
	printf("Judul Buku \t\t: "); scanf("%[^\n]",&Buku_beli.judul); fflush(stdin);
	printf("Penerbit \t\t: "); scanf("%[^\n]",&Buku_beli.penerbit); fflush(stdin);
	printf("Pengarang \t\t: "); scanf("%[^\n]",&Buku_beli.pengarang); fflush(stdin);
	printf("ISBN \t\t\t: "); scanf("%[^\n]",&Buku_beli.isbn); fflush(stdin);
	printf("No Buku \t\t: "); scanf("%i",&Buku_beli.no); fflush(stdin);
	printf("Jumlah Buku \t\t: "); scanf("%i", &Buku_beli.jmlh); fflush(stdin);
    printf("Harga buku \t\t: "); scanf("%i", &Buku_beli.harga); fflush(stdin);
	printf("Tunggu Sebentar...\n");
	fprintf(BUKU_BELI,"%s_%s_%s_%s_%i_%i_%i\n", Buku_beli.judul, Buku_beli.penerbit, Buku_beli.pengarang, Buku_beli.isbn, Buku_beli.no, Buku_beli.jmlh, Buku_beli.harga);
	printf("Selamat! Buku sudah berhasil ditambahkan.\n");
	fclose(BUKU_BELI);
}

void daftar_buku_beli(){
    BukuT Buku_beli;
    BUKU_BELI = fopen("buku_beli.txt", "r");
	printf("==============================================================================================================================================================\n");
    printf("No Buku \t"); 
	printf("Judul Buku \t\t\t");
    printf("Penerbit \t\t");
    printf("Pengarang \t\t"); 
    printf("ISBN \t\t");
    printf("Jumlah Buku \t");
    printf("Harga Buku \t");
    printf("\n==============================================================================================================================================================\n");
    while (!feof(BUKU_BELI)){
    fscanf(BUKU_BELI,"%[^_]_%[^_]_%[^_]_%[^_]_%i_%i_%i\n", &Buku_beli.judul, &Buku_beli.penerbit, &Buku_beli.pengarang, &Buku_beli.isbn, &Buku_beli.no, &Buku_beli.jmlh, &Buku_beli.harga);
		fflush(stdin);
			printf("|%-2i| \t", Buku_beli.no); 
			printf("|%-30s|", Buku_beli.judul);
			printf("|%-25s|", Buku_beli.penerbit);
			printf("|%-25s|", Buku_beli.pengarang); 
			printf("|%-20s|", Buku_beli.isbn);
			printf("|%-4i|\t", Buku_beli.jmlh);
			printf("|%-10i|\n", Buku_beli.harga);
	}
    fclose(BUKU_BELI);
}

void Cari(){
	BukuT Buku;
	char id[100];
    BUKU = fopen("buku.txt", "r");
	printf("Masukan ISBN Buku yang ingin dicari \t: "); scanf("%s",&id); fflush(stdin);
	while (!feof(BUKU)){
    	fscanf(BUKU,"%[^_]_%[^_]_%[^_]_%[^_]_%i_%i\n", &Buku.judul, &Buku.penerbit, &Buku.pengarang, &Buku.isbn, &Buku.no, &Buku.jmlh);
		fflush(stdin);
		if(strcmp(id,Buku.isbn)==0){
			printf("No Buku \t\t: %i\n", Buku.no);
			printf("Judul Buku \t\t: %s\n", Buku.judul);
            printf("Penerbit \t\t: %s\n", Buku.penerbit);
            printf("Pengarang \t\t: %s\n", Buku.pengarang); 
            printf("ISBN \t\t\t: %s\n", Buku.isbn); 
            printf("Jumlah Buku \t\t: %i\n\n", Buku.jmlh);
        }
    }
    fclose(BUKU);
} 

void Peminjaman(){
	Biodata Pengunjung;
	BukuT Buku[20];
	char isbn[100], id[20];
	int index,i;
	index=0;
	daftar_buku_pinjam();
	BUKU=fopen("buku.txt", "r+");
	printf("\nMau meminjam buku yang mana ?\n");
	printf("Masukkan ISBN Buku yang ingin dipinjam : ");
	scanf("%[^\n]",&isbn); fflush(stdin);
	while (!feof(BUKU)){
		fscanf(BUKU,"%[^_]_%[^_]_%[^_]_%[^_]_%i_%i\n", &Buku[index].judul, &Buku[index].penerbit, &Buku[index].pengarang, &Buku[index].isbn, &Buku[index].no, &Buku[index].jmlh);
		fflush(stdin);
		if(strcmp(isbn,Buku[index].isbn)==0){
			if(Buku[index].jmlh > 0){
				printf("======================Buku Berhasil Dipinjam===============\n");
				Buku[index].jmlh -= 1;
				PENGUNJUNG=fopen("pengunjung.txt","r");
				printf("Masukan Username sekali lagi \t: "); scanf("%s",&id); fflush(stdin);
				while (!feof(PENGUNJUNG)){
					fscanf(PENGUNJUNG,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pengunjung.nama, &Pengunjung.username, &Pengunjung.umur, &Pengunjung.telepon, &Pengunjung.pendidikan, &Pengunjung.password);
					fflush(stdin);
						if(strcmp(id,Pengunjung.username)==0){
							PEMINJAMAN=fopen("peminjaman.txt", "a");
							fprintf(PEMINJAMAN,"%s_%s_%s_%s_%s\n", Buku[index].judul, Buku[index].isbn, Pengunjung.username, Pengunjung.nama, Pengunjung.telepon);
							fclose(PEMINJAMAN);
					}
				}
				fclose(PENGUNJUNG);
			}
			else {
				printf("======================Buku Tidak Dapat Dipinjam===============\n");
			}
		}
		index++;
	}
	fclose(BUKU);
	BUKU=fopen("buku.txt","w");
	fclose(BUKU);
	BUKU=fopen("buku.txt","a");
	for(i=0; i<index; i++){
		fprintf(BUKU,"%s_%s_%s_%s_%i_%i\n", Buku[i].judul, Buku[i].penerbit, Buku[i].pengarang, Buku[i].isbn, Buku[i].no, Buku[i].jmlh);
	}
	fclose(BUKU);
}

void Pengembalian(){
	Biodata Pengunjung[20];
	BukuT Buku[20];
	char isbn[100];
	int index,i,index2,j;
	index=0;
	index2=0;
	BUKU=fopen("buku.txt", "r+");
	printf("\nMau mengembalikan buku yang mana ?\n");
	printf("Masukkan ISBN Buku yang ingin dikembalikan : \n");
	scanf("%[^\n]",&isbn); fflush(stdin);
	while (!feof(BUKU)){
		fscanf(BUKU,"%[^_]_%[^_]_%[^_]_%[^_]_%i_%i\n", &Buku[index].judul, &Buku[index].penerbit, &Buku[index].pengarang, &Buku[index].isbn, &Buku[index].no, &Buku[index].jmlh);
		fflush(stdin);
		if(strcmp(isbn,Buku[index].isbn)==0){
			if(Buku[index].jmlh > 0){
				printf("======================Buku Berhasil Dikembalikan===============\n");
				Buku[index].jmlh += 1;
				PEMINJAMAN=fopen("peminjaman.txt","r");
				while (!feof(PEMINJAMAN)){
					fscanf(PEMINJAMAN,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n", Buku[index2].judul, Buku[index2].isbn, Pengunjung[index2].username, Pengunjung[index2].nama, Pengunjung[index2].telepon);
					fflush(stdin);
					if(Buku[index].isbn != Buku[index2].isbn){
						index2++;
					}
				}
				fclose(PEMINJAMAN);
				PEMINJAMAN=fopen("peminjaman.txt","w");
				fclose(PEMINJAMAN);
				PEMINJAMAN=fopen("peminjaman.txt","a");
				for(j=0;j<index2;j++){
					fprintf(PEMINJAMAN,"%s_%s_%s_%s_%s\n", Buku[j].judul, Buku[j].isbn, Pengunjung[j].username, Pengunjung[j].nama, Pengunjung[j].telepon);
				}
				fclose(PEMINJAMAN);
			}
			else {
				printf("======================Buku Tidak Dapat Dikembalikan===============\n");
			}
		}
		index++;
	}
	fclose(BUKU);
	BUKU=fopen("buku.txt","w");
	fclose(BUKU);
	BUKU=fopen("buku.txt","a");
	for(i=0; i<index; i++){
		fprintf(BUKU,"%s_%s_%s_%s_%i_%i\n", Buku[i].judul, Buku[i].penerbit, Buku[i].pengarang, Buku[i].isbn, Buku[i].no, Buku[i].jmlh);
	}
	fclose(BUKU);
}

void Pembelian(){
	Biodata Pengunjung;
	BukuT Buku_beli[20];
    time_t now;
    time (&now);
	char isbn[100], id[20], c;
	int index,i;
	index=0;
	daftar_buku_beli();
	BUKU_BELI=fopen("buku_beli.txt", "r+");
	printf("\nMau membeli buku yang mana ?\n");
	printf("Masukkan ISBN Buku yang ingin dibeli : \n");
	scanf("%[^\n]",&isbn); fflush(stdin);
	while (!feof(BUKU_BELI)){
		fscanf(BUKU_BELI,"%[^_]_%[^_]_%[^_]_%[^_]_%i_%i_%i\n", &Buku_beli[index].judul, &Buku_beli[index].penerbit, &Buku_beli[index].pengarang, &Buku_beli[index].isbn, &Buku_beli[index].no, &Buku_beli[index].jmlh, &Buku_beli[index].harga);
		fflush(stdin);
		if(strcmp(isbn,Buku_beli[index].isbn)==0){
			if(Buku_beli[index].jmlh > 0){
				printf("======================Buku Berhasil Dibeli===============\n");
				Buku_beli[index].jmlh -= 1;
				PENGUNJUNG=fopen("pengunjung.txt","r");
				printf("Masukan Username sekali lagi \t: "); scanf("%s",&id); fflush(stdin);
				while (!feof(PENGUNJUNG)){
					fscanf(PENGUNJUNG,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pengunjung.nama, &Pengunjung.username, &Pengunjung.umur, &Pengunjung.telepon, &Pengunjung.pendidikan, &Pengunjung.password);
					fflush(stdin);
					if(strcmp(id,Pengunjung.username)==0){
						PEMBELIAN=fopen("pembelian.txt", "a");
						fprintf(PEMBELIAN,"%s_%s_%i_%s_%s_%s\n", Buku_beli[index].judul, Buku_beli[index].isbn, Buku_beli[index].harga, Pengunjung.username, Pengunjung.nama, Pengunjung.telepon);
						fclose(PEMBELIAN);
						printf("Anda ingin mencetak struk?(y/n)");
                   		scanf("%c", &c);
						if(c == 'y' || c == 'Y'){
                    	   	system("cls");
                   	    	PEMBELIAN=fopen("pembelian.txt", "r");
                  	 	    printf("Tanggal pembelian : %s", ctime(&now));
                  	 	    printf("======================Struk Bukti Pembelian===============\n");
                  			printf("Judul Buku \t\t: %s\n", Buku_beli[index].judul);
               		   	    printf("ISBN \t\t\t: %s\n", Buku_beli[index].isbn);
               		   	    printf("Harga Buku \t\t; %i\n", Buku_beli[index].harga);
              	 	        printf("Nama \t\t\t: %s\n", Pengunjung.nama);
              	    	    printf("Nama Sekolah/Instansi \t: %s\n", Pengunjung.username);
              	          	printf("No Telepon \t\t: %s\n\n", Pengunjung.telepon);
              	          	printf("Terima Kasih telah berbelanja.\n");
             	          	printf("===========================================================\n");
                	    	fclose(PEMBELIAN);
                    	}
					}
				}
				fclose(PENGUNJUNG);
			}
			else {
				printf("======================Buku Tidak Dapat Dibeli===============\n");
			}
		}
		index++;
	}
	fclose(BUKU_BELI);
	BUKU=fopen("buku_beli.txt","w");
	fclose(BUKU_BELI);
	BUKU=fopen("buku_beli.txt","a");
	for(i=0; i<index; i++){
		fprintf(BUKU_BELI,"%s_%s_%s_%s_%i_%i_%i\n", Buku_beli[i].judul, Buku_beli[i].penerbit, Buku_beli[i].pengarang, Buku_beli[i].isbn, Buku_beli[i].no, Buku_beli[i].jmlh, Buku_beli[i].harga);
	}
	fclose(BUKU_BELI);
}

void daftar_peminjam(){
	Biodata Pengunjung;
	BukuT Buku;
	PEMINJAMAN=fopen("peminjaman.txt","r");
	while (!feof(PEMINJAMAN)){
		fscanf(PEMINJAMAN,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&Buku.judul, &Buku.isbn, &Pengunjung.username, &Pengunjung.nama, &Pengunjung.telepon);;
		fflush(stdin);
			printf("Judul Buku \t\t: %s\n", Buku.judul);
			printf("ISBN \t\t\t: %s\n", Buku.isbn);
			printf("Nama \t\t\t: %s\n", Pengunjung.nama);
			printf("Nama Sekolah/Instansi \t: %s\n", Pengunjung.username);
			printf("No Telepon \t\t: %s\n\n", Pengunjung.telepon);
	}
	fclose(PEMINJAMAN);
}

void daftar_pembelian(){
	Biodata Pengunjung;
	BukuT Buku_beli;
	PEMBELIAN=fopen("pembelian.txt","r");
	while (!feof(PEMBELIAN)){
		fscanf(PEMBELIAN,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Buku_beli.judul, &Buku_beli.isbn, &Buku_beli.harga, &Pengunjung.username, &Pengunjung.nama, &Pengunjung.telepon);;
		fflush(stdin);
			printf("Judul Buku \t\t: %s\n", Buku_beli.judul);
			printf("ISBN \t\t\t: %s\n", Buku_beli.isbn);
			printf("Harga Buku \t\t; %i\n", Buku_beli.harga);
			printf("Nama \t\t\t: %s\n", Pengunjung.nama);
			printf("Nama Sekolah/Instansi \t: %s\n", Pengunjung.username);
			printf("No Telepon \t\t: %s\n\n", Pengunjung.telepon);
	}
	fclose(PEMBELIAN);
}

void UpdateAkunP(){
	Biodata Pengunjung[20];
	char id[20];
	int index,i;
	index=0;
	PENGUNJUNG=fopen("pengunjung.txt","r");
	printf("Masukan Username sekali lagi \t: ");scanf("%s",&id);fflush(stdin);
	while (!feof(PENGUNJUNG)){
		fscanf(PENGUNJUNG,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pengunjung[index].nama, &Pengunjung[index].username, &Pengunjung[index].umur, &Pengunjung[index].telepon, &Pengunjung[index].pendidikan, &Pengunjung[index].password);
		fflush(stdin);
		if(strcmp(id,Pengunjung[index].username)==0){
			printf("Nama baru \t\t\t: "); scanf("%[^\n]",&Pengunjung[index].nama); fflush(stdin);
			printf("Umur baru \t\t\t: "); scanf("%i",&Pengunjung[index].umur); fflush(stdin);
			printf("No Telepon baru \t\t: "); scanf("%[^\n]",&Pengunjung[index].telepon); fflush(stdin);
			printf("Nama Sekolah/Instansi baru \t: "); scanf("%[^\n]",&Pengunjung[index].pendidikan); fflush(stdin);
		}
		index++;
	}
	fclose(PENGUNJUNG);
	PENGUNJUNG=fopen("pengunjung.txt","w");
	fclose(PENGUNJUNG);
	PENGUNJUNG=fopen("pengunjung.txt","a");
	for(i=0; i<index; i++){
		fprintf(PENGUNJUNG,"%s_%s_%i_%s_%s_%s\n", Pengunjung[i].nama, Pengunjung[i].username, Pengunjung[i].umur, Pengunjung[i].telepon, Pengunjung[i].pendidikan, Pengunjung[i].password);
	}
	printf("Selamat! Akun Anda sudah berhasil diupdate.\n");
	fclose(PENGUNJUNG);
}

void UpdateAkunA(){
	Admin Admin[20];
	char id[20];
	int index,i;
	index=0;
	ADMIN=fopen("admin.txt","r");
	printf("Masukan Username sekali lagi \t: ");scanf("%s",&id);fflush(stdin);
	while (!feof(ADMIN)){
		fscanf(ADMIN,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^_]_%[^\n]\n",&Admin[index].nama, &Admin[index].username, &Admin[index].umur, &Admin[index].telepon, &Admin[index].pendidikan, &Admin[index].jabatan ,&Admin[index].password);
		fflush(stdin);
		if(strcmp(id,Admin[index].username)==0){
			printf("Nama baru \t\t\t: "); scanf("%[^\n]",&Admin[index].nama); fflush(stdin);
			printf("Umur baru \t\t\t: "); scanf("%i",&Admin[index].umur); fflush(stdin);
			printf("No Telepon baru \t\t: "); scanf("%[^\n]",&Admin[index].telepon); fflush(stdin);
			printf("Nama Sekolah/Instansi baru \t: "); scanf("%[^\n]",&Admin[index].pendidikan); fflush(stdin);
		}
		index++;
	}
	fclose(ADMIN);
	ADMIN=fopen("admin.txt","w");
	fclose(ADMIN);
	ADMIN=fopen("admin.txt","a");
	for(i=0; i<index; i++){
		fprintf(ADMIN,"%s_%s_%i_%s_%s_%s_%s\n", Admin[i].nama, Admin[i].username, Admin[i].umur, Admin[i].telepon, Admin[i].pendidikan, Admin[i].jabatan, Admin[i].password);
	}
	printf("Selamat! Akun Anda sudah berhasil diupdate.\n");
	fclose(ADMIN);
}