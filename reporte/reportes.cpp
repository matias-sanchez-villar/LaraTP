#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "reportes.h"
#include "ArchivosReportes.h"
#include "../estructura.h"
#include "../validaciones.h"
#include "../InterfazGrafica/ui.h"
#include "../entrenamientos/ArchivosEntrenamiento.h"
#include "../usuarios/ArchivosUsuarios.h"
#include "../configuraciones/ArchivosConfiguracion.h"
#include "../entrenamientos/entrenamiento.h"
#include "../usuarios/usuario.h"
#include "../pagos.h"

/*
    El importe promedio abonado en Efectivo, Tarjeta y Billetera
    electr�nica (se muestran tres resultados).
*/

void reporte1(){
    title("REPORTE 1", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl<<endl;

    Pago uno;
    float Promedio[3]={};
    int Cantidad[3]={};
    for(int x=0;x<CantidadPagos();x++){
        uno=leer_pago(x);
        switch(uno.formapago){
            case 'e':
            case 'E':
                Promedio[0]+=uno.importe;
                Cantidad[0]++;
            break;
            case 't':
            case 'T':
                Promedio[1]+=uno.importe;
                Cantidad[1]++;
            break;
            case 'b':
            case 'B':
                Promedio[2]+=uno.importe;
                Cantidad[2]++;
            break;
        }
    }

    cout<<"El importe promedio en 'E' efectivo es: "<<Promedio[0]/Cantidad[0]<<endl<<endl;
    cout<<"El importe promedio en 'T' tarjeta de credito es: "<<Promedio[1]/Cantidad[1]<<endl<<endl;
    cout<<"El importe promedio en 'B' billetera electonica es: "<<Promedio[2]/Cantidad[2]<<endl<<endl;

    system("pause");
    system("cls");
}

/*
    Listar apellidos y nombres de los usuarios que no hayan abonado
    con Tarjeta pero s� con Efectivo.
*/

bool MedioPago(int);

void reporte2(){
    title("REPORTE 2", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl<<endl;

    usuario uno;
    cout<<"Usuarios no abonaron en efectivo"<<endl<<endl;
    cout<<"--------------------------------"<<endl;
    for(int x=0;x<CantidadUsuarios();x++){
        LeerUsuario(uno, x);
        if(MedioPago(uno.id)){
            cout<<"Nombre: "<<uno.nombre<<endl;
            cout<<"Apellido: "<<uno.apellido<<endl;
            cout<<"--------------------------------"<<endl<<endl;
        }
    }

    system("pause");
    system("cls");
}

bool MedioPago(int id){
    Pago uno;
    bool Estado=false;
    for(int x=0;x<CantidadPagos();x++){
        uno=leer_pago(x);
        if(uno.idusuario==id){
            if(uno.formapago=='t' || uno.formapago=='T'){
                return false;
            }
            Estado=true;
        }
    }
return Estado;
}
