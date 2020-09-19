#include <iostream>
using namespace std;
#include <stdlib.h>
#include "menu.h"
#include "usuario/usuario.h"
#include "entrenamiento/entrenamiento.h"
#include "reporte/reporte.h"
#include "configuraciones/confuguracion.h"

void usuario(){
    short opcion;
    do{
        cout<<"\t USUARIOS";
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) NUEVO USUARIO";
        cout<<endl<<"2) MODIFICAR USUARIO";
        cout<<endl<<"3) LISTAR USUARIO POR ID";
        cout<<endl<<"4) LISTAR TODOS LOS USUARIOS";
        cout<<endl<<"5) ELIMINAR USUARIO";
        cout<<endl<<"6) SALIR";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t opcion: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            NuevoUsuario();
            system ("pause");
            system ("cls");
        break;
        case 2:
            ModificarUsuario();
            system ("pause");
            system ("cls");
        break;
        case 3:
            ListarUsuariosID();
            system ("pause");
            system ("cls");
        break;
        case 4:
            ListarTodosUsuarios();
            system ("pause");
            system ("cls");
        break;
        case 5:
            EliminarUsuario();
            system ("pause");
            system ("cls");
        break;
        case 6:
        break;
        default:
            cout<<endl<<"\t Opcion incorrecta"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        }
    }while (opcion!=6);
}


void entrenamientos(){
    short opcion;
    do{
        cout<<"\t ENTRENAMIENTOS";
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) NUEVO ENTRENAMIENTO";
        cout<<endl<<"2) MODIFICAR ENTRENAMIENTO";
        cout<<endl<<"3) LISTAR ENTRENAMIENTO POR ID";
        cout<<endl<<"4) LISTAR ENTRENAMIENTOS POR ID USUARIO";
        cout<<endl<<"5) LISTAR TODOS LOS ENTRENAMIENTOS";
        cout<<endl<<"6) SALIR";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t opcion: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            NuevoEntrenamiento();
            system ("pause");
            system ("cls");
        break;
        case 2:
            ModificarEntrenamiento();
            system ("pause");
            system ("cls");
        break;
        case 3:
            ListarEntrenamientoID();
            system ("pause");
            system ("cls");
        break;
        case 4:
            ListarEntrenamientoIDusuario();
            system ("pause");
            system ("cls");
        break;
        case 5:
            ListarTodosEntrenamientos();
            system ("pause");
            system ("cls");
        break;
        case 6:
        break;
        default:
            cout<<endl<<"\t Opcion incorrecta"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        }
    }while (opcion!=6);
}

void reportes(){
    short opcion;
    do{
        cout<<"\t ENTRENAMIENTOS";
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) REPORTE 1";
        cout<<endl<<"2) REPORTE 2";
        cout<<endl<<"3) SALIR";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t opcion: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            reporte1();
            system ("pause");
            system ("cls");
        break;
        case 2:
            reporte2();
            system ("pause");
            system ("cls");
        break;
        case 3:
            return;
        break;
        default:
            cout<<endl<<"\t Opcion incorrecta"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        }
    }while (opcion!=3);
}

void configuracion(){
    short opcion;
    do{
        cout<<"\t ENTRENAMIENTOS";
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) REALIZAR COPIA DE SEGURIDAD";
        cout<<endl<<"2) RESTAURAR COPIA DE SEGURIDAD";
        cout<<endl<<"3) SALIR";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t opcion: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            CopiaSeguridad();
            system ("pause");
            system ("cls");
        break;
        case 2:
            RestaurarCopia();
            system ("pause");
            system ("cls");
        break;
        case 3:
            return;
        break;
        default:
            cout<<endl<<"\t Opcion incorrecta"<<endl<<endl;
            system ("pause");
            system ("cls");
        break;
        }
    }while (opcion!=3);
}
