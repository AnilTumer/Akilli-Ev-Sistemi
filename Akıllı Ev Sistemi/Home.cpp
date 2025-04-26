#include "Home.h"

static int yang�nDurum = 0;
static int suBaskiniDurum = 0;
static int hirsizDurum = 0;
static int depremDurum = 0;

map<string, int> mEvcilHayvan;

//CONSTRACTOR
home::home() {
	isim = "";
}

//CONSTRACTOR
home::home(string _isim) {
	home::isim = _isim;
}

//DESTRUCTOR
home::~home() {
	cout << getHomeName() << "'in Destructor'� �a��r�ld�." << endl;
}

//Ev Ad� ��renme
string home::getHomeName() {
	return home::isim;
}

//Ev Adi De�i�tirme
void home::setHomeName(string _isim) {
	home::isim = _isim;
}

//Evdeki Yang�n Durumunu ��renme
int home::getYanginDurum() {
	return yang�nDurum;
}

//Evdeki Yang�n Durumunu De�i�tirme
void home::setYanginDurum(int _guvenlikDegisken) {
	yang�nDurum = _guvenlikDegisken;
}

//Evdeki Su Bask�n� Durumunu ��renme
int home::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Evdeki Su Bask�n� Durumunu De�i�tirme
void home::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Evdeki H�rs�z Durumunu ��renme
int home::getHirsizDurum() {
	return hirsizDurum;
}

//Evdeki H�rs�z Durumunu De�i�tirme
void home::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//S�cakl�k De�erini ��renme
float home::getSicaklikDeger() {
	return sicaklik;
}

//S�cakl�k De�erini De�i�tirme
void home::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem De�erini ��renme
float home::getNemDeger() {
	return nem;
}

//Nem De�erini De�i�tirme
void home::setNemDeger(float _nem) {
	nem = _nem;
}

//Perde Durumunu ��renme
int home::getPerdeDurum() {
	return perde;
}

//Perde Durumunu De�i�tirme
void home::setPerdeDurum(int _perde) {
	perde = _perde;
}

//Klima Durumunu ��renme
int home::getKlimaDurum() {
	return klima;
}

//Klima Durumunu De�i�tirme
void home::setKlimaDurum(int _klima) {
	klima = _klima;
}

//Saks� Sayac
int home::getSaksiSayac() {
	return saksi;
}

//Saks� Ekleme
void home::saksiEkle() {

}

//Saks�lar�n Listelenmesi
void home::saksilarinListelenmesi() {

}

//Saks� ��karma
void home::saksiCikarma() {

}

//Saks� Durumunu Sorgulama
void home::saksiDurumuSorgulama() {

}

//Saks� Durumunu De�i�tirme
void home::saksiDurumunuDegistirme() {

}

//Evdeki Deprem Durumunu ��renme
int home::getDepremDurum() {
	return depremDurum;
}

//Evdeki Deprem Durumunu De�i�tirme
void home::setDepremDurum(int _guvenlikDegisken) {
	depremDurum = _guvenlikDegisken;
}

//Yang�n Olmas� Durumu
void home::yanginVar() {
	cout << "Evde Yang�n Var!" << endl << endl;
}

//Yang�n Yok Durumu
void home::yanginYok() {

}

//Su Bask�n� Olmas� Durumu
void home::suBaskiniVar() {
	cout << "Evi Su Bast�!" << endl << endl;
}

//Su Bask�n� Yok Durumu
void home::suBaskiniYok() {

}

//H�rs�z Girmesi Durumu
void home::hirsizGirdi() {
	cout << "Eve H�rs�z Girdi!" << endl << endl;
}

//H�rs�z Yok Durumu
void home::hirsizYok() {

}

//Deprem Olmas� Durumu
void home::depremOluyor() {
	cout << "Evde Deprem Oluyor!" << endl << endl;
}

//Deprem Yok Durumu
void home::depremYok() {

}

//Sicakl�k ve Nem Kontrol�
void home::sicaklikVeNemDurum() {

}


//Evcil Hayvan B�l�m�

//Evcil Hayvan Sayac
int home::getEvcilHayvanSayac() {
	return mEvcilHayvan.size();
}

//Evcil Hayvan ekleme
void home::evcilHayvanEkleme() {
	string evcilHayvanIsmi, devamlilikDurumu;
	cout << "-->Evcil Hayvan Ekleme<--\n\n\n";
	do {
		cout << "L�tfen evinizde bulunan " << mEvcilHayvan.size() + 1 << ". Evcil hayvan�z�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, evcilHayvanIsmi);
		mEvcilHayvan[evcilHayvanIsmi] = 0;
	hataliTuslama:
		cout << "Ba�ka bir evcil hayvan eklemek istiyor musunuz? (y/n): ";
		cin >> devamlilikDurumu;
		if (devamlilikDurumu == "y" || devamlilikDurumu == "Y") {
			devamlilikDurumu = "devam et";
		}
		else if (devamlilikDurumu == "n" || devamlilikDurumu == "N") {
			cout << "Evcil Hayvan Ekleme B�l�m�nden ��k�� Yap�l�yor... \n\n";
			devamlilikDurumu = "devam etme";
		}
		else {
			cout << "Hatal� Tu�lama Yapt�n�z!";
			goto hataliTuslama;
		}
	} while (devamlilikDurumu != "devam etme");
}

//Evcil Hayvanlar� listeleme
void home::evcilHayvanListelenmesi() {
	cout << getHomeName() << " isimli evde " << mEvcilHayvan.size() << " adet evcil hayvan bulunuyor. Bunlar; \n";
	for (const auto& evcilHayvan : mEvcilHayvan) {
		if (evcilHayvan.second > 0) {
			cout << "Evcil Hayvan�n Ad�: " << evcilHayvan.first << " , Evcil Hayvan�n yemi var ve doluluk oran�: " << evcilHayvan.second << endl;
		}
		else if (evcilHayvan.second == 0) {
			cout << "Evcil Hayvan�n Ad�: " << evcilHayvan.first << " , Evcil Hayvan�n yemi kalmam��." << endl;
		}
	}
}

//Evcil Hayvan ��kartma
void home::evcilHayvanCikartma() {
	string evcilHayvanSilinecek;
	evcilHayvanListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz evcil hayvan�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, evcilHayvanSilinecek);
	if (mEvcilHayvan.size() != 0) {
		if (mEvcilHayvan.find(evcilHayvanSilinecek) != mEvcilHayvan.end()) {
			mEvcilHayvan.erase(evcilHayvanSilinecek);
			cout << evcilHayvanSilinecek << "�simli evcil hayvan�n�z evinizden ��kar�lm��t�r...\n\n";
		}
		else {
			cout << "Girdi�iniz evcil hayvan ad� bulunamad�!\n\n";
		}
	}
	else {
		cout << "Evcil Hayvan bulunmyor! L�tfen �nce evcil hayvan ekleyiniz..." << endl << endl;
	}
}

//Evcil Hayvanlar�n durumlar�n� sorgulama
void home::evcilHayvanDurumuSorgulama() {
	string evcilHayvanAdi;
	cout << "L�tfen yem durumunu ��renmek istedi�iniz evcil hayvan�n�z�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, evcilHayvanAdi);
	if (mEvcilHayvan.find(evcilHayvanAdi) != mEvcilHayvan.end()) {
		if (mEvcilHayvan[evcilHayvanAdi] > 0) {
			cout << "Evcil Hayvan�n Ad�: " << evcilHayvanAdi << " , Evcil Hayvan�n yemi var ve doluluk oran�: " << mEvcilHayvan[evcilHayvanAdi] << endl;
		}
		else if (mEvcilHayvan[evcilHayvanAdi] == 0) {
			cout << "Evcil Hayvan�n Ad�: " << evcilHayvanAdi << " , Evcil Hayvan�n yemi kalmam��." << endl;
		}
	}
	else {
		cout << endl << getHomeName() << " isimli evinizde b�yle bir evcil hayvan bulunmuyor!\n";
	}
}

//Evcil Hayvanlar�n durumunun de�i�tirilmesi
void home::evcilHayvanDurumunuDegistirme() {
	string evcilHayvanAdi;
	int onOff;
	cout << "L�tfen yem durumunu de�i�tirmek istedi�iniz evcil hayvan�n�z�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, evcilHayvanAdi);
	if (mEvcilHayvan.find(evcilHayvanAdi) != mEvcilHayvan.end()) {
	hataliTuslama:
		cout << "Yem kab�n� doldurmak i�in '100 - 0' aras�nda bir de�er giriniz (100 = MAX, 0 = M�N): ";
		cin >> onOff;
		try {
			if (onOff > 100 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mEvcilHayvan[evcilHayvanAdi] = onOff;
		}
		catch (int hatakodu) {
			if (hatakodu == 101) {
				cout << "Hatal� tu�lama yapt�n�z! \n";
				goto hataliTuslama;
			}
			else if (hatakodu == 102) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "HATA! L�tfen say� giriniz! \n";
				goto hataliTuslama;
			}
		}

	}
	else {
		cout << endl << getHomeName() << " isimli evinizde b�yle bir evcil hayvan bulunmuyor!\n";
	}
}

