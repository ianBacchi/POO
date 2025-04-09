#include <iostream>
#include <string>
#include <ctime> // para srand(time(0))

using namespace std;

class Lutador {
private:
    string nome;
    string nacionalidade;
    int idade;
    float altura;
    float peso;
    string categoria;
    int vitorias;
    int derrotas;
    int empates;

    void setCategoria() {
        if (peso < 52.2) categoria = "Inválido";
        else if (peso <= 70.3) categoria = "Leve";
        else if (peso <= 83.9) categoria = "Médio";
        else if (peso <= 120.2) categoria = "Pesado";
        else categoria = "Inválido";
    }

public:
    Lutador(string no, string nac, int id, float alt, float pes, int vit, int der, int emp)
        : nome(no), nacionalidade(nac), idade(id), altura(alt), peso(pes),
          vitorias(vit), derrotas(der), empates(emp) {
        setCategoria();
    }

    void apresentar() {
        cout << "Lutador: " << nome << ", de " << nacionalidade << endl;
        cout << "Idade: " << idade << ", Altura: " << altura << ", Peso: " << peso << endl;
        cout << "Vitórias: " << vitorias << ", Derrotas: " << derrotas << ", Empates: " << empates << endl;
    }

    void status() {
        cout << nome << " é um peso " << categoria << " com " << vitorias << " vitórias." << endl;
    }

    void ganharLuta() {
        vitorias++;
    }

    void perderLuta() {
        derrotas++;
    }

    void empatarLuta() {
        empates++;
    }

    string getNome() { return nome; }
};

class Luta {
private:
    Lutador* desafiado;
    Lutador* desafiante;
    int rounds;
    bool aprovada;

public:
    void marcarLuta(Lutador* l1, Lutador* l2) {
        if (l1 != l2) {
            desafiado = l1;
            desafiante = l2;
            aprovada = true;
        } else {
            aprovada = false;
            desafiado = desafiante = nullptr;
        }
    }

    void lutar() {
        if (aprovada) {
            desafiado->apresentar();
            desafiante->apresentar();

            int resultado = rand() % 3;
            cout << "Resultado da luta: ";
            switch (resultado) {
                case 0:
                    cout << "Empate!" << endl;
                    desafiado->empatarLuta();
                    desafiante->empatarLuta();
                    break;
                case 1:
                    cout << desafiado->getNome() << " venceu!" << endl;
                    desafiado->ganharLuta();
                    desafiante->perderLuta();
                    break;
                case 2:
                    cout << desafiante->getNome() << " venceu!" << endl;
                    desafiante->ganharLuta();
                    desafiado->perderLuta();
                    break;
            }
        } else {
            cout << "Luta não pode acontecer!" << endl;
        }
    }
};

int main() {
    rand(time(0)); // para aleatoriedade nas lutas
    
    
    
    // Criando os lutadores com dados da imagem
    Lutador l1("Danny Abbadi", "EUA", 30, 1.75, 70.0, 2, 2, 0);          // Lightweight
    Lutador l2("Nariman Abbasov", "Azerbaijão", 29, 1.78, 70.0, 28, 4, 0); // Lightweight
    Lutador l3("Tank Abbott", "EUA", 58, 1.83, 120.0, 10, 15, 0);        // Heavyweight
    Lutador l4("Hamdy Abdelwahab", "Egito", 31, 1.85, 115.0, 5, 0, 0);   // Heavyweight
    Lutador l5("Shamil Abdurakhimov", "Rússia", 37, 1.91, 115.0, 20, 8, 0); // Peso Pesado
    Lutador l6("Daichi Abe", "Japão", 30, 1.77, 77.0, 6, 4, 0);          // Welterweight
    Lutador l7("Papy Abedi", "Suécia", 34, 1.80, 84.0, 10, 4, 0);        // Middleweight
    Lutador l8("Klidson Abreu", "Brasil", 31, 1.88, 93.0, 16, 6, 0);     // Light Heavyweight
    Lutador l9("Juan Adams", "EUA", 29, 1.96, 120.0, 9, 5, 0);           // Heavyweight
    Lutador l10("Scott Adams", "EUA", 40, 1.83, 120.0, 6, 2, 0);         // Heavyweight
    Lutador l11("Anthony Adams", "EUA", 32, 1.85, 84.0, 9, 3, 0);        // Middleweight
    Lutador l12("Zarrukh Adashev", "Uzbequistão", 30, 1.70, 61.0, 4, 4, 0); // Peso Mosca

    // Simulando algumas lutas
    Luta luta1;
    luta1.marcarLuta(&l2, &l1); // Abbasov vs Abbadi
    luta1.lutar();

    Luta luta2;
    luta2.marcarLuta(&l4, &l3); // Hamdy vs Tank
    luta2.lutar();

    Luta luta3;
    luta3.marcarLuta(&l11, &l7); // Anthony vs Papy
    luta3.lutar();

    Luta luta4;
    luta4.marcarLuta(&l9, &l10); // Juan vs Scott
    luta4.lutar();

    cout << "\nStatus dos lutadores após as lutas:\n";
    l1.status();
    l2.status();
    l3.status();
    l4.status();
    l7.status();
    l11.status();
    l9.status();
    l10.status();

    return 0;
}
