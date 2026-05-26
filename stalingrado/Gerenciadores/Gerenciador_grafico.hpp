#pragma once

#include <SFML/Graphics.hpp>

//Pré declaração do namespace aqui para usar os ponteiros e etc
namespace Stalingrado {
    class Ente;
}

namespace Gerenciadores {
class Gerenciador_Grafico {
private:
    sf::RenderWindow janela;

public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();
    void desenharEnte (Stalingrado::Ente *pE);
    void desenhar(sf::RectangleShape* forma);
    sf::RenderWindow* getJanela();   
    void executar(); //interpretacao Gustavo
};

}
