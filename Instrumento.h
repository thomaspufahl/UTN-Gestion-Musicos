//
// Created by thoma on 8/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_INSTRUMENTO_H
#define DEV_PARCIAL_2_LABS_INSTRUMENTO_H

class Instrumento: public Entidad {
private:
    char _nombre[30];
    int _clasificacion;
public:
    Instrumento() {};

    const char * get_nombre() { return _nombre; }
    int get_clasificacion() const { return _clasificacion; }
    void set_nombre(Cadena nombre);
    void set_clasificacion(const int clasificacion) { _clasificacion = clasificacion; }

    friend ostream &operator<<(ostream &salida, Instrumento &instrumento_obj);
    friend istream &operator>>(istream &entrada, Instrumento &instrumento_obj);
};

// CONSTRUCTORES

// SETS
void Instrumento::set_nombre(Cadena nombre) {
    nombre.copiar_cadena_char(_nombre, 30);
}

// COUT y CIN
ostream &operator<<(ostream &salida, Instrumento &instrumento_obj) {
    salida << "ID: " <<  instrumento_obj.get_id() << endl;
    salida << "Nombre: " << instrumento_obj._nombre << endl;
    salida << "Clasificacion: " << instrumento_obj._clasificacion;
    return salida;
}

istream &operator>>(istream &entrada, Instrumento &instrumento_obj) {
    Cadena aux_nombre;
    cout << "Ingresar nombre: ";
    entrada >> aux_nombre;
    aux_nombre.copiar_cadena_char(instrumento_obj._nombre, 30);

    cout << "Ingresar clasificacion: ";
    entrada >> instrumento_obj._clasificacion;
    return entrada;
}

#endif //DEV_PARCIAL_2_LABS_INSTRUMENTO_H
