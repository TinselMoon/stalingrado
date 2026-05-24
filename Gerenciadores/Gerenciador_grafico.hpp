#pragma once

#include <SFML/Graphics.hpp>

//Pré declaração do namespace aqui para usar os ponteiros e etc
namespace Stalingrado {
    class Ente;
}

namespace Gerenciadores {
class Gerenciador_Grafico {
private:
    sf::RenderWindow Obj; //interpretacao do Gustavo sobre o atributo da classe no UML

public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();
    void desenharEnte (Stalingrado::Ente *pE);
    void executar(); //interpretacao Gustavo
};

}
