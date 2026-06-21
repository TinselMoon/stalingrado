#include "MenuGameOver.hpp"
#include "../States/Jogo.hpp"
#include <fstream>
#include <sstream>

#include "../Defines.hpp"

namespace Stalingrado {
    namespace Menus {

        MenuGameOver::MenuGameOver(States::Jogo* pJ) : Menu("Menu"), pJogo(pJ), vitoria(false), pontuacaoFinal(0) {

        }

        MenuGameOver::~MenuGameOver() { }

        bool MenuGameOver::getTwoPlayers() const {
            return false;
        }

        void MenuGameOver::configurar(bool vitoriaFinal, int pontuacao) {
            vitoria = vitoriaFinal;
            pontuacaoFinal = pontuacao;
            nomeDigitado = "";
        }

        void MenuGameOver::executar() {

            desenhar();

            if (vitoria)
                pGG->desenharTextoCoordAbs("PARABENS!  VOCE  ZEROU  O  JOGO.", 45, 250.f, 300.f);
            else
                pGG->desenharTextoCoordAbs("GAME  OVER!", 45, 250.f, 300.f);

            std::stringstream pontos;
            pontos << "PONTUACAO  FINAL:  " << pontuacaoFinal;
            pGG->desenharTextoCoordAbs(pontos.str(), 32, 250.f, 400.f);

            pGG->desenharTextoCoordAbs("Escreva seu nome para registrar sua pontuacao:", 28, 250.f, 500.f);
            pGG->desenharTextoCoordAbs(nomeDigitado, 32, 250.f, 560.f);
        }

        void MenuGameOver::inserirCaractere(unsigned int unicode) {
            if (unicode < 32 || unicode > 126) return; //somente caracteres imprimiveis (ASCII)
            if (nomeDigitado.size() < MAX_TAM_NOME)
                nomeDigitado += static_cast<char>(unicode);
        }

        void MenuGameOver::apagarCaractere() {
            if (!nomeDigitado.empty())
                nomeDigitado.erase(nomeDigitado.size() - 1);
        }

        void MenuGameOver::confirmar() {

            if (nomeDigitado.empty()) return;

            std::ofstream arquivo(RANKING_PATH, std::ios::app);
            if (arquivo.is_open()) {
                arquivo << nomeDigitado << " " << pontuacaoFinal << "\n";
                arquivo.close();
            }

            pJogo->voltarAoMenuPrincipal();
        }

    }
}
