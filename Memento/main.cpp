#include <iostream>
#include <vector>

class Memento {
private:
    std::string estado;
public:
    Memento(const std::string &estado):estado(estado){}
    std::string getEstado() const {return estado;}
};

class Originador {
private:
    std::string texto;
public:

    std::string getTexto() {
    return texto;
    }

    void setText(const std::string & nuevoTexto) {
        texto = nuevoTexto;
        std::cout << "Texto actualizado: " << getTexto() << std::endl;
    }

    Memento guardarEstado() {
        return Memento(getTexto());
    }

    void restaurarEstado(const Memento& memento) {
        texto = memento.getEstado();
        std::cout << "Texto restaurado: " << getTexto() << std::endl;

    }
};

class Cuidador {
private:
    std::vector<Memento> historial;
public:
    void guardar(const Memento& memento) {
        historial.push_back(memento);
    }

    Memento deshacer() {
        if(historial.empty()) {
            throw std::runtime_error("no hay estados para deshacer!");
        }
        Memento memento = historial.back();
        historial.pop_back();
        return memento;
    }
};

int main(){
    try {
    Originador editor;
    Cuidador cuidador;

    editor.setText("Version 1");
    cuidador.guardar(editor.guardarEstado());

    editor.setText("Version 2");
    cuidador.guardar(editor.guardarEstado());

    editor.setText("Version 3");
    cuidador.guardar(editor.guardarEstado());

    //deshacer version3
    editor.restaurarEstado((cuidador.deshacer()));
    //deshacer version2
    editor.restaurarEstado((cuidador.deshacer()));
    //deshacer version1
    editor.restaurarEstado((cuidador.deshacer()));
    //error
    editor.restaurarEstado((cuidador.deshacer()));

    }catch (std::runtime_error e) {

    std::cout << e.what();

    }

    return 0;
}
