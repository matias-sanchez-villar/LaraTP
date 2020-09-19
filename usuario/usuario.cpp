#include <iostream>
using namespace std;
#include "usuario.h"
#include "../estructura.h"
#include "ArchivosUsuario.h"
#include "../validacion.h"

void NuevoUsuario(){
    participante uno;
    short apto;
    cout<<"Ingrese ID: ";
    cin>>uno.id;
        while(validarIDusuario(uno.id)!=true){
                if(continuar()==false){
                    return;
                }
            cout<<">>reingrese Ingrese el ID: ";
            cin>>uno.id;
        }
    cout<<"Ingrese el Nombre: ";
    cin.ignore();
    cin.getline(uno.nombre, 30, '\n');
        while(uno.nombre[0]==' '){
            cout<<endl<<"Nombre incorrecta, reingrese el Nombre"<<endl<<endl;
            cout<<">> Ingrese el Nombre: ";
            cin.getline(uno.nombre, 30, '\n');
        }
    cout<<"Ingrese el Apellido: ";
    cin.getline(uno.apellido, 30, '\n');
        while(uno.apellido[0]==' '){
            cout<<endl<<"Apellido incorrecta, reingrese el Apellido"<<endl<<endl;
            cout<<">> Ingrese el Apellido: ";
            cin.getline(uno.apellido, 30, '\n');
        }
    cout<<"Ingrese la fecha de nacimiento"<<endl;
    cout<<"\t dia    : ";
    cin>>uno.nacimiento.dia;
    cout<<"\t mes    : ";
    cin>>uno.nacimiento.mes;
    cout<<"\tanio (4): ";
    cin>>uno.nacimiento.anio;
        while(ValidarFecha(uno.nacimiento.dia, uno.nacimiento.mes, uno.nacimiento.anio, true)!=true){
                if(continuar()==false){
                        return;
                }
            cout<<endl<<"Fecha incorrecta, reingrese el fecha"<<endl<<endl;
            cout<<">> Ingrese el fecha: "<<endl;
            cout<<"\tdia  : ";
            cin>>uno.nacimiento.dia;
            cout<<"\tmes  : ";
            cin>>uno.nacimiento.mes;
            cout<<"\tanio : ";
            cin>>uno.nacimiento.anio;
        }
    cout<<"Ingrese altura: ";
    cin>>uno.altura;
        while(uno.altura<0){
            cout<<endl<<"Altura incorrecta, reingrese el altura"<<endl<<endl;
            cout<<">> Ingrese el altura: ";
            cin>>uno.altura;
        }
    cout<<"Ingrese peso: ";
    cin>>uno.peso;
        while(uno.peso<0){
            cout<<endl<<"Peso incorrecta, reingrese el peso"<<endl<<endl;
            cout<<">> Ingrese el peso: ";
            cin>>uno.peso;
        }
    cout<<"Ingrese el perfil de actividad: ";
    cin>>uno.perfil;
        while((uno.perfil!='a') && (uno.perfil!='b') && (uno.perfil!='c') && (uno.perfil!='A') && (uno.perfil!='B') && (uno.perfil!='C')){
            cout<<endl<<"Perfil incorrecta, reingrese el perfil"<<endl<<endl;
            cout<<">> Ingrese el perfil de actividad: ";
            cin>>uno.perfil;
            cout<<endl;
        }
    cout<<"Ingrese apto: ";
    cin>>apto;
        while((apto<false)||(apto>true)){
            cout<<endl<<"Apto incorrecta, reingrese el apto"<<endl<<endl;
            cout<<">> Ingrese el apto: ";
            cin>>apto;
        }
    uno.apto=apto;
    uno.estado=true;
    ///procedemos a guardar el usuario
    system ("cls");
    if(GuardarUsuario(uno)==false){
        cout<<endl<<"Error usuario no guardado"<<endl;
        return;
    }
    else{
        cout<<endl<<"Usuario guardado"<<endl;
    }
}

void ModificarUsuario(){
    participante uno;
    int posicion;
    bool estado=false;
    short apto;
    cout<<"Ingrese el ID de usuario a modificar: ";
    cin>>uno.id;
    posicion=BuscarUsuario(uno.id, &estado);
        if (posicion==-1 || estado==false){
            cout<<"Error de archivo"<<endl;
            return;
        }
    ///traemos el usuario
    uno=TraerUsuario(posicion);
        if(uno.id==-1){
            cout<<"Error de Archivos"<<endl;
            return;
        }
    ///empieza la modificacion
    cout<<"Ingrese peso: ";
    cin>>uno.peso;
        while(uno.peso<0){
            cout<<endl<<"Peso incorrecta, reingrese el peso"<<endl<<endl;
            cout<<">> Ingrese el peso: ";
            cin>>uno.peso;
        }
    cout<<"Ingrese el perfil de actividad: ";
    cin>>uno.perfil;
        while((uno.perfil!='a') && (uno.perfil!='b') && (uno.perfil!='c') && (uno.perfil!='A') && (uno.perfil!='B') && (uno.perfil!='C')){
            cout<<endl<<"Perfil incorrecta, reingrese el perfil"<<endl<<endl;
            cout<<">> Ingrese el perfil de actividad: ";
            cin>>uno.perfil;
            cout<<endl;
        }
    cout<<"Ingrese apto: ";
    cin>>apto;
        while((apto<false)||(apto>true)){
            cout<<endl<<"Apto incorrecta, reingrese el apto"<<endl<<endl;
            cout<<">> Ingrese el apto: ";
            cin>>apto;
        }
    uno.apto=apto;
    ///guardamos la modificacion
    if(ModificarUsuario(uno, posicion)==false){
        cout<<"participante no guardado";
        return;
    }
    cout<<"Participante guardado";
}

void ListarUsuariosID(){
    participante uno;
    int posicion;
    bool estado=false;
    cout<<"Ingrese el ID de usuario: ";
    cin>>uno.id;
    posicion=BuscarUsuario(uno.id, &estado);
        if (posicion==-1 || estado==false){
            cout<<"Error de archivo"<<endl;
            return;
        }
    ///traemos el usuario
    uno=TraerUsuario(posicion);
        if(uno.id==-1){
            cout<<"Error de Archivos"<<endl;
            return;
        }
    ///mostrar usuario
    MostrarUsuario(uno);
}

void ListarTodosUsuarios(){
    if(ListarTodosLosUsuarios()==false){
        cout<<endl<<"-Error de archivos-"<<endl;
    }
    else{
        cout<<endl<<"-Todos los usuarios han sido mostrados-"<<endl;
    }
}

void EliminarUsuario(){
    participante uno;
    int posicion;
    bool estado=false;
    cout<<"Ingrese el ID de usuario: ";
    cin>>uno.id;
    posicion=BuscarUsuario(uno.id, &estado);
        if (posicion==-1 || estado==false){
            cout<<"Error de archivo"<<endl;
            return;
        }
    ///traemos el participante
    uno=TraerUsuario(posicion);
        if(uno.id==-1){
            cout<<"Error de Archivos"<<endl;
            return;
        }
    uno.estado=false;
    ///procedemos a guardar el usuario
    system ("cls");
    if(ModificarUsuario(uno, posicion)==false){
        cout<<"Error usuario no guardado"<<endl;
        return;
    }
    else{
        cout<<endl<<"Usuario guardado"<<endl;
    }
}

void MostrarUsuario(participante uno){
    cout<<"----------------------------------------------"<<endl;
    cout<<"ID "<<uno.id<<endl;
    cout<<"Nombre "<<uno.nombre<<endl;
    cout<<"Apelldio "<<uno.apellido<<endl;
    cout<<"Fecha de nacimiento "<<uno.nacimiento.dia<<"/"<<uno.nacimiento.mes<<"/"<<uno.nacimiento.anio<<endl;
    cout<<"Altura "<<uno.altura<<endl;
    cout<<"Peso "<<uno.peso<<endl;
    cout<<"Perfil de actividad "<<uno.perfil<<endl;
    cout<<"Apto medico "<<uno.apto<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
}
