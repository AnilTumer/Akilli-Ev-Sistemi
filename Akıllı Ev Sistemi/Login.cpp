#include "Login.h"

//CONSTRACTOR
login::login(string _ad, string _soyad, string _id, string _password) {
	ad = _ad;
	soyad = _soyad;
	id = _id;
	password = _password;
	idKontrol = "ghost06";
	passwordKontrol = "5462";
}

//DESTRUCTOR
login::~login() {
	cout << "Login'in Destructor'ý çaðýrýldý." << endl;
}

//Ad Deðiþtirme
void login::setAd(string _ad) {
	login::ad = _ad;
}

//Ad Öðrenme
string login::getAd() {
	return login::ad;
}

//Soyad Deðiþtirme
void login::setSoyad(string _soyad) {
	login::soyad = _soyad;
}

//Soyad Öðrenme
string login::getSoyad() {
	return login::soyad;
}

//ID Deðiþtirme
void login::setId(string _id) {
	login::id = _id;
}

//ID Öðrenme
string login::getId() {
	return login::id;
}

//Þifre Deðiþtirme
void login::setPassword(string _password) {
	login::password = _password;
}

//Þifre Öðrenme
string login::getPassword() {
	return login::password;
}

//Þifre Kontrolü Deðiþtirme
void login::setPassworKontrol(string sifre) {
	login::passwordKontrol = sifre;
}

//Þifre Kontrolü Öðrenme
string login::getPasswordKontrol() {
	return login::passwordKontrol;
}

//ID Kontrolü Deðiþtirme
void login::setIdKontrol(string kullaniciAdi) {
	login::idKontrol = kullaniciAdi;
}

//ID Kontrolü Öðrenme
string login::getIdKontrol() {
	return login::idKontrol;
}

//Giriþ Yapma
string login::girisYap() 
{
	while (login::id != login::idKontrol) 
	{
		cout << "Kullanýcý adý bulunamadý! Lütfen yeniden deneyiniz: " << endl;
		cout << "Kullanýcý adýnýzý giriniz: ";
		cin >> login::id;
		cout << "Þifrenizi giriniz: ";
		cin >> login::password;
	}

	if (login::passwordKontrol != login::password)
	{

		do
		{
			int a = 1;
			while (a == 1) 
			{
				cout << "Girdiðiniz þifre yanlýþ! Lütfen yeniden deneyiniz... " << endl;
				cout << "Kullanýcý adý: " << login::id << endl;
				cout << "Þifre: ";
				cin >> login::password;
				a++;
			}
		} while (login::passwordKontrol != login::password);
		cout << "Baþarýyla giriþ yaptýnýz." << endl;
		return login::password;
	}
	else
	{
		cout << "Baþarýyla giriþ yaptýnýz." << endl;
		return login::password;
	}
}

//Giriþ Bilgilerini Deðiþtirme
int login::girisBilgileriDegistir() {
	string kullaniciAdiSifreDegisimiKontrol;
	bool kontrol = 0;

	while (kontrol != 1)
	{
		cout << "Kullanýcý adýnýzý ve þifrenizi deðiþtirmek istiyor musunuz?(y/n): ";
		cin >> kullaniciAdiSifreDegisimiKontrol;
		if (kullaniciAdiSifreDegisimiKontrol == "y" || kullaniciAdiSifreDegisimiKontrol == "Y")
		{
			kontrol = 1;
			return 1;
		}
		else if (kullaniciAdiSifreDegisimiKontrol == "n" || kullaniciAdiSifreDegisimiKontrol == "N")
		{
			cout << "Giriþ bilgileriniz ayný þekilde kalmýþtýr..." << endl << endl;
			kontrol = 1;
			return 0;
		}
		else
		{
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			kontrol = 0;
		}
	}
}