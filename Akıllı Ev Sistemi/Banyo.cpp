#include "Banyo.h"

map <string, int> mBanyoPriz;
map <string, float> mBanyoLamp;

//CONSTRACTOR
banyo::banyo(string _banyoAdi) : home(_banyoAdi) {
	banyo::banyoAdi = _banyoAdi;
	yang�nDurum = 0;
	suBaskiniDurum = 0;
	hirsizDurum = 0;
}

//DESTRUCTOR
banyo::~banyo() {
	cout << getBanyoAdi() << "'in Destructor'� �a��r�ld�." << endl;
}

//Banyo Ad� ��renme
string banyo::getBanyoAdi() {
	return banyo::banyoAdi;
}

//Banyo Ad�n� De�i�tirme
void banyo::setBanyoAdi(string _banyoAdi) {
	banyo::banyoAdi = _banyoAdi;
}

//Baynodaki Priz Say�s�n� ��renme
int banyo::getBanyoPrizSayac() {
	return mBanyoPriz.size();
}

//Baynodaki Lamba Say�s�n� ��renme
int banyo::getBanyoLampSayac() {
	return mBanyoLamp.size();
}

// Baynodaki Yang�n Durumunu ��renme
int banyo::getYanginDurum() {
	return yang�nDurum;
}

//Baynodaki Yang�n Durumunu De�i�tirme
void banyo::setYanginDurum(int _guvenlikDegisken) {
	yang�nDurum = _guvenlikDegisken;
}

//Baynodaki Su Bask�n� Durumunu ��renme
int banyo::getSuBaskiniDurum() {
	return suBaskiniDurum;
}

//Baynodaki Su Bask�n� Durumunu De�i�tirme
void banyo::setSuBaskiniDurum(int _guvenlikDegisken) {
	suBaskiniDurum = _guvenlikDegisken;
}

//Baynodaki H�rs�z Durumunu ��renme
int banyo::getHirsizDurum() {
	return hirsizDurum;
}

//Baynodaki H�rs�z Durumunu De�i�tirme
void banyo::setHirsizDurum(int _guvenlikDegisken) {
	hirsizDurum = _guvenlikDegisken;
}

//Priz ekleme
void banyo::prizEkleme() {
	string prizIsmi, devamlilikDurumu;
	cout << "-->Priz Ekleme<--\n\n\n";
	do {
		cout << "L�tfen Banyoda bulunan " << mBanyoPriz.size() + 1 << ". prizin ad�n� giriniz: ";
		cin.ignore();
		getline(cin, prizIsmi);
		mBanyoPriz[prizIsmi] = 0;
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
void banyo::prizlerinListelenmesi() {
	cout << banyo::banyoAdi << " isimli banyoda " << mBanyoPriz.size() << " adet priz bulunuyor. Bunlar; \n";
	for (const auto& priz : mBanyoPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
}

//Priz ��kartma
void banyo::prizCikartma() {
	string prizSilinecek;
	prizlerinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizSilinecek);
	if (mBanyoPriz.size() != 0) {
		if (mBanyoPriz.find(prizSilinecek) != mBanyoPriz.end()) {
			mBanyoPriz.erase(prizSilinecek);
			cout << prizSilinecek << "�simli priz banyodan ��kar�lm��t�r...\n\n";
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
void banyo::prizDurumuSorgulama() {
	string prizAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mBanyoPriz.find(prizAdi) != mBanyoPriz.end()) {
		if (mBanyoPriz[prizAdi] == 1) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz a��k konumda." << endl;
		}
		else if (mBanyoPriz[prizAdi] == 0) {
			cout << "Prizin Ad�: " << prizAdi << " , Priz kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << banyo::banyoAdi << " isimli banyonuzda b�yle bir priz bulunmuyor!\n";
	}
}

//Girilen priz ad�n�n durumunun de�i�tirilmesi
void banyo::prizDurumunuDegistirme() {
	string prizAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, prizAdi);
	if (mBanyoPriz.find(prizAdi) != mBanyoPriz.end()) {
	hataliTuslama:
		cout << "Prizi a�mak i�in '1',Kapatmak i�in '0' � tu�lay�n�z: ";
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
		cout << endl << banyo::banyoAdi<< " isimli banyonuzda b�yle bir priz bulunmuyor!\n";
	}
}

//Lamba ekleme
void banyo::lambaEkleme() {
	string lambaIsmi, devamlilikDurumu;
	cout << "--> Lamba Ekleme <--\n\n\n";
	do {
		cout << "L�tfen Banyoda bulunan " << mBanyoLamp.size() + 1 << ". lamban�n ad�n� giriniz: ";
		cin.ignore();
		getline(cin, lambaIsmi);
		mBanyoLamp[lambaIsmi] = 0;
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
void banyo::lambalarinListelenmesi() {
	cout << banyo::banyoAdi << " isimli banyoda " << mBanyoLamp.size() << " adet lamba bulunuyor. Bunlar; \n";
	for (const auto& lamp : mBanyoLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}

	}
}

//Lamba ��karma
void banyo::lambaCikarma() {
	string lampSilinecek;
	lambalarinListelenmesi();
	cout << "L�tfen ��kartmak istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampSilinecek);
	if (mBanyoLamp.size() != 0) {
		if (mBanyoLamp.find(lampSilinecek) != mBanyoLamp.end()) {
			mBanyoLamp.erase(lampSilinecek);
			cout << lampSilinecek << " isimli lamba banyodan ��kar�lm��t�r...\n\n";
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
void banyo::lambaDurumuSorgulama() {
	string lampAdi;
	cout << "L�tfen durumunu ��renmek istedi�iniz prizin ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mBanyoLamp.find(lampAdi) != mBanyoLamp.end()) {
		if (mBanyoLamp[lampAdi] > 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba a��k konumda ve de�eri: " << mBanyoLamp[lampAdi] << endl;
		}
		else if (mBanyoLamp[lampAdi] == 0) {
			cout << "Lamban�n Ad�: " << lampAdi << " , Lamba kapal� konumda." << endl;
		}
	}
	else {
		cout << endl << banyo::banyoAdi << " isimli banyonuzda b�yle bir lamba bulunmuyor!\n";
	}
}

//Girilen lamba ad�n�n durumunun de�i�tirilmesi
void banyo::lambaDurumunuDegistirme() {
	string lampAdi;
	int onOff;
	cout << "L�tfen durumunu de�i�tirmek istedi�iniz lamban�n ad�n� giriniz: ";
	cin.ignore();
	getline(cin, lampAdi);
	if (mBanyoLamp.find(lampAdi) != mBanyoLamp.end()) {
	hataliTuslama:
		cout << "Lambay� a�mak i�in '1024 - 0' aras�nda bir de�er giriniz (1024 = MAX, 0 = M�N): ";
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
		cout << endl << banyo::banyoAdi << " isimli banyonuzda b�yle bir priz bulunmuyor!\n";
	}
}

//Prizleri ve Lambalar� listeme
void banyo::prizlerinVeLambalarinListelenmesi() {
	cout << banyo::banyoAdi << " isimli banyoda " << mBanyoPriz.size() << " adet priz ve ";
	cout << mBanyoLamp.size() << " adet lamba bulunuyor.Bunlar; \n";
	cout << "Prizler;\n";
	for (const auto& priz : mBanyoPriz) {
		if (priz.second == 1) {
			cout << "Prizin Ad�: " << priz.first << " , Priz a��k konumda." << endl;
		}
		else if (priz.second == 0) {
			cout << "Prizin Ad�: " << priz.first << " , Priz kapal� konumda." << endl;
		}

	}
	cout << "Lambalar;\n";
	for (const auto& lamp : mBanyoLamp) {
		if (lamp.second > 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba a��k konumda ve de�eri: " << lamp.second << endl;
		}
		else if (lamp.second == 0) {
			cout << "Lamban�n Ad�: " << lamp.first << " , Lamba kapal� konumda." << endl;
		}
	}
}

//Yang�n Durumu
void banyo::yanginVar() {
	cout << getBanyoAdi() << " isimli banyoda Yang�n Var!" << endl << endl;
}

//Yang�n Yok Durumu
void banyo::yanginYok() {

}

//Su Bask�n� Durumu
void banyo::suBaskiniVar() {
	cout << getBanyoAdi() << " isimli banyoyu Su Bast�!" << endl << endl;
}

//Su Bask�n� Yok Durumu
void banyo::suBaskiniYok() {

}

//H�rs�z Girmesi Durumu
void banyo::hirsizGirdi() {
	cout << getBanyoAdi() << " isimli banyodan H�rs�z Girdi!" << endl << endl;
}

//H�rs�z Yok Durumu
void banyo::hirsizYok() {

}