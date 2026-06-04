#include "Chao.hpp"

namespace Stalingrado{
namespace Entidades{

Chao::Chao() : Entidade("Chao_fase_um"), comprimento(10000), altura(900){
    personagem.setTextureRect(sf::IntRect(0, 0, comprimento, altura));
}

Chao::~Chao(){

}

void Chao::setPosicao(float x, float y){
    personagem.setPosition(x, y);
}

void Chao::executar(){

}

void Chao::salvar(){

}

}
}
