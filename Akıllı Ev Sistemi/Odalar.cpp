#include "Odalar.h"


//CONSTRACTOR
odalar::odalar() : home() {

}

//DESTRUCTOR
odalar::~odalar() {
	cout << getOdaAdi() << "'in Destructor'� �a��r�ld�." << endl;
}

//CONSTRACTOR
odalar::odalar(string _odaAdi, map <string, int> _mOdaPriz, map <string, float> _mOdaLamp, map<string, float> _mOdaSaksi) {
	odalar::odaAdi = _odaAdi;
	mOdaPriz = _mOdaPriz;
	mOdaLamp = _mOdaLamp;
	mOdaSaksi = _mOdaSaksi;
	yang�nDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
	sicaklik = 25;
	nem = 25;
	perde = 0;
	klima = 0;
}

//Oda Ad� ��renme
string odalar::getOdaAdi() {
	return odalar::odaAdi;
}

//Oda Adi De�i�tirme
void odalar::setOdaAdi(string _odaAdi) {
	odalar::odaAdi = _odaAdi;
}

//Odadaki Priz Say�s�n� ��renme
int odalar::getOdaPrizSayac() {
	return mOdaPriz.size();
}

//Odadaki Lamba Say�s�n� ��renme
int odalar::getOdaLampSayac() {
	return mOdaLamp.size();
}

// Odadaki Yang�n Durumunu ��renme
int odalar::getYanginDurum() {
	return yang�nDurum;
}

//Odadaki Yang�n Durumunu De�i�tirme
void odalar::setYanginDurum(int _guvenlikDegisken) {
	yang�nDurum = _guvenlikDegisken;
}

//Odadaki Su Bask�n� Durumunu ��renme
int odalar::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Odadaki Su Bask�n� Durumunu De�i�tirme
void odalar::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Odadaki H�rs�z Durumunu ��renme
int odalar::getHirsizDurum() {
	return hirsizDurum;
}

//Odadaki H�rs�z Durumunu De�i�tirme
void odalar::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//S�cakl�k De�erini ��renme
float odalar::getSicaklikDeger() {
	return sicaklik;
}

//S�cakl�k De�erini De�i�tirme
void odalar::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem De�erini ��renme
float odalar::getNemDeger() {
	return nem;
}

//Nem De�erini De�i�tirme
void odalar::setNemDeger(float _nem) {
	nem = _nem;
}

//Perde Durumunu ��renme
int odalar::getPerdeDurum() {
	return perde;
}

//Perde Durumunu De�i�tirme
void odalar::setPerdeDurum(int _perde) {
	perde = _perde;
}

//Klima Durumunu ��renme
int odalar::getKlimaDurum() {
	return klima;
}

//Klima Durumunu De�i�tirme
void odalar::setKlimaDurum(int _klima) {
	klima = _klima;
}

//Saks� Sayac
int odalar::getSaksiSayac() {
	return mOdaSaksi.size();
}

//Saks� Ekleme
void odalar::saksiEkle() {
	string saksiIsmi, devamlilikDurumu;
	cout << "--> Saks� Ekleme <--\n\n\n";
	do {
		cout << "L�tfen odada bulunan " << mOdaSaksi.size() + 1 << ". saks�n�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, saksiIsmi);
		mOdaSaksi[saksiIsmi] = 0;
	hataliTuslama:
		cout << "Ba�ka bir saks� eklemek istiyor musunuz? (y/n): ";
		cin >> devamlilikDurumu;
		if (devamlilikDurumu == "y" || devamlilikDurumu == "Y") {
			devamlilikDurumu = "devam et";
		}
		else if (devamlilikDurumu == "n" || devamlilikDurumu == "N") {
			cout << "Saks� Ekleme B�l�m�nden ��k�� Yap�l�yor... \n\n";
			devamlilikDurumu = "devam etme";
		}
		else {
			cout << "Hatal� Tu�lama Yapt�n�z!";
			goto hataliTuslama;
		}
	} while (devamlilikDurumu != "devam etme");
}

//Saks�lar�n Listelenmesi
void odalar::saksilarinListelenmesi() {
	cout << getOdaAdi() << " isimli odada " << mOdaSaksi.size() << " adet saks� bulunuyor. Bunlar; \n";
	for (const auto& saksi : mOdaSaksi) {
		if (saksi.second > 0) {
			cout << "Saks�n�n Ad�: " << saksi.first << " , Saks� topra��ndaki nem de�eri: " << saksi.second << endl;
		}
		else if (saksi.second == 0) {
			cout << "Saks�n�n Ad�: " << saksi.first << " , Saks� topra�� kurumu�." << endl;
		}

	}
}

//Saks� ��karma
void odalar::saksiCikarma() {
	string saksiSilinecek;
	saksilarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiSilinecek);
	if (mOdaSaksi.size() != 0) {
		if (mOdaSaksi.find(saksiSilinecek) != mOdaSaksi.end()) {
			mOdaSaksi.erase(saksiSilinecek);
			cout << saksiSilinecek << " isimli saks� odadan ��kar�lm��t�r...\n\n";
		}
		else {
			cout << "Girdi�iniz saks� ad� bulunamad�!\n\n";
		}
	}
	else {
		cout << "Saks� bulunmyor! L�tfen �nce saks� ekleyiniz..." << endl << endl;
	}
}

//Girilen Saks� Durumunu Sorgulama
void odalar::saksiDurumuSorgulama() {
	string saksiAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mOdaSaksi.find(saksiAdi) != mOdaSaksi.end()) {
		if (mOdaSaksi[saksiAdi] > 0) {
			cout << "Saks�n�n Ad�: " << saksiAdi << " , Saks� topra��ndaki nem de�eri: " << mOdaSaksi[saksiAdi] << endl;
		}
		else if (mOdaSaksi[saksiAdi] == 0) {
			cout << "Saks�n�n Ad�: " << saksiAdi << " , Saks� topra�� kurumu�." << endl;
		}
	}
	else {
		cout << endl << getOdaAdi() << " isimli odan�zda b�yle bir saks� bulunmuyor!\n";
	}
}

//Girilen Saks� Durumunu De�i�tirme
void odalar::saksiDurumunuDegistirme() {
	string saksiAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mOdaSaksi.find(saksiAdi) != mOdaSaksi.end()) {
	hataliTuslama:
		cout << "Saks�y� sulamak ve nem de�erini ayarlamak i�in '100 - 0' aras�nda bir de�er giriniz (100 = MAX, 0 = M�N): ";
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
		cout << endl << getOdaAdi() << " isimli odan�zda b�yle bir saks� bulunmuyor!\n";
	}
}

//Priz ekleme
void odalar::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "L�tfen odada bulunan " << mOdaPriz.size() + 1 << ". prizin ad�n� giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mOdaPriz[prizIsmi] = 0;
	hataliTuslama:
		cout << "Ba�ka bir priz eklemek istiyor musunuz? (y/n): ";
		cin >> devamlilikDurumu;
		if (devamlilikDurumu == "y" || devamlilikDurumu == "Y") {
			devamlilikDurumu = "devam et";
		}
		else if (devamlilikDurumu == "n" || devamlilikDurumu == "N") {
			cout << "Priz Ekleme B�l�m�nden ��k�� Yap�l�yor... \n\n";
			devamlilikDurumu = "devam etme";
		}
		else {
			cout << "Hatal� Tu�lama Yapt�n�z!";
			goto hataliTuslama;
		}
	} while (devamlilikDurumu != "devam etme");
}

//Prizleri listeleme
void odalar::prizlerinListelenmesi() {
	cout << getOdaAdi() << " isimli odada " << mOdaPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mOdaPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}
	}
}

//Priz ��kartma
void odalar::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mOdaPriz.size() != 0) {
		if (mOdaPriz.find(prizSilinecek) != mOdaPriz.end()) {
			mOdaPriz.erase(prizSilinecek);
			cout << prizSilinecek << "�simli priz odadan ��kar�lm��t�r...\n\n";
		}
		else {
			cout << "Girdi�iniz priz ad� bulunamad�!\n\n";
		}
	}
	else {
		cout << "Priz bulunmyor! L�tfen �nce priz ekleyiniz..." << endl << endl;
	}
}

//Girilen prizin durumlar�n� sorgulama
void odalar::prizDurumuSorgulama() {
	string prizAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mOdaPriz.find(prizAdi) != mOdaPriz.end()) {
		if (mOdaPriz[prizAdi] == 1) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz a��k konumda." << endl;
		}
		else if (mOdaPriz[prizAdi] == 0) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << getOdaAdi() << " isimli odan�zda b�yle bir priz bulunmuyor!\n";
	}
}

//Girilen priz ad�n�n durumunun de�i�tirilmesi
void odalar::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mOdaPriz.find(prizAdi) != mOdaPriz.end()) {
	hataliTuslama:
		cout << "Prizi a�mak i�in '1',Kapatmak i�in '0' � tu�lay�n�z: ";
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
		cout << endl << getOdaAdi() << " isimli odan�zda b�yle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void odalar::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "L�tfen odada bulunan " << mOdaLamp.size() + 1 << ". lamban�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mOdaLamp[lambaIsmi] = 0;
	hataliTuslama:
		cout << "Ba�ka bir lamba eklemek istiyor musunuz? (y/n): ";
		cin >> devamlilikDurumu;
		if (devamlilikDurumu == "y" || devamlilikDurumu == "Y") {
			devamlilikDurumu = "devam et";
		}
		else if (devamlilikDurumu == "n" || devamlilikDurumu == "N") {
			cout << "Lamba Ekleme B�l�m�nden ��k�� Yap�l�yor... \n\n";
			devamlilikDurumu = "devam etme";
		}
		else {
			cout << "Hatal� Tu�lama Yapt�n�z!";
			goto hataliTuslama;
		}
	} while (devamlilikDurumu != "devam etme");
}

//Lambalar� listeleme
void odalar::lambalarinListelenmesi() {
	cout << getOdaAdi() << " isimli odada " << mOdaLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mOdaLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}

	}
}

//Lamba ��karma
void odalar::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mOdaLamp.size() != 0) {
		if (mOdaLamp.find(lampSilinecek) != mOdaLamp.end()) {
			mOdaLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba odadan ��kar�lm��t�r...\n\n";
		}
		else {
			cout << "Girdi�iniz lamba ad� bulunamad�!\n\n";
		}
	}
	else {
		cout << "Lamba bulunmyor! L�tfen �nce lamba ekleyiniz..." << endl << endl;
	}
}

//Girilen lamban�n durumunu sorgulama
void odalar::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mOdaLamp.find(lampAdi) != mOdaLamp.end()) {
		if (mOdaLamp[lampAdi] > 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba a��k konumda ve de�eri: " << mOdaLamp[lampAdi] << endl;
		}
		else if (mOdaLamp[lampAdi] == 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << getOdaAdi() << " isimli odan�zda b�yle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba ad�n�n durumunun de�i�tirilmesi
void odalar::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mOdaLamp.find(lampAdi) != mOdaLamp.end()) {
	hataliTuslama:
		cout << "Lambay� a�mak i�in '1024 - 0' aras�nda bir de�er giriniz (1024 = MAX, 0 = M�N): ";
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
		cout << endl << getOdaAdi() << " isimli odan�zda b�yle bir lamba bulunmuyor!\n";
	}
}

//Prizleri ve Lambalar� listeme
void odalar::prizlerinVeLambalarinListelenmesi() {
	cout << getOdaAdi() << " isimli odada " << mOdaPriz.size() << " adet priz ve ";
	cout << mOdaLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mOdaPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mOdaLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}
	}
}

//Yang�n Durumu
void odalar::yanginVar() {
	cout << getOdaAdi() << " isimli odada Yang�n Var!" << endl << endl;
}

//Yang�n Yok Durumu
void odalar::yanginYok() {

}

//Su Bask�n� Durumu
void odalar::suBaskiniVar() {
	cout << getOdaAdi() << " isimli oday� Su Bast�!" << endl << endl;
}

//Su Bask�n� Yok Durumu
void odalar::suBaskiniYok() {

}

//H�rs�z Girmesi Durumu
void odalar::hirsizGirdi() {
	cout << getOdaAdi() << " isimli odadan H�rs�z Girdi!" << endl << endl;
}

//H�rs�z Yok Durumu
void odalar::hirsizYok() {

}

//Sicakl�k ve Nem Kontrol�
void odalar::sicaklikVeNemDurum() {
	cout << getOdaAdi() << " isimli odan�n s�cakl���: " << sicaklik << " �C, nem de�eri: " << nem << " RH'dir." << endl << endl;
}
