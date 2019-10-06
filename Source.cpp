#include<iostream>
using namespace std;


int main()
{	
	setlocale(LC_ALL, "");
	int masc[13];
	int nom;
	int cono;
	cout << "введите кол-во номеров" << endl;
	cin >> cono;	
	for (int i = 0; i < cono; i++) {
		int s = 0;
		int a = 10;
		cout << "введите номер" << endl;
		cin >> nom;
		for (int j = 0; j < 13; j++) {
			masc[j] = nom % 10;
			nom /= 10;
			cout <<masc[j]<<endl;
		}
		for (int k = 11; k >= 0; k--) {
			if (k % 2 == 0)
				s += masc[k];
			else
				s += masc[k] * 3;
		}
		s %= 10;
		cout << s;
		if (10 - s == masc[11])
			cout << "данный номер действителен";
		else
			cout<<"данный номер не действителен";
	}
} 