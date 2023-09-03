//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_PAIS_H
#define DEV_PARCIAL_2_LABS_PAIS_H

class Pais: public Entidad {
private:
    char _nombre[30];
    char _continente[30];
public:
    Pais() {};

    const char* get_nombre() { return _nombre; }
    const char* get_continente() { return _continente; }
    void set_nombre(Cadena nombre);
    void set_continente(Cadena continente);

    friend ostream &operator<<(ostream &salida, Pais &pais_obj);
    friend istream &operator>>(istream &entrada, Pais &pais_obj);
};

// SETS,
void Pais::set_nombre(Cadena nombre) {
    nombre.copiar_cadena_char(_nombre, 30);
}
void Pais::set_continente(Cadena continente) {
    continente.copiar_cadena_char(_continente, 30);
}

ostream &operator<<(ostream &salida, Pais &pais_obj) {
    salida << "ID: " << pais_obj.get_id() << endl;
    salida << "Nombre: " << pais_obj._nombre << endl;
    salida << "Continente: " << pais_obj._continente;
    return salida;
}

istream &operator>>(istream &entrada, Pais &pais_obj) {
    Cadena aux_cadena;
    cout << "Ingresar nombre: ";
    entrada  >> aux_cadena;
    aux_cadena.copiar_cadena_char(pais_obj._nombre, 30);

    cout << "Ingresar continente: ";
    entrada >> aux_cadena;
    aux_cadena.copiar_cadena_char(pais_obj._continente, 30);

    return entrada;
}

// COUT y CIN



#endif //DEV_PARCIAL_2_LABS_PAIS_H
