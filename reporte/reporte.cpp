#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "reporte.h"
#include "../InterfazGrafica/ui.h"
#include "../estructura.h"
#include "ArchivosReportes.h"
#include "../entrenamiento/ArchivosEntrenamientos.h"
#include "../usuario/ArchivosUsuario.h"
#include "../validacion.h"

///A partir de un IDUsuario que se ingresa por teclado, listar el entrenamiento
///de mayor cantidad de calorías y la fecha en que las registró. Si hay dos
///registro con misma cantidad, mostrar el primero de ellos.

void reporte1(){
    title("REPORTE 1", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;
    int id;
    cout<<endl<<"Ingrese ID: ";
    cin>>id;
        while(validarIDusuario(id)==true){
                cout<<"Error ID, Desea continuar (SI/NO): ";
                if(continuar()==false){
                    system ("cls");
                    return;
                }
            cout<<">>reingrese Ingrese el ID: ";
            cin>>id;
        }
    fecha uno;
    float calorias=0;
    uno=MayorCantidadCalorias(id, &calorias);
    ///mostramos
    cout<<"Numero de ID: "<<id<<endl;
    cout<<"Numero de calorias: "<<calorias<<endl;
    cout<<"Fecha de nacimiento "<<uno.dia<<"/"<<uno.mes<<"/"<<uno.anio<<endl;
    system ("pause");
    system ("cls");
}

///Por cada tipo de actividad, listar la cantidad de entrenamientos
///discriminado por perfil de usuario.

void reporte2(){
    title("REPORTE 2", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;
    for(int x=1;x<=5;x++){
        cout<<"Entrenamiento: "<<x<<endl;
        cout<<"Cantidad de entrenamientos: "<<CantidadEntrenamientos(x)<<endl<<endl;
        MostrarPerfilUsuario(x);
    }
    system ("pause");
    system ("cls");
    cout<<"Todas las actividades fueron mostradas";
    system ("pause");
    system ("cls");
}

