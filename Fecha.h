//
// Created by thoma on 1/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_FECHA_H
#define DEV_PARCIAL_2_LABS_FECHA_H

class Fecha {
private:
    // Las fechas se construyen a partir del año 1900
    const int _anio_inicio = 1900;
    int _dias_del_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Cadena _nombre_meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    Cadena _nombre_dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    int _dia, _mes, _anio;
    const int _formato_por_defecto = 2;
    int _formato_salida = _formato_por_defecto;
    bool _es_bisiesto(int anio);
public:
    Fecha(int dia = 0, int mes = 0, int anio = 0);

    friend ostream &operator<<(ostream &salida, Fecha &fecha_obj);
    friend istream &operator>>(istream &entrada, Fecha &fecha_obj);

    int get_anio() const { return _anio; }
    int get_mes() const { return _mes; }
    int get_dia() const { return _dia; }
    int get_formato_salida() const { return _formato_salida; }
    bool set_anio(int anio);
    bool set_mes(int mes);
    bool set_dia(int dia);

    /*
    1: Formato Internacional
    2: Formato Local
    3: Formato Texto
    Cualquier otro _valor inicializa el formato a 2
    */
    bool set_formato_salida(int formato);

    // Cambio Febrero en caso de ser anio bisiesto
    int* get_dias_del_mes();

    // Usa la fecha del objeto
    // Devuelve los días
    int convertir_Fecha_a_dias();

    // Pide los días del objeto, se requiere utilizar el conversor de Fecha a días (ln: 29)
    // Convierte el propio objeto
    void convertir_dias_a_Fecha(int dias);

    bool operator>(Fecha &fecha_obj);
    bool operator>=(Fecha &fecha_obj);
    bool operator==(Fecha &fecha_obj);
    Fecha operator+(int dias);
    int operator-(Fecha &fecha_obj);
    void operator+=(int dias);
    Fecha& operator= (const Fecha &fecha_obj);
};

// CONSTRUCTOR
Fecha::Fecha(int dia, int mes, int anio) {
    if (dia == 0) {
        time_t tiempo;
        struct tm *tmPtr;
        tiempo = time(nullptr);
        tmPtr = localtime(&tiempo);
        _anio= tmPtr->tm_year + _anio_inicio;
        _mes= tmPtr->tm_mon + 1;
        _dia=tmPtr->tm_mday;
        return;
    }
    set_anio(anio);
    set_mes(mes);
    set_dia(dia);
}
// CIN y COUT
ostream &operator<<(ostream &salida, Fecha &fecha_obj) {
    switch (fecha_obj._formato_salida) {
        case 1:
            salida << fecha_obj._anio << "/" << fecha_obj._mes << "/" << fecha_obj._dia << endl;
            break;
        case 2:
            salida << fecha_obj._dia << "/" << fecha_obj._mes << "/" << fecha_obj._anio << endl;
            break;
        case 3:
            salida << fecha_obj._nombre_dias[(fecha_obj.convertir_Fecha_a_dias() - 1) % 7] << " " << fecha_obj._dia << " de " << fecha_obj._nombre_meses[fecha_obj._mes - 1] << " de " << fecha_obj._anio << endl;
            break;
        default:
            salida << fecha_obj._anio << "/" << fecha_obj._mes << "/" << fecha_obj._dia << endl;
            break;
    }
    return salida;
}

istream &operator>>(istream &entrada, Fecha &fecha_obj) {
    FechaError error;
    int aux;
    bool realizado_set_dia, realizado_set_mes, realizado_set_anio;

    do {
        cout << endl << "INGRESAR ANIO: ";
        entrada >> aux;
        realizado_set_anio = fecha_obj.set_anio(aux);

        cout << "INGRESAR MES: ";
        entrada >> aux;
        realizado_set_mes = fecha_obj.set_mes(aux);

        cout << "INGRESAR DIA: ";
        entrada >> aux;
        realizado_set_dia = fecha_obj.set_dia(aux);

        if (!realizado_set_anio || !realizado_set_dia || !realizado_set_mes) error.fecha_no_valida();
    } while (!realizado_set_anio || !realizado_set_dia || !realizado_set_mes);

    return entrada;
}

// SETS
bool Fecha::set_anio(const int anio) {
//    Fecha fecha_actual;
//    bool es_valido_anio = anio >= _anio_inicio && anio <= fecha_actual.get_anio();
    bool es_valido_anio = anio >= _anio_inicio;
    if (es_valido_anio) _anio = anio;
    return es_valido_anio;
}

bool Fecha::set_mes(const int mes) {
//    Fecha fecha_actual;
//    bool es_valido_mes = mes >= 1 && mes <= 12 && (mes <= fecha_actual.get_mes() || _anio < fecha_actual.get_anio());
    bool es_valido_mes = mes >= 1 && mes <= 12;
    if (es_valido_mes) _mes = mes;
    return es_valido_mes;
}

bool Fecha::set_dia(const int dia) {
//    Fecha fecha_actual;
//    bool es_valido_dia = dia >= 1 && dia <= get_dias_del_mes()[_mes-1] && (dia <= fecha_actual.get_dia() || _anio < fecha_actual.get_anio() || _mes < fecha_actual.get_mes());
    bool es_valido_dia = dia >= 1 && dia <= get_dias_del_mes()[_mes-1];
    if (es_valido_dia) _dia = dia;
    return es_valido_dia;
}

bool Fecha::set_formato_salida(const int formato) {
    _formato_salida = _formato_por_defecto;
    bool es_formato_valido = formato >= 1 && formato <= 3;
    if (es_formato_valido) _formato_salida = formato;
    return es_formato_valido;
}

// Herramientas

bool Fecha::_es_bisiesto(int anio) {
    bool es_bisiesto = false;

    if (anio%4==0) {
        es_bisiesto = true;
    }
    if (anio%100==0 && anio%400!=0) {
        es_bisiesto = false;
    }

    return es_bisiesto;
}

int *Fecha::get_dias_del_mes() {
    if (_es_bisiesto(_anio)) _dias_del_mes[1] = 29;
    return _dias_del_mes;
}

int Fecha::convertir_Fecha_a_dias() {
    int dias_de_los_anios_bisiestos = 0;
    for (int i = _anio_inicio; i < _anio; ++i) {
        if (_es_bisiesto(i)) dias_de_los_anios_bisiestos++;
    }

    int dias_hasta_la_fecha = (_anio - _anio_inicio) * 365 + dias_de_los_anios_bisiestos + _dia;

    for (int i = 0; i < _mes-1; ++i) {
        dias_hasta_la_fecha += get_dias_del_mes()[i];
    }

    return dias_hasta_la_fecha;
}

void Fecha::convertir_dias_a_Fecha(int dias) {
    int dia_bisiesto;
    int suma = 0, suma_anterior;
    int anio_en_conversion = _anio_inicio;

    while (dias>suma) {
        dia_bisiesto = _es_bisiesto(anio_en_conversion) ? 1 : 0;
        suma_anterior = suma;
        suma += 365 + dia_bisiesto;
        anio_en_conversion++;
    }
    set_anio(anio_en_conversion - 1);

    int dias_anio_actual = dias - suma_anterior;
    int i = 0;
    suma = 0;

    while (dias_anio_actual > suma) {
        suma += get_dias_del_mes()[i++];
    }

    set_mes(i);
    set_dia(dias_anio_actual-(suma-get_dias_del_mes()[i-1]));
}

// Operadores

bool Fecha::operator>(Fecha &fecha_obj) {
    return convertir_Fecha_a_dias()>fecha_obj.convertir_Fecha_a_dias();
}

bool Fecha::operator>=(Fecha &fecha_obj) {
    return convertir_Fecha_a_dias()>=fecha_obj.convertir_Fecha_a_dias();
}

bool Fecha::operator==(Fecha &fecha_obj) {
    bool c = convertir_Fecha_a_dias()==fecha_obj.convertir_Fecha_a_dias();
    return c;
}

Fecha Fecha::operator+(int dias) {
    Fecha nueva_Fecha;
    nueva_Fecha.convertir_dias_a_Fecha(convertir_Fecha_a_dias() + dias);
    return nueva_Fecha;
}

int Fecha::operator-(Fecha &fecha_obj) {
    return convertir_Fecha_a_dias()-fecha_obj.convertir_Fecha_a_dias();
}

void Fecha::operator+=(int dias) {
    convertir_dias_a_Fecha(convertir_Fecha_a_dias()+dias);
}

Fecha &Fecha::operator=(const Fecha &fecha_obj) {
    if (this != &fecha_obj) {
        set_anio(fecha_obj.get_anio());
        set_mes(fecha_obj.get_mes());
        set_dia(fecha_obj.get_dia());
    }
    return *this;
}


#endif //DEV_PARCIAL_2_LABS_FECHA_H
