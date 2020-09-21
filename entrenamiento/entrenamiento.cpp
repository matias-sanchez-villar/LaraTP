#include <iostream>
using namespace std;
#include "entrenamiento.h"
#include "../InterfazGrafica/ui.h"
#include "../estructura.h"
#include "../validacion.h"
#include "ArchivosEntrenamientos.h"
#include "../usuario/ArchivosUsuario.h"

void NuevoEntrenamiento(){
    entrenamiento uno;
    bool estado;
    int posicion;
    title("NUEVO ENTRENAMIENTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Ingrese el ID de usuario: ";
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
            cout<<"\taño : ";
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
        msj("ERROR ENTRENAMIENTO NO GUARDADO", 15, 3, 1, 1);
        return;
    }
    msj("ENTRENAMIENTO GUARDADO CORRECTAMENTE", 15, 3, 1, 1);
}

void ModificarEntrenamiento(){
    entrenamiento uno;
    int pos;
    title("MODIFICAR ENTRENAMIENTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Ingrese el ID de entrenamiento: ";
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
        msj("ERROR ENTRENAMIENTO NO GUARDADO", 15, 3, 1, 1);
        return;
    }
    msj("ENTRENAMIENTO GUARDADO CORRECTAMENTE", 15, 3, 1, 1);
}

void ListarEntrenamientoID(){
    title("LISTAR ENTRENAMIENTO POR ID ENTRENAMIENTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    entrenamiento uno;
    cout<<endl<<"Ingrese el ID de entrenamiento: ";
    cin>>uno.id;
    if(ListarEntrenamientoID(uno.id)==false){
        msj("ERROR DE ARCHIVO  1", 15, 3, 1, 1);
    }
    system ("pause");
    system ("cls");
}

void ListarEntrenamientoIDusuario(){
    entrenamiento uno;
    title("LISTAR ENTRENAMIENTO POR ID USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Ingrese el ID de entrenamiento: ";
    cin>>uno.id;
    if(ListarEntrenamientoIDusuario(uno.id)==false){
        msj("ERROR DE ARCHIVO 1", 15, 3, 1, 1);
    }
    system ("pause");
    system ("cls");
}

void ListarTodosEntrenamientos(){
    title("LISTAR TODOS LOS ENTRENAMIENTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;
    bool correcto=ListarTodosLosEntrenamientos();
        if(correcto==false){
            msj("Error de archivo 1", 15, 3, 1, 1);
        }
    system ("pause");
    system ("cls");
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
