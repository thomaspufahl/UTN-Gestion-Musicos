//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_CONFIGURACION_H
#define DEV_PARCIAL_2_LABS_CONFIGURACION_H

class Configuracion {
private:
    Cartel cartel;

    MusicoArchivo _archivo_musico;
    GeneroArchivo _archivo_genero;
    InstrumentoArchivo _archivo_instrumento;
    PaisArchivo _archivo_pais;
public:
    void backup_musicos();
    void backup_generos();
    void backup_instrumentos();
    void backup_paises();

    void restaurar_musicos(const char *ruta_archivo = "musicos.bkp", bool ignorar_mensaje = false);
    void restaurar_generos(const char *ruta_archivo = "generos.bkp", bool ignorar_mensaje = false);
    void restaurar_instrumentos(const char *ruta_archivo = "instrumentos.bkp", bool ignorar_mensaje = false);
    void restaurar_paises(const char *ruta_archivo = "paises.bkp", bool ignorar_mensaje = false);

    void establecer_datos_de_inicio();
};

void Configuracion::backup_musicos() {
    MusicoArchivo backup("musicos.bkp");

    for (int i = 0; i < _archivo_musico.obtener_cantidad_registros(); ++i) {
        Musico reg = _archivo_musico.leer_registro_por_posicion(i);
//        backup.alta_registro(reg);
        i == 0? backup.alta_registro(reg, true) : backup.alta_registro(reg);
    }
    backup.existe_archivo() ? cartel << "COPIA DE SEGURIDAD REALIZADA": cartel << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD";
    system("pause");
}
void Configuracion::backup_generos() {
    GeneroArchivo backup("generos.bkp");

    for (int i = 0; i < _archivo_genero.obtener_cantidad_registros(); ++i) {
        Genero reg = _archivo_genero.leer_registro_por_posicion(i);
//        backup.alta_registro(reg);
        i == 0? backup.alta_registro(reg, true) : backup.alta_registro(reg);
    }
    backup.existe_archivo() ? cartel << "COPIA DE SEGURIDAD REALIZADA": cartel << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD";
    system("pause");
}
void Configuracion::backup_instrumentos() {
    InstrumentoArchivo backup("instrumentos.bkp");

    for (int i = 0; i < _archivo_instrumento.obtener_cantidad_registros(); ++i) {
        Instrumento reg = _archivo_instrumento.leer_registro_por_posicion(i);
//        backup.alta_registro(reg);
        i == 0? backup.alta_registro(reg, true) : backup.alta_registro(reg);
    }
    backup.existe_archivo() ? cartel << "COPIA DE SEGURIDAD REALIZADA": cartel << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD";
    system("pause");
}
void Configuracion::backup_paises() {
    PaisArchivo backup("paises.bkp");

    for (int i = 0; i < _archivo_pais.obtener_cantidad_registros(); ++i) {
        Pais reg = _archivo_pais.leer_registro_por_posicion(i);
//        backup.alta_registro(reg);
        i == 0? backup.alta_registro(reg, true) : backup.alta_registro(reg);
    }
    backup.existe_archivo() ? cartel << "COPIA DE SEGURIDAD REALIZADA": cartel << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD";
    system("pause");
}


void Configuracion::restaurar_musicos(const char* ruta_archivo, const bool ignorar_mensaje) {
    MusicoArchivo backup(ruta_archivo);

    for (int i = 0; i < backup.obtener_cantidad_registros(); ++i) {
        Musico reg = backup.leer_registro_por_posicion(i);
        i == 0? _archivo_musico.alta_registro(reg, true) : _archivo_musico.alta_registro(reg);

    }
    if (!ignorar_mensaje) _archivo_pais.existe_archivo() ? cartel << "BACKUP RESTAURADO": cartel << "NO SE PUDO RESTAURAR EL BACKUP";
    system("pause");
}
void Configuracion::restaurar_generos(const char* ruta_archivo, const bool ignorar_mensaje) {
    GeneroArchivo backup(ruta_archivo);

    for (int i = 0; i < backup.obtener_cantidad_registros(); ++i) {
        Genero reg = backup.leer_registro_por_posicion(i);
        i == 0? _archivo_genero.alta_registro(reg, true) : _archivo_genero.alta_registro(reg);

    }
    if (!ignorar_mensaje) _archivo_pais.existe_archivo() ? cartel << "BACKUP RESTAURADO": cartel << "NO SE PUDO RESTAURAR EL BACKUP";
    system("pause");
}
void Configuracion::restaurar_instrumentos(const char* ruta_archivo, const bool ignorar_mensaje) {
    InstrumentoArchivo backup(ruta_archivo);

    for (int i = 0; i < backup.obtener_cantidad_registros(); ++i) {
        Instrumento reg = backup.leer_registro_por_posicion(i);
        i == 0? _archivo_instrumento.alta_registro(reg, true) : _archivo_instrumento.alta_registro(reg);

    }
    if (!ignorar_mensaje) _archivo_pais.existe_archivo() ? cartel << "BACKUP RESTAURADO": cartel << "NO SE PUDO RESTAURAR EL BACKUP";
    system("pause");
}
void Configuracion::restaurar_paises(const char* ruta_archivo, const bool ignorar_mensaje) {
    PaisArchivo backup(ruta_archivo);

    for (int i = 0; i < backup.obtener_cantidad_registros(); ++i) {
        Pais reg = backup.leer_registro_por_posicion(i);
        i == 0? _archivo_pais.alta_registro(reg, true) : _archivo_pais.alta_registro(reg);

    }
    if (!ignorar_mensaje) _archivo_pais.existe_archivo() ? cartel << "BACKUP RESTAURADO": cartel << "NO SE PUDO RESTAURAR EL BACKUP";
    system("pause");
}


void Configuracion::establecer_datos_de_inicio() {
    restaurar_musicos("ini_musicos.dat", true);
    restaurar_generos("ini_generos.dat", true);
    restaurar_instrumentos("ini_instrumentos.dat", true);
    restaurar_paises("ini_paises.dat", true);

    _archivo_musico.existe_archivo() ? cartel << "DATOS DE INICIO DE MUSICOS ESTABLECIDOS": cartel << "NO SE LOGRO ESTABLECER LOS DATOS DE INICIO DE MUSICOS";
    _archivo_genero.existe_archivo() ? cartel << "DATOS DE INICIO DE GENEROS ESTABLECIDOS": cartel << "NO SE LOGRO ESTABLECER LOS DATOS DE INICIO DE GENEROS";
    _archivo_instrumento.existe_archivo() ? cartel << "DATOS DE INICIO DE INSTRUMENTOS ESTABLECIDOS": cartel << "NO SE LOGRO ESTABLECER LOS DATOS DE INICIO DE INSTRUMENTOS";
    _archivo_pais.existe_archivo() ? cartel << "DATOS DE INICIO DE PAISES ESTABLECIDOS": cartel << "NO SE LOGRO ESTABLECER LOS DATOS DE INICIO DE PAISES";
    system("pause");
}


#endif //DEV_PARCIAL_2_LABS_CONFIGURACION_H
