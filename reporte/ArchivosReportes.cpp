#include <iostream>
using namespace std;
#include <cstdio>
#include "ArchivosReportes.h"
#include "../estructura.h"
#include "../entrenamiento/entrenamiento.h"

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
    bool validar;
    entrenamiento uno;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return false;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if(uno.tiempo>prom){
            MostrarEntramiento(uno);
        }
        validar=true;
    }
    fclose(p);
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
