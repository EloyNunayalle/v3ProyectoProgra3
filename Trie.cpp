//
// Created by Usuario on 3/12/2024.
//

#include "Trie.h"
#include <algorithm>
#include <cctype>

using namespace std;

Trie::Trie() {
    root = new TrieNode('\0'); // Nodo raíz vacío
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(const string& word, Pelicula* pelicula) {
    TrieNode* node = root;
    for (char c : word) {
        c = tolower(c);
        if (node->children.count(c) == 0) {
            node->children[c] = new TrieNode(c);
        }
        node = node->children[c];
    }
    node->isEndOfWord = true;
    node->peliculas[pelicula]++; // Incrementa la frecuencia
}

unordered_map<Pelicula*, int> Trie::search(const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        c = tolower(c);
        if (node->children.count(c) == 0) {
            return {}; // No encontrado
        }
        node = node->children[c];
    }
    if (node->isEndOfWord) {
        return node->peliculas;
    }
    return {};
}