#include "Parede.hpp"

namespace Stalingrado{
namespace Entidades{

Parede::Parede() : Entidade("Inimigo_facil"), largura(10), altura(1080){
    personagem.setTextureRect(sf::IntRect(0, 0, largura, altura));
    personagem.setColor(sf::Color::Transparent);
}

Parede::~Parede(){

}

void Parede::setPosicao(float x, float y){
    personagem.setPosition(x, y);
}

void Parede::executar(){

}

void Parede::salvar(){

}

}
}
