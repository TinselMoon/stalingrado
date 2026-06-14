#include "Inimigo.hpp"

#include "Personagem.hpp"
#include "Jogador.hpp"
#include "../../Jogo.hpp"
#include <cstdlib>
#include <ctime>

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            Inimigo::Inimigo(int vida, int maldade, const std::string& nomeTextura) : Personagens::Personagem(vida, nomeTextura), dt_dano(0), dt_movimento(0), max_speed(0){
                nivel_maldade = maldade;
            }

            Inimigo::~Inimigo(){
                nivel_maldade = -1;
            }
            
            const bool Inimigo::getChefao() const{
                return isChefao;
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
