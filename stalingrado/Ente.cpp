#include "Ente.hpp"
#include <cstdlib>
using namespace Stalingrado::Gerenciadores;

namespace Stalingrado {


Gerenciador_Grafico* Ente::pGG(nullptr);
//INICIO ENTE 
Ente::Ente(const std::string& nomeTextura) : id(contId++), corpo(pGG->getTextura(nomeTextura))
{
    sf::Vector2f size = pGG->getTamanhoTextura(nomeTextura);

    sf::Vector2u tamanhoOriginal = corpo.getTexture()->getSize();

    if (tamanhoOriginal.x != 0 && tamanhoOriginal.y != 0) {

        // 4. Calcula a escala necessária para o eixo X e Y
        float escalaX = size.x / tamanhoOriginal.x;
        float escalaY = size.y / tamanhoOriginal.y;

        // 5. Aplica a escala no Sprite
        corpo.setScale(escalaX, escalaY);
    }

}

Ente::Ente() : id(contId++), corpo()
{

}

sf::FloatRect Ente::getRectangle(){
    return corpo.getGlobalBounds();
}

Ente::~Ente() {


}

void Ente::desenhar() {

    pGG->desenharEnte(this);
}

void Ente::setGG (Gerenciador_Grafico* pG) {
    pGG = pG;
}

const sf::Sprite* Ente::getSprite(){
    return &corpo;
}

Gerenciador_Grafico *Ente::getGG() const {
    return pGG;
}


int Ente::contId(0);

}
