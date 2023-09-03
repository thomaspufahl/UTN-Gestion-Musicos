//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MENUGENEROS_H
#define DEV_PARCIAL_2_LABS_MENUGENEROS_H

class MenuGeneros: public Menu {
private:
    GeneroServicio _servicio;
    void ejecutar();
public:
    MenuGeneros();
    void operator() () { ejecutar(); }

    void opcion_1_agregar_genero();
    void opcion_2_listar_genero_por_id();
    void opcion_3_listar_todo();
    void opcion_4_modificar_anio_de_origen();
    void opcion_5_eliminar_registro();
};

MenuGeneros::MenuGeneros() {
    set_titulo("GENEROS");
    Cadena opciones[] = {
            "VOLVER AL MENU PRINCIPAL",
            "Agregar genero",
            "Listar genero por ID",
            "Listar todo",
            "Modificar anio de origen",
            "Eliminar registro",
            "\0"
    };
    agregar_opciones(opciones);
}

void MenuGeneros::ejecutar() {
    while (true) {
        system("cls");

        mostrar_menu();

        system("cls");
        switch (_opcion_elegida) {
            case 0:
                return;
            case 1:
                opcion_1_agregar_genero();
                break;
            case 2:
                opcion_2_listar_genero_por_id();
                break;
            case 3:
                opcion_3_listar_todo();
                break;
            case 4:
                opcion_4_modificar_anio_de_origen();
                break;
            case 5:
                opcion_5_eliminar_registro();
                break;
            default:
                break;
        }
    }
}

void MenuGeneros::opcion_1_agregar_genero() {
    system("cls");

    _cartel << "AGREGAR GENERO";
    cout << "Ingresar registro" << endl;
    Genero nuevo_registro;
    cin >> nuevo_registro;

    _cartel.linea();
    if (!_servicio.agregar_registro(nuevo_registro)) return;
    _cartel << "El registro se grabo en el archivo con exito.";

    system("pause");
    system("cls");
}

void MenuGeneros::opcion_2_listar_genero_por_id() {
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

void MenuGeneros::opcion_3_listar_todo() {
    system("cls");

    _cartel << "LISTAR TODO";
    if (!_servicio.listar_todo()) return;
    _cartel << "FIN DE LOS REGISTROS";

    system("pause");
    system("cls");
}

void MenuGeneros::opcion_4_modificar_anio_de_origen() {
    system("cls");

    _cartel << "MODIFICAR ANIO DE ORIGEN DE UN REGISTRO POR ID";
    cout << "Ingresar ID: ";
    int filtro_id;
    cin >> filtro_id;
    _cartel.linea();
    cout << endl << "Ingresar nuevo anio de origen: ";
    int nuevo_anio_de_origen;
    cin >> nuevo_anio_de_origen;
    _cartel.linea();
    if (!_servicio.modificar_anio_de_origen(filtro_id, nuevo_anio_de_origen)) return;
    _cartel << "El anio de origen fue modificado con exito";
    system("pause");
    system("cls");
}

void MenuGeneros::opcion_5_eliminar_registro() {
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

#endif //DEV_PARCIAL_2_LABS_MENUGENEROS_H
