//
// Created by Usuario on 3/12/2024.
//

#include "Utils.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

// Inicialización del conjunto global de stopWords
unordered_set<string> Utils::stopWords;

// Función para cargar stopWords desde un archivo
void Utils::loadStopWords(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo de stopWords: " + filename);
    }

    string word;
    while (getline(file, word)) {
        stopWords.insert(trim(word));
    }

    file.close();
}

// Función para filtrar texto eliminando stopWords y convirtiendo a minúsculas
string Utils::filterText(const string& text) {
    stringstream ss(text);
    string word;
    string filteredText;

    while (ss >> word) {
        word = trim(word);
        // Convertir a minúsculas
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (stopWords.find(word) == stopWords.end()) {
            filteredText += word + " ";
        }
    }

    return trim(filteredText);
}

// Función para eliminar espacios en blanco al inicio y al final de una cadena
string Utils::trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\"");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r\"");
    return str.substr(first, (last - first + 1));
}

// Función para dividir una cadena en un conjunto usando un delimitador específico
unordered_set<string> Utils::splitToSet(const string& str, char delimiter) {
    unordered_set<string> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        token = trim(token);
        if (!token.empty()) {
            result.insert(token);
        }
    }

    return result;
}

// Función para dividir una línea CSV en campos, manejando comillas y comas internas
vector<string> Utils::splitCSVLine(const string& line) {
    vector<string> result;
    string field;
    bool inQuotes = false;

    for (size_t i = 0; i < line.length(); ++i) {
        char c = line[i];

        if (c == '"') {
            if (inQuotes && i + 1 < line.length() && line[i + 1] == '"') {
                // Comillas dobles dentro de un campo, agregar una comilla y saltar la segunda
                field += '"';
                ++i; // Saltar la segunda comilla
            }
            else {
                inQuotes = !inQuotes; // Alternar el estado de comillas
            }
        }
        else if (c == ',' && !inQuotes) {
            // Coma fuera de comillas, fin del campo
            result.push_back(trim(field));
            field.clear();
        }
        else {
            field += c;
        }
    }

    // Agregar el último campo
    result.push_back(trim(field));

    return result;
}

vector<string> Utils::splitString(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        token = trim(token);
        if (!token.empty()) {
            result.push_back(token);
        }
    }

    return result;
}


