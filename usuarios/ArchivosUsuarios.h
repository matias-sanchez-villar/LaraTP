#ifndef ARCHIVOSUSUARIOS_H_INCLUDED
#define ARCHIVOSUSUARIOS_H_INCLUDED

bool GuardarUsuario(struct usuario);
bool ModificarUsuario(usuario, int);
bool LeerUsuario(usuario &, int);
bool ValidarIDusuario(int);
bool EstadoUsuario(int);
int CantidadUsuarios();
int BuscarPosUsuario(int);

#endif // ARCHIVOSUSUARIOS_H_INCLUDED
