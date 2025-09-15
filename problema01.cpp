#include <iostream>

using namespace std;

int main() {
	int totalVitalicios = 0;
	int totalDepositos = 0; 
	int totalHijos34 = 0; 
	double montoAcumuladoMes = 0; 
	double montoAcumuladoSinHijos = 0; 
	double montoTotalVipMayores50 = 0; 
	int totalVipMayores50 = 0; 
	
	char opcion; 
	
	do {
		string nombre;
		char tipoSocio;
		int edad;
		int cantidadHijos;
		char formaPago;
		int cantidadCanchas;
		
		cout << "1. Registrar pago" << endl;
		cout << "2. Reportar" << endl;
		cout << "3. Salir" << endl;
		cout << "Ingrese una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1': {
			cout << "Nombre del socio: ";
			cin.ignore();
			getline(cin, nombre);
			
			
			do {
				cout << "Tipo de Socio (A- Vip, R-Regular, N-Nuevo, V-Vitalicio): ";
				cin >> tipoSocio;
				
				if (tipoSocio != 'A' && tipoSocio != 'R' && tipoSocio != 'N' && tipoSocio != 'V') {
					cout << "Tipo de Socio invalido." << endl;
				}
			} while (tipoSocio != 'A' && tipoSocio != 'R' && tipoSocio != 'N' && tipoSocio != 'V');
			
			
			do {
				cout << "Ingrese la edad del socio : ";
				cin >> edad;
				
				if (edad < 1 || edad > 110) {
					cout << "Edad invalida" << endl;
				}
			} while (edad < 1 || edad > 110);
			
			cout << "Cantidad de hijos del socio: ";
			cin >> cantidadHijos;
			
			
			do {
				cout << "Forma de pago (E-Efectivo, T-Tarjeta, D-Depósito): ";
				cin >> formaPago;
				
				if (formaPago != 'E' && formaPago != 'T' && formaPago != 'D') {
					cout << "Forma de pago invalida." << endl;
				}
			} while (formaPago != 'E' && formaPago != 'T' && formaPago != 'D');
			
			cout << "Cantidad de canchas a utilizar al mes: ";
			cin >> cantidadCanchas;
			
			
			double cuotaMensual = 0;
			double pagoAniversario = 0;
			double precioCanchas = 0;
			
			
			switch (tipoSocio) {
			case 'A':
				cuotaMensual = 90.00;
				pagoAniversario = cuotaMensual * 0.2;
				precioCanchas = 4.00;
				break;
			case 'R':
				cuotaMensual = 120.00;
				pagoAniversario = cuotaMensual * 0.25;
				precioCanchas = 6.00;
				break;
			case 'N':
				cuotaMensual = 170.00;
				pagoAniversario = cuotaMensual * 0.3;
				precioCanchas = 8.00;
				break;
			case 'V':
				cuotaMensual = 60.00;
				
				precioCanchas = 0.00; 
				break;
			}
			
			
			double montoPagar = cuotaMensual + pagoAniversario * cuotaMensual + cantidadCanchas * precioCanchas + cantidadHijos * 30.00;
			
			
			double montoIgv = montoPagar * 0.18;
			
			
			double totalMes = montoPagar + montoIgv;
			
			
			cout << "      RESULTADOS    " << endl;
			cout << "Monto a pagar: " << montoPagar << endl;
			cout << "Monto de IGV: " << montoIgv << endl;
			cout << "Total del mes: " << totalMes << endl;
			
			
			if (tipoSocio == 'V') {
				totalVitalicios=totalVitalicios+1;
			}
			
			if (formaPago == 'D') {
				totalDepositos=totalDepositos+1;
			}
			
			if (cantidadHijos >= 3 && cantidadHijos <= 4) {
				totalHijos34=totalHijos34+1;
			}
			
			montoAcumuladoMes =montoAcumuladoMes+ totalMes;
			
			if (cantidadHijos == 0) {
				montoAcumuladoSinHijos =montoAcumuladoSinHijos+ totalMes;
			}
			
			if (tipoSocio == 'A' && edad > 50) {
				montoTotalVipMayores50 =montoTotalVipMayores50+ totalMes;
				totalVipMayores50=totalVipMayores50+1;
			}
			
			break;
		}
		case '2':
			cout << "--- Reporte ---" << endl;
			cout << "Cantidad de Tipo de Socios Vitalicios: " << totalVitalicios << endl;
			cout << "Cantidad de pagos en Depósitos: " << totalDepositos << endl;
			cout << "Cantidad de hijos de socios con rangos entre 3-4: " << totalHijos34 << endl;
			cout << "Monto acumulado de ingresos al mes: " << montoAcumuladoMes << endl;
			cout << "Monto acumulado de registros de Socios sin hijos: " << montoAcumuladoSinHijos << endl;
			cout << "Monto promedio de registros de socios Vip con edad mayor a 50: ";
			if (totalVipMayores50 > 0) {
				cout << montoTotalVipMayores50 / totalVipMayores50 << endl;
			} else {
				cout << "N/A" << endl;
			}
			break;
		case '3':
			
			break;
		default:
			cout << "Opción invalida." << endl;
			break;
		}
		
		cout << endl;
		
	} while (opcion != '3');
	
	return 0;
}
