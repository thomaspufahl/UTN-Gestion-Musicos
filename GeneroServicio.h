//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_GENEROSERVICIO_H
#define DEV_PARCIAL_2_LABS_GENEROSERVICIO_H

class GeneroServicio: public Servicio {
private:
    const int anio_de_origen_minimo = 1500;
    Genero *_registros;
    GeneroArchivo _archivo;
public:
    GeneroServicio();
    GeneroServicio(const char* ruta_archivo);
    ~GeneroServicio() { delete[] _registros; }

    Genero *get_registros() { return _registros; }

    bool actualizar_tamanio_registros();
    void actualizar_registros();
    Genero buscar_por_id(int id, bool listar_inactivos = false);

    bool agregar_registro(Genero &genero);
    bool listar_todo(bool listar_inactivos = false);
    bool listar_por_id(int id);
    bool modificar_anio_de_origen(int id, int nuevo_anio_de_origen);
    bool baja_logica(int id);
};

// CONSTRUCTOR
GeneroServicio::GeneroServicio() {
    _ubicacion_archivo = _archivo.get_ruta_archivo();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;
    _registros = new Genero[_cantidad_registros];
}

GeneroServicio::GeneroServicio(const char *ruta_archivo) {
    _archivo.set_ruta_archivo(ruta_archivo);

    _ubicacion_archivo = _archivo.get_ruta_archivo();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;
    _registros = new Genero[_cantidad_registros];
}
// HERRAMIENTAS
bool GeneroServicio::actualizar_tamanio_registros() {
    delete[] _registros;

    _registros = new Genero[_cantidad_registros];
    if (_registros == nullptr) return false;
    return true;
}
void GeneroServicio::actualizar_registros() {
    delete[] _registros;

//    _cantidad_registros = _archivo.obtener_cantidad_registros();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;

    _registros = new Genero[_cantidad_registros];
    if (_registros == nullptr) return;

    Genero registro;
    for (int i = 0; i < _cantidad_registros; ++i) {
        registro = _archivo.leer_registro_por_posicion(i);
        if (registro.get_id() == -1) return;
        _registros[i] = registro;
    }
}

Genero GeneroServicio::buscar_por_id(const int id, const bool listar_inactivos) {
    Genero aux_registro;
    aux_registro.set_id(-1);
    actualizar_registros();

    for (int i = 0; i < _cantidad_registros; ++i) {
        if (_registros[i].get_id() == id && (_registros[i].get_estado() || listar_inactivos)) return _registros[i];
    }

    return aux_registro;
}

bool GeneroServicio::agregar_registro(Genero &genero) {
    actualizar_registros();
    aumentar_id(genero);

    if (buscar_por_id(genero.get_id()).get_id() != -1) return _error.registro_existente(_ubicacion_archivo);

    PaisServicio pais_servicio;
    if (pais_servicio.buscar_por_id(genero.get_pais_de_origen()).get_id() == -1) return _error.dependencia_inexistente(_ubicacion_archivo, "Pais de origen.", "Ingresar un pais existente o agregar el pais a los registros con anterioridad");

    Fecha fecha_actual;
    bool es_valido_anio_de_origen = genero.get_anio_de_origen() >= anio_de_origen_minimo && genero.get_anio_de_origen() <= fecha_actual.get_anio();
    if (!es_valido_anio_de_origen) return _error.dato_invalido(_ubicacion_archivo, "Anio de origen", "Ingresar un anio de origen que se encuentre entre el anio 1500 y el actual inclusive");

    activar_registro(genero);

    bool condicion_exito = _archivo.alta_registro(genero);
    if (!condicion_exito) return false;

    _cantidad_registros = _archivo.obtener_cantidad_registros();
    return condicion_exito;
}

bool GeneroServicio::listar_todo(bool listar_inactivos) {
    actualizar_registros();

    for (int i = 0; i < _cantidad_registros; ++i) {
        if (_registros[i].get_estado() || listar_inactivos) cout << endl << _registros[i] << endl;
    }

    return true;
}

bool GeneroServicio::listar_por_id(int id) {
    Genero registro;
    registro = buscar_por_id(id);
    if (!registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);
    cout << endl << registro << endl;
    return true;
}

bool GeneroServicio::modificar_anio_de_origen(int id, int nuevo_anio_de_origen) {
    if (!_archivo.existe_archivo()) return false;
    if (_cantidad_registros == 0) return _error.no_existen_registros(_ubicacion_archivo);

    Genero nuevo_registro;
    nuevo_registro = buscar_por_id(id);
    if (!nuevo_registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);

    Fecha fecha_actual;
    bool es_valido_anio_de_origen = nuevo_anio_de_origen >= anio_de_origen_minimo && nuevo_anio_de_origen <= fecha_actual.get_anio();
    if (!es_valido_anio_de_origen) return _error.dato_invalido(_ubicacion_archivo, "Anio de origen", "Ingresar un anio de origen que se encuentre entre el anio 1500 y el actual inclusive");

    nuevo_registro.set_anio_de_origen(nuevo_anio_de_origen);

    if (!_archivo.modificar_registro(nuevo_registro)) return _error.modificacion_sin_exito(_ubicacion_archivo);
    return true;
}

bool GeneroServicio::baja_logica(int id) {
    if (!_archivo.existe_archivo()) return false;
    if (_cantidad_registros == 0) return _error.no_existen_registros(_ubicacion_archivo);

    Genero registro;
    registro = buscar_por_id(id);
    if (!registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);

    desactivar_registro(registro);
    if (!_archivo.modificar_registro(registro)) return _error.modificacion_sin_exito(_ubicacion_archivo);
    return true;
}


#endif //DEV_PARCIAL_2_LABS_GENEROSERVICIO_H
