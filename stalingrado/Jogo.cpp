#include "Jogo.hpp"
#include "Fases/Fase_prim.hpp"

namespace Stalingrado{
    Jogo::Jogo() : GG(), mJogo(this), fase_um(){
        //AQUI NA CONSTRUTORA EU FAÇO O SET DA INSTANCIA DO GERENCIADOR GRAFICO PARA TODOS OS ENTES
        Ente::setGG(&GG);
    }

    Jogo::~Jogo(){
    }

    void Jogo::executar(){
        while (GG.getJanela()->isOpen()) { //loop 'infinito' para so fechar janela qnd apertar esc ou clicar no x
            sf::Event evento;
            while (GG.getJanela()->pollEvent(evento)) {
                if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                    GG.getJanela()->close();
                }
            }

            GG.getJanela()->clear();
            
            fase_um.executar();

            GG.getJanela()->display();
        }   //IMPLEMENTAR
    }
}
