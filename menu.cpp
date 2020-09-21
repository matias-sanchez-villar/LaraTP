#include <iostream>
using namespace std;
#include <stdlib.h>
#include "menu.h"
#include "InterfazGrafica/ui.h"
#include "usuario/usuario.h"
#include "entrenamiento/entrenamiento.h"
#include "reporte/reporte.h"
#include "configuraciones/confuguracion.h"

void usuario(){
    short opcion;
    do{
        title("MENÚ USUARIOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) NUEVO USUARIO";
        cout<<endl<<"2) MODIFICAR USUARIO";
        cout<<endl<<"3) LISTAR USUARIO POR ID";
        cout<<endl<<"4) LISTAR TODOS LOS USUARIOS";
        cout<<endl<<"5) ELIMINAR USUARIO";
        cout<<endl<<"6) VOLVER AL MENÚ PRINCIPAL";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t OPCIÓN: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            NuevoUsuario();
        break;
        case 2:
            ModificarUsuario();
        break;
        case 3:
            ListarUsuariosID();
        break;
        case 4:
            ListarTodosUsuarios();
        break;
        case 5:
            EliminarUsuario();
        break;
        case 6:
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=6);
}


void entrenamientos(){
    short opcion;
    do{
        title("MENÚ ENTRENAMIENTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) NUEVO ENTRENAMIENTO";
        cout<<endl<<"2) MODIFICAR ENTRENAMIENTO";
        cout<<endl<<"3) LISTAR ENTRENAMIENTO POR ID";
        cout<<endl<<"4) LISTAR ENTRENAMIENTOS POR ID USUARIO";
        cout<<endl<<"5) LISTAR TODOS LOS ENTRENAMIENTOS";
        cout<<endl<<"6) VOLVER AL MENÚ PRINCIPAL";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t OPCIÓN: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            NuevoEntrenamiento();
        break;
        case 2:
            ModificarEntrenamiento();
        break;
        case 3:
            ListarEntrenamientoID();
        break;
        case 4:
            ListarEntrenamientoIDusuario();
        break;
        case 5:
            ListarTodosEntrenamientos();
        break;
        case 6:
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=6);
}

void reportes(){
    short opcion;
    do{
        title("MENÚ REPORTE", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) REPORTE 1";
        cout<<endl<<"2) REPORTE 2";
        cout<<endl<<"3) VOLVER AL MENÚ PRINCIPAL";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t OPCIÓN: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            reporte1();
        break;
        case 2:
            reporte2();
        break;
        case 3:
            return;
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=3);
}

void configuracion(){
    short opcion;
    do{
        title("MENÚ CONFIGURACIÓN", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        cout<<endl<<"---------------------------";
        cout<<endl<<"1) REALIZAR COPIA DE SEGURIDAD";
        cout<<endl<<"2) RESTAURAR COPIA DE SEGURIDAD";
        cout<<endl<<"3) VOLVER AL MENÚ PRINCIPAL";
        cout<<endl<<"---------------------------";
        cout<<endl<<"\t OPCIÓN: ";
        cin>>opcion;
        system ("cls");
        switch(opcion){
        case 1:
            CopiaSeguridad();
        break;
        case 2:
            RestaurarCopia();
        break;
        case 3:
            return;
        break;
        default:
            msj("OPCIÓN INCORRECTA", 15, 3, 1, 1);
        break;
        }
    }while (opcion!=3);
}
