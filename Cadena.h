//
// Created by thoma on 1/6/2023.
//

#ifndef DEV_PARCIAL_2_LABS_CADENA_H
#define DEV_PARCIAL_2_LABS_CADENA_H

class Cadena {
private:
    char *_cadena_interna;
    int _tamanio_cadena_interna;
public:

    /// Agregar las sobrecargas de los operadores  >, <, >=, <=

    /// CONSULTAR POR LINEA 134 y 148 en comparación a la 97

    Cadena (const char *cadena = nullptr);
    Cadena (const Cadena &cadena_obj): _cadena_interna(nullptr){ *this=cadena_obj;};
    ~Cadena();

    friend ostream &operator<<(ostream &salida, Cadena &cadena_obj);
    friend ostream &operator<<(ostream &salida, const Cadena &cadena_obj);
    friend istream &operator>>(istream &entrada, Cadena &cadena_obj);

    int get_tamanio_cadena_interna() const { return _tamanio_cadena_interna; }
    const char *get_cadena_interna() const { return _cadena_interna; }
    void set_tamanio_cadena_interna(int tamanio);
    void set_cadena_interna (const char *cadena);
    void set_cadena_interna (const Cadena &cadena_obj);

    Cadena& operator= (const char *cadena);
    Cadena& operator= (const Cadena &cadena_obj);

    bool operator== (const char *cadena);
    bool operator== (const Cadena &cadena_obj);

    void operator+= (const char *cadena);
    void operator+= (const Cadena &cadena_obj);

    Cadena operator+ (const char *cadena);
    Cadena operator+ (const Cadena &cadena_obj);

    void copiar_cadena_char(char *destino, int tamanio_cadena_char);
};
// DESTRUCTOR
Cadena::~Cadena() {
//    if (_cadena_interna == nullptr) _cadena_interna = new char[1];
//    delete[] _cadena_interna;
}

// CONSTRUCTOR
Cadena::Cadena(const char *cadena) {
    if (cadena==nullptr) {
        _cadena_interna = nullptr;
        _tamanio_cadena_interna = 0;
        return;
    }
    set_tamanio_cadena_interna(strlen(cadena)+1);
    _cadena_interna = new char [_tamanio_cadena_interna];
    if (_cadena_interna == nullptr) exit(1);
    strcpy(_cadena_interna, cadena);
}

// CIN y COUT
ostream &operator<<(ostream &salida, Cadena &cadena_obj) {
    salida<<cadena_obj.get_cadena_interna();
    return salida;
}

ostream &operator<<(ostream &salida, const Cadena &cadena_obj) {
    salida<<cadena_obj.get_cadena_interna();
    return salida;
}

istream &operator>>(istream &entrada, Cadena &cadena_obj) {
    char *cadena;
    cadena = new char[256];

    int i;
    fflush(stdin);
    for (i = 0; i < 256; ++i) {
        cadena[i] = cin.get();
        if (cadena[i]=='\n') break;
    }
    cadena[i]='\0';
    fflush(stdin);

//    entrada >> cadena;

    delete cadena_obj._cadena_interna;
    cadena_obj._tamanio_cadena_interna= strlen(cadena) + 1;
    cadena_obj._cadena_interna=new char[cadena_obj._tamanio_cadena_interna];
    strcpy(cadena_obj._cadena_interna, cadena);
    delete cadena;

    return entrada;
}

// SETS

void Cadena::set_tamanio_cadena_interna(const int tamanio) {
    if (tamanio<0) return;
    _tamanio_cadena_interna = tamanio;
}

void Cadena::set_cadena_interna(const char *cadena) {
    delete _cadena_interna;
    if (cadena == nullptr) {
        _cadena_interna = nullptr;
        return;
    }
    _tamanio_cadena_interna = strlen(cadena) + 1;
    _cadena_interna = new char[_tamanio_cadena_interna];
    if (_cadena_interna == nullptr) exit(1);
    strcpy(_cadena_interna, cadena);

}

void Cadena::set_cadena_interna(const Cadena &cadena_obj) {
    delete _cadena_interna;
    if (cadena_obj._cadena_interna == nullptr) {
        _cadena_interna = nullptr;
        return;
    }
    _tamanio_cadena_interna = cadena_obj.get_tamanio_cadena_interna();
    _cadena_interna = new char[_tamanio_cadena_interna];
    if (_cadena_interna == nullptr) exit(1);
    strcpy(_cadena_interna, cadena_obj.get_cadena_interna());
}

// SOBRECARGAS

// =
Cadena &Cadena::operator=(const char *cadena) {
    set_cadena_interna(cadena);
    return *this;
}

Cadena &Cadena::operator=(const Cadena &cadena_obj) {
    if (this != &cadena_obj) {
        if (cadena_obj.get_cadena_interna()) {
            set_cadena_interna(cadena_obj);
        } else {
            delete _cadena_interna;
            _cadena_interna = nullptr;
        }
    }
    return *this;
}

// ==
bool Cadena::operator==(const char *cadena) {
    return strcmp(_cadena_interna, cadena) == 0;
}

bool Cadena::operator==(const Cadena &cadena_obj) {
    return strcmp(_cadena_interna, cadena_obj.get_cadena_interna()) == 0;
}

// +=
void Cadena::operator+=(const char *cadena) {
    char *aux;
    aux = new char[_tamanio_cadena_interna];
    if (aux == nullptr) exit(1);
    strcpy(aux, _cadena_interna);
    delete _cadena_interna;

    _cadena_interna = new char[_tamanio_cadena_interna + strlen(cadena)];
    if (_cadena_interna == nullptr) exit(1);
    strcpy(_cadena_interna, aux);
    strcat(_cadena_interna, cadena);
    delete aux;
}

void Cadena::operator+=(const Cadena &cadena_obj) {
    char *aux;
    aux = new char[_tamanio_cadena_interna];
    if (aux == nullptr) exit(1);
    strcpy(aux, _cadena_interna);
    delete _cadena_interna;

    _tamanio_cadena_interna += cadena_obj.get_tamanio_cadena_interna() - 1;
    _cadena_interna = new char[_tamanio_cadena_interna];
    if (_cadena_interna == nullptr) exit(1);
    strcpy(_cadena_interna, aux);
    strcat(_cadena_interna, cadena_obj.get_cadena_interna());

    delete aux;
}

// +
Cadena Cadena::operator+(const char *cadena) {
    Cadena aux;
    aux.set_tamanio_cadena_interna(_tamanio_cadena_interna + strlen(cadena));
    aux._cadena_interna = new char[aux.get_tamanio_cadena_interna()];
    if (aux._cadena_interna == nullptr) exit(1);
    strcpy(aux._cadena_interna, _cadena_interna);
    strcat(aux._cadena_interna, cadena);
    return aux;
}

Cadena Cadena::operator+(const Cadena &cadena_obj) {
    Cadena aux;
    aux.set_tamanio_cadena_interna(_tamanio_cadena_interna + cadena_obj.get_tamanio_cadena_interna() - 1);
    aux._cadena_interna = new char[aux.get_tamanio_cadena_interna()];
    if (aux._cadena_interna == nullptr) exit(1);
    strcpy(aux._cadena_interna, _cadena_interna);
    strcat(aux._cadena_interna, cadena_obj.get_cadena_interna());
    return aux;
}

void Cadena::copiar_cadena_char(char *destino, const int tamanio_cadena_char) {

    for (int i = 0; i < tamanio_cadena_char-1; ++i) {
        destino[i] = _cadena_interna[i];
    }

    destino[tamanio_cadena_char - 1] = '\0';
}

#endif //DEV_PARCIAL_2_LABS_CADENA_H
