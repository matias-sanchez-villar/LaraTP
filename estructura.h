#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

struct fecha{
    int dia, mes, anio;
};

struct usuario{
    bool apto, estado;
    int id;
    float altura, peso;
    char nombre[30], apellido[30], perfil;
    fecha nacimiento;
};

struct entrenamiento{
    int id, idUsuario, actividad;
    float calorias, tiempo;
    fecha entrenamiento;
};

#endif // ESTRUCTURA_H_INCLUDED
