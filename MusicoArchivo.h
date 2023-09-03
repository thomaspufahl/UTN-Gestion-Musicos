//
// Created by thoma on 19/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MUSICOARCHIVO_H
#define DEV_PARCIAL_2_LABS_MUSICOARCHIVO_H

class MusicoArchivo: public Archivo {
public:
    MusicoArchivo(const char* ruta_archivo = "musicos.dat");
    Musico leer_registro_por_posicion(int posicion);
    bool alta_registro(const Musico &registro_musico, bool modo_sobreescribir = false);
    bool modificar_registro(const Musico &registro_musico);
};

// CONSTRUCTOR
MusicoArchivo::MusicoArchivo(const char* ruta_archivo) {
    set_ruta_archivo(ruta_archivo);
    set_tamanio_entidad(sizeof(Musico));
}

// HERRAMIENTAS
Musico MusicoArchivo::leer_registro_por_posicion(int posicion) {
    Musico aux_registro;
    aux_registro.set_id(-1);

    FILE *archivo;
    if (!abrir_rb(archivo)) return aux_registro;

    fseek(archivo, get_tamanio_entidad()*posicion, 0);
    fread(&aux_registro, get_tamanio_entidad(), 1, archivo);

    fclose(archivo);

    return aux_registro;
}

bool MusicoArchivo::alta_registro(const Musico &registro_musico, const bool modo_sobreescribir) {
    FILE *archivo;
    bool condicion_exito;

    if (modo_sobreescribir) {
        condicion_exito = abrir_wb(archivo);
    } else {
        existe_archivo(true) ? condicion_exito = abrir_ab(archivo) : condicion_exito = abrir_wb(archivo);
    }

    if (!condicion_exito) return false;

    condicion_exito = fwrite(&registro_musico, get_tamanio_entidad(), 1, archivo);
    fclose(archivo);

    return condicion_exito;
}

bool MusicoArchivo::modificar_registro(const Musico &registro_musico) {
    FILE *archivo;
    if (!abrir_rbplus(archivo)) return false;

    Musico aux_registro;

    while (fread(&aux_registro, get_tamanio_entidad(), 1, archivo)!=0) {
        if (aux_registro.get_id() == registro_musico.get_id()) {
            fseek(archivo, ftell(archivo)-get_tamanio_entidad(), 0);
            break;
        }
    }

    bool fue_modificado = fwrite(&registro_musico, get_tamanio_entidad(), 1, archivo);
    fclose(archivo);

    return fue_modificado;
}

#endif //DEV_PARCIAL_2_LABS_MUSICOARCHIVO_H
