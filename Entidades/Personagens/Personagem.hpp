#include "../Entidade.hpp"

namespace Personagens{
class Personagem : public Entidades::Entidade {
protected:
    int num_vidas;
public:
    Personagem();
    Personagem(int vida);
    ~Personagem();
    void salvarDataBuffer();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
};
}
