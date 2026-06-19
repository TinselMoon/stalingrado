#include "Inimigo.hpp"

#include "Personagem.hpp"
#include "Jogador.hpp"
#include "../../States/Jogo.hpp"
#include <cstdlib>
#include <ctime>

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            Inimigo::Inimigo(int vida, int maldade, const std::string& nomeTextura) : Personagens::Personagem(vida, maldade, 0, 0, 0, nomeTextura){
                nivel_maldade = maldade;
            }

            Inimigo::~Inimigo(){
                nivel_maldade = -1;
            }

            void Inimigo::salvarDataBuffer(){

            }

            void Inimigo::salvar(){

            }

            void Inimigo::mover(){

            }

        } // Fim dos namespaces

    } // Fim do namespace Stalingrado
}