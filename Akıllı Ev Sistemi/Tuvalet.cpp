#include "Tuvalet.h"

map <string, int> mTuvaletPriz;
map <string, float> mTuvaletLamp;

//CONSTRACTOR
tuvalet::tuvalet(string _tuvaletAdi) : home(_tuvaletAdi) {
	tuvalet::tuvaletAdi = _tuvaletAdi;
	yangýnDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
}

//DESTRUCTOR
tuvalet::~tuvalet() {
	cout << getTuvaletAdi() << "'in Destructor'ý çaðýrýldý." << endl;
}

//Tuvalet Adý Öðrenme
string tuvalet::getTuvaletAdi() {
	return tuvalet::tuvaletAdi;
}

//Tuvalet Adýný Deðiþtirme
void tuvalet::setTuvaletAdi(string _tuvaletAdi) {
	tuvalet::tuvaletAdi = _tuvaletAdi;
}

//Tuvaletteki Priz Sayýsýný Öðrenme
int tuvalet::getTuvaletPrizSayac() {
	return mTuvaletPriz.size();
}

//Tuvaletteki Lamba Sayýsýný Öðrenme
int tuvalet::getTuvaletLampSayac() {
	return mTuvaletLamp.size();
}

// Tuvaletteki Yangýn Durumunu Öðrenme
int tuvalet::getYanginDurum() {
	return yangýnDurum;
}

//Tuvaletteki Yangýn Durumunu Deðiþtirme
void tuvalet::setYanginDurum(int _guvenlikDegisken) {
	yangýnDurum = _guvenlikDegisken;
}

//Tuvaletteki Su Baskýný Durumunu Öðrenme
int tuvalet::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Tuvaletteki Su Baskýný Durumunu Deðiþtirme
void tuvalet::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Tuvaletteki Hýrsýz Durumunu Öðrenme
int tuvalet::getHirsizDurum() {
	return hirsizDurum;
}

//Tuvaletteki Hýrsýz Durumunu Deðiþtirme
void tuvalet::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Priz ekleme
void tuvalet::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "Lütfen Tuvalette bulunan " << mTuvaletPriz.size() + 1 << ". prizin adýný giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mTuvaletPriz[prizIsmi] = 0;
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
void tuvalet::prizlerinListelenmesi() {
	cout << tuvalet::tuvaletAdi << " isimli tuvalette " << mTuvaletPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mTuvaletPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
}

//Priz çýkartma
void tuvalet::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mTuvaletPriz.size() != 0) {
		if (mTuvaletPriz.find(prizSilinecek) != mTuvaletPriz.end()) {
			mTuvaletPriz.erase(prizSilinecek);
			cout << prizSilinecek << "Ýsimli priz tuvaletten çýkarýlmýþtýr...\n\n";
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
void tuvalet::prizDurumuSorgulama() {
	string prizAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mTuvaletPriz.find(prizAdi) != mTuvaletPriz.end()) {
		if (mTuvaletPriz[prizAdi] == 1) {
			cout << "Prizin Adý: " << prizAdi << " , Priz açýk konumda." << endl;
		}
		else if (mTuvaletPriz[prizAdi] == 0) {
			cout << "Prizin Adý: " << prizAdi << " , Priz kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << tuvalet::tuvaletAdi << " isimli tuvalette böyle bir priz bulunmuyor!\n";
	}
}

//Girilen priz adýnýn durumunun deðiþtirilmesi
void tuvalet::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mTuvaletPriz.find(prizAdi) != mTuvaletPriz.end()) {
	hataliTuslama:
		cout << "Prizi açmak için '1',Kapatmak için '0' ý tuþlayýnýz: ";
		cin >> onOff;
		try {
			if (onOff != 1 && onOff != 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mTuvaletPriz[prizAdi] = onOff;
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
		cout << endl << tuvalet::tuvaletAdi << " isimli tuvalette böyle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void tuvalet::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "Lütfen Tuvalette bulunan " << mTuvaletLamp.size() + 1 << ". lambanýn adýný giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mTuvaletLamp[lambaIsmi] = 0;
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
void tuvalet::lambalarinListelenmesi() {
	cout << tuvalet::tuvaletAdi<< " isimli tuvalette " << mTuvaletLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mTuvaletLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}

	}
}

//Lamba çýkarma
void tuvalet::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mTuvaletLamp.size() != 0) {
		if (mTuvaletLamp.find(lampSilinecek) != mTuvaletLamp.end()) {
			mTuvaletLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba tuvaletten çýkarýlmýþtýr...\n\n";
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
void tuvalet::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mTuvaletLamp.find(lampAdi) != mTuvaletLamp.end()) {
		if (mTuvaletLamp[lampAdi] > 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba açýk konumda ve deðeri: " << mTuvaletLamp[lampAdi] << endl;
		}
		else if (mTuvaletLamp[lampAdi] == 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << tuvalet::tuvaletAdi << " isimli tuvaletinizde böyle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba adýnýn durumunun deðiþtirilmesi
void tuvalet::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mTuvaletLamp.find(lampAdi) != mTuvaletLamp.end()) {
	hataliTuslama:
		cout << "Lambayý açmak için '1024 - 0' arasýnda bir deðer giriniz (1024 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 1024 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mTuvaletLamp[lampAdi] = onOff;
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
		cout << endl << tuvalet::tuvaletAdi << " isimli tuvaletinizden böyle bir priz bulunmuyor!\n";
	}
}

//Prizleri ve Lambalarý listeme
void tuvalet::prizlerinVeLambalarinListelenmesi() {
	cout << tuvalet::tuvaletAdi << " isimli tuvalette " << mTuvaletPriz.size() << " adet priz ve ";
	cout << mTuvaletLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mTuvaletPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mTuvaletLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}
	}
}

//Yangýn Durumu
void tuvalet::yanginVar() {
	cout << getTuvaletAdi() <<" isimli tuvalette Yangýn Var!" << endl << endl;
}

//Yangýn Yok Durumu
void tuvalet::yanginYok() {

}

//Su Baskýný Durumu
void tuvalet::suBaskiniVar() {
	cout << getTuvaletAdi() << " isimli tuvaleti Su Bastý!" << endl << endl;
}

//Su Baskýný Yok Durumu
void tuvalet::suBaskiniYok() {

}

//Hýrsýz Girmesi Durumu
void tuvalet::hirsizGirdi() {
	cout << getTuvaletAdi() << " isimli tuvaletten Hýrsýz Girdi!" << endl << endl;
}

//Hýrsýz Yok Durumu
void tuvalet::hirsizYok() {

}
