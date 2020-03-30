/****************************************************************************
**ÖÐRENCÝ ADI............:Serkan Kuruoðlu
**ÖÐRENCÝ NUMARASI.......:B181210050
**DERS GRUBU.............:D
****************************************************************************/
#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;
const char style[] = { '+','#','*','@','$' };
//sahne yapsý tanýmý
struct Scene {
	int Scenex;
	int Sceney;
	char style;
};
//Sekil yapýsý tanýmý
struct FigureL {
	int x;
	int y;
	int dimention;
	char style;
};
//sahne ve Þekil yapýlarýna deðer atamasý yapar.
Scene CreatScene() {                  // sahnenin deðerlerini oluþturur.
	Scene Temp;
	int Tempx[] = { 30,40,50 };
	Temp.Scenex = Tempx[rand() % 3];
	Temp.Sceney = (rand() % 11) + 20;
	Temp.style = style[rand() % 5];
	return Temp;
}
FigureL CreatFirgureL() {             //L þeklinin deðerlerini oluþturur.
	FigureL Temp;
	Temp.x = rand() % 21 + 5;
	Temp.y = 3;
	Temp.dimention = rand() % 6 + 2;
	Temp.style = style[(rand() % 5)];
	return Temp;
}
//Fonksiyonlarýn tanýtlmasý
FigureL Shift(int counter, FigureL FigureL, Scene Scene);
void printSahne(Scene Scene);
void PrintFigure(FigureL FigurL);

int main() {
	srand(time(NULL));
	Scene Scene = CreatScene();
	FigureL FigureL = CreatFirgureL();
	int counter = 0;

	while (1) {               //iþlemin sürekli devam etmesini saðlar.
		system("cls");
		PrintFigure(FigureL);
		printSahne(Scene);
		FigureL = Shift(counter, FigureL, Scene);
		Sleep(100);
	}
}
//Kursorün kordinatlarýný ayarlamamýzý saðlayan fonksiyon.
void setCoord(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Sahne yapýsýný basar.
void printSahne(Scene Scene) {
	for (int satir = 0; satir <= Scene.Sceney; satir++) {//satýrlarý  gezer
		setCoord(0, satir);
		cout << Scene.style;                             //ilk satýrý oluþturur.
		if (satir == 0 || satir == Scene.Sceney) {       //sahnenin sað ve sol sýnýrlarýný oluþturur.
			for (int sutun = 1; sutun <= Scene.Scenex; sutun++) {//sutularý sayar.
				cout << Scene.style;
			}
		}
		setCoord(Scene.Scenex, satir);
		cout << Scene.style;                             //sahnenin son satýrný oluþturur.
	}
}
//L figürünü basar.
void PrintFigure(FigureL FigureL) {

	setCoord(FigureL.x, FigureL.y);
	for (int a = 0; a < 2 * FigureL.dimention + 1; a++) {                       //figürün satýrlarýný gezer
		for (int b = 0; b < 2 * FigureL.dimention; b++) {                       //figürün sutunlarýný gezer
			if (b < (FigureL.dimention)) {                                    //Lseklinin üst tabanýný oluþturur.
				setCoord(FigureL.x + b, FigureL.y);
				cout << FigureL.style;
			}
			if (b >= (FigureL.dimention)) {
				setCoord(FigureL.x + b - 1, FigureL.y + (FigureL.dimention));    //Lseklinin orta tabanýný oluþturur.
				cout << FigureL.style;
			}
			if (a < (FigureL.dimention)) {

				setCoord(FigureL.x + FigureL.dimention - 1, FigureL.y + a);       //Lseklinin orta çizgisini oluþturur.
				cout << FigureL.style;
			}
			if (a > (FigureL.dimention)) {
				setCoord(FigureL.x + 2 * FigureL.dimention - 1, FigureL.y + a - 1);     //Lseklinin sað çizgisini oluþturur.
				cout << FigureL.style;

			}
			if (a != 0 || a != (2 * FigureL.dimention - 4)) {                     //Lseklinin sol çizgisini oluþturur.
				setCoord(FigureL.x, FigureL.y + a);
				cout << FigureL.style;
			}
			setCoord(FigureL.x + b, FigureL.y + 2 * FigureL.dimention);             //Lseklinin alt tabanýný oluþturur.
			cout << FigureL.style;
		}

	}
}
//L þeklini 1 birim aþaðý kaydýrýr
FigureL Shift(int counter, FigureL FigureL, Scene Scene) {
	counter++;
	FigureL.y += counter;
	if (FigureL.y == Scene.Sceney - 2 * FigureL.dimention) {        //sahne sonuna geldiðinde baþa geri dönmesini saðlar.
		counter = 0;
		FigureL = CreatFirgureL();                                     //sahne sonuna geldiðinde yeni þekil oluþmasýný saðlar.
	}
	return FigureL;
}
