//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MENUMUSICOS_H
#define DEV_PARCIAL_2_LABS_MENUMUSICOS_H

class MenuMusicos: public Menu {
private:
    MusicoServicio _servicio;
    void ejecutar();
public:
    MenuMusicos();
    void operator() () { ejecutar(); }

    void opcion_1_agregar_musico();
    void opcion_2_listar_musico_por_id();
    void opcion_3_listar_todo();
    void opcion_4_modificar_fecha_de_inscripcion();
    void opcion_5_eliminar_registro();
};

MenuMusicos::MenuMusicos() {
    set_titulo("MUSICOS");
    Cadena opciones[] = {
            "VOLVER AL MENU PRINCIPAL",
            "Agregar musico",
            "Listar musico por ID",
            "Listar todo",
            "Modificar fecha de inscripcion",
            "Eliminar registro",
            "\0"
    };
    agregar_opciones(opciones);
}

void MenuMusicos::ejecutar() {
    while (true) {
        system("cls");

        mostrar_menu();

        system("cls");
        switch (_opcion_elegida) {
            case 0:
                return;
            case 1:
                opcion_1_agregar_musico();
                break;
            case 2:
                opcion_2_listar_musico_por_id();
                break;
            case 3:
                opcion_3_listar_todo();
                break;
            case 4:
                opcion_4_modificar_fecha_de_inscripcion();
                break;
            case 5:
                opcion_5_eliminar_registro();
                break;
            default:
                break;
        }
    }
}

void MenuMusicos::opcion_1_agregar_musico() {
    system("cls");

    _cartel << "AGREGAR MUSICO";
    cout << "Ingresar registro" << endl;
    Musico nuevo_registro;
    cin >> nuevo_registro;

    _cartel.linea();
    if (!_servicio.agregar_registro(nuevo_registro)) return;
    _cartel << "El registro se grabo en el archivo con exito.";

    system("pause");
    system("cls");
}

void MenuMusicos::opcion_2_listar_musico_por_id() {
    system("cls");

    _cartel << "LISTAR POR ID";
    int filtro_id;
    cout << "Ingresar ID: ";
    cin >> filtro_id;
    _cartel.linea();

    if (!_servicio.listar_por_id(filtro_id)) return;
    _cartel << "FIN DE LOS REGISTROS";

    system("pause");
    system("cls");
}

void MenuMusicos::opcion_3_listar_todo() {
    system("cls");

    _cartel << "LISTAR TODO";
    if (!_servicio.listar_todo()) return;
    _cartel << "FIN DE LOS REGISTROS";

    system("pause");
    system("cls");
}

void MenuMusicos::opcion_4_modificar_fecha_de_inscripcion() {
    system("cls");

    _cartel << "MODIFICAR FECHA DE INSCRIPCION DE UN REGISTRO POR ID";
    cout << "Ingresar ID: ";
    int filtro_id;
    cin >> filtro_id;
    _cartel.linea();
    cout << endl << "Ingresar nueva fecha de inscripcion: ";
    Fecha nueva_fecha_de_inscripcion;
    cin >> nueva_fecha_de_inscripcion;
    _cartel.linea();
    if (!_servicio.modificar_fecha_de_inscripcion(filtro_id, nueva_fecha_de_inscripcion)) return;
    _cartel << "La fecha de inscripcion fue modificado con exito";
    system("pause");
    system("cls");
}

void MenuMusicos::opcion_5_eliminar_registro() {
    system("cls");

    _cartel << "ELIMINAR REGISTRO POR ID";
    cout << "Ingresar ID: ";
    int filtro_id;
    cin >> filtro_id;
    _cartel.linea();
    if (!_servicio.baja_logica(filtro_id)) return;
    _cartel << "El registro fue eliminado con exito";
    system("pause");
    system("cls");
}

#endif //DEV_PARCIAL_2_LABS_MENUMUSICOS_H
