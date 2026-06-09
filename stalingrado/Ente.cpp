#include "Ente.hpp"
#include <cstdlib>

namespace Stalingrado {
using namespace Gerenciadores;

Gerenciador_Grafico* Ente::pGG(NULL);
//INICIO ENTE 
Ente::Ente(const std::string& nomeTextura) : id(contId++), personagem(pGG->getTextura(nomeTextura))
{
    sf::Vector2f size = pGG->getTamanhoTextura(nomeTextura);

    sf::Vector2u tamanhoOriginal = personagem.getTexture()->getSize();

    if (tamanhoOriginal.x != 0 && tamanhoOriginal.y != 0) {

        // 4. Calcula a escala necessária para o eixo X e Y
        float escalaX = size.x / tamanhoOriginal.x;
        float escalaY = size.y / tamanhoOriginal.y;

        // 5. Aplica a escala no Sprite
        personagem.setScale(escalaX, escalaY);
    }

}

Ente::Ente() : id(contId++), personagem()
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

const sf::Sprite* Ente::getSprite(){
    return &personagem;
}

int Ente::contId(0);

}
