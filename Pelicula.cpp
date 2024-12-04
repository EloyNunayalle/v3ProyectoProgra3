//
// Created by Usuario on 3/12/2024.
//

#include "Pelicula.h"

Pelicula::Pelicula(const string& imdb_id,
                   const string& title,
                   const string& plot_synopsis,
                   const unordered_set<string>& tags,
                   const string& split,
                   const string& synopsis_source)
        : imdb_id(imdb_id),
          title(title),
          plot_synopsis(plot_synopsis),
          tags(tags),
          split(split),
          synopsis_source(synopsis_source) {}