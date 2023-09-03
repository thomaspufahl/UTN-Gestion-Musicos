//
// Created by thoma on 5/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MENUERROR_H
#define DEV_PARCIAL_2_LABS_MENUERROR_H

class MenuError: public Error {
public:
    void opcion_no_valida();
    void cantidad_opcion_no_valido();
};

void MenuError::opcion_no_valida() {
    _alerta("Ingresa una opcion valida");
}

void MenuError::cantidad_opcion_no_valido() {
    _alerta("Ingresa un numero mayo a 0", "Cantidad invalida", true);
}

#endif //DEV_PARCIAL_2_LABS_MENUERROR_H
