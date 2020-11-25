#ifndef ARCHIVOSUSUARIO_H_INCLUDED
#define ARCHIVOSUSUARIO_H_INCLUDED

bool BuscarUsuario(int);
int BuscarUsuario(int, bool *);
bool GuardarUsuario(struct participante);
bool ModificarUsuario(struct participante, int);
bool ListarTodosLosUsuarios();
struct participante TraerUsuario(int);
int TotalUsuarios();

#endif // ARCHIVOSUSUARIO_H_INCLUDED
