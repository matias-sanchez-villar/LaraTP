#include <iostream>
using namespace std;
#include "../estructura.h"
#include "ArchivosUsuarios.h"
#include "usuario.h"

bool GuardarUsuario(usuario uno){
        bool correcto;
    FILE *p= fopen("archivos/usuarios.dat","ab");
        if(p==NULL){
            fclose(p);
            return false;
        }
    correcto=fwrite(&uno, sizeof(usuario),1,p);
    fclose(p);
return correcto;
}

bool ModificarUsuario(usuario uno, int pos){
        bool correcto;
    FILE *p=fopen("archivos/usuarios.dat","rb+");
        if(p==NULL){
            fclose(p);
            return false;
        }
    fseek(p, pos*sizeof(usuario), SEEK_SET);
    correcto= fwrite(&uno, sizeof(usuario), 1, p);
    fclose(p);
return correcto;
}

bool LeerUsuario(usuario &uno, int pos){
    bool estado;
    FILE *p=fopen("archivos/usuarios.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(usuario),SEEK_SET);
    estado=fread(&uno, sizeof(usuario),1,p);
    fclose(p);
return estado;
}

bool ValidarIDusuario(int ID){
    usuario uno;
    int pos=0;
    while(LeerUsuario(uno, pos++)){
        if(uno.id==ID){
            return true;
        }
    }
return false;
}

bool EstadoUsuario(int ID){
    usuario uno;
    int pos=0;
    while(LeerUsuario(uno, pos++)){
        if(uno.id==ID){
            return uno.estado;
        }
    }
return false;
}

int CantidadUsuarios(){
    int cantidad;
    FILE *p=fopen("archivos/usuarios.dat","rb");
        if(p==NULL){
            fclose(p);
            return 0;
        }
    fseek(p, 0, SEEK_END);
    cantidad=ftell(p);
return (cantidad/sizeof(usuario));
}

int BuscarPosUsuario(int ID){
    usuario uno;
    int pos=0;
    while(LeerUsuario(uno, pos)){
        if(uno.id==ID){
            return pos;
        }
        pos++;
    }
return -1;
}
