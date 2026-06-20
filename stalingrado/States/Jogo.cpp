#include "Jogo.hpp"
#include "Fases/Fase_prim.hpp"
#include "../Ente.hpp"
#include "../Entidades/Personagens/Jogador.hpp"
#include "../Menus/MenuInicial.hpp"
#include <cstdlib>
#include <ctime>

#include "../Defines.txt"

namespace Stalingrado {
    namespace States {

        Jogo* Jogo::instanciaJogo = nullptr;
        float Jogo::dt = 0.0f;

        Jogo::Jogo() : GG(), pMenuI(nullptr), pJog1(nullptr), pJog2(nullptr), fase_um(nullptr), fase_seg(nullptr),
        clock(), tempoDecorrido(), executando(true), faseAtual(0)
        {
            std::srand(static_cast<unsigned int>(std::time(0)));
            Ente::setGG(&GG); //set do gerenciador grafico para entes
            pMenuI = new Menus::MenuInicial(this);
        }

        Jogo::~Jogo() {

            if (fase_um)    delete fase_um;
            if (fase_seg)   delete fase_seg;
            if (pJog1)      delete pJog1;
            if (pJog2)      delete pJog2;
            if (pMenuI)      delete pMenuI;
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

                    if (faseAtual == 0 && evento.type == sf::Event::KeyPressed) {
                        if (evento.key.code == sf::Keyboard::Up)
                            pMenuI->selectUp();
                        else if (evento.key.code == sf::Keyboard::Down)
                            pMenuI->selectDown();
                        else if (evento.key.code == sf::Keyboard::Enter || evento.key.code == sf::Keyboard::Space)
                            static_cast<Menus::MenuInicial*>(pMenuI)->confirmar();
                    }
                }

                tempoDecorrido = clock.restart();
                dt = tempoDecorrido.asSeconds();

                GG.getJanela()->clear();

                if (faseAtual == 0) {
                    GG.setAlvoCamera(pMenuI);
                    pMenuI->executar();
                    GG.atualizarCamera();
                }
                else if (faseAtual == 1 && fase_um) {
                    pMenuI->setInMenu(false);

                    pMenuI->getTwoPlayers() ? pJog2->setAtivo(true) : pJog2->setAtivo(false);

                    if (pJog1->isAtivo())
                        GG.setAlvoCamera(static_cast<Ente*>(pJog1));
                    else if (pJog2->isAtivo())
                        GG.setAlvoCamera(static_cast<Ente*>(pJog2));
                    fase_um->executar();
                    GG.atualizarCamera();
                }
                else if (faseAtual == 2 && fase_seg) {
                    pMenuI->setInMenu(false);
                    if (pJog1->isAtivo())
                        GG.setAlvoCamera(static_cast<Ente*>(pJog1));
                    else if (pJog2->isAtivo())
                        GG.setAlvoCamera(static_cast<Ente*>(pJog2));
                    fase_seg->executar();
                    GG.atualizarCamera();
                }

                GG.getJanela()->display();
            }
        }

        void Jogo::iniciarFase1() {

            if (!pJog1)  pJog1 = new Entidades::Personagens::Jogador(VIDA_JOG1);
            if (!pJog2)  pJog2 = new Entidades::Personagens::Jogador(VIDA_JOG2);
            if (!fase_um) {
                fase_um = new Fases::Fase_prim(pJog1, pJog2);
                musica.openFromFile("../stalingrado/assets/audios/fase1.mp3");
                musica.setLoop(true);
                musica.play();
            }

            faseAtual = 1;
        }

        void Jogo::iniciarFase2() {
            if (!pJog1)  pJog1 = new Entidades::Personagens::Jogador(VIDA_JOG1);
            if (!pJog2)  pJog2 = new Entidades::Personagens::Jogador(VIDA_JOG2);
            if (!fase_seg) {
                fase_seg = new Fases::Fase_seg(pJog1, pJog2);
                musica.openFromFile("../stalingrado/assets/audios/fase2.mp3");
                musica.setLoop(true);
                musica.play();
            }

            faseAtual = 2;
        }

        void Jogo::fecharJogo() {
            executando = false;
        }

    }
}
