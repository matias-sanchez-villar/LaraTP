#include <iostream>
using namespace std;
#include <cstdlib>
#include "confuguracion.h"
#include "../estructura.h"
#include "ArchivosConfiguraciones.h"
#include "../usuario/ArchivosUsuario.h"
#include "../entrenamiento/ArchivosEntrenamientos.h"
#include "../validacion.h"

void CopiaSeguridad(){
    while(ConfirmacionConfiguracion()==false){
        if(continuar()==false){
            return;
        }
        system ("cls");
    }
    ///guardamos usuarios
    int cant=TotalUsuarios();
    if(cant==-1){
        cout<<"-error de archivos 1-"<<endl;
        return;
    }
    participante *uno;
    uno=(participante *)malloc(cant * sizeof(participante));
    if(uno==NULL){
        cout<<"-error de archivos 2-"<<endl;
        free(uno);
        return;
    }
    for(int x=0;x<cant;x++){
        uno[x]=TraerUsuario(x);
    }
    if(GuardamosCopiaUsuario(uno, cant)!=cant){
        cout<<"-error de archivos 3-"<<endl;
        free(uno);
        return;
    }
    free(uno);
    ///guardamos entrenamiento
    cant=TotalEntremanitos();
    if(cant==-1){
        cout<<"-error de archivos 1-"<<endl;
        return;
    }
    entrenamiento *dos;
    dos=(entrenamiento *)malloc(cant * sizeof(entrenamiento));
    if(dos==NULL){
        cout<<"-error de archivos 2-"<<endl;
        free(dos);
        return;
    }
    for(int x=0;x<cant;x++){
        dos[x]=TreaerEntrenamiento(x);
    }
    if(GuardamosCopiaEntrenamiento(dos, cant)!=cant){
        cout<<"-error de archivos 3-"<<endl;
        free(dos);
        return;
    }
    free(dos);
    system ("cls");
    cout<<"-Copia de seguridad guardada-"<<endl;
}

void RestaurarCopia(){
    while(ConfirmacionConfiguracion()==false){
        if(continuar()==false){
            return;
        }
        system ("cls");
    }
    ///cambiamos usuario
    int cant=TotalUsuariosbkp();
    if(cant==-1){
        cout<<"-error de archivos 1-"<<endl;
        return;
    }
    participante *uno;
    uno=(participante *)malloc(cant * sizeof(participante));
    if(uno==NULL){
        cout<<"-error de archivos 2-"<<endl;
        free(uno);
        return;
    }
    if(CargarUsuariobkp(uno, cant)!=cant){
        cout<<"-error de archivos 3-"<<endl;
        free(uno);
        return;
    }
    if(GuardarUsuarioBKP_en_DAt(uno, cant)!=cant){
        cout<<"-error de archivos 4-"<<endl;
        free(uno);
        return;
    }
    free(uno);
    ///cambiamos entrenamiento
    cant=TotalEntremanitosbkp();
    if(cant==-1){
        cout<<"-error de archivos 1-"<<endl;
        return;
    }
    entrenamiento *dos;
    dos=(entrenamiento *)malloc(cant*sizeof(entrenamiento));
    if(dos==NULL){
        cout<<"-error de archivos 2-"<<endl;
        free(dos);
        return;
    }
    if(CargarEntrenamientosbkp(dos, cant)!=cant){
        cout<<"-error de archivos 3-"<<endl;
        return;
    }
    if(GuardarEntrenamietoBKP_en_DAt(dos, cant)!=cant){
        cout<<"-error de archivos 4-"<<endl;
        free(dos);
        return;
    }
    free(dos);
    system ("cls");
    cout<<"-Copia de seguridad guardada-"<<endl;
}
