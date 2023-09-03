//
// Created by thoma on 18/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_SERVICIOERROR_H
#define DEV_PARCIAL_2_LABS_SERVICIOERROR_H

class ServicioError: public Error {
public:
    bool dato_invalido(const Cadena &ubicacion, const Cadena &dato_en_falla, const Cadena &posible_solucion);
    bool dependencia_inexistente(const Cadena &ubicacion, const Cadena &dato_en_falla, const Cadena &posible_solucion);
    bool no_existen_registros(const Cadena &ubicacion);
    bool registro_existente(const Cadena &ubicacion);
    bool registro_inexistente(const Cadena &ubicacion);
    bool modificacion_sin_exito(const Cadena &ubicacion);
};

bool ServicioError::dato_invalido(const Cadena &ubicacion, const Cadena &dato_en_falla, const Cadena &posible_solucion) {
    _descripcion = "Al intentar guardar el registro, se detecto el ingreso de un dato considerado invalido.";
    _alerta(_descripcion + "\nDato invalido: " + dato_en_falla + "\nPosible solucion: " + posible_solucion, ubicacion, true);
    return false;
}

bool ServicioError::dependencia_inexistente(const Cadena &ubicacion, const Cadena &dato_en_falla, const Cadena &posible_solucion) {
    _descripcion = "El dato ingresado no es valido, se trata de una dependencia inexistente.\nAntes de guardar el registro se valida la existencia de uno de sus datos con los registros de un archivo externo, el dato ingresado no coincide con ninguno de estos registros.";
    _alerta(_descripcion + "\nDato inexistente: " + dato_en_falla + "\nPosible solucion: " + posible_solucion, ubicacion, true);
    return false;
}

bool ServicioError::no_existen_registros(const Cadena &ubicacion) {
    _descripcion = "No existen registros.";
    _alerta(_descripcion, ubicacion, true);
    return false;
}

bool ServicioError::registro_existente(const Cadena &ubicacion) {
    _descripcion = "Ya existe un registro con igual Identificador(ID correspondiente al tipo de entidad.";
    _alerta(_descripcion, ubicacion, true);
    return false;
}

bool ServicioError::registro_inexistente(const Cadena &ubicacion) {
    _descripcion = "No se encontro registro con el ID ingresado en el archivo.";
    _alerta(_descripcion, ubicacion, true);
    return false;
}

bool ServicioError::modificacion_sin_exito(const Cadena &ubicacion) {
    _descripcion = "No se pudo realizar la modificacion del registro en el archivo.";
    _alerta(_descripcion, ubicacion, true);
    return false;
}

#endif //DEV_PARCIAL_2_LABS_SERVICIOERROR_H
