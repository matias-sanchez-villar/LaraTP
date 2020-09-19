#ifndef ARCHIVOSCONFIGURACIONES_H_INCLUDED
#define ARCHIVOSCONFIGURACIONES_H_INCLUDED

int GuardamosCopiaUsuario(struct participante [], int );
int GuardamosCopiaEntrenamiento(struct entrenamiento [], int );

int TotalUsuariosbkp();
int CargarUsuariobkp(struct participante [], int);
int GuardarUsuarioBKP_en_DAt(struct participante [], int);

int TotalEntremanitosbkp();
int CargarEntrenamientosbkp(struct entrenamiento [], int);
int GuardarEntrenamietoBKP_en_DAt (struct entrenamiento [], int);

#endif // ARCHIVOSCONFIGURACIONES_H_INCLUDED
