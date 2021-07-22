/*
Nama : I Wayan Adi Sudirtayasa
NIM : 2001020039
Prodi : Teknik Informatika
Keterangan: File header ini mengandung fungsi enkripsi dan dekripsi 
			dengan metode Subtitution Chiper.
*/

#include <stdio.h>
#include <string.h>

void enkripsiSubtitution(char pAsli[30], char kunci[26]){
	
	char alfabet[27]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	//alfabetV2 bertugas untuk menampung huruf yang telah disaring dengan kunci					
	char alfabetV2[26], pSamar[30]; 
	
	//pAsliV2 merupakan variabel untuk menampung pAsli versi angka
	int pAsliV2[30];
	
	int lengthP, 
		lengthK, 
	    notif = 0,
	    count = 0; 
	
	lengthP =  strlen(pAsli);
	lengthK = strlen(kunci);
	
	//menelusuri seluruh alfabet 
	for(int i = 0; i < 26; i++){
		
		//mencari apakah ada huruf dari alfabet yang sama dengan kunci
		for(int j = 0; j < lengthK; j++){
			
			//jika ada maka notif akan bernilai 1 
			//jika tidak notif akan bernilai 0
			if(alfabet[i] == kunci[j]){ 
				
				notif = 1;
				
			}
			
		}
		
		//jika notif bernilai 1 maka count akan bertambah 1
		//dan notif akan direset kembali menjadi 0
		if(notif == 1){
			
			count += 1;
			
			notif = 0;
			
		}else{
			
			/*
			agar alfabetV2 tetap menambahkan array secara teratur
			atau bisa dibilang tidak mengikuti penambahan nilai i.
			Maka dibuatkan count untuk membuat alfabetV2 menambahkan array 
			secara teratur.
			*/
			alfabetV2[i - count] = alfabet[i]; 
		
		}
		
	}
	
	//menggabungkan kunci dan alfabetV2 agar menjadi chiper alfabet.
	strcat(kunci, alfabetV2);
	
	/*
	mengubah pesan asli menjadi bentuk angka, yang dimana angka tersebut akan 
	mewakili indeks dari array yang menampung chiper alfabet.
	*/
	for(int k = 0; k < lengthP; k++){
		
		for(int l = 0; l < 26; l++){
			
			if(pAsli[k] == alfabet[l]){
				
				pAsliV2[k] = l;
				
			}
			
		}
		
	}
	
	
	/*
	proses memetakan hasil, dengan cara memanggil array kunci(yg sudah melalui proses penggabungan dengan alfabetV2)
	yang dimana array kunci ini dipanggil indeksnya sesuai isi dari indeks pAsliV2.
	*/
	for(int m = 0; m < lengthP; m++){
		
		pSamar[m] = kunci[pAsliV2[m]];
		
	}
	
	for(int n = 0; n < lengthP; n++){
		
		printf("%c", pSamar[n]);
		
	}
	
	printf("\n");
	
}

void dekripsiSubtitution(char pSamar[30], char kunci[26]){
	
	char alfabet[27]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	//alfabetV2 bertugas untuk menampung huruf yang telah disaring dengan kunci					
	char pAsli[30], alfabetV2[26]; 
	
	//pAsliV2 merupakan variabel untuk menampung pSamar versi angka
	int pSamarV2[30];
	
	int lengthP, lengthK; 
	int notif = 0; 
	int count = 0; 
	
	lengthP = strlen(pSamar);
	lengthK = strlen(kunci);
	
	//menelusuri seluruh alfabet 
	for(int i = 0; i < 26; i++){
		
		//mencari apakah ada huruf dari alfabet yang sama dengan kunci
		for(int j = 0; j < lengthK; j++){
			
			//jika ada maka notif akan bernilai 1 
			//jika tidak notif akan bernilai 0
			if(alfabet[i] == kunci[j]){ 
				
				notif = 1;
				
			}
			
		}
		
		//jika notif bernilai 1 maka count akan bertambah 1
		//dan notif akan direset kembali menjadi 0
		if(notif == 1){
			
			count += 1;
			
			notif = 0;
			
		}else{
			
			/*
			agar alfabetV2 tetap menambahkan array secara teratur
			atau bisa dibilang tidak mengikuti penambahan nilai i.
			Maka dibuatkan count untuk membuat alfabetV2 menambahkan array 
			secara teratur.
			*/
			alfabetV2[i - count] = alfabet[i]; 
		
		}
		
	}
	
	//menggabungkan kunci dan alfabetV2 agar menjadi chiper alfabet.
	strcat(kunci, alfabetV2);
	
	/*
	mengubah pesan yang disamarkan menjadi bentuk angka, yang dimana angka tersebut akan 
	mewakili indeks dari array yang menampung alfabet.
	*/
	for(int k = 0; k < lengthP; k++){
		
		for(int l = 0; l < 26; l++){
			
			if(pSamar[k] == kunci[l]){
				
				pSamarV2[k] = l;
				
			}
			
		}
		
	}
	
	/*
	proses memetakan hasil, dengan cara memanggil array kunci(yg sudah melalui proses penggabungan dengan alfabetV2)
	yang dimana array kunci ini dipanggil indeksnya sesuai isi dari indeks pSamarV2.
	*/
	for(int m = 0; m < lengthP; m++){
		
		pAsli[m] = alfabet[pSamarV2[m]];
		
	}
	
	
	for(int n = 0; n < lengthP; n++){
		
		printf("%c", pAsli[n]);
		
	}
	
	printf("\n");
	
}
