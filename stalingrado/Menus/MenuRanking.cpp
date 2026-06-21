#include "MenuRanking.hpp"
#include "../States/Jogo.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

#include "../Defines.hpp"

namespace Stalingrado {
    namespace Menus {
        using namespace Graficos;

        bool MenuRanking::compararPontuacao(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
            return a.first > b.first;
        }

        MenuRanking::MenuRanking(States::Jogo* pJ) : Menu("Menu"), pJogo(pJ) {
            resetMenu();
        }

        MenuRanking::~MenuRanking() {
            limparEntradas();
        }

        bool MenuRanking::getTwoPlayers() const {
            return false;
        }

        void MenuRanking::limparEntradas() {
            for (itTexto = entradas.begin(); itTexto != entradas.end(); ++itTexto)
                if (*itTexto != nullptr) delete (*itTexto);
            entradas.clear();
        }

        void MenuRanking::carregarPontuacoes() {

            std::ifstream arquivo(RANKING_PATH);

            std::vector<std::pair<int, std::string> > pontuacoes;
            std::string nome;
            int pontos;

            while (arquivo >> nome >> pontos)
                pontuacoes.push_back(std::pair<int, std::string>(pontos, nome));

            arquivo.close();

            std::sort(pontuacoes.begin(), pontuacoes.end(), MenuRanking::compararPontuacao);

            float posY = POS_TEXTO_RANKING_INICIAL.y;
            int max = (int)pontuacoes.size() < MAX_ENTRADAS_RANKING ? (int)pontuacoes.size() : MAX_ENTRADAS_RANKING;

            for (int i = 0; i < max; i++) {
                std::stringstream linha;
                linha << (i + 1) << "  -  " << pontuacoes[i].second << "   " << pontuacoes[i].first;
                Texto* txt = new Texto(sf::Vector2f(POS_TEXTO_RANKING_INICIAL.x, posY), linha.str());
                txt->setFontSize(28);
                txt->setOutline(3.f);
                entradas.push_back(txt);
                posY += ESPACAMENTO_RANKING;
            }

            if (pontuacoes.empty()) {
                Texto* txt = new Texto(POS_TEXTO_RANKING_INICIAL, "Nenhuma  pontuacao  registrada  ainda.");
                txt->setFontSize(28);
                entradas.push_back(txt);
            }
        }

        void MenuRanking::executar() {

            desenhar();

            pGG->desenharTextoCoordAbs("RANKING", 50, POS_TEXTO_RANKING_TITULO.x, POS_TEXTO_RANKING_TITULO.y);

            for (it = botoes.begin(); it != botoes.end(); ++it)
                (*it)->executar();

            for (itTexto = entradas.begin(); itTexto != entradas.end(); ++itTexto)
                (*itTexto)->executar();
        }

        void MenuRanking::confirmar() {

            if (getInMenu()) {
                setInMenu(false);
                pJogo->sairRanking();
            }
        }

        void MenuRanking::carregarBotoes() {

            Botao* bt = nullptr;

            while (!botoes.empty()) {
                bt = botoes.back();
                if (bt != nullptr) delete bt;
                botoes.pop_back();
            }

            //BOTAO 0: VOLTAR
            bt = new Botao(POS_BOTAO_RANKING_VOLTAR, "VOLTAR"); bt->select(true);
            botoes.push_back(bt);
        }

        void MenuRanking::resetMenu() {
            carregarBotoes();
            setValuesBotoes();
            setInMenu(true);
            limparEntradas();
            carregarPontuacoes();
        }

    }
}
