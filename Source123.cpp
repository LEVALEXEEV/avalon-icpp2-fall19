#include <string>
#include <iostream>
#include "Extention.hpp"

using namespace ext;
using namespace std;

struct Student
{
	int Id;
	int Graid;
	string Name;
};

int main()
{
	int mas[] = { 0,1,2,3 };
	Student pls[4];
	for (int i = 0; i < 4; ++i)
	{
		int length = GetRandomValue(3, 6);
		char letter = GetRandomValue('A', 'Z');
		pls[i].Name += letter;
		for (int j = 1; j < length; ++j)
		{
			pls[i].Name += GetRandomValue('a', 'z');
		}
		pls[i].Id = GetRandomValue(1, 1000);
		pls[i].Graid = GetRandomValue(1, 100);
	}
	for (int i = 0; i < 4; i++) {
		cout << pls[mas[i]].Id << "      " << pls[mas[i]].Name << "      " << pls[mas[i]].Graid << endl;
	}
	cout << "Name: press 1" << endl;
	cout << "Id: press 2" << endl;
	cout << "Grade: press 3" << endl;
	int ch;
	int v;
	cin >> ch;
	if (ch == 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (pls[mas[i]].Name < pls[mas[j]].Name) {
					v = mas[j];
					mas[j] = mas[i];
					mas[i] = v;
				}
			}
		}
	}
	if (ch == 2) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (pls[mas[i]].Id <pls[mas[j]].Id) {
					v = mas[j];
					mas[j] = mas[i];
					mas[i] = v;
				}
			}
		}
	}
	if (ch == 3) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (pls[mas[i]].Graid < pls[mas[j]].Graid) {
					v = mas[j];
					mas[j] = mas[i];
					mas[i] = v;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		cout << pls[mas[i]].Id << "      " << pls[mas[i]].Name << "      " << pls[mas[i]].Graid << endl;
	}

}
