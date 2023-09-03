//
// Created by thoma on 20/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_REPORTES_H
#define DEV_PARCIAL_2_LABS_REPORTES_H

class MenuReportes: public Menu {
private:
    Cartel cartel;
    void ejecutar();
public:
    MenuReportes();
    void operator() () { ejecutar(); }

    void punto_1();
    void punto_2();
    void punto_3();
};
MenuReportes::MenuReportes() {
    set_titulo("REPORTES");
    Cadena opciones[] = {
            "VOLVER AL MENU PRINCIPAL",
            "Punto 1",
            "Punto 2",
            "Punto 3",
            "\0"
    };
    agregar_opciones(opciones);
}
void MenuReportes::ejecutar() {
    while (true) {
        system("cls");

        mostrar_menu();

        system("cls");
        switch (_opcion_elegida) {
            case 0:
                return;
            case 1:
                punto_1();
                break;
            case 2:
                punto_2();
                break;
            case 3:
                punto_3();
                break;
            default:
                break;
        }
    }
}







void MenuReportes::punto_1() {
    cartel << "GENERAR ARCHIVO SIN EL SIGUIENTE PAIS y CON ANIO DE ORIGEN MAYOR A 2000: ";
    cout << "Ingresar nombre del pais: ";
    Cadena nombre_pais;
    cin >> nombre_pais;

    int id_pais = -1;
    PaisArchivo archivo_pais;
    for (int i = 0; i < archivo_pais.obtener_cantidad_registros(); ++i) {
        Pais reg = archivo_pais.leer_registro_por_posicion(i);
        if (strcmp(nombre_pais.get_cadena_interna(), reg.get_nombre())==0) id_pais = reg.get_id();
    }


    GeneroArchivo archivo_genero;
    GeneroArchivo nuevo_archivo("generos_v2.dat");
    int primer_reg = 0;
    for (int i = 0; i < archivo_genero.obtener_cantidad_registros(); ++i) {
        Genero reg_genero = archivo_genero.leer_registro_por_posicion(i);
        if (reg_genero.get_anio_de_origen() >= 2000 && reg_genero.get_pais_de_origen()!=id_pais) {
            primer_reg == 0 ? nuevo_archivo.alta_registro(reg_genero, true) : nuevo_archivo.alta_registro(reg_genero);
            primer_reg++;
        }
    }

    if (primer_reg==0) {
        nuevo_archivo.crear_archivo();
        cartel << "No hay registros de genero con diferente pais al ingresado y un anio de origen mayor a 2000";
        system("pause");
        return;
    }

    cartel << "El archivo fue generado, presiona enter para mostrar el archivo";
    system("pause");
    system("cls");
    cartel << "Muestreo del archivo generado";

    for (int i = 0; i < nuevo_archivo.obtener_cantidad_registros(); ++i) {
        Genero reg_nuevo = nuevo_archivo.leer_registro_por_posicion(i);
        cout << reg_nuevo << endl;
    }

    cout << endl;
    cartel << "FIN DEL MUESTREO";
    cout << endl;
    system("pause");
}

void MenuReportes::punto_2() {
    GeneroArchivo archivo;
    const int siglo_xxi=2001;

    int cantidad_anios_siglo_xxi = 0;

    for (int i = 0; i < archivo.obtener_cantidad_registros(); ++i) {
        Genero reg = archivo.leer_registro_por_posicion(i);

        if (reg.get_anio_de_origen() >= siglo_xxi) {
            cantidad_anios_siglo_xxi++;
        }
    }

    if (cantidad_anios_siglo_xxi == 0) cout << "En el arhivo de generos, no hay registros con un anio del siglo xxi" << endl;

    int *anios_siglo_xxi;
    anios_siglo_xxi = new int[cantidad_anios_siglo_xxi]{};
    if (anios_siglo_xxi == nullptr) return;

    int *repetidos_siglo_xxi;
    repetidos_siglo_xxi = new int[cantidad_anios_siglo_xxi]{};
    if (repetidos_siglo_xxi == nullptr) return;


    int cont = 0;
    for (int i = 0; i < archivo.obtener_cantidad_registros(); ++i) {
        Genero reg2 = archivo.leer_registro_por_posicion(i);
        if (reg2.get_anio_de_origen() >= siglo_xxi) {
            anios_siglo_xxi[cont] = reg2.get_anio_de_origen();
            cont++;
        }
    }

    cartel << "DEL SIGLO XXI CON 3 O MAS GENEROS";
    int cont_r;
    int cantidad = 0;
    for (int i = 0; i < cantidad_anios_siglo_xxi; ++i) {
        int anio = anios_siglo_xxi[i];
        cont_r = 0;
        for (int j = 0; j < cantidad_anios_siglo_xxi; ++j) {
            if (anio == anios_siglo_xxi[j]) {
                cont_r++;
                if (cont_r>=3) {
                    cantidad++;
                }
                if (cantidad>=3) {
                    cout << anios_siglo_xxi[i] << endl;
                    cantidad=0;
                }
            }
        }
    }

    delete[] anios_siglo_xxi;
    delete[] repetidos_siglo_xxi;
    cout << endl;
    cartel << "FIN DEL MUESTREO";
    cout << endl;
    system("pause");
}

void MenuReportes::punto_3() {
    GeneroArchivo archivo_nuevo("generos_v2.dat");
    Genero *generos;
    generos = new Genero[archivo_nuevo.obtener_cantidad_registros()];
    if (generos == nullptr) return;

    for (int i = 0; i < archivo_nuevo.obtener_cantidad_registros(); ++i) {
        Genero reg = archivo_nuevo.leer_registro_por_posicion(i);
        generos[i] = reg;
    }

    cartel << "REGISTROS DEL ARCHIVO GENERADO EN EL PUNTO 1";
    for (int i = 0; i < archivo_nuevo.obtener_cantidad_registros(); ++i) {
        cout << generos[i] << endl;
    }

    delete[] generos;

    cout << endl;
    cartel << "FIN DEL MUESTREO";
    cout << endl;
    system("pause");
}


#endif //DEV_PARCIAL_2_LABS_REPORTES_H
