#include "Inimigo.hpp"

#include "Personagem.hpp"
#include "Jogador.hpp"
#include "../../Jogo.hpp"
#include <cstdlib>
#include <ctime>

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            Inimigo::Inimigo(int vida, int maldade, const std::string& nomeTextura) : Personagem(vida, maldade, 250.f , nomeTextura),
            pontos_por_kill(10*maldade)
            {
                nivel_maldade = maldade;
            }

            Inimigo::~Inimigo(){
                nivel_maldade = -1;
            }
            
            void Inimigo::executar(){
                if(num_vidas == 0){
                    
                }
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
