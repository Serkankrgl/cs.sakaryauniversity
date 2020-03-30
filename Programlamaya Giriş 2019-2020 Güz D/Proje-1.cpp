/****************************************************************************
**																			*
**				ÖÐRENCÝ ADI..................: Serkan Kuruoðlu				*
**				ÖÐRENCÝ NUMARASI.............:B181210050					*
**				DERS GRUBU...................:D								*
*****************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include <iomanip>
#include<Windows.h>
#include <cstdlib>

using namespace std;
//kordinat ayarlama fonksiyonu
void kord(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Ogrenci {

private:
	string name = "";
	string surname = "";
	int Number = 0;
public:
	//öðrenci isimni kontrol eder ve atama yapar
	void setName(string tempName)
	{
		name = tempName;
	};
	//öðrenci soyisimni kontrol eder ve atama yapar
	void setSurname(string tempSurname)
	{
		surname = tempSurname;
	};
	//öðrenci numarasýna kontrol eder ve atama yapar
	void setNumber()
	{
		Number = (rand() % 100) + 100;
	};
	//öðrenci verilerine atama yapar
	void setData(string tempName, string tempSurname, int tempNumb)
	{
		name = tempName;
		surname = tempSurname;
		Number = tempNumb;
	}
	//Öðrenci ismine ulaþmamýzý saðlar
	string getName()
	{
		return name;
	}
	//Öðrenci soyismine ulaþmamýzý saðlar
	string getSurname()
	{
		return surname;
	}
	//Öðrenci numarasýna ulaþmamýzý saðlar
	int getNumber()
	{
		return Number;
	}

};
class Sýnýf {
public:
	Ogrenci Ogrenciler[100];
	string sinifIsmi = "";
	int ogrenciSayisi = 0;
	//öðrenciler dizisine yeni öðrenci ekler
	void ogrenciEkle(Ogrenci EklencekOgrenci)
	{
		Ogrenciler[ogrenciSayisi] = EklencekOgrenci;
		ogrenciSayisi++;
	}
	//öðrenci dizisinden öðrenci siler
	void ogrenciSil(int öðrenciNumarsý)
	{
		//öðrencileri gezer ve numaralarý karþýlaþtýrýr
		for (int i = 0; i < ogrenciSayisi; i++)
		{
			//Numaralarý karþýlaþtýrýr
			if (Ogrenciler[i].getNumber() == öðrenciNumarsý)
			{
				//istenilen öðrenciden sonraki öðrenciler bir sýra öne gelir
				for (int j = i; j < ogrenciSayisi; j++)
				{
					Ogrenciler[j] = Ogrenciler[j + 1];
				}
				ogrenciSayisi--;
			}
		}
	}
};
class Okul {
public:
	Okul() {

		string tempName, tempSurname;
		int tempNumber;
		ifstream kayýtOku("kayitlar.txt");
		//dosyayý açýp açmadýmýzý kontrol eder
		if (kayýtOku)
		{
			//sýnýflarý gezer sýnýf ismi ve öðrenci numarasýný diziye alýr
			for (int i = 0; i < 20; i++)
			{

				kayýtOku >> siniflar[i].sinifIsmi;
				kayýtOku >> siniflar[i].ogrenciSayisi;
				//boþ olan sýnýf varmý kontrol edilir
				if (siniflar[i].sinifIsmi != "")
				{
					//sýnýfýn öðrencileri diziye alýnýr
					for (int j = 0; j < siniflar[i].ogrenciSayisi; j++)
					{
						kayýtOku >> tempName;
						kayýtOku >> tempSurname;
						kayýtOku >> tempNumber;

						siniflar[i].Ogrenciler[j].setData(tempName, tempSurname, tempNumber);
					}
					// kaç tane dolu sýnýf olduðunu sayar
					sinifSayisi += 1;
				}
			}
		}
		kayýtOku.close();
	}

	Sýnýf siniflar[20];
	int sinifSayisi = 0;

	int kordYBaslangic = 3;
	int kordXBaslangic = 0;

	const char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;
	//tablo için þekil fonksiyonlarý
	void ustYazdir(int elemanSayisi)
	{
		cout << solUstKose;

		for (int i = 0; i < elemanSayisi; i++)
		{
			cout << duz;
		}

		cout << sagUstKose;
	}
	void altYazdir(int elemanSayisi)
	{
		cout << solAltKose;

		for (int i = 0; i < elemanSayisi; i++)
		{
			cout << duz;
		}

		cout << sagAltKose;
	}
	//bir sýnýfý ve öðrencilerini siler
	void sýnýfSil(string seçSýnýf)
	{
		//sýnýflarý gezer
		for (int i = 0; i < 20; i++)
		{
			//sýnýf isimlerini karþýlaþtýrýr
			if (siniflar[i].sinifIsmi == seçSýnýf)
			{
				//seçilen sýnýfý kaldýrýp yerine üst sýnýflarý yerleþtirir
				for (int j = i; j < 19; j++)
				{
					siniflar[j] = siniflar[j + 1];
				}
				sinifSayisi--;
			}

		}

	}
	//verileri ekrana bastýrýr
	void tablo() {
		//baþlýk kýsýmlarýný oluþturur
		for (int i = 0; i < sinifSayisi; i++)
		{
			ustYazdir(12);
		}
		cout << endl;

		for (int i = 0; i < sinifSayisi; i++)
		{
			cout << dikey << setw(6) << siniflar[i].sinifIsmi << setw(7) << dikey;
		}
		cout << endl;

		for (int i = 0; i < sinifSayisi; i++)
		{
			altYazdir(12);
		}
		cout << endl;
		//sýnýflarý gezer
		for (int j = 0; j < sinifSayisi; j++)
		{
			//öðrencileri gezer ve verileri tablo halinde ekrana getirir
			for (int i = 0; i < siniflar[j].ogrenciSayisi; i++)
			{

				kord(kordXBaslangic, kordYBaslangic);
				ustYazdir(12);
				kordYBaslangic += 1;

				kord(kordXBaslangic, kordYBaslangic);
				cout << dikey << setw(12) << siniflar[j].Ogrenciler[i].getName() << dikey << endl;
				kordYBaslangic += 1;

				kord(kordXBaslangic, kordYBaslangic);
				cout << dikey << setw(12) << siniflar[j].Ogrenciler[i].getSurname() << dikey << endl;
				kordYBaslangic += 1;

				kord(kordXBaslangic, kordYBaslangic);
				cout << dikey << setw(12) << siniflar[j].Ogrenciler[i].getNumber() << dikey << endl;
				kordYBaslangic += 1;

				kord(kordXBaslangic, kordYBaslangic);
				altYazdir(12);
				kordYBaslangic += 1;

				kord(kordXBaslangic, kordYBaslangic);

			}
			kordXBaslangic += 14;
			kordYBaslangic = 3;
		}
		kordXBaslangic = 0;
	}
};
class Dosyayönetim {
public:

	string line1 = "";
	string line2 = "";
	//txt dosaysýndan isim seçer
	string isimGetir() {
		srand(time(0));
		int counter = 0;
		long int random = (((rand() % 100) * (rand() % 100) * (rand() % 100)) % 4945);

		ifstream dosya2("isimler.txt");

		if (dosya2)
		{
			while (getline(dosya2, line1, '\n'))
			{
				if (counter == random)
				{
					return line1;
				}
				counter++;
			}
			dosya2.close();
		}
		return line1;
	}
	//txt dosyasýndan soyism seçer 
	string soyisimGetir()
	{
		srand(time(0));

		int counter = 0;
		long int random = (rand() % 278);

		ifstream dosya3("soyisimler.txt");

		if (dosya3)
		{
			while (getline(dosya3, line2, '\n'))
			{
				if (counter == random)
				{
					return  line2;
				}
				counter++;
			}
			dosya3.close();
		}
	}
	//öðrenci verilerini txt dosyasýna kaydeder
	void kaydetOgrenci(Ogrenci ogrenci)
	{
		ofstream kayýt("temp.txt", ios::app);

		if (kayýt)
		{
			kayýt << ogrenci.getName() << "\t";
			kayýt << ogrenci.getSurname() << "\t";
			kayýt << ogrenci.getNumber() << "\n";
			cout << endl;
		}
		kayýt.close();
	}
	//Sýnýf verilerini txt dosyasýna kaydeder
	void kaydetSinif(Sýnýf sýnýf) {

		ofstream kayýt("temp.txt", ios::app);

		if (kayýt)
		{
			kayýt << sýnýf.sinifIsmi << endl;
			kayýt << sýnýf.ogrenciSayisi << endl;

			for (int i = 0; i < sýnýf.ogrenciSayisi; i++)
			{
				kaydetOgrenci(sýnýf.Ogrenciler[i]);

			}
		}
		kayýt.close();
	}

};
class Program {
private:
	Okul* okul = new Okul;
	Dosyayönetim DosyaYönet;

public:
	void Caliþtir() {

		int dongü = 1;
		while (dongü)
		{
			system("cls");
			okul->tablo();

			//Seçneklerin baþlama kordinatlarýný ayarlar
			if (okul->siniflar[0].ogrenciSayisi >= okul->siniflar[1].ogrenciSayisi)
				kord(0, 3 + okul->siniflar[0].ogrenciSayisi * 5);
			else
				kord(0, 3 + okul->siniflar[1].ogrenciSayisi * 5);


			int Seçenek;
			cout << "1.Ogrenci Ekle\n";
			cout << "2.Sinif Ekle\n";
			cout << "3.Ogrenci Degistir\n";
			cout << "4.Ogrenci Sil\n";
			cout << "5.Sinif Sil\n";
			cout << "6.Cikis\n";

			cin >> Seçenek;

			if (Seçenek == 1)
			{
				string sýnýfAdý;
				cout << "Sinif Adi giriniz...:\t";
				cin >> sýnýfAdý;
				//Sýnýflarý gezer
				for (int i = 0; i < 20; i++)
				{//Sýnýf isimlerini diðer isimlerle karþýlaþtýrýr
					if (sýnýfAdý == okul->siniflar[i].sinifIsmi)
					{
						Ogrenci temp;
						temp.setName(DosyaYönet.isimGetir());
						temp.setSurname(DosyaYönet.soyisimGetir());
						temp.setNumber();
						cout << "Ogrenci isimi...:\t" << temp.getName() << endl;
						cout << "Ogrenci soyisimi...:\t" << temp.getSurname() << endl;
						cout << "Ogrenci numarasý...:\t" << temp.getNumber() << endl;
						okul->siniflar[i].ogrenciEkle(temp);
						system("pause");

					}
				}
			};

			if (Seçenek == 2)
			{
				char ch = (rand() % 26) + 65;
				string tempSýnýfNumb = to_string(okul->sinifSayisi + 1);
				okul->siniflar[okul->sinifSayisi].sinifIsmi = tempSýnýfNumb + ch;
				okul->siniflar[okul->sinifSayisi].ogrenciSayisi = 0;
				okul->sinifSayisi++;
			};

			if (Seçenek == 3)
			{
				int TempNumb;
				cout << "Ogrenci Numarasi giriniz...:\t";
				cin >> TempNumb;
				//Sýnýflarý sayar
				for (int i = 0; i < 20; i++)
				{//Öðrencileri sayar
					for (int j = 0; j < okul->siniflar[i].ogrenciSayisi; j++)
					{//seçilen numarayý diðer numaralarla karþýlaþtýrýr
						if (TempNumb == okul->siniflar[i].Ogrenciler[j].getNumber())
						{
							Ogrenci temp;
							temp.setName(DosyaYönet.isimGetir());
							temp.setSurname(DosyaYönet.soyisimGetir());
							temp.setNumber();
							cout << "Ogrenci isimi...:\t" << temp.getName() << endl;
							cout << "Ogrenci soyisimi...:\t" << temp.getSurname() << endl;
							cout << "Ogrenci numarasý...:\t" << temp.getNumber() << endl;
							okul->siniflar[i].Ogrenciler[j] = temp;
							system("pause");

						}
					}
				}
			};

			if (Seçenek == 4)
			{
				int SeçNumber;
				cout << "Ogrenci Numarasi Giriniz...:\t";
				cin >> SeçNumber;
				//Sýnýflarý sayar
				for (int i = 0; i < 20; i++)
				{//Öðrencileri sayar
					for (int j = 0; j < okul->siniflar[i].ogrenciSayisi; j++)
					{//seçilen numarayý diðer numaralarla karþýlaþtýrýr
						if (okul->siniflar[i].Ogrenciler[j].getNumber() == SeçNumber)
						{
							okul->siniflar[i].ogrenciSil(SeçNumber);

						}
					}
				}
			};

			if (Seçenek == 5)
			{
				string SeçSýnýf;
				cout << "Sinif Adi Giriniz...:\t";
				cin >> SeçSýnýf;
				okul->sýnýfSil(SeçSýnýf);
			};

			if (Seçenek == 6)
			{
				for (int i = 0; i < okul->sinifSayisi; i++)
				{
					DosyaYönet.kaydetSinif(okul->siniflar[i]);

				}
				remove("kayitlar.txt");
				rename("temp.txt", "kayitlar.txt");
				dongü = 0;

			};
		}
	}
};
int main()
{
	Program program;
	program.Caliþtir();

}