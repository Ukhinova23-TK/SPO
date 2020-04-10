#include <iostream>
#include <Windows.h>
using namespace std;

struct App
{
	char name[100];
	char prouzvod[100];
	double razmer;
	double zena;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите количество программ: ";
	cin >> n;
	cin.ignore();
	App *Applications = new App[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите наименование программы " << i + 1 << ": ";
		cin.getline(Applications[i].name, 99);
		cout << "Введите наименование производителя программы " << i + 1 << ": ";
		cin.getline (Applications[i].prouzvod, 99);
		cout << "Введите размер на диске для программы (в Гб) " << i + 1 << ": ";
		cin >> Applications[i].razmer;
		cin.ignore();
		cout << "Введите цену прогаммы (в рублях) " << i + 1 << ": ";
		cin >> Applications[i].zena;
		cin.ignore();
	}
	char buf_name[100];
	char buf_prou[100];
	double buf_razm = 0;
	double buf_zena = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (strcmp(Applications[j].prouzvod, Applications[j + 1].prouzvod) > 0)
			{
				strcpy_s(buf_name, Applications[j].name);
				strcpy_s(Applications[j].name, Applications[j + 1].name);
				strcpy_s(Applications[j + 1].name, buf_name);
				for (int g = strlen(buf_name); g > 0; g--)
					buf_name[g] = '\0';

				strcpy_s(buf_prou, Applications[j].prouzvod);
				strcpy_s(Applications[j].prouzvod, Applications[j + 1].prouzvod);
				strcpy_s(Applications[j + 1].prouzvod, buf_prou);
				for (int g = strlen(buf_prou); g > 0; g--)
					buf_prou[g] = '\0';

				buf_razm = Applications[j].razmer;
				Applications[j].razmer = Applications[j + 1].razmer;
				Applications[j + 1].razmer = buf_razm;
				buf_razm = 0;

				buf_zena = Applications[j].zena;
				Applications[j].zena = Applications[j + 1].zena;
				Applications[j + 1].zena = buf_zena;
				buf_zena = 0;
			}
			if (strcmp(Applications[j].prouzvod, Applications[j + 1].prouzvod) == 0)
			{
				if (Applications[j].zena > Applications[j + 1].zena)
				{
					strcpy_s(buf_name, Applications[j].name);
					strcpy_s(Applications[j].name, Applications[j + 1].name);
					strcpy_s(Applications[j + 1].name, buf_name);
					for (int g = strlen(buf_name); g > 0; g--)
						buf_name[g] = '\0';

					buf_razm = Applications[j].razmer;
					Applications[j].razmer = Applications[j + 1].razmer;
					Applications[j + 1].razmer = buf_razm;
					buf_razm = 0;

					buf_zena = Applications[j].zena;
					Applications[j].zena = Applications[j + 1].zena;
					Applications[j + 1].zena = buf_zena;
					buf_zena = 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Программа " << i + 1 << endl;
		cout << "Наименование программы: " << Applications[i].name << endl;
		cout << "Наименование производителя программы: " << Applications[i].prouzvod << endl;
		cout << "Размер на диске для программы : " << Applications[i].razmer << " Гб" << endl;
		cout << "Цена программы: " << Applications[i].zena << " рублей" << endl;
		cout << endl;
	}
	return 0;
}