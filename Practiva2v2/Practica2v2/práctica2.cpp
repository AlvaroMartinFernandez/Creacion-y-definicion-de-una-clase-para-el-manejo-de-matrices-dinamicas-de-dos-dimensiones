#include <cstdio>
#include "CMatFloat.h"
#include "utils.h"
#include "MemoryManager.h"
using namespace std;

int main() {
	{
		const char* menu[6] = { "Construir matriz 1D","Construir matriz 2D","Introducir Matriz","Mostrar Matriz","Destruir Matriz", "Terminar" };
		int funcion, nElementos, nFilas, nColumnas;
		CMatFloat Matriz;
		Matriz.Iniciar();
		while (1) {
			CrearMenu(menu, 6);
			funcion = LeerInt();
			switch (funcion) {
			case 1:
			{
				cout << "Introducir el numero de ELEMENTOS que queremos que tenga nuestra matriz" << endl;
				nElementos = LeerInt();
				Matriz.CrearMatriz1D(nElementos);
				break;
			}
			case 2:
			{
				cout << "Introducir el numero de FILAS que queremos que tenga nuestra matriz" << endl;
				nFilas = LeerInt();
				cout << "Introducir el numero de COLUMNAS que queremos que tenga nuestra matriz" << endl;
				nColumnas = LeerInt();
				Matriz.CrearMatriz2D(nFilas, nColumnas);
				break;
			}
			case 3:
			{
				if (Matriz.Existe())
					Matriz.Introducir();
				break;
			}
			case 4:
			{
				if (Matriz.Existe())
					Matriz.Mostrar();
				break;
			}
			case 5:
			{
				if (Matriz.Existe())
					Matriz.Destruir();
				break;
			}
			case 6:
			{
				if (Matriz.Existe())
					Matriz.Destruir();
				exit(1);
			}
			}
		}
	}
	MemoryManager::dumpMemoryLeaks();
}