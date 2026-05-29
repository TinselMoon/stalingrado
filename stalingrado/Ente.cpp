#include "Ente.hpp"
#include <cstdlib>

namespace Stalingrado {
using namespace Gerenciadores;

int Ente::contId(0);
Gerenciador_Grafico* Ente::pGG(NULL);
//INICIO ENTE 
Ente::Ente(const sf::Texture &texture) : id(contId++), pFig(NULL), personagem(texture),
    actual_shape()
{


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

}
void Ente::setGG (Gerenciador_Grafico* pG) {
    pGG = pG;
}
}
