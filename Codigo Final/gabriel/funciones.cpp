#include <iostream>
#include "variables.h"
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;


CUSTOMER customers[MAX_REG];
int pos = 0;

void addCustomer(CUSTOMER *customer);
CUSTOMER findCustomer(int id);
int findPos(int id);
void updateCustomer(CUSTOMER *customer, int id);
void destroyCustomer(int id);

void pedirDato();
void mostrarTodo();
void editar();
void eliminar();
void buscarCustomer();
void showData(CUSTOMER &customer);
int menu();
void MENU();

//manejo de archivos
int loadCustomers();
void writeFile(const CUSTOMER &customer);


void addCustomer(CUSTOMER *customer){
	customers[pos] = *customer;
	pos++;
}

CUSTOMER findCustomer(int id){
	CUSTOMER customer;
	for(int i = 0; i<pos; i++){
		if(customers[i].id == id){
			return customers[i];
		}
	}
	return customer;
}

int findPos(int id){
	for(int i = 0; i < pos; i++){
		if(customers[i].id == id) return i;
	}
	return -1;
}

void updateCustomer(CUSTOMER *customer, int id){
	int position = findPos(id);
	strcpy(customers[position].email, customer->email);
	strcpy(customers[position].name, customer->name);
	strcpy(customers[position].telephone, customer->telephone);
	strcpy(customers[position].address, customer->address);
	strcpy(customers[position].date, customer->date);
}

void destroyCustomer(int id){
	int position = findPos(id);
	for(int i = position; i<pos-1; i++){
		customers[i] = customers[i+1];
	}
	CUSTOMER c;
	customers[pos-1] = c;
	pos--;
}



void pedirDato(){
    CUSTOMER customer;
    
    cout << "Datos del Cliente" << endl;
    cout << "ID: ";
    cin >> customer.id;
    if(findPos(customer.id)!=-1){
        cout << "Registro ya existe..." << endl;
        return;
    }
    cout << "NOMBRE: ";
    scanf(" %[^\n]", customer.name);
    cout << "CORREO: ";
    scanf(" %[^\n]", customer.email);
    cout << "TELEFONO: ";
    scanf(" %[^\n]", customer.telephone);
    cout << "DIRECCION: ";
    scanf(" %[^\n]", customer.address);
    cout << "FECHA DE NACIMIENTO: ";
    scanf(" %[^\n]", customer.date);
    addCustomer(&customer);
    writeFile(customer);
  
}

void mostrarTodo(){
    
    cout << "Mostrar Registros\n";
    for(int i =0; i < pos; i++){
        showData(customers[i]);
    }
}

void editar(){
    CUSTOMER customer;
    int id;
    cout << "ID: ";
    cin >>id;
    if(findPos(id)==-1){
        cout << "Registro no existe..." << endl;
        return;
    }
    customer = findCustomer(id);
    cout << "Nombre: " ;
    scanf(" %[^\n]", customer.name);
    cout << "Correo: ";
    scanf(" %[^\n]", customer.email);
    cout << "Telefono: ";
    scanf(" %[^\n]", customer.telephone);
    cout << "Direccion: ";
    scanf(" %[^\n]", customer.address);
    cout << "Fecha de nacimiento: ";
    scanf(" %[^\n]", customer.date);
    
    updateCustomer(&customer, id);
    cout << "Registro actualizado...\n";
}

void eliminar() {
    int id = 0;
    if(pos == 0){
        cout << "No hay nada que eliminar\n";
        return;
    }
     cout << "ID de cliente a eliminar: ";
    cin >> id;
    if(findPos(id)==-1){
        cout << "Registro no existe..." << endl;
        return;
    }
    destroyCustomer(id);

    cout << "Cliente eliminado\n";
}

void buscarCustomer() {
    int id = 0;
    cout << "ID de cliente a buscar: ";
    cin >> id;
    if(findPos(id)==-1){
        cout << "Registro no existe..." << endl;
        return;
    }

    CUSTOMER customer = findCustomer(id);
    int x = findPos(id);

    cout << "\nCliente #" << x+1 << ":\n";
    showData(customer);
}

void showData(CUSTOMER &customer){

    cout << "ID: " << customer.id << endl;
    cout << "Nombre: " << customer.name << endl;
    cout << "Correo: " << customer.email << endl;
    cout << "Telefono: " << customer.telephone << endl;
    cout << "Direccion: " << customer.address << endl;
    cout << "Fecha de nacimiento: " << customer.date << endl;
 
}






int loadCustomers()
{
	ifstream archivo("customers.txt");
	if(archivo.fail()){
		return 0;
	}
	int i = 0;
	while(archivo >> customers[i].id)
	{
		archivo.ignore();
		archivo.getline(customers[i].name, 30);
		archivo.getline(customers[i].email, 50);
		archivo.getline(customers[i].telephone, 15);
		archivo.getline(customers[i].address, 100);
		archivo.getline(customers[i].date, 20);
		i++;
	}
	archivo.close();
	return i;
}


void writeFile(const CUSTOMER &customer)
{
	ofstream archivo;
	archivo.open("customers.txt", ios::app);
	
	if(archivo.fail())
	{
		cout << "No se puede abrir archivo" << endl;
		exit(1);
	}

	archivo << customer.id << endl;
	archivo << customer.name << endl;
	archivo << customer.email << endl;
	archivo << customer.address << endl;
	archivo << customer.date << endl;

	
}

//agregar funcionalidad de borrar y editar el archivo 
