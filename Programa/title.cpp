#include <iostream>
#include <windows.h>
using namespace std;
//definimos el void a ocupar

int SetColor(int color);
void title_Op();
void title_Principal();
void title_PedirDato();
void title_Editar();
void title_Eliminar();
void title_MostrarTodo();
void title_BuscarCustomer();
void title_ShowData();
void title_ordenarClientes();



/*MENUS*/



int SetColor(int color) {
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consola, color);
}

void resetarColor(){
    SetColor(15);
}

void title_Op(){

SetColor(6);

cout<<" /$$      /$$                                           /$$                  /$$$$$$                      /$$                                        "<<endl;
cout<<"| $$$    /$$$                                          | $$                 /$$__  $$                    |__/                                        "<<endl;
cout<<"| $$$$  /$$$$  /$$$$$$  /$$$$$$$  /$$   /$$        /$$$$$$$  /$$$$$$       | $$  \\ $$  /$$$$$$   /$$$$$$$ /$$  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$$"<<endl;
cout<<"| $$ $$/$$ $$ /$$__  $$| $$__  $$| $$  | $$       /$$__  $$ /$$__  $$      | $$  | $$ /$$__  $$ /$$_____/| $$ /$$__  $$| $$__  $$ /$$__  $$ /$$_____/"<<endl;
cout<<"| $$  $$$| $$| $$$$$$$$| $$  \\ $$| $$  | $$      | $$  | $$| $$$$$$$$      | $$  | $$| $$  \\ $$| $$      | $$| $$  \\ $$| $$  \\ $$| $$$$$$$$|  $$$$$$ "<<endl;
cout<<"| $$\\  $ | $$| $$_____/| $$  | $$| $$  | $$      | $$  | $$| $$_____/      | $$  | $$| $$  | $$| $$      | $$| $$  | $$| $$  | $$| $$_____/ \\____  $$"<<endl;
cout<<"| $$ \\/  | $$|  $$$$$$$| $$  | $$|  $$$$$$/      |  $$$$$$$|  $$$$$$$      |  $$$$$$/| $$$$$$$/|  $$$$$$$| $$|  $$$$$$/| $$  | $$|  $$$$$$$ /$$$$$$$/"<<endl;
cout<<"|__/     |__/ \\_______/|__/  |__/ \\______/        \\_______/ \\_______/       \\______/ | $$____/  \\_______/|__/ \\______/ |__/  |__/ \\_______/|_______/ "<<endl;
cout<<"                                                                                     | $$"<<endl;                                                            
cout<<"                                                                                     | $$"<<endl;                                                            
cout<<"                                                                                     |__/"<<endl;                                                            
cout<<" ";
SetColor(15);
}
void title_Principal(){
    SetColor(6);
cout<<"$$$$$$$\\            $$\\                     $$\\                     $$\\ "<<endl;
cout<<"$$  __$$\\           \\__|                    \\__|                    $$ |"<<endl;
cout<<"$$ |  $$ | $$$$$$\\  $$\\ $$$$$$$\\   $$$$$$$\\ $$\\  $$$$$$\\   $$$$$$\\  $$ |"<<endl;
cout<<"$$$$$$$  |$$  __$$\\ $$ |$$  __$$\\ $$  _____|$$ |$$  __$$\\  \\____$$\\ $$ |"<<endl;
cout<<"$$  ____/ $$ |  \\__|$$ |$$ |  $$ |$$ /      $$ |$$ /  $$ | $$$$$$$ |$$ |"<<endl;
cout<<"$$ |      $$ |      $$ |$$ |  $$ |$$ |      $$ |$$ |  $$ |$$  __$$ |$$ |"<<endl;
cout<<"$$ |      $$ |      $$ |$$ |  $$ |\\$$$$$$$\\ $$ |$$$$$$$  |\\$$$$$$$ |$$ |"<<endl;
cout<<"\\__|      \\__|      \\__|\\__|  \\__| \\_______|\\__|$$  ____/  \\_______|\\__|"<<endl;
cout<<"                                                $$ |                    "<<endl;
cout<<"                                                $$ |                    "<<endl;
cout<<"                                                \\__|                    "<<endl;
SetColor(15);
}
void title_PedirDato(){
    SetColor(6);
    
cout<<" $$$$$$\\                                                              "<<endl;
cout<<"$$  __$$\\                                                             "<<endl;
cout<<"$$ /  $$ | $$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$\\  "<<endl;
cout<<"$$$$$$$$ |$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\  \\____$$\\ $$  __$$\\ "<<endl;
cout<<"$$  __$$ |$$ /  $$ |$$ |  \\__|$$$$$$$$ |$$ /  $$ | $$$$$$$ |$$ |  \\__|"<<endl;
cout<<"$$ |  $$ |$$ |  $$ |$$ |      $$   ____|$$ |  $$ |$$  __$$ |$$ |      "<<endl;
cout<<"$$ |  $$ |\\$$$$$$$ |$$ |      \\$$$$$$$\\ \\$$$$$$$ |\\$$$$$$$ |$$ |      "<<endl;
cout<<"\\__|  \\__| \\____$$ |\\__|       \\_______| \\____$$ | \\_______|\\__|      "<<endl;
cout<<"          $$\\   $$ |                    $$\\   $$ |                    "<<endl;
cout<<"          \\$$$$$$  |                    \\$$$$$$  |                    "<<endl;
cout<<"           \\______/                      \\______/                     "<<endl;
cout<<""<<endl;
    SetColor(15);
}
void title_Editar(){
    SetColor(6);
    
cout<<" /$$$$$$$$       /$$ /$$   /$$                               /$$$$$$$              /$$                        "<<endl;
cout<<"| $$_____/      | $$|__/  | $$                              | $$__  $$            | $$                        "<<endl;
cout<<"| $$        /$$$$$$$ /$$ /$$$$$$    /$$$$$$   /$$$$$$       | $$  \\ $$  /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$"<<endl;
cout<<"| $$$$$    /$$__  $$| $$|_  $$_/   |____  $$ /$$__  $$      | $$  | $$ |____  $$|_  $$_/   /$$__  $$ /$$_____/"<<endl;
cout<<"| $$__/   | $$  | $$| $$  | $$      /$$$$$$$| $$  \\__/      | $$  | $$  /$$$$$$$  | $$    | $$  \\ $$|  $$$$$$ "<<endl;
cout<<"| $$      | $$  | $$| $$  | $$ /$$ /$$__  $$| $$            | $$  | $$ /$$__  $$  | $$ /$$| $$  | $$ \\____  $$"<<endl;
cout<<"| $$$$$$$$|  $$$$$$$| $$  |  $$$$/|  $$$$$$$| $$            | $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$/ /$$$$$$$/"<<endl;
cout<<"|________/ \\_______/|__/   \\___/   \\_______/|__/            |_______/  \\_______/   \\___/   \\______/ |_______/ "<<endl;
                                                                                                              
                                                                                                              
                                                                                                              

    SetColor(15);
}
void title_Eliminar(){
    SetColor(6);
    
cout<<" ________  __  __                __                               "<<endl;      
cout<<"/        |/  |/  |              /  |                              "<<endl;      
cout<<"$$$$$$$$/ $$ |$$/  _____  ____  $$/  _______    ______    ______  "<<endl;      
cout<<"$$ |__    $$ |/  |/     \\/    \\ /  |/       \\  /      \\  /      \\ "<<endl;      
cout<<"$$    |   $$ |$$ |$$$$$$ $$$$  |$$ |$$$$$$$  | $$$$$$  |/$$$$$$  |"<<endl;      
cout<<"$$$$$/    $$ |$$ |$$ | $$ | $$ |$$ |$$ |  $$ | /    $$ |$$ |  $$/ "<<endl;      
cout<<"$$ |_____ $$ |$$ |$$ | $$ | $$ |$$ |$$ |  $$ |/$$$$$$$ |$$ |      "<<endl;      
cout<<"$$       |$$ |$$ |$$ | $$ | $$ |$$ |$$ |  $$ |$$    $$ |$$ |      "<<endl;      
cout<<"$$$$$$$$/ $$/ $$/ $$/  $$/  $$/ $$/ $$/   $$/  $$$$$$$/ $$/       "<<endl;      
                                                                        
                                                                        
                                                                        

    SetColor(15);
}
void title_MostrarTodo(){
    SetColor(6);
    
cout<<" /$$      /$$                       /$$                                        /$$$$$$$              /$$                        "<<endl;
cout<<"| $$$    /$$$                      | $$                                       | $$__  $$            | $$                        "<<endl;
cout<<"| $$$$  /$$$$  /$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$  /$$$$$$   /$$$$$$       | $$  \\ $$  /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$"<<endl;
cout<<"| $$ $$/$$ $$ /$$__  $$ /$$_____/|_  $$_/   /$$__  $$|____  $$ /$$__  $$      | $$  | $$ |____  $$|_  $$_/   /$$__  $$ /$$_____/"<<endl;
cout<<"| $$  $$$| $$| $$  \\ $$|  $$$$$$   | $$    | $$  \\__/ /$$$$$$$| $$  \\__/      | $$  | $$  /$$$$$$$  | $$    | $$  \\ $$|  $$$$$$ "<<endl;
cout<<"| $$\\  $ | $$| $$  | $$ \\____  $$  | $$ /$$| $$      /$$__  $$| $$            | $$  | $$ /$$__  $$  | $$ /$$| $$  | $$ \\____  $$"<<endl;
cout<<"| $$ \\/  | $$|  $$$$$$/ /$$$$$$$/  |  $$$$/| $$     |  $$$$$$$| $$            | $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$/ /$$$$$$$/"<<endl;
cout<<"|__/     |__/ \\______/ |_______/    \\___/  |__/      \\_______/|__/            |_______/  \\_______/   \\___/   \\______/ |_______/ "<<endl;
                                                                                                                                
                                                                                                                                
                                                                                                                                

    SetColor(15);
}
void title_BuscarCustomer(){
    SetColor(6);
    
cout<<" /$$$$$$$                                                   "<<endl;
cout<<"| $$__  $$                                                  "<<endl;
cout<<"| $$  \\ $$ /$$   /$$  /$$$$$$$  /$$$$$$$  /$$$$$$   /$$$$$$ "<<endl;
cout<<"| $$$$$$$ | $$  | $$ /$$_____/ /$$_____/ |____  $$ /$$__  $$"<<endl;
cout<<"| $$__  $$| $$  | $$|  $$$$$$ | $$        /$$$$$$$| $$  \\__/"<<endl;
cout<<"| $$  \\ $$| $$  | $$ \\____  $$| $$       /$$__  $$| $$      "<<endl;
cout<<"| $$$$$$$/|  $$$$$$/ /$$$$$$$/|  $$$$$$$|  $$$$$$$| $$      "<<endl;
cout<<"|_______/  \\______/ |_______/  \\_______/ \\_______/|__/      "<<endl;
                                                            
                                                            
                                                            

    SetColor(15);
}
void title_ShowData(){
    SetColor(6);
    
cout<<" /$$$$$$$              /$$              "<<endl;
cout<<"| $$__  $$            | $$              "<<endl;
cout<<"| $$  \\ $$  /$$$$$$  /$$$$$$    /$$$$$$ "<<endl;
cout<<"| $$  | $$ |____  $$|_  $$_/   |____  $$"<<endl;
cout<<"| $$  | $$  /$$$$$$$  | $$      /$$$$$$$"<<endl;
cout<<"| $$  | $$ /$$__  $$  | $$ /$$ /$$__  $$"<<endl;
cout<<"| $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$$"<<endl;
cout<<"|_______/  \\_______/   \\___/   \\_______/"<<endl;
                                        
                                        
                                        

    SetColor(15);
}

void title_ordenarClientes(){
    

 cout << "              .----------------.  .----------------.  .----------------.  " << endl;
 cout << "              | .--------------. || .--------------. || .--------------. |" << endl;
 cout << "              | |      __      | || |   ______     | || |     ______   | |" << endl;
 cout << "              | |     /  \     | || |  |_   _ \    | || |   .' ___  |  | |" << endl;
 cout << "              | |    / /\ \    | || |    | |_) |   | || |  / .'   \_|  | |" << endl;
 cout << "              | |   / ____ \   | || |    |  __'.   | || |  | |         | |" << endl;
 cout << "              | | _/ /    \ \_ | || |   _| |__) |  | || |  \ `.___.'\  | |" << endl;
 cout << "              | ||____|  |____|| || |  |_______/   | || |   `._____.'  | |" << endl;
 cout << "              | |              | || |              | || |              | |" << endl;
 cout << "              | '--------------' || '--------------' || '--------------' |" << endl;
 cout << "               '----------------'  '----------------'  '----------------' " << endl;

}
