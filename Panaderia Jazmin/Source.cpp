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
		} while (cin >> tipoPan && tipoPan !=6);
		fseek(stdin, 0, SEEK_END);
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