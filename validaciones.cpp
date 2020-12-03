#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string.h>
#include "validaciones.h"
#include "usuarios/ArchivosUsuarios.h"
#include "estructura.h"

bool continuar(){
    char opcion[3]={};
    cin.ignore();
    cin.getline(opcion, 4, '\n');
    if((strcmp(opcion, "si") && strcmp(opcion, "SI") && strcmp(opcion, "Si") && strcmp(opcion, "sI")) ==0){
        return true;
    }
    else{
        if((strcmp(opcion, "no") && strcmp(opcion, "NO") && strcmp(opcion, "No") && strcmp(opcion, "nO"))==0){
            return false;
        }
    }
    do{
        cout<<endl<<"-Error de ingreso de datos-"<<endl;
        cout<<"Desea continuar (SI/NO): ";
        cin.getline(opcion, 4, '\n');
        if((strcmp(opcion, "si") && strcmp(opcion, "SI") && strcmp(opcion, "Si") && strcmp(opcion, "sI"))==0){
            return true;
        }
        else{
            if((strcmp(opcion, "no") && strcmp(opcion, "NO") && strcmp(opcion, "No") && strcmp(opcion, "nO"))==0){
                return false;
            }
        }
    }while(1!=0);
return true;
}

bool ValidarFecha(int dia, int mes, int anio, bool menor){
    ///valido el positivo
    if((dia<=0)||(mes<=0)||(anio<=0)){
        return false;
    }
    ///valido dia 1-31 mes 1-12
    if(dia>31||mes>12){
        return false;
    }
    ///fecha actual
    time_t tiempo;
    tiempo =time(NULL);
    tm *fecha;
    fecha=localtime(&tiempo);
    ///fecha nacimiento no sea mayor a la fecha actual--con 3 preguntas ((anio), (anio y mes), (anio, mes y dia))
    if((anio>fecha->tm_year+1900)||((anio==fecha->tm_year+1900)&&(mes>fecha->tm_mon+1))||((anio==fecha->tm_year+1900)&&(mes>=fecha->tm_mon+1)&&(dia>fecha->tm_mday))){
        return false;
    }
    if(menor==true){
        ///mayor de 13 anio--con 3 preguntas ((anio), (anio y mes), (anio, mes y dia))
        if((anio>fecha->tm_year+(1900-13))||((anio==fecha->tm_year+(1900-13))&&(mes>fecha->tm_mon+1))||((anio==fecha->tm_year+1887)&&(mes>=fecha->tm_mon+1)&&(dia>fecha->tm_mday))){
            return false;
        }
    }
    int cifras;
    cifras=anio-1000;
    if(cifras<=0){
        return false;
    }
return true;
}

bool ValidarActividadEntrenamiento(int ID, int actividad){
    if(actividad>=1 && actividad<=3){
        return true;
    }
    usuario uno;
    int pos=0;
    while(LeerUsuario(uno, pos++)){
        if(uno.apto==true && uno.id==ID){
            return true;
        }
    }
return false;
}






