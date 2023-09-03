//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_PAISARCHIVO_H
#define DEV_PARCIAL_2_LABS_PAISARCHIVO_H

class PaisArchivo: public Archivo {
public:
    PaisArchivo(const char *ruta_archivo = "paises.dat");
    Pais leer_registro_por_posicion(int posicion);
    bool alta_registro(const Pais &registro_pais, bool modo_sobreescribir = false);
    bool modificar_registro(const Pais &registro_pais);
};

// CONSTRUCTOR
PaisArchivo::PaisArchivo(const char *ruta_archivo) {
    set_ruta_archivo(ruta_archivo);
    set_tamanio_entidad(sizeof(Pais));
}

Pais PaisArchivo::leer_registro_por_posicion(int posicion) {
    Pais aux_registro;
    aux_registro.set_id(-1);

    FILE *archivo;
    if (!abrir_rb(archivo)) return aux_registro;

    fseek(archivo, get_tamanio_entidad()*posicion, 0);
    fread(&aux_registro, get_tamanio_entidad(), 1, archivo);

    fclose(archivo);

    return aux_registro;
}

bool PaisArchivo::alta_registro(const Pais &registro_pais, const bool modo_sobreescribir) {
    FILE *archivo;
    bool condicion_exito;

    if (modo_sobreescribir) {
        condicion_exito = abrir_wb(archivo);
    } else {
        existe_archivo(true) ? condicion_exito = abrir_ab(archivo) : condicion_exito = abrir_wb(archivo);
    }

    if (!condicion_exito) return false;

    condicion_exito = fwrite(&registro_pais, get_tamanio_entidad(), 1, archivo);
    fclose(archivo);

    return condicion_exito;
}

bool PaisArchivo::modificar_registro(const Pais &registro_pais) {
    FILE *archivo;
    if (!abrir_rbplus(archivo)) return false;

    Pais aux_registro;
    while (fread(&aux_registro, get_tamanio_entidad(), 1, archivo)!=0) {
        if (aux_registro.get_id() == registro_pais.get_id()) {
            fseek(archivo, ftell(archivo)-get_tamanio_entidad(), 0);
            break;
        }
    }
    bool fue_modificado = fwrite(&registro_pais, get_tamanio_entidad(), 1, archivo);
    fclose(archivo);

    return fue_modificado;
}

#endif //DEV_PARCIAL_2_LABS_PAISARCHIVO_H
