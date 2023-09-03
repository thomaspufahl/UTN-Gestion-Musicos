//
// Created by thoma on 5/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_MENUPRINCIPAL_H
#define DEV_PARCIAL_2_LABS_MENUPRINCIPAL_H

class MenuPrincipal: public Menu {
private:
    void ejecutar();
public:
    MenuPrincipal();
    void operator() () {
        ejecutar();
    }
};

MenuPrincipal::MenuPrincipal() {
    set_titulo("MENU PRINCIPAL");
    Cadena opciones[] = {
            "SALIR",
            "Musicos",
            "Genero",
            "Instrumentos",
            "Paises",
            "Reportes",
            "Configuracion",
            "\0"
    };
    agregar_opciones(opciones);
}

void MenuPrincipal::ejecutar() {
    MenuInstrumentos submenu_instrumentos;
    MenuPaises submenu_paises;
    MenuGeneros submenu_generos;
    MenuMusicos submenu_musicos;
    MenuReportes submenu_reportes;
    MenuConfiguracion submenu_configuracion;

    while (true) {
        system("cls");

        mostrar_menu();

        system("cls");
        switch (_opcion_elegida) {
            case 0:
                return;
            case 1:
                submenu_musicos();
                break;
            case 2:
                submenu_generos();
                break;
            case 3:
                submenu_instrumentos();
                break;
            case 4:
                submenu_paises();
                break;
            case 5:
                submenu_reportes();
                break;
            case 6:
                submenu_configuracion();
                break;
            default:
                break;
        }
    }
}

#endif //DEV_PARCIAL_2_LABS_MENUPRINCIPAL_H
