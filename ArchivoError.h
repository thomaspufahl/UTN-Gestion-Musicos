//
// Created by thoma on 10/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_ARCHIVOERROR_H
#define DEV_PARCIAL_2_LABS_ARCHIVOERROR_H

class ArchivoError: public Error {
public:
    /// FALLAS
    // APERTURA
    bool apertura_rb(const Cadena &ubicacion);
    bool apertura_rbplus(const Cadena &ubicacion);
    bool apertura_wb(const Cadena &ubicacion);
    bool apertura_ab(const Cadena &ubicacion);

    bool archivo_inexistente(const Cadena &ubicacion);
};

bool ArchivoError::apertura_rb(const Cadena &ubicacion) {
    _descripcion = "Error al abrir el archivo en modo lectura(RB).\nProbablemente se deba a que no existe el archivo, pruebe agregando un registro primero.";
    _alerta(_descripcion, ubicacion, true);
    return false;
}

bool ArchivoError::apertura_rbplus(const Cadena &ubicacion) {
    _descripcion = "Error al abrir el archivo en modo lectura + escritura(RB+).\nProbablemente se deba a que no existe el archivo, pruebe agregando un registro primero.";
    _alerta(_descripcion, ubicacion, true);
    return false;
}

bool ArchivoError::apertura_wb(const Cadena &ubicacion) {
    _descripcion = "Error al abrir el archivo en modo escritura(WB).";
    _alerta(_descripcion, ubicacion, true);
    return false;
}

bool ArchivoError::apertura_ab(const Cadena &ubicacion) {
    _descripcion = "Error al abrir el archivo en modo escitura(AB).";
    _alerta(_descripcion, ubicacion, true);
    return false;
}

bool ArchivoError::archivo_inexistente(const Cadena &ubicacion) {
    _descripcion = "No existe el archivo.\nPruebe agregando un registro para crear el archivo.";
    _alerta(_descripcion, ubicacion, true);
    return false;
}


#endif //DEV_PARCIAL_2_LABS_ARCHIVOERROR_H
