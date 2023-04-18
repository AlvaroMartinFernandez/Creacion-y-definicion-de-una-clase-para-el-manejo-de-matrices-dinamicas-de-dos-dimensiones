#include <cstdio>
#include<cstdlib>
#include "CMatFloat.h"
#include "utils.h"
#include "MemoryManager.h"
using namespace std;

int main() {
	{
		const char *menu[6]{ "Construir matriz 1D","Construir matriz 2D","Introducir Matriz","Mostrar Matriz","Destruir Matriz", "Terminar" };
		int funcion = 0, nElementos, nFilas, nColumnas;
		CMatFloat matriz;
		matriz.Iniciar();
		while (funcion != 6) {
			CrearMenu(menu, 6);
			funcion = LeerInt();
			switch (funcion) {
			case 1:
			{
				cout << "Introducir el numero de ELEMENTOS que queremos que tenga nuestra matriz" << endl;
				nElementos = LeerInt();
				matriz.CrearMatriz1D(nElementos);
				break;
			}
			case 2:
			{
				cout << "Introducir el numero de FILAs que queremos que tenga nuestra matriz" << endl;
				nFilas = LeerInt();
				cout << "Introducir el numero de COLUMNAS que queremos que tenga nuestra matriz" << endl;
				nColumnas = LeerInt();
				matriz.CrearMatriz2D(nFilas, nColumnas);
				break;
			}
			case 3:
			{
				if (matriz.Existe())
					matriz.Introducir();
				break;
			}
			case 4:
			{
				if (matriz.Existe())
					matriz.Mostrar();
				break;
			}
			case 5:
			{
				if (matriz.Existe())
					matriz.Destruir();
				break;
			}
			case 6:
			{
				if (matriz.Existe())
					matriz.Destruir();
			}
			}
		}
	}
	MemoryManager::dumpMemoryLeaks();
}
