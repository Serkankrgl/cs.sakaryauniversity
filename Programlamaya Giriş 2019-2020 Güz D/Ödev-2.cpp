/****************************************************************************
*ÖÐRENCÝ ADI..........:Serkan Kuruoðlu
*ÖÐRENCÝ NUMARASI.....:b181210050
*DERS GRUBU...........:D
****************************************************************************/
#include<time.h>
#include <iostream>
using namespace std;                                                             //fonksiyonlarýn tanýmý.
void fill(int matris[25][25], int a);
void print(int matris[25][25], int a);
void optionone(int matris[25][25], int a);
void optiontwo(int matris[25][25], int a);
void optionthree(int matris[25][25], int a);
void optionfour(int matris[25][25], int a);
int main() {
	srand(time(NULL));
	int matris[25][25];
	int size, option = 1;
	while (option) {                                     //iþlemleri tekrarlar
		cout << "Matris Boyutunu Giriniz...:\t";
		cin >> size;
		if (size <= 25 && size >= 5) {                  //boyutun uygunluðu kontrol ediliyor
			fill(matris, size);
			while (true) {                             //iþlemleri tekrarlar
				print(matris, size);                   //yapýlacak iþlem menüsü ve seçimi.
				cout << "1.)Sutun Satir Degistir\n"
					<< "2.)Tekleri Basa Al (Satir)\n"
					<< "3.)Ters Cevir (Sutun)\n"
					<< "4.)Toplamlari Yazdir\n";
				cin >> option;
				if (option == 1)                     //1. iþlem
					optionone(matris, size);
				if (option == 2)                     //2. iþlem
					optiontwo(matris, size);
				if (option == 3)                     //3. iþlem
					optionthree(matris, size);
				if (option == 4)                     //4. iþlem
					optionfour(matris, size);
			}
		}
		else
			cout << "matris boyutu 5 ve 25 degerleri arasinda olmalidir\n";
	}
}
void fill(int matris[25][25], int size) { //Matris elemanlarýna rastgele sayý atama fonksiyonu
	for (int x = 0; x < size; x++)        //matristeki satýrlarý gezer
		for (int y = 0; y < size; y++)    // matristeki sutunlarý gezer
			matris[x][y] = (rand() % 9) + 1;
}
void print(int matris[25][25], int size) { //matrisi yazdýrma fonksionu
	cout << "\n";
	for (int x = 0; x < size + 2; x++) { //matristeki satýrlarý gezer
		if (x >= 2)
			cout << x - 1 << "|\t";     //satýr sayýsýný yazdýrýr
		for (int y = 0; y < size; y++) {// matristeki sutunlarý gezer
			if (x == 0)
				cout << " \t" << y + 1;  //sutun sayýsýný yazdýrýr
			else if (x == 1)
				cout << " \t__";
			else
				cout << matris[x - 2][y] << "\t"; // dizinin elemanlarýný yazdýrýr
		}
		cout << endl;
	}
}
void optionone(int matris[25][25], int size) {  // satý ve sutunu yer deðiþtirir ve yazdýrýr
	int row, column;
	cout << "Satir  Sutun\n";
	cin >> row >> column;
	if (row - 1 < size && column - 1 < size) {                                     // girilen deðerlerin uygunluðunu kontrol eder.
		int yedek1 = matris[column - 1][column - 1] + matris[row - 1][row - 1];
		int yedek2 = matris[row - 1][column - 1];
		for (int m = 0; m < size; m++) {          // satýr ve sutundaki deðerler yer deðiþtiriliyor
			int copymatris = matris[row - 1][m];
			matris[row - 1][m] = matris[m][column - 1];
			matris[m][column - 1] = copymatris;
		}
		if (row < column)                              //yer deðiþtirme sýrasýnda oluþan hata gideriliyor.
			matris[column - 1][column - 1] = yedek2;
		else
			matris[row - 1][row - 1] = yedek2;

		matris[row - 1][column - 1] = yedek1;
		print(matris, size);
		fill(matris, size);
	}
	else
		cout << "Gecersiz Satir veya Sutun Degeri Girdiniz" << endl;
}
void optiontwo(int matris[25][25], int size) {  //tekleri satýr baþýna yazdýrýr
	int row, counter1 = 0, counter2 = 0;
	int test_matris[25];
	cout << "Satir...:";
	cin >> row;
	if (row - 1 < size) {                                                   //girilen deðerlerin uygunluðunu kontrol eder.
		for (int m = 0; m < size; m++) {                                    //istenilen satýrdaki elemanlarý gezer.
			if (matris[row - 1][m] % 2 == 1) {                               //tek veya cift oldugu kontrol edilip test matrisine diziliyor
				test_matris[counter1] = matris[row - 1][m];
				counter1++;
			}
			else {
				test_matris[((size - 1) - counter2)] = matris[row - 1][m];
				counter2++;
			}
		}
		for (int c = 0; c < size; c++)                                      //test matrisi ana matrisin istenilen satýrýna sýralanýyor
			matris[row - 1][c] = test_matris[c];

		print(matris, size);
		fill(matris, size);
	}
	else
		cout << "girdiginiz deger matris boyutundan küçük olmalýdýr";
}
void optionthree(int matris[25][25], int size) { // sutunu tersten yazdýrýr
	int column, counter = 0;
	cout << "Sutun ...:";
	cin >> column;
	if (column - 1 < size) {                                  //girilen deðerlerin uygunluðunu kontrol eder
		for (int n = 0; n < size / 2; n++) {                  // istenilen sutunu sondan baþa doðru gezerek tersten kaydeder.
			int temp = matris[n][column - 1];
			matris[n][column - 1] = matris[size - 1 - n][column - 1];
			matris[size - 1 - n][column - 1] = temp;
		}
		print(matris, size);
		fill(matris, size);
	}
	else
		cout << "girdiginiz deger matris boyutundan küçük olmalýdýr";
}
void optionfour(int matris[25][25], int size) { // sayýlarýn toplamýndan sayýlarý çýkartýr ve yazdýrýr
	int total = 0;
	for (int x = 0; x < size; x++) {          // matris elemanlarýný toplar
		for (int y = 0; y < size; y++) {
			total += matris[x][y];
		}
	}
	matris[0][0] = total;
	for (int x = 0; x < size; x++) {            // toplamdan matris elemanlarýný çýkartýr ve matrise geri yazar
		for (int y = 0; y < size; y++) {
			if (x != 0 || y != 0) {             // (0,0) elemanýný deðiþtirilmemesini saðlar
				total -= matris[x][y];
				matris[x][y] = total;
			}
		}
	}
	print(matris, size);
	fill(matris, size);
}
