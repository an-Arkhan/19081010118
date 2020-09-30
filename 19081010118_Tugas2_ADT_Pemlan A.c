#include <stdio.h>
#include <string.h>

typedef char string[256];

typedef struct{
string Tanggal;
string Bulan;
string Tahun;
}Lahir;

typedef struct {
string Nama;
string NPM;
Lahir L;
char Golongan_Darah[1];
float Tinggi_Badan;
float Berat_Badan;
}Mahasiswa;

 

Mahasiswa InputDataMahasiswa (Mahasiswa M) {

printf("INPUT DATA MAHASISWA\n");
printf("--------------------\n");
printf("Nama 		: "); scanf("%[^\n]", &M.Nama);
printf("NPM 		: "); scanf("%s", &M.NPM);
printf("Tgl Lahir (Contoh: DD MM YYYY) \n");
printf(" 		: ");scanf("%s%s%s", &M.L.Tanggal, &M.L.Bulan, &M.L.Tahun);
printf("Golongan Darah 	: "); scanf("%s", &M.Golongan_Darah);
printf("Tinggi Badan 	: "); scanf("%f", &M.Tinggi_Badan);
printf("Berat Badan 	: "); scanf("%f", &M.Berat_Badan);
printf("\n\n\n");

return M;
}

void TampilkanDataMahasiswa (Mahasiswa M) {

 

printf("DATA MAHASISWA\n");
printf("---------------\n");
printf("Nama 		: %s\n", M.Nama);
printf("NPM 		: %s\n", M.NPM);
printf("Tgl Lahir 	: %s - %s - %s \n", M.L.Tanggal, M.L.Bulan, M.L.Tahun);
printf("Golongan Darah	: %s\n", M.Golongan_Darah);
printf("Tinggi Badan	: %.2f\n", M.Tinggi_Badan);
printf("Berat Badan	: %.2f\n", M.Berat_Badan);
printf("\n\n");
}

int main() {
Mahasiswa M;

M=InputDataMahasiswa(M);
TampilkanDataMahasiswa(M);

return 0;
}
