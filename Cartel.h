//
// Created by thoma on 1/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_CARTEL_H
#define DEV_PARCIAL_2_LABS_CARTEL_H

class Cartel {
private:
    void _cartel(const char *mensaje);
    void _cartel(const Cadena &mensaje);
public:
    void operator<<(const char *mensaje);
    void operator<<(const Cadena &mensaje);
    void linea();
};
// OPERADORES

void Cartel::operator<<(const char *mensaje) {
    _cartel(mensaje);
}
void Cartel::operator<<(const Cadena &mensaje) {
    _cartel(mensaje);
}


// FUNCIONES PRIVADAS
void Cartel::_cartel(const char *mensaje) {
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << mensaje << endl;
    cout << "------------------------------------------" << endl;
}

void Cartel::_cartel(const Cadena &mensaje) {
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << mensaje << endl;
    cout << "------------------------------------------" << endl;
}

void Cartel::linea() {
    cout << "------------------------------------------" << endl;
}


#endif //DEV_PARCIAL_2_LABS_CARTEL_H
