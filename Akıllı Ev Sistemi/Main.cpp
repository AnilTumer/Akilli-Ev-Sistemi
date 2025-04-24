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
		cout << "Kullanýcý adi þifre deðiþtrime bölümü.. " << endl << endl;
		cout << "Lütfen yeni kullanýcý adýnýzý giriniz: ";
		cin >> newID;
		cout << "Lütfen yeni þifrenizi giriniz: ";
		cin >> newPassword;

		giris.setIdKontrol(newID);
		giris.setPassworKontrol(newPassword);

		cout << "Yeni kullanýcý adý: " << giris.getIdKontrol() << endl;
		cout << "Yeni þifre: " << giris.getPasswordKontrol() << endl;
		cout << endl << endl << "Merhaba " << ad << " " << soyad << ". Lütfen yeniden giriþ yapýnýz." << endl;
		cout << "Lütfen kullanýcý adýnýzý giriniz: ";
		cin >> kullaniciAdi;
		cout << "Lütfen kullanýcý þifrenizi giriniz: ";
		cin >> parola;
		giris.setId(kullaniciAdi);
		giris.setPassword(parola);
		giris.girisYap();
	}
}

void kullaniciAdSoyadDegistirme(login& giris, string& ad, string& soyad) {
	cout << "Kullanýcý ad ve soyad deðiþtrime bölümü.. " << endl << endl;
	cout << "Merhaba " << giris.getAd() << " " << giris.getSoyad() << "." << endl;
	cout << "Lütfen adýnýzý giriniz: ";
	cin.ignore();
	getline(cin, ad);
	giris.setAd(ad);
	cout << "\nLütfen soyadýnýzý giriniz: ";
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
		//Priz oluþturulmasý
		cout << "En az bir adet evcil hayvan oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Evcil Hayvan oluþturmak istiyor musunuz?(y/n): ";
		cin >> evcilHayvanEklemek;
		if (evcilHayvanEklemek == "y" || evcilHayvanEklemek == "Y") {
			cout << "Sizi evcil hayvan ekleme menüsüne aktarýyorum...... " << endl << endl;
			evim.evcilHayvanEkleme();
		}
		else if (evcilHayvanEklemek == "n" || evcilHayvanEklemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return secenek;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|        |-------------------------|       |" << endl;
	cout << "|        |* EVCÝL HAYVANIM MENÜSÜ *|       |" << endl;
	cout << "|        |-------------------------|       |" << endl;
	cout << "| 1 = Evcil Hayvan Ekle                    |" << endl;
	cout << "| 2 = Evcil Hayvan Çýkar                   |" << endl;
	cout << "| 3 = Bir Evcil Hayvanýn Durumunu Öðren    |" << endl;
	cout << "| 4 = Bir Evcil Hayvanýn Durumunu Deðiþtir |" << endl;
	cout << "| 5 = Tüm Evcil Hayvanlarýo Listele        |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Evcil Hayvan Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Evcil Hayvan Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Evcil Hayvanýn Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Evcil Hayvanýn Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Evcil Hayvanlarý Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		evim.evcilHayvanListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

int saksiMenusu(int& secenek, home* pGuvenlik) {
	string saksiEklemek;
basaDon:
	if (pGuvenlik->getSaksiSayac() == 0) {
		//Mutfak oluþturulmasý
		cout << "En az bir adet saksý oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Saksý oluþturmak istiyor musunuz?(y/n): ";
		cin >> saksiEklemek;
		if (saksiEklemek == "y" || saksiEklemek == "Y") {
			cout << "Sizi saksý ekleme menüsüne aktarýyorum...... " << endl << endl;
			pGuvenlik->saksiEkle();
		}
		else if (saksiEklemek == "n" || saksiEklemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|          |---------------------|         |" << endl;
	cout << "|          |* SAKSILARIM MENÜSÜ *|         |" << endl;
	cout << "|          |---------------------|         |" << endl;
	cout << "| 1 = Saksý Ekle                           |" << endl;
	cout << "| 2 = Saksý Çýkar                          |" << endl;
	cout << "| 3 = Bir Saksýnýn Durumunu Öðren          |" << endl;
	cout << "| 4 = Bir Saksýnýn Durumunu Deðiþtir       |" << endl;
	cout << "| 5 = Tüm Saksýlarý Listele                |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksiEkle();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksiCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksiDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksiDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Lambalarý Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->saksilarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

void perdeDurumuMenusu(home* pGuvenlik) {
	string degisimKontrol;
	bool degisim = 0;
	int perdeDeger = 0;

	cout << "Perdenizin Þuan ki Durumu: " << endl;
	if (pGuvenlik->getPerdeDurum() == 0) {
		cout << "Perde kapalý!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() > 0 && pGuvenlik->getPerdeDurum() <= 250) {
		cout << "Perdenin neredeyse tamamý kapalý!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() > 250 && pGuvenlik->getPerdeDurum() <= 500) {
		cout << "Perde yarýya yakýn kapalý!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() > 500 && pGuvenlik->getPerdeDurum() <= 750) {
		cout << "Perdenin yarýdan fazlasý açýk!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() > 750 && pGuvenlik->getPerdeDurum() <= 999) {
		cout << "Perdenin neredeyse tamamý açýk!" << endl << endl;
	}
	else if (pGuvenlik->getPerdeDurum() == 1000) {
		cout << "Perde açýk!" << endl << endl;
	}

	while (degisim != 1)
	{
		cout << "Perdenizin durumunu deðiþtirmek istiyor musunuz?(y/n): ";
		cin >> degisimKontrol;
		if (degisimKontrol == "y" || degisimKontrol == "Y")
		{
		c:
			cout << "Perdenizin yeni deðerini giriniz(0 - 1000): " << endl;
			cout << "* 1000 = Max Açýk\n* 500 = Yarý Açýk\n* 0 =Kapalý" << endl;
			cin >> perdeDeger;
			try {
				if (cin.fail())
					throw 101;
			}
			catch (int hatakodu) {
				if (hatakodu == 101) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
					goto c;
				}
			}

			if (perdeDeger > 1000 || perdeDeger < 0) {
				cout << "HATALI DEÐER GÝRDÝNÝZ! " << perdeDeger << " Verilen aralýkta deðildir!!\n";
				goto c;
			}
			else {
				pGuvenlik->setPerdeDurum(perdeDeger);
				cout << "Perdenizin yeni deðeri: " << endl;
				if (pGuvenlik->getPerdeDurum() == 0) {
					cout << "Perde kapalý!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() > 0 && pGuvenlik->getPerdeDurum() <= 250) {
					cout << "Perdenin neredeyse tamamý kapalý!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() > 250 && pGuvenlik->getPerdeDurum() <= 500) {
					cout << "Perde yarýya yakýn kapalý!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() > 500 && pGuvenlik->getPerdeDurum() <= 750) {
					cout << "Perdenin yarýdan fazlasý açýk!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() > 750 && pGuvenlik->getPerdeDurum() <= 999) {
					cout << "Perdenin neredeyse tamamý açýk!" << endl << endl;
				}
				else if (pGuvenlik->getPerdeDurum() == 1000) {
					cout << "Perde açýk!" << endl << endl;
				}
			}
			
			degisim = 1;

		}
		else if (degisimKontrol == "n" || degisimKontrol == "N")
		{
			cout << "Perdenizin durumu ayný þekilde kalmýþtýr..." << endl << endl;
			degisim = 1;
		}
		else
		{
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			degisim = 0;
		}
	}

}

void klimaDurumuMenusu(home* pGuvenlik) {
	string degisimKontrol;
	bool degisim = 0;
	int klimaDeger = 0;

	cout << "Klimanýzýn Þuan ki Durumu: " << endl;
	if (pGuvenlik->getKlimaDurum() == 0) {
		cout << "Klima kapalý!" << endl << endl;
	}
	else if (pGuvenlik->getKlimaDurum() > 0) {
		cout << "Klima açýk ve deðeri: "<<pGuvenlik->getKlimaDurum() <<" derece."<< endl << endl;
	}

	while (degisim != 1)
	{
		cout << "Klimanýzýn durumunu deðiþtirmek istiyor musunuz?(y/n): ";
		cin >> degisimKontrol;
		if (degisimKontrol == "y" || degisimKontrol == "Y")
		{
		c:
			cout << "Klimanýzýn yeni deðerini giriniz(0 - 50): " << endl;
			cout << "* 50 = Max Açýk\n* 0 = Kapalý" << endl;
			cin >> klimaDeger;
			try {
				if (cin.fail())
					throw 101;
			}
			catch (int hatakodu) {
				if (hatakodu == 101) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
					goto c;
				}
			}

			if (klimaDeger > 50 || klimaDeger < 0) {
				cout << "HATALI DEÐER GÝRDÝNÝZ! " << klimaDeger << " Verilen aralýkta deðildir!!\n";
				goto c;
			}
			else {
				pGuvenlik->setKlimaDurum(klimaDeger);
				cout << "Klimanýzýn Þuan ki Durumu: " << endl;
				if (pGuvenlik->getKlimaDurum() == 0) {
					cout << "Klima kapalý!" << endl << endl;
				}
				else if (pGuvenlik->getKlimaDurum() > 0) {
					cout << "Klima açýk ve deðeri: " << pGuvenlik->getKlimaDurum() << " derece." << endl << endl;
				}
			}

			degisim = 1;

		}
		else if (degisimKontrol == "n" || degisimKontrol == "N")
		{
			cout << "Klimanizin durumu ayný þekilde kalmýþtýr..." << endl << endl;
			degisim = 1;
		}
		else
		{
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			degisim = 0;
		}
	}
}

int sicaklikKontrolMenusu(int& secenek, home* pGuvenlik) {
	float sicaklik = 25;
	float nem = 25;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "|       |* SICAKLÝK ve NEM MENÜSÜ *|       |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "| 1 = Sýcaklýk ve Nem Durumunu             |" << endl;
	cout << "| 2 = Sýcaklýk Deðerini Deðiþtir           |" << endl;
	cout << "| 3 = Nem Deðerini Deðiþtir                |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-3): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Sýcaklýk ve Nem Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		pGuvenlik->sicaklikVeNemDurum();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Sýcaklýk Deðerini Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		cout << "Lütfen olmasýný istediðiniz sýcaklýk deðerini giriniz: ";
		cin >> sicaklik;
		pGuvenlik->setSicaklikDeger(sicaklik);
		cout << "Yeni sýcaklýk deðeriniz = " << pGuvenlik->getSicaklikDeger() << endl << endl;
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Nem Deðerini Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		cout << "Lütfen olmasýný istediðiniz nem deðerini giriniz: ";
		cin >> nem;
		pGuvenlik->setNemDeger(nem);
		cout << "Yeni nem deðeriniz = " << pGuvenlik->getNemDeger() << endl << endl;
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-3 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
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
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|  |------------------------------------|  |" << endl;
	cout << "|  |* GÜVENLÝK DURUM DEÐÝÞTÝRME MENÜSÜ *|  |" << endl;
	cout << "|  |------------------------------------|  |" << endl;
	cout << "| 1 = Yangýn Durumu Deðiþtirme             |" << endl;
	cout << "| 2 = Su Baskýný Durumunu Deðiþtirme       |" << endl;
	cout << "| 3 = Hýrsýz Durumunu Deðiþtirme           |" << endl;
	cout << "| 4 = Deprem Durumunu Deðiþtirme           |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-2): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Yangýn Durumu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		int yanginDurumunuDegistir;
		cout << "* 1 = Yangýn Çýkar." << endl;
		cout << "* 2 = Yangýný Söndür." << endl << endl;
		cout << "Lütfen Yukarýdaki seçeneklerden birini seçinizi (1-2): ";
		cin >> yanginDurumunuDegistir;
		if (yanginDurumunuDegistir == 1) {
			cout <<"Yangýn çýkarýldý..." << endl << endl;
			pGuvenlik->setYanginDurum(1);
		}
		else if (yanginDurumunuDegistir == 2) {
			cout << "Yangýn söndürüldü..." << endl << endl;
			pGuvenlik->setYanginDurum(0);
		}
		else {
			cout << "Hatali tuþlama yaptýnýz!!!" << endl << endl;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Su Baskýný Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		int suBaskiniDurumunuDegistir;
		cout << "* 1 = Su Baskýný Çýkar." << endl;
		cout << "* 2 = Su Baskýnýný Durdur." << endl << endl;
		cout << "Lütfen Yukarýdaki seçeneklerden birini seçinizi (1-2): ";
		cin >> suBaskiniDurumunuDegistir;
		if (suBaskiniDurumunuDegistir == 1) {
			cout << "Su baskýný çýkarýldý..." << endl << endl;
			pGuvenlik->setSuBaskiniDurum(1);
		}else if (suBaskiniDurumunuDegistir == 2) {
			cout << "Su baskýný durduruldu..." << endl << endl;
			pGuvenlik->setSuBaskiniDurum(0);
		}
		else {
			cout << "Hatali tuþlama yaptýnýz!!!" << endl << endl;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Hýrsýz Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		int hirsizDurumunuDegistir;
		cout << "* 1 = Hýrsýz Sok." << endl;
		cout << "* 2 = Hýrsýzý Dýþarý Çýkar." << endl << endl;
		cout << "Lütfen Yukarýdaki seçeneklerden birini seçinizi (1-2): ";
		cin >> hirsizDurumunuDegistir;
		if (hirsizDurumunuDegistir == 1) {
			cout << "Hýrsýz sokuldu..." << endl << endl;
			pGuvenlik->setHirsizDurum(1);
		}else if (hirsizDurumunuDegistir == 2) {
			cout << "Hýrsýz dýþarý çýkarýldý..." << endl << endl;
			pGuvenlik->setHirsizDurum(0);
		}
		else {
			cout << "Hatali tuþlama yaptýnýz!!!" << endl << endl;
		}
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Deprem Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		int depremDurumunuDegistir;
		cout << "* 1 = Deprem Yap." << endl;
		cout << "* 2 = Depremi Durdur." << endl << endl;
		cout << "Lütfen Yukarýdaki seçeneklerden birini seçinizi (1-2): ";
		cin >> depremDurumunuDegistir;
		if (depremDurumunuDegistir == 1) {
			cout << "Deprem Yapýldý..." << endl << endl;
			pGuvenlik->setDepremDurum(1);
		}
		else if (depremDurumunuDegistir == 2) {
			cout << "Deprem Durduruldu..." << endl << endl;
			pGuvenlik->setDepremDurum(0);
		}
		else {
			cout << "Hatali tuþlama yaptýnýz!!!" << endl << endl;
		}
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;


}

int guvenlikMenusu(int& secenek, home* pGuvenlik) {
basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|           |-------------------|          |" << endl;
	cout << "|           |* GÜVENLÝK MENÜSÜ *|          |" << endl;
	cout << "|           |-------------------|          |" << endl;
	cout << "| 1 = Güvenlik Durumu Öðrenme              |" << endl;
	cout << "| 2 = Güvenlik Durumunu Deðiþtirme         |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-2): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Güvenlik Durumu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		guvenlikDurumlari(secenek, pGuvenlik);
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Güvenlik Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		guvenlikDurumunuDegistirme(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

void odaEkleme(map<int, odalar>& mOda) {
	string odaAdi;
	map <string, float> mOdaLamp;
	map <string, int> mOdaPriz;
	map<string, float>mOdaSaksi;
	cout << "Odanýza bir isim veriniz: ";
farkliIsim:
	cin.ignore();
	getline(cin, odaAdi);

	for (const auto& odalarim : mOda) {
		auto it = mOda.find(odalarim.first);
		odalar& myOda = it->second;
		if (myOda.getOdaAdi() == odaAdi) {
			cout << "Ayný isimle oluþturulmuþ bir odanýz mevcuttur! Lütfen baþka bir isim giriniz: ";
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
		cout << "\nHiç odanýz yok!\n\n";
		return;
	}

	cout << "--------------------------------------------" << endl;
	cout << "|           Akýllý Ev Sistemleri           |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "|           |* ODALAR MENÜSÜ *|            |" << endl;
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
	cout << "Lütfen evinizin yeni adýný giriniz: ";
	cin.ignore();
	getline(cin, newHomeName);
	evim.setHomeName(newHomeName);
	cout << "Evinizin adý " << evim.getHomeName() << " olarak deðiþtirilmiþtir." << endl;
	cout << "/*/*/*/*/*/---> Ana Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
}

void mutfakAdiDegistirme(mutfak& myMutfak) {
		string newMutfakAdi;
		cout << "Lütfen mutfaðýnýzýn yeni adýný giriniz: ";
		cin.ignore();
		getline(cin, newMutfakAdi);
		myMutfak.setMutfakAdi(newMutfakAdi);
		cout << "Mutfaðýnýzýn adý " << myMutfak.getMutfakAdi() << " olarak deðiþtirilmiþtir." << endl;
		cout << "/*/*/*/*/*/---> Mutfak Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;	
}

int mutfakPrizleriMenusu(int& secenek, mutfak& myMutfak) {
	string prizEkelemek;
basaDon:
	if (myMutfak.getPrizSayac() == 0) {
		//Priz oluþturulmasý
		cout << "En az bir adet priz oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz oluþturmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme menüsüne aktarýyorum...... " << endl << endl;
			myMutfak.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "|       |* MUTFAK PRÝZLERÝ MENÜSÜ *|       |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz Çýkar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu Öðren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu Deðiþtir         |" << endl;
	cout << "| 5 = Tüm Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Prizleri Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int mutfakLambalariMenusu(int& secenek, mutfak& myMutfak) {
	string lambaEklemek;
basaDon:
	if (myMutfak.getLampSayac() == 0) {
		//Mutfak oluþturulmasý
		cout << "En az bir adet lamba oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba oluþturmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme menüsüne aktarýyorum...... " << endl << endl;
			myMutfak.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "|       |* MUTFAK LAMBALARI MENÜSÜ *|      |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba Çýkar                          |" << endl;
	cout << "| 3 = Bir Lambanýn Durumunu Öðren          |" << endl;
	cout << "| 4 = Bir Lambanýn Durumunu Deðiþtir       |" << endl;
	cout << "| 5 = Tüm Lambalarý Listele                |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Lambalarý Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int mutfakMenusu(int& secenek,mutfak &myMutfak,home *pGuvenlik) {
	static int mutfakOlusturulmusMu = 0;
	if (mutfakOlusturulmusMu == 0) {
		string mutfakAdi;
		//Mutfak oluþturulmasý
		cout << "Öncelikle bir Mutfak oluþturmanýz gerekiyor." << endl;
		cout << "Lütfen mutfaðýnýza bir isim veriniz: ";
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
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "|           |* MUTFAK MENÜSÜ *|            |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Aydýnlatmalar                        |" << endl;
	cout << "| 3 = Tüm Bileþenler                       |" << endl;
	cout << "| 4 = Mutfak Adýný Deðiþtirme              |" << endl;
	cout << "| 5 = Mutfaðýn Güvenlik Durumu             |" << endl;
	cout << "| 6 = Mutfaðýn Sýcaklik ve Nem Durumu      |" << endl;
	cout << "| 7 = Kombi Durumu                         |" << endl;
	cout << "| 8 = Mutfaktaki Diðer Bileþenler          |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mutfakPrizleriMenusu(secenek, myMutfak);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Aydýnlatmalar Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mutfakLambalariMenusu(secenek, myMutfak);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myMutfak.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Listelendi. Mutfak Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Mutfak Adý Deðiþim Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mutfakAdiDegistirme(myMutfak);
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Mutfaðýn Güvenlik Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Mutfaðýn Sýcaklik ve Nem Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		sicaklikKontrolMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Mutfaðýn Kombi Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		cout << "Kombinizin durumu: ";
		if (myMutfak.getKombi() == 0) {
			cout << "Kapalý." << endl << endl;
		}
		else if (myMutfak.getKombi() > 0) {
			cout << "Açýk ve " << myMutfak.getKombi() << " derece." << endl << endl;
		}
		while (degistirme != 1)
		{
			cout << "Kombinizin durumunu deðiþtirmek istiyor musunuz?(y/n): ";
			cin >> degistirmeKontrol;
			if (degistirmeKontrol == "y" || degistirmeKontrol == "Y")
			{
				c:
				cout << "Kombinizin yeni deðerini giriniz(KAPATMAK ÝÇÝN = 0): ";
				cin >> kombiDeger;
				try {
					if (cin.fail())
						throw 101;
				}
				catch (int hatakodu) {
					if (hatakodu == 101) {
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
						goto c;
					}
				}
				myMutfak.setKombi(kombiDeger);
				cout << "Kombinizin yeni durumu: ";
				if (myMutfak.getKombi() == 0) {
					cout << "Kapalý." << endl << endl;
				}
				else if (myMutfak.getKombi() > 0) {
					cout << "Açýk ve " << myMutfak.getKombi() << " derece." << endl << endl;
				}
				degistirme = 1;

			}
			else if (degistirmeKontrol == "n" || degistirmeKontrol == "N")
			{
				cout << "Kombinizin durumu ayný þekilde kalmýþtýr..." << endl << endl;
				degistirme = 1;
			}
			else
			{
				cout << "Hatalý tuþlama yaptýnýz! " << endl;
				degistirme = 0;
			}
		}

		goto basaDon;
		break;
	case 8:
		cout << "/*/*/*/*/*/---> Mutfaktaki Diðer Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
	bilesenBasaDon:
		cout << "--------------------------------------------" << endl;
		cout << "|            Akýllý Ev Sistemleri          |" << endl;
		cout << "|   |----------------------------------|   |" << endl;
		cout << "|   |* MUTFAK DÝÐER BÝLEÞENLER MENÜSÜ *|   |" << endl;
		cout << "|   |----------------------------------|   |" << endl;
		cout << "| 1 = Perde                                |" << endl;
		cout << "| 2 = Saksý                                |" << endl;
		cout << "| 3 = Mutfak Ana Menüsü                    |" << endl;
		cout << "| 0 = Ana Menü                             |" << endl;
		cout << "|                                          |" << endl;
		cout << "--------------------------------------------" << endl << endl << endl;

	x:
		cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-3): ";
		cin >> secenek;
		try {
			if (cin.fail())
				throw 101;
		}
		catch (int hatakodu) {
			if (hatakodu == 101) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
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
			cout << "Hatalý Tuþlama!!" << endl << endl;
			goto bilesenBasaDon;
		}
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

void salonAdiDegistirme(salon& mySalon) {
	string newSalonAdi;
	cout << "Lütfen salonunuza yeni adýný giriniz: ";
	cin.ignore();
	getline(cin, newSalonAdi);
	mySalon.setSalonAdi(newSalonAdi);
	cout << "Salonunuzun adý " << mySalon.getSalonAdi() << " olarak deðiþtirilmiþtir." << endl;
	cout << "/*/*/*/*/*/---> Salon Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
}

int salonPrizleriMenusu(int& secenek, salon& mySalon) {
	string prizEkelemek;
basaDon:
	if (mySalon.getSalonPrizSayac() == 0) {
		//Priz oluþturulmasý
		cout << "En az bir adet priz oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz oluþturmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme menüsüne aktarýyorum...... " << endl << endl;
			mySalon.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |-------------------------|        |" << endl;
	cout << "|       |* SALON PRÝZLERÝ MENÜSÜ *|        |" << endl;
	cout << "|       |-------------------------|        |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz Çýkar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu Öðren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu Deðiþtir         |" << endl;
	cout << "| 5 = Tüm Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Prizleri Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int salonLambalariMenusu(int& secenek, salon& mySalon) {
	string lambaEklemek;
basaDon:
	if (mySalon.getSalonLampSayac() == 0) {
		//Lamba oluþturulmasý
		cout << "En az bir adet lamba oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba oluþturmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme menüsüne aktarýyorum...... " << endl << endl;
			mySalon.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "|       |* SALON LAMBALARI MENÜSÜ *|       |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba Çýkar                          |" << endl;
	cout << "| 3 = Bir Lambanýn Durumunu Öðren          |" << endl;
	cout << "| 4 = Bir Lambanýn Durumunu Deðiþtir       |" << endl;
	cout << "| 5 = Tüm Lambalarý Listele                |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Lambalarý Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int salonMenusu(int& secenek, salon& mySalon, home* pGuvenlik) {
	static int salonOlusturulmusMu = 0;
	if (salonOlusturulmusMu == 0) {
		string salonAdi;
		//Salon oluþturulmasý
		cout << "Öncelikle bir Salon oluþturmanýz gerekiyor." << endl;
		cout << "Lütfen salonunuza bir isim veriniz: ";
		cin.ignore();
		getline(cin, salonAdi);
		cout << endl;
		mySalon.setSalonAdi(salonAdi);
		salonOlusturulmusMu = 1;
	}

	pGuvenlik = &mySalon;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|           |----------------|             |" << endl;
	cout << "|           |* SALON MENÜSÜ *|             |" << endl;
	cout << "|           |----------------|             |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Aydýnlatmalar                        |" << endl;
	cout << "| 3 = Tüm Bileþenler                       |" << endl;
	cout << "| 4 = Salon Adýný Deðiþtirme               |" << endl;
	cout << "| 5 = Salonun Güvenlik Durumu              |" << endl;
	cout << "| 6 = Salonun Sýcaklýk ve Nem Durumu       |" << endl;
	cout << "| 7 = Salondaki Diðer Bileþenler           |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		salonPrizleriMenusu(secenek, mySalon);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Aydýnlatmalar Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		salonLambalariMenusu(secenek, mySalon);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mySalon.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Listelendi. Salon Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Salon Adý Deðiþim Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		salonAdiDegistirme(mySalon);
		goto basaDon;
	case 5:
		cout << "/*/*/*/*/*/---> Salonun Güvenlik Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Salonun Sýcaklýk ve Nem Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		sicaklikKontrolMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Salondaki Diðer Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
	bilesenBasaDon:
		cout << "--------------------------------------------" << endl;
		cout << "|            Akýllý Ev Sistemleri          |" << endl;
		cout << "|   |-----------------------------------|  |" << endl;
		cout << "|   |* SALONDA DÝÐER BÝLEÞENLER MENÜSÜ *|  |" << endl;
		cout << "|   |-----------------------------------|  |" << endl;
		cout << "| 1 = Perde                                |" << endl;
		cout << "| 2 = Klima                                |" << endl;
		cout << "| 3 = Saksý                                |" << endl;
		cout << "| 4 = Salon Ana Menüsü                     |" << endl;
		cout << "| 0 = Ana Menü                             |" << endl;
		cout << "|                                          |" << endl;
		cout << "--------------------------------------------" << endl << endl << endl;

	x:
		cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
		cin >> secenek;
		try {
			if (cin.fail())
				throw 101;
		}
		catch (int hatakodu) {
			if (hatakodu == 101) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
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
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

void odaAdiDegistirme(odalar& myOda) {
	string newOdaAdi;
	cout << "Lütfen odanýza yeni adýný giriniz: ";
	cin.ignore();
	getline(cin, newOdaAdi);
	myOda.setOdaAdi(newOdaAdi);
	cout << "Odanýzýn adý " << myOda.getOdaAdi() << " olarak deðiþtirilmiþtir." << endl;
	cout << "/*/*/*/*/*/---> Odalar Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
}

int odaPrizleriMenusu(int& secenek, odalar& myOda) {
	string prizEkelemek;
basaDon:
	if (myOda.getOdaPrizSayac() == 0) {
		//Priz oluþturulmasý
		cout << "En az bir adet priz oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz oluþturmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme menüsüne aktarýyorum...... " << endl << endl;
			myOda.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|      |----------------------------|      |" << endl;
	cout << "|      |* ODANIZIN PRÝZLERÝ MENÜSÜ *|      |" << endl;
	cout << "|      |----------------------------|      |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz Çýkar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu Öðren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu Deðiþtir         |" << endl;
	cout << "| 5 = Tüm Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Prizleri Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;


}

int odaLambalariMenusu(int& secenek, odalar& myOda) {
	string lambaEklemek;
basaDon:
	if (myOda.getOdaLampSayac() == 0) {
		//Lamba oluþturulmasý
		cout << "En az bir adet lamba oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba oluþturmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme menüsüne aktarýyorum...... " << endl << endl;
			myOda.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|      |-----------------------------|     |" << endl;
	cout << "|      |* ODANIZIN LAMBALARI MENÜSÜ *|     |" << endl;
	cout << "|      |-----------------------------|     |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba Çýkar                          |" << endl;
	cout << "| 3 = Bir Lambanýn Durumunu Öðren          |" << endl;
	cout << "| 4 = Bir Lambanýn Durumunu Deðiþtir       |" << endl;
	cout << "| 5 = Tüm Lambalarý Listele                |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Lambalarý Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int odalarMenusu(int& secenek, odalar& myOda, home* pGuvenlik) {

	pGuvenlik = &myOda;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|           |-------------------|          |" << endl;
	cout << "|           |* ODANIZIN MENÜSÜ *|          |" << endl;
	cout << "|           |-------------------|          |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Aydýnlatmalar                        |" << endl;
	cout << "| 3 = Tüm Bileþenler                       |" << endl;
	cout << "| 4 = Oda Adýný Deðiþtirme                 |" << endl;
	cout << "| 5 = Odanýn Güvenlik Durumu               |" << endl;
	cout << "| 6 = Odanýn Sýcaklýk ve Nem Durum         |" << endl;
	cout << "| 7 = Odadaki Diðer Bileþenler             |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		odaPrizleriMenusu(secenek, myOda);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Aydýnlatmalar Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		odaLambalariMenusu(secenek, myOda);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myOda.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Listelendi. Oda Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Oda Adý Deðiþim Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		odaAdiDegistirme(myOda);
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Odanýn Güvenlik Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Odanýn Sýcaklýk ve Nem Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		sicaklikKontrolMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Odadaki Diðer Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
	bilesenBasaDon:
		cout << "--------------------------------------------" << endl;
		cout << "|            Akýllý Ev Sistemleri          |" << endl;
		cout << "|   |-----------------------------------|  |" << endl;
		cout << "|   |* ODADAKÝ DÝÐER BÝLEÞENLER MENÜSÜ *|  |" << endl;
		cout << "|   |-----------------------------------|  |" << endl;
		cout << "| 1 = Perde                                |" << endl;
		cout << "| 2 = Klima                                |" << endl;
		cout << "| 3 = Saksý                                |" << endl;
		cout << "| 4 = Odanýzýn Ana Menüsü                  |" << endl;
		cout << "| 0 = Ana Menü                             |" << endl;
		cout << "|                                          |" << endl;
		cout << "--------------------------------------------" << endl << endl << endl;

	x:
		cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
		cin >> secenek;
		try {
			if (cin.fail())
				throw 101;
		}
		catch (int hatakodu) {
			if (hatakodu == 101) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
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
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

int odaIslemleriMenusu(int& secenek, map<int, odalar>& mOda,home *pGuvenlik) {
	int odaSorgu;
	auto it = mOda.find(odaSorgu);
basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "|           |* ODALAR MENÜSÜ *|            |" << endl;
	cout << "|           |-----------------|            |" << endl;
	cout << "| 1 = Oda Ekle                             |" << endl;
	cout << "| 2 = Odaya Git                            |" << endl;
	cout << "| 3 = Odalarý Listele                      |" << endl;
	cout << "| 4 = Odayý Sil                            |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}
	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Oda Ekle Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		odaEkleme(mOda);
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Odaya Git Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		if (odaSayac == 1) {
			cout << "\n Hiç Oda Oluþturulmamýþ! Lütfen önce oda oluþturunuz...\n\n";
			goto basaDon;
		}
		odaListeleme(mOda);
		cout << "\nÝçerisine girmek istediginiz oda ID: ";
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
		cout << "/*/*/*/*/*/---> Oda Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		odaListeleme(mOda);
		cout << "/*/*/*/*/*/---> Tüm Odalar Listelendi. Odalar Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Oda Silme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		if (odaSayac == 1) {
			cout << "\n Hiç Oda Oluþturulmamýþ! Lütfen önce oda oluþturunuz...\n\n";
			goto basaDon;
		}
		odaListeleme(mOda);
		cout << "\nSilmek istediðiniz Oda ID: ";
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
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

void banyoAdiDegistirme(banyo& myBanyo) {
	string newBanyoAdi;
	cout << "Lütfen banyonuza yeni adýný giriniz: ";
	cin.ignore();
	getline(cin, newBanyoAdi);
	myBanyo.setBanyoAdi(newBanyoAdi);
	cout << "Banyonuzun adý " << myBanyo.getBanyoAdi() << " olarak deðiþtirilmiþtir." << endl;
	cout << "/*/*/*/*/*/---> Banyo Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
}

int banyoPrizleriMenusu(int& secenek, banyo& myBanyo) {
	string prizEkelemek;
basaDon:
	if (myBanyo.getBanyoPrizSayac() == 0) {
		//Priz oluþturulmasý
		cout << "En az bir adet priz oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz oluþturmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme menüsüne aktarýyorum...... " << endl << endl;
			myBanyo.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |-------------------------|        |" << endl;
	cout << "|       |* BANYO PRÝZLERÝ MENÜSÜ *|        |" << endl;
	cout << "|       |-------------------------|        |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz Çýkar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu Öðren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu Deðiþtir         |" << endl;
	cout << "| 5 = Tüm Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Prizleri Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int banyoLambalariMenusu(int& secenek, banyo& myBanyo) {
	string lambaEklemek;
basaDon:
	if (myBanyo.getBanyoLampSayac() == 0) {
		//Lamba oluþturulmasý
		cout << "En az bir adet lamba oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba oluþturmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme menüsüne aktarýyorum...... " << endl << endl;
			myBanyo.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "|       |* BANYO LAMBALARI MENÜSÜ *|       |" << endl;
	cout << "|       |--------------------------|       |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba Çýkar                          |" << endl;
	cout << "| 3 = Bir Lambanýn Durumunu Öðren          |" << endl;
	cout << "| 4 = Bir Lambanýn Durumunu Deðiþtir       |" << endl;
	cout << "| 5 = Tüm Lambalarý Listele                |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Lambalarý Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int banyoMenusu(int& secenek, banyo& myBanyo,home* pGuvenlik) {
	static int banyoOlusturulmusMu = 0;
	if (banyoOlusturulmusMu == 0) {
		string banyoAdi;
		//Banyo oluþturulmasý
		cout << "Öncelikle bir Banyo oluþturmanýz gerekiyor." << endl;
		cout << "Lütfen banyonuza bir isim veriniz: ";
		cin.ignore();
		getline(cin, banyoAdi);
		cout << endl;
		myBanyo.setBanyoAdi(banyoAdi);
		banyoOlusturulmusMu = 1;
	}

	pGuvenlik = &myBanyo;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|           |----------------|             |" << endl;
	cout << "|           |* BANYO MENÜSÜ *|             |" << endl;
	cout << "|           |----------------|             |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Aydýnlatmalar                        |" << endl;
	cout << "| 3 = Tüm Bileþenler                       |" << endl;
	cout << "| 4 = Banyo Adýný Deðiþtirme               |" << endl;
	cout << "| 5 = Banyonun Güvenlik Durumu             |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		banyoPrizleriMenusu(secenek, myBanyo);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Aydýnlatmalar Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		banyoLambalariMenusu(secenek, myBanyo);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myBanyo.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Listelendi. Salon Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Banyo Adý Deðiþim Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		banyoAdiDegistirme(myBanyo);
		goto basaDon;
	case 5:
		cout << "/*/*/*/*/*/---> Banyonun Güvenlik Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

void tuvaletAdiDegistirme(tuvalet& myTuvalet) {
	string newTuvaletAdi;
	cout << "Lütfen tuvaletinize yeni adýný giriniz: ";
	cin.ignore();
	getline(cin, newTuvaletAdi);
	myTuvalet.setTuvaletAdi(newTuvaletAdi);
	cout << "Tuvaletinizin adý " << myTuvalet.getTuvaletAdi() << " olarak deðiþtirilmiþtir." << endl;
	cout << "/*/*/*/*/*/---> Tuvalet Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
}

int tuvaletPrizleriMenusu(int& secenek, tuvalet& myTuvalet) {
	string prizEkelemek;
basaDon:
	if (myTuvalet.getTuvaletPrizSayac() == 0) {
		//Priz oluþturulmasý
		cout << "En az bir adet priz oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz oluþturmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme menüsüne aktarýyorum...... " << endl << endl;
			myTuvalet.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "|       |* TUVALET PRÝZLERÝ MENÜSÜ *|      |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz Çýkar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu Öðren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu Deðiþtir         |" << endl;
	cout << "| 5 = Tüm Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Prizleri Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int tuvaletLambalariMenusu(int& secenek, tuvalet& myTuvalet) {
	string lambaEklemek;
basaDon:
	if (myTuvalet.getTuvaletLampSayac() == 0) {
		//Lamba oluþturulmasý
		cout << "En az bir adet lamba oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba oluþturmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme menüsüne aktarýyorum...... " << endl << endl;
			myTuvalet.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |----------------------------|     |" << endl;
	cout << "|       |* TUVALET LAMBALARI MENÜSÜ *|     |" << endl;
	cout << "|       |----------------------------|     |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba Çýkar                          |" << endl;
	cout << "| 3 = Bir Lambanýn Durumunu Öðren          |" << endl;
	cout << "| 4 = Bir Lambanýn Durumunu Deðiþtir       |" << endl;
	cout << "| 5 = Tüm Lambalarý Listele                |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Lambalarý Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int tuvaletMenusu(int& secenek, tuvalet& myTuvalet, home* pGuvenlik) {
	static int tuvaletOlusturulmusMu = 0;
	if (tuvaletOlusturulmusMu == 0) {
		string tuvaletAdi;
		//Tuvalet oluþturulmasý
		cout << "Öncelikle bir Tuvalet oluþturmanýz gerekiyor." << endl;
		cout << "Lütfen Tuvaletinize bir isim veriniz: ";
		cin.ignore();
		getline(cin, tuvaletAdi);
		cout << endl;
		myTuvalet.setTuvaletAdi(tuvaletAdi);
		tuvaletOlusturulmusMu = 1;
	}

	pGuvenlik = &myTuvalet;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|           |------------------|           |" << endl;
	cout << "|           |* TUVALET MENÜSÜ *|           |" << endl;
	cout << "|           |------------------|           |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Aydýnlatmalar                        |" << endl;
	cout << "| 3 = Tüm Bileþenler                       |" << endl;
	cout << "| 4 = Tuvalet Adýný Deðiþtirme             |" << endl;
	cout << "| 5 = Tuvaletin Güvenlik Durumu            |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		tuvaletPrizleriMenusu(secenek, myTuvalet);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Aydýnlatmalar Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		tuvaletLambalariMenusu(secenek, myTuvalet);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myTuvalet.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Listelendi. Salon Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Tuvalet Adý Deðiþim Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		tuvaletAdiDegistirme(myTuvalet);
		goto basaDon;
	case 5:
		cout << "/*/*/*/*/*/---> Tuvaletin Güvenlik Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

void koridorAdiDegistirme(koridor& myKoridor) {
	string newKoridorAdi;
	cout << "Lütfen koridorunuza yeni adýný giriniz: ";
	cin.ignore();
	getline(cin, newKoridorAdi);
	myKoridor.setKoridorAdi(newKoridorAdi);
	cout << "Koridorunuzun adý " << myKoridor.getKoridorAdi() << " olarak deðiþtirilmiþtir." << endl;
	cout << "/*/*/*/*/*/---> Koridor Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
}

int koridorPrizleriMenusu(int& secenek, koridor& myKoridor) {
	string prizEkelemek;
basaDon:
	if (myKoridor.getKoridorPrizSayac() == 0) {
		//Priz oluþturulmasý
		cout << "En az bir adet priz oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Priz oluþturmak istiyor musunuz?(y/n): ";
		cin >> prizEkelemek;
		if (prizEkelemek == "y" || prizEkelemek == "Y") {
			cout << "Sizi priz ekleme menüsüne aktarýyorum...... " << endl << endl;
			myKoridor.prizEkleme();
		}
		else if (prizEkelemek == "n" || prizEkelemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "|       |* KORÝDOR PRÝZLERÝ MENÜSÜ *|      |" << endl;
	cout << "|       |---------------------------|      |" << endl;
	cout << "| 1 = Priz Ekle                            |" << endl;
	cout << "| 2 = Priz Çýkar                           |" << endl;
	cout << "| 3 = Bir Prizin Durumunu Öðren            |" << endl;
	cout << "| 4 = Bir Prizin Durumunu Deðiþtir         |" << endl;
	cout << "| 5 = Tüm Prizleri Listele                 |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Priz Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Priz Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizCikartma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Prizin Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Prizleri Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizlerinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int koridorLambalariMenusu(int& secenek, koridor& myKoridor) {
	string lambaEklemek;
basaDon:
	if (myKoridor.getKoridorLampSayac() == 0) {
		//Lamba oluþturulmasý
		cout << "En az bir adet lamba oluþturmanýz gerekiyor." << endl;
	hataliTuslama:
		cout << "Lamba oluþturmak istiyor musunuz?(y/n): ";
		cin >> lambaEklemek;
		if (lambaEklemek == "y" || lambaEklemek == "Y") {
			cout << "Sizi lamba ekleme menüsüne aktarýyorum...... " << endl << endl;
			myKoridor.lambaEkleme();
		}
		else if (lambaEklemek == "n" || lambaEklemek == "N") {
			cout << "Sizi bir önceki menüye aktarýyorum...... " << endl << endl;
			return 9;
		}
		else {
			cout << "Hatalý tuþlama yaptýnýz! " << endl;
			goto hataliTuslama;
		}

	}

	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|       |----------------------------|     |" << endl;
	cout << "|       |* KORÝDOR LAMBALARI MENÜSÜ *|     |" << endl;
	cout << "|       |----------------------------|     |" << endl;
	cout << "| 1 = Lamba Ekle                           |" << endl;
	cout << "| 2 = Lamba Çýkar                          |" << endl;
	cout << "| 3 = Bir Lambanýn Durumunu Öðren          |" << endl;
	cout << "| 4 = Bir Lambanýn Durumunu Deðiþtir       |" << endl;
	cout << "| 5 = Tüm Lambalarý Listele                |" << endl;
	cout << "| 9 = Bir Önceki Menü                      |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Lamba Ekleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambaEkleme();
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Lamba Çýkarma Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambaCikarma();
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Öðrenme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambaDurumuSorgulama();
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Bir Lambanýn Durumunu Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambaDurumunuDegistirme();
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tüm Lambalarý Listeleme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.lambalarinListelenmesi();
		goto basaDon;
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Bir Önceki Menüye Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		return secenek;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ANA MENÜ=9,ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

int koridorMenusu(int& secenek, koridor& myKoridor, home* pGuvenlik) {
	static int koridorOlusturulmusMu = 0;
	if (koridorOlusturulmusMu == 0) {
		string koridorAdi;
		//Koridor oluþturulmasý
		cout << "Öncelikle bir Koridor oluþturmanýz gerekiyor." << endl;
		cout << "Lütfen Koridorunuza bir isim veriniz: ";
		cin.ignore();
		getline(cin, koridorAdi);
		cout << endl;
		myKoridor.setKoridorAdi(koridorAdi);
		koridorOlusturulmusMu = 1;
	}

	pGuvenlik = &myKoridor;

basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|           |------------------|           |" << endl;
	cout << "|           |* KORÝDOR MENÜSÜ *|           |" << endl;
	cout << "|           |------------------|           |" << endl;
	cout << "| 1 = Prizler                              |" << endl;
	cout << "| 2 = Aydýnlatmalar                        |" << endl;
	cout << "| 3 = Tüm Bileþenler                       |" << endl;
	cout << "| 4 = Koridor Adýný Deðiþtirme             |" << endl;
	cout << "| 5 = Koridorun Güvenlik Durumu            |" << endl;
	cout << "| 6 = Koridorun Sýcaklýk ve Nem Durumu     |" << endl;
	cout << "| 7 = Koridorun Saksý Menüsü               |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;
b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-4): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Prizler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		koridorPrizleriMenusu(secenek, myKoridor);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Aydýnlatmalar Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		koridorLambalariMenusu(secenek, myKoridor);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		myKoridor.prizlerinVeLambalarinListelenmesi();
		cout << "/*/*/*/*/*/---> Tüm Bileþenler Listelendi. Salon Menüsüne Aktarýlýyor <---/*/*/*/*/*/ " << endl << endl;
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Koridor Adý Deðiþim Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		koridorAdiDegistirme(myKoridor);
		goto basaDon;
	case 5:
		cout << "/*/*/*/*/*/---> Koridorun Güvenlik Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		guvenlikMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Koridorun Sýcaklýk ve Nem Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		sicaklikKontrolMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Koridorun Sýcaklýk ve Nem Durumu Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		saksiMenusu(secenek, pGuvenlik);
		if (secenek == 0) {
			return secenek;
		}
		goto basaDon;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-4 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

int kullaniciIslemleriMenusu(int& secenek,login& giris, home& evim, string& kullaniciAdi, string& parola, string& ad, string& soyad) {
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|        |-----------------------|         |" << endl;
	cout << "|        |* KULLANICI ÝÞLEMLERÝ *|         |" << endl;
	cout << "|        |-----------------------|         |" << endl;
	cout << "| 1 = Ev Adýný Deðiþtirme                  |" << endl;
	cout << "| 2 = Kullanýcý Adý ve Þifre Deðiþtirme    |" << endl;
	cout << "| 3 = Ad ve Soyad Deðiþtirme               |" << endl;
	cout << "| 0 = Ana Menü                             |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-5): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Evin Adýný Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		evAdiDegistirme(evim);
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Kullanýcý Adýný ve Þifresini Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		girisBilgisiDegistirme(giris, ad, soyad, kullaniciAdi, parola);
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Kullanýcý Ad ve Soyad Deðiþtirme Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		kullaniciAdSoyadDegistirme(giris, ad, soyad);
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-5 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;
}

void evdeBulunanHerseyinListesi(home& evim, mutfak& myMutfak, salon& mySalon, banyo& myBanyo,
	tuvalet& myTuvalet, koridor& myKoridor, map<int, odalar>& mOda) {
	cout << "\n\n\n-*-*-*-*-*-*-*-EVDE BULUNAN HERÞEYÝN DURUMLARI-*-*-*-*-*-*-*-\n\n\n";
	//Ev
	cout << "Evin Adý: " << evim.getHomeName() << endl << endl;
	tumEvinGuvenlikDurumlari(evim,myMutfak, mySalon, myBanyo, myTuvalet, myKoridor, mOda);
	//Mutfak
	cout << "\nMutfak Adý: " << myMutfak.getMutfakAdi() << endl;
	myMutfak.sicaklikVeNemDurum();
	myMutfak.prizlerinVeLambalarinListelenmesi();
	cout << "\nKombinizin durumu: ";
	if (myMutfak.getKombi() == 0) {
		cout << "Kapalý." << endl;
	}
	else if (myMutfak.getKombi() > 0) {
		cout << "Açýk ve " << myMutfak.getKombi() << " derece." << endl;
	}
	cout << "Perdenin Þuan ki Durumu: ";
	if (myMutfak.getPerdeDurum() == 0) {
		cout << "Perde kapalý!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 0 && myMutfak.getPerdeDurum() <= 250) {
		cout << "Perdenin neredeyse tamamý kapalý!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 250 && myMutfak.getPerdeDurum() <= 500) {
		cout << "Perde yarýya yakýn kapalý!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 500 && myMutfak.getPerdeDurum() <= 750) {
		cout << "Perdenin yarýdan fazlasý açýk!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 750 && myMutfak.getPerdeDurum() <= 999) {
		cout << "Perdenin neredeyse tamamý açýk!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() == 1000) {
		cout << "Perde açýk!" << endl << endl;
	}
	myMutfak.saksilarinListelenmesi();
	//Salon
	cout << "\nSalon Adý: " << mySalon.getSalonAdi() << endl;
	mySalon.sicaklikVeNemDurum();
	mySalon.prizlerinVeLambalarinListelenmesi();
	cout << "Perdenin Þuan ki Durumu: ";
	if (myMutfak.getPerdeDurum() == 0) {
		cout << "Perde kapalý!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 0 && myMutfak.getPerdeDurum() <= 250) {
		cout << "Perdenin neredeyse tamamý kapalý!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 250 && myMutfak.getPerdeDurum() <= 500) {
		cout << "Perde yarýya yakýn kapalý!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 500 && myMutfak.getPerdeDurum() <= 750) {
		cout << "Perdenin yarýdan fazlasý açýk!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() > 750 && myMutfak.getPerdeDurum() <= 999) {
		cout << "Perdenin neredeyse tamamý açýk!" << endl << endl;
	}
	else if (myMutfak.getPerdeDurum() == 1000) {
		cout << "Perde açýk!" << endl << endl;
	}
	cout << "Klimanýzýn Þuan ki Durumu: ";
	if (mySalon.getKlimaDurum() == 0) {
		cout << "Klima kapalý!" << endl << endl;
	}
	else if (mySalon.getKlimaDurum() > 0) {
		cout << "Klima açýk ve deðeri: " << mySalon.getKlimaDurum() << " derece." << endl << endl;
	}
	mySalon.saksilarinListelenmesi();
	//Odalar
	for (const auto& odalarim : mOda) {

		auto it = mOda.find(odalarim.first);
		odalar& myOda = it->second;
		cout << "\nOdanýn Adý: " << myOda.getOdaAdi() << endl;
		myOda.sicaklikVeNemDurum();
		myOda.prizlerinVeLambalarinListelenmesi();
		cout << "Perdenin Þuan ki Durumu: ";
		if (myOda.getPerdeDurum() == 0) {
			cout << "Perde kapalý!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() > 0 && myOda.getPerdeDurum() <= 250) {
			cout << "Perdenin neredeyse tamamý kapalý!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() > 250 && myOda.getPerdeDurum() <= 500) {
			cout << "Perde yarýya yakýn kapalý!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() > 500 && myOda.getPerdeDurum() <= 750) {
			cout << "Perdenin yarýdan fazlasý açýk!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() > 750 && myOda.getPerdeDurum() <= 999) {
			cout << "Perdenin neredeyse tamamý açýk!" << endl << endl;
		}
		else if (myOda.getPerdeDurum() == 1000) {
			cout << "Perde açýk!" << endl << endl;
		}
		cout << "Klimanýzýn Þuan ki Durumu: ";
		if (myOda.getKlimaDurum() == 0) {
			cout << "Klima kapalý!" << endl << endl;
		}
		else if (myOda.getKlimaDurum() > 0) {
			cout << "Klima açýk ve deðeri: " << myOda.getKlimaDurum() << " derece." << endl << endl;
		}
		myOda.saksilarinListelenmesi();
	}
	//Bayno
	cout << "\nBanyo Adý: " << myBanyo.getBanyoAdi() << endl;
	myBanyo.prizlerinVeLambalarinListelenmesi();
	//Tuvalet
	cout << "\nTuvalet Adý: " << myTuvalet.getTuvaletAdi() << endl;
	myTuvalet.prizlerinVeLambalarinListelenmesi();
	//Koridor
	cout << "\nKoridor Adý: " << myKoridor.getKoridorAdi() << endl;
	myKoridor.sicaklikVeNemDurum();
	myKoridor.prizlerinVeLambalarinListelenmesi();
	myKoridor.saksilarinListelenmesi();



}

int akilliEvSistemiAnaMenu(int& secenek, login& giris, home& evim, mutfak& myMutfak, salon& mySalon, map<int, odalar>& mOda, banyo& myBanyo,
	tuvalet& myTuvalet, koridor& myKoridor,home *pGuvenlik, string& kullaniciAdi, string& parola, string& ad, string& soyad) {
basaDon:
	cout << "--------------------------------------------" << endl;
	cout << "|            Akýllý Ev Sistemleri          |" << endl;
	cout << "|               |------------|             |" << endl;
	cout << "|               |* ANA MENÜ *|             |" << endl;
	cout << "|               |------------|             |" << endl;
	cout << "| 1 = Mutfak                               |" << endl;
	cout << "| 2 = Salon                                |" << endl;
	cout << "| 3 = Odalar                               |" << endl;
	cout << "| 4 = Banyo                                |" << endl;
	cout << "| 5 = Tuvalet                              |" << endl;
	cout << "| 6 = Koridorlar                           |" << endl;
	cout << "| 7 = Güvenlik                             |" << endl;
	cout << "| 8 = Evde bulunan herþey                  |" << endl;
	cout << "| 9 = Kullanýcý Ýþlemleri                  |" << endl;
	cout << "| 10 = Evcil Hayvan Durumu                 |" << endl;
	cout << "| 0 = Çýkýþ                                |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl << endl << endl;

	b:
	cout << "Lütfen kontrol etmek istediðiniz bölümü seçiniz(1-9): ";
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
			cout << "HATA! Girdiðiniz deðer bir SAYI deðil! \n";
			goto b;
		}
	}

	switch (secenek)
	{
	case 0:
		return secenek;
		break;
	case 1:
		cout << "/*/*/*/*/*/---> Mutfak Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		mutfakMenusu(secenek,myMutfak,pGuvenlik);
		goto basaDon;
		break;
	case 2:
		cout << "/*/*/*/*/*/---> Salon Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		salonMenusu(secenek,mySalon, pGuvenlik);
		goto basaDon;
		break;
	case 3:
		cout << "/*/*/*/*/*/---> Odalar Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		odaIslemleriMenusu(secenek, mOda, pGuvenlik);
		goto basaDon;
		break;
	case 4:
		cout << "/*/*/*/*/*/---> Banyo Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		banyoMenusu(secenek,myBanyo, pGuvenlik);
		goto basaDon;
		break;
	case 5:
		cout << "/*/*/*/*/*/---> Tuvalet Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		tuvaletMenusu(secenek,myTuvalet, pGuvenlik);
		goto basaDon;
		break;
	case 6:
		cout << "/*/*/*/*/*/---> Koridorlar Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		koridorMenusu(secenek, myKoridor, pGuvenlik);
		goto basaDon;
		break;
	case 7:
		cout << "/*/*/*/*/*/---> Güvenlik Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		tumEvinGuvenlikDurumlari(evim, myMutfak, mySalon, myBanyo, myTuvalet, myKoridor, mOda);
		goto basaDon;
		break;
	case 8:
		cout << "/*/*/*/*/*/---> Evde Bulunan Herþey Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		evdeBulunanHerseyinListesi(evim, myMutfak, mySalon, myBanyo, myTuvalet, myKoridor, mOda);
		break;
	case 9:
		cout << "/*/*/*/*/*/---> Kullanýcý Ýþlmeleri Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		while (secenek != 0) {
			kullaniciIslemleriMenusu(secenek, giris, evim, kullaniciAdi, parola, ad, soyad);
		}
		goto basaDon;
		break;
	case 10:
		cout << "/*/*/*/*/*/---> Evcil Hayvanlarým Bölümüne Aktarýlýyor <---/*/*/*/*/*/ " << endl;
		evcilHayvanMenusu(secenek, evim);
		goto basaDon;
		break;
	default:
		cout << "Yanlýþ bir tuþlama yaptýnýz! Lütfen 1-9 arasýnda bir sayý giriniz (ÇIKIÞ=0): ";
		goto a;
	}
	return secenek;

}

int main() {
	setlocale(LC_ALL, "Turkish");
	cout << "------------------------------------------------" << endl;
	cout << "|              Akýllý Ev Sistemleri            |" << endl;
	cout << "|                                              |" << endl;
	cout << "|                 * ANIL TUMER *               |" << endl;
	cout << "|                *  GhosTTymeR  *              |" << endl;
	cout << "|                                              |" << endl;
	cout << "|                                              |" << endl;
	cout << "------------------------------------------------" << endl << endl << endl;

	//Giriþ yaparken kullanýlan deðiþkenler
	string kullaniciAdi, parola, ad, soyad;
	//Ev oluþtururken kullanýlan deðiþkenler
	string evAdi;
	//Menülerde kullanýlacak deðiþkenler
	int secenek = 0; int cikis = 1;

	//Giriþ için bilgileri alma
	cout << "Lütfen adýnýzý giriniz: ";
	getline(cin, ad);
	cout << "Lütfen soyadýnýzý giriniz: ";
	cin >> soyad;
	cout << endl << endl << "Merhaba " << ad << " " << soyad << "." << endl;
	cout << "Lütfen kullanýcý adýnýzý giriniz: ";
	cin >> kullaniciAdi;
	cout << "Lütfen kullanýcý þifrenizi giriniz: ";
	cin >> parola;

	//Kullanýcý oluþturma 
	login giris(ad, soyad, kullaniciAdi, parola);

	//Ýlk giriþ için kullanýcý adý: ghost06, þifre:5462
	giris.girisYap();

	//Kullanýcý bilgilerinin ekrana yazdýrýlmasý
	cout << "Kullanýcý bilgileri: " << endl;
	cout << "AD--> " << giris.getAd() << endl << "SOYAD--> " << giris.getSoyad() << endl << "KULLNICI ADI--> " << giris.getId() << endl;
	cout << "PAROLA--> " << giris.getPassword() << endl;
	cout << endl << endl << endl;

	//Ev oluþumu
	cin.ignore();
	cout << "Lütfen evinize bir isim veriniz: ";
	getline(cin, evAdi);
	home evim(evAdi);

	//Default Ev Bölümlerinin Oluþturulmasý
	mutfak myMutfak("MUTFAK");
	salon mySalon("SALON");
	map<int, odalar> mOda;
	banyo myBanyo("BANYO");
	tuvalet myTuvalet("TUVALET");
	koridor myKoridor("KORÝDOR");

	//Evin Bölümlerinin Güvenlik Durumlarýný Tutacak Pointer
	home* pGuvenlik;
	pGuvenlik = &evim;

	//Ana Menümüzün Baþlatýlmasý
	while (cikis >= 1) {
		cikis = akilliEvSistemiAnaMenu
		(secenek, giris, evim, myMutfak, mySalon, mOda, myBanyo, myTuvalet, myKoridor, pGuvenlik, kullaniciAdi, parola, ad, soyad);
	}
	if (secenek == 0) {
		cout << endl << "Çýkýþ yapýlýyor..." << endl;
	}

	//Program kapanýrken son kontroller
	cout << endl << endl << endl;
	cout << "Çýkýþ bilgileri: " << endl;
	cout << "EV ADI--> " << evim.getHomeName() << endl;
	cout << "AD--> " << giris.getAd() << endl << "SOYAD--> " << giris.getSoyad() << endl << "KULLNICI ADI--> " << giris.getId() << endl;
	cout << "PAROLA--> " << giris.getPassword() << endl;
	cout << endl << endl << endl;
	cout << endl << endl << endl;
	
	return 0;
}