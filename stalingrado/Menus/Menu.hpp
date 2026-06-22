#pragma once

#include "../Graficos/Botao.hpp"

namespace Stalingrado {
    namespace States {
        class Jogo;
    }

    namespace Menus {

        class Menu : public Ente {
        private:
            bool inMenu;
        protected:
            int selected;
            int min;
            int max;
            std::vector<Graficos::Botao*> botoes;
            std::vector<Graficos::Botao*>::iterator it;
            States::Jogo* pJogo;
        public:
            Menu(const std::string& nomeText, States::Jogo* pJ = nullptr);
            virtual ~Menu();
            virtual void executar() = 0;
            bool getInMenu();
            void setInMenu(bool iM);
            void selectDown();
            void selectUp();
            void setValuesBotoes();
            virtual bool getTwoPlayers() const = 0;
        };

    }
}
