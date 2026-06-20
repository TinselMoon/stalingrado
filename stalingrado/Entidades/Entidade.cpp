#include "Entidade.hpp"

namespace Stalingrado {

namespace Entidades{

Entidade::Entidade(const std::string& nomeTextura) : Ente(nomeTextura), ativo(true){
}

Entidade::~Entidade(){

}
const bool Entidade::isAtivo() const {
    return ativo;
}

void Entidade::setAtivo(bool at) {
    ativo = at;
}

void Entidade::salvarDataBuffer(){

}
}
} // Fim do namespace Stalingrado
