#include <iostream>
using namespace std;
#include <cstdlib>
#include "reporte.h"
#include "../estructura.h"
#include "ArchivosReportes.h"
#include "../entrenamiento/ArchivosEntrenamientos.h"
#include "../usuario/ArchivosUsuario.h"

///Listar todos los entrenamientos cuyo tiempo supere el tiempo promedio.

void reporte1(){
    int cant=TotalEntremanitos();
        if(cant==-1){
            cout<<"-error de archivos 1-"<<endl;
            return;
        }
    float tiempo=TotalTiempo(), total;
        if(tiempo==-1){
            cout<<"-error de archivos 2-"<<endl;
            return;
        }
    total=tiempo/cant;
    if(MostrarMayoresAlPromedio(total)==false){
        cout<<"-error de archivos 3-"<<endl;
        return;
    }
}

/// A partir de un ID de usuario que se ingrese por teclado listar Apellido,
/// Nombres y cantidad de entrenamientos realizados en el año 2020.

void reporte2(){
    int cant=TotalUsuarios();
    if(cant==-1){
        cout<<"-error de archivos 1-"<<endl;
        return;
    }
    participante *uno;
    uno=(participante *)malloc(cant * sizeof(participante));
    if(uno==NULL){
        cout<<"-error de archivos 2-"<<endl;
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
}
