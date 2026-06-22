#include "Obstaculo.hpp"

namespace Stalingrado {
    namespace Entidades {
        namespace Obstaculos {

            Obstaculo::Obstaculo(bool dano, bool lento, const std::string& nomeTextura) : Entidade(nomeTextura){
                danoso = dano;
                lentidao = lento;
            }

            Obstaculo::~Obstaculo(){
                danoso = false;
                lentidao = false;
            }


            bool Obstaculo::getLentidao(){
                return lentidao;
            }

            bool Obstaculo::getDanoso(){
                return danoso;
            }

            void Obstaculo::movePos(float x, float y){
                corpo.move(x, y);
            }

            void Obstaculo::setVelocidadeY(float vy){
                //não faz nada pq obstaculos nao sofrem aceleração gravitacional, pois estao estáticos no chao
            }
        }
    }
}
