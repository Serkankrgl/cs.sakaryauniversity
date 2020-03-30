/****************************************************************************
**��RENC� ADI............:Serkan Kuruo�lu
**��RENC� NUMARASI.......:B181210050
**DERS GRUBU.............:D
****************************************************************************/
#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;
const char style[] = { '+','#','*','@','$' };
//sahne yaps� tan�m�
struct Scene {
	int Scenex;
	int Sceney;
	char style;
};
//Sekil yap�s� tan�m�
struct FigureL {
	int x;
	int y;
	int dimention;
	char style;
};
//sahne ve �ekil yap�lar�na de�er atamas� yapar.
Scene CreatScene() {                  // sahnenin de�erlerini olu�turur.
	Scene Temp;
	int Tempx[] = { 30,40,50 };
	Temp.Scenex = Tempx[rand() % 3];
	Temp.Sceney = (rand() % 11) + 20;
	Temp.style = style[rand() % 5];
	return Temp;
}
FigureL CreatFirgureL() {             //L �eklinin de�erlerini olu�turur.
	FigureL Temp;
	Temp.x = rand() % 21 + 5;
	Temp.y = 3;
	Temp.dimention = rand() % 6 + 2;
	Temp.style = style[(rand() % 5)];
	return Temp;
}
//Fonksiyonlar�n tan�tlmas�
FigureL Shift(int counter, FigureL FigureL, Scene Scene);
void printSahne(Scene Scene);
void PrintFigure(FigureL FigurL);

int main() {
	srand(time(NULL));
	Scene Scene = CreatScene();
	FigureL FigureL = CreatFirgureL();
	int counter = 0;

	while (1) {               //i�lemin s�rekli devam etmesini sa�lar.
		system("cls");
		PrintFigure(FigureL);
		printSahne(Scene);
		FigureL = Shift(counter, FigureL, Scene);
		Sleep(100);
	}
}
//Kursor�n kordinatlar�n� ayarlamam�z� sa�layan fonksiyon.
void setCoord(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Sahne yap�s�n� basar.
void printSahne(Scene Scene) {
	for (int satir = 0; satir <= Scene.Sceney; satir++) {//sat�rlar�  gezer
		setCoord(0, satir);
		cout << Scene.style;                             //ilk sat�r� olu�turur.
		if (satir == 0 || satir == Scene.Sceney) {       //sahnenin sa� ve sol s�n�rlar�n� olu�turur.
			for (int sutun = 1; sutun <= Scene.Scenex; sutun++) {//sutular� sayar.
				cout << Scene.style;
			}
		}
		setCoord(Scene.Scenex, satir);
		cout << Scene.style;                             //sahnenin son sat�rn� olu�turur.
	}
}
//L fig�r�n� basar.
void PrintFigure(FigureL FigureL) {

	setCoord(FigureL.x, FigureL.y);
	for (int a = 0; a < 2 * FigureL.dimention + 1; a++) {                       //fig�r�n sat�rlar�n� gezer
		for (int b = 0; b < 2 * FigureL.dimention; b++) {                       //fig�r�n sutunlar�n� gezer
			if (b < (FigureL.dimention)) {                                    //Lseklinin �st taban�n� olu�turur.
				setCoord(FigureL.x + b, FigureL.y);
				cout << FigureL.style;
			}
			if (b >= (FigureL.dimention)) {
				setCoord(FigureL.x + b - 1, FigureL.y + (FigureL.dimention));    //Lseklinin orta taban�n� olu�turur.
				cout << FigureL.style;
			}
			if (a < (FigureL.dimention)) {

				setCoord(FigureL.x + FigureL.dimention - 1, FigureL.y + a);       //Lseklinin orta �izgisini olu�turur.
				cout << FigureL.style;
			}
			if (a > (FigureL.dimention)) {
				setCoord(FigureL.x + 2 * FigureL.dimention - 1, FigureL.y + a - 1);     //Lseklinin sa� �izgisini olu�turur.
				cout << FigureL.style;

			}
			if (a != 0 || a != (2 * FigureL.dimention - 4)) {                     //Lseklinin sol �izgisini olu�turur.
				setCoord(FigureL.x, FigureL.y + a);
				cout << FigureL.style;
			}
			setCoord(FigureL.x + b, FigureL.y + 2 * FigureL.dimention);             //Lseklinin alt taban�n� olu�turur.
			cout << FigureL.style;
		}

	}
}
//L �eklini 1 birim a�a�� kayd�r�r
FigureL Shift(int counter, FigureL FigureL, Scene Scene) {
	counter++;
	FigureL.y += counter;
	if (FigureL.y == Scene.Sceney - 2 * FigureL.dimention) {        //sahne sonuna geldi�inde ba�a geri d�nmesini sa�lar.
		counter = 0;
		FigureL = CreatFirgureL();                                     //sahne sonuna geldi�inde yeni �ekil olu�mas�n� sa�lar.
	}
	return FigureL;
}
