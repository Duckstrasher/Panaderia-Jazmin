#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	
	char sentinel;
	string nombreTemp;
	vector<string> lista;
	vector<int> compraPorCliente;
	int contadorCliente = 0, tipoPan = 0, totalPanes = 0;
	cout << "Quieres registrar otro cliente?" << endl;
	cout << "(S)i" << endl;
	cout << "(N)o\t		Abandonar y ver resulatados" << endl;
	cin >> sentinel; cout << "\n";
	do {
		//si desde el pricipio se dice no, romper
		if (sentinel == 'n')
			break;
		cout << "Bienvenidos" << endl;
		cout << "Cual es su apellido?" << endl;
		cin >> nombreTemp;
		lista.push_back(nombreTemp);
		contadorCliente++;
		int contadorPan = 0;
		cout << nombreTemp << ", que pan desea adquirir? (CTRL + z para salir)" << endl;
		cout << "1-\tSemita Rellena" << endl;
		cout << "2-\tCacho" << endl;
		cout << "3-\tMargarita" << endl;
		cout << "4-\tConcha" << endl;
		cout << "5-\tQuesadilla" << endl;
		cin >> tipoPan;
		do {
			
			system("CLS");
			switch (tipoPan)
			{
			case 1:
				cout << "Usted eligió Semita Rellena" << endl;
				contadorPan++;
				break;
			case 2:
				cout << "Usted eligio Cacho" << endl;
				contadorPan++;
				break;
			case 3:
				cout << "Usted eligió Margarita" << endl;
				contadorPan++;
				break;
			case 4:
				cout << "Usted eligio Concha" << endl;
				contadorPan++;
				break;
			case 5:
				cout << "Usted eligio Quesadilla" << endl;
				contadorPan++;
				break;
			default:
				cout << "Lo sentimos, esa opcion no es valida" << endl;
				break;
			}

			cout << "Has elegido:\t	" << contadorPan << "panes" << endl;
			cout << nombreTemp << ", que pan desea adquirir? (CTRL + z para salir)" << endl;
			cout << "\n1-\tSemita Rellena" << endl;
			cout << "2-\tCacho" << endl;
			cout << "3-\tMargarita" << endl;
			cout << "4-\tConcha" << endl;
			cout << "5-\tQuesadilla" << endl;
			cout << "6-\tSalir" << endl;
			//mientras see lee algun dato para el tipo de pan y no eliga opcion 6
			// seguir preguntando si quiere algun pan
			// si la opcion no es valida, no se cuenta ningun pan
		} while (cin >> tipoPan && tipoPan !=6);

		fseek(stdin, 0, SEEK_END);
		//pushback hace que cada cliente tenga un elemento en el vector con el valor con el que salio del menu
		//por ejemplo si primerCliente hace 3 opciones, entonces compraPorCliente[0] = 3
		//segunda persona hace 8 opciones, entonces compraPorCliente[1] = 8 y asi...
		compraPorCliente.push_back(contadorPan);
		//se guarda la cantidad que cada quien compro en su respectivo elemento en el vector
		cout << nombreTemp << "coompro:\t" << compraPorCliente[contadorCliente - 1] << "panes" << endl;
		sentinel = 'n';
		cout << "\nQuieres registrar otro cliente?" << endl;
		cout << "(S)i" << endl;
		cout << "(N)o\t		Abandonar y ver resulatados" << endl;
		fseek(stdin, 0, SEEK_END);
		cin >> sentinel; cout << "\n";
		system("CLS");
	} while (sentinel == 'S' || sentinel == 's');
	//(N)o (no mas clientes) sale del sentinela
	//si hubo zero clientes solo omite lo de abajo, si no, trata de llamar elementos del vecotr que no existen
	if (contadorCliente == 0) {
		cout << "Hasta luego gracias por visitar" << endl;
	}
	else {
		//se calcula el total de panes comprados, mirando cuanto compró cada elemento (cliente) en la lista
		for (int i = 0; i < compraPorCliente.size(); i++) {
			totalPanes += compraPorCliente[i];
		}
		cout << "\n\nEl primer cliente fue:\t" << lista.front() << endl;
		cout << "El ultimo cliente fue:\t" << lista.back() << endl;
		cout << "Se atendieron a:\t" << contadorCliente << "clientes" << endl;
		cout << "El total de panes vendidos fue:\t" << totalPanes << "panes" << endl;
		cout << "\nHasta luego, gracias" << endl;
	}
	

	return 0;
}