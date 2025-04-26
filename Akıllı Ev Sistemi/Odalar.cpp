#include "Odalar.h"


//CONSTRACTOR
odalar::odalar() : home() {

}

//DESTRUCTOR
odalar::~odalar() {
	cout << getOdaAdi() << "'in Destructor'ý çaðýrýldý." << endl;
}

//CONSTRACTOR
odalar::odalar(string _odaAdi, map <string, int> _mOdaPriz, map <string, float> _mOdaLamp, map<string, float> _mOdaSaksi) {
	odalar::odaAdi = _odaAdi;
	mOdaPriz = _mOdaPriz;
	mOdaLamp = _mOdaLamp;
	mOdaSaksi = _mOdaSaksi;
	yangýnDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
	sicaklik = 25;
	nem = 25;
	perde = 0;
	klima = 0;
}

//Oda Adý Öðrenme
string odalar::getOdaAdi() {
	return odalar::odaAdi;
}

//Oda Adi Deðiþtirme
void odalar::setOdaAdi(string _odaAdi) {
	odalar::odaAdi = _odaAdi;
}

//Odadaki Priz Sayýsýný Öðrenme
int odalar::getOdaPrizSayac() {
	return mOdaPriz.size();
}

//Odadaki Lamba Sayýsýný Öðrenme
int odalar::getOdaLampSayac() {
	return mOdaLamp.size();
}

// Odadaki Yangýn Durumunu Öðrenme
int odalar::getYanginDurum() {
	return yangýnDurum;
}

//Odadaki Yangýn Durumunu Deðiþtirme
void odalar::setYanginDurum(int _guvenlikDegisken) {
	yangýnDurum = _guvenlikDegisken;
}

//Odadaki Su Baskýný Durumunu Öðrenme
int odalar::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Odadaki Su Baskýný Durumunu Deðiþtirme
void odalar::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Odadaki Hýrsýz Durumunu Öðrenme
int odalar::getHirsizDurum() {
	return hirsizDurum;
}

//Odadaki Hýrsýz Durumunu Deðiþtirme
void odalar::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Sýcaklýk Deðerini Öðrenme
float odalar::getSicaklikDeger() {
	return sicaklik;
}

//Sýcaklýk Deðerini Deðiþtirme
void odalar::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem Deðerini Öðrenme
float odalar::getNemDeger() {
	return nem;
}

//Nem Deðerini Deðiþtirme
void odalar::setNemDeger(float _nem) {
	nem = _nem;
}

//Perde Durumunu Öðrenme
int odalar::getPerdeDurum() {
	return perde;
}

//Perde Durumunu Deðiþtirme
void odalar::setPerdeDurum(int _perde) {
	perde = _perde;
}

//Klima Durumunu Öðrenme
int odalar::getKlimaDurum() {
	return klima;
}

//Klima Durumunu Deðiþtirme
void odalar::setKlimaDurum(int _klima) {
	klima = _klima;
}

//Saksý Sayac
int odalar::getSaksiSayac() {
	return mOdaSaksi.size();
}

//Saksý Ekleme
void odalar::saksiEkle() {
	string saksiIsmi, devamlilikDurumu;
	cout << "--> Saksý Ekleme <--\n\n\n";
	do {
		cout << "Lütfen odada bulunan " << mOdaSaksi.size() + 1 << ". saksýnýn adýný giriniz: ";
		cin.ignore();
		getline(cin, saksiIsmi);
		mOdaSaksi[saksiIsmi] = 0;
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
void odalar::saksilarinListelenmesi() {
	cout << getOdaAdi() << " isimli odada " << mOdaSaksi.size() << " adet saksý bulunuyor. Bunlar; \n";
	for (const auto& saksi : mOdaSaksi) {
		if (saksi.second > 0) {
			cout << "Saksýnýn Adý: " << saksi.first << " , Saksý topraðýndaki nem deðeri: " << saksi.second << endl;
		}
		else if (saksi.second == 0) {
			cout << "Saksýnýn Adý: " << saksi.first << " , Saksý topraðý kurumuþ." << endl;
		}

	}
}

//Saksý Çýkarma
void odalar::saksiCikarma() {
	string saksiSilinecek;
	saksilarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiSilinecek);
	if (mOdaSaksi.size() != 0) {
		if (mOdaSaksi.find(saksiSilinecek) != mOdaSaksi.end()) {
			mOdaSaksi.erase(saksiSilinecek);
			cout << saksiSilinecek << " isimli saksý odadan çýkarýlmýþtýr...\n\n";
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
void odalar::saksiDurumuSorgulama() {
	string saksiAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mOdaSaksi.find(saksiAdi) != mOdaSaksi.end()) {
		if (mOdaSaksi[saksiAdi] > 0) {
			cout << "Saksýnýn Adý: " << saksiAdi << " , Saksý topraðýndaki nem deðeri: " << mOdaSaksi[saksiAdi] << endl;
		}
		else if (mOdaSaksi[saksiAdi] == 0) {
			cout << "Saksýnýn Adý: " << saksiAdi << " , Saksý topraðý kurumuþ." << endl;
		}
	}
	else {
		cout << endl << getOdaAdi() << " isimli odanýzda böyle bir saksý bulunmuyor!\n";
	}
}

//Girilen Saksý Durumunu Deðiþtirme
void odalar::saksiDurumunuDegistirme() {
	string saksiAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mOdaSaksi.find(saksiAdi) != mOdaSaksi.end()) {
	hataliTuslama:
		cout << "Saksýyý sulamak ve nem deðerini ayarlamak için '100 - 0' arasýnda bir deðer giriniz (100 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 100 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mOdaSaksi[saksiAdi] = onOff;
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
		cout << endl << getOdaAdi() << " isimli odanýzda böyle bir saksý bulunmuyor!\n";
	}
}

//Priz ekleme
void odalar::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "Lütfen odada bulunan " << mOdaPriz.size() + 1 << ". prizin adýný giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mOdaPriz[prizIsmi] = 0;
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
void odalar::prizlerinListelenmesi() {
	cout << getOdaAdi() << " isimli odada " << mOdaPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mOdaPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}
	}
}

//Priz çýkartma
void odalar::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mOdaPriz.size() != 0) {
		if (mOdaPriz.find(prizSilinecek) != mOdaPriz.end()) {
			mOdaPriz.erase(prizSilinecek);
			cout << prizSilinecek << "Ýsimli priz odadan çýkarýlmýþtýr...\n\n";
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
void odalar::prizDurumuSorgulama() {
	string prizAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mOdaPriz.find(prizAdi) != mOdaPriz.end()) {
		if (mOdaPriz[prizAdi] == 1) {
			cout << "Prizin Adý: " << prizAdi << " , Priz açýk konumda." << endl;
		}
		else if (mOdaPriz[prizAdi] == 0) {
			cout << "Prizin Adý: " << prizAdi << " , Priz kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << getOdaAdi() << " isimli odanýzda böyle bir priz bulunmuyor!\n";
	}
}

//Girilen priz adýnýn durumunun deðiþtirilmesi
void odalar::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mOdaPriz.find(prizAdi) != mOdaPriz.end()) {
	hataliTuslama:
		cout << "Prizi açmak için '1',Kapatmak için '0' ý tuþlayýnýz: ";
		cin >> onOff;
		try {
			if (onOff != 1 && onOff != 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mOdaPriz[prizAdi] = onOff;
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
		cout << endl << getOdaAdi() << " isimli odanýzda böyle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void odalar::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "Lütfen odada bulunan " << mOdaLamp.size() + 1 << ". lambanýn adýný giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mOdaLamp[lambaIsmi] = 0;
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
void odalar::lambalarinListelenmesi() {
	cout << getOdaAdi() << " isimli odada " << mOdaLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mOdaLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}

	}
}

//Lamba çýkarma
void odalar::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mOdaLamp.size() != 0) {
		if (mOdaLamp.find(lampSilinecek) != mOdaLamp.end()) {
			mOdaLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba odadan çýkarýlmýþtýr...\n\n";
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
void odalar::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mOdaLamp.find(lampAdi) != mOdaLamp.end()) {
		if (mOdaLamp[lampAdi] > 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba açýk konumda ve deðeri: " << mOdaLamp[lampAdi] << endl;
		}
		else if (mOdaLamp[lampAdi] == 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << getOdaAdi() << " isimli odanýzda böyle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba adýnýn durumunun deðiþtirilmesi
void odalar::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mOdaLamp.find(lampAdi) != mOdaLamp.end()) {
	hataliTuslama:
		cout << "Lambayý açmak için '1024 - 0' arasýnda bir deðer giriniz (1024 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 1024 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mOdaLamp[lampAdi] = onOff;
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
		cout << endl << getOdaAdi() << " isimli odanýzda böyle bir lamba bulunmuyor!\n";
	}
}

//Prizleri ve Lambalarý listeme
void odalar::prizlerinVeLambalarinListelenmesi() {
	cout << getOdaAdi() << " isimli odada " << mOdaPriz.size() << " adet priz ve ";
	cout << mOdaLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mOdaPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mOdaLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}
	}
}

//Yangýn Durumu
void odalar::yanginVar() {
	cout << getOdaAdi() << " isimli odada Yangýn Var!" << endl << endl;
}

//Yangýn Yok Durumu
void odalar::yanginYok() {

}

//Su Baskýný Durumu
void odalar::suBaskiniVar() {
	cout << getOdaAdi() << " isimli odayý Su Bastý!" << endl << endl;
}

//Su Baskýný Yok Durumu
void odalar::suBaskiniYok() {

}

//Hýrsýz Girmesi Durumu
void odalar::hirsizGirdi() {
	cout << getOdaAdi() << " isimli odadan Hýrsýz Girdi!" << endl << endl;
}

//Hýrsýz Yok Durumu
void odalar::hirsizYok() {

}

//Sicaklýk ve Nem Kontrolü
void odalar::sicaklikVeNemDurum() {
	cout << getOdaAdi() << " isimli odanýn sýcaklýðý: " << sicaklik << " °C, nem deðeri: " << nem << " RH'dir." << endl << endl;
}
