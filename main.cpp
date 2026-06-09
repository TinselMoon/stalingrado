#include "stalingrado/Jogo.hpp"
#include <cstdlib>
#include <ctime>
using namespace Stalingrado;

int main(void){

    std::srand(static_cast<unsigned int>(std::time(0)));
    Jogo jogo;
    jogo.executar();
    return 0;
}
