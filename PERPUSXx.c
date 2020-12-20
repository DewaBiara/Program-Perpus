#include <stdio.h>
#include <stdlib.h> // Agar bisa menggunakan cls

void buatakun();
char login(char a, char b);

int main(){
	char pilihan, pilihan2, pilihan3, username, password;
	int Login;
	char ulangi = 'y';
	/*	printf("Nama  : Gusti Ngurah Deva Wirandana Putra \n");
		printf("NIM   : 2008561050 \n");
		printf("Kelas : E \n"); */
	// do{
		printf("======================PERPUSTAKAAN SARASWATI======================\n");
		printf("Anda ingin masuk sebagai?\n");
		printf("1. Pengunjung \n2. Admin \n");
		printf("Masukkan Pilihan :");
		scanf("%c", &pilihan); fflush(stdin);
		system("cls");
		switch (pilihan) {
			case '1':
				printf("======================Anda masuk sebagai Pengunjung=====================\n");
				printf("1. Login \n2. Register \n");
				printf("Masukkan Pilihan :");
				scanf("%c", &pilihan2); fflush(stdin);
				system("cls");
				switch (pilihan2) {
					case '1':
						printf("======================Login====================\n");
						printf("Username \t: \n");
						scanf("%c", &username); fflush(stdin);
						printf("Password \t: \n");
						scanf("%c", &username); fflush(stdin);
						Login = login(username,password);
						if(Login == 1){
							printf("======================Anda sudah berhasil Login====================\n"); /*
							printf("MENU \t: \n");
							printf("1. Profil \n2. Cari Buku \n3. Peminjaman Buku \n4. Pengembalian Buku \n5. Pembelian Buku \n6. Keluar \n");
							scanf("%c", &pilihan3); fflush(stdin);
							switch (pilihan3){
								case '1':
									printf("======================Profil===============\n");
									break;
								case '2':
									printf("======================Cari Buku============\n");
									break;
								case '3':
									printf("======================Peminjaman Buku===============\n");
									break;
								case '4':
									printf("======================Pengembalian Buku============\n");
									break;
								case '5':
									printf("======================Pembelian Buku===============\n");
									break;
								case '6':
									printf("======================Keluar============\n");
									break;
								default:
									printf("~Pilihan yang anda masukkan salah~\n");
							}*/
						}
						else {
							printf("~Username atau Password yang anda masukkan salah~");
						}
						break;
					case '2':
						printf("=======================Register======================\n");
						buatakun();
						break;
					default:
						printf("~Pilihan yang anda masukkan salah~\n");
				}
			case '2':
				printf("=======================Belum Jadi======================\n");
				break;
			default:
				printf("~Pilihan yang anda masukkan salah~\n");
		}
		return 0;
	// printf("Apakah anda ingin mengulang? (y/t) :"); 
	// scanf("%c",&ulangi); fflush(stdin);
	// } while(ulangi == 'y');
}
