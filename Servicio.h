//
// Created by thoma on 18/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_SERVICIO_H
#define DEV_PARCIAL_2_LABS_SERVICIO_H

class Servicio {
protected:
    ServicioError _error;
    Cartel _cartel;
    Cadena _ubicacion_archivo;
    int _cantidad_registros;
public:
    Cadena get_ubicacion_archivo() { return _ubicacion_archivo; }

    void aumentar_id(Entidad &entidad) const { entidad.set_id(_cantidad_registros+1); }

    void activar_registro(Entidad &entidad) const { entidad.set_estado(true); }

    void desactivar_registro(Entidad &entidad) const{ entidad.set_estado(false); }

    int get_cantidad_registros() const { return _cantidad_registros; }

    void set_cantidad_registros(const int cantidad_registros) { _cantidad_registros = cantidad_registros;}
};

#endif //DEV_PARCIAL_2_LABS_SERVICIO_H
