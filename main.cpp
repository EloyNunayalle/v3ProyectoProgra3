#include "Menu.h"
#include <iostream>
int main() {
    vector<Pelicula*> peliculas;
    Trie trie;
    VerMasTarde vmt;
    unordered_map<string, vector<Pelicula*>> tagIndex;
    Menu::iniciarMenu(peliculas, trie, tagIndex,vmt);
    for (auto pelicula : peliculas) {
        delete pelicula;
    }
    return 0;
}
