#include <iostream>
using namespace std;
#include <stdlib.h>
#include "InterfazGrafica/ui.h"
#include "menu.h"

int main(){
    short opcion;
    do{
        title("MENU", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        system("cls");
        title("MENU", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------";
        cout<<endl<<"1_ USUARIOS";
        cout<<endl<<"2_ ENTRENAMIENTOS";
        cout<<endl<<"3_ REPORTES";
        cout<<endl<<"4_ CONFIGURACION";
        cout<<endl<<"5_ SALIR";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t OPCION: ";
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
            cout<<endl<<"\t Gracias Hasta luego"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        default:
            msj("OPCION INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=5);
return 0;
}
