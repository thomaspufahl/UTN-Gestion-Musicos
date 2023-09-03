//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_PAISSERVICIO_H
#define DEV_PARCIAL_2_LABS_PAISSERVICIO_H

class PaisServicio: public Servicio {
private:
    Pais *_registros;
    PaisArchivo _archivo;
public:
    PaisServicio();
    PaisServicio(const char* ruta_archivo);
    ~PaisServicio() { delete[] _registros; }

    Pais *get_registros() { return _registros; }

    bool actualizar_tamanio_registros();
    void actualizar_registros();
    Pais buscar_por_id(int id, bool listar_inactivos = false);

    bool agregar_registro(Pais &pais);
    bool listar_todo(bool listar_inactivos = false);
    bool listar_por_id(int id);
    bool modificar_nombre(int id, const Cadena &nuevo_nombre);
    bool baja_logica(int id);
};

// CONSTRUCTORES
PaisServicio::PaisServicio() {
    _ubicacion_archivo = _archivo.get_ruta_archivo();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;
    _registros = new Pais[_cantidad_registros];
}

PaisServicio::PaisServicio(const char *ruta_archivo) {
    _archivo.set_ruta_archivo(ruta_archivo);

    _ubicacion_archivo = _archivo.get_ruta_archivo();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;
    _registros = new Pais[_cantidad_registros];
}

// HERRAMIENTAS
bool PaisServicio::actualizar_tamanio_registros() {
    delete[] _registros;

    _registros = new Pais[_cantidad_registros];
    if (_registros == nullptr) return false;
    return true;
}

void PaisServicio::actualizar_registros() {
    delete[] _registros;

//    _cantidad_registros = _archivo.obtener_cantidad_registros();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;

    _registros = new Pais[_cantidad_registros];
    if (_registros == nullptr) return;

    Pais registro;
    for (int i = 0; i < _cantidad_registros; ++i) {
        registro = _archivo.leer_registro_por_posicion(i);
        if (registro.get_id() == -1) return;
        _registros[i] = registro;
    }
}

Pais PaisServicio::buscar_por_id(const int id, const bool listar_inactivos) {
    Pais aux_registro;
    aux_registro.set_id(-1);
    actualizar_registros();

    for (int i = 0; i < _cantidad_registros; ++i) {
        if (_registros[i].get_id() == id && (_registros[i].get_estado() || listar_inactivos)) return _registros[i];
    }

    return aux_registro;
}

// METODOS
bool PaisServicio::agregar_registro(Pais &pais) {
    actualizar_registros();
    aumentar_id(pais);

    if (buscar_por_id(pais.get_id()).get_id() != -1) return _error.registro_existente(_ubicacion_archivo);

    activar_registro(pais);

    bool condicion_exito = _archivo.alta_registro(pais);
    if (!condicion_exito) return false;

    _cantidad_registros = _archivo.obtener_cantidad_registros();
    return condicion_exito;
}

bool PaisServicio::listar_todo(bool listar_inactivos) {
    actualizar_registros();

    for (int i = 0; i < _cantidad_registros; ++i) {
        if (_registros[i].get_estado() || listar_inactivos) cout << endl << _registros[i] << endl;
    }

    return true;
}

bool PaisServicio::listar_por_id(int id) {
    Pais registro;
    registro = buscar_por_id(id);
    if (!registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);
    cout << endl << registro << endl;
    return true;
}

bool PaisServicio::modificar_nombre(int id, const Cadena &nuevo_nombre) {
    if (!_archivo.existe_archivo()) return false;
    if (_cantidad_registros == 0) return _error.no_existen_registros(_ubicacion_archivo);

    Pais nuevo_registro;
    nuevo_registro = buscar_por_id(id);
    if (!nuevo_registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);
    nuevo_registro.set_nombre(nuevo_nombre);

    if (!_archivo.modificar_registro(nuevo_registro)) return _error.modificacion_sin_exito(_ubicacion_archivo);
    return true;
}

bool PaisServicio::baja_logica(int id) {
    if (!_archivo.existe_archivo()) return false;
    if (_cantidad_registros == 0) return _error.no_existen_registros(_ubicacion_archivo);

    Pais registro;
    registro = buscar_por_id(id);
    if (!registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);

    desactivar_registro(registro);
    if (!_archivo.modificar_registro(registro)) return _error.modificacion_sin_exito(_ubicacion_archivo);
    return true;
}


#endif //DEV_PARCIAL_2_LABS_PAISSERVICIO_H
