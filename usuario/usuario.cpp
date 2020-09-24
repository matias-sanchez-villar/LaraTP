#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "usuario.h"
#include "../InterfazGrafica/ui.h"
#include "../estructura.h"
#include "ArchivosUsuario.h"
#include "../validacion.h"

void NuevoUsuario(){
    participante uno;
    short apto;
    title("NUEVO USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Ingrese ID: ";
    cin>>uno.id;
        while(validarIDusuario(uno.id)!=true){
                cout<<"Error ID, Desea continuar (SI/NO): ";
                if(continuar()==false){
                    system ("cls");
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
    cout<<"\taño (4): ";
    cin>>uno.nacimiento.anio;
        while(ValidarFecha(uno.nacimiento.dia, uno.nacimiento.mes, uno.nacimiento.anio, true)!=true){
                cout<<"Error de Fecha, Desea continuar (SI/NO): ";
                if(continuar()==false){
                    system ("cls");
                    return;
                }
            cout<<endl<<"Fecha incorrecta, reingrese el fecha"<<endl<<endl;
            cout<<">> Ingrese el fecha: "<<endl;
            cout<<"\tdia  : ";
            cin>>uno.nacimiento.dia;
            cout<<"\tmes  : ";
            cin>>uno.nacimiento.mes;
            cout<<"\taño : ";
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
    ///preguntamos
    cout<<"Desea Guardar el Usuario (SI/NO): ";
        if(continuar()==false){
            cout<<"El Usuario no ha sido guardado"<<endl;
            system ("pause");
            system ("cls");
            return;
        }
    ///procedemos a guardar el usuario
    system ("cls");
    if(GuardarUsuario(uno)==false){
        msj("ERROR USUARIO NO GUARDADO", 15, 3, 1, 1);
        return;
    }
    else{
        msj("USUARIO GUARDADO CORRECTAMENTE", 15, 3, 1, 1);
    }
}

void ModificarUsuario(){
    participante uno;
    int posicion;
    bool estado=false;
    short apto;
    title("MODIFICAR USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Ingrese el ID de usuario a modificar: ";
    cin>>uno.id;
    posicion=BuscarUsuario(uno.id, &estado);
        if (posicion==-1 || estado==false){
            msj("Error de archivo 1", 15, 3, 1, 1);
            return;
        }
    ///traemos el usuario
    uno=TraerUsuario(posicion);
        if(uno.id==-1){
            msj("Error de archivo 2", 15, 3, 1, 1);
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
    system ("cls");
    ///preguntamos
    cout<<"Desea Guardar la Modificación del Usuario (SI/NO): ";
        if(continuar()==false){
            cout<<"El Usuario no ha sido modificado"<<endl;
            system ("pause");
            system ("cls");
            return;
        }
    ///guardamos la modificacion
    if(ModificarUsuario(uno, posicion)==false){
        msj("Error USUARIO NO GUARDADO", 15, 3, 1, 1);
        return;
    }
    msj("USUARIO GUARDADO CORRECTAMENTE", 15, 3, 1, 1);
}

void ListarUsuariosID(){
    participante uno;
    int posicion;
    bool estado=false;
    title("LISTAR USUARIO POR ID", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Ingrese el ID de usuario: ";
    cin>>uno.id;
    posicion=BuscarUsuario(uno.id, &estado);
        if (posicion==-1 || estado==false){
            msj("Error de archivo 1", 15, 3, 1, 1);
            return;
        }
    ///traemos el usuario
    uno=TraerUsuario(posicion);
        if(uno.id==-1){
            msj("ERROR DE ARCHIVO 2", 15, 3, 1, 1);
            return;
        }
    ///mostrar usuario
    MostrarUsuario(uno);
    system ("pause");
    system ("cls");
}

void ListarTodosUsuarios(){
    title("LISTAR TODOS LOS USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl;
    if(ListarTodosLosUsuarios()==false){
        msj("ERROR DE ARCHIVO 1", 15, 3, 1, 1);
    }
    else{
        cout<<endl<<"-Todos los usuarios han sido mostrados-"<<endl;
    }
    system ("pause");
    system ("cls");
}

void EliminarUsuario(){
    participante uno;
    int posicion;
    bool estado=false;
    title("ELIMINAR USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Ingrese el ID de usuario: ";
    cin>>uno.id;
    posicion=BuscarUsuario(uno.id, &estado);
        if (posicion==-1 || estado==false){
            msj("USUARIO INEXISTENTE", 15, 3, 1, 1);
            return;
        }
    ///traemos el participante
    uno=TraerUsuario(posicion);
        if(uno.id==-1){
            msj("ERROR DE ARCHIVO 2", 15, 3, 1, 1);
            return;
        }
    uno.estado=false;
    ///preguntamos
    cout<<"Desea Eliminar el Usuario (SI/NO): ";
        if(continuar()==false){
            cout<<"El Usuario no ha sido eliminado"<<endl;
            system ("pause");
            system ("cls");
            return;
        }
    ///procedemos a guardar el usuario
    system ("cls");
    if(ModificarUsuario(uno, posicion)==false){
        msj("Error USUARIO NO GUARDADO", 15, 3, 1, 1);
        return;
    }
    msj("USUARIO ELIMINADO CORRECTAMENTE", 15, 3, 1, 1);
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
