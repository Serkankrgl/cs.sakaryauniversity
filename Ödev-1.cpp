/********************************************
*     ��renci Ad�: Serkan Kuruo�lu          *
*     ��renci Numaras�: B181210050          *
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
		if (5 <= Satir && Satir <= 15) {  //sat�r de�eri kontrol edilir.
			cout << "Sutun Sayisi...: ";
			cin >> Sutun;
			if ((5 <= Sutun <= 40) && (Sutun == (2 * Satir)))  // s�tun de�eri kontrol ediliyor.
			{
				SekilCiz(Satir, Sutun); // fig�r olu�turulur ve d�ng�den ��k�l�r.
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

	for (int SatirSay = 1; SatirSay <= (2 * Satir); SatirSay++) {           // sat�rlar� olu�turur.
		for (int SutunSay = 1; SutunSay <= Sutun; SutunSay++) {             // s�tunlar� olu�turur.
			if (SatirSay == (Satir + 1) || SatirSay == (2 * Satir) || SatirSay == 1 || SatirSay == Satir)          //Tamamen y�ld�zdan olu�an sat�rlar� yazd�r�r.
				cout << "*";
			if (SatirSay > 1 && SatirSay < Satir) {                         //�ekilin ilk yar�s�n� yazd�r�r.          

				if (SutunSay == 1 || SutunSay == ((Sutun / 2) - (SatirSay - 1)) || SutunSay == ((Sutun / 2) + SatirSay) || SutunSay == Sutun)  //1. sat�r ile sat�r de�eri aras�ndaki y�ld�zlar� yazd�r�r.
					cout << "*";
				else                                                        //y�ld�zlar aras�ndaki bo�luklar� yazd�r�r.
					cout << " ";
			}

			else if (SatirSay > (Satir + 1) && SatirSay < Sutun) {               // �eklin ikinci yar�s�n� yazd�r�r.

				if (SutunSay == 1 || SutunSay == (SatirSay - Satir) || SutunSay == (Sutun + 1) - (SatirSay - Satir) || SutunSay == Sutun)      //sat�r de�erinin 1 fazlas� ile sat�r de�erinin 2 kat� aras�ndaki y�ld�zlar� yazd�r�r .      
					cout << "*";
				else                                                        //y�ld�zlar aras�ndaki bo�luklar� yazd�r�r.
					cout << " ";
			}
		}
		cout << endl;
		Sleep(100);
	}
	system("pause");
	return 0;
}