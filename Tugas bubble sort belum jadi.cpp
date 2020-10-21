#include <iostream>
#include <fstream>
#include <string>
#include <limits>

//maaf pak saya bingung, caranya gimana bahkan tugas array of struct saya masih error
//bahkan saya meniru persis tutorial yang ada di youtube, akan tetapi masih saja error
//ini source code array of struct yang baru karena saya sudah menyerah dengan yang lama
//mohon bimbingannya pak
using namespace std;

struct mahasiswa{
	int pk;
	string NPM;
	string Nama;
	string Jurusan;
	string Fakultas;
	string goldar;
	string hobby;
	char ipk;
};

int getOption();
void checkDatabase(fstream &data);


void writeData(fstream &data, int posisi, mahasiswa &inputmahasiswa){
	data.seekp((posisi-1)*sizeof(inputmahasiswa), ios::beg);
	data.write(reinterpret_cast<char*>(&inputmahasiswa),sizeof(mahasiswa));
}

int getDataSize(fstream &data){
	int start, end;
	data.seekg(0,ios::beg);
	start = data.tellg();
	data.seekg(0,ios::end);
	end = data.tellg();
	return(end-start)/sizeof(mahasiswa);
}

mahasiswa readData(fstream &data, int posisi){
	mahasiswa readmahasiswa;
	data.seekg((posisi-1)*sizeof(mahasiswa),ios::beg);
	data.read(reinterpret_cast<char*>(&readmahasiswa),sizeof(mahasiswa));
	return readmahasiswa;
}

void addDatamahasiswa(fstream &data){
	
	mahasiswa inputmahasiswa, lastmahasiswa;
	
	int size=getDataSize(data);
	
	cout << "ukuran data : " << size << endl;
	
	if(size==0){
		inputmahasiswa.pk = 1;
	}else{
		lastmahasiswa = readData(data,size);
		cout << "pk = " << lastmahasiswa.pk << endl;
		inputmahasiswa.pk = lastmahasiswa.pk + 1;
	}
	
	//readData(data,size);
	cout << "Nama : ";
	getline(cin,inputmahasiswa.Nama);
	cout << "Jurusan : ";
	getline(cin,inputmahasiswa.Jurusan);
	cout << "Fakultas : ";
	getline(cin,inputmahasiswa.Fakultas);
	cout << "NPM : ";
	getline(cin,inputmahasiswa.NPM);
	//cout << "Golongan Darah : ";
	//getline(cin,inputmahasiswa.goldar);
	//cout << "Hobby : ";
	//getline(cin,inputmahasiswa.hobby);
	//cout << "IPK : ";
	//getline(cin,inputmahasiswa.ipk);
	
	writeData(data,size+1,inputmahasiswa);
}

void displaydatamahasiswa(fstream &data){
	int size = getDataSize(data);
	mahasiswa showmahasiswa;
	cout << "no.\tpk.\tNPM.\tNama.\tJurusan.\tFakultas" << endl;
	for(int i=1; i<=size; i++){
		showmahasiswa = readData(data,i);
		cout << i << "\t";
		cout << showmahasiswa.pk << "\t";
		cout << showmahasiswa.NPM << "\t";
		cout << showmahasiswa.Nama << "\t";
		cout << showmahasiswa.Jurusan << "\t";
		cout << showmahasiswa.Fakultas << endl;
	}
}

int main(){
	
	fstream data;
	
	checkDatabase(data);
	
	int option = getOption();
	char cont;
	
	enum option{CREATE = 1, READ, UPDATE, DELETE, FINISH};
	
	while(option != FINISH){
		
		switch(option){
			case CREATE:
				cout << "menambah data mahasiswa" << endl;
				addDatamahasiswa(data);
				break;
			case READ:
				cout << "tampilkan data mahasiswa" << endl;
				displaydatamahasiswa(data);
				break;
			case UPDATE:
				cout << "ubah data mahasiswa" << endl;
				break;
			case DELETE:
				cout << "hapus data mahasiswa" << endl;
				break;
			default:
				cout << "Nilai tidak valid" << endl;
		}
		lable_cont:
		
		cout << "Lanjut?[y/n] : ";
		cin >> cont;
		if( (cont == 'y') | (cont == 'Y')){
			option = getOption();
		}
		else if((cont == 'n') | (cont == 'N')){
			break;
		}
		else{
			goto lable_cont;
		}
	}
	
	cout << "program berakhir" << endl;
	
	cin.get();
	return 0;
}

void checkDatabase(fstream &data){
	data.open("data.bin", ios::out | ios::in | ios::binary);
	
	//check file
	if(data.is_open()){
		cout << "data exist" << endl;
	}
	else{
		cout << "data doesn't exist, make a new data" << endl;
		data.close();
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}

int getOption(){
	int input;
	//system("cls");
	cout << "\nData Mahasisiswa" << endl;
	cout << "===========================" << endl;
	cout << "1. Tambah data mahasiswa" << endl;
	cout << "2. Tampilkan data mahasiswa" << endl;
	cout << "3. Ubah data mahasiswa" << endl;
	cout << "4. Hapus data mahasiswa" << endl;
	cout << "5. Selesai" << endl;
	cout << "===========================" << endl;
	cout << "pilih [1-5] : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return input;
}










