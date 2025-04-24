#include "Mutfak.h"

map <string, int> mPriz;
map <string, float> mLamp;
map<string, float> mMutfakSaksi;

//CONSTRACTOR
mutfak::mutfak(string _mutfakAdi) : home(_mutfakAdi) {
	mutfak::mutfakAdi = _mutfakAdi;
	yang�nDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
	sicaklik = 25;
	nem = 25;
	kombi = 0;
	perde = 0;
}

//DESTRUCTOR
mutfak::~mutfak() {
	cout << getMutfakAdi() << "'in Destructor'� �a��r�ld�." << endl;
}

//Mutfak Ad� ��renme
string mutfak::getMutfakAdi() {
	return mutfak::mutfakAdi;
}

//Mutfak Adi De�i�tirme
void mutfak::setMutfakAdi(string _mutfakAdi) {
	mutfak::mutfakAdi = _mutfakAdi;
}

//Mutfaktaki Priz Say�s�n� ��renme
int mutfak::getPrizSayac() {
	return mPriz.size();
}

//Mutfaktaki Lamba Say�s�n� ��renme
int mutfak::getLampSayac() {
	return mLamp.size();
}

//Mutfaktaki Yang�n Durumunu ��renme
int mutfak::getYanginDurum() {
	return yang�nDurum;
}

//Mutfaktaki Yang�n Durumunu De�i�tirme
void mutfak::setYanginDurum(int _guvenlikDegisken) {
	yang�nDurum = _guvenlikDegisken;
}

//Mutfaktaki Su Bask�n� Durumunu ��renme
int mutfak::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Mutfaktaki Su Bask�n� Durumunu De�i�tirme
void mutfak::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Mutfaktaki H�rs�z Durumunu ��renme
int mutfak::getHirsizDurum() {
	return hirsizDurum;
}

//Mutfaktaki H�rs�z Durumunu De�i�tirme
void mutfak::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//S�cakl�k De�erini ��renme
float mutfak::getSicaklikDeger() {
	return sicaklik;
}

//S�cakl�k De�erini De�i�tirme
void mutfak::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem De�erini ��renme
float mutfak::getNemDeger() {
	return nem;
}

//Perde Durumunu ��renme
int mutfak::getPerdeDurum() {
	return perde;
}

//Perde Durumunu De�i�tirme
void mutfak::setPerdeDurum(int _perde) {
	perde = _perde;
}

//Nem De�erini De�i�tirme
void mutfak::setNemDeger(float _nem) {
	nem = _nem;
}

//Kombi Durumun ��renme
int mutfak::getKombi() {
	return kombi;
}

//Kombi Durumunu ve De�erini De�i�tirme
void mutfak::setKombi(int _kombi) {
	kombi = _kombi;
}

//Saks� Sayac
int mutfak::getSaksiSayac() {
	return mMutfakSaksi.size();
}

//Saks� Ekleme
void mutfak::saksiEkle() {
	string saksiIsmi, devamlilikDurumu;
	cout << "--> Saks� Ekleme <--\n\n\n";
	do {
		cout << "L�tfen mutfakta bulunan " << mMutfakSaksi.size() + 1 << ". saks�n�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, saksiIsmi);
		mMutfakSaksi[saksiIsmi] = 0;
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
void mutfak::saksilarinListelenmesi() {
	cout << getMutfakAdi() << " isimli mutfakta " << mMutfakSaksi.size() << " adet saks� bulunuyor. Bunlar; \n";
	for (const auto& saksi : mMutfakSaksi) {
		if (saksi.second > 0) {
			cout << "Saks�n�n Ad�: " << saksi.first << " , Saks� topra��ndaki nem de�eri: " << saksi.second << endl;
		}
		else if (saksi.second == 0) {
			cout << "Saks�n�n Ad�: " << saksi.first << " , Saks� topra�� kurumu�." << endl;
		}

	}
}

//Saks� ��karma
void mutfak::saksiCikarma() {
	string saksiSilinecek;
	saksilarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiSilinecek);
	if (mMutfakSaksi.size() != 0) {
		if (mMutfakSaksi.find(saksiSilinecek) != mMutfakSaksi.end()) {
			mMutfakSaksi.erase(saksiSilinecek);
			cout << saksiSilinecek << " isimli saks� mutfaktan ��kar�lm��t�r...\n\n";
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
void mutfak::saksiDurumuSorgulama() {
	string saksiAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mMutfakSaksi.find(saksiAdi) != mMutfakSaksi.end()) {
		if (mMutfakSaksi[saksiAdi] > 0) {
			cout << "Saks�n�n Ad�: " << saksiAdi << " , Saks� topra��ndaki nem de�eri: " << mMutfakSaksi[saksiAdi] << endl;
		}
		else if (mMutfakSaksi[saksiAdi] == 0) {
			cout << "Saks�n�n Ad�: " << saksiAdi << " , Saks� topra�� kurumu�." << endl;
		}
	}
	else {
		cout << endl << getMutfakAdi() << " isimli mutfa��n�zda b�yle bir saks� bulunmuyor!\n";
	}
}

//Girilen Saks� Durumunu De�i�tirme
void mutfak::saksiDurumunuDegistirme() {
	string saksiAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mMutfakSaksi.find(saksiAdi) != mMutfakSaksi.end()) {
	hataliTuslama:
		cout << "Saks�y� sulamak ve nem de�erini ayarlamak i�in '100 - 0' aras�nda bir de�er giriniz (100 = MAX, 0 = M�N): ";
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
		cout << endl << getMutfakAdi() << " isimli mutfa��n�zda b�yle bir saks� bulunmuyor!\n";
	}
}

//Priz ekleme
void mutfak::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "L�tfen mutfakta bulunan " << mPriz.size() + 1 << ". prizin ad�n� giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mPriz[prizIsmi] = 0;
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
void mutfak::prizlerinListelenmesi() {
	cout << mutfak::mutfakAdi << " isimli mutfakta " << mPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}
	}
}

//Priz ��kartma
void mutfak::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mPriz.size() != 0) {
		if (mPriz.find(prizSilinecek) != mPriz.end()) {
			mPriz.erase(prizSilinecek);
			cout << prizSilinecek << "�simli priz mutfaktan ��kar�lm��t�r...\n\n";
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
void mutfak::prizDurumuSorgulama() {
	string prizAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mPriz.find(prizAdi) != mPriz.end()) {
		if (mPriz[prizAdi] == 1) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz a��k konumda." << endl;
		}
		else if (mPriz[prizAdi] == 0) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << mutfak::mutfakAdi << " isimli mutfa��n�zda b�yle bir priz bulunmuyor!\n";
	}
}

//Girilen priz ad�n�n durumunun de�i�tirilmesi
void mutfak::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mPriz.find(prizAdi) != mPriz.end()) {
	hataliTuslama:
		cout << "Prizi a�mak i�in '1',Kapatmak i�in '0' � tu�lay�n�z: ";
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
		cout << endl << mutfak::mutfakAdi << " isimli mutfa��n�zda b�yle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void mutfak::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "L�tfen mutfakta bulunan " << mLamp.size() + 1 << ". lamban�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mLamp[lambaIsmi] = 0;
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
void mutfak::lambalarinListelenmesi() {
	cout << mutfak::mutfakAdi << " isimli mutfakta " << mLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}

	}
}

//Lamba ��karma
void mutfak::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mLamp.size() != 0) {
		if (mLamp.find(lampSilinecek) != mLamp.end()) {
			mLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba mutfaktan ��kar�lm��t�r...\n\n";
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
void mutfak::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mLamp.find(lampAdi) != mLamp.end()) {
		if (mLamp[lampAdi] > 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba a��k konumda ve de�eri: " << mLamp[lampAdi] << endl;
		}
		else if (mLamp[lampAdi] == 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << mutfak::mutfakAdi << " isimli mutfa��n�zda b�yle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba ad�n�n durumunun de�i�tirilmesi
void mutfak::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mLamp.find(lampAdi) != mLamp.end()) {
	hataliTuslama:
		cout << "Lambay� a�mak i�in '1024 - 0' aras�nda bir de�er giriniz (1024 = MAX, 0 = M�N): ";
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
		cout << endl << mutfak::mutfakAdi << " isimli mutfa��n�zda b�yle bir lamba bulunmuyor!\n";
	}
}

//Prizleri ve Lambalar� listeme
void mutfak::prizlerinVeLambalarinListelenmesi() {
	cout << mutfak::mutfakAdi << " isimli mutfakta " << mPriz.size() << " adet priz ve ";
	cout << mLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}
	}
}

//Yang�n Durumu
void mutfak::yanginVar() {
	cout << getMutfakAdi() << " isimli mutfakta Yang�n Var!" << endl << endl;
}

//Yang�n Yok Durumu
void mutfak::yanginYok() {

}

//Su Bask�n� Durumu
void mutfak::suBaskiniVar() {
	cout << getMutfakAdi() << " isimli mutfa�� Su Bast�!" << endl << endl;
}

//Su Bask�n� Yok Durumu
void mutfak::suBaskiniYok() {

}

//H�rs�z Girmesi Durumu
void mutfak::hirsizGirdi() {
	cout << getMutfakAdi() << " isimli mutfaktan H�rs�z Girdi!" << endl << endl;
}

//H�rs�z Yok Durumu
void mutfak::hirsizYok() {

}

//Sicakl�k ve Nem Kontrol�
void mutfak::sicaklikVeNemDurum() {
	cout << getMutfakAdi() << " isimli mutfa��n s�cakl���: " << sicaklik << " �C, nem de�eri: " << nem << " RH'dir." << endl << endl;
}

