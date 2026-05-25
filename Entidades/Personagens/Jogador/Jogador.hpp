#include "../Personagem.hpp"

class Inimigo;

namespace Personagens{
class Jogador : public Personagens::Personagem{
protected:
    int pontos;
public:
    Jogador(int vida);
    ~Jogador();
    void colidir(Inimigo* pIn);
    void executar();
    void salvar();
    void mover();
};
}
