//
#include "VerMasTarde.h"
#include <vector>
#include <fstream>
void VerMasTarde::insertarpelicula(string pelicula) {
    std::ofstream file("vermastarde.txt", std::ios::app);
    file << pelicula<< endl;
    file.close();
}

vector<string> VerMasTarde::obtenerpeliculasenvermastarde() {
    vector<string> v_vmt;
    ifstream file("vermastarde.txt");
    string line;
    while (getline(file, line)) {
        v_vmt.push_back(line);
    }
    file.close();
    return v_vmt;
}

void VerMasTarde::mostrar_vermastarde(){
    if(obtenerpeliculasenvermastarde().size() != 0){
        ifstream file("vermastarde.txt");
        string line;
        cout << "VER MAS TARDE" <<endl;
        while (getline(file, line)) {
            cout <<"| "<< line << " |"<< endl;
        }
        file.close();
    }


}


//
