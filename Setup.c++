#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;
namespace fs = std::filesystem;

class Instalador {
public:
    Instalador() {
        if (!fs::exists("./Dependencias")) {
            cout << "Pasta 'Dependencias' não encontrada, criando e instalando dependências...\n";
            fs::create_directory("./Dependencias");

            ofstream file("./Dependencias/dependencias.txt");
            file << "Qt5-default, QtCreator e SFML instalados.\n";
            file.close();

            cout << "Atualizando pacotes e instalando dependências...\n";
            system("sudo apt-get update");
            system("sudo apt-get install qt5-default qtcreator -y");
            system("sudo apt-get install libsfml-dev -y");
        } else {
            cout << "Dependências já instaladas.\n";
        }
    }
};

int main() {
    cout << "Central de projetos!" << endl;

    if (!fs::exists("./Dependencias")) {
        Instalador instalador;
    } else {
        cout << "As dependências já estão instaladas." << endl;
    }

    // Inicializa uma janela usando a biblioteca SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Central de projetos");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
