#ifndef ARCHIVOSCONFIGURACION_H_INCLUDED
#define ARCHIVOSCONFIGURACION_H_INCLUDED

bool GuardarCopiaUsuarioBKP(struct usuario [], int);
bool GuardarCopiaEntrenamientoBKP(struct entrenamiento [], int);

int CantidadUsuariosBKP();
int CantidadEntrenamientosBKP();
bool LeerUsuarioBKP(struct usuario &, int);
bool LeerEntrenamientoBKP(struct entrenamiento &, int);

bool GuardarCopiaUsuario(struct usuario [], int);
bool GuardarCopiaEntrenamiento(struct entrenamiento [], int);

#endif // ARCHIVOSCONFIGURACION_H_INCLUDED
