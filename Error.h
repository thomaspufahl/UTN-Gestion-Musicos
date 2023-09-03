//
// Created by thoma on 1/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_ERROR_H
#define DEV_PARCIAL_2_LABS_ERROR_H


class Error {
protected:
    Cadena _descripcion;
    void _alerta(const Cadena &descripcion, bool con_cls = false);
    void _alerta(const Cadena &descripcion, const Cadena &titulo, bool con_cls = false);
};

void Error::_alerta(const Cadena &descripcion, bool con_cls) {
    _alerta(descripcion, nullptr, con_cls);
}
void Error::_alerta(const Cadena &descripcion, const Cadena &titulo, bool con_cls) {
    if (con_cls) {
        system("cls");
    }
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "ERROR";
    if (titulo.get_cadena_interna() != nullptr) {
        cout << " | " << titulo;
    }
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << descripcion << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;

    if (con_cls) {
        system("pause");
        system("cls");
    }
}


#endif //DEV_PARCIAL_2_LABS_ERROR_H
