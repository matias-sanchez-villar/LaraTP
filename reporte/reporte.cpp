#include <iostream>
using namespace std;
#include <cstdlib>
#include "reporte.h"
#include "../InterfazGrafica/ui.h"
#include "../estructura.h"
#include "ArchivosReportes.h"
#include "../entrenamiento/ArchivosEntrenamientos.h"
#include "../usuario/ArchivosUsuario.h"

///Listar todos los entrenamientos cuyo tiempo supere el tiempo promedio.

void reporte1(){
    title("REPORTE 1", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;
    int cant=TotalEntremanitos();
        if(cant==-1){
            msj("ERROR DE ARCHIVO 1", 15, 3, 1, 1);
            return;
        }
    float tiempo=TotalTiempo(), total;
        if(tiempo==-1){
            msj("ERROR DE ARCHIVO 2", 15, 3, 1, 1);
            return;
        }
    total=tiempo/cant;
    if(MostrarMayoresAlPromedio(total)==false){
        msj("ERROR DE ARCHIVO 3", 15, 3, 1, 1);
        return;
    }
    system ("pause");
    system ("cls");
}

/// A partir de un ID de usuario que se ingrese por teclado listar Apellido,
/// Nombres y cantidad de entrenamientos realizados en el año 2020.

void reporte2(){
    title("REPORTE 2", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;
    int cant=TotalUsuarios();
    if(cant==-1){
        msj("ERROR DE ARCHIVO 1", 15, 3, 1, 1);
        return;
    }
    participante *uno;
    uno=(participante *)malloc(cant * sizeof(participante));
    if(uno==NULL){
        msj("ERROR DE ARCHIVO 2", 15, 3, 1, 1);
        free(uno);
        return;
    }
    for(int x=0;x<cant;x++){
        uno[x]=TraerUsuario(x);
    }
    for(int x=0;x<cant;x++){
        if(uno[x].estado==true){
            cout<<"Nombre "<<uno[x].nombre<<endl;
            cout<<"Apelldio "<<uno[x].apellido<<endl;
            cout<<"Cantidad de entrenamientos en el 2020: "<<CantidadEntrenamientos(uno[x].id)<<endl<<endl;
        }
    }
    system ("pause");
    system ("cls");
}

