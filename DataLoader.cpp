#include "DataLoader.h"
#include "Utils.h"
#include <fstream>
#include <sstream>
#include <iostream>      // Se mantiene para usar cerr en caso de errores
#include <stdexcept>

using namespace std;

void DataLoader::loadMovies(const string& filename,
                            vector<Pelicula*>& peliculas,
                            Trie& trie,
                            unordered_map<string, vector<Pelicula*>>& tagIndex) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo CSV: " + filename);
    }

    string line;
    // Leer la línea de encabezado (si existe)
    if (!getline(file, line)) {
        cerr << "El archivo CSV está vacío." << endl;
        file.close();
        return;
    }

    while (getline(file, line)) {
        vector<string> fields = Utils::splitCSVLine(line);

        // Verificar que se hayan leído al menos 6 campos
        if (fields.size() < 6) {
            cerr << "Línea inválida o incompleta: " << line << endl;
            continue;
        }

        // Asignar cada campo a su variable correspondiente
        string imdb_id = Utils::trim(fields[0]);
        string title = Utils::trim(fields[1]);
        string plot_synopsis = Utils::trim(fields[2]);
        string tags_str = Utils::trim(fields[3]);
        string split = Utils::trim(fields[4]);
        string synopsis_source = Utils::trim(fields[5]);

        // Convertir los tags en un conjunto usando '|' como delimitador
        unordered_set<string> tagSet = Utils::splitToSet(tags_str, '|');

        // Crear instancia de Pelicula
        Pelicula* pelicula = new Pelicula(imdb_id, title, plot_synopsis, tagSet, split, synopsis_source);
        peliculas.push_back(pelicula);

        // Indexar por tags
        for (const auto& tag : tagSet) {
            tagIndex[tag].push_back(pelicula);
        }


        // Procesar texto: título y sinopsis para insertar en el Trie
        string full_text = title + " " + plot_synopsis;
        string filtered_text = Utils::filterText(full_text);

        // Dividir en palabras
        stringstream ss_words(filtered_text);
        string word;
        unordered_set<string> words;

        while (ss_words >> word) {
            words.insert(word);
        }

        // Insertar palabras y substrings en el Trie
        for (const auto& w : words) {
            // Insertar la palabra completa
            trie.insert(w, pelicula);

            // Insertar substrings

            for (size_t i = 1; i < w.length(); ++i) {
                string prefix = w.substr(0, i); // Substring desde el inicio hasta la posición i
                trie.insert(prefix, pelicula);
            }

            for (size_t i = 1; i < w.length(); ++i) {
                string substring = w.substr(i);
                trie.insert(substring, pelicula);
            }
        }
    }

    file.close();
}
