#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

void Create(const char* fName);
void Print(const char* fName);
void Process(const char* fName, const char* gName);

int main()
{
	Create("rand_numb.dat");
	Print("rand_numb.dat");
	Process("rand_numb.dat", "lg_numb.dat");
	Print("lg_numb.dat");
	return 0;
}
void Create(const char* fName)
{
	srand((unsigned)time(NULL));
	ofstream rand_numb(fName, ios::binary); // відкриття файлу для редагування
	int x;
	for (int i = 0; i < 40; i++) 
	{
		x = -30 + rand() % 100; // формування рандомних чисел від -30 до 100
		rand_numb.write((char*)&x, sizeof(x)); // запис цих чисел у бінарний файл
	}
	rand_numb.close();
}
void Print(const char* fName)
{
	cout << endl << "\nfile \"" << fName << "\":\n";
	ifstream rand_numb(fName, ios::binary); // відкриття файлу для читання
	int x;
	while (rand_numb.read((char*)&x, sizeof(x))) // поки файл не закінчився 
		cout << x << endl; // виводяться цифри, які записані в нього
	cout << endl;
	rand_numb.close();
}
void Process(const char* fName, const char* gName)
{ 
	ifstream rand_numb(fName, ios::binary); // читання файлу з цифрами 
	ofstream lg_numb(gName, ios::binary); // відкриття файлу для запису 
	int x;
	while (rand_numb.read((char*)&x, sizeof(x))) {
		if (x > 0 && x != 0) // провірка, чи може x бути аргументом lg, оскільки 0 і від'ємні числа не можуть бути аргументами,
			lg_numb.write((char*)&x, sizeof(x)); // то записуються тільки додатні числа 
	}
	rand_numb.close();
	lg_numb.close();
}