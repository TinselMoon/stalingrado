#include "MenuInicial.hpp"
#include "../States/Jogo.hpp"

#include "../Defines.hpp"

//Inspirado na implementação do ex-monitor Matheus Augusto Burda, conforme este mostra nos seus vídeos tutoriais.

namespace Stalingrado {
    namespace Menus {
        using namespace States;
        using namespace Graficos;

        MenuInicial::MenuInicial(Jogo* pJ) : Menu("Menu", pJ), two_players(false), State(menuInicial) {
            resetState();
        }

        MenuInicial::~MenuInicial() {

        }

        bool MenuInicial::getTwoPlayers() const {
            return two_players;
        }

        void MenuInicial::executar() {

            desenhar();

            for (it = botoes.begin(); it != botoes.end(); ++it)
                (*it)->executar();
        }

        void MenuInicial::confirmar() {

            if (getInMenu()) {

                switch (selected) {

                    case 0:
                        setInMenu(false);
                        pJogo->iniciarFase1();
                        break;

                    case 1:
                        setInMenu(false);
                        pJogo->retomarFase1();
                        break;

                    case 2:
                        setInMenu(false);
                        pJogo->iniciarFase2();
                        break;

                    case 3:
                        setInMenu(false);
                        pJogo->retomarFase2();
                        break;

                    case 4:
                        two_players = !two_players;
                        resetState();
                        break;

                    case 5:
                        setInMenu(false);
                        pJogo->abrirRanking();
                        break;

                    case 6:
                        setInMenu(false);
                        pJogo->fecharJogo();
                        break;

                    default:
                        break;

                }
            }
        }

        void MenuInicial::carregarBotoes() {

            Botao* bt = nullptr;

            //recarregar os botoes toda vez
            while (!botoes.empty()) {
                bt = botoes.back();
                if (bt != nullptr) delete bt;
                botoes.pop_back();
            }

            //BOTAO 0: JOGAR NOVA FASE 1
            bt = new Botao(POS_BOTAO_0, "NOVA  FASE  1"); bt->select(true);
            botoes.push_back(bt);

            //BOTAO 1: RETOMAR FASE 1
            bt = new Botao(POS_BOTAO_1, "RETOMAR  FASE  1");
            botoes.push_back(bt);

            //BOTAO 2: JOGAR NOVA FASE 2
            bt = new Botao(POS_BOTAO_2, "NOVA  FASE  2");
            botoes.push_back(bt);

            //BOTAO 3: RETOMAR FASE 2
            bt = new Botao(POS_BOTAO_3, "RETOMAR  FASE  2");
            botoes.push_back(bt);

            //BOTAO 4: NUMERO DE JOGADORES
            bt = new Botao(POS_BOTAO_4, two_players ? "2  JOGADORES" : "1  JOGADOR");
            botoes.push_back(bt);

            //BOTAO 5: VER RANKING
            bt = new Botao(POS_BOTAO_5, "VER  RANKING");
            botoes.push_back(bt);

            //BOTAO 6: SAIR DO JOGO
            bt = new Botao(POS_BOTAO_6, "SAIR  DO  JOGO");
            botoes.push_back(bt);

        }

        void MenuInicial::resetState() {
            carregarBotoes();
            setValuesBotoes();
            setInMenu(true);
        }

        void MenuInicial::update(const float dt) {
            setInMenu(true);
        }

        void MenuInicial::desenharState() {
            desenhar();
        }

    }
}
