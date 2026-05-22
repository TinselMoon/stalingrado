#pragma once

#include <SFML/Graphics.hpp>

class Ente;
namespace Gerenciadores {
class Gerenciador_Grafico {
private:
    sf::RenderWindow Obj; //interpretacao do Gustavo sobre o atributo da classe no UML

public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();
    void desenharEnte (Ente *pE);
    void executar(); //interpretacao Gustavo
};


//CLASSE GERENCIADOR DE COLISOES, IMPLEMENTAR
class Gerenciador_Colisoes{
private:

public:

};

}
