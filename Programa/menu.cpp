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
        cout << " 7. (WIP) (Aún no sirve) Ordenar por ABC\n";
        cout << "Elija la opcion: ";
        cin >> opciones;
        SetColor(15);

        switch (opciones)
        {
        case 1:
            Sleep(1000);
            title_PedirDato();
            pedirDato();
            system("clear");

            break;
        case 2:
            Sleep(1000);
            title_Editar();
            editar();
            system("clear");


            break;
        case 3:
            Sleep(1000);
            title_Eliminar();
            eliminar();
            system("clear");
            
          
            break;
        case 4:
            Sleep(1000);
            title_MostrarTodo();
            mostrarTodo();
            system("clear");
            
           
            break;
        case 5:
            Sleep(1000);
            title_BuscarCustomer();
            buscarCustomer();
            system("clear");
           
          
            break;
        case 6:
            Sleep(1000);
            title_ordenarClientes();
            ordenarClientes();
            system("clear");

            break;
        case 7:
            Sleep(1000);
            cout << "Gracias...\n";
            system("clear");
            Sleep(2000);
            break;

        default:
            cout << "Solo hay 7 opciones. \n";
            system("clear");
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
