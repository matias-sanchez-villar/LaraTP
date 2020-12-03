#include <iostream>
using namespace std;
#include "InterfazGrafica/ui.h"
#include "menu.h"

int main(){
    setlocale(LC_ALL, "Spanish");
    short opcion;
    do{
        title("MENU", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        system("cls");
        title("MENU", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------";
        cout<<endl<<"1_ USUARIOS";
        cout<<endl<<"2_ ENTRENAMIENTOS";
        cout<<endl<<"3_ REPORTES";
        cout<<endl<<"4_ CONFIGURACIÓN";
        cout<<endl<<"5_ SALIR";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t OPCIÓN: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            usuario();
        break;
        case 2:
            entrenamientos();
        break;
        case 3:
            reportes();
        break;
        case 4:
            configuracion();
        break;
        case 5:
            cout<<endl<<"\t GRACIAS HASTA LUEGO"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=5);
return 0;
}
