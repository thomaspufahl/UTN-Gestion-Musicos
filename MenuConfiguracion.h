//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MENUCONFIGURACION_H
#define DEV_PARCIAL_2_LABS_MENUCONFIGURACION_H

class MenuConfiguracion: public Menu {
private:
    Cartel _cartel;
    Configuracion _config;
    void ejecutar();
public:
    MenuConfiguracion();
    void operator() () { ejecutar(); }

    void opcion_1_bkp_musicos();
    void opcion_2_bkp_generos();
    void opcion_3_bkp_instrumentos();
    void opcion_4_bkp_paises();
    void opcion_5_restaurar_musicos();
    void opcion_6_restaurar_generos();
    void opcion_7_restaurar_instrumentos();
    void opcion_8_restaurar_paises();
    void opcion_9_establecer_datos_de_inicio();
};

MenuConfiguracion::MenuConfiguracion() {
    set_titulo("CONFIGURACION");
    Cadena opciones[] = {
            "VOLVER AL MENU PRINCIPAL",
            "Copia de seguridad del archivo de musicos",
            "Copia de seguridad del archivo de generos",
            "Copia de seguridad del archivo de instrumentos",
            "Copia de seguridad del archivo de paises",
            "Restaurar el archivo de musicos",
            "Restaurar el archivo de generos",
            "Restaurar el archivo de instrumentos",
            "Restaurar el archivo de paises",
            "Establecer datos de inicio",
            "\0"
    };
    agregar_opciones(opciones);
}

void MenuConfiguracion::ejecutar() {
    while (true) {
        system("cls");

        mostrar_menu();

        system("cls");
        switch (_opcion_elegida) {
            case 0:
                return;
            case 1:
                opcion_1_bkp_musicos();
                break;
            case 2:
                opcion_2_bkp_generos();
                break;
            case 3:
                opcion_3_bkp_instrumentos();
                break;
            case 4:
                opcion_4_bkp_paises();
                break;
            case 5:
                opcion_5_restaurar_musicos();
                break;
            case 6:
                opcion_6_restaurar_generos();
                break;
            case 7:
                opcion_7_restaurar_instrumentos();
                break;
            case 8:
                opcion_8_restaurar_paises();
                break;
            case 9:
                opcion_9_establecer_datos_de_inicio();
                break;
            default:
                break;
        }
    }
}

void MenuConfiguracion::opcion_1_bkp_musicos() {
    _cartel << "BACKUP MUSICOS";
    cout << endl;

    _config.backup_musicos();
}

void MenuConfiguracion::opcion_2_bkp_generos() {
    _cartel << "BACKUP GENEROS";
    cout << endl;

    _config.backup_generos();
}

void MenuConfiguracion::opcion_3_bkp_instrumentos() {
    _cartel << "BACKUP INSTRUMENTOS";
    cout << endl;

    _config.backup_instrumentos();
}

void MenuConfiguracion::opcion_4_bkp_paises() {
    _cartel << "BACKUP PAISES";
    cout << endl;

    _config.backup_paises();
}

void MenuConfiguracion::opcion_5_restaurar_musicos() {
    _cartel << "RESTAURAR MUSICOS";
    cout << endl;

    _config.restaurar_musicos();
}

void MenuConfiguracion::opcion_6_restaurar_generos() {
    _cartel << "RESTAURAR GENEROS";
    cout << endl;

    _config.restaurar_generos();
}

void MenuConfiguracion::opcion_7_restaurar_instrumentos() {
    _cartel << "RESTAURAR INSTRUMENTOS";
    cout << endl;

    _config.restaurar_instrumentos();
}

void MenuConfiguracion::opcion_8_restaurar_paises() {
    _cartel << "RESTAURAR PAISES";
    cout << endl;

    _config.restaurar_paises();
}

void MenuConfiguracion::opcion_9_establecer_datos_de_inicio() {
    _cartel << "ESTABLECER DATOS DE INICIO";
    cout << endl;

    _config.establecer_datos_de_inicio();
}

#endif //DEV_PARCIAL_2_LABS_MENUCONFIGURACION_H
