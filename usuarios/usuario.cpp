#include <iostream>
using namespace std;
#include <cstring>
#include "usuario.h"
#include "ArchivosUsuarios.h"
#include "../estructura.h"
#include "../validaciones.h"
#include "../InterfazGrafica/ui.h"

void NuevoUsuario(){
    title("NUEVO USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    usuario uno;
    short apto;
    cout<<endl<<"Ingrese ID: ";
    cin>>uno.id;
        while(ValidarIDusuario(uno.id)!=false){
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
        system("cls");
        msj("ERROR USUARIO NO GUARDADO", 15, 3, 1, 1);
        return;
    }
    system("cls");
    msj("USUARIO GUARDADO CORRECTAMENTE", 15, 3, 1, 1);
}

void ModificarUsuario(){
    title("MODIFICAR USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    usuario uno;
    int pos;
    short apto;
    cout<<endl<<"Ingrese ID: ";
    cin>>uno.id;
    pos=BuscarPosUsuario(uno.id);
    if(pos==-1 || EstadoUsuario(uno.id)==false){
        system("cls");
        msj("EL USUARIO NO EXISTE", 15, 3, 1, 1);
        return;
    }
    LeerUsuario(uno, pos);
    MostrarUsuario(uno);
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
            system ("cls");
            msj("USUARIO NO MODIFICADO", 15, 3, 1, 1);
            return;
        }
    ///guardamos la modificacion
    if(ModificarUsuario(uno, pos)==false){
        system("cls");
        msj("Error USUARIO NO MODIFICADO", 15, 3, 1, 1);
        return;
    }
    system("cls");
    msj("USUARIO MODIFICADO CORRECTAMENTE", 15, 3, 1, 1);
}

void ListarUsuariosID(){
    title("LISTAR USUARIO POR ID", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    usuario uno;
    int pos=0, ID;
    cout<<endl<<"Ingrese ID: ";
    cin>>ID;
    while(LeerUsuario(uno, pos++)){
        if(uno.id==ID && uno.estado==true){
            MostrarUsuario(uno);
            system("pause");
            system("cls");
            return;
        }
    }

}

void ListarTodosUsuarios(){
    title("MOSTRAR TODOS LOS USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    usuario uno;
    int pos=0;
    bool estado=false;
    cout<<endl;
    while(LeerUsuario(uno, pos++)){
        if(uno.estado==true){
            MostrarUsuario(uno);
            estado=true;
        }
    }
    if(estado==false){
        system("cls");
        msj("NO EXISTEN USUARIOS", 15, 3, 1, 1);
    }
    system("pause");
    system("cls");
}

void EliminarUsuario(){
    title("ELIMINAR USUARIO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    usuario uno;
    int pos;
    cout<<endl<<"Ingrese ID: ";
    cin>>uno.id;
    pos=BuscarPosUsuario(uno.id);
    if(pos==-1 || EstadoUsuario(uno.id)==false){
        system("cls");
        msj("EL USUARIO NO EXISTE", 15, 3, 1, 1);
        return;
    }
    LeerUsuario(uno, pos);
    MostrarUsuario(uno);
    cout<<"Desea continuar (SI/NO): ";
    if(continuar()==false){
        system ("cls");
        return;
    }
    uno.estado=false;
    ///guardamos la modificacion
    if(ModificarUsuario(uno, pos)==false){
        system("cls");
        msj("Error USUARIO NO ELIMINADO", 15, 3, 1, 1);
        return;
    }
    system("cls");
    msj("USUARIO ELIMINADO CORRECTAMENTE", 15, 3, 1, 1);
}

void MostrarUsuario(usuario uno){
    cout<<endl<<"----------------------------------------------"<<endl;
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
