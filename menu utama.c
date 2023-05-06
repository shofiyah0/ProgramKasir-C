#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <string.h>

//	==================================================PROCEDURE TAMPILAN AWAL============================================================================
void tampilan(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("||= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =||\n");
	printf("\t\t\t||                  SELAMAT DATANG DI APLIKASI CHOCO MATES                   ||\n");
	printf("\t\t\t||                     _________________________________                     ||\n");
	printf("\t\t\t||= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =||\n\n");	
	printf("\t\t\t                     Klik tombol enter untuk melanjutkan                     \n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
//	==================================================PROCEDURE MENU UTAMA===============================================================================
void menu_utama(){
	printf("\n\n\n\n\n\n");
	printf("\t\t\t||=======================================================================||\n");	
	printf("\t\t\t||                              CHOCO MATES                              ||\n");
	printf("\t\t\t||                               MAIN MENU                               ||\n");
	printf("\t\t\t||=======================================================================||\n");
	printf("\t\t\t|| 1. Panduan Penggunaan Aplikasi                                        ||\n");
	printf("\t\t\t|| 2. Customer                                                           ||\n"); 
	printf("\t\t\t|| 3. Admin                                                              ||\n");	
	printf("\t\t\t|| 4. Exit                                                               ||\n");
	printf("\t\t\t||=======================================================================||\n\n");	
}

//	==================================================PROCEDURE BACA FILE PANDUAN========================================================================
void panduan(){
	char panduan[300];
	FILE *filetubes;
	printf("\n\n\n");
	if((filetubes = fopen("Panduan.txt","r")) == NULL){
		printf("File ini kosong !!! Silahkan hubungi admin");
		
		exit(1);
	}
	while(fgets(panduan, sizeof(panduan),filetubes)){
		printf("%s",panduan);
	}
		
	fclose(filetubes);
}
