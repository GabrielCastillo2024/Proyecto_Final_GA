#include <iostream>
#include "variables.h"

//funcion para buscar al cliente

CLIENTE buscarClientePorId(int idCliente, CLIENTE arrayClientes[], int numClientes) {
    CLIENTE clienteEncontrado;
    for (int i = 0; i < numClientes; i++) {
        if (arrayClientes[i].id == idCliente) {
            return arrayClientes[i];
        }
    }
    return clienteEncontrado; 
}


void mostrarInfoCliente(const CLIENTE &cliente) {
    std::cout << "ID: " << cliente.id << std::endl;
    std::cout << "Nombre: " << cliente.nombre << std::endl;
    std::cout << "Correo: " << cliente.correo << std::endl;
    std::cout << "Teléfono: " << cliente.telefono << std::endl;
    std::cout << "Dirección: " << cliente.direccion << std::endl;
    std::cout << "Fecha de Nacimiento: " << cliente.fecha << std::endl;
}

int main() {
    const int MAX_CLIENTES = 100;
    CLIENTE arrayClientes[MAX_CLIENTES]; 
    int numClientes = 0; 

   
    int idClienteABuscar = 1; 
    CLIENTE clienteEncontrado = buscarClientePorId(idClienteABuscar, arrayClientes, numClientes);

    if (clienteEncontrado.id != 0) { 
        std::cout << "Cliente encontrado:\n";
        mostrarInfoCliente(clienteEncontrado);
    } else {
        std::cout << "Cliente no encontrado.\n";
    }

    return 0;
}
