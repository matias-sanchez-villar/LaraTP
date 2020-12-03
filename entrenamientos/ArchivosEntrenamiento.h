#ifndef ARCHIVOSENTRENAMIENTO_H_INCLUDED
#define ARCHIVOSENTRENAMIENTO_H_INCLUDED

bool GuardarEntrenamiento(struct entrenamiento);
bool ModificarEntrenamiento(entrenamiento, int);
bool LeerEntrenamiento(entrenamiento &, int);
bool validarIDEntrenaminto(int);
int CantidadEntrenaminto();
int UbicacionEntrenaminto(int);

#endif // ARCHIVOSENTRENAMIENTO_H_INCLUDED
