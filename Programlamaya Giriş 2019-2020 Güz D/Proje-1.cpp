/****************************************************************************
**																			*
**				��RENC� ADI..................: Serkan Kuruo�lu				*
**				��RENC� NUMARASI.............:B181210050					*
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
	//��renci isimni kontrol eder ve atama yapar
	void setName(string tempName)
	{
		name = tempName;
	};
	//��renci soyisimni kontrol eder ve atama yapar
	void setSurname(string tempSurname)
	{
		surname = tempSurname;
	};
	//��renci numaras�na kontrol eder ve atama yapar
	void setNumber()
	{
		Number = (rand() % 100) + 100;
	};
	//��renci verilerine atama yapar
	void setData(string tempName, string tempSurname, int tempNumb)
	{
		name = tempName;
		surname = tempSurname;
		Number = tempNumb;
	}
	//��renci ismine ula�mam�z� sa�lar
	string getName()
	{
		return name;
	}
	//��renci soyismine ula�mam�z� sa�lar
	string getSurname()
	{
		return surname;
	}
	//��renci numaras�na ula�mam�z� sa�lar
	int getNumber()
	{
		return Number;
	}

};
class S�n�f {
public:
	Ogrenci Ogrenciler[100];
	string sinifIsmi = "";
	int ogrenciSayisi = 0;
	//��renciler dizisine yeni ��renci ekler
	void ogrenciEkle(Ogrenci EklencekOgrenci)
	{
		Ogrenciler[ogrenciSayisi] = EklencekOgrenci;
		ogrenciSayisi++;
	}
	//��renci dizisinden ��renci siler
	void ogrenciSil(int ��renciNumars�)
	{
		//��rencileri gezer ve numaralar� kar��la�t�r�r
		for (int i = 0; i < ogrenciSayisi; i++)
		{
			//Numaralar� kar��la�t�r�r
			if (Ogrenciler[i].getNumber() == ��renciNumars�)
			{
				//istenilen ��renciden sonraki ��renciler bir s�ra �ne gelir
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
		ifstream kay�tOku("kayitlar.txt");
		//dosyay� a��p a�mad�m�z� kontrol eder
		if (kay�tOku)
		{
			//s�n�flar� gezer s�n�f ismi ve ��renci numaras�n� diziye al�r
			for (int i = 0; i < 20; i++)
			{

				kay�tOku >> siniflar[i].sinifIsmi;
				kay�tOku >> siniflar[i].ogrenciSayisi;
				//bo� olan s�n�f varm� kontrol edilir
				if (siniflar[i].sinifIsmi != "")
				{
					//s�n�f�n ��rencileri diziye al�n�r
					for (int j = 0; j < siniflar[i].ogrenciSayisi; j++)
					{
						kay�tOku >> tempName;
						kay�tOku >> tempSurname;
						kay�tOku >> tempNumber;

						siniflar[i].Ogrenciler[j].setData(tempName, tempSurname, tempNumber);
					}
					// ka� tane dolu s�n�f oldu�unu sayar
					sinifSayisi += 1;
				}
			}
		}
		kay�tOku.close();
	}

	S�n�f siniflar[20];
	int sinifSayisi = 0;

	int kordYBaslangic = 3;
	int kordXBaslangic = 0;

	const char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;
	//tablo i�in �ekil fonksiyonlar�
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
	//bir s�n�f� ve ��rencilerini siler
	void s�n�fSil(string se�S�n�f)
	{
		//s�n�flar� gezer
		for (int i = 0; i < 20; i++)
		{
			//s�n�f isimlerini kar��la�t�r�r
			if (siniflar[i].sinifIsmi == se�S�n�f)
			{
				//se�ilen s�n�f� kald�r�p yerine �st s�n�flar� yerle�tirir
				for (int j = i; j < 19; j++)
				{
					siniflar[j] = siniflar[j + 1];
				}
				sinifSayisi--;
			}

		}

	}
	//verileri ekrana bast�r�r
	void tablo() {
		//ba�l�k k�s�mlar�n� olu�turur
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
		//s�n�flar� gezer
		for (int j = 0; j < sinifSayisi; j++)
		{
			//��rencileri gezer ve verileri tablo halinde ekrana getirir
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
class Dosyay�netim {
public:

	string line1 = "";
	string line2 = "";
	//txt dosays�ndan isim se�er
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
	//txt dosyas�ndan soyism se�er 
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
	//��renci verilerini txt dosyas�na kaydeder
	void kaydetOgrenci(Ogrenci ogrenci)
	{
		ofstream kay�t("temp.txt", ios::app);

		if (kay�t)
		{
			kay�t << ogrenci.getName() << "\t";
			kay�t << ogrenci.getSurname() << "\t";
			kay�t << ogrenci.getNumber() << "\n";
			cout << endl;
		}
		kay�t.close();
	}
	//S�n�f verilerini txt dosyas�na kaydeder
	void kaydetSinif(S�n�f s�n�f) {

		ofstream kay�t("temp.txt", ios::app);

		if (kay�t)
		{
			kay�t << s�n�f.sinifIsmi << endl;
			kay�t << s�n�f.ogrenciSayisi << endl;

			for (int i = 0; i < s�n�f.ogrenciSayisi; i++)
			{
				kaydetOgrenci(s�n�f.Ogrenciler[i]);

			}
		}
		kay�t.close();
	}

};
class Program {
private:
	Okul* okul = new Okul;
	Dosyay�netim DosyaY�net;

public:
	void Cali�tir() {

		int dong� = 1;
		while (dong�)
		{
			system("cls");
			okul->tablo();

			//Se�neklerin ba�lama kordinatlar�n� ayarlar
			if (okul->siniflar[0].ogrenciSayisi >= okul->siniflar[1].ogrenciSayisi)
				kord(0, 3 + okul->siniflar[0].ogrenciSayisi * 5);
			else
				kord(0, 3 + okul->siniflar[1].ogrenciSayisi * 5);


			int Se�enek;
			cout << "1.Ogrenci Ekle\n";
			cout << "2.Sinif Ekle\n";
			cout << "3.Ogrenci Degistir\n";
			cout << "4.Ogrenci Sil\n";
			cout << "5.Sinif Sil\n";
			cout << "6.Cikis\n";

			cin >> Se�enek;

			if (Se�enek == 1)
			{
				string s�n�fAd�;
				cout << "Sinif Adi giriniz...:\t";
				cin >> s�n�fAd�;
				//S�n�flar� gezer
				for (int i = 0; i < 20; i++)
				{//S�n�f isimlerini di�er isimlerle kar��la�t�r�r
					if (s�n�fAd� == okul->siniflar[i].sinifIsmi)
					{
						Ogrenci temp;
						temp.setName(DosyaY�net.isimGetir());
						temp.setSurname(DosyaY�net.soyisimGetir());
						temp.setNumber();
						cout << "Ogrenci isimi...:\t" << temp.getName() << endl;
						cout << "Ogrenci soyisimi...:\t" << temp.getSurname() << endl;
						cout << "Ogrenci numaras�...:\t" << temp.getNumber() << endl;
						okul->siniflar[i].ogrenciEkle(temp);
						system("pause");

					}
				}
			};

			if (Se�enek == 2)
			{
				char ch = (rand() % 26) + 65;
				string tempS�n�fNumb = to_string(okul->sinifSayisi + 1);
				okul->siniflar[okul->sinifSayisi].sinifIsmi = tempS�n�fNumb + ch;
				okul->siniflar[okul->sinifSayisi].ogrenciSayisi = 0;
				okul->sinifSayisi++;
			};

			if (Se�enek == 3)
			{
				int TempNumb;
				cout << "Ogrenci Numarasi giriniz...:\t";
				cin >> TempNumb;
				//S�n�flar� sayar
				for (int i = 0; i < 20; i++)
				{//��rencileri sayar
					for (int j = 0; j < okul->siniflar[i].ogrenciSayisi; j++)
					{//se�ilen numaray� di�er numaralarla kar��la�t�r�r
						if (TempNumb == okul->siniflar[i].Ogrenciler[j].getNumber())
						{
							Ogrenci temp;
							temp.setName(DosyaY�net.isimGetir());
							temp.setSurname(DosyaY�net.soyisimGetir());
							temp.setNumber();
							cout << "Ogrenci isimi...:\t" << temp.getName() << endl;
							cout << "Ogrenci soyisimi...:\t" << temp.getSurname() << endl;
							cout << "Ogrenci numaras�...:\t" << temp.getNumber() << endl;
							okul->siniflar[i].Ogrenciler[j] = temp;
							system("pause");

						}
					}
				}
			};

			if (Se�enek == 4)
			{
				int Se�Number;
				cout << "Ogrenci Numarasi Giriniz...:\t";
				cin >> Se�Number;
				//S�n�flar� sayar
				for (int i = 0; i < 20; i++)
				{//��rencileri sayar
					for (int j = 0; j < okul->siniflar[i].ogrenciSayisi; j++)
					{//se�ilen numaray� di�er numaralarla kar��la�t�r�r
						if (okul->siniflar[i].Ogrenciler[j].getNumber() == Se�Number)
						{
							okul->siniflar[i].ogrenciSil(Se�Number);

						}
					}
				}
			};

			if (Se�enek == 5)
			{
				string Se�S�n�f;
				cout << "Sinif Adi Giriniz...:\t";
				cin >> Se�S�n�f;
				okul->s�n�fSil(Se�S�n�f);
			};

			if (Se�enek == 6)
			{
				for (int i = 0; i < okul->sinifSayisi; i++)
				{
					DosyaY�net.kaydetSinif(okul->siniflar[i]);

				}
				remove("kayitlar.txt");
				rename("temp.txt", "kayitlar.txt");
				dong� = 0;

			};
		}
	}
};
int main()
{
	Program program;
	program.Cali�tir();

}