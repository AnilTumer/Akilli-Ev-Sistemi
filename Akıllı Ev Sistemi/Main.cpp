#include <iostream>
#include <map>
#include <string>
#include "Login.h"
#include "Home.h"
#include "Mutfak.h"
#include "Salon.h"
#include "Odalar.h"
#include "Banyo.h"
#include "Tuvalet.h"
#include "Koridor.h"
using namespace std;

static int odaSayac = 1;

void girisBilgisiDegistirme(login& giris, string& ad, string& soyad, string& kullaniciAdi, string& parola) {
	int bilgiDegisimKontrol = giris.girisBilgileriDegistir();
	if (bilgiDegisimKontrol == 1) {
		string newID, newPassword;
		cout << "Kullan�c� adi �ifre de�i�trime b�l�m�.. " << endl << endl;
		cout << "L�tfen yeni kullan�c� ad�n�z� giriniz: ";
		cin >> newID;
		cout << "L�tfen yeni �ifrenizi giriniz: ";
		cin >> newPassword;

		giris.setIdKontrol(newID);
		giris.setPassworKontrol(newPassword);

		cout << "Yeni kullan�c� ad�: " << giris.getIdKontrol() << endl;
		cout << "Yeni �ifre: " << giris.getPasswordKontrol() << endl;
		cout << endl << endl << "Merhaba " << ad << " " << soyad << ". L�tfen yeniden giri� yap�n�z." << endl;
		cout << "L�tfen kullan�c� ad�n�z� giriniz: ";
		cin >> kullaniciAdi;
		cout << "L�tfen kullan�c� �ifrenizi giriniz: ";
		cin >> parola;
		giris.setId(kullaniciAdi);
		giris.setPassword(parola);
		giris.girisYap();
	}
}

void kullaniciAdSoyadDegistirme(login& giris, string& ad, string& soyad) {
	cout << "Kullan�c� ad ve soyad de�i�trime b�l�m�.. " << endl << endl;
	cout << "Merhaba " << giris.getAd() << " " << giris.getSoyad() << "." << endl;
	cout << "L�tfen ad�n�z� giriniz: ";
	cin.ignore();
	getline(cin, ad);
	giris.setAd(ad);
	cout << "\nL�tfen soyad�n�z� giriniz: ";
	cin >> soyad;
	giris.setSoyad(soyad);
}

void tumEvinGuvenlikDurumlari
(home& evim, mutfak& myMutfak, salon& mySalon, banyo& myBanyo, tuvalet& myTuvalet, koridor& myKoridor, map<int, odalar>& mOda) {
	int odalardaGuvenlikSorunu = 0;
	for (const auto& odalarim : mOda) {

		auto it = mOda.find(odalarim.first);
		odalar& myOda = it->second;
		//cout << myOda.getOdaAdi() << endl;
		if (myOda.getYanginDurum() > 0) {
			odalardaGuvenlikSorunu = 1;
			myOda.yanginVar();
		}
		if (myOda.getSuBaskiniDurum() > 0) {
			odalardaGuvenlikSorunu = 1;
			myOda.suBaskiniVar();
		}
		if (myOda.getHirsizDurum() > 0) {
			odalardaGuvenlikSorunu = 1;
			myOda.hirsizGirdi();
		}
	}


	if (myMutfak.getYanginDurum() == 0 && myMutfak.getSuBaskiniDurum() == 0 && myMutfak.getHirsizDurum() == 0 && myMutfak.getDepremDurum()==0
		&& mySalon.getYanginDurum() == 0 && mySalon.getSuBaskiniDurum() == 0 && mySalon.getHirsizDurum() == 0 && mySalon.getDepremDurum() == 0
		&& myBanyo.getYanginDurum() == 0 && myBanyo.getSuBaskiniDurum() == 0 && myBanyo.getHirsizDurum() == 0 && myBanyo.getDepremDurum() == 0
		&& myTuvalet.getYanginDurum() == 0 && myTuvalet.getSuBaskiniDurum() == 0 && myTuvalet.getHirsizDurum() == 0 && myTuvalet.getDepremDurum() == 0
		&& myKoridor.getYanginDurum() == 0 && myKoridor.getSuBaskiniDurum() == 0 && myKoridor.getHirsizDurum() == 0 && myKoridor.getDepremDurum() == 0
		&& evim.getDepremDurum() ==0 && odalardaGuvenlikSorunu == 0) {

		cout << "Evinizde Herhangi Bir Sorun Yoktur...." << endl << endl;
	}if (evim.getDepremDurum() > 0) {
		evim.depremOluyor();
	}
	if (myMutfak.getYanginDurum() > 0) {
		myMutfak.yanginVar();
	}
	if (myMutfak.getSuBaskiniDurum() > 0) {
		myMutfak.suBaskiniVar();
	}
	if (myMutfak.getHirsizDurum() > 0) {
		myMutfak.hirsizGirdi();
	}
	if (mySalon.getYanginDurum() > 0) {
		mySalon.yanginVar();
	}
	if (mySalon.getSuBaskiniDurum() > 0) {
		mySalon.suBaskiniVar();
	}
	if (mySalon.getHirsizDurum() > 0) {
		mySalon.hirsizGirdi();
	}
	if (myBanyo.getYanginDurum() > 0) {
		myBanyo.yanginVar();
	}
	if (myBanyo.getSuBaskiniDurum() > 0) {
		myBanyo.suBaskiniVar();
	}
	if (myBanyo.getHirsizDurum() > 0) {
		myBanyo.hirsizGirdi();
	}
	if (myTuvalet.getYanginDurum() > 0) {
		myTuvalet.yanginVar();
	}
	if (myTuvalet.getSuBaskiniDurum() > 0) {
		myTuvalet.suBaskiniVar();
	}
	if (myTuvalet.getHirsizDurum() > 0) {
		myTuvalet.hirsizGirdi();
	}
	if (myKoridor.getYanginDurum() > 0) {
		myKoridor.yanginVar();
	}
	if (myKoridor.getSuBaskiniDurum() > 0) {
		myKoridor.suBaskiniVar();
	}
	if (myKoridor.getHirsizDurum() > 0) {
		myKoridor.hirsizGirdi();
	}
	/*
	if (myMutfak.getDepremDurum() > 0 || mySalon.getDepremDurum() > 0
		|| myBanyo.getDepremDurum() > 0 || myTuvalet.getDepremDurum() > 0 || myKoridor.getDepremDurum() > 0) {
		myMutfak.depremOluyor();
	}
	*/
}

int evcilHayvanMenusu(int& secenek, home& evim) {
	string evcilHayvanEklemek;
basaDon:
	if (evim.getEvcilHayvanSayac() == 0) {
		//Priz olu�turulmas�
		cout << "En az bir adet evcil hayvan olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Evcil Hayvan olu�turmak istiyor musunuz?(y/n): ";
		cin >> evcilHayvanEklemek;
		if (evcilHayvanEklemek == "y" || evcilHayvanEklemek == "Y") {
			cout << "Sizi evcil hayvan ekleme men�s�ne aktar�yorum...... " << endl << endl;
			evim.evcilHayvanEkleme();
		}
		else if (evcilHayvanEklemek == "n" || evcilHayvanEklemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return secenek;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|        |-------------------------|       |" << endl;
	cout << "|        |* EVC�L HAYVANIM MEN�S� *|       |" << endl;
	cout << "|        |-------------------------|       |" << endl;
	cout << "| 1 = Evcil Hayvan Ekle                    |" << endl;
	cout << "| 2 = Evcil Hayvan ��kar                   |" << endl;
	cout << "| 3 = Bir Evcil Hayvan�n Durumunu ��ren    |" << endl;
	cout << "| 4 = Bir Evcil Hayvan�n Durumunu De�i�tir |" << endl;
	cout << "| 5 = T�m Evcil Hayvanlar�o Listele        |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Evcil Hayvan Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Evcil Hayvan ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Evcil Hayvan�n Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Evcil Hayvan�n Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Evcil Hayvanlar� Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;
}

int saksiMenusu(int& secenek, home* pGuvenlik) {
	string saksiEklemek;
basaDon:
	if (pGuvenlik->getSaksiSayac() == 0) {
		//Mutfak olu�turulmas�
		cout << "En az bir adet saks� olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Saks� olu�turmak istiyor musunuz?(y/n): ";
		cin >> saksiEklemek;
		if (saksiEklemek == "y" || saksiEklemek == "Y") {
			cout << "Sizi saks� ekleme men�s�ne aktar�yorum...... " << endl << endl;
			pGuvenlik->saksiEkle();
		}
		else if (saksiEklemek == "n" || saksiEklemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|          |---------------------|         |" << endl;
	cout << "|          |* SAKSILARIM MEN�S� *|         |" << endl;
	cout << "|          |---------------------|         |" << endl;
	cout << "| 1 = Saks� Ekle                           |" << endl;
	cout << "| 2 = Saks� ��kar                          |" << endl;
	cout << "| 3 = Bir Saks�n�n Durumunu ��ren          |" << endl;
	cout << "| 4 = Bir Saks�n�n Durumunu De�i�tir       |" << endl;
	cout << "| 5 = T�m Saks�lar� Listele                |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksiEkle();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksiCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksiDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksiDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Lambalar� Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksilarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

void perdeDurumuMenusu(home* pGuvenlik) {
	string degisimKontrol;
	bool degisim = 0;
	int perdeDeger = 0;

	cout << "Perdenizin �uan ki Durumu: " << endl;
	if (pGuvenlik->getPerdeDurum() == 0) {
		cout << "Perde kapal�!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() > 0 && pGuvenlik->getPerdeDurum() <= 250) {
		cout << "Perdenin neredeyse tamam� kapal�!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() > 250 && pGuvenlik->getPerdeDurum() <= 500) {
		cout << "Perde yar�ya yak�n kapal�!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() > 500 && pGuvenlik->getPerdeDurum() <= 750) {
		cout << "Perdenin yar�dan fazlas� a��k!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() > 750 && pGuvenlik->getPerdeDurum() <= 999) {
		cout << "Perdenin neredeyse tamam� a��k!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() == 1000) {
		cout << "Perde a��k!" << endl << endl;
	}

	while (degisim != 1)
	{
		cout << "Perdenizin durumunu de�i�tirmek istiyor musunuz?(y/n): ";
		cin >> degisimKontrol;
		if (degisimKontrol == "y" || degisimKontrol == "Y")
		{
		c:
			cout << "Perdenizin yeni de�erini giriniz(0 - 1000): " << endl;
			cout << "* 1000 = Max A��k\n* 500 = Yar� A��k\n* 0 =Kapal�" << endl;
			cin >> perdeDeger;
			try {
				if (cin.fail())
					throw 101;
			}
			catch (int hatakodu) {
				if (hatakodu == 101) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
					goto c;
				}
			}

			if (perdeDeger > 1000 || perdeDeger < 0) {
				cout << "HATALI DE�ER G�RD�N�Z! " << perdeDeger << " Verilen aral�kta de�ildir!!\n";
				goto c;
			}
			else {
				pGuvenlik->setPerdeDurum(perdeDeger);
				cout << "Perdenizin yeni de�eri: " << endl;
				if (pGuvenlik->getPerdeDurum() == 0) {
					cout << "Perde kapal�!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() > 0 && pGuvenlik->getPerdeDurum() <= 250) {
					cout << "Perdenin neredeyse tamam� kapal�!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() > 250 && pGuvenlik->getPerdeDurum() <= 500) {
					cout << "Perde yar�ya yak�n kapal�!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() > 500 && pGuvenlik->getPerdeDurum() <= 750) {
					cout << "Perdenin yar�dan fazlas� a��k!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() > 750 && pGuvenlik->getPerdeDurum() <= 999) {
					cout << "Perdenin neredeyse tamam� a��k!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() == 1000) {
					cout << "Perde a��k!" << endl << endl;
				}
			}
			
			degisim = 1;

		}
		else if (degisimKontrol == "n" || degisimKontrol == "N")
		{
			cout << "Perdenizin durumu ayn� �ekilde kalm��t�r..." << endl << endl;
			degisim = 1;
		}
		else
		{
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			degisim = 0;
		}
	}

}

void klimaDurumuMenusu(home* pGuvenlik) {
	string degisimKontrol;
	bool degisim = 0;
	int klimaDeger = 0;

	cout << "Kliman�z�n �uan ki Durumu: " << endl;
	if (pGuvenlik->getKlimaDurum() == 0) {
		cout << "Klima kapal�!" << endl << endl;
	}
	else if (pGuvenlik->getKlimaDurum() > 0) {
		cout << "Klima a��k ve de�eri: "<<pGuvenlik->getKlimaDurum() <<" derece."<< endl << endl;
	}

	while (degisim != 1)
	{
		cout << "Kliman�z�n durumunu de�i�tirmek istiyor musunuz?(y/n): ";
		cin >> degisimKontrol;
		if (degisimKontrol == "y" || degisimKontrol == "Y")
		{
		c:
			cout << "Kliman�z�n yeni de�erini giriniz(0 - 50): " << endl;
			cout << "* 50 = Max A��k\n* 0 = Kapal�" << endl;
			cin >> klimaDeger;
			try {
				if (cin.fail())
					throw 101;
			}
			catch (int hatakodu) {
				if (hatakodu == 101) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
					goto c;
				}
			}

			if (klimaDeger > 50 || klimaDeger < 0) {
				cout << "HATALI DE�ER G�RD�N�Z! " << klimaDeger << " Verilen aral�kta de�ildir!!\n";
				goto c;
			}
			else {
				pGuvenlik->setKlimaDurum(klimaDeger);
				cout << "Kliman�z�n �uan ki Durumu: " << endl;
				if (pGuvenlik->getKlimaDurum() == 0) {
					cout << "Klima kapal�!" << endl << endl;
				}
				else if (pGuvenlik->getKlimaDurum() > 0) {
					cout << "Klima a��k ve de�eri: " << pGuvenlik->getKlimaDurum() << " derece." << endl << endl;
				}
			}

			degisim = 1;

		}
		else if (degisimKontrol == "n" || degisimKontrol == "N")
		{
			cout << "Klimanizin durumu ayn� �ekilde kalm��t�r..." << endl << endl;
			degisim = 1;
		}
		else
		{
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			degisim = 0;
		}
	}
}

int sicaklikKontrolMenusu(int& secenek, home* pGuvenlik) {
	float sicaklik = 25;
	float nem = 25;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "|       |* SICAKL�K ve NEM MEN�S� *|       |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "| 1 = S�cakl�k ve Nem Durumunu             |" << endl;
	cout << "| 2 = S�cakl�k De�erini De�i�tir           |" << endl;
	cout << "| 3 = Nem De�erini De�i�tir                |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-3): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> S�cakl�k ve Nem Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->sicaklikVeNemDurum();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> S�cakl�k De�erini De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		cout << "L�tfen olmas�n� istedi�iniz s�cakl�k de�erini giriniz: ";
		cin >> sicaklik;
		pGuvenlik->setSicaklikDeger(sicaklik);
		cout << "Yeni s�cakl�k de�eriniz = " << pGuvenlik->getSicaklikDeger() << endl << endl;
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Nem De�erini De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		cout << "L�tfen olmas�n� istedi�iniz nem de�erini giriniz: ";
		cin >> nem;
		pGuvenlik->setNemDeger(nem);
		cout << "Yeni nem de�eriniz = " << pGuvenlik->getNemDeger() << endl << endl;
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-3 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;

}

void guvenlikDurumlari(int& secenek, home* pGuvenlik) {

	if (pGuvenlik->getYanginDurum() == 0 && pGuvenlik->getSuBaskiniDurum() == 0 
		&& pGuvenlik->getHirsizDurum() == 0 && pGuvenlik->getDepremDurum() == 0) {
		cout << "Evinizde Herhangi Bir Sorun Yoktur...." << endl << endl;
	}
	if (pGuvenlik->getYanginDurum() > 0) {
		pGuvenlik->yanginVar();
	}
	if (pGuvenlik->getSuBaskiniDurum() > 0) {
		pGuvenlik->suBaskiniVar();
	}
	if (pGuvenlik->getHirsizDurum() > 0) {
		pGuvenlik->hirsizGirdi();
	}
	if (pGuvenlik->getDepremDurum() > 0) {
		pGuvenlik->depremOluyor();
	}
}

int guvenlikDurumunuDegistirme(int& secenek, home* pGuvenlik) {
basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|  |------------------------------------|  |" << endl;
	cout << "|  |* G�VENL�K DURUM DE���T�RME MEN�S� *|  |" << endl;
	cout << "|  |------------------------------------|  |" << endl;
	cout << "| 1 = Yang�n Durumu De�i�tirme             |" << endl;
	cout << "| 2 = Su Bask�n� Durumunu De�i�tirme       |" << endl;
	cout << "| 3 = H�rs�z Durumunu De�i�tirme           |" << endl;
	cout << "| 4 = Deprem Durumunu De�i�tirme           |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-2): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Yang�n Durumu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		int yanginDurumunuDegistir;
		cout << "* 1 = Yang�n ��kar." << endl;
		cout << "* 2 = Yang�n� S�nd�r." << endl << endl;
		cout << "L�tfen Yukar�daki se�eneklerden birini se�inizi (1-2): ";
		cin >> yanginDurumunuDegistir;
		if (yanginDurumunuDegistir == 1) {
			cout <<"Yang�n ��kar�ld�..." << endl << endl;
			pGuvenlik->setYanginDurum(1);
		}
		else if (yanginDurumunuDegistir == 2) {
			cout << "Yang�n s�nd�r�ld�..." << endl << endl;
			pGuvenlik->setYanginDurum(0);
		}
		else {
			cout << "Hatali tu�lama yapt�n�z!!!" << endl << endl;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Su Bask�n� Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		int suBaskiniDurumunuDegistir;
		cout << "* 1 = Su Bask�n� ��kar." << endl;
		cout << "* 2 = Su Bask�n�n� Durdur." << endl << endl;
		cout << "L�tfen Yukar�daki se�eneklerden birini se�inizi (1-2): ";
		cin >> suBaskiniDurumunuDegistir;
		if (suBaskiniDurumunuDegistir == 1) {
			cout << "Su bask�n� ��kar�ld�..." << endl << endl;
			pGuvenlik->setSuBaskiniDurum(1);
		}else if (suBaskiniDurumunuDegistir == 2) {
			cout << "Su bask�n� durduruldu..." << endl << endl;
			pGuvenlik->setSuBaskiniDurum(0);
		}
		else {
			cout << "Hatali tu�lama yapt�n�z!!!" << endl << endl;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> H�rs�z Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		int hirsizDurumunuDegistir;
		cout << "* 1 = H�rs�z Sok." << endl;
		cout << "* 2 = H�rs�z� D��ar� ��kar." << endl << endl;
		cout << "L�tfen Yukar�daki se�eneklerden birini se�inizi (1-2): ";
		cin >> hirsizDurumunuDegistir;
		if (hirsizDurumunuDegistir == 1) {
			cout << "H�rs�z sokuldu..." << endl << endl;
			pGuvenlik->setHirsizDurum(1);
		}else if (hirsizDurumunuDegistir == 2) {
			cout << "H�rs�z d��ar� ��kar�ld�..." << endl << endl;
			pGuvenlik->setHirsizDurum(0);
		}
		else {
			cout << "Hatali tu�lama yapt�n�z!!!" << endl << endl;
		}
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Deprem Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		int depremDurumunuDegistir;
		cout << "* 1 = Deprem Yap." << endl;
		cout << "* 2 = Depremi Durdur." << endl << endl;
		cout << "L�tfen Yukar�daki se�eneklerden birini se�inizi (1-2): ";
		cin >> depremDurumunuDegistir;
		if (depremDurumunuDegistir == 1) {
			cout << "Deprem Yap�ld�..." << endl << endl;
			pGuvenlik->setDepremDurum(1);
		}
		else if (depremDurumunuDegistir == 2) {
			cout << "Deprem Durduruldu..." << endl << endl;
			pGuvenlik->setDepremDurum(0);
		}
		else {
			cout << "Hatali tu�lama yapt�n�z!!!" << endl << endl;
		}
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;


}

int guvenlikMenusu(int& secenek, home* pGuvenlik) {
basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|           |-------------------|          |" << endl;
	cout << "|           |* G�VENL�K MEN�S� *|          |" << endl;
	cout << "|           |-------------------|          |" << endl;
	cout << "| 1 = G�venlik Durumu ��renme              |" << endl;
	cout << "| 2 = G�venlik Durumunu De�i�tirme         |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-2): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> G�venlik Durumu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		guvenlikDurumlari(secenek, pGuvenlik);
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> G�venlik Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		guvenlikDurumunuDegistirme(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

void odaEkleme(map<int, odalar>& mOda) {
	string odaAdi;
	map <string, float> mOdaLamp;
	map <string, int> mOdaPriz;
	map<string, float>mOdaSaksi;
	cout << "Odan�za bir isim veriniz: ";
farkliIsim:
	cin.ignore();
	getline(cin, odaAdi);

	for (const auto& odalarim : mOda) {
		auto it = mOda.find(odalarim.first);
		odalar& myOda = it->second;
		if (myOda.getOdaAdi() == odaAdi) {
			cout << "Ayn� isimle olu�turulmu� bir odan�z mevcuttur! L�tfen ba�ka bir isim giriniz: ";
			goto farkliIsim;
		}
	}
	mOda[odaSayac] = odalar(odaAdi, mOdaPriz, mOdaLamp,mOdaSaksi);
	odaSayac++;
}

void odaListeleme(map<int, odalar>& mOda) {
	int odaSorgu;
	auto it = mOda.find(odaSorgu);

	if (mOda.empty()) {
		cout << "\nHi� odan�z yok!\n\n";
		return;
	}

	cout << "--------------------------------------------" << endl;
	cout << "|           Ak�ll� Ev Sistemleri           |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "|           |* ODALAR MEN�S� *|            |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "--------------------------------------------" << endl;

	for (const auto& odalarim : mOda) {

		cout << "--> " << odalarim.first << " = ";
		auto it = mOda.find(odalarim.first);
		odalar& myOda = it->second;
		cout << myOda.getOdaAdi() << endl;
	}
	cout << "--------------------------------------------" << endl << endl;
}

void evAdiDegistirme(home& evim) {
	string newHomeName;
	cout << "L�tfen evinizin yeni ad�n� giriniz: ";
	cin.ignore();
	getline(cin, newHomeName);
	evim.setHomeName(newHomeName);
	cout << "Evinizin ad� " << evim.getHomeName() << " olarak de�i�tirilmi�tir." << endl;
	cout << "/*/*/*/*/*/---> Ana Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
}

void mutfakAdiDegistirme(mutfak& myMutfak) {
		string newMutfakAdi;
		cout << "L�tfen mutfa��n�z�n yeni ad�n� giriniz: ";
		cin.ignore();
		getline(cin, newMutfakAdi);
		myMutfak.setMutfakAdi(newMutfakAdi);
		cout << "Mutfa��n�z�n ad� " << myMutfak.getMutfakAdi() << " olarak de�i�tirilmi�tir." << endl;
		cout << "/*/*/*/*/*/---> Mutfak Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;	
}

int mutfakPrizleriMenusu(int& secenek, mutfak& myMutfak) {
	string prizEkelemek;
basaDon:
	if (myMutfak.getPrizSayac() == 0) {
		//Priz olu�turulmas�
		cout << "En az bir adet priz olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz olu�turmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myMutfak.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "|       |* MUTFAK PR�ZLER� MEN�S� *|       |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz ��kar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu ��ren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu De�i�tir         |" << endl;
	cout << "| 5 = T�m Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Prizleri Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int mutfakLambalariMenusu(int& secenek, mutfak& myMutfak) {
	string lambaEklemek;
basaDon:
	if (myMutfak.getLampSayac() == 0) {
		//Mutfak olu�turulmas�
		cout << "En az bir adet lamba olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba olu�turmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myMutfak.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "|       |* MUTFAK LAMBALARI MEN�S� *|      |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba ��kar                          |" << endl;
	cout << "| 3 = Bir Lamban�n Durumunu ��ren          |" << endl;
	cout << "| 4 = Bir Lamban�n Durumunu De�i�tir       |" << endl;
	cout << "| 5 = T�m Lambalar� Listele                |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Lambalar� Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int mutfakMenusu(int& secenek,mutfak &myMutfak,home *pGuvenlik) {
	static int mutfakOlusturulmusMu = 0;
	if (mutfakOlusturulmusMu == 0) {
		string mutfakAdi;
		//Mutfak olu�turulmas�
		cout << "�ncelikle bir Mutfak olu�turman�z gerekiyor." << endl;
		cout << "L�tfen mutfa��n�za bir isim veriniz: ";
		cin.ignore();
		getline(cin, mutfakAdi);
		cout << endl;
		myMutfak.setMutfakAdi(mutfakAdi);
		mutfakOlusturulmusMu = 1;
	}

	pGuvenlik = &myMutfak;

	string degistirmeKontrol;
	bool degistirme = 0;
	int kombiDeger = 0;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "|           |* MUTFAK MEN�S� *|            |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Ayd�nlatmalar                        |" << endl;
	cout << "| 3 = T�m Bile�enler                       |" << endl;
	cout << "| 4 = Mutfak Ad�n� De�i�tirme              |" << endl;
	cout << "| 5 = Mutfa��n G�venlik Durumu             |" << endl;
	cout << "| 6 = Mutfa��n S�caklik ve Nem Durumu      |" << endl;
	cout << "| 7 = Kombi Durumu                         |" << endl;
	cout << "| 8 = Mutfaktaki Di�er Bile�enler          |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mutfakPrizleriMenusu(secenek, myMutfak);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Ayd�nlatmalar B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mutfakLambalariMenusu(secenek, myMutfak);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> T�m Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> T�m Bile�enler Listelendi. Mutfak Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Mutfak Ad� De�i�im B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mutfakAdiDegistirme(myMutfak);
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Mutfa��n G�venlik Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Mutfa��n S�caklik ve Nem Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		sicaklikKontrolMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Mutfa��n Kombi Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		cout << "Kombinizin durumu: ";
		if (myMutfak.getKombi() == 0) {
			cout << "Kapal�." << endl << endl;
		}
		else if (myMutfak.getKombi() > 0) {
			cout << "A��k ve " << myMutfak.getKombi() << " derece." << endl << endl;
		}
		while (degistirme != 1)
		{
			cout << "Kombinizin durumunu de�i�tirmek istiyor musunuz?(y/n): ";
			cin >> degistirmeKontrol;
			if (degistirmeKontrol == "y" || degistirmeKontrol == "Y")
			{
				c:
				cout << "Kombinizin yeni de�erini giriniz(KAPATMAK ���N = 0): ";
				cin >> kombiDeger;
				try {
					if (cin.fail())
						throw 101;
				}
				catch (int hatakodu) {
					if (hatakodu == 101) {
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
						goto c;
					}
				}
				myMutfak.setKombi(kombiDeger);
				cout << "Kombinizin yeni durumu: ";
				if (myMutfak.getKombi() == 0) {
					cout << "Kapal�." << endl << endl;
				}
				else if (myMutfak.getKombi() > 0) {
					cout << "A��k ve " << myMutfak.getKombi() << " derece." << endl << endl;
				}
				degistirme = 1;

			}
			else if (degistirmeKontrol == "n" || degistirmeKontrol == "N")
			{
				cout << "Kombinizin durumu ayn� �ekilde kalm��t�r..." << endl << endl;
				degistirme = 1;
			}
			else
			{
				cout << "Hatal� tu�lama yapt�n�z! " << endl;
				degistirme = 0;
			}
		}

		goto basaDon;
		break;
	case 8:
		cout << "/*/*/*/*/*/---> Mutfaktaki Di�er Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
	bilesenBasaDon:
		cout << "--------------------------------------------" << endl;
		cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
		cout << "|   |----------------------------------|   |" << endl;
		cout << "|   |* MUTFAK D��ER B�LE�ENLER MEN�S� *|   |" << endl;
		cout << "|   |----------------------------------|   |" << endl;
		cout << "| 1 = Perde                                |" << endl;
		cout << "| 2 = Saks�                                |" << endl;
		cout << "| 3 = Mutfak Ana Men�s�                    |" << endl;
		cout << "| 0 = Ana Men�                             |" << endl;
		cout << "|                                          |" << endl;
		cout << "--------------------------------------------" << endl << endl << endl;

	x:
		cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-3): ";
		cin >> secenek;
		try {
			if (cin.fail())
				throw 101;
		}
		catch (int hatakodu) {
			if (hatakodu == 101) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
				goto x;
			}
		}

		if (secenek == 0) {
			return secenek;
		}else if(secenek == 1) {
			perdeDurumuMenusu(pGuvenlik);
			goto bilesenBasaDon;
		}
		else if (secenek == 2) {
			saksiMenusu(secenek, pGuvenlik);
			if (secenek == 0) {
				return secenek;
			}
			goto bilesenBasaDon;
		}
		else if (secenek == 3) {

			goto basaDon;
		}
		else {
			cout << "Hatal� Tu�lama!!" << endl << endl;
			goto bilesenBasaDon;
		}
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

void salonAdiDegistirme(salon& mySalon) {
	string newSalonAdi;
	cout << "L�tfen salonunuza yeni ad�n� giriniz: ";
	cin.ignore();
	getline(cin, newSalonAdi);
	mySalon.setSalonAdi(newSalonAdi);
	cout << "Salonunuzun ad� " << mySalon.getSalonAdi() << " olarak de�i�tirilmi�tir." << endl;
	cout << "/*/*/*/*/*/---> Salon Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
}

int salonPrizleriMenusu(int& secenek, salon& mySalon) {
	string prizEkelemek;
basaDon:
	if (mySalon.getSalonPrizSayac() == 0) {
		//Priz olu�turulmas�
		cout << "En az bir adet priz olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz olu�turmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme men�s�ne aktar�yorum...... " << endl << endl;
			mySalon.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |-------------------------|        |" << endl;
	cout << "|       |* SALON PR�ZLER� MEN�S� *|        |" << endl;
	cout << "|       |-------------------------|        |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz ��kar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu ��ren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu De�i�tir         |" << endl;
	cout << "| 5 = T�m Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Prizleri Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int salonLambalariMenusu(int& secenek, salon& mySalon) {
	string lambaEklemek;
basaDon:
	if (mySalon.getSalonLampSayac() == 0) {
		//Lamba olu�turulmas�
		cout << "En az bir adet lamba olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba olu�turmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme men�s�ne aktar�yorum...... " << endl << endl;
			mySalon.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "|       |* SALON LAMBALARI MEN�S� *|       |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba ��kar                          |" << endl;
	cout << "| 3 = Bir Lamban�n Durumunu ��ren          |" << endl;
	cout << "| 4 = Bir Lamban�n Durumunu De�i�tir       |" << endl;
	cout << "| 5 = T�m Lambalar� Listele                |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Lambalar� Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int salonMenusu(int& secenek, salon& mySalon, home* pGuvenlik) {
	static int salonOlusturulmusMu = 0;
	if (salonOlusturulmusMu == 0) {
		string salonAdi;
		//Salon olu�turulmas�
		cout << "�ncelikle bir Salon olu�turman�z gerekiyor." << endl;
		cout << "L�tfen salonunuza bir isim veriniz: ";
		cin.ignore();
		getline(cin, salonAdi);
		cout << endl;
		mySalon.setSalonAdi(salonAdi);
		salonOlusturulmusMu = 1;
	}

	pGuvenlik = &mySalon;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|           |----------------|             |" << endl;
	cout << "|           |* SALON MEN�S� *|             |" << endl;
	cout << "|           |----------------|             |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Ayd�nlatmalar                        |" << endl;
	cout << "| 3 = T�m Bile�enler                       |" << endl;
	cout << "| 4 = Salon Ad�n� De�i�tirme               |" << endl;
	cout << "| 5 = Salonun G�venlik Durumu              |" << endl;
	cout << "| 6 = Salonun S�cakl�k ve Nem Durumu       |" << endl;
	cout << "| 7 = Salondaki Di�er Bile�enler           |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		salonPrizleriMenusu(secenek, mySalon);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Ayd�nlatmalar B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		salonLambalariMenusu(secenek, mySalon);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> T�m Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mySalon.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> T�m Bile�enler Listelendi. Salon Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Salon Ad� De�i�im B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		salonAdiDegistirme(mySalon);
		goto basaDon;
	case 5:
		cout << "/*/*/*/*/*/---> Salonun G�venlik Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Salonun S�cakl�k ve Nem Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		sicaklikKontrolMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Salondaki Di�er Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
	bilesenBasaDon:
		cout << "--------------------------------------------" << endl;
		cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
		cout << "|   |-----------------------------------|  |" << endl;
		cout << "|   |* SALONDA D��ER B�LE�ENLER MEN�S� *|  |" << endl;
		cout << "|   |-----------------------------------|  |" << endl;
		cout << "| 1 = Perde                                |" << endl;
		cout << "| 2 = Klima                                |" << endl;
		cout << "| 3 = Saks�                                |" << endl;
		cout << "| 4 = Salon Ana Men�s�                     |" << endl;
		cout << "| 0 = Ana Men�                             |" << endl;
		cout << "|                                          |" << endl;
		cout << "--------------------------------------------" << endl << endl << endl;

	x:
		cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
		cin >> secenek;
		try {
			if (cin.fail())
				throw 101;
		}
		catch (int hatakodu) {
			if (hatakodu == 101) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
				goto x;
			}
		}

		if (secenek == 0) {
			return secenek;
		}
		else if (secenek == 1) {
			perdeDurumuMenusu(pGuvenlik);
			goto bilesenBasaDon;
		}
		else if (secenek == 2) {
			klimaDurumuMenusu(pGuvenlik);
			goto bilesenBasaDon;
		}
		else if (secenek == 3) {
			saksiMenusu(secenek, pGuvenlik);
			if (secenek == 0) {
				return secenek;
			}
			goto bilesenBasaDon;
		}
		else if (secenek == 4) {
			goto basaDon;
		}

		goto basaDon;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

void odaAdiDegistirme(odalar& myOda) {
	string newOdaAdi;
	cout << "L�tfen odan�za yeni ad�n� giriniz: ";
	cin.ignore();
	getline(cin, newOdaAdi);
	myOda.setOdaAdi(newOdaAdi);
	cout << "Odan�z�n ad� " << myOda.getOdaAdi() << " olarak de�i�tirilmi�tir." << endl;
	cout << "/*/*/*/*/*/---> Odalar Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
}

int odaPrizleriMenusu(int& secenek, odalar& myOda) {
	string prizEkelemek;
basaDon:
	if (myOda.getOdaPrizSayac() == 0) {
		//Priz olu�turulmas�
		cout << "En az bir adet priz olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz olu�turmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myOda.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|      |----------------------------|      |" << endl;
	cout << "|      |* ODANIZIN PR�ZLER� MEN�S� *|      |" << endl;
	cout << "|      |----------------------------|      |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz ��kar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu ��ren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu De�i�tir         |" << endl;
	cout << "| 5 = T�m Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Prizleri Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;


}

int odaLambalariMenusu(int& secenek, odalar& myOda) {
	string lambaEklemek;
basaDon:
	if (myOda.getOdaLampSayac() == 0) {
		//Lamba olu�turulmas�
		cout << "En az bir adet lamba olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba olu�turmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myOda.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|      |-----------------------------|     |" << endl;
	cout << "|      |* ODANIZIN LAMBALARI MEN�S� *|     |" << endl;
	cout << "|      |-----------------------------|     |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba ��kar                          |" << endl;
	cout << "| 3 = Bir Lamban�n Durumunu ��ren          |" << endl;
	cout << "| 4 = Bir Lamban�n Durumunu De�i�tir       |" << endl;
	cout << "| 5 = T�m Lambalar� Listele                |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Lambalar� Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int odalarMenusu(int& secenek, odalar& myOda, home* pGuvenlik) {

	pGuvenlik = &myOda;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|           |-------------------|          |" << endl;
	cout << "|           |* ODANIZIN MEN�S� *|          |" << endl;
	cout << "|           |-------------------|          |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Ayd�nlatmalar                        |" << endl;
	cout << "| 3 = T�m Bile�enler                       |" << endl;
	cout << "| 4 = Oda Ad�n� De�i�tirme                 |" << endl;
	cout << "| 5 = Odan�n G�venlik Durumu               |" << endl;
	cout << "| 6 = Odan�n S�cakl�k ve Nem Durum         |" << endl;
	cout << "| 7 = Odadaki Di�er Bile�enler             |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		odaPrizleriMenusu(secenek, myOda);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Ayd�nlatmalar B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		odaLambalariMenusu(secenek, myOda);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> T�m Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myOda.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> T�m Bile�enler Listelendi. Oda Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Oda Ad� De�i�im B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		odaAdiDegistirme(myOda);
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Odan�n G�venlik Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Odan�n S�cakl�k ve Nem Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		sicaklikKontrolMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Odadaki Di�er Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
	bilesenBasaDon:
		cout << "--------------------------------------------" << endl;
		cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
		cout << "|   |-----------------------------------|  |" << endl;
		cout << "|   |* ODADAK� D��ER B�LE�ENLER MEN�S� *|  |" << endl;
		cout << "|   |-----------------------------------|  |" << endl;
		cout << "| 1 = Perde                                |" << endl;
		cout << "| 2 = Klima                                |" << endl;
		cout << "| 3 = Saks�                                |" << endl;
		cout << "| 4 = Odan�z�n Ana Men�s�                  |" << endl;
		cout << "| 0 = Ana Men�                             |" << endl;
		cout << "|                                          |" << endl;
		cout << "--------------------------------------------" << endl << endl << endl;

	x:
		cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
		cin >> secenek;
		try {
			if (cin.fail())
				throw 101;
		}
		catch (int hatakodu) {
			if (hatakodu == 101) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
				goto x;
			}
		}

		if (secenek == 0) {
			return secenek;
		}
		else if (secenek == 1) {
			perdeDurumuMenusu(pGuvenlik);
			goto bilesenBasaDon;
		}
		else if (secenek == 2) {
			klimaDurumuMenusu(pGuvenlik);
			goto bilesenBasaDon;
		}
		else if (secenek == 3) {
			saksiMenusu(secenek, pGuvenlik);
			if (secenek == 0) {
				return secenek;
			}
			goto bilesenBasaDon;
		}
		else if (secenek == 4) {
			goto basaDon;
		}

		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

int odaIslemleriMenusu(int& secenek, map<int, odalar>& mOda,home *pGuvenlik) {
	int odaSorgu;
	auto it = mOda.find(odaSorgu);
basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "|           |* ODALAR MEN�S� *|            |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "| 1 = Oda Ekle                             |" << endl;
	cout << "| 2 = Odaya Git                            |" << endl;
	cout << "| 3 = Odalar� Listele                      |" << endl;
	cout << "| 4 = Oday� Sil                            |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}
	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Oda Ekle B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		odaEkleme(mOda);
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Odaya Git B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		if (odaSayac == 1) {
			cout << "\n Hi� Oda Olu�turulmam��! L�tfen �nce oda olu�turunuz...\n\n";
			goto basaDon;
		}
		odaListeleme(mOda);
		cout << "\n��erisine girmek istediginiz oda ID: ";
		cin >> odaSorgu;
		it = mOda.find(odaSorgu);
		if (it != mOda.end()) {
			// Oda bulundu
			odalar& myOda = it->second;
			odalarMenusu(secenek, myOda, pGuvenlik);
			if (secenek == 0) {
				return secenek;
			}
		}
		else {
			// Oda bulunamadi ise..
			cout << "Oda bulunamadi!\n";
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Oda Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		odaListeleme(mOda);
		cout << "/*/*/*/*/*/---> T�m Odalar Listelendi. Odalar Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Oda Silme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		if (odaSayac == 1) {
			cout << "\n Hi� Oda Olu�turulmam��! L�tfen �nce oda olu�turunuz...\n\n";
			goto basaDon;
		}
		odaListeleme(mOda);
		cout << "\nSilmek istedi�iniz Oda ID: ";
		cin >> odaSorgu;
		if (mOda.erase(odaSorgu)) {
			cout << "Oda basariyla silindi.\n";
			odaSayac--;
		}
		else {
			cout << "Oda bulunamadi!\n";
		}
		goto basaDon;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

void banyoAdiDegistirme(banyo& myBanyo) {
	string newBanyoAdi;
	cout << "L�tfen banyonuza yeni ad�n� giriniz: ";
	cin.ignore();
	getline(cin, newBanyoAdi);
	myBanyo.setBanyoAdi(newBanyoAdi);
	cout << "Banyonuzun ad� " << myBanyo.getBanyoAdi() << " olarak de�i�tirilmi�tir." << endl;
	cout << "/*/*/*/*/*/---> Banyo Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
}

int banyoPrizleriMenusu(int& secenek, banyo& myBanyo) {
	string prizEkelemek;
basaDon:
	if (myBanyo.getBanyoPrizSayac() == 0) {
		//Priz olu�turulmas�
		cout << "En az bir adet priz olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz olu�turmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myBanyo.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |-------------------------|        |" << endl;
	cout << "|       |* BANYO PR�ZLER� MEN�S� *|        |" << endl;
	cout << "|       |-------------------------|        |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz ��kar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu ��ren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu De�i�tir         |" << endl;
	cout << "| 5 = T�m Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Prizleri Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int banyoLambalariMenusu(int& secenek, banyo& myBanyo) {
	string lambaEklemek;
basaDon:
	if (myBanyo.getBanyoLampSayac() == 0) {
		//Lamba olu�turulmas�
		cout << "En az bir adet lamba olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba olu�turmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myBanyo.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "|       |* BANYO LAMBALARI MEN�S� *|       |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba ��kar                          |" << endl;
	cout << "| 3 = Bir Lamban�n Durumunu ��ren          |" << endl;
	cout << "| 4 = Bir Lamban�n Durumunu De�i�tir       |" << endl;
	cout << "| 5 = T�m Lambalar� Listele                |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Lambalar� Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int banyoMenusu(int& secenek, banyo& myBanyo,home* pGuvenlik) {
	static int banyoOlusturulmusMu = 0;
	if (banyoOlusturulmusMu == 0) {
		string banyoAdi;
		//Banyo olu�turulmas�
		cout << "�ncelikle bir Banyo olu�turman�z gerekiyor." << endl;
		cout << "L�tfen banyonuza bir isim veriniz: ";
		cin.ignore();
		getline(cin, banyoAdi);
		cout << endl;
		myBanyo.setBanyoAdi(banyoAdi);
		banyoOlusturulmusMu = 1;
	}

	pGuvenlik = &myBanyo;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|           |----------------|             |" << endl;
	cout << "|           |* BANYO MEN�S� *|             |" << endl;
	cout << "|           |----------------|             |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Ayd�nlatmalar                        |" << endl;
	cout << "| 3 = T�m Bile�enler                       |" << endl;
	cout << "| 4 = Banyo Ad�n� De�i�tirme               |" << endl;
	cout << "| 5 = Banyonun G�venlik Durumu             |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		banyoPrizleriMenusu(secenek, myBanyo);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Ayd�nlatmalar B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		banyoLambalariMenusu(secenek, myBanyo);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> T�m Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> T�m Bile�enler Listelendi. Salon Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Banyo Ad� De�i�im B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		banyoAdiDegistirme(myBanyo);
		goto basaDon;
	case 5:
		cout << "/*/*/*/*/*/---> Banyonun G�venlik Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

void tuvaletAdiDegistirme(tuvalet& myTuvalet) {
	string newTuvaletAdi;
	cout << "L�tfen tuvaletinize yeni ad�n� giriniz: ";
	cin.ignore();
	getline(cin, newTuvaletAdi);
	myTuvalet.setTuvaletAdi(newTuvaletAdi);
	cout << "Tuvaletinizin ad� " << myTuvalet.getTuvaletAdi() << " olarak de�i�tirilmi�tir." << endl;
	cout << "/*/*/*/*/*/---> Tuvalet Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
}

int tuvaletPrizleriMenusu(int& secenek, tuvalet& myTuvalet) {
	string prizEkelemek;
basaDon:
	if (myTuvalet.getTuvaletPrizSayac() == 0) {
		//Priz olu�turulmas�
		cout << "En az bir adet priz olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz olu�turmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myTuvalet.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "|       |* TUVALET PR�ZLER� MEN�S� *|      |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz ��kar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu ��ren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu De�i�tir         |" << endl;
	cout << "| 5 = T�m Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Prizleri Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int tuvaletLambalariMenusu(int& secenek, tuvalet& myTuvalet) {
	string lambaEklemek;
basaDon:
	if (myTuvalet.getTuvaletLampSayac() == 0) {
		//Lamba olu�turulmas�
		cout << "En az bir adet lamba olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba olu�turmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myTuvalet.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |----------------------------|     |" << endl;
	cout << "|       |* TUVALET LAMBALARI MEN�S� *|     |" << endl;
	cout << "|       |----------------------------|     |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba ��kar                          |" << endl;
	cout << "| 3 = Bir Lamban�n Durumunu ��ren          |" << endl;
	cout << "| 4 = Bir Lamban�n Durumunu De�i�tir       |" << endl;
	cout << "| 5 = T�m Lambalar� Listele                |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Lambalar� Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int tuvaletMenusu(int& secenek, tuvalet& myTuvalet, home* pGuvenlik) {
	static int tuvaletOlusturulmusMu = 0;
	if (tuvaletOlusturulmusMu == 0) {
		string tuvaletAdi;
		//Tuvalet olu�turulmas�
		cout << "�ncelikle bir Tuvalet olu�turman�z gerekiyor." << endl;
		cout << "L�tfen Tuvaletinize bir isim veriniz: ";
		cin.ignore();
		getline(cin, tuvaletAdi);
		cout << endl;
		myTuvalet.setTuvaletAdi(tuvaletAdi);
		tuvaletOlusturulmusMu = 1;
	}

	pGuvenlik = &myTuvalet;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|           |------------------|           |" << endl;
	cout << "|           |* TUVALET MEN�S� *|           |" << endl;
	cout << "|           |------------------|           |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Ayd�nlatmalar                        |" << endl;
	cout << "| 3 = T�m Bile�enler                       |" << endl;
	cout << "| 4 = Tuvalet Ad�n� De�i�tirme             |" << endl;
	cout << "| 5 = Tuvaletin G�venlik Durumu            |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		tuvaletPrizleriMenusu(secenek, myTuvalet);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Ayd�nlatmalar B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		tuvaletLambalariMenusu(secenek, myTuvalet);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> T�m Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> T�m Bile�enler Listelendi. Salon Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Tuvalet Ad� De�i�im B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		tuvaletAdiDegistirme(myTuvalet);
		goto basaDon;
	case 5:
		cout << "/*/*/*/*/*/---> Tuvaletin G�venlik Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

void koridorAdiDegistirme(koridor& myKoridor) {
	string newKoridorAdi;
	cout << "L�tfen koridorunuza yeni ad�n� giriniz: ";
	cin.ignore();
	getline(cin, newKoridorAdi);
	myKoridor.setKoridorAdi(newKoridorAdi);
	cout << "Koridorunuzun ad� " << myKoridor.getKoridorAdi() << " olarak de�i�tirilmi�tir." << endl;
	cout << "/*/*/*/*/*/---> Koridor Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
}

int koridorPrizleriMenusu(int& secenek, koridor& myKoridor) {
	string prizEkelemek;
basaDon:
	if (myKoridor.getKoridorPrizSayac() == 0) {
		//Priz olu�turulmas�
		cout << "En az bir adet priz olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz olu�turmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myKoridor.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "|       |* KOR�DOR PR�ZLER� MEN�S� *|      |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz ��kar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu ��ren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu De�i�tir         |" << endl;
	cout << "| 5 = T�m Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Prizleri Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int koridorLambalariMenusu(int& secenek, koridor& myKoridor) {
	string lambaEklemek;
basaDon:
	if (myKoridor.getKoridorLampSayac() == 0) {
		//Lamba olu�turulmas�
		cout << "En az bir adet lamba olu�turman�z gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba olu�turmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme men�s�ne aktar�yorum...... " << endl << endl;
			myKoridor.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir �nceki men�ye aktar�yorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatal� tu�lama yapt�n�z! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|       |----------------------------|     |" << endl;
	cout << "|       |* KOR�DOR LAMBALARI MEN�S� *|     |" << endl;
	cout << "|       |----------------------------|     |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba ��kar                          |" << endl;
	cout << "| 3 = Bir Lamban�n Durumunu ��ren          |" << endl;
	cout << "| 4 = Bir Lamban�n Durumunu De�i�tir       |" << endl;
	cout << "| 5 = T�m Lambalar� Listele                |" << endl;
	cout << "| 9 = Bir �nceki Men�                      |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba ��karma B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu ��renme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lamban�n Durumunu De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> T�m Lambalar� Listeleme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir �nceki Men�ye Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (ANA MEN�=9,�IKI�=0): ";
		goto a;
	}
	return secenek;
}

int koridorMenusu(int& secenek, koridor& myKoridor, home* pGuvenlik) {
	static int koridorOlusturulmusMu = 0;
	if (koridorOlusturulmusMu == 0) {
		string koridorAdi;
		//Koridor olu�turulmas�
		cout << "�ncelikle bir Koridor olu�turman�z gerekiyor." << endl;
		cout << "L�tfen Koridorunuza bir isim veriniz: ";
		cin.ignore();
		getline(cin, koridorAdi);
		cout << endl;
		myKoridor.setKoridorAdi(koridorAdi);
		koridorOlusturulmusMu = 1;
	}

	pGuvenlik = &myKoridor;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|           |------------------|           |" << endl;
	cout << "|           |* KOR�DOR MEN�S� *|           |" << endl;
	cout << "|           |------------------|           |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Ayd�nlatmalar                        |" << endl;
	cout << "| 3 = T�m Bile�enler                       |" << endl;
	cout << "| 4 = Koridor Ad�n� De�i�tirme             |" << endl;
	cout << "| 5 = Koridorun G�venlik Durumu            |" << endl;
	cout << "| 6 = Koridorun S�cakl�k ve Nem Durumu     |" << endl;
	cout << "| 7 = Koridorun Saks� Men�s�               |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-4): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		koridorPrizleriMenusu(secenek, myKoridor);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Ayd�nlatmalar B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		koridorLambalariMenusu(secenek, myKoridor);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> T�m Bile�enler B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> T�m Bile�enler Listelendi. Salon Men�s�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Koridor Ad� De�i�im B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		koridorAdiDegistirme(myKoridor);
		goto basaDon;
	case 5:
		cout << "/*/*/*/*/*/---> Koridorun G�venlik Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Koridorun S�cakl�k ve Nem Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		sicaklikKontrolMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Koridorun S�cakl�k ve Nem Durumu B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		saksiMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-4 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

int kullaniciIslemleriMenusu(int& secenek,login& giris, home& evim, string& kullaniciAdi, string& parola, string& ad, string& soyad) {
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|        |-----------------------|         |" << endl;
	cout << "|        |* KULLANICI ��LEMLER� *|         |" << endl;
	cout << "|        |-----------------------|         |" << endl;
	cout << "| 1 = Ev Ad�n� De�i�tirme                  |" << endl;
	cout << "| 2 = Kullan�c� Ad� ve �ifre De�i�tirme    |" << endl;
	cout << "| 3 = Ad ve Soyad De�i�tirme               |" << endl;
	cout << "| 0 = Ana Men�                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-5): ";
a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Evin Ad�n� De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		evAdiDegistirme(evim);
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Kullan�c� Ad�n� ve �ifresini De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		girisBilgisiDegistirme(giris, ad, soyad, kullaniciAdi, parola);
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Kullan�c� Ad ve Soyad De�i�tirme B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		kullaniciAdSoyadDegistirme(giris, ad, soyad);
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-5 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;
}

void evdeBulunanHerseyinListesi(home& evim, mutfak& myMutfak, salon& mySalon, banyo& myBanyo,
	tuvalet& myTuvalet, koridor& myKoridor, map<int, odalar>& mOda) {
	cout << "\n\n\n-*-*-*-*-*-*-*-EVDE BULUNAN HER�EY�N DURUMLARI-*-*-*-*-*-*-*-\n\n\n";
	//Ev
	cout << "Evin Ad�: " << evim.getHomeName() << endl << endl;
	tumEvinGuvenlikDurumlari(evim,myMutfak, mySalon, myBanyo, myTuvalet, myKoridor, mOda);
	//Mutfak
	cout << "\nMutfak Ad�: " << myMutfak.getMutfakAdi() << endl;
	myMutfak.sicaklikVeNemDurum();
	myMutfak.prizlerinVeLambalarinListelenmesi();
	cout << "\nKombinizin durumu: ";
	if (myMutfak.getKombi() == 0) {
		cout << "Kapal�." << endl;
	}
	else if (myMutfak.getKombi() > 0) {
		cout << "A��k ve " << myMutfak.getKombi() << " derece." << endl;
	}
	cout << "Perdenin �uan ki Durumu: ";
	if (myMutfak.getPerdeDurum() == 0) {
		cout << "Perde kapal�!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 0 && myMutfak.getPerdeDurum() <= 250) {
		cout << "Perdenin neredeyse tamam� kapal�!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 250 && myMutfak.getPerdeDurum() <= 500) {
		cout << "Perde yar�ya yak�n kapal�!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 500 && myMutfak.getPerdeDurum() <= 750) {
		cout << "Perdenin yar�dan fazlas� a��k!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 750 && myMutfak.getPerdeDurum() <= 999) {
		cout << "Perdenin neredeyse tamam� a��k!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() == 1000) {
		cout << "Perde a��k!" << endl << endl;
	}
	myMutfak.saksilarinListelenmesi();
	//Salon
	cout << "\nSalon Ad�: " << mySalon.getSalonAdi() << endl;
	mySalon.sicaklikVeNemDurum();
	mySalon.prizlerinVeLambalarinListelenmesi();
	cout << "Perdenin �uan ki Durumu: ";
	if (myMutfak.getPerdeDurum() == 0) {
		cout << "Perde kapal�!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 0 && myMutfak.getPerdeDurum() <= 250) {
		cout << "Perdenin neredeyse tamam� kapal�!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 250 && myMutfak.getPerdeDurum() <= 500) {
		cout << "Perde yar�ya yak�n kapal�!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 500 && myMutfak.getPerdeDurum() <= 750) {
		cout << "Perdenin yar�dan fazlas� a��k!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 750 && myMutfak.getPerdeDurum() <= 999) {
		cout << "Perdenin neredeyse tamam� a��k!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() == 1000) {
		cout << "Perde a��k!" << endl << endl;
	}
	cout << "Kliman�z�n �uan ki Durumu: ";
	if (mySalon.getKlimaDurum() == 0) {
		cout << "Klima kapal�!" << endl << endl;
	}
	else if (mySalon.getKlimaDurum() > 0) {
		cout << "Klima a��k ve de�eri: " << mySalon.getKlimaDurum() << " derece." << endl << endl;
	}
	mySalon.saksilarinListelenmesi();
	//Odalar
	for (const auto& odalarim : mOda) {

		auto it = mOda.find(odalarim.first);
		odalar& myOda = it->second;
		cout << "\nOdan�n Ad�: " << myOda.getOdaAdi() << endl;
		myOda.sicaklikVeNemDurum();
		myOda.prizlerinVeLambalarinListelenmesi();
		cout << "Perdenin �uan ki Durumu: ";
		if (myOda.getPerdeDurum() == 0) {
			cout << "Perde kapal�!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() > 0 && myOda.getPerdeDurum() <= 250) {
			cout << "Perdenin neredeyse tamam� kapal�!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() > 250 && myOda.getPerdeDurum() <= 500) {
			cout << "Perde yar�ya yak�n kapal�!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() > 500 && myOda.getPerdeDurum() <= 750) {
			cout << "Perdenin yar�dan fazlas� a��k!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() > 750 && myOda.getPerdeDurum() <= 999) {
			cout << "Perdenin neredeyse tamam� a��k!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() == 1000) {
			cout << "Perde a��k!" << endl << endl;
		}
		cout << "Kliman�z�n �uan ki Durumu: ";
		if (myOda.getKlimaDurum() == 0) {
			cout << "Klima kapal�!" << endl << endl;
		}
		else if (myOda.getKlimaDurum() > 0) {
			cout << "Klima a��k ve de�eri: " << myOda.getKlimaDurum() << " derece." << endl << endl;
		}
		myOda.saksilarinListelenmesi();
	}
	//Bayno
	cout << "\nBanyo Ad�: " << myBanyo.getBanyoAdi() << endl;
	myBanyo.prizlerinVeLambalarinListelenmesi();
	//Tuvalet
	cout << "\nTuvalet Ad�: " << myTuvalet.getTuvaletAdi() << endl;
	myTuvalet.prizlerinVeLambalarinListelenmesi();
	//Koridor
	cout << "\nKoridor Ad�: " << myKoridor.getKoridorAdi() << endl;
	myKoridor.sicaklikVeNemDurum();
	myKoridor.prizlerinVeLambalarinListelenmesi();
	myKoridor.saksilarinListelenmesi();



}

int akilliEvSistemiAnaMenu(int& secenek, login& giris, home& evim, mutfak& myMutfak, salon& mySalon, map<int, odalar>& mOda, banyo& myBanyo,
	tuvalet& myTuvalet, koridor& myKoridor,home *pGuvenlik, string& kullaniciAdi, string& parola, string& ad, string& soyad) {
basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Ak�ll� Ev Sistemleri          |" << endl;
	cout << "|               |------------|             |" << endl;
	cout << "|               |* ANA MEN� *|             |" << endl;
	cout << "|               |------------|             |" << endl;
	cout << "| 1 = Mutfak                               |" << endl;
	cout << "| 2 = Salon                                |" << endl;
	cout << "| 3 = Odalar                               |" << endl;
	cout << "| 4 = Banyo                                |" << endl;
	cout << "| 5 = Tuvalet                              |" << endl;
	cout << "| 6 = Koridorlar                           |" << endl;
	cout << "| 7 = G�venlik                             |" << endl;
	cout << "| 8 = Evde bulunan her�ey                  |" << endl;
	cout << "| 9 = Kullan�c� ��lemleri                  |" << endl;
	cout << "| 10 = Evcil Hayvan Durumu                 |" << endl;
	cout << "| 0 = ��k��                                |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

	b:
	cout << "L�tfen kontrol etmek istedi�iniz b�l�m� se�iniz(1-9): ";
	a:
	cin >> secenek;
	try {
		if (cin.fail())
			throw 101;
	}
	catch (int hatakodu) {
		if (hatakodu == 101) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "HATA! Girdi�iniz de�er bir SAYI de�il! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Mutfak B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		mutfakMenusu(secenek,myMutfak,pGuvenlik);
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Salon B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		salonMenusu(secenek,mySalon, pGuvenlik);
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Odalar B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		odaIslemleriMenusu(secenek, mOda, pGuvenlik);
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Banyo B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		banyoMenusu(secenek,myBanyo, pGuvenlik);
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tuvalet B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		tuvaletMenusu(secenek,myTuvalet, pGuvenlik);
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Koridorlar B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		koridorMenusu(secenek, myKoridor, pGuvenlik);
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> G�venlik B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		tumEvinGuvenlikDurumlari(evim, myMutfak, mySalon, myBanyo, myTuvalet, myKoridor, mOda);
		goto basaDon;
		break;
	case 8:
		cout << "/*/*/*/*/*/---> Evde Bulunan Her�ey B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		evdeBulunanHerseyinListesi(evim, myMutfak, mySalon, myBanyo, myTuvalet, myKoridor, mOda);
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Kullan�c� ��lmeleri B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		while (secenek != 0) {
			kullaniciIslemleriMenusu(secenek, giris, evim, kullaniciAdi, parola, ad, soyad);
		}
		goto basaDon;
		break;
	case 10:
		cout << "/*/*/*/*/*/---> Evcil Hayvanlar�m B�l�m�ne Aktar�l�yor <---/*/*/*/*/*/ " << endl;
		evcilHayvanMenusu(secenek, evim);
		goto basaDon;
		break;
	default:
		cout << "Yanl�� bir tu�lama yapt�n�z! L�tfen 1-9 aras�nda bir say� giriniz (�IKI�=0): ";
		goto a;
	}
	return secenek;

}

int main() {
	setlocale(LC_ALL, "Turkish");
	cout << "------------------------------------------------" << endl;
	cout << "|              Ak�ll� Ev Sistemleri            |" << endl;
	cout << "|                                              |" << endl;
	cout << "|                 * ANIL TUMER *               |" << endl;
	cout << "|                *  GhosTTymeR  *              |" << endl;
	cout << "|                                              |" << endl;
	cout << "|                                              |" << endl;
	cout << "------------------------------------------------" << endl << endl << endl;

	//Giri� yaparken kullan�lan de�i�kenler
	string kullaniciAdi, parola, ad, soyad;
	//Ev olu�tururken kullan�lan de�i�kenler
	string evAdi;
	//Men�lerde kullan�lacak de�i�kenler
	int secenek = 0; int cikis = 1;

	//Giri� i�in bilgileri alma
	cout << "L�tfen ad�n�z� giriniz: ";
	getline(cin, ad);
	cout << "L�tfen soyad�n�z� giriniz: ";
	cin >> soyad;
	cout << endl << endl << "Merhaba " << ad << " " << soyad << "." << endl;
	cout << "L�tfen kullan�c� ad�n�z� giriniz: ";
	cin >> kullaniciAdi;
	cout << "L�tfen kullan�c� �ifrenizi giriniz: ";
	cin >> parola;

	//Kullan�c� olu�turma 
	login giris(ad, soyad, kullaniciAdi, parola);

	//�lk giri� i�in kullan�c� ad�: ghost06, �ifre:5462
	giris.girisYap();

	//Kullan�c� bilgilerinin ekrana yazd�r�lmas�
	cout << "Kullan�c� bilgileri: " << endl;
	cout << "AD--> " << giris.getAd() << endl << "SOYAD--> " << giris.getSoyad() << endl << "KULLNICI ADI--> " << giris.getId() << endl;
	cout << "PAROLA--> " << giris.getPassword() << endl;
	cout << endl << endl << endl;

	//Ev olu�umu
	cin.ignore();
	cout << "L�tfen evinize bir isim veriniz: ";
	getline(cin, evAdi);
	home evim(evAdi);

	//Default Ev B�l�mlerinin Olu�turulmas�
	mutfak myMutfak("MUTFAK");
	salon mySalon("SALON");
	map<int, odalar> mOda;
	banyo myBanyo("BANYO");
	tuvalet myTuvalet("TUVALET");
	koridor myKoridor("KOR�DOR");

	//Evin B�l�mlerinin G�venlik Durumlar�n� Tutacak Pointer
	home* pGuvenlik;
	pGuvenlik = &evim;

	//Ana Men�m�z�n Ba�lat�lmas�
	while (cikis >= 1) {
		cikis = akilliEvSistemiAnaMenu
		(secenek, giris, evim, myMutfak, mySalon, mOda, myBanyo, myTuvalet, myKoridor, pGuvenlik, kullaniciAdi, parola, ad, soyad);
	}
	if (secenek == 0) {
		cout << endl << "��k�� yap�l�yor..." << endl;
	}

	//Program kapan�rken son kontroller
	cout << endl << endl << endl;
	cout << "��k�� bilgileri: " << endl;
	cout << "EV ADI--> " << evim.getHomeName() << endl;
	cout << "AD--> " << giris.getAd() << endl << "SOYAD--> " << giris.getSoyad() << endl << "KULLNICI ADI--> " << giris.getId() << endl;
	cout << "PAROLA--> " << giris.getPassword() << endl;
	cout << endl << endl << endl;
	cout << endl << endl << endl;
	
	return 0;
}