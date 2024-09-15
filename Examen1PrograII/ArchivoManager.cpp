//
// Created by LenovoE450 on 14/9/2024.
//

#include "ArchivoManager.h"


bool ArchivoManager::guardarCatalogo(const ListaDoble<Material*>& catalogo, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::trunc);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar el catálogo." << std::endl;
        return false;
    }

    Nodo<Material*>* actual = catalogo.getCabeza();
    while (actual != nullptr) {
        Material* material = actual->getValor();
        if (Libro* libro = dynamic_cast<Libro*>(material)) {
            archivo << "Libro;" << libro->getTitulo() << ";" << libro->getAutor() << ";" << std::to_string(libro->getNumPaginas()) << std::endl;
        } else if (Revista* revista = dynamic_cast<Revista*>(material)) {
            archivo << "Revista;" << revista->getTitulo() << ";" << revista->getAutor() << ";" << std::to_string(revista->getNumEdicion()) << std::endl;
        }
        actual = actual->getSiguiente();
    }

    archivo.close();
    return true;
}

bool ArchivoManager::cargarCatalogo(ListaDoble<Material*>& catalogo, const std::string& nombreArchivo, std::string& infoMateriales) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        return false;
    }

    std::string linea;
    std::stringstream infoStream;

    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        std::string tipoMaterial, titulo, autor, datoExtra;

        std::getline(stream, tipoMaterial, ';');
        std::getline(stream, titulo, ';');
        std::getline(stream, autor, ';');
        std::getline(stream, datoExtra, ';');  // numPaginas o numEdicion

        if (tipoMaterial == "Libro") {
            int numPaginas = std::stoi(datoExtra);
            infoStream << "Libro: " << titulo << " de " << autor << ", Paginas: " << numPaginas << "\n";
            catalogo.agregarAlfinal(new Libro(titulo, autor, numPaginas));

        } else if (tipoMaterial == "Revista") {
            int numEdicion = std::stoi(datoExtra);
            infoStream << "Revista: " << titulo << " de " << autor << ", Edicion: " << numEdicion << "\n";
            catalogo.agregarAlfinal(new Revista(titulo, autor, numEdicion));
        }
    }

    infoMateriales = infoStream.str();
    archivo.close();
    return true;
}
