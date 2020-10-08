#include "try.h"

COORD coord = {0,0};

void gotoxy(int x, int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void buat_kotak(){
	int i, j;
	gotoxy(0,0);
	printf("%c", 201);
	for(i=1; i<78; i++){
		gotoxy(i,0);
		printf("%c", 205);
	}
	gotoxy(78,0);
	printf("%c", 187);
	for (i=1; i=25; i++){
		gotoxy(78, i);
		if(i==6){
			printf("%c", 185);
		}
		else{
			printf("%c", 186);
		}
	}
	gotoxy(78,25);
	printf("%c", 188);
	for(i=77; i=0; i--){
		gotoxy(i,25);
		if(i==35){
			printf("%c", 202);
		}
		else{
			printf("%c", 205);
		}
	}
	gotoxy(0, 25);
	printf("%c", 200);
	for (i=24; i>0; i--){
		gotoxy(0,i);
		if(i==6){
			printf("%c", 204);
		}
		else{
			printf("%c", 186);
		}
	}
	for (i=1; i<78; i++){
		gotoxy(i,6);
		if(i==35){
			printf("%c", 203);
		}
		else{
			printf("%c", 205);
		}
	}
	for (i=7; i<25; i++){
		gotoxy(35,i);
		printf("%c", 186);
	}
}

void clear(){
	int i, j;
	for(i=37; i<78; i++){
		for(j=7; j<25; j++){
			gotoxy(i, j);
			printf(" ");
		}
	}
	return;
}

void show(){
	buat_kotak();
	gotoxy (25,2);
	printf("DATA MAHASISWA");
	gotoxy (20,4);
	printf("UPNV Jawa Timur");
}

void cetak_judul(const char judul[]){
	gotoxy(40,8);
	printf("--> %s", judul);
}

void add_mahasiswa(){
	clear();
	cetak_judul("Input Data Mahasiswa");
	int print=37;
	FILE *fp;
	fp=fopen("Data_Mahasiswa.txt","ab+");
	if(fp==NULL){
		MessageBeep(0);
	}
	else{
		int a=1;
		int b;
		gotoxy(print,10); printf("Jumlah Data Mahasiswa yang akan Ditambahkan :"); scanf("%d", &b);
		while(a<=b){
			fflush(stdin);
			gotoxy(print, 12); printf("NIM			: "); gets(mahasiswa.npm);
			gotoxy(print, 13); printf("Nama			: "); gets(mahasiswa.nama);
			gotoxy(print, 14); printf("Prodi		: "); gets(mahasiswa.prodi);
			gotoxy(print, 15); printf("Fakultas		: "); gets(mahasiswa.fakultas);
			gotoxy(print, 16); printf("Alamat		: "); gets(mahasiswa.alamat);
			gotoxy(print, 17); printf("Nama Ortu	: "); gets(mahasiswa.ortu);
			gotoxy(print, 18); printf("No. Telp/HP	: "); gets(mahasiswa.no_hp);
			fwrite(&mahasiswa, sizeof(mahasiswa), 1, fp);
			a++;
		}
		gotoxy(40,20); printf("Data berhasilkan dimasukkan...");
	}
	fclose(fp);
	return;
}

void cari_mahasiswa(){
	clear();
	cetak_judul("Cari Data Mahasiswa");
	char s_npm[15];
	FILE *fp;
	int found=0;
	gotoxy(37,10); printf("Inputkan NPM : "); fflush(stdin);
	gets(s_npm);
	fp=fopen("Data_Mahasiswa.txt", "ab+");
	while(fread(&mahasiswa, sizeof(mahasiswa), 1, fp)==1){
		if(strcmp(s_npm, mahasiswa.npm)==0)
		found=1;
		break;
	}
	if(found == 1){
		gotoxy(37,12); printf("Data Ditemukan: ");
		gotoxy(37,14); printf("NIM			: %s", mahasiswa.npm);
		gotoxy(37,15); printf("Nama			: %s", mahasiswa.nama);
		gotoxy(37,16); printf("Prodi		: %s", mahasiswa.prodi);
		gotoxy(37,17); printf("Fakultas		: %s", mahasiswa.fakultas);
		gotoxy(37,18); printf("Alamat		: %s", mahasiswa.alamat);
		gotoxy(37,19); printf("Nama Ortu	: %s", mahasiswa.ortu);
		gotoxy(37,20); printf("No. Telp/HP	: %s", mahasiswa.no_hp);
	}
	else{
		gotoxy(37,12); printf("Data Tidak Ditemukan!");
	}
	fclose(fp);
	return;
}

void ubah_mahasiswa(){
	clear();
	cetak_judul("Ubah Data Mahasiswa");
	char s_npm[15];
	int found=0, print=37;
	gotoxy(37,10); printf("Inputkan NPM : "); fflush(stdin);
	gets(s_npm);
	FILE *fp;
	fp = fopen("Data_Mahasiswa.txt", "rb+");
	while(fread(&mahasiswa, sizeof(mahasiswa), 1, fp)==1){
		if(strcmp(s_npm, mahasiswa.npm)==0){
			fflush(stdin);
			gotoxy(print,12); printf("NPM			: "); gets(mahasiswa.npm);
			gotoxy(print,13); printf("Nama			: "); gets(mahasiswa.npm);
			gotoxy(print,14); printf("Prodi		: "); gets(mahasiswa.prodi);
			gotoxy(print,15); printf("Fakultas		: "); gets(mahasiswa.fakultas);
			gotoxy(print,16); printf("Alamat		: "); gets(mahasiswa.alamat);
			gotoxy(print,17); printf("Nama Ortu	: "); gets(mahasiswa.ortu);
			gotoxy(print,18); printf("No. Telp/HP	: "); gets(mahasiswa.no_hp);
			fseek(fp, -sizeof(mahasiswa), SEEK_CUR);
			fwrite(&mahasiswa, sizeof(mahasiswa), 1, fp);
			found=1;
			gotoxy(40,20); printf("Data berhasil diperbaharui...");
			break;
		}
	}
	if(!found){
		gotoxy(37,12); printf("Data Tidak Ditemukan!");
	}
	fclose(fp);
}

void hapus_mahasiswa(){
	clear();
	cetak_judul("Hapus Data Mahasiswa");
	char s_npm[15];
	int found=0;
	gotoxy(37,10); printf("Inputkan NPM : "); fflush(stdin);
	gets(s_npm);
	FILE *fp, *temp;
	fp=fopen("Data_Mahasiswa.txt", "ab+");
	temp=fopen("temp.txt", "wb");
	while(fread(&mahasiswa, sizeof(mahasiswa), 1, fp)==1){
		if(strcmp(s_npm, mahasiswa.npm)==0){
			fwrite(&mahasiswa, sizeof(mahasiswa), 1, temp);
		}
	}
	fclose(fp);
	fclose(temp);
	remove("Data_Mahasiswa.txt");
	rename("temp.txt", "Data_Mahasiswa");
	gotoxy(37,12); printf("Data telah dihapus...");
	return;
}

void main_tampilan(){
	int pilih;
	int x=2;
	
	while(1){
		gotoxy(x,8); printf("1. Input Data Mahasiswa");
		gotoxy(x,10); printf("2. Mencari Data Mahasiswa");
		gotoxy(x,12); printf("3. Mengubah Data Mahasiswa");
		gotoxy(x,14); printf("4. Menghapus Data Mahasiswa");
		gotoxy(x,16); printf("5. Keluar");
		gotoxy(x,18); printf("Menu Pilihan Anda : "); scanf("%d", &pilih);
		switch(pilih){
			case 1: add_mahasiswa(); break;
			case 2: cari_mahasiswa(); break;
			case 3: ubah_mahasiswa(); break;
			case 4: hapus_mahasiswa(); break;
			case 5: exit(0); break;
			default: break;
		}
	}
}


int main(){
	system("color F0");
	show();
	main_tampilan();
	return 0;
}
