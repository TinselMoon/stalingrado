#include "Chao.hpp"

namespace Stalingrado{
namespace Entidades{

Chao::Chao() : Entidade("Chao_fase_um"){
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
