#include <iostream>
#include "variables.h"
#include <string.h>
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
void principal();

// manejo de archivos
int loadCustomers();
void writeFile();

void addCustomer(CUSTOMER *customer) {
    customers[pos] = *customer;
    pos++;
    writeFile();
}

CUSTOMER findCustomer(int id) {
    CUSTOMER customer;
    for (int i = 0; i < pos; i++) {
        if (customers[i].id == id) {
            return customers[i];
        }
    }
    return customer;
}

int findPos(int id) {
    for (int i = 0; i < pos; i++) {
        if (customers[i].id == id) return i;
    }
    return -1;
}

void updateCustomer(CUSTOMER *customer, int id) {
    int position = findPos(id);
    strcpy(customers[position].email, customer->email);
    strcpy(customers[position].name, customer->name);
    strcpy(customers[position].telephone, customer->telephone);
    strcpy(customers[position].address, customer->address);
    strcpy(customers[position].date, customer->date);
    writeFile();
}

void destroyCustomer(int id) {
    int position = findPos(id);
    for (int i = position; i < pos - 1; ++i) {
        customers[i] = customers[i + 1];
    }
    pos--;
    writeFile();
}

int menu() {
    int op;
    pos = loadCustomers();
    cout << "Menu\n";
    cout << "1. Agregar \n";
    cout << "2. Editar \n";
    cout << "3. Eliminar\n";
    cout << "4. Mostrar Todos \n";
    cout << "5. Buscar \n";
    cout << "6. Salir\n";
    cout << "Opción: ";
    cin >> op;
    return op;
}

void principal() {
    int op;
    pos = loadCustomers();
    do {
        op = menu();
        switch (op) {
            case 1:
                pedirDato();
                break;
            case 2:
                editar();
                break;
            case 3:
                eliminar();
                break;
            case 4:
                mostrarTodo();
                break;
            case 5:
                buscarCustomer();
                break;
            case 6:
                cout << "Gracias...\n";
                break;
            default:
                cout << "Solo hay 6 opciones. \n";
                break;
        }
    } while (op != 6);
}

void pedirDato() {
    CUSTOMER customer;
    cout << "Datos del Cliente" << endl;
    cout << "ID: ";
    cin >> customer.id;
    if (findPos(customer.id) != -1) {
        cout << "Registro ya existe..." << endl;
        return;
    }
    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(customer.name, 30);
    cout << "CORREO: ";
    cin.getline(customer.email, 50);
    cout << "TELEFONO: ";
    cin.getline(customer.telephone, 15);
    cout << "DIRECCION: ";
    cin.getline(customer.address, 100);
    cout << "FECHA DE NACIMIENTO: ";
    cin.getline(customer.date, 20);
    addCustomer(&customer);
}

void mostrarTodo() {
    cout << "Mostrar Registros\n";
    for (int i = 0; i < pos; i++) {
        showData(customers[i]);
    }
}

void editar() {
    CUSTOMER customer;
    int id;
    cout << "ID: ";
    cin >> id;
    if (findPos(id) == -1) {
        cout << "Registro no existe..." << endl;
        return;
    }
    customer = findCustomer(id);
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(customer.name, 30);
    cout << "Correo: ";
    cin.getline(customer.email, 50);
    cout << "Telefono: ";
    cin.getline(customer.telephone, 15);
    cout << "Direccion: ";
    cin.getline(customer.address, 100);
    cout << "Fecha de nacimiento: ";
    cin.getline(customer.date, 20);

    updateCustomer(&customer, id);
    cout << "Registro actualizado...\n";
}

void eliminar() {
    int id = 0;
    if (pos == 0) {
        cout << "No hay nada que eliminar\n";
        return;
    }
    cout << "ID de cliente a eliminar: ";
    cin >> id;
    if (findPos(id) == -1) {
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
    if (findPos(id) == -1) {
        cout << "Registro no existe..." << endl;
        return;
    }

    CUSTOMER customer = findCustomer(id);
    int x = findPos(id);

    cout << "\nCliente #" << x + 1 << ":\n";
    showData(customer);
}

void showData(CUSTOMER &customer) {
    cout << "ID: " << customer.id << endl;
    cout << "Nombre: " << customer.name << endl;
    cout << "Correo: " << customer.email << endl;
    cout << "Telefono: " << customer.telephone << endl;
    cout << "Direccion: " << customer.address << endl;
    cout << "Fecha de nacimiento: " << customer.date << endl;
}

int loadCustomers() {
    ifstream archivo("customers.txt");
    if (archivo.fail()) {
        return 0;
    }
    int i = 0;
    while (archivo >> customers[i].id) {
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

void writeFile() {
    ofstream archivo("customers.txt");
    if (archivo.fail()) {
        cout << "No se puede abrir archivo" << endl;
        exit(1);
    }

    for (int i = 0; i < pos; ++i) {
        archivo << customers[i].id << endl;
        archivo << customers[i].name << endl;
        archivo << customers[i].email << endl;
        archivo << customers[i].telephone << endl;
        archivo << customers[i].address << endl;
        archivo << customers[i].date << endl;
    }

    archivo.close();
}

// la parte de Tony

// Función para comparar dos cadenas de caracteres
int compararNombres(const char* a, const char* b) {
    while (*a && *b && (*a == *b)) {
        ++a;
        ++b;
    }
    return *a - *b;
}

// Función para intercambiar dos clientes
void intercambiarClientes(CUSTOMER& a, CUSTOMER& b) {
    CUSTOMER temp = a;
    a = b;
    b = temp;
}

// Función para ordenar clientes alfabéticamente por nombre
void ordenarClientes() {
    ifstream archivoEntrada("customers_sorted.txt");
    if (!archivoEntrada) {
        cout << "Error al abrir el archivo customers.txt" << endl;
        return;
    }

    // Leer los clientes del archivo
    while (archivoEntrada >> customers[pos].id) {
        archivoEntrada.ignore();
        archivoEntrada.getline(customers[pos].name, sizeof(customers[pos].name));
        archivoEntrada.getline(customers[pos].email, sizeof(customers[pos].email));
        archivoEntrada.getline(customers[pos].telephone, sizeof(customers[pos].telephone));
        archivoEntrada.getline(customers[pos].address, sizeof(customers[pos].address));
        archivoEntrada.getline(customers[pos].date, sizeof(customers[pos].date));
        pos++;
    }
    archivoEntrada.close();

    // Ordenar clientes por nombre usando el algoritmo de selección
    for (int i = 0; i < pos - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < pos; ++j) {
            if (compararNombres(customers[j].name, customers[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            intercambiarClientes(customers[i], customers[minIndex]);
        }
    }

    // Escribir los clientes ordenados en el archivo
    ofstream archivoSalida("customers_sorted.txt");
    if (!archivoSalida) {
        cout << "Error al abrir el archivo customers_sorted.txt" << endl;
        return;
    }

    for (int i = 0; i < pos; ++i) {
        archivoSalida << customers[i].id << endl;
        archivoSalida << customers[i].name << endl;
        archivoSalida << customers[i].email << endl;
        archivoSalida << customers[i].telephone << endl;
        archivoSalida << customers[i].address << endl;
        archivoSalida << customers[i].date << endl;
    }

    archivoSalida.close();
}
