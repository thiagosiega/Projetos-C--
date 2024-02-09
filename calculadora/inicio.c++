#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    double numero_1 = 0, numero_2 = 0, resultado = 0;
    string operador;
    int continuar = 1; // Variável para controlar se o usuário quer continuar

    while (continuar == 1) {
        cout << "==========================\n";
        cout << "  Calculadora - em C++    \n";
        cout << "==========================\n\n";
        cout << "Digite o primeiro número: ";
        cin >> numero_1;
        cout << "Digite o segundo número: ";
        cin >> numero_2;
        cout << "Qual será o operador: \n\nSoma => +\n\nDivisão => /\n\nMultiplicação => *\n\nSubtração => -\n\nPorcentagem => %\n\n\n";
        cin >> operador;

        bool operacaoValida = true; // Assume que a operação será válida

        if (operador == "+") {
            resultado = numero_1 + numero_2;
        } else if (operador == "/") {
            if (numero_2 == 0) {
                cout << "Erro: Divisão por zero não é permitida.\n";
                operacaoValida = false;
            } else {
                resultado = numero_1 / numero_2;
            }
        } else if (operador == "*") {
            resultado = numero_1 * numero_2;
        } else if (operador == "-") {
            resultado = numero_1 - numero_2;
        } else if (operador == "%") {
            if (numero_1 == static_cast<int>(numero_1) && numero_2 == static_cast<int>(numero_2)) {
                resultado = static_cast<int>(numero_1) % static_cast<int>(numero_2);
            } else {
                cout << "Erro: A operação de módulo só é válida com números inteiros.\n";
                operacaoValida = false;
            }
        } else {
            cout << "Erro: Operador inválido.\n";
            operacaoValida = false;
        }

        if (operacaoValida) {
            cout << "A resposta é: " << resultado << endl;
        }

        cout << "Deseja fazer outra operação?\n1 => Sim\n2 => Não\n";
        cin >> continuar;
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    cout << "Obrigado por me testar :3\nAte mais" << endl;
    return 0;
}
