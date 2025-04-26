#include "Salon.h"

map <string, int> mSalonPriz;
map <string, float> mSalonLamp;
map<string, float>mSalonSaksi;

//CONSTRACTOR
salon::salon(string _salonAdi) : home(_salonAdi) {
	salon::salonAdi = _salonAdi;
	yang�nDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
	sicaklik = 25;
	nem = 25;
	perde = 0;
	klima = 0;
}

//DESTRUCTOR
salon::~salon() {
	cout << getSalonAdi() << "'in Destructor'� �a��r�ld�." << endl;
}

//Salon Ad� ��renme
string salon::getSalonAdi() {
	return salon::salonAdi;
}

//Salon Ad�n� De�i�tirme
void salon::setSalonAdi(string _salonAdi) {
	salon::salonAdi = _salonAdi;
}

//Salondaki Priz Say�s�n� ��renme
int salon::getSalonPrizSayac() {
	return mSalonPriz.size();
}

//Salondaki Lamba Say�s�n� ��renme
int salon::getSalonLampSayac() {
	return mSalonLamp.size();
}

//Salondaki Yang�n Durumunu ��renme
int salon::getYanginDurum() {
	return yang�nDurum;
}

//Salondaki Yang�n Durumunu De�i�tirme
void salon::setYanginDurum(int _guvenlikDegisken) {
	yang�nDurum = _guvenlikDegisken;
}

//Salondaki Su Bask�n� Durumunu ��renme
int salon::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Salondaki Su Bask�n� Durumunu De�i�tirme
void salon::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Salondaki H�rs�z Durumunu ��renme
int salon::getHirsizDurum() {
	return hirsizDurum;
}

//Salondaki H�rs�z Durumunu De�i�tirme
void salon::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//S�cakl�k De�erini ��renme
float salon::getSicaklikDeger() {
	return sicaklik;
}

//S�cakl�k De�erini De�i�tirme
void salon::setSicaklikDeger(float _sicaklik) {
	sicaklik = _sicaklik;
}

//Nem De�erini ��renme
float salon::getNemDeger() {
	return nem;
}

//Nem De�erini De�i�tirme
void salon::setNemDeger(float _nem) {
	nem = _nem;
}

//Perde Durumunu ��renme
int salon::getPerdeDurum() {
	return perde;
}

//Perde Durumunu De�i�tirme
void salon::setPerdeDurum(int _perde) {
	perde = _perde;
}

//Klima Durumunu ��renme
int salon::getKlimaDurum() {
	return klima;
}

//Klima Durumunu De�i�tirme
void salon::setKlimaDurum(int _klima) {
	klima = _klima;
}

//Saks� Sayac
int salon::getSaksiSayac() {
	return mSalonSaksi.size();
}

//Saks� Ekleme
void salon::saksiEkle() {
	string saksiIsmi, devamlilikDurumu;
	cout << "--> Saks� Ekleme <--\n\n\n";
	do {
		cout << "L�tfen salonda bulunan " << mSalonSaksi.size() + 1 << ". saks�n�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, saksiIsmi);
		mSalonSaksi[saksiIsmi] = 0;
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
void salon::saksilarinListelenmesi() {
	cout << getSalonAdi() << " isimli salonda " << mSalonSaksi.size() << " adet saks� bulunuyor. Bunlar; \n";
	for (const auto& saksi : mSalonSaksi) {
		if (saksi.second > 0) {
			cout << "Saks�n�n Ad�: " << saksi.first << " , Saks� topra��ndaki nem de�eri: " << saksi.second << endl;
		}
		else if (saksi.second == 0) {
			cout << "Saks�n�n Ad�: " << saksi.first << " , Saks� topra�� kurumu�." << endl;
		}

	}
}

//Saks� ��karma
void salon::saksiCikarma() {
	string saksiSilinecek;
	saksilarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiSilinecek);
	if (mSalonSaksi.size() != 0) {
		if (mSalonSaksi.find(saksiSilinecek) != mSalonSaksi.end()) {
			mSalonSaksi.erase(saksiSilinecek);
			cout << saksiSilinecek << " isimli saks� salondan ��kar�lm��t�r...\n\n";
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
void salon::saksiDurumuSorgulama() {
	string saksiAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mSalonSaksi.find(saksiAdi) != mSalonSaksi.end()) {
		if (mSalonSaksi[saksiAdi] > 0) {
			cout << "Saks�n�n Ad�: " << saksiAdi << " , Saks� topra��ndaki nem de�eri: " << mSalonSaksi[saksiAdi] << endl;
		}
		else if (mSalonSaksi[saksiAdi] == 0) {
			cout << "Saks�n�n Ad�: " << saksiAdi << " , Saks� topra�� kurumu�." << endl;
		}
	}
	else {
		cout << endl << getSalonAdi() << " isimli salonunuzada b�yle bir saks� bulunmuyor!\n";
	}
}

//Girilen Saks� Durumunu De�i�tirme
void salon::saksiDurumunuDegistirme() {
	string saksiAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz saks�n�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, saksiAdi);
	if (mSalonSaksi.find(saksiAdi) != mSalonSaksi.end()) {
	hataliTuslama:
		cout << "Saks�y� sulamak ve nem de�erini ayarlamak i�in '100 - 0' aras�nda bir de�er giriniz (100 = MAX, 0 = M�N): ";
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
		cout << endl << getSalonAdi() << " isimli salonunuzda b�yle bir saks� bulunmuyor!\n";
	}
}

//Priz ekleme
void salon::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "L�tfen Salonda bulunan " << mSalonPriz.size() + 1 << ". prizin ad�n� giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mSalonPriz[prizIsmi] = 0;
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
void salon::prizlerinListelenmesi() {
	cout << salon::salonAdi << " isimli salonda " << mSalonPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mSalonPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
}

//Priz ��kartma
void salon::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mSalonPriz.size() != 0) {
		if (mSalonPriz.find(prizSilinecek) != mSalonPriz.end()) {
			mSalonPriz.erase(prizSilinecek);
			cout << prizSilinecek << "�simli priz salondan ��kar�lm��t�r...\n\n";
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
void salon::prizDurumuSorgulama() {
	string prizAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mSalonPriz.find(prizAdi) != mSalonPriz.end()) {
		if (mSalonPriz[prizAdi] == 1) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz a��k konumda." << endl;
		}
		else if (mSalonPriz[prizAdi] == 0) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << salon::salonAdi<< " isimli salonunuzda b�yle bir priz bulunmuyor!\n";
	}
}

//Girilen priz ad�n�n durumunun de�i�tirilmesi
void salon::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mSalonPriz.find(prizAdi) != mSalonPriz.end()) {
	hataliTuslama:
		cout << "Prizi a�mak i�in '1',Kapatmak i�in '0' � tu�lay�n�z: ";
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
		cout << endl << salon::salonAdi<< " isimli salonunuzda b�yle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void salon::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "L�tfen Salonda bulunan " << mSalonLamp.size() + 1 << ". lamban�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mSalonLamp[lambaIsmi] = 0;
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
void salon::lambalarinListelenmesi() {
	cout << salon::salonAdi<< " isimli salonda " << mSalonLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mSalonLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}

	}
}

//Lamba ��karma
void salon::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mSalonLamp.size() != 0) {
		if (mSalonLamp.find(lampSilinecek) != mSalonLamp.end()) {
			mSalonLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba salondan ��kar�lm��t�r...\n\n";
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
void salon::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mSalonLamp.find(lampAdi) != mSalonLamp.end()) {
		if (mSalonLamp[lampAdi] > 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba a��k konumda ve de�eri: " << mSalonLamp[lampAdi] << endl;
		}
		else if (mSalonLamp[lampAdi] == 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << salon::salonAdi << " isimli salonunuzda b�yle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba ad�n�n durumunun de�i�tirilmesi
void salon::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mSalonLamp.find(lampAdi) != mSalonLamp.end()) {
	hataliTuslama:
		cout << "Lambay� a�mak i�in '1024 - 0' aras�nda bir de�er giriniz (1024 = MAX, 0 = M�N): ";
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
		cout << endl << salon::salonAdi<< " isimli salonunuzda b�yle bir lamba bulunmuyor!\n";
	}
}

//Prizleri ve Lambalar� listeme
void salon::prizlerinVeLambalarinListelenmesi() {
	cout << salon::salonAdi<< " isimli salonda " << mSalonPriz.size() << " adet priz ve ";
	cout << mSalonLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mSalonPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mSalonLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}
	}
}

//Yang�n Durumu
void salon::yanginVar() {
	cout <<getSalonAdi() << " isimli salonda Yang�n Var!" << endl << endl;
}

//Yang�n Yok Durumu
void salon::yanginYok() {

}

//Su Bask�n� Durumu
void salon::suBaskiniVar() {
	cout << getSalonAdi() << " isimli salonu Su Bast�!" << endl << endl;
}

//Su Bask�n� Yok Durumu
void salon::suBaskiniYok() {

}

//H�rs�z Girmesi Durumu
void salon::hirsizGirdi() {
	cout << getSalonAdi() << " isimli salondan H�rs�z Girdi!" << endl << endl;
}

//H�rs�z Yok Durumu
void salon::hirsizYok() {

}

//Sicakl�k ve Nem Kontrol�
void salon::sicaklikVeNemDurum() {
	cout << getSalonAdi() << " isimli salonun s�cakl���: " << sicaklik << " �C, nem de�eri: " << nem << " RH'dir." << endl << endl;
}