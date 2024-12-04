//
// Created by Usuario on 3/12/2024.
//

#ifndef VERSION_3_TRIENODE_H
#define VERSION_3_TRIENODE_H

#include <unordered_map>
#include <vector>
#include "Pelicula.h"

using namespace std;

class TrieNode {
public:
    char character;
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    unordered_map<Pelicula*, int> peliculas;

    TrieNode(char character);
    ~TrieNode();
};

#endif //VERSION_3_TRIENODE_H
