#include "Mutfak.h"

map <string, int> mPriz;
map <string, float> mLamp;
map<string, float> mMutfakSaksi;

//CONSTRACTOR
mutfak::mutfak(string _mutfakAdi) : home(_mutfakAdi) {
	mutfak::mutfakAdi = _mutfakAdi;
	yangýnDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
	sicaklik = 25;
	nem = 25;
	kombi = 0;
	perde = 0;
}

//DESTRUCTOR
mutfak::~mutfak() {
	cout << getMutfakAdi() << "'in Destructor'ý çaðýrýldý." << endl;
}

//Mutfak Adý Öðrenme
string mutfak::getMutfakAdi() {
	return mutfak::mutfakAdi;
}

//Mutfak Adi Deðiþtirme
void mutfak::setMutfakAdi(string _mutfakAdi) {
	mutfak::mutfakAdi = _mutfakAdi;
}

//Mutfaktaki Priz Sayýsýný Öðrenme
int mutfak::getPrizSayac() {
	return mPriz.size();
}

//Mutfaktaki Lamba Sayýsýný Öðrenme
int mutfak::getLampSayac() {
	return mLamp.size();
}

//Mutfaktaki Yangýn Durumunu Öðrenme
int mutfak::getYanginDurum() {
	return yangýnDurum;
}

//Mutfaktaki Yangýn Durumunu Deðiþtirme
void mutfak::setYanginDurum(int _guvenlikDegisken) {
	yangýnDurum = _guvenlikDegisken;
}

//Mutfaktaki Su Baskýný Durumunu Öðrenme
int mutfak::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Mutfaktaki Su Baskýný Durumunu Deðiþtirme
void mutfak::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Mutfaktaki Hýrsýz Durumunu Öðrenme
int mutfak::getHirsizDurum() {
	return hirsizDurum;
}

//Mutfaktaki Hýrsýz Durumunu Deðiþtirme
void mutfak::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Sýcaklýk Deðerini Öðrenme
float mutfak::getSicaklikDeger() {
	return sicaklik;
}

//Sýcaklýk Deðerini Deðiþtirme
void mutfak::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem Deðerini Öðrenme
float mutfak::getNemDeger() {
	return nem;
}

//Perde Durumunu Öðrenme
int mutfak::getPerdeDurum() {
	return perde;
}

//Perde Durumunu Deðiþtirme
void mutfak::setPerdeDurum(int _perde) {
	perde = _perde;
}

//Nem Deðerini Deðiþtirme
void mutfak::setNemDeger(float _nem) {
	nem = _nem;
}

//Kombi Durumun Öðrenme
int mutfak::getKombi() {
	return kombi;
}

//Kombi Durumunu ve Deðerini Deðiþtirme
void mutfak::setKombi(int _kombi) {
	kombi = _kombi;
}

//Saksý Sayac
int mutfak::getSaksiSayac() {
	return mMutfakSaksi.size();
}

//Saksý Ekleme
void mutfak::saksiEkle() {
	string saksiIsmi, devamlilikDurumu;
	cout << "--> Saksý Ekleme <--\n\n\n";
	do {
		cout << "Lütfen mutfakta bulunan " << mMutfakSaksi.size() + 1 << ". saksýnýn adýný giriniz: ";
		cin.ignore();
		getline(cin, saksiIsmi);
		mMutfakSaksi[saksiIsmi] = 0;
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
void mutfak::saksilarinListelenmesi() {
	cout << getMutfakAdi() << " isimli mutfakta " << mMutfakSaksi.size() << " adet saksý bulunuyor. Bunlar; \n";
	for (const auto& saksi : mMutfakSaksi) {
		if (saksi.second > 0) {
			cout << "Saksýnýn Adý: " << saksi.first << " , Saksý topraðýndaki nem deðeri: " << saksi.second << endl;
		}
		else if (saksi.second == 0) {
			cout << "Saksýnýn Adý: " << saksi.first << " , Saksý topraðý kurumuþ." << endl;
		}

	}
}

//Saksý Çýkarma
void mutfak::saksiCikarma() {
	string saksiSilinecek;
	saksilarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiSilinecek);
	if (mMutfakSaksi.size() != 0) {
		if (mMutfakSaksi.find(saksiSilinecek) != mMutfakSaksi.end()) {
			mMutfakSaksi.erase(saksiSilinecek);
			cout << saksiSilinecek << " isimli saksý mutfaktan çýkarýlmýþtýr...\n\n";
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
void mutfak::saksiDurumuSorgulama() {
	string saksiAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mMutfakSaksi.find(saksiAdi) != mMutfakSaksi.end()) {
		if (mMutfakSaksi[saksiAdi] > 0) {
			cout << "Saksýnýn Adý: " << saksiAdi << " , Saksý topraðýndaki nem deðeri: " << mMutfakSaksi[saksiAdi] << endl;
		}
		else if (mMutfakSaksi[saksiAdi] == 0) {
			cout << "Saksýnýn Adý: " << saksiAdi << " , Saksý topraðý kurumuþ." << endl;
		}
	}
	else {
		cout << endl << getMutfakAdi() << " isimli mutfaðýnýzda böyle bir saksý bulunmuyor!\n";
	}
}

//Girilen Saksý Durumunu Deðiþtirme
void mutfak::saksiDurumunuDegistirme() {
	string saksiAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mMutfakSaksi.find(saksiAdi) != mMutfakSaksi.end()) {
	hataliTuslama:
		cout << "Saksýyý sulamak ve nem deðerini ayarlamak için '100 - 0' arasýnda bir deðer giriniz (100 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 100 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mMutfakSaksi[saksiAdi] = onOff;
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
		cout << endl << getMutfakAdi() << " isimli mutfaðýnýzda böyle bir saksý bulunmuyor!\n";
	}
}

//Priz ekleme
void mutfak::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "Lütfen mutfakta bulunan " << mPriz.size() + 1 << ". prizin adýný giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mPriz[prizIsmi] = 0;
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
void mutfak::prizlerinListelenmesi() {
	cout << mutfak::mutfakAdi << " isimli mutfakta " << mPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}
	}
}

//Priz çýkartma
void mutfak::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mPriz.size() != 0) {
		if (mPriz.find(prizSilinecek) != mPriz.end()) {
			mPriz.erase(prizSilinecek);
			cout << prizSilinecek << "Ýsimli priz mutfaktan çýkarýlmýþtýr...\n\n";
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
void mutfak::prizDurumuSorgulama() {
	string prizAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mPriz.find(prizAdi) != mPriz.end()) {
		if (mPriz[prizAdi] == 1) {
			cout << "Prizin Adý: " << prizAdi << " , Priz açýk konumda." << endl;
		}
		else if (mPriz[prizAdi] == 0) {
			cout << "Prizin Adý: " << prizAdi << " , Priz kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << mutfak::mutfakAdi << " isimli mutfaðýnýzda böyle bir priz bulunmuyor!\n";
	}
}

//Girilen priz adýnýn durumunun deðiþtirilmesi
void mutfak::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mPriz.find(prizAdi) != mPriz.end()) {
	hataliTuslama:
		cout << "Prizi açmak için '1',Kapatmak için '0' ý tuþlayýnýz: ";
		cin >> onOff;
		try {
			if (onOff != 1 && onOff != 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mPriz[prizAdi] = onOff;
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
		cout << endl << mutfak::mutfakAdi << " isimli mutfaðýnýzda böyle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void mutfak::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "Lütfen mutfakta bulunan " << mLamp.size() + 1 << ". lambanýn adýný giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mLamp[lambaIsmi] = 0;
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
void mutfak::lambalarinListelenmesi() {
	cout << mutfak::mutfakAdi << " isimli mutfakta " << mLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}

	}
}

//Lamba çýkarma
void mutfak::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mLamp.size() != 0) {
		if (mLamp.find(lampSilinecek) != mLamp.end()) {
			mLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba mutfaktan çýkarýlmýþtýr...\n\n";
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
void mutfak::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mLamp.find(lampAdi) != mLamp.end()) {
		if (mLamp[lampAdi] > 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba açýk konumda ve deðeri: " << mLamp[lampAdi] << endl;
		}
		else if (mLamp[lampAdi] == 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << mutfak::mutfakAdi << " isimli mutfaðýnýzda böyle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba adýnýn durumunun deðiþtirilmesi
void mutfak::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mLamp.find(lampAdi) != mLamp.end()) {
	hataliTuslama:
		cout << "Lambayý açmak için '1024 - 0' arasýnda bir deðer giriniz (1024 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 1024 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mLamp[lampAdi] = onOff;
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
		cout << endl << mutfak::mutfakAdi << " isimli mutfaðýnýzda böyle bir lamba bulunmuyor!\n";
	}
}

//Prizleri ve Lambalarý listeme
void mutfak::prizlerinVeLambalarinListelenmesi() {
	cout << mutfak::mutfakAdi << " isimli mutfakta " << mPriz.size() << " adet priz ve ";
	cout << mLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}
	}
}

//Yangýn Durumu
void mutfak::yanginVar() {
	cout << getMutfakAdi() << " isimli mutfakta Yangýn Var!" << endl << endl;
}

//Yangýn Yok Durumu
void mutfak::yanginYok() {

}

//Su Baskýný Durumu
void mutfak::suBaskiniVar() {
	cout << getMutfakAdi() << " isimli mutfaðý Su Bastý!" << endl << endl;
}

//Su Baskýný Yok Durumu
void mutfak::suBaskiniYok() {

}

//Hýrsýz Girmesi Durumu
void mutfak::hirsizGirdi() {
	cout << getMutfakAdi() << " isimli mutfaktan Hýrsýz Girdi!" << endl << endl;
}

//Hýrsýz Yok Durumu
void mutfak::hirsizYok() {

}

//Sicaklýk ve Nem Kontrolü
void mutfak::sicaklikVeNemDurum() {
	cout << getMutfakAdi() << " isimli mutfaðýn sýcaklýðý: " << sicaklik << " °C, nem deðeri: " << nem << " RH'dir." << endl << endl;
}

