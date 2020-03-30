/****************************************************************************
*��RENC� ADI..........:Serkan Kuruo�lu
*��RENC� NUMARASI.....:b181210050
*DERS GRUBU...........:D
****************************************************************************/
#include<time.h>
#include <iostream>
using namespace std;                                                             //fonksiyonlar�n tan�m�.
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
	while (option) {                                     //i�lemleri tekrarlar
		cout << "Matris Boyutunu Giriniz...:\t";
		cin >> size;
		if (size <= 25 && size >= 5) {                  //boyutun uygunlu�u kontrol ediliyor
			fill(matris, size);
			while (true) {                             //i�lemleri tekrarlar
				print(matris, size);                   //yap�lacak i�lem men�s� ve se�imi.
				cout << "1.)Sutun Satir Degistir\n"
					<< "2.)Tekleri Basa Al (Satir)\n"
					<< "3.)Ters Cevir (Sutun)\n"
					<< "4.)Toplamlari Yazdir\n";
				cin >> option;
				if (option == 1)                     //1. i�lem
					optionone(matris, size);
				if (option == 2)                     //2. i�lem
					optiontwo(matris, size);
				if (option == 3)                     //3. i�lem
					optionthree(matris, size);
				if (option == 4)                     //4. i�lem
					optionfour(matris, size);
			}
		}
		else
			cout << "matris boyutu 5 ve 25 degerleri arasinda olmalidir\n";
	}
}
void fill(int matris[25][25], int size) { //Matris elemanlar�na rastgele say� atama fonksiyonu
	for (int x = 0; x < size; x++)        //matristeki sat�rlar� gezer
		for (int y = 0; y < size; y++)    // matristeki sutunlar� gezer
			matris[x][y] = (rand() % 9) + 1;
}
void print(int matris[25][25], int size) { //matrisi yazd�rma fonksionu
	cout << "\n";
	for (int x = 0; x < size + 2; x++) { //matristeki sat�rlar� gezer
		if (x >= 2)
			cout << x - 1 << "|\t";     //sat�r say�s�n� yazd�r�r
		for (int y = 0; y < size; y++) {// matristeki sutunlar� gezer
			if (x == 0)
				cout << " \t" << y + 1;  //sutun say�s�n� yazd�r�r
			else if (x == 1)
				cout << " \t__";
			else
				cout << matris[x - 2][y] << "\t"; // dizinin elemanlar�n� yazd�r�r
		}
		cout << endl;
	}
}
void optionone(int matris[25][25], int size) {  // sat� ve sutunu yer de�i�tirir ve yazd�r�r
	int row, column;
	cout << "Satir  Sutun\n";
	cin >> row >> column;
	if (row - 1 < size && column - 1 < size) {                                     // girilen de�erlerin uygunlu�unu kontrol eder.
		int yedek1 = matris[column - 1][column - 1] + matris[row - 1][row - 1];
		int yedek2 = matris[row - 1][column - 1];
		for (int m = 0; m < size; m++) {          // sat�r ve sutundaki de�erler yer de�i�tiriliyor
			int copymatris = matris[row - 1][m];
			matris[row - 1][m] = matris[m][column - 1];
			matris[m][column - 1] = copymatris;
		}
		if (row < column)                              //yer de�i�tirme s�ras�nda olu�an hata gideriliyor.
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
void optiontwo(int matris[25][25], int size) {  //tekleri sat�r ba��na yazd�r�r
	int row, counter1 = 0, counter2 = 0;
	int test_matris[25];
	cout << "Satir...:";
	cin >> row;
	if (row - 1 < size) {                                                   //girilen de�erlerin uygunlu�unu kontrol eder.
		for (int m = 0; m < size; m++) {                                    //istenilen sat�rdaki elemanlar� gezer.
			if (matris[row - 1][m] % 2 == 1) {                               //tek veya cift oldugu kontrol edilip test matrisine diziliyor
				test_matris[counter1] = matris[row - 1][m];
				counter1++;
			}
			else {
				test_matris[((size - 1) - counter2)] = matris[row - 1][m];
				counter2++;
			}
		}
		for (int c = 0; c < size; c++)                                      //test matrisi ana matrisin istenilen sat�r�na s�ralan�yor
			matris[row - 1][c] = test_matris[c];

		print(matris, size);
		fill(matris, size);
	}
	else
		cout << "girdiginiz deger matris boyutundan k���k olmal�d�r";
}
void optionthree(int matris[25][25], int size) { // sutunu tersten yazd�r�r
	int column, counter = 0;
	cout << "Sutun ...:";
	cin >> column;
	if (column - 1 < size) {                                  //girilen de�erlerin uygunlu�unu kontrol eder
		for (int n = 0; n < size / 2; n++) {                  // istenilen sutunu sondan ba�a do�ru gezerek tersten kaydeder.
			int temp = matris[n][column - 1];
			matris[n][column - 1] = matris[size - 1 - n][column - 1];
			matris[size - 1 - n][column - 1] = temp;
		}
		print(matris, size);
		fill(matris, size);
	}
	else
		cout << "girdiginiz deger matris boyutundan k���k olmal�d�r";
}
void optionfour(int matris[25][25], int size) { // say�lar�n toplam�ndan say�lar� ��kart�r ve yazd�r�r
	int total = 0;
	for (int x = 0; x < size; x++) {          // matris elemanlar�n� toplar
		for (int y = 0; y < size; y++) {
			total += matris[x][y];
		}
	}
	matris[0][0] = total;
	for (int x = 0; x < size; x++) {            // toplamdan matris elemanlar�n� ��kart�r ve matrise geri yazar
		for (int y = 0; y < size; y++) {
			if (x != 0 || y != 0) {             // (0,0) eleman�n� de�i�tirilmemesini sa�lar
				total -= matris[x][y];
				matris[x][y] = total;
			}
		}
	}
	print(matris, size);
	fill(matris, size);
}
