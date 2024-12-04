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
#include "VerMasTarde.h"

class Menu {
public:
    static void iniciarMenu(std::vector<Pelicula*>& peliculas,
                            Trie& trie,
                            std::unordered_map<std::string, std::vector<Pelicula*>>& tagIndex,VerMasTarde& vmt);

private:
    static void buscarPorPalabraClave(Trie& trie,VerMasTarde& vmt);
    static void buscarPorTag(const std::unordered_map<std::string, std::vector<Pelicula*>>& tagIndex, VerMasTarde& vmt);
    static void mostrarPelicula(Pelicula* pelicula,VerMasTarde& vmt);
    static void cargarDatos(const std::string& filename,
                            std::vector<Pelicula*>& peliculas,
                            Trie& trie,
                            std::unordered_map<std::string, std::vector<Pelicula*>>& tagIndex);
};



#endif //VERSION_3_MENU_H
