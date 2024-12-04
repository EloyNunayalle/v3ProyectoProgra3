//
// Created by Usuario on 3/12/2024.
//

#ifndef VERSION_3_DATALOADER_H
#define VERSION_3_DATALOADER_H


#include <vector>
#include <string>
#include <unordered_map>
#include "Pelicula.h"
#include "Trie.h"

using namespace std;

class DataLoader {
public:
    static void loadMovies(const string& filename,
                           vector<Pelicula*>& peliculas,
                           Trie& trie,
                           unordered_map<string, vector<Pelicula*>>& tagIndex);
};


#endif //VERSION_3_DATALOADER_H
