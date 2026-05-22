#pragma once
#include "Gerenciadores/Gerenciadores.hpp"
#include "SFML/Graphics.hpp"
#include "Fases/fase.hpp"
using namespace Gerenciadores;
using namespace Fases;

namespace Stalingrado {

class Ente {
protected:
    int id;
    static int contId; //adicao do Gustavo, interpretacao
    static Gerenciador_Grafico* pGG;
    sf::RectangleShape* pFig; //interpretacao do Gustavo sobre o UML

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void desenhar();
    static void setGG(Gerenciador_Grafico* pGG);
};

//IMPLEMENTAR CLASSE JOGO
class Jogo{
private:
    Gerenciador_Grafico GG;
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
