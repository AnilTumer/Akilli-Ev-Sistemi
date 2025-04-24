#pragma once
#include "Home.h"

class banyo : public home
{
private:
	string banyoAdi;
	int guvenlikDegisken = 0;
	int yangýnDurum = 0;
	int suBaskiniDurum = 0;
	int hirsizDurum = 0;
public:
	//CONSTRACTOR
	banyo(string _banyoAdi);
	//DESTRUCTOR
	~banyo();
	//Getter ve Setterlar
	string getBanyoAdi();
	void setBanyoAdi(string _banyoAdi);
	int getBanyoPrizSayac();
	int getBanyoLampSayac();
	int getYanginDurum();
	void setYanginDurum(int _guvenlikDegisken);
	int getSuBaskiniDurum();
	void setSuBaskiniDurum(int _guvenlikDegisken);
	int getHirsizDurum();
	void setHirsizDurum(int _guvenlikDegisken);
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
};