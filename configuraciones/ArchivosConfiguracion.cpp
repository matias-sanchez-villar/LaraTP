#include <iostream>
using namespace std;
#include "ArchivosConfiguracion.h"
#include "configuracion.h"
#include "../estructura.h"

bool GuardarCopiaUsuarioBKP(usuario uno[], int cant){
    int correcto;
    FILE *p= fopen("archivos/usuarios.bkp","wb");
    if(p==NULL){
        return -1;
    }
    correcto=fwrite(uno, sizeof(usuario),cant,p);
    fclose(p);
return correcto;
}

bool GuardarCopiaEntrenamientoBKP(struct entrenamiento uno[], int cant){
    int correcto;
    FILE *p= fopen("archivos/entrenamientos.bkp","wb");
    if(p==NULL){
        return -1;
    }
    correcto=fwrite(uno, sizeof(entrenamiento),cant,p);
    fclose(p);
return correcto;
}

int CantidadUsuariosBKP(){
    int cantidad;
    FILE *p=fopen("archivos/usuarios.bkp","rb");
        if(p==NULL){
            fclose(p);
            return 0;
        }
    fseek(p, 0, SEEK_END);
    cantidad=ftell(p);
return (cantidad/sizeof(usuario));
}

bool LeerUsuarioBKP(usuario &uno, int pos){
    bool estado;
    FILE *p=fopen("archivos/usuarios.bkp","rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(usuario),SEEK_SET);
    estado=fread(&uno, sizeof(usuario),1,p);
    fclose(p);
return estado;
}

bool LeerEntrenamientoBKP(entrenamiento &uno, int pos){
    bool estado;
    FILE *p=fopen("archivos/entrenamientos.bkp","rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(entrenamiento),SEEK_SET);
    estado=fread(&uno, sizeof(entrenamiento),1,p);
    fclose(p);
return estado;
}

int CantidadEntrenamientosBKP(){
    int cantidad;
    FILE *p=fopen("archivos/entrenamientos.bkp","rb");
        if(p==NULL){
            fclose(p);
            return 0;
        }
    fseek(p, 0, SEEK_END);
    cantidad=ftell(p);
return (cantidad/sizeof(entrenamiento));
}

bool GuardarCopiaUsuario(struct usuario uno[], int cant){
    int correcto;
    FILE *p= fopen("archivos/usuarios.dat","wb");
    if(p==NULL){
        return -1;
    }
    correcto=fwrite(uno, sizeof(usuario),cant,p);
    fclose(p);
return correcto;
}

bool GuardarCopiaEntrenamiento(struct entrenamiento uno[], int cant){
        int correcto;
    FILE *p= fopen("archivos/entrenamientos.dat","wb");
    if(p==NULL){
        return -1;
    }
    correcto=fwrite(uno, sizeof(entrenamiento),cant,p);
    fclose(p);
return correcto;
}
