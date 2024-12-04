//
// Created by Usuario on 3/12/2024.
//

#ifndef VERSION_3_MENU_H
#define VERSION_3_MENU_H


#include <vector>
#include <unordered_map>
#include <string>
#include "Pelicula.h"
#include "Trie.h"

class Menu {
public:
    static void iniciarMenu(std::vector<Pelicula*>& peliculas,
                            Trie& trie,
                            std::unordered_map<std::string, std::vector<Pelicula*>>& tagIndex);

private:
    static void buscarPorPalabraClave(Trie& trie);
    static void buscarPorTag(const std::unordered_map<std::string, std::vector<Pelicula*>>& tagIndex);
    static void mostrarPelicula(Pelicula* pelicula);
    static void cargarDatos(const std::string& filename,
                            std::vector<Pelicula*>& peliculas,
                            Trie& trie,
                            std::unordered_map<std::string, std::vector<Pelicula*>>& tagIndex);
};



#endif //VERSION_3_MENU_H
