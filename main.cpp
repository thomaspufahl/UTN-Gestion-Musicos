#include <iostream>
#include <cstring>

using namespace std;

// UTILIDADES
#include "Cadena.h"
#include "Cartel.h"

// ERRORES
#include "Error.h"
#include "FechaError.h"
#include "MenuError.h"
#include "ArchivoError.h"
#include "ServicioError.h"

// TIPOS
#include "Fecha.h"
#include "Entidad.h"
#include "Archivo.h"
#include "Servicio.h"

// ENTIDAD-ARCHIVO
#include "Instrumento.h"
#include "InstrumentoArchivo.h"

#include "Pais.h"
#include "PaisArchivo.h"

#include "Genero.h"
#include "GeneroArchivo.h"

#include "Musico.h"
#include "MusicoArchivo.h"

// SERVICIOS
#include "InstrumentoServicio.h"
#include "PaisServicio.h"
#include "GeneroServicio.h"
#include "MusicoServicio.h"

// CONFIGURACION
#include "Configuracion.h"

// INTERFACES
#include "Menu.h"

#include "MenuInstrumentos.h"
#include "MenuPaises.h"
#include "MenuGeneros.h"
#include "MenuMusicos.h"
#include "MenuConfiguracion.h"

// *caso reportes
#include "reportes.h"

#include "MenuPrincipal.h"


int main() {

    MenuPrincipal menuPrincipal;
    menuPrincipal();

    return 0;
}
