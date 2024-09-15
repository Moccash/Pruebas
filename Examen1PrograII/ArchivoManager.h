//
// Created by LenovoE450 on 14/9/2024.
//

#ifndef EXAMENPRUEBA_ARCHIVOMANAGER_H
#define EXAMENPRUEBA_ARCHIVOMANAGER_H

#include "ListaDoble.h"
#include "Material.h"
#include "Libro.h"
#include "Revista.h"
#include "Utilities.h"
//esta clase esta manejando unicamente los archivos, respetando el primer principio de SOLID
class ArchivoManager {
public:
    static bool guardarCatalogo(const ListaDoble<Material*>& catalogo, const std::string& nombreArchivo);
    static bool cargarCatalogo(ListaDoble<Material*>& catalogo, const std::string& nombreArchivo, std::string& infoMateriales);

};

#endif //EXAMENPRUEBA_ARCHIVOMANAGER_H
