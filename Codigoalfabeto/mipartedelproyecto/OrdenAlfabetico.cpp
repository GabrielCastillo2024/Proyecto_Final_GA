#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Tamaño máximo para los nombres de los clientes
const int MAX_NOMBRE = 100;

// Declaración de funciones
void copiarCadena(char* destino, const char* origen);
int compararCadenas(const char* a, const char* b);
int longitudCadena(const char* cadena);
std::vector<char*> leerClientes(const char* nombreArchivo);
void escribirClientes(const std::vector<char*>& clientes, const char* nombreArchivo);
void agregarCliente(const char* nombreCliente, const char* nombreArchivo);

// Función para copiar una cadena de caracteres
void copiarCadena(char* destino, const char* origen) {
    while (*origen) {
        *destino++ = *origen++;
    }
    *destino = '\0';
}

// Función para comparar dos cadenas de caracteres
int compararCadenas(const char* a, const char* b) {
    while (*a && (*a == *b)) {
        a++;
        b++;
    }
    return *(unsigned char*)a - *(unsigned char*)b;
}

// Función para calcular la longitud de una cadena de caracteres
int longitudCadena(const char* cadena) {
    const char* s = cadena;
    while (*s) {
        s++;
    }
    return s - cadena;
}

// Función para leer el archivo de clientes y devolver un vector de arrays de caracteres
std::vector<char*> leerClientes(const char* nombreArchivo) {
    std::vector<char*> clientes;
    std::ifstream archivo(nombreArchivo);
    char cliente[MAX_NOMBRE];

    while (archivo.getline(cliente, MAX_NOMBRE)) {
        if (longitudCadena(cliente) > 0) {
            char* nuevoCliente = new char[MAX_NOMBRE];
            copiarCadena(nuevoCliente, cliente);
            clientes.push_back(nuevoCliente);
        }
    }

    archivo.close();
    return clientes;
}

// Función para escribir el vector de clientes en el archivo ordenado
void escribirClientes(const std::vector<char*>& clientes, const char* nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    for (const auto& cliente : clientes) {
        archivo << cliente << std::endl;
    }

    archivo.close();
}

// Función principal para agregar un cliente y actualizar el archivo
void agregarCliente(const char* nombreCliente, const char* nombreArchivo) {
    std::vector<char*> clientes = leerClientes(nombreArchivo);
    char* nuevoCliente = new char[MAX_NOMBRE];
    copiarCadena(nuevoCliente, nombreCliente);
    clientes.push_back(nuevoCliente);

    std::sort(clientes.begin(), clientes.end(), [](const char* a, const char* b) {
        return compararCadenas(a, b) < 0;
    });

    escribirClientes(clientes, nombreArchivo);

    // Liberar memoria
    for (auto cliente : clientes) {
        delete[] cliente;
    }
}

// La función main está excluida, como se solicitó
