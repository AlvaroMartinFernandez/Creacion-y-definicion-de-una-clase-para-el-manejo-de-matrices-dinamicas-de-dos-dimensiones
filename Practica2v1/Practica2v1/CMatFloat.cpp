#include <cstdio>
#include <iostream>
#include "CMatFloat.h"
#include "Utils.h"
#include "MemoryManager.h"
using namespace std;

void CMatFloat::Iniciar() {
	m_nFilas = 0;
	m_nColumnas = 0;
	m_ppDatosF = NULL;
}

void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas){
	if (m_ppDatosF == NULL) {
		m_nFilas = nFilas;
		m_nColumnas = nColumnas;
		m_ppDatosF = new float* [m_nFilas];
		for (int i = 0; i < nFilas; i++)
			m_ppDatosF[i] = new float[m_nColumnas];
		Ceros();
	}
	else
		cout << "Ya tienes una matriz creada, no puedes crear otra" << endl << endl;
}
void CMatFloat::CrearMatriz1D(int nElementos) {
	if (m_ppDatosF == NULL) {
		m_nFilas = 1;
		m_nColumnas = nElementos;
		m_ppDatosF = new float* [m_nFilas];
		m_ppDatosF[0] = new float[m_nColumnas];
		Ceros();
	}
	else
		cout << "Ya tienes una matriz creada, no puedes crear otra" << endl;
}
void CMatFloat::Introducir() {
	int fila = 0, columna = 0;
	do {
		if (fila >= m_nFilas)
			cout << "ERROR, el numero de FILA es mas grande que el de la matriz" << endl;
		cout << "Introduce la fila en la que quieres introducir el valor (" << m_nFilas - 1 << "-0)" << endl;
		fila = LeerInt();
	} while ((fila >= m_nFilas)&&(fila<0));
	do {
		if (columna >= m_nColumnas)
			cout << "ERROR, el numero de COLUMNA es mas grande que el de la matriz" << endl;
		cout << "Introduce la columna en la que quieres introducir el valor (" << m_nColumnas - 1 << "-0)" << endl;;
		columna = LeerInt();
	} while (columna >= m_nColumnas);
	cout << "Introduce el valor que se quiere dar" << endl;
	m_ppDatosF[fila][columna] = LeerFloat();
}
void CMatFloat::Mostrar() {
	cout << "Nuestra matriz es:" << endl;
	for (int i = 0; i < m_nFilas; i++) {
		for (int j = 0; j < m_nColumnas; j++)
			cout << m_ppDatosF[i][j] << "\t";
		cout << endl;
	}
	cout << endl << endl;
};
void CMatFloat::Destruir() {
	{
		for (int i = 0; i < m_nFilas; i++)
			delete[] m_ppDatosF[i];
		delete[] m_ppDatosF;
		Iniciar();
	}
};
bool CMatFloat::Existe() {
	if (m_ppDatosF == NULL)
		return false;
	else
		return true;
};
void CMatFloat::Ceros() {
	for (int i = 0; i < m_nFilas; i++)
		for (int j = 0; j < m_nColumnas; j++)
			m_ppDatosF[i][j] = 0;
}