#pragma once
#include "../Stalingrad.hpp"
#include <ostream>

namespace Entidades{
class Entidade : public Stalingrado::Ente{
protected:
    int x;
    int y;
    //std::ostream buffer; Ainda não entendi para que serve
    virtual void salvarDataBuffer();

public:
    Entidade();
    ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;
};


}
