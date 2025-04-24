#include "Koridor.h"

map <string, int> mKoridorPriz;
map <string, float> mKoridorLamp;
map <string, float> mKoridorSaksi;

//CONSTRACTOR
koridor::koridor(string _koridorAdi) : home(_koridorAdi) {
	koridor::koridorAdi = _koridorAdi;
	yang�nDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
	sicaklik = 25;
	nem = 25;
}

//DESTRUCTOR
koridor::~koridor() {
	cout << getKoridorAdi() << "'in Destructor'� �a��r�ld�." << endl;
}

//Koridor Ad� ��renme
string koridor::getKoridorAdi() {
	return koridor::koridorAdi;
}

//Koridor Ad�n� De�i�tirme
void koridor::setKoridorAdi(string _koridorAdi) {
	koridor::koridorAdi = _koridorAdi;
}

//Koridordaki Priz Say�s�n� ��renme
int koridor::getKoridorPrizSayac() {
	return mKoridorPriz.size();
}

//Koridordaki Lamba Say�s�n� ��renme
int koridor::getKoridorLampSayac() {
	return mKoridorLamp.size();
}

// Koridordaki Yang�n Durumunu ��renme
int koridor::getYanginDurum() {
	return yang�nDurum;
}

//Koridordaki Yang�n Durumunu De�i�tirme
void koridor::setYanginDurum(int _guvenlikDegisken) {
	yang�nDurum = _guvenlikDegisken;
}

//Koridordaki Su Bask�n� Durumunu ��renme
int koridor::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Koridordaki Su Bask�n� Durumunu De�i�tirme
void koridor::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Koridordaki H�rs�z Durumunu ��renme
int koridor::getHirsizDurum() {
	return hirsizDurum;
}

//Koridordaki H�rs�z Durumunu De�i�tirme
void koridor::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//S�cakl�k De�erini ��renme
float koridor::getSicaklikDeger() {
	return sicaklik;
}

//S�cakl�k De�erini De�i�tirme
void koridor::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem De�erini ��renme
float koridor::getNemDeger() {
	return nem;
}

//Nem De�erini De�i�tirme
void koridor::setNemDeger(float _nem) {
	nem = _nem;
}

//Saks� Sayac
int koridor::getSaksiSayac() {
	return mKoridorSaksi.size();
}

//Saks� Ekleme
void koridor::saksiEkle() {
	string saksiIsmi, devamlilikDurumu;
	cout << "--> Saks� Ekleme <--\n\n\n";
	do {
		cout << "L�tfen koridorda bulunan " << mKoridorSaksi.size() + 1 << ". saks�n�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, saksiIsmi);
		mKoridorSaksi[saksiIsmi] = 0;
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
void koridor::saksilarinListelenmesi() {
	cout << getKoridorAdi() << " isimli koridorda " << mKoridorSaksi.size() << " adet saks� bulunuyor. Bunlar; \n";
	for (const auto& saksi : mKoridorSaksi) {
		if (saksi.second > 0) {
			cout << "Saks�n�n Ad�: " << saksi.first << " , Saks� topra��ndaki nem de�eri: " << saksi.second << endl;
		}
		else if (saksi.second == 0) {
			cout << "Saks�n�n Ad�: " << saksi.first << " , Saks� topra�� kurumu�." << endl;
		}

	}
}

//Saks� ��karma
void koridor::saksiCikarma() {
	string saksiSilinecek;
	saksilarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiSilinecek);
	if (mKoridorSaksi.size() != 0) {
		if (mKoridorSaksi.find(saksiSilinecek) != mKoridorSaksi.end()) {
			mKoridorSaksi.erase(saksiSilinecek);
			cout << saksiSilinecek << " isimli saks� koridordan ��kar�lm��t�r...\n\n";
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
void koridor::saksiDurumuSorgulama() {
	string saksiAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mKoridorSaksi.find(saksiAdi) != mKoridorSaksi.end()) {
		if (mKoridorSaksi[saksiAdi] > 0) {
			cout << "Saks�n�n Ad�: " << saksiAdi << " , Saks� topra��ndaki nem de�eri: " << mKoridorSaksi[saksiAdi] << endl;
		}
		else if (mKoridorSaksi[saksiAdi] == 0) {
			cout << "Saks�n�n Ad�: " << saksiAdi << " , Saks� topra�� kurumu�." << endl;
		}
	}
	else {
		cout << endl << getKoridorAdi() << " isimli koridorunuzda b�yle bir saks� bulunmuyor!\n";
	}
}

//Girilen Saks� Durumunu De�i�tirme
void koridor::saksiDurumunuDegistirme() {
	string saksiAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mKoridorSaksi.find(saksiAdi) != mKoridorSaksi.end()) {
	hataliTuslama:
		cout << "Saks�y� sulamak ve nem de�erini ayarlamak i�in '100 - 0' aras�nda bir de�er giriniz (100 = MAX, 0 = M�N): ";
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
		cout << endl << getKoridorAdi() << " isimli koridorunuzda b�yle bir saks� bulunmuyor!\n";
	}
}

//Priz ekleme
void koridor::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "L�tfen Koridorda bulunan " << mKoridorPriz.size() + 1 << ". prizin ad�n� giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mKoridorPriz[prizIsmi] = 0;
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
void koridor::prizlerinListelenmesi() {
	cout << getKoridorAdi() << " isimli koridorda " << mKoridorPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mKoridorPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
}

//Priz ��kartma
void koridor::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mKoridorPriz.size() != 0) {
		if (mKoridorPriz.find(prizSilinecek) != mKoridorPriz.end()) {
			mKoridorPriz.erase(prizSilinecek);
			cout << prizSilinecek << "�simli priz koridordan ��kar�lm��t�r...\n\n";
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
void koridor::prizDurumuSorgulama() {
	string prizAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mKoridorPriz.find(prizAdi) != mKoridorPriz.end()) {
		if (mKoridorPriz[prizAdi] == 1) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz a��k konumda." << endl;
		}
		else if (mKoridorPriz[prizAdi] == 0) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << getKoridorAdi() << " isimli koridorda b�yle bir priz bulunmuyor!\n";
	}
}

//Girilen priz ad�n�n durumunun de�i�tirilmesi
void koridor::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mKoridorPriz.find(prizAdi) != mKoridorPriz.end()) {
	hataliTuslama:
		cout << "Prizi a�mak i�in '1',Kapatmak i�in '0' � tu�lay�n�z: ";
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
		cout << endl << getKoridorAdi() << " isimli koridorda b�yle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void koridor::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "L�tfen Koridorda bulunan " << mKoridorLamp.size() + 1 << ". lamban�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mKoridorLamp[lambaIsmi] = 0;
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
void koridor::lambalarinListelenmesi() {
	cout << getKoridorAdi() << " isimli koridorda " << mKoridorLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mKoridorLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}

	}
}

//Lamba ��karma
void koridor::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mKoridorLamp.size() != 0) {
		if (mKoridorLamp.find(lampSilinecek) != mKoridorLamp.end()) {
			mKoridorLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba koridordan ��kar�lm��t�r...\n\n";
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
void koridor::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mKoridorLamp.find(lampAdi) != mKoridorLamp.end()) {
		if (mKoridorLamp[lampAdi] > 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba a��k konumda ve de�eri: " << mKoridorLamp[lampAdi] << endl;
		}
		else if (mKoridorLamp[lampAdi] == 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << getKoridorAdi() << " isimli koridorunuzda b�yle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba ad�n�n durumunun de�i�tirilmesi
void koridor::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mKoridorLamp.find(lampAdi) != mKoridorLamp.end()) {
	hataliTuslama:
		cout << "Lambay� a�mak i�in '1024 - 0' aras�nda bir de�er giriniz (1024 = MAX, 0 = M�N): ";
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
		cout << endl << getKoridorAdi() << " isimli koridornuzda b�yle bir priz bulunmuyor!\n";
	}
}

//Prizleri ve Lambalar� listeme
void koridor::prizlerinVeLambalarinListelenmesi() {
	cout << getKoridorAdi() << " isimli koridorda " << mKoridorPriz.size() << " adet priz ve ";
	cout << mKoridorLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mKoridorPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mKoridorLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}
	}
}

//Yang�n Durumu
void koridor::yanginVar() {
	cout << getKoridorAdi() << " isimli koridorda Yang�n Var!" << endl << endl;
}

//Yang�n Yok Durumu
void koridor::yanginYok() {

}

//Su Bask�n� Durumu
void koridor::suBaskiniVar() {
	cout << getKoridorAdi() << " isimli koridoru Su Bast�!" << endl << endl;
}

//Su Bask�n� Yok Durumu
void koridor::suBaskiniYok() {

}

//H�rs�z Girmesi Durumu
void koridor::hirsizGirdi() {
	cout << getKoridorAdi() << " isimli koridordan H�rs�z Girdi!" << endl << endl;
}

//H�rs�z Yok Durumu
void koridor::hirsizYok() {

}

//Sicakl�k ve Nem Kontrol�
void koridor::sicaklikVeNemDurum() {
	cout << getKoridorAdi() << " isimli koridorun s�cakl���: " << sicaklik << " �C, nem de�eri: " << nem << " RH'dir." << endl << endl;
}
