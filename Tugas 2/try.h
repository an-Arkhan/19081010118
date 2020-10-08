#ifndef TRY_H_INCLUDED
#define TRY_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

//struktur data penyimpanan//
struct data{
	char npm[15];
	char nama[50];
	char prodi[50];
	char fakultas[50];
	char alamat[50];
	char ortu[50];
	char no_hp[13];
};
struct data mahasiswa;

void gotoxy(int x, int y);
void buat_kotak();
void clear();
void show();
void cetak_judul(const char judul[]);
void add_mahasiswa();
void cari_mahasiswa();
void ubah_mahasiswa();
void hapus_mahasiswa();
void main_tampilan();

#endif
