/********************************************
*     Öðrenci Adý: Serkan Kuruoðlu          *
*     Öðrenci Numarasý: B181210050          *
*     Ders Gurubu:	D                       *
*********************************************/
#include<iostream>
#include<Windows.h>

using namespace std;

int SekilCiz(int Satir, int Sutun);

int main() {
	int Satir, Sutun;

	do
	{
		cout << "Satir sayisi...: ";
		cin >> Satir;
		if (5 <= Satir && Satir <= 15) {  //satýr deðeri kontrol edilir.
			cout << "Sutun Sayisi...: ";
			cin >> Sutun;
			if ((5 <= Sutun <= 40) && (Sutun == (2 * Satir)))  // sütun deðeri kontrol ediliyor.
			{
				SekilCiz(Satir, Sutun); // figür oluþturulur ve döngüden çýkýlýr.
				break;
			}
			else {
				cout << "Sutun sayisi satir sayisinin 2 kati olmalidir.... Lutfen Tekrar Deneyiniz....\n";
			}
		}
		else {
			cout << "Satir sayisi 5 ve 15 arasinda olmalidir.... Lutfen Tekrar Deneyiniz....\n";
		}
	} while (true);
}

int SekilCiz(int Satir, int Sutun) {

	for (int SatirSay = 1; SatirSay <= (2 * Satir); SatirSay++) {           // satýrlarý oluþturur.
		for (int SutunSay = 1; SutunSay <= Sutun; SutunSay++) {             // sütunlarý oluþturur.
			if (SatirSay == (Satir + 1) || SatirSay == (2 * Satir) || SatirSay == 1 || SatirSay == Satir)          //Tamamen yýldýzdan oluþan satýrlarý yazdýrýr.
				cout << "*";
			if (SatirSay > 1 && SatirSay < Satir) {                         //þekilin ilk yarýsýný yazdýrýr.          

				if (SutunSay == 1 || SutunSay == ((Sutun / 2) - (SatirSay - 1)) || SutunSay == ((Sutun / 2) + SatirSay) || SutunSay == Sutun)  //1. satýr ile satýr deðeri arasýndaki yýldýzlarý yazdýrýr.
					cout << "*";
				else                                                        //yýldýzlar arasýndaki boþluklarý yazdýrýr.
					cout << " ";
			}

			else if (SatirSay > (Satir + 1) && SatirSay < Sutun) {               // þeklin ikinci yarýsýný yazdýrýr.

				if (SutunSay == 1 || SutunSay == (SatirSay - Satir) || SutunSay == (Sutun + 1) - (SatirSay - Satir) || SutunSay == Sutun)      //satýr deðerinin 1 fazlasý ile satýr deðerinin 2 katý arasýndaki yýldýzlarý yazdýrýr .      
					cout << "*";
				else                                                        //yýldýzlar arasýndaki boþluklarý yazdýrýr.
					cout << " ";
			}
		}
		cout << endl;
		Sleep(100);
	}
	system("pause");
	return 0;
}