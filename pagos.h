#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

struct Pago{
    int idusuario;
    int dia, mes, anio;
    char formapago; /// 'E' - Efectivo, 'T' - Tarjeta, 'B' - Billetera electrónica
    float importe;
};

void mostrar_pago(Pago p){
    cout << "IDUsuario: ";
    cout <<  p.idusuario << endl;
    cout << "Dia: ";
    cout <<  p.dia << endl;
    cout << "Mes: ";
    cout <<  p.mes << endl;
    cout << "Año: ";
    cout <<  p.anio << endl;
    cout << "Forma de pago: ";
    cout <<  p.formapago << endl;
    cout << "Importe: ";
    cout <<  p.importe << endl;
}

struct Pago leer_pago(int pos){
    /*
        Realizar la siguiente función para que reciba una posición
        y devuelva el registro del archivo pagos.dat que se ubica
        en dicha posición.
    */
    Pago uno;
    FILE *p=fopen("archivos/pagos.dat","rb");
    if(p==NULL){
        uno.idusuario=-1;
        return uno;
    }
    fseek(p, pos*sizeof(Pago),SEEK_SET);
    fread(&uno, sizeof(Pago),1,p);
    fclose(p);
return uno;
}

int CantidadPagos(){
    int cantidad;
    FILE *p=fopen("archivos/Pagos.dat","rb");
        if(p==NULL){
            fclose(p);
            return 0;
        }
    fseek(p, 0, SEEK_END);
    cantidad=ftell(p);
return (cantidad/sizeof(Pago));
}


#endif // PAGOS_H_INCLUDED
