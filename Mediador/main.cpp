#include <iostream>
#include "chatMediador.h"
#include "Usuario.h"

int main() {
    chatMediador mediador;
    Usuario usuario1(&mediador, "Alicia");
    Usuario usuario2(&mediador, "Cheshire");
    Usuario usuario3(&mediador, "MadHatter");

    mediador.registrar(&usuario1);
    mediador.registrar(&usuario2);
    mediador.registrar(&usuario3);

    usuario1.enviar("Hola a todos!");
    usuario1.enviar("Hola Alicia!");
    usuario1.enviar("Todos estamos locos!");

    return 0;
}

/*Esta actuando como un chat, un metodo de trabajo para com*/

// base de tarea, agregar funcionalidades que solo llegue a un solo usuario
// eliminar vector, o sea, trabajar con una lista enlazada
//nodo y lista