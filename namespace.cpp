#include <iostream>

/*Boas praticas no POO
nomear classe 1 letra maiuscula
camelcase ou _ se precisar mais de uma palavra
metodos=verbos 1 letra maiuscula tbm*/
using namespace std;

class Carro{

    private: //atributos, n consigo acessar externamente
        float valor;
        int ano;
        float km;

    public: //metodos

        int getAno(){
            return this->ano;
        }

        float getValor(){

            return this->valor;
        }

        void atualizarkm(float km);

        Carro(float v, int a, float k){

            ano = a;
            valor = v;
            km = k;
        }

};

int main(){

    Carro opala(55000, 1988, 101100); //instanciando objeto da classe 
    cout<<"Opala ano ="<<opala;
    return 0;
}
