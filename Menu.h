//
// Created by thoma on 5/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MENU_H
#define DEV_PARCIAL_2_LABS_MENU_H

class Menu {
protected:
    MenuError _error;

    Cartel _cartel;

    Cadena _titulo;
    Cadena *_opciones;

    int _opcion_elegida;
    int _cantidad_opciones;
public:
    Menu() {};
    Cadena get_titulo() const { return _titulo; };
    int get_opcion_elegida() const { return _opcion_elegida; }
    Cadena* get_opciones() { return _opciones; }
    int get_cantidad_opciones() const { return _cantidad_opciones; }

    void set_titulo(const char* titulo);
    bool set_opcion_elegida(int opcion);
    bool set_cantidad_opciones(int cantidad_opciones);

    void agregar_opciones(Cadena *vector_opciones);
    void mostrar_menu();
};

// SETS
void Menu::set_titulo(const char *titulo) {
    _titulo = titulo;
}

bool Menu::set_opcion_elegida(const int opcion) {
    bool es_opcion_valida = opcion >= 0 && opcion <= _cantidad_opciones;
    if (es_opcion_valida) _opcion_elegida = opcion;
    return es_opcion_valida;
}

bool Menu::set_cantidad_opciones(int cantidad_opciones) {
    bool es_cantidad_valida = cantidad_opciones > 0;
    if (es_cantidad_valida) _cantidad_opciones = cantidad_opciones;
    return es_cantidad_valida;
}

// HERRAMIENTAS

void Menu::agregar_opciones(Cadena *vector_opciones) {

    int i=0;
    while (!(vector_opciones[i]=="\0")) {
        i++;
    }

    if (!set_cantidad_opciones(i+1)) {
        _error.cantidad_opcion_no_valido();
    }

    _opciones = new Cadena[_cantidad_opciones];
    if (_opciones == nullptr) exit(1);
    for (i = 0; i < _cantidad_opciones; ++i) {
        _opciones[i] = vector_opciones[i];
    }
}

void Menu::mostrar_menu() {
    int aux_opcion_elegida;

    _cartel<<_titulo;

    for (int i = 1; i < _cantidad_opciones-1; ++i) {
        cout << i << ". " << _opciones[i] << endl;
    }
    cout << endl;
    cout << "0. " << _opciones[0] << endl;
    cout << "------------------------------------------" << endl;
    cout << "Ingresar opcion: ";
    cin >> aux_opcion_elegida;
    if (!set_opcion_elegida(aux_opcion_elegida)) {
        _error.opcion_no_valida();
    }
}


#endif //DEV_PARCIAL_2_LABS_MENU_H
