#include <iostream>
using namespace std;
#include <stdlib.h>
#include "rlutil.h"
using namespace rlutil;
#include "menu.h"

int main(){
    setBackgroundColor(LIGHTMAGENTA);
    setColor(WHITE);
    system ("cls");
    short opcion;
    do{
        cout<<"\t MENU";
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
            cout<<endl<<"\t Opcion incorrecta"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        }
    }while (opcion!=5);
return 0;
}
