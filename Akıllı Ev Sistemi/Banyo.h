#pragma once
#include "Home.h"

class banyo : public home
{
private:
	string banyoAdi;
	int guvenlikDegisken = 0;
	int yang�nDurum = 0;
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
	//Priz Fonksiyonlar�:
	void prizEkleme();
	void prizlerinListelenmesi();
	void prizCikartma();
	void prizDurumuSorgulama();
	void prizDurumunuDegistirme();
	//Lamba Fonksiyonlar�:
	void lambaEkleme();
	void lambalarinListelenmesi();
	void lambaCikarma();
	void lambaDurumuSorgulama();
	void lambaDurumunuDegistirme();
	//T�m Bile�enleri ��eren Fonksiyonlar:
	void prizlerinVeLambalarinListelenmesi();
	//G�venlik Sorunu Olan Durumlar
	void yanginVar();
	void suBaskiniVar();
	void hirsizGirdi();
	//G�venlik Sorunu Olamayan Durumlar
	void yanginYok();
	void suBaskiniYok();
	void hirsizYok();
};