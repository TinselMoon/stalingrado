#pragma once

#include "../Gráficos/Botao.hpp"

namespace Stalingrado {
    namespace Menus {
        using namespace std;

        class Menu : public Ente {
        private:
            bool inMenu;
        protected:
            int selected;
            int min;
            int max;
            std::vector<Graficos::Botao*> botoes;
            std::vector<Graficos::Botao*>::iterator it;
        public:
            Menu(const string& nomeText);
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