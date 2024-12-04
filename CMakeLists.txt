cmake_minimum_required(VERSION 3.25.2)
project(version_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(version_3
        main.cpp
        Pelicula.cpp
        Pelicula.h
        Utils.cpp
        Utils.h
        TrieNode.cpp
        TrieNode.h
        Trie.cpp
        Trie.h
        DataLoader.cpp
        DataLoader.h
        Menu.cpp
        Menu.h
)
