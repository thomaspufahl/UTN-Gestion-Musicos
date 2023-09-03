//
// Created by thoma on 19/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MUSICO_H
#define DEV_PARCIAL_2_LABS_MUSICO_H

class Musico: public Entidad {
private:
    char _nombre[30], _apellido[30], _email[30], _telefono[30];
    int _claustro, _instrumento_principal, _genero;
    Fecha _fecha_de_inscripcion;
    float _matricula;
public:
    Musico() {};

    const char* get_nombre() { return _nombre; };
    const char* get_apellido() { return _apellido; };
    const char* get_email() { return _email; };
    const char* get_telefono() { return _telefono; };
    int get_claustro() const { return _claustro; }
    int get_instrumento_principal() const { return _instrumento_principal; }
    int get_genero() const { return _genero; }
    Fecha get_fecha_de_inscripcion() { return _fecha_de_inscripcion; }
    float get_matricula() const { return _matricula; }
    void set_nombre(Cadena nombre);
    void set_apellido(Cadena apellido);
    void set_email(Cadena email);
    void set_telefono(Cadena telefono);
    void set_fecha_de_inscripcion(const Fecha &fecha_de_inscripcion);

    friend ostream &operator<<(ostream &salida, Musico &musico_obj);
    friend istream &operator>>(istream &entrada, Musico &musico_obj);
};

// SETS
void Musico::set_nombre(Cadena nombre) {
    nombre.copiar_cadena_char(_nombre, 30);
}

void Musico::set_apellido(Cadena apellido) {
    apellido.copiar_cadena_char(_apellido, 30);
}

void Musico::set_email(Cadena email) {
    email.copiar_cadena_char(_email, 30);
}

void Musico::set_telefono(Cadena telefono) {
    telefono.copiar_cadena_char(_telefono, 30);
}

void Musico::set_fecha_de_inscripcion(const Fecha &fecha_de_inscripcion) {
    _fecha_de_inscripcion = fecha_de_inscripcion;
}
// CIN y COUT
ostream &operator<<(ostream &salida, Musico &musico_obj) {
    salida << "DNI: " << musico_obj.get_id() << endl;
    salida << "Nombre: " << musico_obj._nombre << endl;
    salida << "Apellido: " << musico_obj._apellido << endl;
    salida << "Email: " << musico_obj._email << endl;
    salida << "Telefono: " << musico_obj._telefono << endl;
    salida << "Claustro: " << musico_obj._claustro << endl;
    salida << "Instrumento Principal: " << musico_obj._instrumento_principal << endl;
    salida << "Genero: " << musico_obj._genero << endl;
    salida << "Fecha de inscripcion: " << musico_obj._fecha_de_inscripcion;
    salida << "Matricula: " << musico_obj._matricula;
    return salida;
}
istream &operator>>(istream &entrada, Musico &musico_obj) {
    Cadena aux_cadena;
    cout << "Ingresar DNI: ";
    entrada >> musico_obj._id;

    cout << "Ingresar nombre: ";
    entrada >> aux_cadena;
    aux_cadena.copiar_cadena_char(musico_obj._nombre, 30);

    cout << "Ingresar apellido: ";
    entrada >> aux_cadena;
    aux_cadena.copiar_cadena_char(musico_obj._apellido, 30);

    cout << "Ingresar email: ";
    entrada >> aux_cadena;
    aux_cadena.copiar_cadena_char(musico_obj._email, 30);

    cout << "Ingresar telefono: ";
    entrada >> aux_cadena;
    aux_cadena.copiar_cadena_char(musico_obj._telefono, 30);

    cout << "Ingresar claustro: ";
    entrada >> musico_obj._claustro;

    cout << "Ingresar instrumento principal: ";
    entrada >> musico_obj._instrumento_principal;

    cout << "Ingresar genero: ";
    entrada >> musico_obj._genero;

    cout << "Ingresar fecha de inscripcion: ";
    entrada >> musico_obj._fecha_de_inscripcion;

    cout << "Ingresar matricula: ";
    entrada >> musico_obj._matricula;
    return entrada;
}

#endif //DEV_PARCIAL_2_LABS_MUSICO_H