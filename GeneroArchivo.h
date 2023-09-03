//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_GENEROARCHIVO_H
#define DEV_PARCIAL_2_LABS_GENEROARCHIVO_H

class GeneroArchivo: public Archivo {
public:
    GeneroArchivo(const char *ruta_archivo = "generos.dat");
    Genero leer_registro_por_posicion(int posicion);
    bool alta_registro(const Genero &registro_genero, bool modo_sobreescribir = false);
    bool modificar_registro(const Genero &registro_genero);
};

// CONSTRUCTORES
GeneroArchivo::GeneroArchivo(const char *ruta_archivo) {
    set_ruta_archivo(ruta_archivo);
    set_tamanio_entidad(sizeof(Genero));
}

// HERRAMIENTAS
Genero GeneroArchivo::leer_registro_por_posicion(int posicion) {
    Genero aux_registro;
    aux_registro.set_id(-1);

    FILE *archivo;
    if (!abrir_rb(archivo)) return aux_registro;

    fseek(archivo, get_tamanio_entidad()*posicion, 0);
    fread(&aux_registro, get_tamanio_entidad(), 1, archivo);

    fclose(archivo);

    return aux_registro;
}

bool GeneroArchivo::alta_registro(const Genero &registro_genero, const bool modo_sobreescribir) {
    FILE *archivo;
    bool condicion_exito;

    if (modo_sobreescribir) {
        condicion_exito = abrir_wb(archivo);
    } else {
        existe_archivo(true) ? condicion_exito = abrir_ab(archivo) : condicion_exito = abrir_wb(archivo);
    }

    if (!condicion_exito) return false;

    condicion_exito = fwrite(&registro_genero, get_tamanio_entidad(), 1, archivo);
    fclose(archivo);

    return condicion_exito;
}

bool GeneroArchivo::modificar_registro(const Genero &registro_genero) {
    FILE *archivo;
    if (!abrir_rbplus(archivo)) return false;

    Genero aux_registro;
    while (fread(&aux_registro, get_tamanio_entidad(), 1, archivo)!=0) {
        if (aux_registro.get_id() == registro_genero.get_id()) {
            fseek(archivo, ftell(archivo)-get_tamanio_entidad(), 0);
            break;
        }
    }
    bool fue_modificado = fwrite(&registro_genero, get_tamanio_entidad(), 1, archivo);
    fclose(archivo);

    return fue_modificado;
}

#endif //DEV_PARCIAL_2_LABS_GENEROARCHIVO_H
