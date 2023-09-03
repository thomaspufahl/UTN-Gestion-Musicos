//
// Created by thoma on 8/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_ARCHIVO_H
#define DEV_PARCIAL_2_LABS_ARCHIVO_H

class Archivo {
private:
    int _tamanio_entidad;
    Cadena _ruta_archivo;
    ArchivoError _error;
protected:
    bool abrir_rb(FILE *&archivo);
    bool abrir_rbplus(FILE *&archivo);
    bool abrir_wb(FILE *&archivo);
    bool abrir_ab(FILE *&archivo);
public:
    int get_tamanio_entidad() const { return _tamanio_entidad; }
    Cadena get_ruta_archivo() { return _ruta_archivo; }
    void set_tamanio_entidad(int tamanio_entidaad);
    void set_ruta_archivo(const char* ruta_archivo);

// HERRAMIENTAS
    int obtener_cantidad_registros();
    bool existe_archivo(bool ignorar_error = false);
    Entidad leer_entidad_por_posicion(int posicion);

//    Mantenimiento del archivo
    bool crear_archivo();
};

// SETS
void Archivo::set_ruta_archivo(const char *ruta_archivo) {
    _ruta_archivo = ruta_archivo;
}
void Archivo::set_tamanio_entidad(int tamanio_entidaad) {
    _tamanio_entidad = tamanio_entidaad;
}

// APERTURAS
bool Archivo::abrir_rb(FILE *&archivo) {
    archivo = fopen(_ruta_archivo.get_cadena_interna(), "rb");
    if (archivo == nullptr) return _error.apertura_rb(_ruta_archivo);
    return true;
}
bool Archivo::abrir_rbplus(FILE *&archivo) {
    archivo = fopen(_ruta_archivo.get_cadena_interna(), "rb+");
    if (archivo == nullptr) return _error.apertura_rbplus(_ruta_archivo);
    return true;
}
bool Archivo::abrir_wb(FILE *&archivo) {
    archivo = fopen(_ruta_archivo.get_cadena_interna(), "wb");
    if (archivo == nullptr) return _error.apertura_wb(_ruta_archivo);
    return true;
}
bool Archivo::abrir_ab(FILE *&archivo) {
    archivo = fopen(_ruta_archivo.get_cadena_interna(), "ab");
    if (archivo == nullptr) return _error.apertura_ab(_ruta_archivo);
    return true;
}

// HERRAMIENTAS
bool Archivo::existe_archivo(bool ignorar_error) {
    FILE *archivo;
    archivo = fopen(get_ruta_archivo().get_cadena_interna(), "rb");
    if (archivo == nullptr) {
        if (ignorar_error) {
            return false;
        }
        return _error.archivo_inexistente(_ruta_archivo);
    }
    fclose(archivo);
    return true;
}

int Archivo::obtener_cantidad_registros() {
    FILE *archivo;
    if (!abrir_rb(archivo)) return -1;

    fseek(archivo, 0, 2);
    int tamanio = ftell(archivo);
    fclose(archivo);

    return tamanio/_tamanio_entidad;
}

Entidad Archivo::leer_entidad_por_posicion(int posicion) {
    Entidad aux_entidad;
    aux_entidad.set_id(-1);

    FILE *archivo;
    if (!abrir_rb(archivo)) return aux_entidad;

    fseek(archivo, sizeof(Entidad)*posicion, 0 );
    fread(&aux_entidad, sizeof(Entidad), 1, archivo);

    fclose(archivo);

    return aux_entidad;
}

// MANTENIMIENTO
bool Archivo::crear_archivo() {
    FILE *archivo;
    if (!abrir_wb(archivo)) return false;
    fclose(archivo);
    return true;
}

#endif //DEV_PARCIAL_2_LABS_ARCHIVO_H
