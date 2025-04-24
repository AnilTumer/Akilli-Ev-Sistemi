#pragma once
#include "Home.h"

using namespace std;
class odalar : public home {

private:
	map <string, int> mOdaPriz;
	map <string, float> mOdaLamp;
	map<string, float> mOdaSaksi;
	int guvenlikDegisken = 0;
	int yang�nDurum = 0;
	int suBaskiniDurum = 0;
	int hirsizDurum = 0;
	float sicaklik = 25;
	float nem = 25;
	int perde = 0;
	int klima = 0;
public:
	string odaAdi;
	//CONSTRACTOR
	odalar();
	odalar(string _odaAdi, map <string, int> _mOdaPriz, map <string, float> _mOdaLamp, map<string, float> _mOdaSaksi);
	//DESTRUCTOR
	~odalar();
	//Oda Ad� Getter ve Setter
	string getOdaAdi();
	void setOdaAdi(string _odaAdi);
	//Priz ve Lamba Sayac� Getterlar
	int getOdaPrizSayac();
	int getOdaLampSayac();
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
	//Perde Getter ve Setter
	int getPerdeDurum();
	void setPerdeDurum(int _perde);
	//Klima Getter ve Setter
	int getKlimaDurum();
	void setKlimaDurum(int _klima);
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