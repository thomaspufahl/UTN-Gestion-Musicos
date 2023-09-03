//
// Created by thoma on 18/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_ENTIDAD_H
#define DEV_PARCIAL_2_LABS_ENTIDAD_H

class Entidad {
protected:
    int _id;
    bool _estado;
public:
    Entidad(){};
    int get_id() const { return _id; }
    bool get_estado() const { return _estado; }

    void set_id(const int id) { _id = id; }
    void set_estado(const bool estado) { _estado = estado; }
};

#endif //DEV_PARCIAL_2_LABS_ENTIDAD_H
