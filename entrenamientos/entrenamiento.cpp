#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "entrenamiento.h"
#include "ArchivosEntrenamiento.h"
#include "../usuarios/ArchivosUsuarios.h"
#include "../estructura.h"
#include "../validaciones.h"
#include "../InterfazGrafica/ui.h"

void NuevoEntrenamiento(){
    title("NUEVO ENTRENAMIENTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    entrenamiento uno;
    cout<<endl<<"Ingrese el ID de usuario: ";
    cin>>uno.idUsuario;
    while(EstadoUsuario(uno.idUsuario)!=true){
        cout<<"Error ID, Desea continuar (SI/NO): ";
            if(continuar()==false){
                system ("cls");
                return;
            }
        cout<<endl<<">> Ingrese el ID de usuario: ";
        cin>>uno.idUsuario;
    }
    uno.id=CantidadEntrenaminto()+1;
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
        while(ValidarActividadEntrenamiento(uno.idUsuario, uno.actividad)!=true){
            cout<<"> Usuario no apoto para la actividad "<<uno.actividad;
                if(continuar()==false){
                    system ("cls");
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
    ///preguntamos
    cout<<"Desea Guardar el Entrenamiento (SI/NO): ";
        if(continuar()==false){
            system ("cls");
            msj("ENTRENAMIENTO NO GUARDADO", 15, 3, 1, 1);
            return;
        }
    system ("cls");
    if(GuardarEntrenamiento(uno)){
        msj("ENTRENAMIENTO GUARDADO CORRECTAMENTE", 15, 3, 1, 1);
        return;
    }
    msj("ERROR ENTRENAMIENTO NO GUARDADO", 15, 3, 1, 1);
}

void ModificarEntrenamiento(){
    title("MODIFICAR ENTRENAMIENTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    entrenamiento uno;
    int pos;
    cout<<endl<<"Ingrese el ID de entrenamiento: ";
    cin>>uno.id;
    pos=UbicacionEntrenaminto(uno.id);
    LeerEntrenamiento(uno, pos);
    if(pos==-1){
        system ("cls");
        msj("ERROR ENTRENAMIENTO NO EXISTE", 15, 3, 1, 1);
    }
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
    ///preguntamos
    cout<<"Desea Guardar la Modificación del Entrenamiento (SI/NO): ";
        if(continuar()==false){
            system ("cls");
            msj("ENTRENAMIENTO NO GUARDADO MODIFICADO", 15, 3, 1, 1);
            return;
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
    title("LISTAR ENTRENAMIENTO POR ID", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    entrenamiento uno;
    int ID;
    int pos=0;
    cout<<endl<<"Ingrese el ID de entrenamiento: ";
    cin>>ID;
    while(LeerEntrenamiento(uno, pos++)){
        if(uno.id==ID){
            MostrarEntramiento(uno);
        }
    }
    system ("pause");
    system ("cls");
}

void ListarEntrenamientoIDusuario(){
    title("LISTAR ENTRENAMIENTO POR ID USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    entrenamiento uno;
    int ID;
    int pos=0;
    cout<<endl<<"Ingrese el ID de usuario: ";
    cin>>ID;
    while(LeerEntrenamiento(uno, pos++)){
        if(uno.idUsuario==ID){
            MostrarEntramiento(uno);
        }
    }
    system ("pause");
    system ("cls");
}

void ListarTodosEntrenamientos(){
    title("LISTAR ENTRENAMIENTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    entrenamiento uno;
    int pos=0;
    while(LeerEntrenamiento(uno, pos++)){
        MostrarEntramiento(uno);
    }
    system ("pause");
    system ("cls");
}

void MostrarEntramiento(struct entrenamiento uno){
    cout<<endl<<"----------------------------------------"<<endl;
    cout<<"ID de entrenamiento "<<uno.id<<endl;
    cout<<"ID de usuario: "<<uno.idUsuario<<endl;
    cout<<"fecha de entrenamiento "<<uno.entrenamiento.dia<<"/"<<uno.entrenamiento.mes<<"/"<<uno.entrenamiento.anio<<endl;
    cout<<"actividad: "<<uno.actividad<<endl;
    cout<<"calorias: "<<uno.calorias<<endl;
    cout<<"tiempo: "<<uno.tiempo<<endl;
    cout<<"----------------------------------------"<<endl<<endl;
}
