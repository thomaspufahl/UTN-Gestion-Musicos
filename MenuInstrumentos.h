//
// Created by thoma on 10/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MENUINSTRUMENTOS_H
#define DEV_PARCIAL_2_LABS_MENUINSTRUMENTOS_H

class MenuInstrumentos: public Menu {
private:
    InstrumentoServicio _servicio;
    void ejecutar();
public:
    MenuInstrumentos();
    void operator() () { ejecutar(); }

    void opcion_1_agregar_instrumento();
    void opcion_2_listar_instrumento_por_id();
    void opcion_3_listar_todo();
    void opcion_4_modificar_nombre();
    void opcion_5_eliminar_registro();
};

MenuInstrumentos::MenuInstrumentos() {
    set_titulo("INSTRUMENTOS");
    Cadena opciones[] = {
            "VOLVER AL MENU PRINCIPAL",
            "Agregar instrumento",
            "Listar instrumento por ID",
            "Listar todo",
            "Modificar nombre",
            "Eliminar registro",
            "\0"
    };
    agregar_opciones(opciones);
}

void MenuInstrumentos::ejecutar() {
    while (true) {
        system("cls");

        mostrar_menu();

        system("cls");
        switch (_opcion_elegida) {
            case 0:
                return;
            case 1:
                opcion_1_agregar_instrumento();
                break;
            case 2:
                opcion_2_listar_instrumento_por_id();
                break;
            case 3:
                opcion_3_listar_todo();
                break;
            case 4:
                opcion_4_modificar_nombre();
                break;
            case 5:
                opcion_5_eliminar_registro();
                break;
            default:
                break;
        }
    }
}

void MenuInstrumentos::opcion_1_agregar_instrumento() {
    system("cls");

    _cartel << "AGREGAR INSTRUMENTO";
    cout << "Ingresar registro" << endl;
    Instrumento nuevo_registro;
    cin >> nuevo_registro;

    _cartel.linea();
    if (!_servicio.agregar_registro(nuevo_registro)) return;
    _cartel << "El registro se grabo en el archivo con exito.";

    system("pause");
    system("cls");
}

void MenuInstrumentos::opcion_2_listar_instrumento_por_id() {
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

void MenuInstrumentos::opcion_3_listar_todo() {
    system("cls");

    _cartel << "LISTAR TODO";
    if (!_servicio.listar_todo()) return;
    _cartel << "FIN DE LOS REGISTROS";

    system("pause");
    system("cls");
}

void MenuInstrumentos::opcion_4_modificar_nombre() {
    system("cls");

    _cartel << "MODIFICAR NOMBRE DE REGISTRO POR ID";
    cout << "Ingresar ID: ";
    int filtro_id;
    cin >> filtro_id;
    _cartel.linea();
    cout << endl << "Ingresar nuevo nombre: ";
    Cadena nuevo_nombre;
    cin >> nuevo_nombre;
    _cartel.linea();
    if (!_servicio.modificar_nombre(filtro_id, nuevo_nombre)) return;
    _cartel << "El _nombre fue modificado con exito";
    system("pause");
    system("cls");
}

void MenuInstrumentos::opcion_5_eliminar_registro() {
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

#endif //DEV_PARCIAL_2_LABS_MENUINSTRUMENTOS_H
