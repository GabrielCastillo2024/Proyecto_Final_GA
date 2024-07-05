#include <iostream>
#include "title.cpp"
#include "funciones.cpp"
#include <stdlib.h>

using namespace std;

// MENUS
// tomar en cuenta 
// https://mathbits.com/MathBits/CompSci/Introduction/clear.htm#:~:text=To%20clear%20the%20screen%20in,h%3E%20is%20needed.

void MENU()
{
    int opciones;
    pos = loadCustomers();
    do
    {
        title_Op();
        SetColor(12);
        cout << "1. Agregar \n";
        cout << " 2. Editar \n";
        cout << " 3. Eliminar\n";
        cout << " 4. Mostrar Todos \n";
        cout << " 5. Buscar \n";
        cout << " 6. (WIP) (Aún no sirve) Ordenar por ABC\n";
        cout << " 7. Salir\n";
        cout << "Elija la opcion: ";
        cin >> opciones;
        SetColor(15);

        switch (opciones)
        {
        case 1:
            Sleep(1000);
            title_PedirDato();
            pedirDato();
            

            break;
        case 2:
            Sleep(1000);
            title_Editar();
            editar();


            break;
        case 3:
            Sleep(1000);
            title_Eliminar();
            eliminar();            
          
            break;
        case 4:
            Sleep(1000);
            title_MostrarTodo();
            mostrarTodo();            
           
            break;
        case 5:
            Sleep(1000);
            title_BuscarCustomer();
            buscarCustomer();           
          
            break;
        case 6:
            Sleep(1000);
            title_ordenarClientes();
            ordenarClientes();

            break;
        case 7:
            Sleep(1000);
            cout << "Gracias...\n";
            break;

        default:
            cout << "Solo hay 7 opciones. \n";
            break;
        }
    } while (opciones != 7);
}
int main()
{
    Sleep(1500);
    MENU();
    return 0;
}
