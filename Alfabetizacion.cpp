#include <iostream>
#include <fstream>
#include "variables.h"

using namespace std;

// Definición de estructuras y variables globales
CUSTOMER customers[MAX_REG];
int pos = 0;

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
    ifstream archivoEntrada("customers.txt");
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
