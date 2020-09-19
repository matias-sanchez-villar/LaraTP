#include <iostream>
using namespace std;
#include <cstdio>
#include "confuguracion.h"
#include "../estructura.h"

int GuardamosCopiaUsuario(participante *uno, int cant){
    int correcto;
    FILE *p= fopen("archivos/usuarios.bkp","wb");
        if(p==NULL){
            fclose(p);
            return -1;
        }
    correcto=fwrite(uno, sizeof(participante),cant,p);
    fclose(p);
return correcto;
}

int GuardamosCopiaEntrenamiento(entrenamiento *uno, int cant){
    int correcto;
    FILE *p= fopen("archivos/entrenamientos.bkp","wb");
        if(p==NULL){
            fclose(p);
            return -1;
        }
    correcto=fwrite(uno, sizeof(entrenamiento),cant,p);
    fclose(p);
return correcto;
}

///guardamos copia usuarios
int TotalUsuariosbkp(){
    int total;
    FILE *p=fopen("archivos/usuarios.bkp", "rb");
    if(p==NULL){
        fclose(p);
        return -1;
    }
    fseek(p, 0, SEEK_END);
    total=ftell(p)/sizeof(participante);
return total;
}

int CargarUsuariobkp(struct participante *uno, int cant){
    int correcto;
    FILE *p=fopen("archivos/usuarios.bkp", "rb");
    if(p==NULL){
        fclose(p);
        return -1;
    }
    correcto=fread(uno, sizeof(participante),cant,p);
    fclose(p);
return correcto;
}

int GuardarUsuarioBKP_en_DAt(struct participante *uno, int cant){
    int correcto;
    FILE *p=fopen("archivos/usuarios.dat", "wb");
    if(p==NULL){
        fclose(p);
        return -1;
    }
    correcto=fwrite(uno, sizeof(participante),cant,p);
    fclose(p);
return correcto;
}

///guardamos copia entrenamientos
int TotalEntremanitosbkp(){
    int total;
    FILE *p=fopen("archivos/entrenamientos.bkp", "rb");
    if(p==NULL){
        fclose(p);
        return -1;
    }
    fseek(p, 0, SEEK_END);
    total=ftell(p)/sizeof(entrenamiento);
return total;
}

int CargarEntrenamientosbkp(entrenamiento *uno, int cant){
    int correcto;
    FILE *p=fopen("archivos/entrenamientos.bkp", "rb");
    if(p==NULL){
        fclose(p);
        return -1;
    }
    correcto=fread(uno, sizeof(entrenamiento),cant,p);
    fclose(p);
return correcto;
}

int GuardarEntrenamietoBKP_en_DAt (entrenamiento *uno, int cant){
    int correcto;
    FILE *p=fopen("archivos/entrenamientos.dat", "wb");
    if(p==NULL){
        fclose(p);
        return -1;
    }
    correcto=fwrite(uno, sizeof(entrenamiento),cant,p);
    fclose(p);
return correcto;
}
