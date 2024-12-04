//
// Created by Usuario on 3/12/2024.
//

#ifndef VERSION_3_UTILS_H
#define VERSION_3_UTILS_H

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Utils {
public:
    // Conjunto global de stopWords
    static std::unordered_set<std::string> stopWords;

    // Cargar stopWords desde un archivo y almacenarlas en el conjunto global
    static void loadStopWords(const std::string& filename);

    // Filtrar texto eliminando stopWords y convirtiendo a minúsculas
    static std::string filterText(const std::string& text);

    // Eliminar espacios en blanco al inicio y al final de una cadena
    static std::string trim(const std::string& str);

    // Dividir una cadena en un conjunto usando un delimitador específico
    static std::unordered_set<std::string> splitToSet(const std::string& str, char delimiter);

    // Dividir una línea CSV en campos, manejando comillas y comas internas
    static std::vector<std::string> splitCSVLine(const std::string& line);


    static vector<string> splitString(const string& str, char delimiter);
};

#endif //VERSION_3_UTILS_H



