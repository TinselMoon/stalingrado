#include "Jogo.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Personagens/Inim_facil/Inim_facil.hpp"

namespace Stalingrado{
    Jogo::Jogo() : GG(), mJogo(this), pJog1(NULL), pInim1(NULL){
        //AQUI NA CONSTRUTORA EU FAÇO O SET DA INSTANCIA DO GERENCIADOR GRAFICO PARA TODOS OS ENTES
        Ente::setGG(&GG);
        pJog1 = new Entidades::Personagens::Jogador(5);
        pInim1 = new Entidades::Personagens::Inim_facil(5, 1);
    }

    Jogo::~Jogo(){
        if (pInim1 != NULL) delete pInim1;
        if (pJog1 != NULL) delete pJog1;
    }

    void Jogo::executar(){
        while (GG.getJanela()->isOpen()) { //loop 'infinito' para so fechar janela qnd apertar esc ou clicar no x
            sf::Event evento;
            while (GG.getJanela()->pollEvent(evento)) {
                if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                    GG.getJanela()->close();
                }
            }
            pJog1->executar();
            pInim1->executar();

            GG.getJanela()->clear();

            pJog1->desenhar();
            pInim1->desenhar();

            GG.getJanela()->display();
        }   //IMPLEMENTAR
    }
}
