//
// Created by LenovoE450 on 14/9/2024.
//

#include "Biblioteca.h"

Biblioteca::Biblioteca() {}

Biblioteca::~Biblioteca() {}

void Biblioteca::agregarMaterial(Material* material) {
    if (!existeMaterialEnCatalogo(material->getTitulo(), material->getAutor())) {
        catalogo.agregarAlfinal(material);
    } else {
        std::cout << "El material \"" << material->getTitulo() << "\" de " << material->getAutor() << " ya existe en el catalogo." << std::endl;
    }
}

bool Biblioteca::guardarCatalogo(const std::string& nombreArchivo) {
    return ArchivoManager::guardarCatalogo(catalogo, nombreArchivo);
}

void Biblioteca::cargarCatalogo(const std::string& nombreArchivo) {
    std::string infoMateriales;
    ListaDoble<Material*> tempCatalogo;

    if (ArchivoManager::cargarCatalogo(tempCatalogo, nombreArchivo, infoMateriales)) {
        Nodo<Material*>* actual = tempCatalogo.getCabeza();

        while (actual != nullptr) {
            Material* material = actual->getValor();
            if (!existeMaterialEnCatalogo(material->getTitulo(), material->getAutor())) {
                catalogo.agregarAlfinal(material);
            }
            actual = actual->getSiguiente();
        }

        std::cout << "\nCatalogo cargado correctamente desde " << nombreArchivo << ":\n";
        std::cout << infoMateriales;
    } else {
        std::cout << "Error al cargar el catalogo.\n";
    }
}

bool Biblioteca::existeMaterialEnCatalogo(const std::string& titulo, const std::string& autor) const {
    Nodo<Material*>* actual = catalogo.getCabeza();
    while (actual != nullptr) {
        Material* material = actual->getValor();
        if (material->getTitulo() == titulo && material->getAutor() == autor) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

void Biblioteca::mostrarCatalogo() const {
    Nodo<Material*>* actual = catalogo.getCabeza();
    if (actual == nullptr) {
        std::cout << "El catalogo esta vacio.\n";
        return;
    }

    while (actual != nullptr) {
        Material* material = actual->getValor();
        if (Libro* libro = dynamic_cast<Libro*>(material)) {
            std::cout << "Libro: " << libro->getTitulo() << ", Autor: " << libro->getAutor() << ", Paginas: " << libro->getNumPaginas() << std::endl;
        } else if (Revista* revista = dynamic_cast<Revista*>(material)) {
            std::cout << "Revista: " << revista->getTitulo() << ", Autor: " << revista->getAutor() << ", Edicion: " << revista->getNumEdicion() << std::endl;
        }
        actual = actual->getSiguiente();
    }
}
