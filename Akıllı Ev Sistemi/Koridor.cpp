#include "Koridor.h"

map <string, int> mKoridorPriz;
map <string, float> mKoridorLamp;
map <string, float> mKoridorSaksi;

//CONSTRACTOR
koridor::koridor(string _koridorAdi) : home(_koridorAdi) {
	koridor::koridorAdi = _koridorAdi;
	yangýnDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
	sicaklik = 25;
	nem = 25;
}

//DESTRUCTOR
koridor::~koridor() {
	cout << getKoridorAdi() << "'in Destructor'ý çaðýrýldý." << endl;
}

//Koridor Adý Öðrenme
string koridor::getKoridorAdi() {
	return koridor::koridorAdi;
}

//Koridor Adýný Deðiþtirme
void koridor::setKoridorAdi(string _koridorAdi) {
	koridor::koridorAdi = _koridorAdi;
}

//Koridordaki Priz Sayýsýný Öðrenme
int koridor::getKoridorPrizSayac() {
	return mKoridorPriz.size();
}

//Koridordaki Lamba Sayýsýný Öðrenme
int koridor::getKoridorLampSayac() {
	return mKoridorLamp.size();
}

// Koridordaki Yangýn Durumunu Öðrenme
int koridor::getYanginDurum() {
	return yangýnDurum;
}

//Koridordaki Yangýn Durumunu Deðiþtirme
void koridor::setYanginDurum(int _guvenlikDegisken) {
	yangýnDurum = _guvenlikDegisken;
}

//Koridordaki Su Baskýný Durumunu Öðrenme
int koridor::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Koridordaki Su Baskýný Durumunu Deðiþtirme
void koridor::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Koridordaki Hýrsýz Durumunu Öðrenme
int koridor::getHirsizDurum() {
	return hirsizDurum;
}

//Koridordaki Hýrsýz Durumunu Deðiþtirme
void koridor::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Sýcaklýk Deðerini Öðrenme
float koridor::getSicaklikDeger() {
	return sicaklik;
}

//Sýcaklýk Deðerini Deðiþtirme
void koridor::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem Deðerini Öðrenme
float koridor::getNemDeger() {
	return nem;
}

//Nem Deðerini Deðiþtirme
void koridor::setNemDeger(float _nem) {
	nem = _nem;
}

//Saksý Sayac
int koridor::getSaksiSayac() {
	return mKoridorSaksi.size();
}

//Saksý Ekleme
void koridor::saksiEkle() {
	string saksiIsmi, devamlilikDurumu;
	cout << "--> Saksý Ekleme <--\n\n\n";
	do {
		cout << "Lütfen koridorda bulunan " << mKoridorSaksi.size() + 1 << ". saksýnýn adýný giriniz: ";
		cin.ignore();
		getline(cin, saksiIsmi);
		mKoridorSaksi[saksiIsmi] = 0;
	hataliTuslama:
		cout << "Baþka bir saksý eklemek istiyor musunuz? (y/n): ";
		cin >> devamlilikDurumu;
		if (devamlilikDurumu == "y" || devamlilikDurumu == "Y") {
			devamlilikDurumu = "devam et";
		}
		else if (devamlilikDurumu == "n" || devamlilikDurumu == "N") {
			cout << "Saksý Ekleme Bölümünden Çýkýþ Yapýlýyor... \n\n";
			devamlilikDurumu = "devam etme";
		}
		else {
			cout << "Hatalý Tuþlama Yaptýnýz!";
			goto hataliTuslama;
		}
	} while (devamlilikDurumu != "devam etme");
}

//Saksýlarýn Listelenmesi
void koridor::saksilarinListelenmesi() {
	cout << getKoridorAdi() << " isimli koridorda " << mKoridorSaksi.size() << " adet saksý bulunuyor. Bunlar; \n";
	for (const auto& saksi : mKoridorSaksi) {
		if (saksi.second > 0) {
			cout << "Saksýnýn Adý: " << saksi.first << " , Saksý topraðýndaki nem deðeri: " << saksi.second << endl;
		}
		else if (saksi.second == 0) {
			cout << "Saksýnýn Adý: " << saksi.first << " , Saksý topraðý kurumuþ." << endl;
		}

	}
}

//Saksý Çýkarma
void koridor::saksiCikarma() {
	string saksiSilinecek;
	saksilarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiSilinecek);
	if (mKoridorSaksi.size() != 0) {
		if (mKoridorSaksi.find(saksiSilinecek) != mKoridorSaksi.end()) {
			mKoridorSaksi.erase(saksiSilinecek);
			cout << saksiSilinecek << " isimli saksý koridordan çýkarýlmýþtýr...\n\n";
		}
		else {
			cout << "Girdiðiniz saksý adý bulunamadý!\n\n";
		}
	}
	else {
		cout << "Saksý bulunmyor! Lütfen önce saksý ekleyiniz..." << endl << endl;
	}
}

//Girilen Saksý Durumunu Sorgulama
void koridor::saksiDurumuSorgulama() {
	string saksiAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mKoridorSaksi.find(saksiAdi) != mKoridorSaksi.end()) {
		if (mKoridorSaksi[saksiAdi] > 0) {
			cout << "Saksýnýn Adý: " << saksiAdi << " , Saksý topraðýndaki nem deðeri: " << mKoridorSaksi[saksiAdi] << endl;
		}
		else if (mKoridorSaksi[saksiAdi] == 0) {
			cout << "Saksýnýn Adý: " << saksiAdi << " , Saksý topraðý kurumuþ." << endl;
		}
	}
	else {
		cout << endl << getKoridorAdi() << " isimli koridorunuzda böyle bir saksý bulunmuyor!\n";
	}
}

//Girilen Saksý Durumunu Deðiþtirme
void koridor::saksiDurumunuDegistirme() {
	string saksiAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mKoridorSaksi.find(saksiAdi) != mKoridorSaksi.end()) {
	hataliTuslama:
		cout << "Saksýyý sulamak ve nem deðerini ayarlamak için '100 - 0' arasýnda bir deðer giriniz (100 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 100 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mKoridorSaksi[saksiAdi] = onOff;
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
		cout << endl << getKoridorAdi() << " isimli koridorunuzda böyle bir saksý bulunmuyor!\n";
	}
}

//Priz ekleme
void koridor::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "Lütfen Koridorda bulunan " << mKoridorPriz.size() + 1 << ". prizin adýný giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mKoridorPriz[prizIsmi] = 0;
	hataliTuslama:
		cout << "Baþka bir priz eklemek istiyor musunuz? (y/n): ";
		cin >> devamlilikDurumu;
		if (devamlilikDurumu == "y" || devamlilikDurumu == "Y") {
			devamlilikDurumu = "devam et";
		}
		else if (devamlilikDurumu == "n" || devamlilikDurumu == "N") {
			cout << "Priz Ekleme Bölümünden Çýkýþ Yapýlýyor... \n\n";
			devamlilikDurumu = "devam etme";
		}
		else {
			cout << "Hatalý Tuþlama Yaptýnýz!";
			goto hataliTuslama;
		}
	} while (devamlilikDurumu != "devam etme");
}

//Prizleri listeleme
void koridor::prizlerinListelenmesi() {
	cout << getKoridorAdi() << " isimli koridorda " << mKoridorPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mKoridorPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
}

//Priz çýkartma
void koridor::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mKoridorPriz.size() != 0) {
		if (mKoridorPriz.find(prizSilinecek) != mKoridorPriz.end()) {
			mKoridorPriz.erase(prizSilinecek);
			cout << prizSilinecek << "Ýsimli priz koridordan çýkarýlmýþtýr...\n\n";
		}
		else {
			cout << "Girdiðiniz priz adý bulunamadý!\n\n";
		}
	}
	else {
		cout << "Priz bulunmyor! Lütfen önce priz ekleyiniz..." << endl << endl;
	}

}

//Girilen prizin durumlarýný sorgulama
void koridor::prizDurumuSorgulama() {
	string prizAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mKoridorPriz.find(prizAdi) != mKoridorPriz.end()) {
		if (mKoridorPriz[prizAdi] == 1) {
			cout << "Prizin Adý: " << prizAdi << " , Priz açýk konumda." << endl;
		}
		else if (mKoridorPriz[prizAdi] == 0) {
			cout << "Prizin Adý: " << prizAdi << " , Priz kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << getKoridorAdi() << " isimli koridorda böyle bir priz bulunmuyor!\n";
	}
}

//Girilen priz adýnýn durumunun deðiþtirilmesi
void koridor::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mKoridorPriz.find(prizAdi) != mKoridorPriz.end()) {
	hataliTuslama:
		cout << "Prizi açmak için '1',Kapatmak için '0' ý tuþlayýnýz: ";
		cin >> onOff;
		try {
			if (onOff != 1 && onOff != 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mKoridorPriz[prizAdi] = onOff;
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
		cout << endl << getKoridorAdi() << " isimli koridorda böyle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void koridor::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "Lütfen Koridorda bulunan " << mKoridorLamp.size() + 1 << ". lambanýn adýný giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mKoridorLamp[lambaIsmi] = 0;
	hataliTuslama:
		cout << "Baþka bir lamba eklemek istiyor musunuz? (y/n): ";
		cin >> devamlilikDurumu;
		if (devamlilikDurumu == "y" || devamlilikDurumu == "Y") {
			devamlilikDurumu = "devam et";
		}
		else if (devamlilikDurumu == "n" || devamlilikDurumu == "N") {
			cout << "Lamba Ekleme Bölümünden Çýkýþ Yapýlýyor... \n\n";
			devamlilikDurumu = "devam etme";
		}
		else {
			cout << "Hatalý Tuþlama Yaptýnýz!";
			goto hataliTuslama;
		}
	} while (devamlilikDurumu != "devam etme");
}

//Lambalarý listeleme
void koridor::lambalarinListelenmesi() {
	cout << getKoridorAdi() << " isimli koridorda " << mKoridorLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mKoridorLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}

	}
}

//Lamba çýkarma
void koridor::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mKoridorLamp.size() != 0) {
		if (mKoridorLamp.find(lampSilinecek) != mKoridorLamp.end()) {
			mKoridorLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba koridordan çýkarýlmýþtýr...\n\n";
		}
		else {
			cout << "Girdiðiniz lamba adý bulunamadý!\n\n";
		}
	}
	else {
		cout << "Lamba bulunmyor! Lütfen önce lamba ekleyiniz..." << endl << endl;
	}

}

//Girilen lambanýn durumunu sorgulama
void koridor::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mKoridorLamp.find(lampAdi) != mKoridorLamp.end()) {
		if (mKoridorLamp[lampAdi] > 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba açýk konumda ve deðeri: " << mKoridorLamp[lampAdi] << endl;
		}
		else if (mKoridorLamp[lampAdi] == 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << getKoridorAdi() << " isimli koridorunuzda böyle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba adýnýn durumunun deðiþtirilmesi
void koridor::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mKoridorLamp.find(lampAdi) != mKoridorLamp.end()) {
	hataliTuslama:
		cout << "Lambayý açmak için '1024 - 0' arasýnda bir deðer giriniz (1024 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 1024 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mKoridorLamp[lampAdi] = onOff;
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
		cout << endl << getKoridorAdi() << " isimli koridornuzda böyle bir priz bulunmuyor!\n";
	}
}

//Prizleri ve Lambalarý listeme
void koridor::prizlerinVeLambalarinListelenmesi() {
	cout << getKoridorAdi() << " isimli koridorda " << mKoridorPriz.size() << " adet priz ve ";
	cout << mKoridorLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mKoridorPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mKoridorLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}
	}
}

//Yangýn Durumu
void koridor::yanginVar() {
	cout << getKoridorAdi() << " isimli koridorda Yangýn Var!" << endl << endl;
}

//Yangýn Yok Durumu
void koridor::yanginYok() {

}

//Su Baskýný Durumu
void koridor::suBaskiniVar() {
	cout << getKoridorAdi() << " isimli koridoru Su Bastý!" << endl << endl;
}

//Su Baskýný Yok Durumu
void koridor::suBaskiniYok() {

}

//Hýrsýz Girmesi Durumu
void koridor::hirsizGirdi() {
	cout << getKoridorAdi() << " isimli koridordan Hýrsýz Girdi!" << endl << endl;
}

//Hýrsýz Yok Durumu
void koridor::hirsizYok() {

}

//Sicaklýk ve Nem Kontrolü
void koridor::sicaklikVeNemDurum() {
	cout << getKoridorAdi() << " isimli koridorun sýcaklýðý: " << sicaklik << " °C, nem deðeri: " << nem << " RH'dir." << endl << endl;
}
