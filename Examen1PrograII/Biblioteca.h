//
// Created by LenovoE450 on 14/9/2024.
//

#ifndef EXAMENPRUEBA_BIBLIOTECA_H
#define EXAMENPRUEBA_BIBLIOTECA_H
#include "ListaDoble.h"
#include "ArchivoManager.h"
#include "Material.h"

class Biblioteca {
private:
    ListaDoble<Material*> catalogo;
public:
    Biblioteca();
    ~Biblioteca();
    void agregarMaterial(Material* material);
    void mostrarCatalogo() const;
    bool guardarCatalogo(const std::string& nombreArchivo);
    void cargarCatalogo(const std::string& nombreArchivo);
    bool existeMaterialEnCatalogo(const std::string& titulo, const std::string& autor) const;
};

#endif //EXAMENPRUEBA_BIBLIOTECA_H
