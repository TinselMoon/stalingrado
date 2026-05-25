#pragma once
#include "../Inimigo.hpp"

namespace Entidades {
namespace Personagens {
class Inim_facil : public Personagens::Inimigo{
private:
    float raio;
    sf::RectangleShape corpo;
    sf::Texture textura;
public:
    Inim_facil(int vida, int maldade);
    Inim_facil();
    ~Inim_facil();
    void danificar(Jogador *pJ);
    void executar();
    void salvar();
    void mover();
    void desenhar();
};

}

} // Fim do namespace Entidades
