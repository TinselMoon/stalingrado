#include "Chao.hpp"

namespace Stalingrado{
namespace Entidades{

Chao::Chao(const int comp, const std::string& textura) : Entidade(textura), comprimento(comp), altura(900){
    const int largura = static_cast<int>(comprimento / corpo.getScale().x) + corpo.getTexture()->getSize().x;
    const int alturaPx = static_cast<int>(altura / corpo.getScale().y);
    corpo.setTextureRect(sf::IntRect(0, 0, largura, alturaPx));
}

Chao::~Chao(){

}

const int Chao::getComprimento() const{
    return comprimento;
}

void Chao::setPosicao(float x, float y){
    corpo.setPosition(x, y);
}

void Chao::executar(){

}

void Chao::salvar(std::ofstream& arquivo){

}

}
}
