#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char npm[15];
	char nama[50];
	char prodi[50];
	char fakultas[50];
	char alamat[50];
	char ortu[50];
	char no_hp[13];
};struct data mahasiswa;

void add_mahasiswa(){
	printf("\n\n===================\n");
	printf("Input Data Mahasiswa\n");
	FILE *fp;
	fp=fopen("Data_Mahasiswa.txt","ab+");
	if(fp==NULL){
		
	}
	else{
		int a=1;
		int b;
		printf("Jumlah Data Mahasiswa yang akan Ditambahkan :"); scanf("%d", &b);
		while(a<=b){
			fflush(stdin);
			printf("NPM		: "); gets(mahasiswa.npm);
			printf("Nama		: "); gets(mahasiswa.nama);
			printf("Prodi		: "); gets(mahasiswa.prodi);
			printf("Fakultas	: "); gets(mahasiswa.fakultas);
			printf("Alamat		: "); gets(mahasiswa.alamat);
			printf("Nama Ortu	: "); gets(mahasiswa.ortu);
			printf("No. Telp/HP	: "); gets(mahasiswa.no_hp);
			fwrite(&mahasiswa, sizeof(mahasiswa), 1, fp);
			a++;
		}
		printf("Data berhasilkan dimasukkan...\n");
		printf("==============================");
	}
	fclose(fp);
	return;
}

void cari_mahasiswa(){
	printf("\n\n===================\n");
	printf("Cari Data Mahasiswa\n");
	char s_npm[15];
	FILE *fp;
	int found=0;
	printf("Inputkan NPM : "); fflush(stdin);
	gets(s_npm);
	fp=fopen("Data_Mahasiswa.txt", "ab+");
	while(fread(&mahasiswa, sizeof(mahasiswa), 1, fp)==1){
		if(strcmp(s_npm, mahasiswa.npm)==0)
		found=1;
		break;
	}
	if(found == 1){
		printf("\n==>Data Ditemukan\n");
		printf("NPM		: %s\n", mahasiswa.npm);
		printf("Nama		: %s\n", mahasiswa.nama);
		printf("Prodi		: %s\n", mahasiswa.prodi);
		printf("Fakultas	: %s\n", mahasiswa.fakultas);
		printf("Alamat		: %s\n", mahasiswa.alamat);
		printf("Nama Ortu	: %s\n", mahasiswa.ortu);
		printf("No. Telp/HP	: %s\n", mahasiswa.no_hp);
	}
	else{
		printf("Data Tidak Ditemukan!\n");
		printf("==============================");
	}
	fclose(fp);
	return;
}

void ubah_mahasiswa(){
	printf("\n\n===================\n");
	printf("Ubah Data Mahasiswa\n");
	char s_npm[15];
	int found=0, print=37;
	printf("Inputkan NPM : "); fflush(stdin);
	gets(s_npm);
	FILE *fp;
	fp = fopen("Data_Mahasiswa.txt", "rb+");
	while(fread(&mahasiswa, sizeof(mahasiswa), 1, fp)==1){
		if(strcmp(s_npm, mahasiswa.npm)==0){
			fflush(stdin);
			printf("NPM		: "); gets(mahasiswa.npm);
			printf("Nama		: "); gets(mahasiswa.nama);
			printf("Prodi		: "); gets(mahasiswa.prodi);
			printf("Fakultas	: "); gets(mahasiswa.fakultas);
			printf("Alamat		: "); gets(mahasiswa.alamat);
			printf("Nama Ortu	: "); gets(mahasiswa.ortu);
			printf("No. Telp/HP	: "); gets(mahasiswa.no_hp);
			fseek(fp, -sizeof(mahasiswa), SEEK_CUR);
			fwrite(&mahasiswa, sizeof(mahasiswa), 1, fp);
			found=1;
			printf("Data berhasil diperbaharui...\n");
			break;
		}
	}
	if(!found){
		printf("Data Tidak Ditemukan!\n");
		("==============================");
	}
	fclose(fp);
	return;
}

void hapus_mahasiswa(){
	printf("\n\n===================\n");
	printf("Hapus Data Mahasiswa\n");
	char s_npm[15];
	int found=0;
	printf("Inputkan NPM : "); fflush(stdin);
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
	printf("Data telah dihapus...");
	return;
}

void bnseq(){
	int data[100] = {3, 9, 11, 12, 15, 17, 23, 31, 35};
	int l,r,m;
	int n=9;
	int cari=17;
	l=0;
	r=n-1;
	int ktm=0;
	while(l<=r && ktm==0){
		m=(l+r)/2;
		printf("data tengah : %d\n", m);
		if(data[m]==cari) ktm=1;
		else if (cari < data[m]){
			printf("cari dikiri\n");
			r=m-1;
		}
		else{
			l=m+1;
			printf("cari dikanan\n");
		}
	}
	if(ktm==1) printf("data ada\n");
	else printf("data tidak ada\n");
}

int main(){
	
	int pilihan, lanjut;
	
	printf("======NAMA	: Auliya Arkhan	=====\n");
    printf("======NPM	: 19081010118	=====\n\n");
    
	do{
		printf("\n==Data Mahasiswa==\n");
		printf("1. Input data mahasiswa\n");
		printf("2. Tampilkan data mahasiswa\n");
		printf("3. Ubah data mahasiswa\n");
		printf("4. Hapus data mahasiswa\n");
		printf("5. Binary Sequence\n");
		printf("============================\n");
		printf("pilih menu [1-5]: "); scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1:
				add_mahasiswa();
				break;
			case 2:
				cari_mahasiswa();
				break;
			case 3:
				ubah_mahasiswa();
				break;
			case 4:
				hapus_mahasiswa();
				break;
			case 5:
				bnseq();
				break;
			default:
				printf("\nMaaf nilai tidak valid");
				break;
		}printf("\n|Mau coba lagi? (Ketik 'Y' atau 'y' untuk lanjut) : "); scanf("%s", &lanjut);
	}while((lanjut=='Y')||(lanjut=='y'));
	return 0;
}
