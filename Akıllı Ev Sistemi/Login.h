#pragma once
#include <iostream>
using namespace std;

class login
{
private:
	string ad;
	string soyad;
	string id;
	string password;
	string idKontrol;
	string passwordKontrol;
public:
	//CONSTRACTOR
	login(string _ad, string _soyad, string _id, string _password);
	//DESTRUCTOR
	~login();
	//Getter ve Setterlar
	void setAd(string _ad);
	string getAd();
	void setSoyad(string _soyad);
	string getSoyad();
	void setId(string _id);
	string getId();
	void setPassword(string _password);
	string getPassword();
	void setPassworKontrol(string sifre);
	string getPasswordKontrol();
	void setIdKontrol(string kullaniciAdi);
	string getIdKontrol();
	//Giriþ Fonksiyonlarý
	string girisYap();
	int girisBilgileriDegistir();
};