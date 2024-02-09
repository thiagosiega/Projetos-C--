#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>

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

class Button {
public:
    Button(float x, float y, float width, float height, sf::Color color, sf::Font& font, string text) {
        button.setSize(sf::Vector2f(width, height));
        button.setPosition(x, y);
        button.setFillColor(color);

        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(24);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setPosition(x + 10, y + 10);
    }

    bool isMouseOver(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f buttonPos = button.getPosition();
        sf::Vector2f buttonSize = button.getSize();

        return mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSize.x &&
               mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSize.y;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(buttonText);
    }

private:
    sf::RectangleShape button;
    sf::Text buttonText;
};

class Label{
public:
    Label(float x, float y, const string& text, sf::Font& font, sf::Color color) {
        labelText.setFont(font);
        labelText.setString(text);
        labelText.setCharacterSize(24);
        labelText.setFillColor(color);
        labelText.setPosition(x,y);
    }
    void setText(const string& text){
        labelText.setString(text);
    }
    void draw (sf::RenderWindow& window){
        window.draw(labelText);
    }
private:
    sf::Text labelText; // Declare the labelText variable
};


int main() {
    cout << "Central de projetos!" << endl;

    if (!fs::exists("./Dependencias")) {
        Instalador instalador;
    } else {
        cout << "As dependências já estão instaladas." << endl;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Central de projetos");
    sf::Font font;
    if (!font.loadFromFile("Elementos/advera/Advera.ttf")){
        cerr << "Erro ao carregar a fonte" << endl;
        return 1;
    }
    sf:: Font font2;
    if (!font2.loadFromFile("Elementos/dissfunction/Dissfunction.ttf")){
        cerr << "Erro ao carregar a fonte 2"<<endl;
        return 1;
    }

    Button button(300, 200, 200, 50, sf::Color::Blue, font, "Click Me");
    Button button2 (500, 400, 400, 50, sf::Color::White, font, "Teste 1");
    Label label(300, 300, "texte de fonte/labelç", font2, sf::Color::Green);
    Label label2(100, 200, "", font2, sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (button.isMouseOver(window)) {
                    //modifica o label
                    label.setText("Botao 1 clicado");
                }
                if (button2.isMouseOver(window)){
                    label2.setText("Botao 2 clicado");
                }
            }
        }

        window.clear();
        button.draw(window);
        button2.draw(window);
        label.draw(window);
        label2.draw(window);
        window.display();
    }

    return 0;
}
