#pragma once

#include "../Controle/ControleMenu.hpp"
#include "../Gráficos/Botao.hpp"

namespace Stalingrado {
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
        public:
            Menu();
            virtual ~Menu();
            virtual void executar() = 0;
            bool getInMenu();
            void setInMenu(bool iM);
            //observer
            void selectDown();
            void selectUp();
            void setValuesBotoes();
        };

    }
}