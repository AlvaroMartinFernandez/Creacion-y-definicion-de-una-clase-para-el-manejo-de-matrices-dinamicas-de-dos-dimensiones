#include <cstdio>
#include <iostream>
#include "CMatFloat.h"
#include "utils.h"
using namespace std;

void CMatFloat::Iniciar() {
	vector<vector<float> > Matriz;
}
void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas) {
	vector<vector<float> > Matriz(nFilas, vector<float>(nColumnas,0));
	m_ppDatosF = Matriz;
}
void CMatFloat::CrearMatriz1D(int nElementos) {
	vector<vector<float> > Matriz(1, vector<float>(nElementos,0));
	m_ppDatosF = Matriz;
}
void CMatFloat::Introducir() {
	int fila = 0, columna = 0;
	do {
		if (fila >= m_ppDatosF.size())
			cout << "ERROR, el numero de FILA es mas grande que el de la matriz" << endl;
		cout << "Introduce la fila en la que quieres introducir el valor (" << m_ppDatosF.size() - 1 << "-0)" << endl;
		fila = LeerInt();
	} while (fila >= m_ppDatosF.size());
	do {
		if (columna >= m_ppDatosF[0].size())
			cout << "ERROR, el numero de COLUMNA es mas grande que el de la matriz" << endl;
		cout << "Introduce la columna en la que quieres introducir el valor (" << m_ppDatosF[0].size() - 1 << "-0)" << endl;;
		columna = LeerInt();
	} while (columna >= m_ppDatosF[0].size());
	cout << "Introduce el valor que se quiere dar" << endl;
	m_ppDatosF[fila][columna] = LeerFloat();
}
void CMatFloat::Mostrar() {
	cout << "Nuestra matriz es:" << endl;
	for (int i = 0; i < m_ppDatosF.size(); i++) {
		for (int j = 0; j < m_ppDatosF[i].size(); j++)
			cout << m_ppDatosF[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}
void CMatFloat::Destruir() {
	vector<vector<float> > Matriz;
	m_ppDatosF = Matriz;
	Iniciar();
}
bool CMatFloat::Existe() {
	if (m_ppDatosF.size() == 0)
		return false;
	else
		return true;
}