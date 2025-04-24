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
	cout << "Login'in Destructor'� �a��r�ld�." << endl;
}

//Ad De�i�tirme
void login::setAd(string _ad) {
	login::ad = _ad;
}

//Ad ��renme
string login::getAd() {
	return login::ad;
}

//Soyad De�i�tirme
void login::setSoyad(string _soyad) {
	login::soyad = _soyad;
}

//Soyad ��renme
string login::getSoyad() {
	return login::soyad;
}

//ID De�i�tirme
void login::setId(string _id) {
	login::id = _id;
}

//ID ��renme
string login::getId() {
	return login::id;
}

//�ifre De�i�tirme
void login::setPassword(string _password) {
	login::password = _password;
}

//�ifre ��renme
string login::getPassword() {
	return login::password;
}

//�ifre Kontrol� De�i�tirme
void login::setPassworKontrol(string sifre) {
	login::passwordKontrol = sifre;
}

//�ifre Kontrol� ��renme
string login::getPasswordKontrol() {
	return login::passwordKontrol;
}

//ID Kontrol� De�i�tirme
void login::setIdKontrol(string kullaniciAdi) {
	login::idKontrol = kullaniciAdi;
}

//ID Kontrol� ��renme
string login::getIdKontrol() {
	return login::idKontrol;
}

//Giri� Yapma
string login::girisYap() 
{
	while (login::id != login::idKontrol) 
	{
		cout << "Kullan�c� ad� bulunamad�! L�tfen yeniden deneyiniz: " << endl;
		cout << "Kullan�c� ad�n�z� giriniz: ";
		cin >> login::id;
		cout << "�ifrenizi giriniz: ";
		cin >> login::password;
	}

	if (login::passwordKontrol != login::password)
	{

		do
		{
			int a = 1;
			while (a == 1) 
			{
				cout << "Girdi�iniz �ifre yanl��! L�tfen yeniden deneyiniz... " << endl;
				cout << "Kullan�c� ad�: " << login::id << endl;
				cout << "�ifre: ";
				cin >> login::password;
				a++;
			}
		} while (login::passwordKontrol != login::password);
		cout << "Ba�ar�yla giri� yapt�n�z." << endl;
		return login::password;
	}
	else
	{
		cout << "Ba�ar�yla giri� yapt�n�z." << endl;
		return login::password;
	}
}

//Giri� Bilgilerini De�i�tirme
int login::girisBilgileriDegistir() {
	string kullaniciAdiSifreDegisimiKontrol;
	bool kontrol = 0;

	while (kontrol != 1)
	{
		cout << "Kullan�c� ad�n�z� ve �ifrenizi de�i�tirmek istiyor musunuz?(y/n): ";
		cin >> kullaniciAdiSifreDegisimiKontrol;
		if (kullaniciAdiSifreDegisimiKontrol == "y" || kullaniciAdiSifreDegisimiKontrol == "Y")
		{
			kontrol = 1;
			return 1;
		}
		else if (kullaniciAdiSifreDegisimiKontrol == "n" || kullaniciAdiSifreDegisimiKontrol == "N")
		{
			cout << "Giri� bilgileriniz ayn� �ekilde kalm��t�r..." << endl << endl;
			kontrol = 1;
			return 0;
		}
		else
		{
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			kontrol = 0;
		}
	}
}