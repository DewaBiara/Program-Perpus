#include <stdio.h>
#include <stdlib.h>

void lingkaran() {
    int r;
    float luas, kll;
    printf("Masukkan Jari-Jari Lingkaran : ");
    scanf("%d", &r);

    luas = 3.14 * r * r;
    kll = 3.14 * r * 2;

    printf("Luas      = %.2f\n", luas);
    printf("Keliling  = %.2f\n", kll);
    printf("Selesai\n");
}

void persegi() { 
    int p, luas, kll;
    printf("Masukkan panjang sisi persegi : ");
    scanf("%d", &p);

    luas = p * p;
    kll = p * 4;

    printf("Luas      = %d\n", luas);
    printf("Keliling  = %d\n", kll);
    printf("Selesai\n");
}

void persegipan() {
    int p, l, luas, kll;
    printf("Masukkan panjang : ");
    scanf("%d", &p);
    printf("Masukkan lebar   : ");
    scanf("%d", &l);

    luas = p * l;
    kll = (2 * p) + (2 * l);

    printf("Luas      = %d\n", luas);
    printf("Keliling  = %d\n", kll);
    printf("Selesai\n");
}

int main () {
    system("cls");
    int c;
    char op;
    do {
    printf("========================================\n");
    printf("=Program Hitung Kelilig dan Luas Bidang=\n");
    printf("========================================\n");
    printf("Daftar operasi :\n");
    printf("\n\t1. Lingkaran");
    printf("\n\t2. Persegi");
    printf("\n\t3. Persegi Panjang");
    printf("\n\t4. Exit");
    printf("\n\n========================================\n");
    printf("\nPilih operasi : ");
    scanf("%d", &c);
    printf("\n");
    
    
        switch (c) {
            case 1:
            lingkaran();
            printf("\nApakah anda ingin melanjutkan? (y/n) : ");
            scanf(" %c", &op);
            switch (op){
                case 'y':
                case 'Y':
                break;
                case 'n':
                case 'N':
                c = 4;
                break;}
            break;
            case 2:
            persegi();
            printf("\nApakah anda ingin melanjutkan? (y/n) : ");
            scanf(" %c", &op);
            switch (op){
                case 'y':
                case 'Y':
                break;
                case 'n':
                case 'N':
                c = 4;
                break;}
            break;
            case 3:
            persegipan();
            printf("\nApakah anda ingin melanjutkan? (y/n) : ");
            scanf(" %c", &op);
            switch (op){
                case 'n':
                case 'N':
                break;
                case 'y':
                case 'Y':
                c = 4;
                break;}
            break;
            case 4:
            c = 5;
            break;
        default :
            printf("Pilihan yang anda masukkan salah!");
            printf("Silahkan ulangi lagi");
        break;
        }
    }
    while( c <= 4);
    system("pause");
}
        


    


