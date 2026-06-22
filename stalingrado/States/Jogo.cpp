#include "Jogo.hpp"

#include <chrono>
#include "../Fases/Fase_prim.hpp"
#include "../Ente.hpp"
#include "../Entidades/Personagens/Jogador.hpp"
#include "../Menus/MenuInicial.hpp"
#include "../Menus/MenuPausa.hpp"
#include "../Menus/MenuGameOver.hpp"
#include "../Menus/MenuRanking.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "../Defines.hpp"

namespace Stalingrado {
    namespace States {

        Jogo* Jogo::instanciaJogo = nullptr;
        float Jogo::dt = 0.0f;

        Jogo::Jogo() : GG(), pMenuI(nullptr), pMenuPausa(nullptr), pMenuGameOver(nullptr), pMenuRanking(nullptr),
        pJog1(nullptr), pJog2(nullptr), fase_um(nullptr), fase_seg(nullptr), clock(), tempoDecorrido(),
        executando(true), faseAtual(0), emPausa(false), emGameOver(false)
        {
            std::srand(static_cast<unsigned int>(std::time(0)));
            Ente::setGG(&GG); //set do gerenciador grafico para entes
            pMenuI = new Menus::MenuInicial(this);
            pMenuPausa = new Menus::MenuPausa(this);
            pMenuGameOver = new Menus::MenuGameOver(this);
            pMenuRanking = new Menus::MenuRanking(this);

            musica.openFromFile("../stalingrado/assets/audios/menuInicial.mp3");
            musica.setLoop(true);
            musica.play();
            musica.setPlayingOffset(sf::seconds(6.50f)); //a musica que peguei so comeca aos 7 segundos, entao ja comeca tocando aos 7s.

        }

        Jogo::~Jogo() {

            if (fase_um != nullptr)        delete fase_um;
            if (fase_seg != nullptr)       delete fase_seg;
            if (pJog1 != nullptr)          delete pJog1;
            if (pJog2 != nullptr)          delete pJog2;
            if (pMenuI != nullptr)         delete pMenuI;
            if (pMenuPausa != nullptr)     delete pMenuPausa;
            if (pMenuGameOver != nullptr)  delete pMenuGameOver;
            if (pMenuRanking != nullptr)   delete pMenuRanking;
        }

        Jogo* Jogo::getInstanciaJogo() {
            if (instanciaJogo == nullptr)
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

                    if (evento.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::End))
                        executando = false;

                    if (faseAtual == 0 && evento.type == sf::Event::KeyPressed) {
                        if (evento.key.code == sf::Keyboard::Up)
                            pMenuI->selectUp();
                        else if (evento.key.code == sf::Keyboard::Down)
                            pMenuI->selectDown();
                        else if (evento.key.code == sf::Keyboard::Enter || evento.key.code == sf::Keyboard::Space)
                            pMenuI->confirmar();
                    }
                    else if (faseAtual == 3 && evento.type == sf::Event::KeyPressed) {
                        if (evento.key.code == sf::Keyboard::Enter || evento.key.code == sf::Keyboard::Escape)
                            pMenuRanking->confirmar();
                    }
                    else if ((faseAtual == 1 || faseAtual == 2) && emGameOver) {
                        if (evento.type == sf::Event::TextEntered)
                            pMenuGameOver->inserirCaractere(evento.text.unicode);
                        else if (evento.type == sf::Event::KeyPressed) {
                            if (evento.key.code == sf::Keyboard::Enter)
                                pMenuGameOver->confirmar();
                            else if (evento.key.code == sf::Keyboard::BackSpace)
                                pMenuGameOver->apagarCaractere();
                        }
                    }
                    else if ((faseAtual == 1 || faseAtual == 2) && emPausa) {
                        if (evento.type == sf::Event::KeyPressed) {
                            if (evento.key.code == sf::Keyboard::Up)
                                pMenuPausa->selectUp();
                            else if (evento.key.code == sf::Keyboard::Down)
                                pMenuPausa->selectDown();
                            else if (evento.key.code == sf::Keyboard::Enter || evento.key.code == sf::Keyboard::Space)
                                pMenuPausa->confirmar();
                            else if (evento.key.code == sf::Keyboard::Escape)
                                retomarJogo();
                        }
                    }
                    else if ((faseAtual == 1 || faseAtual == 2) && evento.type == sf::Event::KeyPressed) {
                        if (evento.key.code == sf::Keyboard::Escape)
                            pausarJogo();
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
                else if (faseAtual == 3) {
                    GG.setAlvoCamera(pMenuI);
                    GG.atualizarCamera();
                    pMenuI->desenhar();
                    GG.usarViewPadrao();
                    pMenuRanking->executar();
                }
                else if (faseAtual == 1 && fase_um != nullptr) {

                    if (emGameOver) {
                        GG.setAlvoCamera(pMenuGameOver);
                        pMenuGameOver->executar();
                        GG.atualizarCamera();
                    }
                    else if (emPausa) {
                        GG.usarCameraJogo();
                        fase_um->desenharFase();
                        GG.usarViewPadrao();
                        pMenuPausa->executar();
                    }
                    else {
                        pJog2->setAtivo(pMenuI->getTwoPlayers() && pJog2->getVida() > 0);

                        if (pJog1->isAtivo())
                            GG.setAlvoCamera(static_cast<Ente*>(pJog1));
                        else if (pJog2->isAtivo())
                            GG.setAlvoCamera(static_cast<Ente*>(pJog2));
                        fase_um->executar();
                        GG.atualizarCamera();

                        bool jog1Morto = (pJog1->getVida() <= 0);
                        bool jog2Morto = (!pMenuI->getTwoPlayers() || pJog2->getVida() <= 0);
                        if (jog1Morto && jog2Morto)
                            irParaGameOver(false);
                        else if (fase_um->faseConcluida())
                            iniciarFase2();
                    }
                }
                else if (faseAtual == 2 && fase_seg != nullptr) {

                    if (emGameOver) {
                        GG.setAlvoCamera(pMenuGameOver);
                        pMenuGameOver->executar();
                        GG.atualizarCamera();
                    }
                    else if (emPausa) {
                        GG.usarCameraJogo();
                        fase_seg->desenharFase();
                        GG.usarViewPadrao();
                        pMenuPausa->executar();
                    }
                    else {
                        pJog2->setAtivo(pMenuI->getTwoPlayers() && pJog2->getVida() > 0);

                        if (pJog1->isAtivo())
                            GG.setAlvoCamera(static_cast<Ente*>(pJog1));
                        else if (pJog2->isAtivo())
                            GG.setAlvoCamera(static_cast<Ente*>(pJog2));
                        fase_seg->executar();
                        GG.atualizarCamera();

                        bool jog1Morto = (pJog1->getVida() <= 0);
                        bool jog2Morto = (!pMenuI->getTwoPlayers() || pJog2->getVida() <= 0);
                        if (jog1Morto && jog2Morto)
                            irParaGameOver(false);
                        else if (fase_seg->faseConcluida())
                            irParaGameOver(true);
                    }
                }

                GG.getJanela()->display();
            }
        }

        void Jogo::iniciarFase1() {

            if (pJog1 == nullptr)  pJog1 = new Entidades::Personagens::Jogador(VIDA_JOG1, 1);
            if (pJog2 == nullptr)  pJog2 = new Entidades::Personagens::Jogador(VIDA_JOG2, 2);
            if (fase_um == nullptr) {
                fase_um = new Fases::Fase_prim(pJog1, pJog2);
                musica.openFromFile("../stalingrado/assets/audios/fase1.mp3");
                musica.setLoop(true);
                musica.play();
            }

            faseAtual = 1;
        }

        void Jogo::iniciarFase2() {
            if (pJog1 == nullptr)  pJog1 = new Entidades::Personagens::Jogador(VIDA_JOG1, 1);
            if (pJog2 == nullptr)  pJog2 = new Entidades::Personagens::Jogador(VIDA_JOG2, 2);
            if (fase_seg == nullptr) {
                fase_seg = new Fases::Fase_seg(pJog1, pJog2);
                musica.openFromFile("../stalingrado/assets/audios/fase2.mp3");
                musica.setLoop(true);
                musica.setVolume(16);
                musica.play();
            }

            faseAtual = 2;
        }

        int Jogo::lerFaseSalva() {

            std::ifstream arquivo(SAVE_PATH);
            if (!arquivo.is_open()) return 0;

            std::string tag;
            int numero = 0;
            arquivo >> tag >> numero;
            arquivo.close();

            if (tag != "FASE") return 0;
            return numero;
        }

        void Jogo::retomarFase1() {

            if (pJog1 == nullptr)  pJog1 = new Entidades::Personagens::Jogador(VIDA_JOG1, 1);
            if (pJog2 == nullptr)  pJog2 = new Entidades::Personagens::Jogador(VIDA_JOG2, 2);
            if (fase_um != nullptr) { delete fase_um; fase_um = nullptr; }

            bool temSalvo = (lerFaseSalva() == 1);
            fase_um = new Fases::Fase_prim(pJog1, pJog2, temSalvo);

            musica.openFromFile("../stalingrado/assets/audios/fase1.mp3");
            musica.setLoop(true);
            musica.play();

            faseAtual = 1;
        }

        void Jogo::retomarFase2() {

            if (pJog1 == nullptr)  pJog1 = new Entidades::Personagens::Jogador(VIDA_JOG1, 1);
            if (pJog2 == nullptr)  pJog2 = new Entidades::Personagens::Jogador(VIDA_JOG2, 2);
            if (fase_seg != nullptr) { delete fase_seg; fase_seg = nullptr; }

            bool temSalvo = (lerFaseSalva() == 2);
            fase_seg = new Fases::Fase_seg(pJog1, pJog2, temSalvo);

            musica.openFromFile("../stalingrado/assets/audios/fase2.mp3");
            musica.setLoop(true);
            musica.setVolume(16);
            musica.play();

            faseAtual = 2;
        }

        void Jogo::fecharJogo() {
            executando = false;
        }

        void Jogo::pausarJogo() {
            emPausa = true;
            pMenuPausa->resetMenu();
        }

        void Jogo::retomarJogo() {
            emPausa = false;
        }

        void Jogo::sairFaseAtual() {

            std::ofstream arquivo(SAVE_PATH);
            if (arquivo.is_open()) {
                if (faseAtual == 1 && fase_um != nullptr) {
                    arquivo << "FASE 1\n";
                    fase_um->salvarFase(arquivo);
                }
                else if (faseAtual == 2 && fase_seg != nullptr) {
                    arquivo << "FASE 2\n";
                    fase_seg->salvarFase(arquivo);
                }
                arquivo.close();
            }

            voltarAoMenuPrincipal();
        }

        void Jogo::irParaGameOver(bool vitoria) {
            emGameOver = true;
            int pontuacaoTotal = pJog1->getPontos() + (pMenuI->getTwoPlayers() ? pJog2->getPontos() : 0);
            pMenuGameOver->configurar(vitoria, pontuacaoTotal);
        }

        void Jogo::abrirRanking() {
            faseAtual = 3;
            pMenuRanking->resetMenu();
        }

        void Jogo::sairRanking() {
            faseAtual = 0;
            pMenuI->setInMenu(true);
        }

        void Jogo::voltarAoMenuPrincipal() {

            if (fase_um != nullptr)  { delete fase_um;  fase_um = nullptr; }
            if (fase_seg != nullptr) { delete fase_seg; fase_seg = nullptr; }
            if (pJog1 != nullptr)    { delete pJog1;    pJog1 = nullptr; }
            if (pJog2 != nullptr)    { delete pJog2;    pJog2 = nullptr; }

            emPausa = false;
            emGameOver = false;
            faseAtual = 0;
            pMenuI->resetState();

            musica.stop();
            musica.openFromFile("../stalingrado/assets/audios/menuInicial.mp3");
            musica.setLoop(true);
            musica.play();
        }

    }
}
