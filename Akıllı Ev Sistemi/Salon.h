#pragma once
#include "Home.h"

class salon : public home
{
private:
	string salonAdi;
	int guvenlikDegisken = 0;
	int yangýnDurum = 0;
	int suBaskiniDurum = 0;
	int hirsizDurum = 0;
	float sicaklik;
	float nem;
	int perde;
	int klima;
public:
	//CONSTRACTOR
	salon(string _salonAdi);
	//DESTRUCTOR
	~salon();
	//Salon Adý Getter ve Setter
	string getSalonAdi();
	void setSalonAdi(string _salonAdi);
	//Priz ve Lamba Sayacý Getterlar
	int getSalonPrizSayac();
	int getSalonLampSayac();
	//Güvenlik Getter ve Setter
	int getYanginDurum();
	void setYanginDurum(int _guvenlikDegisken);
	int getSuBaskiniDurum();
	void setSuBaskiniDurum(int _guvenlikDegisken);
	int getHirsizDurum();
	void setHirsizDurum(int _guvenlikDegisken);
	//Sýcaklýk Getter ve Setter
	float getSicaklikDeger();
	void setSicaklikDeger(float _sicaklik);
	//Nem Getter ve Setter
	float getNemDeger();
	void setNemDeger(float _nem);
	//Perde Getter ve Setter
	int getPerdeDurum();
	void setPerdeDurum(int _perde);
	//Klima Getter ve Setter
	int getKlimaDurum();
	void setKlimaDurum(int _klima);
	//Saksý Getter
	int getSaksiSayac();
	//Saksý Fonksiyonlarý
	void saksiEkle();
	void saksilarinListelenmesi();
	void saksiCikarma();
	void saksiDurumuSorgulama();
	void saksiDurumunuDegistirme();
	//Priz Fonksiyonlarý:
	void prizEkleme();
	void prizlerinListelenmesi();
	void prizCikartma();
	void prizDurumuSorgulama();
	void prizDurumunuDegistirme();
	//Lamba Fonksiyonlarý:
	void lambaEkleme();
	void lambalarinListelenmesi();
	void lambaCikarma();
	void lambaDurumuSorgulama();
	void lambaDurumunuDegistirme();
	//Tüm Bileþenleri Ýçeren Fonksiyonlar:
	void prizlerinVeLambalarinListelenmesi();
	//Güvenlik Sorunu Olan Durumlar
	void yanginVar();
	void suBaskiniVar();
	void hirsizGirdi();
	//Güvenlik Sorunu Olamayan Durumlar
	void yanginYok();
	void suBaskiniYok();
	void hirsizYok();
	//Sicaklýk ve Nem Kontrolü
	void sicaklikVeNemDurum();
};
