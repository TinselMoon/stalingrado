#include "Ente.hpp"
#include <cstdlib>

namespace Stalingrado {
using namespace Gerenciadores;

int Ente::contId(0);
Gerenciador_Grafico* Ente::pGG(NULL);
//INICIO ENTE 
Ente::Ente(const std::string& nomeTextura) : id(contId++), pFig(NULL), personagem(pGG->getTextura(nomeTextura)), actual_shape()
{
    sf::Vector2f size = pGG->getTamanhoTextura(nomeTextura);
    personagem.setScale(size.x, size.y);

}

Ente::Ente() : id(contId++), pFig(NULL), personagem()
{

}

sf::FloatRect Ente::getRectangle(){
    return personagem.getGlobalBounds();
}

Ente::~Ente() {


}

void Ente::desenhar(){

    pGG->desenharEnte(static_cast<Ente*>(this));

}
void Ente::setGG (Gerenciador_Grafico* pG) {
    pGG = pG;
}

const sf::Sprite Ente::getSprite(){
    return personagem;
}


}
