#include "Banyo.h"

map <string, int> mBanyoPriz;
map <string, float> mBanyoLamp;

//CONSTRACTOR
banyo::banyo(string _banyoAdi) : home(_banyoAdi) {
	banyo::banyoAdi = _banyoAdi;
	yangýnDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
}

//DESTRUCTOR
banyo::~banyo() {
	cout << getBanyoAdi() << "'in Destructor'ý çaðýrýldý." << endl;
}

//Banyo Adý Öðrenme
string banyo::getBanyoAdi() {
	return banyo::banyoAdi;
}

//Banyo Adýný Deðiþtirme
void banyo::setBanyoAdi(string _banyoAdi) {
	banyo::banyoAdi = _banyoAdi;
}

//Baynodaki Priz Sayýsýný Öðrenme
int banyo::getBanyoPrizSayac() {
	return mBanyoPriz.size();
}

//Baynodaki Lamba Sayýsýný Öðrenme
int banyo::getBanyoLampSayac() {
	return mBanyoLamp.size();
}

// Baynodaki Yangýn Durumunu Öðrenme
int banyo::getYanginDurum() {
	return yangýnDurum;
}

//Baynodaki Yangýn Durumunu Deðiþtirme
void banyo::setYanginDurum(int _guvenlikDegisken) {
	yangýnDurum = _guvenlikDegisken;
}

//Baynodaki Su Baskýný Durumunu Öðrenme
int banyo::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Baynodaki Su Baskýný Durumunu Deðiþtirme
void banyo::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Baynodaki Hýrsýz Durumunu Öðrenme
int banyo::getHirsizDurum() {
	return hirsizDurum;
}

//Baynodaki Hýrsýz Durumunu Deðiþtirme
void banyo::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Priz ekleme
void banyo::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "Lütfen Banyoda bulunan " << mBanyoPriz.size() + 1 << ". prizin adýný giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mBanyoPriz[prizIsmi] = 0;
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
void banyo::prizlerinListelenmesi() {
	cout << banyo::banyoAdi << " isimli banyoda " << mBanyoPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mBanyoPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
}

//Priz çýkartma
void banyo::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mBanyoPriz.size() != 0) {
		if (mBanyoPriz.find(prizSilinecek) != mBanyoPriz.end()) {
			mBanyoPriz.erase(prizSilinecek);
			cout << prizSilinecek << "Ýsimli priz banyodan çýkarýlmýþtýr...\n\n";
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
void banyo::prizDurumuSorgulama() {
	string prizAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mBanyoPriz.find(prizAdi) != mBanyoPriz.end()) {
		if (mBanyoPriz[prizAdi] == 1) {
			cout << "Prizin Adý: " << prizAdi << " , Priz açýk konumda." << endl;
		}
		else if (mBanyoPriz[prizAdi] == 0) {
			cout << "Prizin Adý: " << prizAdi << " , Priz kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << banyo::banyoAdi << " isimli banyonuzda böyle bir priz bulunmuyor!\n";
	}
}

//Girilen priz adýnýn durumunun deðiþtirilmesi
void banyo::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mBanyoPriz.find(prizAdi) != mBanyoPriz.end()) {
	hataliTuslama:
		cout << "Prizi açmak için '1',Kapatmak için '0' ý tuþlayýnýz: ";
		cin >> onOff;
		try {
			if (onOff != 1 && onOff != 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mBanyoPriz[prizAdi] = onOff;
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
		cout << endl << banyo::banyoAdi<< " isimli banyonuzda böyle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void banyo::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "Lütfen Banyoda bulunan " << mBanyoLamp.size() + 1 << ". lambanýn adýný giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mBanyoLamp[lambaIsmi] = 0;
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
void banyo::lambalarinListelenmesi() {
	cout << banyo::banyoAdi << " isimli banyoda " << mBanyoLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mBanyoLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}

	}
}

//Lamba çýkarma
void banyo::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "Lütfen çýkartmak istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mBanyoLamp.size() != 0) {
		if (mBanyoLamp.find(lampSilinecek) != mBanyoLamp.end()) {
			mBanyoLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba banyodan çýkarýlmýþtýr...\n\n";
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
void banyo::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "Lütfen durumunu öðrenmek istediðiniz prizin adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mBanyoLamp.find(lampAdi) != mBanyoLamp.end()) {
		if (mBanyoLamp[lampAdi] > 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba açýk konumda ve deðeri: " << mBanyoLamp[lampAdi] << endl;
		}
		else if (mBanyoLamp[lampAdi] == 0) {
			cout << "Lambanýn Adý: " << lampAdi << " , Lamba kapalý konumda." << endl;
		}
	}
	else {
		cout << endl << banyo::banyoAdi << " isimli banyonuzda böyle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba adýnýn durumunun deðiþtirilmesi
void banyo::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "Lütfen durumunu deðiþtirmek istediðiniz lambanýn adýný giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mBanyoLamp.find(lampAdi) != mBanyoLamp.end()) {
	hataliTuslama:
		cout << "Lambayý açmak için '1024 - 0' arasýnda bir deðer giriniz (1024 = MAX, 0 = MÝN): ";
		cin >> onOff;
		try {
			if (onOff > 1024 || onOff < 0)
				throw 101;
			else if (cin.fail())
				throw 102;
			mBanyoLamp[lampAdi] = onOff;
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
		cout << endl << banyo::banyoAdi << " isimli banyonuzda böyle bir priz bulunmuyor!\n";
	}
}

//Prizleri ve Lambalarý listeme
void banyo::prizlerinVeLambalarinListelenmesi() {
	cout << banyo::banyoAdi << " isimli banyoda " << mBanyoPriz.size() << " adet priz ve ";
	cout << mBanyoLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mBanyoPriz) {
		if (priz.second == 1) {
			cout << "Prizin Adý: " << priz.first << " , Priz açýk konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Adý: " << priz.first << " , Priz kapalý konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mBanyoLamp) {
		if (lamp.second > 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba açýk konumda ve deðeri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lambanýn Adý: " << lamp.first << " , Lamba kapalý konumda." << endl;
		}
	}
}

//Yangýn Durumu
void banyo::yanginVar() {
	cout << getBanyoAdi() << " isimli banyoda Yangýn Var!" << endl << endl;
}

//Yangýn Yok Durumu
void banyo::yanginYok() {

}

//Su Baskýný Durumu
void banyo::suBaskiniVar() {
	cout << getBanyoAdi() << " isimli banyoyu Su Bastý!" << endl << endl;
}

//Su Baskýný Yok Durumu
void banyo::suBaskiniYok() {

}

//Hýrsýz Girmesi Durumu
void banyo::hirsizGirdi() {
	cout << getBanyoAdi() << " isimli banyodan Hýrsýz Girdi!" << endl << endl;
}

//Hýrsýz Yok Durumu
void banyo::hirsizYok() {

}