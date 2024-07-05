#include <iostream>
#include "title.cpp"
#include "funciones.cpp"

using namespace std;

// MENUS

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
        cout << " 6. Salir\n";
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
            cout << "Gracias...\n";
            Sleep(2000);
            break;
        default:
            cout << "Solo hay 6 opciones. \n";
            break;
        }
    } while (opciones != 6);
}
int main()
{
    Sleep(1500);
    MENU();
    return 0;
}
