//
// Created by Usuario on 3/12/2024.
//

#ifndef VERSION_3_TRIE_H
#define VERSION_3_TRIE_H

#include "TrieNode.h"
#include <string>
#include <unordered_map>

using namespace std;

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    ~Trie();

    void insert(const string& word, Pelicula* pelicula);
    unordered_map<Pelicula*, int> search(const string& word);
};


#endif //VERSION_3_TRIE_H
