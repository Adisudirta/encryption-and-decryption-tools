/*
Nama : I Wayan Adi Sudirtayasa
NIM : 2001020039
Prodi : Teknik Informatika
Keterangan: File program utama yang berisi switch case dan pemanggilan 
			fungsi-fungsi yang telah dibuat.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "Caesar.h"
#include "Vigenere.h"
#include "Subtitution.h"
#include "salam.h"


//int hasil = 0;



void homePage(){
	
	int jawaban, kunci;
	char pesan[65], kunciP[30];
	
	//Homepage atau halaman utama	
	homeGreeting();
	
	printf("Jawaban = ");
	scanf("%i", &jawaban);
	
	switch(jawaban){
		
		//Halaman utama Caesar Chiper
		case 1 :
			caesarGreeting();
			
			printf("Jawaban = ");
			scanf("%i", &jawaban);
			
			switch(jawaban){
				
				//Enkripsi pesan
				case 1: 
					caesarEnkripsiGreeting();
					printf("Inputkan pesan asli(maks. 60 karakter) \n\n=");
					getchar();
					gets(pesan);
							
					printf("____________________________________________________________________\n");
							
					printf("Inputkan kunci(0-26) \n\n= ");
					scanf("%i", &kunci);
							
					printf("____________________________________________________________________\n");
							
					printf("Pesan yang disamarkan\n\n= ");
							
					enkripsiCaesar(pesan, kunci);
							
					printf("_____________________________________________________________________\n");
					system("pause");
				break;
				
				//Dekripsi pesan	
				case 2:
					caesarDekripsiGreeting();
					printf("Inputkan pesan yang disamarkan!(maks. 60 karakter) \n\n=");
					getchar();
					gets(pesan);
							
					printf("____________________________________________________________________\n");
							
					printf("Inputkan kunci!(0-26) \n\n= ");
					scanf("%i", &kunci);
							
					printf("____________________________________________________________________\n");
							
					printf("Pesan Asli\n\n= ");
							
					dekripsiCaesar(pesan, kunci);
							
					printf("_____________________________________________________________________\n");
					system("pause");
				break;
					
				//Jika user input angka selain pada menu		
				default: 
					printf("Inputkan menu dengan benar!\n");
					system("pause");
			}
			
		break;
		
		//Halaman utama Vigenere Chiper
		case 2:
			vigenereGreeting();
			printf("Jawaban = ");
			scanf("%i", &jawaban);
			
			switch(jawaban){
				
				//Enkripsi Pesan
				case 1:
					enkripsiVigenereGreeting();
					printf("Inputkan pesan asli!(maks. 20 karakter) \n\n=");
					getchar();
					gets(pesan);
							
					printf("____________________________________________________________________\n");
							
					printf("Inputkan kunci!(maks. 10 karakter) \n\n= ");
					gets(kunciP);
							
					printf("____________________________________________________________________\n");
							
					printf("Pesan yang disamarkan\n\n= ");
							
					enkripsiVigenere(pesan, kunciP);
							
					printf("_____________________________________________________________________\n");
					system("pause");
				break;
				
				//Dekripsi pesan
				case 2:
					dekripsiVigenereGreeting();
					printf("Inputkan pesan yang disamarkan!(maks. 20 karakter) \n\n=");
					getchar();
					gets(pesan);
							
					printf("____________________________________________________________________\n");
							
					printf("Inputkan kunci!(maks. 10 karakter) \n\n= ");
					gets(kunciP);
							
					printf("____________________________________________________________________\n");
							
					printf("Pesan asli\n\n= ");
							
					dekripsiVigenere(pesan, kunciP);
							
					printf("_____________________________________________________________________\n");
					system("pause");
				
				break;
				
				//Jika user input angka selain di menu
				default: 
					printf("Inputkan menu dengan benar!\n");
					system("pause");
			}
			
		break;
		
		//Halaman utama Subtitution Chiper
		case 3:
			subtitutionGreeting();
			printf("Jawaban = ");
			scanf("%i", &jawaban);
			
			switch(jawaban){
				
				//Enkripsi pesan	
				case 1:
					enkripsiSubtitutionGreeting();	
					printf("Inputkan pesan asli!(maks. 20 karakter) \n\n=");
					getchar();
					gets(pesan);
							
					printf("____________________________________________________________________\n");
							
					printf("Inputkan kunci!(maks. 26 karakter) \n\n= ");
					gets(kunciP);
							
					printf("____________________________________________________________________\n");
							
					printf("Pesan yang disamarkan\n\n= ");
							
					enkripsiSubtitution(pesan, kunciP);
							
					printf("_____________________________________________________________________\n");
					system("pause");
				break;
				
				//Dekripsi pesan
				case 2:
					dekripsiSubtitutionGreeting();
					printf("Inputkan pesan yang disamarkan!(maks. 20 karakter) \n\n=");
					getchar();
					gets(pesan);
							
					printf("____________________________________________________________________\n");
							
					printf("Inputkan kunci!(maks. 26 karakter) \n\n= ");
					gets(kunciP);
							
					printf("____________________________________________________________________\n");
							
					printf("Pesan asli\n\n= ");
							
					dekripsiSubtitution(pesan, kunciP);
							
					printf("_____________________________________________________________________\n");
					system("pause");
				break;
				
				//Jika user input angka selain di menu
				default:
					printf("Inputkan menu dengan benar!\n");
					system("pause");	 
					
			}		
					
		break;	
		
		//Jika user input angka selain di menu	
		default: 
			printf("Inputkan menu dengan benar!\n");
			system("pause");
	}
	
	
	//metode rekursif untuk kembali ke menu utama(homepage)
	system("cls");
	printf("1 = Kembali ke homepage\n");
	printf("0 = End program\n\n");
	printf("Jawaban = ");
	scanf("%i", &jawaban);
	
	if(jawaban == 1){
		
		homePage();
		
	}
				
}

//Fungsi main saya gunakan hanya untuk mengecek password
void main(){
	int ulangi = 1;
    int pass;
	

	while(ulangi == 1){
		
		system("cls");
		printf("____________________________________________________________________\n\n");
		printf("Demi menjaga kerahasiaan, pengguna diharapkan menginputkan password!\n\n");
		printf("PASSWORD: ");
		scanf("%i", &pass);
		printf("____________________________________________________________________\n");
		
		if(pass == 2001020039){
						
			homePage();
			break;
			
		}else{
			
			printf("MAAF PASSWORD ANDA SALAH!\n");
			printf("____________________________________________________________________\n\n");
		
			printf("Mau Coba lagi?\n\n");
			printf("1 = Ya\n");
			printf("0 = Tidak\n\n");
			printf("Jawaban = ");
			scanf("%i", &ulangi);
		}
		
	}
	
}


