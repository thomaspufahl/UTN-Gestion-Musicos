//
// Created by thoma on 10/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_INSTRUMENTOSERVICIO_H
#define DEV_PARCIAL_2_LABS_INSTRUMENTOSERVICIO_H

class InstrumentoServicio: public Servicio {
private:
    Instrumento *_registros;
    InstrumentoArchivo _archivo;
public:
    InstrumentoServicio();
    InstrumentoServicio(const char *ruta_archivo);
    ~InstrumentoServicio() { delete[] _registros; }

    Instrumento *get_registros() { return _registros; }

    bool actualizar_tamanio_registros();
    void actualizar_registros();
    Instrumento buscar_por_id(int id, bool listar_inactivos = false);

    bool agregar_registro(Instrumento &instrumento);
    bool listar_todo(bool listar_inactivos = false);
    bool listar_por_id(int id);
    bool modificar_nombre(int id, const Cadena &nuevo_nombre);
    bool baja_logica(int id);
};

// CONSTRUCTOR
InstrumentoServicio::InstrumentoServicio() {
    _ubicacion_archivo = _archivo.get_ruta_archivo();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;
    _registros = new Instrumento[_cantidad_registros];
}

InstrumentoServicio::InstrumentoServicio(const char *ruta_archivo) {
    _archivo.set_ruta_archivo(ruta_archivo);

    _ubicacion_archivo = _archivo.get_ruta_archivo();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;
    _registros = new Instrumento[_cantidad_registros];
}

// HERRAMIENTAS
bool InstrumentoServicio::actualizar_tamanio_registros() {
    delete[] _registros;

    _registros = new Instrumento[_cantidad_registros];
    if (_registros == nullptr) return false;
    return true;
}
void InstrumentoServicio::actualizar_registros() {
    delete[] _registros;

//    _cantidad_registros = _archivo.obtener_cantidad_registros();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;

    _registros = new Instrumento[_cantidad_registros];
    if (_registros == nullptr) return;

    Instrumento registro;
    for (int i = 0; i < _cantidad_registros; ++i) {
        registro = _archivo.leer_registro_por_posicion(i);
        if (registro.get_id() == -1) return;
        _registros[i] = registro;
    }
}
Instrumento InstrumentoServicio::buscar_por_id(const int id, const bool listar_inactivos) {
    Instrumento aux_registro;
    aux_registro.set_id(-1);
    actualizar_registros();

    for (int i = 0; i < _cantidad_registros; ++i) {
        if (_registros[i].get_id() == id && (_registros[i].get_estado() || listar_inactivos)) return _registros[i];
    }

    return aux_registro;
}

// METODOS
bool InstrumentoServicio::agregar_registro(Instrumento &instrumento) {
    actualizar_registros();
    aumentar_id(instrumento);

    if (buscar_por_id(instrumento.get_id()).get_id() != -1) return _error.registro_existente(_ubicacion_archivo);

    activar_registro(instrumento);

    bool condicion_exito = _archivo.alta_registro(instrumento);
    if (!condicion_exito) return false;

    _cantidad_registros = _archivo.obtener_cantidad_registros();
    return condicion_exito;
}

bool InstrumentoServicio::listar_todo(const bool listar_inactivos) {
    actualizar_registros();

    for (int i = 0; i < _cantidad_registros; ++i) {
        if (_registros[i].get_estado() || listar_inactivos) cout << endl << _registros[i] << endl;
    }

    return true;
}

bool InstrumentoServicio::listar_por_id(const int id) {
    Instrumento registro;
    registro = buscar_por_id(id);
    if (!registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);
    cout << endl << registro << endl;
    return true;
}

bool InstrumentoServicio::modificar_nombre(const int id, const Cadena &nuevo_nombre) {
    if (!_archivo.existe_archivo()) return false;
    if (_cantidad_registros == 0) return _error.no_existen_registros(_ubicacion_archivo);

    Instrumento nuevo_registro;
    nuevo_registro = buscar_por_id(id);
    if (!nuevo_registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);
    nuevo_registro.set_nombre(nuevo_nombre);

    if (!_archivo.modificar_registro(nuevo_registro)) return _error.modificacion_sin_exito(_ubicacion_archivo);
    return true;
}

bool InstrumentoServicio::baja_logica(const int id) {
    if (!_archivo.existe_archivo()) return false;
    if (_cantidad_registros == 0) return _error.no_existen_registros(_ubicacion_archivo);

    Instrumento registro;
    registro = buscar_por_id(id);
    if (!registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);

    desactivar_registro(registro);
    if (!_archivo.modificar_registro(registro)) return _error.modificacion_sin_exito(_ubicacion_archivo);
    return true;
}


#endif //DEV_PARCIAL_2_LABS_INSTRUMENTOSERVICIO_H
