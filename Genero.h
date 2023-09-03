//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_GENERO_H
#define DEV_PARCIAL_2_LABS_GENERO_H

class Genero: public Entidad {
private:
    char _nombre[30];
    int _pais_de_origen, _anio_de_origen;
public:
    Genero() {};

    const char* get_nombre() { return _nombre; }
    int get_pais_de_origen() const { return _pais_de_origen; }
    int get_anio_de_origen() const { return _anio_de_origen; }

    void set_nombre(Cadena nombre);
    void set_pais_de_origen(const int pais_de_origen) { _pais_de_origen = pais_de_origen; }
    void set_anio_de_origen(const int anio_de_origen) { _anio_de_origen = anio_de_origen; }

    friend ostream &operator<<(ostream &salida, Genero &genero_obj);
    friend istream &operator>>(istream &entrada, Genero &genero_obj);
};

// SETS
void Genero::set_nombre(Cadena nombre) {
    nombre.copiar_cadena_char(_nombre, 30);
}

// COUT y CIN
ostream &operator<<(ostream &salida, Genero &genero_obj) {
    salida << "ID: " << genero_obj.get_id() << endl;
    salida << "Nombre: " << genero_obj._nombre << endl;
    salida << "Pais de origen: " << genero_obj._pais_de_origen << endl;
    salida << "Anio de origen: " << genero_obj._anio_de_origen;
    return salida;
}

istream &operator>>(istream &entrada, Genero &genero_obj) {
    Cadena aux_nombre;
    cout << "Ingresar nombre: ";
    entrada >> aux_nombre;
    aux_nombre.copiar_cadena_char(genero_obj._nombre, 30);

    cout << "Ingresar pais de origen: ";
    entrada >> genero_obj._pais_de_origen;

    cout << "Ingresar anio de origen: ";
    entrada >> genero_obj._anio_de_origen;

    return entrada;
}

#endif //DEV_PARCIAL_2_LABS_GENERO_H
