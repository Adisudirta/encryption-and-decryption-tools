/*
Nama : I Wayan Adi Sudirtayasa
NIM : 2001020039
Prodi : Teknik Informatika
Keterangan: File header ini mengandung fungsi enkripsi dan dekripsi 
			dengan metode Caesar Chiper.
*/

#include <stdio.h>
#include <string.h>

//Fungsi enkripsi
void enkripsiCaesar(char pAsli[77], int kunci){
	
	int pSamar;
	
	//Menelusuri semua karakter pada pesan asli.
	for(int i = 0; i < strlen(pAsli); i++){
		
		/*
		Jika pesan asli mengandung spasi maka varible pSamar akan diisi 
		kode ASCII dari spasi.
		*/
		if(pAsli[i] == ' '){
			
			pSamar = ' ';
		
		/*
		jika huruf pada pesan asli kode ASCII nya lebih dari sama denagan
		'A'(65) dan kurang dari sama dengan 'Z'(90), maka huruf dari pesan 
		asli akan di substitusikan ke rumus enkripsi caesar chiper yaitu
		C = E(P)= (P + K) mod 26 
		*/	
		}else if((pAsli[i] >= 'A') && (pAsli[i] <= 'Z')){  //Ini range untuk huruf kapital(65 - 90).
			
			/*
			tujuan dari mengurangi dengan kode ASCII dari 'A' 
			yaitu agar nilai dari huruf dapat ke bentuk index alfabet yaitu
			0 - 25
			
			Kemudian diakhir akan ditambahkan kode ASCII dari 'A' lagi 
			agar kembali ke range dari kode ASCII dari huruf kapital(65 - 90).
			*/
			pSamar = ((pAsli[i] + kunci - 'A') % 26) + 'A';
		
		
		}else if((pAsli[i] >= 'a') && (pAsli[i] <= 'z')){ //Ini range untuk huruf kecil(97 - 122).
			
			pSamar = ((pAsli[i] + kunci - 'a') % 26) + 'a';
			
		}
		
		printf("%c", pSamar);
		
	}
	
	printf("\n");
}

//Fungsi dekripsi
void dekripsiCaesar(char pSamar[77], int kunci){
	int pAsli;
	
	for(int i = 0; i < strlen(pSamar); i++){
		
		if(pSamar[i] == ' '){	// Jika mengandung sepasi
			
			pAsli = ' ';
		
		}else if((pSamar[i] >= 'A') && (pSamar[i] <= 'Z')){   // Ini range untuk huruf kapital(65 - 90)
			
			/*
			Pada proses dekripsi saya tidak mengisikan modulus 26 pada rumus
			karena pada proses dekripsi nilai akan bergerak ke kiri alias
			nilainya akan mengecil. jika nilai kecil di modulus dengan 26 
			maka hasilnya adalah nilai itu sendiri.
			*/
			pAsli = pSamar[i] - kunci;
			
			/*
			Jika hasil dari rumus kurang dari range (65 - 90)
			maka hasil akan ditambah 26(jmlh alfabet) agar
			kembali ke rangenya
			*/
			if(pAsli < 'A'){
				
				pAsli += 26;
				
			}
			
			
		}else if((pSamar[i] >= 'a') && (pSamar[i] <= 'z')){    // Ini range untu huruf kecil(97 - 122)
			
			pAsli = pSamar[i] - kunci;
			
			if(pAsli < 'a'){
				
				pAsli += 26;
				
			}
			
		}
		
		printf("%c", pAsli);
		
	}
	
	printf("\n");
	
}
