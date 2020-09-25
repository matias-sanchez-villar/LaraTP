#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "ArchivosUsuario.h"
#include "../estructura.h"
#include "usuario.h"

bool BuscarUsuario(int id){
    participante uno;
    FILE *p=fopen("archivos/usuarios.dat","rb");
        if(p==NULL){
            fclose(p);
            return true;
        }
    while(fread(&uno, sizeof(participante),1,p)){
        if(uno.id==id){
            fclose(p);
            return false;
        }
    }
    fclose(p);
return true;
}

int BuscarUsuario(int id, bool * estado){
    participante uno;
    int pos=0;
    FILE *p=fopen("archivos/usuarios.dat","rb");
        if(p==NULL){
            *estado=false;
            fclose(p);
            return -1;
        }
    while(fread(&uno, sizeof(participante),1,p)){
        if(uno.id==id){
            *estado=uno.estado;
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
return pos;
}

bool GuardarUsuario(participante uno){
    bool correcto;
    FILE *p= fopen("archivos/usuarios.dat","ab");
        if(p==NULL){
            fclose(p);
            return false;
        }
    correcto=fwrite(&uno, sizeof(participante),1,p);
    fclose(p);
return correcto;
}

bool ModificarUsuario(struct participante uno, int pos){
    bool correcto;
    FILE *p=fopen("archivos/usuarios.dat","rb+");
        if(p==NULL){
            fclose(p);
            return false;
        }
    fseek(p, pos*sizeof(participante), SEEK_SET);
    correcto= fwrite(&uno, sizeof(participante), 1, p);
    fclose(p);
return correcto;
}

participante TraerUsuario(int pos){
    participante uno;
    FILE *p=fopen("archivos/usuarios.dat","rb");
        if(p==NULL){
            uno.id=-1;
            fclose(p);
            return uno;
        }
    fseek(p, pos*sizeof(participante), SEEK_SET);
    fread(&uno, sizeof(participante), 1, p);
    fclose(p);
return uno;
}

bool ListarTodosLosUsuarios(){
    participante uno;
    bool mostro=false;
    FILE*p=fopen("archivos/usuarios.dat","rb");
        if(p==NULL){
            fclose(p);
            return false;
        }
    while(fread(&uno, sizeof(participante),1,p)){
        if(uno.estado==true){
            mostro=true;
            MostrarUsuario(uno);
        }
    }
    fclose(p);
return mostro;
}

int TotalUsuarios(){
    int total;
    FILE*p=fopen("archivos/usuarios.dat","rb");
        if(p==NULL){
            fclose(p);
            return -1;
        }

    fseek(p, 0, SEEK_END);
    total=ftell(p)/sizeof(participante);
    fclose(p);
return total;
}

void MostarUsuario(int id){
    participante uno;
    int pos=0;
    FILE *p=fopen("archivos/usuarios.dat","rb");
        if(p==NULL){
            fclose(p);
            return;
        }
    while(fread(&uno, sizeof(participante),1,p)){
        if(uno.id==id){
            MostrarUsuario(uno);
        }
        pos++;
    }
    fclose(p);
}
