#include "Menu.h"

int main() {
    vector<Pelicula*> peliculas;
    Trie trie;
    unordered_map<string, vector<Pelicula*>> tagIndex;

    Menu::iniciarMenu(peliculas, trie, tagIndex);


    for (auto pelicula : peliculas) {
        delete pelicula;
    }

    return 0;
}
