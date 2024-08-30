#include <iostream>
#include "Persona.h"

int main() {
    Persona *per1 = new Persona(123, "Maria", "Francia");
    Persona *per2 = new Persona(123, "Jose", "Noruega");

    Json::StreamWriterBuilder builder;
    builder["commentStyle"]="None";
    builder["indentation"]="    ";

    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    ofstream salida("prueba.txt");

    Json::Value event;

    Json::Value arreglo(Json::arrayValue);

    event["id"]=per1->getId();
    event["nombre"]=per1->getNombre();
    event["direccion"]=per1->getDireccion();
    arreglo.append(event);

    event["id"]=per2->getId();
    event["nombre"]=per2->getNombre();
    event["direccion"]=per2->getDireccion();
    arreglo.append(event);

    writer->write(arreglo,&salida);
    salida.close();

    Persona temp;

    ifstream  entrada("prueba.txt");
    Json::Value objeto;
    Json::Reader reader;

    /*
    Json::CharReaderBuilder jsonReaderBuilder;
    unique_ptr<Json::CharReader> lector(jsonReaderBuilder.newCharReader());
     */

    reader.parse(entrada,objeto);
    for(int i=0; i < objeto.size(); i++) {
        temp.setId(objeto[i]["id"].asInt());
        //temp.setId()
        temp.setNombre(objeto[i]["nombre"].asString());
        temp.setDireccion(objeto[i]["direccion"].asString());
        std::cout << temp.ToString() << endl;
    }

    entrada.close();

    delete per1;
    delete per2;

    return 0;//ferreteria, herramienta, json, menu...cantidad,id, nombre,precio

}
