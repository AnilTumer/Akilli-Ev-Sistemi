#pragma once
#include "Home.h"

class koridor : public home
{
private:
	string koridorAdi;
	int guvenlikDegisken = 0;
	int yang�nDurum = 0;
	int suBaskiniDurum = 0;
	int hirsizDurum = 0;
	float sicaklik;
	float nem;
public:
	//CONSTRACTOR
	koridor(string _koridorAdi);
	//DESTRUCTOR
	~koridor();
	//Kortidor Ad� Getter ve Setter
	string getKoridorAdi();
	void setKoridorAdi(string _koridorAdi);
	//Priz ve Lamba Sayac� Getterlar
	int getKoridorPrizSayac();
	int getKoridorLampSayac();
	//G�venlik Getter ve Setter
	int getYanginDurum();
	void setYanginDurum(int _guvenlikDegisken);
	int getSuBaskiniDurum();
	void setSuBaskiniDurum(int _guvenlikDegisken);
	int getHirsizDurum();
	void setHirsizDurum(int _guvenlikDegisken);
	//S�cakl�k Getter ve Setter
	float getSicaklikDeger();
	void setSicaklikDeger(float _sicaklik);
	//Nem Getter ve Setter
	float getNemDeger();
	void setNemDeger(float _nem);
	//Saks� Getter
	int getSaksiSayac();
	//Saks� Fonksiyonlar�
	void saksiEkle();
	void saksilarinListelenmesi();
	void saksiCikarma();
	void saksiDurumuSorgulama();
	void saksiDurumunuDegistirme();
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
	//Sicakl�k ve Nem Kontrol�
	void sicaklikVeNemDurum();
};