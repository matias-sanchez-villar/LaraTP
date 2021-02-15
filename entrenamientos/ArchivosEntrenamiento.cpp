#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "ArchivosEntrenamiento.h"
#include "../estructura.h"
#include "entrenamiento.h"
#include "../usuarios/ArchivosUsuarios.h"

bool GuardarEntrenamiento(entrenamiento uno){
    bool correcto;
    FILE *p= fopen("archivos/entrenamientos.dat","ab");
        if(p==NULL){
            fclose(p);
            return false;
        }
    correcto=fwrite(&uno, sizeof(entrenamiento),1,p);
    fclose(p);
return correcto;
}

bool ModificarEntrenamiento(entrenamiento uno, int pos){
    bool correcto;
    FILE *p=fopen("archivos/entrenamientos.dat","rb+");
        if(p==NULL){
            fclose(p);
            return false;
        }
    fseek(p, pos*sizeof(entrenamiento), SEEK_SET);
    correcto= fwrite(&uno, sizeof(entrenamiento), 1, p);
    fclose(p);
return correcto;
}

bool LeerEntrenamiento(entrenamiento &uno, int pos){
    bool estado;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(entrenamiento),SEEK_SET);
    estado=fread(&uno, sizeof(entrenamiento),1,p);
    fclose(p);
return estado;
}

bool validarIDEntrenaminto(int ID){
    entrenamiento uno;
    int pos=0;
    while(LeerEntrenamiento(uno, pos++)){
        if(uno.id==ID){
            return true;
        }
    }
return false;
}

int CantidadEntrenaminto(){
    int cantidad;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return 0;
        }
    fseek(p, 0, SEEK_END);
    cantidad=ftell(p);
return (cantidad/sizeof(entrenamiento));
}

int UbicacionEntrenaminto(int ID){
    entrenamiento uno;
    int pos=0;
    while(LeerEntrenamiento(uno, pos)){
        if(uno.id==ID){
            return pos;
        }
        pos++;
    }
return -1;
}



