#include "Salon.h"

map <string, int> mSalonPriz;
map <string, float> mSalonLamp;
map<string, float>mSalonSaksi;

//CONSTRACTOR
salon::salon(string _salonAdi) : home(_salonAdi) {
	salon::salonAdi = _salonAdi;
	yangýnDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
	sicaklik = 25;
	nem = 25;
	perde = 0;
	klima = 0;
}

//DESTRUCTOR
salon::~salon() {
	cout << getSalonAdi() << "'in Destructor'ý çaðýrýldý." << endl;
}

//Salon Adý Öðrenme
string salon::getSalonAdi() {
	return salon::salonAdi;
}

//Salon Adýný Deðiþtirme
void salon::setSalonAdi(string _salonAdi) {
	salon::salonAdi = _salonAdi;
}

//Salondaki Priz Sayýsýný Öðrenme
int salon::getSalonPrizSayac() {
	return mSalonPriz.size();
}

//Salondaki Lamba Sayýsýný Öðrenme
int salon::getSalonLampSayac() {
	return mSalonLamp.size();
}

//Salondaki Yangýn Durumunu Öðrenme
int salon::getYanginDurum() {
	return yangýnDurum;
}

//Salondaki Yangýn Durumunu Deðiþtirme
void salon::setYanginDurum(int _guvenlikDegisken) {
	yangýnDurum = _guvenlikDegisken;
}

//Salondaki Su Baskýný Durumunu Öðrenme
int salon::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Salondaki Su Baskýný Durumunu Deðiþtirme
void salon::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Salondaki Hýrsýz Durumunu Öðrenme
int salon::getHirsizDurum() {
	return hirsizDurum;
}

//Salondaki Hýrsýz Durumunu Deðiþtirme
void salon::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Sýcaklýk Deðerini Öðrenme
float salon::getSicaklikDeger() {
	return sicaklik;
}

//Sýcaklýk Deðerini Deðiþtirme
void salon::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem Deðerini Öðrenme
float salon::getNemDeger() {
	return nem;
}

//Nem Deðerini Deðiþtirme
void salon::setNemDeger(float _nem) {
	nem = _nem;
}

//Perde Durumunu Öðrenme
int salon::getPerdeDurum() {
	return perde;
}

//Perde Durumunu Deðiþtirme
void salon::setPerdeDurum(int _perde) {
	perde = _perde;
}

//Klima Durumunu Öðrenme
int salon::getKlimaDurum() {
	return klima;
}

//Klima Durumunu Deðiþtirme
void salon::setKlimaDurum(int _klima) {
	klima = _klima;
}

//Saksý Sayac
int salon::getSaksiSayac() {
	return mSalonSaksi.size();
}

//Saksý Ekleme
void salon::saksiEkle() {
	string saksiIsmi, devamlilikDurumu;
	cout << "--> Saksý Ekleme <--\n\n\n";
	do {
		cout << "Lütfen salonda bulunan " << mSalonSaksi.size() + 1 << ". saksýnýn adýný giriniz: ";
		cin.ignore();
		getline(cin, saksiIsmi);
		mSalonSaksi[saksiIsmi] = 0;
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
void salon::saksilarinListelenmesi() {
	cout << getSalonAdi() << " isimli salonda " << mSalonSaksi.size() << " adet saksý bulunuyor. Bunlar; \n";
	for (const auto& saksi : mSalonSaksi) {
		if (saksi.second > 0) {
			cout << "Saksýnýn Adý: " << saksi.first << " , Saksý topraðýndaki nem deðeri: " << saksi.second << endl;
		}
		else if (saksi.second == 0) {
			cout << "Saksýnýn Adý: " << saksi.first << " , Saksý topraðý kurumuþ." << endl;
		}

	}
}

//Saksý Çýkarma
void salon::saksiCikarma() {
	string saksiSilinecek;
	saksilarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiSilinecek);
	if (mSalonSaksi.size() != 0) {
		if (mSalonSaksi.find(saksiSilinecek) != mSalonSaksi.end()) {
			mSalonSaksi.erase(saksiSilinecek);
			cout << saksiSilinecek << " isimli saksý salondan çýkarýlmýþtýr...\n\n";
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
void salon::saksiDurumuSorgulama() {
	string saksiAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mSalonSaksi.find(saksiAdi) != mSalonSaksi.end()) {
		if (mSalonSaksi[saksiAdi] > 0) {
			cout << "Saksýnýn Adý: " << saksiAdi << " , Saksý topraðýndaki nem deðeri: " << mSalonSaksi[saksiAdi] << endl;
		}
		else if (mSalonSaksi[saksiAdi] == 0) {
			cout << "Saksýnýn Adý: " << saksiAdi << " , Saksý topraðý kurumuþ." << endl;
		}
	}
	else {
		cout << endl << getSalonAdi() << " isimli salonunuzada böyle bir saksý bulunmuyor!\n";
	}
}

//Girilen Saksý Durumunu Deðiþtirme
void salon::saksiDurumunuDegistirme() {
	string saksiAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz saksýnýn adýný giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mSalonSaksi.find(saksiAdi) != mSalonSaksi.end()) {
	hataliTuslama:
		cout << "Saksýyý sulamak ve nem deðerini ayarlamak için '100 - 0' arasýnda bir deðer giriniz (100 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 100 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mSalonSaksi[saksiAdi] = onOff;
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
		cout << endl << getSalonAdi() << " isimli salonunuzda böyle bir saksý bulunmuyor!\n";
	}
}

//Priz ekleme
void salon::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "Lütfen Salonda bulunan " << mSalonPriz.size() + 1 << ". prizin adýný giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mSalonPriz[prizIsmi] = 0;
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
void salon::prizlerinListelenmesi() {
	cout << salon::salonAdi << " isimli salonda " << mSalonPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mSalonPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
}

//Priz çýkartma
void salon::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mSalonPriz.size() != 0) {
		if (mSalonPriz.find(prizSilinecek) != mSalonPriz.end()) {
			mSalonPriz.erase(prizSilinecek);
			cout << prizSilinecek << "Ýsimli priz salondan çýkarýlmýþtýr...\n\n";
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
void salon::prizDurumuSorgulama() {
	string prizAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mSalonPriz.find(prizAdi) != mSalonPriz.end()) {
		if (mSalonPriz[prizAdi] == 1) {
			cout << "Prizin Adý: " << prizAdi << " , Priz açýk konumda." << endl;
		}
		else if (mSalonPriz[prizAdi] == 0) {
			cout << "Prizin Adý: " << prizAdi << " , Priz kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << salon::salonAdi<< " isimli salonunuzda böyle bir priz bulunmuyor!\n";
	}
}

//Girilen priz adýnýn durumunun deðiþtirilmesi
void salon::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mSalonPriz.find(prizAdi) != mSalonPriz.end()) {
	hataliTuslama:
		cout << "Prizi açmak için '1',Kapatmak için '0' ý tuþlayýnýz: ";
		cin >> onOff;
		try {
			if (onOff != 1 && onOff != 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mSalonPriz[prizAdi] = onOff;
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
		cout << endl << salon::salonAdi<< " isimli salonunuzda böyle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void salon::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "Lütfen Salonda bulunan " << mSalonLamp.size() + 1 << ". lambanýn adýný giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mSalonLamp[lambaIsmi] = 0;
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
void salon::lambalarinListelenmesi() {
	cout << salon::salonAdi<< " isimli salonda " << mSalonLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mSalonLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}

	}
}

//Lamba çýkarma
void salon::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mSalonLamp.size() != 0) {
		if (mSalonLamp.find(lampSilinecek) != mSalonLamp.end()) {
			mSalonLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba salondan çýkarýlmýþtýr...\n\n";
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
void salon::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mSalonLamp.find(lampAdi) != mSalonLamp.end()) {
		if (mSalonLamp[lampAdi] > 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba açýk konumda ve deðeri: " << mSalonLamp[lampAdi] << endl;
		}
		else if (mSalonLamp[lampAdi] == 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << salon::salonAdi << " isimli salonunuzda böyle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba adýnýn durumunun deðiþtirilmesi
void salon::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mSalonLamp.find(lampAdi) != mSalonLamp.end()) {
	hataliTuslama:
		cout << "Lambayý açmak için '1024 - 0' arasýnda bir deðer giriniz (1024 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 1024 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mSalonLamp[lampAdi] = onOff;
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
		cout << endl << salon::salonAdi<< " isimli salonunuzda böyle bir lamba bulunmuyor!\n";
	}
}

//Prizleri ve Lambalarý listeme
void salon::prizlerinVeLambalarinListelenmesi() {
	cout << salon::salonAdi<< " isimli salonda " << mSalonPriz.size() << " adet priz ve ";
	cout << mSalonLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mSalonPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mSalonLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}
	}
}

//Yangýn Durumu
void salon::yanginVar() {
	cout <<getSalonAdi() << " isimli salonda Yangýn Var!" << endl << endl;
}

//Yangýn Yok Durumu
void salon::yanginYok() {

}

//Su Baskýný Durumu
void salon::suBaskiniVar() {
	cout << getSalonAdi() << " isimli salonu Su Bastý!" << endl << endl;
}

//Su Baskýný Yok Durumu
void salon::suBaskiniYok() {

}

//Hýrsýz Girmesi Durumu
void salon::hirsizGirdi() {
	cout << getSalonAdi() << " isimli salondan Hýrsýz Girdi!" << endl << endl;
}

//Hýrsýz Yok Durumu
void salon::hirsizYok() {

}

//Sicaklýk ve Nem Kontrolü
void salon::sicaklikVeNemDurum() {
	cout << getSalonAdi() << " isimli salonun sýcaklýðý: " << sicaklik << " °C, nem deðeri: " << nem << " RH'dir." << endl << endl;
}