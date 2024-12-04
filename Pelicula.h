//
// Created by Usuario on 3/12/2024.
//

#ifndef VERSION_3_PELICULA_H
#define VERSION_3_PELICULA_H

#include <string>
#include <unordered_set>

using namespace std;

class Pelicula {
public:
    string imdb_id;
    string title;
    string plot_synopsis;
    unordered_set<string> tags;
    string split;
    string synopsis_source;

    Pelicula(const string& imdb_id,
             const string& title,
             const string& plot_synopsis,
             const unordered_set<string>& tags,
             const string& split,
             const string& synopsis_source);
};


#endif //VERSION_3_PELICULA_H
