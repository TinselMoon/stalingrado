#include "Inimigo.hpp"

#include "Personagem.hpp"
#include "Jogador.hpp"
#include "../../Jogo.hpp"
#include <cstdlib>
#include <ctime>

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            Inimigo::Inimigo(int vida, int maldade, const std::string& nomeTextura) : Personagem(vida, nomeTextura),
            pontos_por_kill(10*maldade), nivel_maldade(maldade), max_speed(250.f), dt_movimento(0), dt_dano(0)
            {
            }

            Inimigo::~Inimigo(){
                nivel_maldade = -1;
            }
            
            void Inimigo::executar(){
            }
            const bool Inimigo::getChefao() const{
                return isChefao;
            }
            void Inimigo::salvarDataBuffer(){

            }

            const int Inimigo::getPontos() const{
                return pontos_por_kill;
            }
            void Inimigo::salvar(){

            }

            void Inimigo::mover(){

            }

        } // Fim dos namespaces

    } // Fim do namespace Stalingrado
}
