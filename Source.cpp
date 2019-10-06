#include<iostream>
using namespace std;

void print(int data[], int si)
{
	for (int i = 0; i < si; i++)
	{
		for (int j = 0; j < si - 1; j++)
		{
			if (data[j]>data[i]){
			int a = data[i];
			data[i] = data[j];
			data[j] = a;}
		}
	}
		for (int i = 0; i < si; i++)
		cout << data[i] << endl;
}

int main()
{
	int mass[10] = {1,2,3,3,6,8,2,3,5,3};
	int size = sizeof(mass) / sizeof(mass[0]);
	print(mass, size);
} 