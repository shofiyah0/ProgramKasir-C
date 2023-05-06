#ifndef headersewa_H
#define headersewa_h


typedef struct pengguna{
	char *nama_coklat;
	char *jenis;
	int harga,subtotal;
}users;

typedef struct data_coklat{
	char nama[50];
	char jenis[50];
	int kodeCoklat,harga;
}data;


typedef	struct dataUser{
	char nama[30];
	char alamat[44];
	char email[37];
}data_user;

typedef struct akun_member{
	char namaMember[20];
	char passwordMember[20];
}akunMember;

int counter;
char username[10], password[10],nama[100],password[10],add[100],passwd[10],nickname[1000];

void menu_utama();
void menu_customer();
void menu_admin();
void panduan();
void vdaftarcoklat();
void vpembayaran();
void ID_customer();
void Read_ID_customer();
void setwaktu();
void restok();
void informasicustomer();
void ambilusername();
void ambilpassword();
void gantiuser();
void gantipass();
int hitungsubtotal();
int hitungkembalian();
int tot_diskon();
int potonganharga();
int hitungpoin();
#endif


