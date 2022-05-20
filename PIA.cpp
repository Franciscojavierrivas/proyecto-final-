#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;


int Alta();
void listas();
void archivos();
void eliminar();
void modificar();

int alta,* precio;
string* nombre, *hora, *tratamiento;
int main()
{
	int opc;
	cout << "Menu principal\n\n";
	cout << "1.- Agedar cita(s)" << endl << "2.- Mostrar cita(s)" << endl << "3.- Limpiar pantalla" << endl << "4.- Modificar" << endl << "5.- Eliminar cita" << endl << "6.- Salir" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1:
		system("cls");
		alta=Alta();
		return main();
		break;
	case 2:
		system("cls");
		listas();
		return main();
		break;
	case 3:
		system("cls");
		return main();
		break;

	case 4:
		system("cls");
		modificar();
		return main();
		break;

	case 5:
		system("cls");
		eliminar();
		return main();
		break;

	case 6:
		system("cls");
		archivos();
		break;
	}
}
int Alta()
{
	int alta;
	cout << "Digite el num de citas que desea dar de alta" << endl;
	cin >> alta;
	nombre = new string[alta];
	tratamiento = new string[alta];
	precio = new int[alta];
	hora = new string[alta];
	for (int i = 0; i < alta; i++)
	{
		cout << "\tCita numero: " << i + 1 << endl;
		cout << "\nIngrese su nombre completo" << endl;
		cin.ignore();
		getline(cin,nombre[i]);
		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		cout << "Ingrese el Tratamiento" << endl;
		getline(cin, tratamiento[i]); //permite los espacios en el nombre
		cout << "Ingrese el precio del tratamiento" << endl;
		cin >> precio[i];
		cout << "Ingrese la hora(en formato de 24hrs)" << endl;
		cin >> hora[i];
			
		system("cls");
		cout << "Cita agendada\n";
	}
	return(alta);
}
void listas()
{
	if (alta != 0){
	for (int i = 0; i < alta; i++)
	{
		if (precio[i] == 0)
		{
			cout << "Cita: " << i + 1 << "Eliminada\n";
		}
		else
		{
			cout << "\n\tcita: " << i + 1 << endl;
			cout << "Nombre: "<<nombre[i] << endl;
			cout << "Tratamiento: "<<tratamiento[i] << endl;
			cout << "Precio: "<<precio[i] << endl;
			cout << "Hora: "<<hora[i] << endl;
		}
	}
	}
	else {
		cout << "no hay citas\n";
	}
}
void archivos()
{
	ofstream archivo("altascitas.txt");

	int texto_int;
	string texto_str;

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	for (int i = 0; i < alta; i++)
	{
		if (precio[i] == 0)
		{

		}
		else
		texto_str = nombre[i];
		archivo << texto_str<<endl;
		texto_str = tratamiento[i];
		archivo << texto_str<<endl;
		texto_int = precio[i];
		archivo << texto_int<<endl;
		texto_str = hora[i];
		archivo << texto_str<<endl;
	}
	archivo.close();
}
void eliminar()
{
	int j;
	cout << "ingrese el numero de la cita a eliminar";
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		cout << "Eliminando cita: " << j + 1 << endl;
		nombre[i] = " ";
		tratamiento[i] = " ";
		precio[i] = 0;
		hora[i] = " ";
		cout << "Cita eliminada\n\n";
	}
}
void modificar()
{
	int j, opcion;
	cout << "ingrese el numero registro a modificar";
	cin >> j;
	j = j - 1; // esto debido a que i inicia en 0
	cout << "ingrese que desea modificar\n 1.- Nombre\n 2.-Tratamiento\n 3.- Hora\n" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el nuevo nombre" << endl;
			getline(cin, nombre[i]);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el nuevo tratamiento" << endl;
			getline(cin, tratamiento[i]);
			cout << "Ingrese el nuevo precio" << endl;
			cin >> precio[i];
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese la nueva hora" << endl;
			getline(cin, hora[i]);
		}
	}
}