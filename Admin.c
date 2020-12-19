#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Admin
{
    char nama[100];
    char userid[20];
    char passwd[100];
    char telp[14];
} admin;


struct buku {
    int kodeB, sewa, beli, stock;
    char judul[30];
    int b;
}buku[100];

void daftar(struct Admin admin) {
    FILE *fd;
    FILE *fu;
    FILE *fp;
    fd = fopen("Record.txt", "a+");
    fu = fopen("User.txt", "a+");
    fp = fopen("Passwd.txt", "a+");
    printf("Masukkan Nama Anda           : ");
    scanf("%s", &admin.nama);
    fputs (admin.nama, fd);
    fputs ("\n", fd);
    printf("Masukkan User Id Anda        : ");
    scanf("%s", &admin.userid);
    fputs (admin.userid, fd);
    fputs (admin.userid, fu);
    fputs ("\n", fd);
    fputs ("\n", fu);
    printf("Masukkan Password Anda       : ");
    scanf("%s", &admin.passwd);
    fputs (admin.passwd, fd);
    fputs (admin.passwd, fp);
    fputs ("\n", fd);
    fputs ("\n", fp);
    printf("Masukkan No Telephone Anda   : ");
    scanf("%s", &admin.telp);
    fputs (admin.telp, fd);
    fputs ("\n", fd);
    fclose(fd);
}

void login() {
    FILE *fl;
    FILE *flp;
    fl = fopen("User.txt", "r");
    flp = fopen("Passwd.txt", "r");
    char id[20], pwd[100];
    int checkid, checkpwd;
    char checku[20], checkp[100];
    printf("Masukkan User Id Anda  : ");
    scanf("%s", &id);
    //printf("this is the user name %s\n", id);
    fscanf(fl, "%[^\n]", checku);
    printf("Masukkan Password Anda : ");
    scanf("%s", &pwd);
    //printf(" this is the password %s\n", pwd);
    fscanf(flp, "%[^\n]", checkp);
    //printf("%s\n", checku);
    //printf("%s\n", checkp);
    checkid = strcmp(id, checku);
    //printf("%d\n", checkid);
    checkpwd = strcmp(pwd, checkp);
    //printf("%d\n", checkpwd);
    if(checkid == 0 && checkpwd == 0){
        printf("Selamat anda telah berhasil login\n");
    }
    else {
        printf("User Id atau Password yang anda masukkan Salah!");
    }
    fclose(fl);
}

void profile() {
    FILE *fp;
    char profile[100];
    fp = fopen("Record.txt", "r");
    fscanf(fp, "%[^\n]", profile);
    printf("%s", profile);
    fclose(fp);
}

void input() {
    FILE *fi;
    

}

int main () {
    
    int emp, c;
    struct admin;
    do{
        printf("\n\t---Select your choice---------\n");
        printf("\n\t1. Daftar\n\t2. Login\n\t");
        printf("\n\t3. Profile\n\t4. Update\n\t");
        printf("\n\t5. EXIT");
        printf("\n\n------------------------------------------\n");
        printf("\nEnter your choice:");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
            case 1:
            daftar(admin);
            break; 
            case 2:
            login();
            break;
            case 3:
            profile();
            break;
            /*
            case 4:
            deletefile();
            break;typedef struct TransistorRec Transistor;
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