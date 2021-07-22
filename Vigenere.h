/*
Nama : I Wayan Adi Sudirtayasa
NIM : 2001020039
Prodi : Teknik Informatika
Keterangan: File header ini mengandung fungsi enkripsi dan dekripsi
			dari metode Vigenere Chiper.
*/

#include <stdio.h>
#include <string.h>

//Fungsi enkripsi
void enkripsiVigenere(char pAsli[30], char kunci[30]){
	
	char alfabet[27]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	char pSamar[30];
	
	int lengthK, lengthP;
	
	lengthP = strlen(pAsli);
	lengthK = strlen(kunci);
	
	/*
	Varible penampung kunci dan pesan asli dalam bentuk angka. yang dimana 
	panjang arraynya sudah ditentukan dengan proses hitung panjang array 
	sebelumnya.
	*/
	int kunciV2[lengthK], pAsliV2[lengthP];
	
	/*
	Proses mengubah pesan asli ke dalam bentuk angka, yang dimana angka tersebut
	mewakili indeks pada array alfabet.
	*/
	for(int i = 0; i < lengthP; i++){
		
		for(int j = 0; j < 26; j++){
			
			if(pAsli[i] == alfabet[j]){
				
				pAsliV2[i] = j;
				
			}
			
		}
		
	}
	
	/*
	Proses mengubah kunci ke dalam bentuk angka, yang dimana angka tersebut
	mewakili indeks pada array alfabet
	*/
	for(int k = 0; k < lengthK; k++){
		
		for(int l = 0; l < 26; l++){
			
			if(kunci[k] == alfabet[l]){
				
				kunciV2[k] = l;
				
			}
			
		}
		
	}
	
	/*
	Proses menjumlahkan tiap elemen dari array kunci dan array pAsli.
	yang kemudian di modulus 26, dan hasilnya akan mewakili indeks dari alfabet 
	*/
	for(int m = 0; m < lengthP; m++){
		
		if(m < lengthK){
			
			pSamar[m] = alfabet[(kunciV2[m] + pAsliV2[m]) % 26];  
		
		/*
		Jika m melebihi atau sama dengan panjang dari kunci 
		maka indeks kunci akan di modulus lengthK(panjang kunci)
		agar kunci dapat disubstitusikan ke rumus dari awal lagi
		yaitu dari indeks ke-0 nya.
		*/	
		}else if(m >= lengthK){
			
			pSamar[m] = alfabet[(kunciV2[m % lengthK] + pAsliV2[m]) % 26];
			
		}	
		
	}
	
	
	
	printf("%s\n", pSamar);
		
}

//Fungsi dekripsi
void dekripsiVigenere(char pSamar[30], char kunci[30]){
	char alfabet[26]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char pAsli[30];
	
	int lengthK, lengthP, indeks;
	
	lengthP = strlen(pSamar);
	lengthK = strlen(kunci);
	
	int kunciV2[lengthK], pSamarV2[lengthP];
	
	for(int i = 0; i < lengthP; i++){
		
		for(int j = 0; j < 26; j++){
			
			if(pSamar[i] == alfabet[j]){
				
				pSamarV2[i] = j;
				
			}
			
		}
		
	}	
	
	for(int k = 0; k < lengthK; k++){
		
		for(int l = 0; l < 26; l++){
			
			if(kunci[k] == alfabet[l]){
				
				kunciV2[k] = l;
				
			}
			
		}
		
	}
	
	for(int m = 0; m < lengthP; m++){
		
		if(m < lengthK){
			
			/*
			Hal yang membedakan proses enkripsi dan dekripsi terletak 
			pada proses ini dimana saya menggunakan variable indeks untuk menyimpan nilai
			secara sementara. Dari variable indeks tersebut dapat dijadikan kondisi
			yaitu dimana jika indeks bernilai kurang dari 0 maka indeks akan ditambah 26
			agar kembali ke range dari huruf alfabet. Sementara jika lebih besar atau sama dengan
			0 maka indeks tersebut tak ada masalah.
			*/
			indeks = pSamar[m] - kunci[m];
			
			if(indeks < 0){
				
				pAsli[m] = alfabet[indeks + 26];
				
			}else if(indeks >= 0 ){
				
				pAsli[m] = alfabet[indeks];
				
			}
			
		}else if(m >= lengthK){
			
			indeks = pSamar[m] - kunci[m % lengthK];
			
			if(indeks < 0){
				
				pAsli[m] = alfabet[indeks + 26];
				
			}else if(indeks >= 0 ){
				
				pAsli[m] = alfabet[indeks];
				
			}
			
		}
		
	}
	
	printf("%s\n", pAsli);
}
