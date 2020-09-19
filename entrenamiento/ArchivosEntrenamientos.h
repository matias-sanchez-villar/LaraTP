#ifndef ARCHIVOSENTRENAMIENTOS_H_INCLUDED
#define ARCHIVOSENTRENAMIENTOS_H_INCLUDED

int IDautomatico();
bool GuardarEntrenamieto(struct entrenamiento);
int PosicionIDentrenamiento(int);
entrenamiento TreaerEntrenamiento(int);
bool ModificarEntrenamiento(struct entrenamiento, int);
bool ListarEntrenamientoID(int);
bool ListarEntrenamientoIDusuario(int);
bool ListarTodosLosEntrenamientos();
int TotalEntremanitos();

#endif // ARCHIVOSENTRENAMIENTOS_H_INCLUDED
