//
// Created by thoma on 5/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_FECHAERROR_H
#define DEV_PARCIAL_2_LABS_FECHAERROR_H

class FechaError: public Error {
public:
    void fecha_no_valida();
};

void FechaError::fecha_no_valida() {
    _alerta("Ingresa una fecha valida!");
}

#endif //DEV_PARCIAL_2_LABS_FECHAERROR_H
