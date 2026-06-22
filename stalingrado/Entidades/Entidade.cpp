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
}
} // Fim do namespace Stalingrado
