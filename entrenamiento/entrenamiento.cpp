#include <iostream>
using namespace std;
#include "entrenamiento.h"
#include "../estructura.h"
#include "../validacion.h"
#include "ArchivosEntrenamientos.h"
#include "../usuario/ArchivosUsuario.h"

void NuevoEntrenamiento(){
    entrenamiento uno;
    bool estado;
    int posicion;
    cout<<"Ingrese el ID de usuario: ";
    cin>>uno.idUsuario;
    posicion=BuscarUsuario(uno.idUsuario, &estado);
        while (posicion==-1 || estado==false){
                if(continuar()==false){
                    return;
                }
            cout<<endl<<">> Ingrese el ID de usuario: ";
            cin>>uno.idUsuario;
            posicion=BuscarUsuario(uno.idUsuario, &estado);
        }
    cout<<"Ingrese la fecha de entrenamiento"<<endl;
    cout<<"\t dia    : ";
    cin>>uno.entrenamiento.dia;
    cout<<"\t mes    : ";
    cin>>uno.entrenamiento.mes;
    cout<<"\tanio (4): ";
    cin>>uno.entrenamiento.anio;
        while(ValidarFecha(uno.entrenamiento.dia, uno.entrenamiento.mes, uno.entrenamiento.anio, false)!=true){
            cout<<endl<<"Fecha incorrecta, reingrese el fecha"<<endl<<endl;
            cout<<">> Ingrese el fecha: "<<endl;
            cout<<"\tdia  : ";
            cin>>uno.entrenamiento.dia;
            cout<<"\tmes  : ";
            cin>>uno.entrenamiento.mes;
            cout<<"\tanio : ";
            cin>>uno.entrenamiento.anio;
        }
    cout<<"Ingrese actividad: ";
    cin>>uno.actividad;
        while(ValidarActividadEntrenamiento(uno.actividad, posicion)!=true){
                if(continuar()==false){
                    return;
                }
            cout<<">> Ingrese el actividad: ";
            cin>>uno.actividad;
        }
    cout<<"Ingrese calorias: ";
    cin>>uno.calorias;
        while(uno.calorias<0){
            cout<<endl<<"Calorias incorrecta, reingrese el calorias"<<endl<<endl;
            cout<<">> Ingrese el calorias: ";
            cin>>uno.calorias;
        }
    cout<<"Ingrese tiempo: ";
    cin>>uno.tiempo;
        while(uno.tiempo<0){
            cout<<endl<<"tiempo incorrecta, reingrese el tiempo"<<endl<<endl;
            cout<<">> Ingrese el tiempo: ";
            cin>>uno.tiempo;
        }
    uno.id=IDautomatico();
    ///procedemos a guardar el usuario
    system ("cls");
    if(GuardarEntrenamieto(uno)==false){
        cout<<endl<<"Error usuario no guardado"<<endl;
        return;
    }
    else{
        cout<<endl<<"Usuario guardado"<<endl;
    }

}

void ModificarEntrenamiento(){
    entrenamiento uno;
    int pos;
    cout<<"Ingrese el ID de entrenamiento: ";
    cin>>uno.id;
    pos=PosicionIDentrenamiento(uno.id);
        while(pos==-1){
                if(continuar()==false){
                    return;
                }
            cout<<"Ingrese el ID de entrenamiento: ";
            cin>>uno.id;
            pos=PosicionIDentrenamiento(uno.id);
        }
    ///traemos el entranmento
    uno=TreaerEntrenamiento(pos);
    MostrarEntramiento(uno);
    ///modificamos entrenamiento
    cout<<"Ingrese calorias: ";
    cin>>uno.calorias;
        while(uno.calorias<0){
            cout<<endl<<"Calorias incorrecta, reingrese el calorias"<<endl<<endl;
            cout<<">> Ingrese el calorias: ";
            cin>>uno.calorias;
        }
    cout<<"Ingrese tiempo: ";
    cin>>uno.tiempo;
        while(uno.tiempo<0){
            cout<<endl<<"tiempo incorrecta, reingrese el tiempo"<<endl<<endl;
            cout<<">> Ingrese el tiempo: ";
            cin>>uno.tiempo;
        }
    ///guardar modificion
    system ("cls");
    if(ModificarEntrenamiento(uno, pos)==false){
        cout<<endl<<"Error usuario no guardado"<<endl;
        return;
    }
    else{
        cout<<endl<<"Usuario guardado"<<endl;
    }
}

void ListarEntrenamientoID(){
    entrenamiento uno;
    cout<<"Ingrese el ID de entrenamiento: ";
    cin>>uno.id;
    if(ListarEntrenamientoID(uno.id)==false){
        cout<<endl<<"Error usuario no guardado"<<endl;
    }
}

void ListarEntrenamientoIDusuario(){
    entrenamiento uno;
    cout<<"Ingrese el ID de entrenamiento: ";
    cin>>uno.id;
    if(ListarEntrenamientoIDusuario(uno.id)==false){
        cout<<endl<<"Error usuario no guardado"<<endl;
    }
}

void ListarTodosEntrenamientos(){
    bool correcto=ListarTodosLosEntrenamientos();
        if(correcto==false){
            cout<<"-Error de archivos-"<<endl;
        }
}

void MostrarEntramiento(entrenamiento uno){
    cout<<"----------------------------------------"<<endl;
    cout<<"ID de entrenamiento "<<uno.id<<endl;
    cout<<"ID de usuario: "<<uno.idUsuario<<endl;
    cout<<"fecha de entrenamiento "<<uno.entrenamiento.dia<<"/"<<uno.entrenamiento.mes<<"/"<<uno.entrenamiento.anio<<endl;
    cout<<"actividad: "<<uno.actividad<<endl;
    cout<<"calorias: "<<uno.calorias<<endl;
    cout<<"tiempo: "<<uno.tiempo<<endl;
    cout<<"----------------------------------------"<<endl<<endl;
}
