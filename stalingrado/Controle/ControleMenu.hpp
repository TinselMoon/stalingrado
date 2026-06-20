#pragma once

#include "Observer.hpp"

namespace Menus {
    class Menu;
}

namespace Stalingrado::Controles {

    class ControleMenu : public Observer {
    private:
        Menus::Menu* pMenu;

    public:
        ControleMenu(Menus::Menu* pM = nullptr);
        ~ControleMenu();
        void notifyPressed(std::string key);
        void notifyReleased(std::string key);
        void setMenu(Menus::Menu* p);
    };

}
