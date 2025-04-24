#include "Tuvalet.h"

map <string, int> mTuvaletPriz;
map <string, float> mTuvaletLamp;

//CONSTRACTOR
tuvalet::tuvalet(string _tuvaletAdi) : home(_tuvaletAdi) {
	tuvalet::tuvaletAdi = _tuvaletAdi;
	yang�nDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
}

//DESTRUCTOR
tuvalet::~tuvalet() {
	cout << getTuvaletAdi() << "'in Destructor'� �a��r�ld�." << endl;
}

//Tuvalet Ad� ��renme
string tuvalet::getTuvaletAdi() {
	return tuvalet::tuvaletAdi;
}

//Tuvalet Ad�n� De�i�tirme
void tuvalet::setTuvaletAdi(string _tuvaletAdi) {
	tuvalet::tuvaletAdi = _tuvaletAdi;
}

//Tuvaletteki Priz Say�s�n� ��renme
int tuvalet::getTuvaletPrizSayac() {
	return mTuvaletPriz.size();
}

//Tuvaletteki Lamba Say�s�n� ��renme
int tuvalet::getTuvaletLampSayac() {
	return mTuvaletLamp.size();
}

// Tuvaletteki Yang�n Durumunu ��renme
int tuvalet::getYanginDurum() {
	return yang�nDurum;
}

//Tuvaletteki Yang�n Durumunu De�i�tirme
void tuvalet::setYanginDurum(int _guvenlikDegisken) {
	yang�nDurum = _guvenlikDegisken;
}

//Tuvaletteki Su Bask�n� Durumunu ��renme
int tuvalet::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Tuvaletteki Su Bask�n� Durumunu De�i�tirme
void tuvalet::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Tuvaletteki H�rs�z Durumunu ��renme
int tuvalet::getHirsizDurum() {
	return hirsizDurum;
}

//Tuvaletteki H�rs�z Durumunu De�i�tirme
void tuvalet::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Priz ekleme
void tuvalet::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "L�tfen Tuvalette bulunan " << mTuvaletPriz.size() + 1 << ". prizin ad�n� giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mTuvaletPriz[prizIsmi] = 0;
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
void tuvalet::prizlerinListelenmesi() {
	cout << tuvalet::tuvaletAdi << " isimli tuvalette " << mTuvaletPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mTuvaletPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
}

//Priz ��kartma
void tuvalet::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mTuvaletPriz.size() != 0) {
		if (mTuvaletPriz.find(prizSilinecek) != mTuvaletPriz.end()) {
			mTuvaletPriz.erase(prizSilinecek);
			cout << prizSilinecek << "�simli priz tuvaletten ��kar�lm��t�r...\n\n";
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
void tuvalet::prizDurumuSorgulama() {
	string prizAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mTuvaletPriz.find(prizAdi) != mTuvaletPriz.end()) {
		if (mTuvaletPriz[prizAdi] == 1) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz a��k konumda." << endl;
		}
		else if (mTuvaletPriz[prizAdi] == 0) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << tuvalet::tuvaletAdi << " isimli tuvalette b�yle bir priz bulunmuyor!\n";
	}
}

//Girilen priz ad�n�n durumunun de�i�tirilmesi
void tuvalet::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mTuvaletPriz.find(prizAdi) != mTuvaletPriz.end()) {
	hataliTuslama:
		cout << "Prizi a�mak i�in '1',Kapatmak i�in '0' � tu�lay�n�z: ";
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
		cout << endl << tuvalet::tuvaletAdi << " isimli tuvalette b�yle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void tuvalet::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "L�tfen Tuvalette bulunan " << mTuvaletLamp.size() + 1 << ". lamban�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mTuvaletLamp[lambaIsmi] = 0;
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
void tuvalet::lambalarinListelenmesi() {
	cout << tuvalet::tuvaletAdi<< " isimli tuvalette " << mTuvaletLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mTuvaletLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}

	}
}

//Lamba ��karma
void tuvalet::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mTuvaletLamp.size() != 0) {
		if (mTuvaletLamp.find(lampSilinecek) != mTuvaletLamp.end()) {
			mTuvaletLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba tuvaletten ��kar�lm��t�r...\n\n";
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
void tuvalet::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mTuvaletLamp.find(lampAdi) != mTuvaletLamp.end()) {
		if (mTuvaletLamp[lampAdi] > 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba a��k konumda ve de�eri: " << mTuvaletLamp[lampAdi] << endl;
		}
		else if (mTuvaletLamp[lampAdi] == 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << tuvalet::tuvaletAdi << " isimli tuvaletinizde b�yle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba ad�n�n durumunun de�i�tirilmesi
void tuvalet::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mTuvaletLamp.find(lampAdi) != mTuvaletLamp.end()) {
	hataliTuslama:
		cout << "Lambay� a�mak i�in '1024 - 0' aras�nda bir de�er giriniz (1024 = MAX, 0 = M�N): ";
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
		cout << endl << tuvalet::tuvaletAdi << " isimli tuvaletinizden b�yle bir priz bulunmuyor!\n";
	}
}

//Prizleri ve Lambalar� listeme
void tuvalet::prizlerinVeLambalarinListelenmesi() {
	cout << tuvalet::tuvaletAdi << " isimli tuvalette " << mTuvaletPriz.size() << " adet priz ve ";
	cout << mTuvaletLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mTuvaletPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mTuvaletLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}
	}
}

//Yang�n Durumu
void tuvalet::yanginVar() {
	cout << getTuvaletAdi() <<" isimli tuvalette Yang�n Var!" << endl << endl;
}

//Yang�n Yok Durumu
void tuvalet::yanginYok() {

}

//Su Bask�n� Durumu
void tuvalet::suBaskiniVar() {
	cout << getTuvaletAdi() << " isimli tuvaleti Su Bast�!" << endl << endl;
}

//Su Bask�n� Yok Durumu
void tuvalet::suBaskiniYok() {

}

//H�rs�z Girmesi Durumu
void tuvalet::hirsizGirdi() {
	cout << getTuvaletAdi() << " isimli tuvaletten H�rs�z Girdi!" << endl << endl;
}

//H�rs�z Yok Durumu
void tuvalet::hirsizYok() {

}
