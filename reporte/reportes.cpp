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
    electrónica (se muestran tres resultados).
*/

void reporte1(){
    title("REPORTE 1", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;

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

    cout<<"El importe en 'E' efectivo es: "<<Promedio[0]/Cantidad[0]<<endl;
    cout<<"El importe en 'T' tarjeta de credito es: "<<Promedio[1]/Cantidad[1]<<endl;
    cout<<"El importe en 'B' billetera electonica es: "<<Promedio[2]/Cantidad[2]<<endl<<endl;

    system("pause");
    system("cls");
}

/*
    Listar apellidos y nombres de los usuarios que no hayan abonado
    con Tarjeta pero sí con Efectivo.
*/

void reporte2(){
    title("REPORTE 2", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;



    system("pause");
    system("cls");
}
