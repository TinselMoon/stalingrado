#pragma once
#include "Gerenciadores/Gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Stalingrado{

class Ente {
protected:
    int id;
    static int contId; //adicao do Gustavo, interpretacao
    static Gerenciadores::Gerenciador_Grafico* pGG;
    //A classe Sprite possui a posição do sprite também
    //sf::Sprite personagem; //Melhorar o nome para englobar
    //sf::RectangleShape actual_shape;
    sf::Texture* pFig; //ponteiro para a classe com o sprite

public:
    Ente(const sf::Texture &texture);
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void desenhar();
    static void setGG(Gerenciadores::Gerenciador_Grafico* pG);
};


class Jogo;
//IMPLEMENTAR CLASSE MENU
class Menu : public Ente{
private:
    const Jogo* pJog;
public:
    Menu(const Jogo *pJ = NULL);
    ~Menu();
    void executar();
};


//IMPLEMENTAR CLASSE JOGO
class Jogo{
private:
    Gerenciadores::Gerenciador_Grafico GG;
    Menu mJogo;
public:
    Jogo();
    ~Jogo();
    void executar();
};

// linha 18-19
Gerenciadores::Gerenciador_Grafico* Ente::pGG(NULL);
int Ente::contId(0);

}
