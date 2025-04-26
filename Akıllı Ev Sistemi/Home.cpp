#include "Home.h"

static int yangýnDurum = 0;
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
	cout << getHomeName() << "'in Destructor'ý çaðýrýldý." << endl;
}

//Ev Adý Öðrenme
string home::getHomeName() {
	return home::isim;
}

//Ev Adi Deðiþtirme
void home::setHomeName(string _isim) {
	home::isim = _isim;
}

//Evdeki Yangýn Durumunu Öðrenme
int home::getYanginDurum() {
	return yangýnDurum;
}

//Evdeki Yangýn Durumunu Deðiþtirme
void home::setYanginDurum(int _guvenlikDegisken) {
	yangýnDurum = _guvenlikDegisken;
}

//Evdeki Su Baskýný Durumunu Öðrenme
int home::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Evdeki Su Baskýný Durumunu Deðiþtirme
void home::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Evdeki Hýrsýz Durumunu Öðrenme
int home::getHirsizDurum() {
	return hirsizDurum;
}

//Evdeki Hýrsýz Durumunu Deðiþtirme
void home::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Sýcaklýk Deðerini Öðrenme
float home::getSicaklikDeger() {
	return sicaklik;
}

//Sýcaklýk Deðerini Deðiþtirme
void home::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem Deðerini Öðrenme
float home::getNemDeger() {
	return nem;
}

//Nem Deðerini Deðiþtirme
void home::setNemDeger(float _nem) {
	nem = _nem;
}

//Perde Durumunu Öðrenme
int home::getPerdeDurum() {
	return perde;
}

//Perde Durumunu Deðiþtirme
void home::setPerdeDurum(int _perde) {
	perde = _perde;
}

//Klima Durumunu Öðrenme
int home::getKlimaDurum() {
	return klima;
}

//Klima Durumunu Deðiþtirme
void home::setKlimaDurum(int _klima) {
	klima = _klima;
}

//Saksý Sayac
int home::getSaksiSayac() {
	return saksi;
}

//Saksý Ekleme
void home::saksiEkle() {

}

//Saksýlarýn Listelenmesi
void home::saksilarinListelenmesi() {

}

//Saksý Çýkarma
void home::saksiCikarma() {

}

//Saksý Durumunu Sorgulama
void home::saksiDurumuSorgulama() {

}

//Saksý Durumunu Deðiþtirme
void home::saksiDurumunuDegistirme() {

}

//Evdeki Deprem Durumunu Öðrenme
int home::getDepremDurum() {
	return depremDurum;
}

//Evdeki Deprem Durumunu Deðiþtirme
void home::setDepremDurum(int _guvenlikDegisken) {
	depremDurum = _guvenlikDegisken;
}

//Yangýn Olmasý Durumu
void home::yanginVar() {
	cout << "Evde Yangýn Var!" << endl << endl;
}

//Yangýn Yok Durumu
void home::yanginYok() {

}

//Su Baskýný Olmasý Durumu
void home::suBaskiniVar() {
	cout << "Evi Su Bastý!" << endl << endl;
}

//Su Baskýný Yok Durumu
void home::suBaskiniYok() {

}

//Hýrsýz Girmesi Durumu
void home::hirsizGirdi() {
	cout << "Eve Hýrsýz Girdi!" << endl << endl;
}

//Hýrsýz Yok Durumu
void home::hirsizYok() {

}

//Deprem Olmasý Durumu
void home::depremOluyor() {
	cout << "Evde Deprem Oluyor!" << endl << endl;
}

//Deprem Yok Durumu
void home::depremYok() {

}

//Sicaklýk ve Nem Kontrolü
void home::sicaklikVeNemDurum() {

}


//Evcil Hayvan Bölümü

//Evcil Hayvan Sayac
int home::getEvcilHayvanSayac() {
	return mEvcilHayvan.size();
}

//Evcil Hayvan ekleme
void home::evcilHayvanEkleme() {
	string evcilHayvanIsmi, devamlilikDurumu;
	cout << "-->Evcil Hayvan Ekleme<--\n\n\n";
	do {
		cout << "Lütfen evinizde bulunan " << mEvcilHayvan.size() + 1 << ". Evcil hayvanýzýn adýný giriniz: ";
		cin.ignore();
		getline(cin, evcilHayvanIsmi);
		mEvcilHayvan[evcilHayvanIsmi] = 0;
	hataliTuslama:
		cout << "Baþka bir evcil hayvan eklemek istiyor musunuz? (y/n): ";
		cin >> devamlilikDurumu;
		if (devamlilikDurumu == "y" || devamlilikDurumu == "Y") {
			devamlilikDurumu = "devam et";
		}
		else if (devamlilikDurumu == "n" || devamlilikDurumu == "N") {
			cout << "Evcil Hayvan Ekleme Bölümünden Çýkýþ Yapýlýyor... \n\n";
			devamlilikDurumu = "devam etme";
		}
		else {
			cout << "Hatalý Tuþlama Yaptýnýz!";
			goto hataliTuslama;
		}
	} while (devamlilikDurumu != "devam etme");
}

//Evcil Hayvanlarý listeleme
void home::evcilHayvanListelenmesi() {
	cout << getHomeName() << " isimli evde " << mEvcilHayvan.size() << " adet evcil hayvan bulunuyor. Bunlar; \n";
	for (const auto& evcilHayvan : mEvcilHayvan) {
		if (evcilHayvan.second > 0) {
			cout << "Evcil Hayvanýn Adý: " << evcilHayvan.first << " , Evcil Hayvanýn yemi var ve doluluk oraný: " << evcilHayvan.second << endl;
		}
		else if (evcilHayvan.second == 0) {
			cout << "Evcil Hayvanýn Adý: " << evcilHayvan.first << " , Evcil Hayvanýn yemi kalmamýþ." << endl;
		}
	}
}

//Evcil Hayvan çýkartma
void home::evcilHayvanCikartma() {
	string evcilHayvanSilinecek;
	evcilHayvanListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz evcil hayvanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, evcilHayvanSilinecek);
	if (mEvcilHayvan.size() != 0) {
		if (mEvcilHayvan.find(evcilHayvanSilinecek) != mEvcilHayvan.end()) {
			mEvcilHayvan.erase(evcilHayvanSilinecek);
			cout << evcilHayvanSilinecek << "Ýsimli evcil hayvanýnýz evinizden çýkarýlmýþtýr...\n\n";
		}
		else {
			cout << "Girdiðiniz evcil hayvan adý bulunamadý!\n\n";
		}
	}
	else {
		cout << "Evcil Hayvan bulunmyor! Lütfen önce evcil hayvan ekleyiniz..." << endl << endl;
	}
}

//Evcil Hayvanlarýn durumlarýný sorgulama
void home::evcilHayvanDurumuSorgulama() {
	string evcilHayvanAdi;
	cout << "Lütfen yem durumunu öðrenmek istediðiniz evcil hayvanýnýzýn adýný giriniz: ";
	cin.ignore();
	getline(cin, evcilHayvanAdi);
	if (mEvcilHayvan.find(evcilHayvanAdi) != mEvcilHayvan.end()) {
		if (mEvcilHayvan[evcilHayvanAdi] > 0) {
			cout << "Evcil Hayvanýn Adý: " << evcilHayvanAdi << " , Evcil Hayvanýn yemi var ve doluluk oraný: " << mEvcilHayvan[evcilHayvanAdi] << endl;
		}
		else if (mEvcilHayvan[evcilHayvanAdi] == 0) {
			cout << "Evcil Hayvanýn Adý: " << evcilHayvanAdi << " , Evcil Hayvanýn yemi kalmamýþ." << endl;
		}
	}
	else {
		cout << endl << getHomeName() << " isimli evinizde böyle bir evcil hayvan bulunmuyor!\n";
	}
}

//Evcil Hayvanlarýn durumunun deðiþtirilmesi
void home::evcilHayvanDurumunuDegistirme() {
	string evcilHayvanAdi;
	int onOff;
	cout << "Lütfen yem durumunu deðiþtirmek istediðiniz evcil hayvanýnýzýn adýný giriniz: ";
	cin.ignore();
	getline(cin, evcilHayvanAdi);
	if (mEvcilHayvan.find(evcilHayvanAdi) != mEvcilHayvan.end()) {
	hataliTuslama:
		cout << "Yem kabýný doldurmak için '100 - 0' arasýnda bir deðer giriniz (100 = MAX, 0 = MÝN): ";
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
				cout << "Hatalý tuþlama yaptýnýz! \n";
				goto hataliTuslama;
			}
			else if (hatakodu == 102) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "HATA! Lütfen sayý giriniz! \n";
				goto hataliTuslama;
			}
		}

	}
	else {
		cout << endl << getHomeName() << " isimli evinizde böyle bir evcil hayvan bulunmuyor!\n";
	}
}

