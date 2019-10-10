#include<iostream>
using namespace std;


int main()
{	
	setlocale(LC_ALL, "");
	int masc[13];
	long int nom;
	int cono;
	cout << "Введите кол-во номеров" << endl;
	cin >> cono;	
	for (int i = 0; i < cono; i++) {
		int s = 0;
		cout << "Введите номер" << endl;
		cin >> nom;
		for (int j = 12; j >= 0; j--) {
			masc[j] = nom % 10;
			nom /= 10;
		}
		for (int k = 0; k < 12; k++) {
			if (k % 2 == 0)
				s += masc[k];
			else
				s += masc[k]* 3;
		}
		s %= 10;
		if (10 - s == masc[12])
			cout << "Номер действителен";
		else
			cout<<"Номер не действителен";
	}
} 