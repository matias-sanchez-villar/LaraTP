#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "ArchivosEntrenamientos.h"
#include "../estructura.h"
#include "entrenamiento.h"
#include "../usuario/ArchivosUsuario.h"

int IDautomatico(){
    int cantidad;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return 1;
        }
    fseek(p, 0, SEEK_END);
    cantidad=ftell(p);
return (cantidad/sizeof(entrenamiento))+1;
}

bool GuardarEntrenamieto(entrenamiento uno){
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

int PosicionIDentrenamiento(int id){
    entrenamiento uno;
    int pos=0;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return -1;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if (id==uno.id){
            return pos;
        }
        pos++;
    }
return -1;
}

entrenamiento TreaerEntrenamiento(int pos){
    entrenamiento uno;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
                uno.id=-1;
                fclose(p);
                return uno;
        }
    fseek(p, pos*sizeof(entrenamiento), SEEK_SET);
    fread(&uno, sizeof(entrenamiento), 1, p);
    fclose(p);
return uno;
}

bool ModificarEntrenamiento(entrenamiento uno, int pos){
    bool correcto;
    FILE *p=fopen("archivos/entrenamientos.dat","rb+");
        if(p==NULL){
            fclose(p);
            return false;
        }
    fseek(p, pos*sizeof(entrenamiento), SEEK_SET);
    correcto=fwrite(&uno, sizeof(entrenamiento), 1, p);
    fclose(p);
return correcto;
}

bool ListarEntrenamientoID(int id){
    entrenamiento uno;
    FILE*p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return false;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if(id==uno.id){
            MostrarEntramiento(uno);
            fclose(p);
            return true;
        }
    }
    fclose(p);
return false;
}

bool ListarEntrenamientoIDusuario(int id){
    bool mostro=false;
    entrenamiento uno;
    FILE*p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return false;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if(id==uno.idUsuario){
            MostrarEntramiento(uno);
            mostro=true;
        }
    }
    fclose(p);
return mostro;
}

bool ListarTodosLosEntrenamientos(){
    entrenamiento uno;
    FILE*p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return false;
        }
    bool estado;
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        BuscarUsuario(uno.idUsuario, &estado);
        if(estado==true){
            MostrarEntramiento(uno);
        }
    }
    fclose(p);
return true;
}

int TotalEntremanitos(){
    int total;
    FILE*p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return -1;
        }

    fseek(p, 0, SEEK_END);
    total=ftell(p)/sizeof(entrenamiento);
    fclose(p);
return total;
}
