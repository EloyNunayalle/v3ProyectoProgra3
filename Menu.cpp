//
// Created by Usuario on 3/12/2024.
//

#include "Menu.h"
#include "DataLoader.h"
#include "Utils.h"
#include "VerMasTarde.h"
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <fstream>
using namespace std;



void Menu::iniciarMenu(vector<Pelicula*>& peliculas, Trie& trie, unordered_map<string, vector<Pelicula*>>& tagIndex,VerMasTarde& vmt) {
    cout << "Cargando datos, por favor espere..." << endl;
    try {
        cargarDatos("data_corregida1.csv", peliculas, trie, tagIndex);
        cout << "Datos cargados exitosamente." << endl;
    } catch (const exception& e) {
        cerr << "Error al cargar datos: " << e.what() << endl;
        return;
    }

    int opcion;
    do {
        cout << "\n--- Menu Principal ---" << endl;
        cout << "1. Buscar pelicula por palabra o frase clave" << endl;
        cout << "2. Buscar pelicula por tag" << endl;
        cout << "3. Salir" << endl;
        vmt.mostrar_vermastarde();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                buscarPorPalabraClave(trie,vmt);
                break;
            case 2:
                buscarPorTag(tagIndex,vmt);
                break;
            case 3:
                cout << "Saliendo del programa. Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor intente nuevamente." << endl;
        }
    } while (opcion != 3);
}

void Menu::cargarDatos(const string& filename,
                       vector<Pelicula*>& peliculas,
                       Trie& trie,
                       unordered_map<string, vector<Pelicula*>>& tagIndex) {
    Utils::loadStopWords("stop_word.txt");
    DataLoader::loadMovies(filename, peliculas, trie, tagIndex);
}

void Menu::buscarPorPalabraClave(Trie& trie, VerMasTarde& vmt) {
    cin.ignore(); // Limpiar buffer
    string query;
    cout << "Ingrese la palabra o frase clave: ";
    getline(cin, query);

    vector<string> palabras = Utils::splitString(query, ' ');
    unordered_map<Pelicula*, int> resultadosUnificados;

    for (const auto& palabra : palabras) {
        auto resultados = trie.search(palabra);
        for (const auto& [pelicula, relevancia] : resultados) {
            resultadosUnificados[pelicula] += relevancia;
        }
    }

    vector<pair<Pelicula*, int>> resultadosOrdenados(resultadosUnificados.begin(), resultadosUnificados.end());
    sort(resultadosOrdenados.begin(), resultadosOrdenados.end(),
         [](const auto& a, const auto& b) {
             return a.second > b.second; // Descendente por relevancia
         });

    size_t totalResultados = resultadosOrdenados.size();
    size_t pagina = 0;
    const size_t resultadosPorPagina = 5;

    while (pagina * resultadosPorPagina < totalResultados) {
        cout << "\nResultados pagina " << (pagina + 1) << ":" << endl;

        for (size_t i = pagina * resultadosPorPagina;
             i < min((pagina + 1) * resultadosPorPagina, totalResultados); ++i) {
            cout << (i + 1) << ". " << resultadosOrdenados[i].first->title
                 << " (Relevancia: " << resultadosOrdenados[i].second << ")" << endl;
        }
        cout <<endl;
        cout << "1. Ver los siguientes cinco resultados" << endl;
        cout << "2. Elegir una pelicula" << endl;
        cout << "3. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            pagina++;
        } else if (opcion == 2) {
            cout << "Ingrese el numero de la pelicula: ";
            int eleccion;
            cin >> eleccion;
            if (eleccion > 0 && eleccion <= totalResultados) {
                mostrarPelicula(resultadosOrdenados[eleccion - 1].first,vmt);
            } else {
                cout << "Eleccion invalida." << endl;
            }
        } else if (opcion == 3) {
            break;
        } else {
            cout << "Opcion invalida." << endl;
        }
    }
}

void Menu::buscarPorTag(const unordered_map<string, vector<Pelicula*>>& tagIndex, VerMasTarde& vmt) {
    cout << "Tags disponibles:" << endl;
    vector<string> tags;

    for (const auto& [tag, _] : tagIndex) {
        tags.push_back(tag);
    }
    for (size_t i = 0; i < tags.size(); ++i) {
        if(i == tags.size()-1){
            cout << tags[i] <<"."<< endl;
        }
        cout << tags[i] << ", ";
    }
    cout << endl;
    cout << "Escriba un tag de la lista: ";

    string eleccion;
    cin >> eleccion;

    if (eleccion != "") {

        string tagElegido = eleccion;
        vector<Pelicula*> peliculas = tagIndex.at(tagElegido);
        size_t pagina = 0;
        const size_t resultadosPorPagina = 5;

        while (pagina * resultadosPorPagina < peliculas.size()) {
            cout << "\nPeliculas con el tag '" << tagElegido << "', pagina " << (pagina + 1) << ":" << endl;

            for (size_t i = pagina * resultadosPorPagina;
                 i < min((pagina + 1) * resultadosPorPagina, peliculas.size()); ++i) {
                cout << (i + 1) << ". " << peliculas[i]->title << endl;
            }

            cout << "1. Ver los siguientes cinco resultados" << endl;
            cout << "2. Elegir una pelicula" << endl;
            cout << "3. Volver al menu principal" << endl;
            cout << "Seleccione una opcion: ";

            int opcion;
            cin >> opcion;

            if (opcion == 1) {
                pagina++;
            } else if (opcion == 2) {
                cout << "Ingrese el numero de la pelicula: ";
                int eleccion;
                cin >> eleccion;
                if (eleccion > 0 && eleccion <= peliculas.size()) {
                    mostrarPelicula(peliculas[eleccion - 1],vmt);
                } else {
                    cout << "Eleccion invalida." << endl;
                }
            } else if (opcion == 3) {
                break;
            } else {
                cout << "Opcion invalida." << endl;
            }
        }
    } else {
        cout << "Eleccion invalida." << endl;
    }
}

void Menu::mostrarPelicula(Pelicula* pelicula, VerMasTarde& vmt) {
    cout << "\n--- Informacion de la pelicula ---" << endl;
    cout << "ID: " << pelicula->imdb_id << endl;
    cout << "Titulo: " << pelicula->title << endl;
    cout << "Sinopsis: " << pelicula->plot_synopsis << endl;
    cout << "Tags: ";
    for (const auto& tag : pelicula->tags) {
        cout << tag << " ";
    }
    cout << endl;
    cout << "Split: " << pelicula->split << endl;
    cout << "Fuente de la sinopsis: " << pelicula->synopsis_source << endl;
    bool flag = false;
    while(!flag ){
        auto vmt_peliculas = vmt.obtenerpeliculasenvermastarde();
        if(find(vmt_peliculas.begin(),vmt_peliculas.end(),pelicula->title) == vmt_peliculas.end()){
            cout << "Seleccione una de las siguientes opciones"<< endl ;
            cout << "1. Guardar en Ver mas tarde" << endl;
            cout << "2. Volver a la seleccion anterior" << endl;
            cout << "Seleccione una opcion: ";
            int opcion;
            cin >> opcion;
            if(opcion == 1){
                cout << "Guardado en Ver mas tarde"<< endl;
                vmt.insertarpelicula(pelicula->title);
            }else if(opcion == 2){
                break;
            }else{
                cout << "Opcion no valida";
            }
        }else{
            cout << "Seleccione una de las siguientes opciones"<< endl ;
            cout << "1. Volver a la seleccion anterior" << endl;
            cout << "Seleccione una opcion: ";
            int opcion;
            cin >> opcion;
            if(opcion == 1){
                break;
            }else{
                cout<< "Opcion no valida" << endl;
            }
        }
    }
}
