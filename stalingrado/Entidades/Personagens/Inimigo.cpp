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
            pontos_por_kill(10*maldade), nivel_maldade(maldade), max_speed(250.f), dt_movimento(0), dt_mudar_direcao(0),
            dt_dano(1.f) // dano já vem engatilhado
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
                float velAntiga = getVelX();
                float velAtual = 0;
                dt_movimento += Jogo::getDt();
                if(dt_movimento > dt_mudar_direcao){
                    int new_direction = (rand() % 3) - 1;
                    velAtual = max_speed*new_direction;
                    setVelocidadeX(velAtual);
                    if(rand() % 100 < 10 && getVelY() == 0)
                        setVelocidadeY(-400.f);
                    dt_movimento = 0;
                    if(velAtual != 0 && velAntiga != velAtual){
                        //Atualizar lado que o personagem esta olhando
                        int larguraTextura = personagem.getTexture()->getSize().x;
                        int alturaTextura = personagem.getTexture()->getSize().y;
                        if(velAtual > 0){
                            personagem.setTextureRect(sf::IntRect(0, 0, larguraTextura, alturaTextura));
                        }
                        if(velAtual < 0){
                            personagem.setTextureRect(sf::IntRect(larguraTextura, 0,-larguraTextura, alturaTextura));
                        }
                    }
                }
                Personagem::mover();
            }

        } // Fim dos namespaces

    } // Fim do namespace Stalingrado
}
