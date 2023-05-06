#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <string.h>

//	==================================================PROCEDURE MENU LOGIN ADMIN=========================================================================
void login_admin(){
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t||=======================================================================||\n");	
	printf("\t\t\t||                                                                       ||\n");
	printf("\t\t\t||                        LOGIN ADMINISTRATOR                            ||\n");
	printf("\t\t\t||                                                                       ||\n");
	printf("\t\t\t||=======================================================================||\n");
}
//	==================================================PROCEDURE MENU ADMIN===============================================================================
void menu_admin(){
	printf("\n\n");
	printf("\t\t\t||=======================================================================||\n");	
	printf("\t\t\t||                             CHOCO MATES                               ||\n");
	printf("\t\t\t||                          MENU ADMINISTRATOR                           ||\n");
	printf("\t\t\t||=======================================================================||\n");
	printf("\t\t\t|| 1. Ubah Username & Password                                           ||\n");
	printf("\t\t\t|| 2. Data Customer                                                      ||\n"); 
	printf("\t\t\t|| 3. Sistem Penjualan                                                   ||\n");
	printf("\t\t\t|| 4. Kembali                                                            ||\n");		
	printf("\t\t\t||=======================================================================||\n\n");	
}

//	==================================================PROCEDURE TAMPILAN GANTI USERNAME DAN PASSWORD ADMIN===============================================
void gantiUsernamePassword(){
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t||=======================================================================||\n");	
	printf("\t\t\t||                                                                       ||\n");
	printf("\t\t\t||                     Change Account Administrator                      ||\n");
	printf("\t\t\t||                                                                       ||\n");
	printf("\t\t\t||=======================================================================||\n");
}

//	==================================================PROCEDURE READ FILE USERNAME=======================================================================
void ambilusername(){
	FILE *file; //pointer ke file
	file=fopen("testuser.txt", "r"); //membaca file password.txt
	fscanf(file,"%s",username); //menyimpan data pada variabel password
	fclose(file); //menutup file
}
//	==================================================PROCEDURE READ FILE PASSWORD=======================================================================
void ambilpassword(){
	FILE *file; //pointer ke file
	file=fopen("testpass.txt", "r"); //membaca file password.txt
	fscanf(file,"%s",password); //menyimpan data pada variabel password
	fclose(file); //menutup file
}
//	==================================================PROCEDURE GANTI USERNAME BARU======================================================================
void gantiuser(){
	char userBaru[10];
	FILE *file;
	
	file=fopen("testuser.txt","w");
	fgets(userBaru, sizeof(userBaru), stdin);
	printf("\n\n");
	printf("\t\t\t\t\t\t- Masukkan Username Baru : ");
	fgets(userBaru, sizeof(userBaru), stdin);
	
	fputs(userBaru,file);
	fclose(file);
}
//	==================================================PROCEDURE GANTI PASSWORD BARU======================================================================
void gantipass(){
	char passBaru[10];
	FILE *file;
	
	file=fopen("testpass.txt","w");
	printf("\t\t\t\t\t\t- Masukkan Password Baru : ");
	fgets(passBaru, sizeof(passBaru), stdin);
	
	fputs(passBaru,file);
	fclose(file);
}
//	==================================================PROCEDURE READ RECORD IDENTITAS CUSTOMER===========================================================
void Read_ID_customer(char nama[30],char alamat[44],char email[37]){
	FILE *filetubes;
	data_user dataUser;
 
	printf("\n\n\n");
	printf("\t||===============================================================================================================================================||\n");	
	printf("\t||                                                                 CHOCO MATES                                                                   ||\n");
	printf("\t||                                                              IDENTITAS CUSTOMER                                                               ||\n");
	printf("\t||===============================================================================================================================================||\n");
	printf("\t||                   Nama:                  ||                            Alamat:                         ||                Email:               ||\n");
	printf("\t||===============================================================================================================================================||\n");

	if ( (filetubes=fopen("datacustomer.txt","rt")) == NULL ){
		printf("File tidak dapat dibuka!\r\n");
		exit(1);
	}
	while ( (fread(&dataUser, sizeof(dataUser),1, filetubes)) == 1)
		printf("\t|| %-23s                  || %-38s                     || %-36s||\r\n", dataUser.nama, dataUser.alamat,dataUser.email);
		printf("\t||===============================================================================================================================================||\n\n");
		fclose(filetubes);
}

//	==================================================PROCEDURE MENU SISTEM DATA COKLAT====================================================================
void sistemDataCoklat(){
		printf("\n\n\n\n\n\n");
		printf("\t\t\t||=======================================================================||\n");	
		printf("\t\t\t||                              CHOCO MATES                              ||\n");
		printf("\t\t\t||                          MENU ADMINISTRATOR                           ||\n");
		printf("\t\t\t||=======================================================================||\n");
        printf("\t\t\t|| 1. Input Data Penjualan                                               ||\n");
        printf("\t\t\t|| 2. Hapus Data Penjualan                                               ||\n");
        printf("\t\t\t|| 3. Kembali                                                            ||\n");
        printf("\t\t\t||=======================================================================||\n\n");
}

//	==================================================PROCEDURE INPUT coklat===============================================================================
void restok(char nama[50],int kodeCoklat,int harga){
	FILE *filetubes;
		char jawab;
		int kodeCoklatInput;
		data coklat;
		input:
		if ( (filetubes=fopen("datacoklat.dat","a+b")) == NULL ){
			 printf("File tidak dapat dibuat!\r\n");
			 exit(1);
		}
			printf("\n\t\t     =====================================================================================================================\n\n\n");
			printf("\t\t     Masukkan Kode Coklat      : "); fflush(stdin);
			scanf("%d",&kodeCoklatInput);
			while (fread(&coklat, sizeof(coklat),1, filetubes)){
				if (kodeCoklatInput==coklat.kodeCoklat){
					printf("\n\n\t\t\t\t\t\t\tKode Coklat Tersedia\n");
					fclose(filetubes);
					goto input;
				}
				
			}
					
			coklat.kodeCoklat=kodeCoklatInput; fflush(stdin);
			printf("\t\t     Masukkan Nama Coklat     : "); fflush(stdin);
			gets(coklat.nama);
			printf("\t\t     Masukkan Harga Coklat     : "); fflush(stdin);
			scanf("%d",&coklat.harga);
			fwrite(&coklat, sizeof(coklat), 1, filetubes);
			fclose(filetubes); 
			printf("\n\n\n\t\t\t\t\t\t\t\t      Data telah tersimpan \n");
			printf("\t\t     =====================================================================================================================\n");	
			printf("\n\n\t\t     Masukkan data kembali? [y/n] : ");fflush(stdin);
			scanf("%s",&jawab);
			switch(jawab){
				case 'y':
					goto input;break;
					
			}
}

//	==================================================PROCEDURE HAPUS KODE coklat==========================================================================
void hapusKodeCoklat(char nama[50],int kode_brg,int harga){
	FILE *fpo;
	FILE *fpt;
	FILE *filetubes;
	data coklat;
	char jawab;
	int s,kode;
		hapusdata:
		printf("\t\t     - Masukan Kode Coklat yang ingin Dihapus: ");
		scanf("%d",&kode);
		if (cek_kode(coklat, kode)){
			fpo = fopen("datacoklat.dat","rb");
			fpt = fopen("temp.dat","wb");
			while (fread(&coklat, sizeof(coklat), 1, fpo)){
				s = coklat.kodeCoklat;
				if ( s != kode){
					//Menyalin data file yang tidak ingin dihapus
					fwrite(&coklat, sizeof(coklat), 1, fpt);
				}
			}
			fclose(fpo);
			fclose(fpt);
			fpo = fopen("datacoklat.dat","wb");
			fpt = fopen("temp.dat","rb");
			while(fread(&coklat,sizeof(coklat),1,fpt)){
				fwrite(&coklat,sizeof(coklat),1,fpo);
			}
			printf("\n\n\n\t\t\t\t\t\t\t\t     Data Berhasil Dihapus...\n");
			fclose(fpo);
			fclose(fpt);
		}
	else{
		fpo = fopen("datacoklat.dat","wb");
		fclose(fpo);
	}
		printf("\n\n\t\t     Hapus Data Kembali? [y/n] : ");
		scanf("%s",&jawab);
		printf("\t\t     =====================================================================================================================\n\n");
			switch(jawab){
				case 'y':
					goto hapusdata;break;
			}
		
}
//	==================================================FUNCTION CEK KODE==================================================================================
int cek_kode(data coklat,int id){
	FILE *filetubes;
	int c = 0;
	
	if (empty(coklat) == 1 ){
		filetubes = fopen("datacoklat.dat","rb");
		while(!feof(filetubes)){
			fread(&coklat, sizeof(coklat),1,filetubes);
			if( id == coklat.kodeCoklat){
				fclose(filetubes);
				return 1;
			}
		}
		fclose(filetubes);
		return 0;
	}
	else{
		return 0;
	}
}
//	==================================================FUNCTION EMPTY=====================================================================================
int empty(data coklat){
	int c = 0;
	FILE *filetubes;
	
	filetubes = fopen("datacoklat.dat", "rb");
	while (fread(&coklat, sizeof(coklat), 1, filetubes))
	c = 1;
	fclose(filetubes);
	return c;
}

