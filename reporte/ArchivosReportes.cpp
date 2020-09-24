#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "ArchivosReportes.h"
#include "../estructura.h"
#include "../entrenamiento/entrenamiento.h"
#include "../InterfazGrafica/ui.h"

float TotalTiempo(){
    float total;
    entrenamiento uno;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return -1;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        total+=uno.tiempo;
    }
    fclose(p);
return total;
}

bool MostrarMayoresAlPromedio(float prom){
    short cont=0;
    bool validar;
    entrenamiento uno;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return false;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if(uno.tiempo>prom){
            cont++;
            MostrarEntramiento(uno);
        }
        validar=true;
    }
    fclose(p);
    if(cont==0){
        msj("NINGUN USUARIO PASA EL PROMEDIO", 15, 3, 1, 1);
    }
return validar;
}

int CantidadEntrenamientos(int id){
    int total=0;
    entrenamiento uno;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return -1;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if(uno.idUsuario==id && uno.entrenamiento.anio==2020){
            total++;
        }
    }
    fclose(p);
return total;
}

