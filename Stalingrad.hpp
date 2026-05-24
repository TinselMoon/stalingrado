#pragma once
#include "Gerenciadores/Gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>

namespace Stalingrado{

class Ente {
protected:
    int id;
    static int contId; //adicao do Gustavo, interpretacao
    static Gerenciadores::Gerenciador_Grafico* pGG;
    sf::RectangleShape* pFig; //interpretacao do Gustavo sobre o UML

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void desenhar();
    static void setGG(Gerenciadores::Gerenciador_Grafico* pGG);
};

//IMPLEMENTAR CLASSE JOGO
class Jogo{
private:
    Gerenciadores::Gerenciador_Grafico GG;
public:
    Jogo();
    ~Jogo();
};

//IMPLEMENTAR CLASSE MENU
class Menu : public Ente{
private:
    Jogo* pJog;
public:
    Menu() : Ente() {}
    ~Menu();
};

}
