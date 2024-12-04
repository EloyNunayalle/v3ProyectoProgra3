//
// Created by Usuario on 3/12/2024.
//

#include "TrieNode.h"

TrieNode::TrieNode(char character) : character(character), isEndOfWord(false) {}

TrieNode::~TrieNode() {
    for (auto& child : children) {
        delete child.second;
    }
}