#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct admin{
    char nama[100];
    char userid[20];
    char passwd[100];
    char telp[14];
    int a;
};


struct buku {
    int kodeB, sewa, beli, stock;
    char judul[30];
    int b;
}buku[100];

void daftar() {
    FILE *fd;
    fd = fopen("Record.txt", "a+");
    printf("Masukkan Nama Anda           : ");
    scanf("%s[^\n]", &admin.nama);
    printf("Masukkan User Id Anda        : ");
    scanf("%s", &admin.userid);
    printf("Masukkan Password Anda       : ");
    scanf("%s", &admin.passwd);
    printf("Masukkan No Telephone Anda   : ");
    scanf("%s", &admin.telp);
    fwrite(&admin, sizeof(admin), 100, fd);
    fclose(fd);
}

void login() {
    FILE *fl;
    char id, pwd, checkid, checkpwd, s, r;
    int a;
    printf("Masukkan User Id Anda  : ");
    scanf("%s", &id);
    printf("Masukkan Password Anda : ");
    scanf("%s", &pwd);
    if(id == 0 && pwd == 0){
        printf("User Id atau Password yang anda masukkan Salah!");
    }
    else {
        fl = fopen("Record", "r");
        while(fread(&admin, sizeof(admin), 1,fl)){
            s = admin[a].userid;
            r = admin[a].passwd;
            if(s == id && r == pwd){
                printf("Selamat anda telah berhasil login\n");
            }
        }
        fclose(fl);
    }
}

void input() {
    FILE *fi;
    

}
int main () {
    
    int emp, c;
    do{
        printf("\n\t---Select your choice---------\n");
        printf("\n\t1. Daftar\n\t2. Login\n\t3. SE");
        printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
        printf("\n\t7. EXIT");
        printf("\n\n------------------------------------------\n");
        printf("\nEnter your choice:");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
            case 1:
            daftar();
            break; 
            
            case 2:
            login();
            break;/*
            case 3:
            search();
            break;
            case 4:
            deletefile();
            break;
            case 5:
            update();
            break;
            case 6:
            emp = empty();
                if (emp == 0)
                    printf("\n The file is EMPTY\n");
                else
                sort();
            break;
            case 7:
            exit(1);
            break;
            */
   
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);
}