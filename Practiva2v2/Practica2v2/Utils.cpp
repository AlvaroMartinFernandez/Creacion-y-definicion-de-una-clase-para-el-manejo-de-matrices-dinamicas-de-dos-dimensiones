#include <cstdio>
#include <iostream>
#include "Utils.h"
#include <string>
using namespace std;

void CrearMenu(const char* opcionesmenu[], int num_opciones) {
	string* menu = new string[num_opciones];
	for (int i = 0; i < num_opciones; i++) {
		menu[i] = opcionesmenu[i];
		cout << i + 1 << " " << menu[i] << endl;
	}
	cout << endl;
}
int LeerInt()
{
	int error;
	int num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		if (error)
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "\nDebe introducir un número entero: ";
		}
	} while (error);
	cin.ignore(numeric_limits<int>::max(), '\n'); // eliminar '\n'
	return num;
}
float LeerFloat()
{
	float error;
	float num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		if (error)
		{
			cin.clear();
			cin.ignore(numeric_limits<float>::max(), '\n');
			cout << "\nDebe introducir un número entero: ";
		}
	} while (error);
	cin.ignore(numeric_limits<float>::max(), '\n'); // eliminar '\n'
	return num;
}
