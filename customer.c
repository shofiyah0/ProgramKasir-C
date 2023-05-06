#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <string.h>


//	==================================================PROCEDURE MENU_CUSTOMER============================================================================
void menu_customer(){
	printf("\n\n\n");
	printf("\t\t\t||=======================================================================||\n");	
	printf("\t\t\t||                               CHOCO MATES                             ||\n");
	printf("\t\t\t||                              MENU CUSTOMER                            ||\n");
	printf("\t\t\t||=======================================================================||\n");
	printf("\t\t\t|| 1. Informasi Customer                                                 ||\n");
	printf("\t\t\t|| 2. Transaksi                                                          ||\n"); 
	printf("\t\t\t|| 3. Kembali                                                            ||\n");	
	printf("\t\t\t||=======================================================================||\n\n");	
}
//	==================================================PROCEDURE PENJELASAN BENEFIT MENJADI MEMBER========================================================
void informasicustomer(){
	char informasi[300];
	FILE *filetubes;
	printf("\n\n\n");
	if((filetubes = fopen("infocustomer.txt","r")) == NULL){
		printf("File ini kosong !!!");		
		exit(1);
	}
	while(fgets(informasi, sizeof(informasi),filetubes)){
		printf("%s",informasi);
	}
	fclose(filetubes);
}
//	==================================================PROCEDURE READ RECORD DATA COKLAT====================================================================
void vdaftarcoklat(char nama[50],int kodeCoklat, int harga){
	FILE *filetubes;
	data coklat;
	printf("\n\n\n");
   	printf("\n\n\n");
    printf("\t\t\t||=================================================================================||\n");	
	printf("\t\t\t||                                    CHOCO MATES                                  ||\n");
	printf("\t\t\t||                                   DAFTAR COKLAT                                 ||\n");
	printf("\t\t\t||=================================================================================||\n");
    printf("\t\t\t||---------------------------------------------------------------------------------||\n");
    printf("\t\t\t|| KODE COKLAT |           NAMA COKLAT          |             HARGA COKLAT         ||\n");
    printf("\t\t\t||---------------------------------------------------------------------------------||");
    
    if ( (filetubes=fopen("datacoklat.dat","rb")) == NULL )
	{
	printf("File tidak dapat dibuka!\r\n");
	exit(1);
	}
	printf("\n");
	while ( (fread(&coklat, sizeof(coklat),1, filetubes)) == 1)
		printf("\t\t\t||  %-4d  | %-28s | %-25s  Rp.%-9d ||\r\n", coklat.kodeCoklat, coklat.nama,coklat.jenis,coklat.harga);
	 	printf("\t\t\t||---------------------------------------------------------------------------------||");
		fclose(filetubes);
    
}

//	==================================================PROCEDURE PEMBAYARAN DAN STRUK=====================================================================
void vpembayaran(char nama[50], int kodeCoklat, int harga){
	
	int i, j, a, jumlahBelanja, jumlahUnit, total, totalDiskon, potongan, hasilPotongan, kembalian, jumlahUang,kodeBarang, poin;
	char vBayar, vTanyaID;
	
	data coklat;
	users user[100];
	FILE *filetubes;
	
	printf("\n\n\t\t     => Berapa Coklat yang akan dibeli: ");
	scanf("%d",&jumlahBelanja);
		for (i=1;i<=jumlahBelanja;i++){
			filetubes=fopen("datacoklat.dat","rb");
			kodeCoklat:
			printf("\t\t     => Masukkan Kode Coklat   : ");
			scanf("%d",&kodeBarang);
				while ((fread(&coklat, sizeof(coklat),1, filetubes))==1){
								
					if (kodeBarang == coklat.kodeCoklat){
						user[i].nama_coklat=coklat.nama;
						user[i].jenis=coklat.jenis;
						user[i].harga=coklat.harga;
				
							printf("\t\t     => Masukkan Jumlah Coklat : ");
							scanf("%d",&jumlahUnit);
							user[i].subtotal=hitungsubtotal(user[i].harga,jumlahUnit);
							printf("\t\t     ===================================================================================================================== \n");
							printf("\t\t     Nama Coklat   : %s\n",user[i].nama_coklat);
							printf("\t\t     Tarif Coklat  : Rp.%d\n",user[i].harga);
							printf("\t\t     Subtotal    : Rp.%d \n",user[i].subtotal);
							printf("\t\t     ===================================================================================================================== \n");
	
							
					}	
					
				}
				fclose(filetubes);																		 
	 	}
	
		total=0;
		for(j=1;j<=jumlahBelanja;j++){
			total=total+user[j].subtotal;	
		}
			
		printf("\t\t     Total Bayar : Rp.%d \n",total);
		printf("\t\t     ===================================================================================================================== \n");
		lanjutbayar:
		printf("\t\t     => Lanjutkan Pembayaran? [y/n] : ");
		scanf("%s",&vBayar);								
			switch(vBayar){
				case 'y':
				
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				isiID:
				printf("\t\t\t\t\t\t\t   Apakah anda pernah mengisi identitas ? [y/n] : ");
				scanf("%s",&vTanyaID);
				system("cls");
				switch (vTanyaID){
					case 'y':
						goto hitung;break;
					case 'n':
						goto masukanID;break;
					default:
						printf("Input Salah!\n");
						goto isiID;break;
				}break;
				masukanID:
				ID_customer();
				system("cls");
				
				hitung:	
				totalDiskon=tot_diskon(total);
				hasilPotongan=potonganharga(potongan,total);
				printf("\n\n\n\n\n\n\n");
				input:
				printf("\t\t\t\t\t\t\t     => Total Awal Bayar           : Rp.%d",total);	
				printf("\n\t\t\t\t\t\t\t     => Potongan Harga             : Rp.%d",hasilPotongan);
				printf("\n\t\t\t\t\t\t\t     => Total Akhir Bayar          : Rp.%d \n",totalDiskon);								
				printf("\n\t\t\t\t\t\t\t     => Masukkan jumlah uang bayar : Rp.");
				scanf("%d",&jumlahUang);
				
				kembalian=hitungkembalian(jumlahUang,totalDiskon);
					if (jumlahUang<totalDiskon){
						system("cls");
						printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t     Mohon maaf uang anda tidak mencukupi \n\n");
						goto input;
					}
					
				system("cls");
				printf("\n\n\n\n\n\n");								
				printf("\t\t\t\t\t\t\t***********************************************************\t\n");
				printf("\t\t\t\t\t\t\t*                        CHOCO MATES                        *\t\n");
				printf("\t\t\t\t\t\t\t***********************************************************\t\n");
			
				a=1;
				while (a<=jumlahBelanja){	
					printf("\t\t\t\t\t\t\t===========================================================\n");	
					printf("\t\t\t\t\t\t\t                        Coklat ke-%d                       \n\n",a);
					printf("\t\t\t\t\t\t\tTarif coklat          : Rp.%d \n",user[a].harga);
					printf("\t\t\t\t\t\t\tSubtotal            : Rp.%d \n",user[a].subtotal);	
					a++;	
				}
				printf("\t\t\t\t\t\t\t===========================================================\n");
				setwaktu();
				printf("\t\t\t\t\t\t\tPotongan Harga      : Rp.%d  \n",hasilPotongan);
				printf("\t\t\t\t\t\t\tTotal Bayar         : Rp.%d  \n",totalDiskon);
				printf("\t\t\t\t\t\t\tJumlah uang bayar   : Rp.%d \n",jumlahUang);
				printf("\t\t\t\t\t\t\tKembalian           : Rp.%d \n\n",kembalian);
				poin=hitungpoin;
				if (totalDiskon<250000){
        		printf("\n\t\t\t                                Anda tidak mendapatkan Poin");
			    }
	    	    if (totalDiskon>=250000 && totalDiskon<500000){
	    		printf("\n\t\t\t                                Poin yang didapatkan = 100");
			    }
			    if (totalDiskon>=500000 && totalDiskon<750000){
	    		printf("\n\t\t\t                                Poin yang didapatkan = 300");
			    }
			    if (totalDiskon>=750000){
	    		printf("\n\t\t\t                                Poin yang didapatkan = 500");
			    }
			    printf("\n");
        		printf("\n");
				printf("\t\t\t\t\t\t\t 	     Terimakasih telah berkunjung :)              \n");
				printf("\t\t\t\t\t\t\t===========================================================\n");break;
				
				case 'n':
				exit;break;
				default:
					printf("Input Salah! \n");
					goto lanjutbayar;
			}
}

//	==================================================PROCEDURE INPUT IDENTITAS CUSTOMER KE RECORD=======================================================
void ID_customer(char nama[30],char alamat[44], char email[37]){
	
	FILE *filetubes;
	data_user datauser;
    printf("\t\t\t||=================================================================================||\n");	
	printf("\t\t\t||                                    CHOCO MATES                                  ||\n");
	printf("\t\t\t||                                IDENTITAS CUSTOMER                               ||\n");
	printf("\t\t\t||=================================================================================||\n");
	(filetubes=fopen("datacustomer.txt","a+t"));
	 printf("\t\t\t\t\t\t\t     Mohon isi dengan benar data customer \n\n");
	 printf("\t\t\t\t\t\t- Masukkan Nama Anda      : "); fflush(stdin);
	 gets(datauser.nama);
	 printf("\t\t\t\t\t\t- Masukkan Alamat Anda    : "); fflush(stdin);
	 gets(datauser.alamat);
	 printf("\t\t\t\t\t\t- Masukkan Email Anda     : "); fflush(stdin);
	 gets(datauser.email);
	
	 fwrite(&datauser, sizeof(datauser), 1, filetubes);
	 fclose(filetubes);
}
//	==================================================FUNCTION HITUNG SUB TOTAL==========================================================================
int hitungsubtotal(int sub, int hrg){
	int subtotal;
	subtotal = sub*hrg;
	return subtotal;
}
//	==================================================FUNCTION HITUNG KEMBALIAN==========================================================================
int hitungkembalian(int uang, int bayar){
	int kembalian;
	kembalian = uang - bayar;
	return kembalian;
}
//	==================================================FUNCTION HITUNG DISKON=============================================================================
int tot_diskon(int diskon){
	if (diskon >= 400000 && diskon< 700000){
		diskon=diskon-(diskon*10/100);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t       Selamat Anda Mendapatkan Diskon Sebesar 10 Persen  \n");
        return diskon;
	}
	
		else if (diskon >= 700000){
			diskon=diskon-(diskon*20/100);
			system("cls");
			printf("\n\n\n\n\n\n\n");
			printf("\n\n\t\t\t\t\t\t       Selamat Anda Mendapatkan Diskon Sebesar 20 Persen  \n");
	        return diskon;
		}
}
//	==================================================FUNCTION HITUNG SETELAH DI DISKON==================================================================
int potonganharga(int discount,int vDiskon){
	if (vDiskon >= 400000 && vDiskon < 700000){
		discount=vDiskon*10/100;
        return discount;
	}
		else if (vDiskon >= 700000){
			discount=vDiskon*20/100;
	        return discount;
			
		}else{
			discount = vDiskon * 0;
			return discount;
		}
}

//	==================================================FUNCTION HITUNG POIN==================================================================
int hitungpoin(totalDiskon){
	if (totalDiskon<250000){
        		printf("\n\t\t\tAnda tidak mendapatkan Poin");
			}
	    	if (totalDiskon>=250000 && totalDiskon<500000){
	    		printf("\n\t\t\tPoin yang didapatkan = 100");
			}
			if (totalDiskon>=500000 && totalDiskon<750000){
	    		printf("\n\t\t\tPoin yang didapatkan = 300");
			}
			if (totalDiskon>=750000){
	    		printf("\n\t\t\tPoin yang didapatkan = 500");
			}
}

//	==================================================PROCEDURE GET TANGGAL SISTEM=======================================================================
void setwaktu() {
    struct tm *waktuSistem;

    time_t vWaktu;
    vWaktu = time(NULL);
    waktuSistem = localtime(&vWaktu); /* Untuk mendapatkan waktu lokal komputer */

    printf("\t\t\t\t\t\t\tWaktu Pembelian     : %d/%d/%d \n", waktuSistem->tm_mday, waktuSistem->tm_mon+1, 1900+waktuSistem->tm_year);
}
