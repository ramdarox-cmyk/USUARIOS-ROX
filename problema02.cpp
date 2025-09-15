#include <iostream>

using namespace std;

int main() {
	int totalBajaGama = 0;
	int totalZonaB = 0; 
	int totalEfectivo = 0; 
	char opcion; 
	
	do {
		string nombre;
		string direccion;
		char tipoCelular;
		char tipoPago;
		char tipoCliente;
		int cantidad;
		char zona;
		
		cout << "Nombre del cliente: ";
		cin>>nombre;
		
		cout << "Dirección: ";
		cin>>direccion;
		
		
		do {
			cout << "Tipo de celular (A- Alta gama, M- Media gama, B-Baja gama): ";
			cin >> tipoCelular;
			
			if (tipoCelular != 'A' && tipoCelular != 'M' && tipoCelular != 'B') {
				cout << "Tipo de celular invalido" << endl;
			}
		} while (tipoCelular != 'A' && tipoCelular != 'M' && tipoCelular != 'B');
		
		
		do {
			cout << "Tipo de pago (E-Efectivo, C-Crédito): ";
			cin >> tipoPago;
			
			if (tipoPago != 'E' && tipoPago != 'C') {
				cout << "Tipo de pago invalido." << endl;
			}
		} while (tipoPago != 'E' && tipoPago != 'C');
		
		
		do {
			cout << "Tipo de cliente (E-Empresa, T-Tienda, B-Bodega): ";
			cin >> tipoCliente;
			
			if (tipoCliente != 'E' && tipoCliente != 'T' && tipoCliente != 'B') {
				cout << "Tipo de cliente invalido." << endl;
			}
		} while (tipoCliente != 'E' && tipoCliente != 'T' && tipoCliente != 'B');
		
		cout << "Cantidad: ";
		cin >> cantidad;
		
		
		do {
			cout << "Ingrese Zona (A, B, C, D): ";
			cin >> zona;
			
			if (zona != 'A' && zona != 'B' && zona != 'C' && zona != 'D') {
				cout << "Zona invalida." << endl;
			}
		} while (zona != 'A' && zona != 'B' && zona != 'C' && zona != 'D');
		
		
		int precio;
		if (tipoCelular == 'A') {
			precio = 4500;
		} else if (tipoCelular == 'M') {
			precio = 3500;
		} else {
			precio = 2500;
			totalBajaGama=totalBajaGama+1; 
		}
		
		int montoTotal = cantidad * precio;
		
		
		cout << "Monto total: " << montoTotal << endl;
		
		
		if (tipoPago == 'E') {
			totalEfectivo=totalEfectivo+1; 
		}
		
		
		if (zona == 'B') {
			totalZonaB=	totalZonaB+1; 
		}
		
		
		cout << "¿Desea continuar registrando clientes? (S/N): ";
		cin >> opcion;
	} while (opcion == 'S' || opcion == 's');
	
	
	cout << "\n     RESPUESTAS        " << endl;
	cout << "Numero de Registros de tipo celular B-Baja gama: " << totalBajaGama << endl;
	cout << "Numero Clientes registrados en Zona B: " << totalZonaB << endl;
	cout << "Numero Cantidad de tipo de pagos en Efectivo: " << totalEfectivo << endl;
	
	return 0;
}
