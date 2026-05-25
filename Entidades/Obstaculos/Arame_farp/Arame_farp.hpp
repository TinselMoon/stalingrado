#include "../Obstaculo.hpp"

namespace Obstaculos{
class Arame_farp : public Obstaculos::Obstaculo{
private:
    //COLOCAR ALGO AQUI SLA
public:
    Arame_farp();
    ~Arame_farp();
    void executar();
    void salvar();
    void obstaculizar(Jogador* pJ);
};
}
