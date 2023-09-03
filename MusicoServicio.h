//
// Created by thoma on 19/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MUSICOSERVICIO_H
#define DEV_PARCIAL_2_LABS_MUSICOSERVICIO_H

class MusicoServicio: public Servicio {
private:
    Musico *_registros;
    MusicoArchivo _archivo;
public:
    MusicoServicio();
    MusicoServicio(const char* ruta_archivo);
    ~MusicoServicio() { delete[] _registros; }

    Musico *get_registros() { return _registros; }

    bool actualizar_tamanio_registros();
    void actualizar_registros();
    Musico buscar_por_id(int id, bool listar_inactivos = false);

    bool agregar_registro(Musico &musico);
    bool listar_todo(bool listar_inactivos = false);
    bool listar_por_id(int id);
    bool modificar_fecha_de_inscripcion(int id, Fecha &nueva_fecha);
    bool baja_logica(int id);

};

// CONSTRUCTORES
MusicoServicio::MusicoServicio() {
    _ubicacion_archivo = _archivo.get_ruta_archivo();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;
    _registros = new Musico[_cantidad_registros];
}

MusicoServicio::MusicoServicio(const char *ruta_archivo) {
    _archivo.set_ruta_archivo(ruta_archivo);

    _ubicacion_archivo = _archivo.get_ruta_archivo();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;
    _registros = new Musico[_cantidad_registros];
}

// HERRAMIENTAS
bool MusicoServicio::actualizar_tamanio_registros() {
    delete[] _registros;

    _registros = new Musico[_cantidad_registros];
    if (_registros == nullptr) return false;
    return true;
}
void MusicoServicio::actualizar_registros() {
    delete[] _registros;

//    _cantidad_registros = _archivo.obtener_cantidad_registros();
    _archivo.existe_archivo(true) ? _cantidad_registros = _archivo.obtener_cantidad_registros() : _cantidad_registros = 0;

    _registros = new Musico[_cantidad_registros];
    if (_registros == nullptr) return;

    Musico registro;
    for (int i = 0; i < _cantidad_registros; ++i) {
        registro = _archivo.leer_registro_por_posicion(i);
        if (registro.get_id() == -1) return;

        _registros[i] = registro;
    }
}
Musico MusicoServicio::buscar_por_id(const int id, const bool listar_inactivos) {
    Musico aux_registro;
    aux_registro.set_id(-1);
    actualizar_registros();

    for (int i = 0; i < _cantidad_registros; ++i) {
        if (_registros[i].get_id() == id && (_registros[i].get_estado() || listar_inactivos)) return _registros[i];
    }

    return aux_registro;
}

// METODOS
bool MusicoServicio::agregar_registro(Musico &musico) {
    actualizar_registros();
//    Uso los inactivos al buscar debido a que el DNI es un ID que no se incrementa, es estatico
    if (buscar_por_id(musico.get_id()).get_id() != -1) return _error.dato_invalido(_ubicacion_archivo, "DNI", "Ingresar un DNI que no este dato de alta en el sistema.");

    InstrumentoServicio instrumento_servicio;
    if (instrumento_servicio.buscar_por_id(musico.get_instrumento_principal()).get_id() == -1) return _error.dependencia_inexistente(_ubicacion_archivo, "Instrumento principal", "Ingresar un instrumento existente o agregar el instrumento a los registros con anterioridad");

    GeneroServicio genero_servicio;
    if (genero_servicio.buscar_por_id(musico.get_genero()).get_id() == -1) return _error.dependencia_inexistente(_ubicacion_archivo, "Genero", "Ingresar un genero existente o agregar el genero a los registros con anterioridad");

    Fecha fecha_registro;
    fecha_registro = musico.get_fecha_de_inscripcion();
    Fecha fecha_actual;
    if (!(fecha_actual>=fecha_registro)) return _error.dato_invalido(_ubicacion_archivo, "Fecha de inscripcion.", "La fecha ingresada debe ser menor o igual a la actual.");

    if (musico.get_matricula() < 0) return _error.dato_invalido(_ubicacion_archivo, "Matricula.", "El numero ingresado debe ser mayor o igual a 0.");

    activar_registro(musico);

    bool condicion_exito = _archivo.alta_registro(musico);
    if (!condicion_exito) return false;

    _cantidad_registros = _archivo.obtener_cantidad_registros();
    return condicion_exito;
}

bool MusicoServicio::listar_todo(bool listar_inactivos) {
    actualizar_registros();

    for (int i = 0; i < _cantidad_registros; ++i) {
        if (_registros[i].get_estado() || listar_inactivos) cout << endl << _registros[i] << endl;
    }

    return true;
}

bool MusicoServicio::listar_por_id(const int id) {
    Musico registro;
    registro = buscar_por_id(id);
    if (!registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);
    cout << endl << registro << endl;
    return true;
}

bool MusicoServicio::modificar_fecha_de_inscripcion(int id, Fecha &nueva_fecha) {
    if (!_archivo.existe_archivo()) return false;
    if (_cantidad_registros == 0) return _error.no_existen_registros(_ubicacion_archivo);

    Musico nuevo_registro;
    nuevo_registro = buscar_por_id(id);
    if (!nuevo_registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);

//    6 tiene que ser mayor o igual a x
// el caso en false entra al if
//    6 >= x = 7 => false
//    6 >= x = 6 => true
//    6 >= x = 5 => true
// si no funciona puedo plantear algo con la fecha actual
    Fecha fecha_actual;
    if (!(fecha_actual>=nueva_fecha)) return _error.dato_invalido(_ubicacion_archivo, "Fecha de inscripcion.", "La fecha ingresada debe ser menor o igual a la actual.");
    nuevo_registro.set_fecha_de_inscripcion(nueva_fecha);

    if (!_archivo.modificar_registro(nuevo_registro)) return _error.modificacion_sin_exito(_ubicacion_archivo);
    return true;
}

bool MusicoServicio::baja_logica(const int id) {
    if (!_archivo.existe_archivo()) return false;
    if (_cantidad_registros == 0) return _error.no_existen_registros(_ubicacion_archivo);

    Musico registro;
    registro = buscar_por_id(id);
    if (!registro.get_estado()) return _error.registro_inexistente(_ubicacion_archivo);

    desactivar_registro(registro);
    if (!_archivo.modificar_registro(registro)) return _error.modificacion_sin_exito(_ubicacion_archivo);
    return true;
}

#endif //DEV_PARCIAL_2_LABS_MUSICOSERVICIO_H
