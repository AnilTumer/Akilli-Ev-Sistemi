#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

class home
{
private:
	string isim;
	int guvenlikDegisken = 0;
	float sicaklik = 25;
	float nem = 25;
	int perde = 0;
	int klima = 0;
	int saksi = 0;
public:
	//CONSTRUCTOR
	home();
	home(string _isim);
	//DESTRUCTOR
	~home();
	//Getter ve Setterlar
	//Ev Adi Getter ve Setter
	string getHomeName();
	void setHomeName(string _isim);
	//G�venlik Getter ve Setter
	virtual int getYanginDurum();
	virtual void setYanginDurum(int _guvenlikDegisken);
	virtual int getSuBaskiniDurum();
	virtual void setSuBaskiniDurum(int _guvenlikDegisken);
	virtual int getHirsizDurum();
	virtual void setHirsizDurum(int _guvenlikDegisken);
	//S�cakl�k Getter ve Setter
	virtual float getSicaklikDeger();
	virtual void setSicaklikDeger(float _sicaklik);
	//Nem Getter ve Setter
	virtual float getNemDeger();
	virtual void setNemDeger(float _nem);
	//Di�er Bile�enler Getter ve Setter:
	//PERDE
	virtual int getPerdeDurum();
	virtual void setPerdeDurum(int _perde);
	//KL�MA
	virtual int getKlimaDurum();
	virtual void setKlimaDurum(int _klima);
	//SAKSI
	virtual int getSaksiSayac();
	virtual void saksiEkle();
	virtual void saksilarinListelenmesi();
	virtual void saksiCikarma();
	virtual void saksiDurumuSorgulama();
	virtual void saksiDurumunuDegistirme();
	//Deprem Getter ve Setter
	int getDepremDurum();
	void setDepremDurum(int _guvenlikDegisken);
	//G�venlik Sorunu Olan Durumlar
	virtual void yanginVar();
	virtual void suBaskiniVar();
	virtual void hirsizGirdi();
	void depremOluyor();
	//G�venlik Sorunu Olmayan Durumlar
	virtual void yanginYok();
	virtual void suBaskiniYok();
	virtual void hirsizYok();
	void depremYok();
	//Sicakl�k ve Nem Kontrol�
	virtual void sicaklikVeNemDurum();

	//Evcil Hayvan B�l�m�
	int getEvcilHayvanSayac();
	void evcilHayvanEkleme();
	void evcilHayvanListelenmesi();
	void evcilHayvanCikartma();
	void evcilHayvanDurumuSorgulama();
	void evcilHayvanDurumunuDegistirme();
};