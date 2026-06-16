#include "Jogo.hpp"
#include "Fases/Fase_prim.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include <cstdlib>
#include <ctime>

namespace Stalingrado {

    Jogo* Jogo::instanciaJogo = NULL;
    float Jogo::dt = 0.0f;

    Jogo::Jogo() : GG(), pMenu(NULL), pJog1(NULL), pJog2(NULL), fase_um(NULL), fase_seg(NULL),
    clock(), tempoDecorrido(), executando(true), faseAtual(0)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        Ente::setGG(&GG); //set do gerenciador grafico para entes
        pMenu = new Menu(this);
        pJog1 = new Entidades::Personagens::Jogador(10);
        pJog2 = new Entidades::Personagens::Jogador(5);
        fase_um = new Fases::Fase_prim(pJog1, pJog2);
        fase_seg = new Fases::Fase_seg(pJog1, pJog2);
    }

    Jogo::~Jogo() {
        if (fase_um)    delete fase_um;
        if (fase_seg)   delete fase_seg;
        if (pJog1)      delete pJog1;
        if (pJog2)      delete pJog2;
        if (pMenu)      delete pMenu;
    }

    Jogo* Jogo::getInstanciaJogo() {
        if (!instanciaJogo)
            instanciaJogo = new Jogo();
        return instanciaJogo;
    }

    float Jogo::getDt() {
        return dt;
    }

    void Jogo::executar() {
        clock.restart();

        while (GG.getJanela()->isOpen() && executando) {
            sf::Event evento;
            while (GG.getJanela()->pollEvent(evento)) {
                if (evento.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    executando = false;
            }

            tempoDecorrido = clock.restart();
            dt = tempoDecorrido.asSeconds();
            

            GG.getJanela()->clear();
            if(pJog1->isAtivo())
                GG.setAlvoCamera(static_cast<Ente*>(pJog1));
            else if(!(pJog1->isAtivo()) && pJog2->isAtivo())
                GG.setAlvoCamera(static_cast<Ente*>(pJog2));
            fase_um->executar();
            GG.atualizarCamera();
            GG.getJanela()->display();
        }
    }

    void Jogo::fecharJogo() {
        executando = false;
    }

}
