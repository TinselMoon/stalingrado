#pragma once 
#include "Entidade.hpp"

namespace Stalingrado{
namespace Entidades{
class Chao : public Entidade{
public:
    Chao();
    ~Chao();
    void executar();
    void salvar();
};
}
}
