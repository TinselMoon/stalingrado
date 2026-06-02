#pragma once
#include "../Ente.hpp"
#include <ostream>

namespace Stalingrado {

namespace Entidades{
class Entidade : public Ente{
protected:
    //std::ostream buffer;// Ainda não entendi para que serve
    virtual void salvarDataBuffer();

public:
    Entidade(const std::string& nomeTextura);
    virtual ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;
};


}

} // Fim do namespace Stalingrado
