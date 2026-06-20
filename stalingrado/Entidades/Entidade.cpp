#include "Entidade.hpp"

namespace Stalingrado {

namespace Entidades{

Entidade::Entidade(const std::string& nomeTextura) : Ente(nomeTextura){
}

Entidade::~Entidade(){

}
const bool Entidade::isAtivo() const {
    return ativo;
}

void Entidade::salvarDataBuffer(){

}
}
} // Fim do namespace Stalingrado
