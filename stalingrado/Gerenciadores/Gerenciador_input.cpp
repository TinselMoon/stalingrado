#include "Gerenciador_input.hpp"
#include "../Controle/Observer.hpp"

namespace Stalingrado {
    namespace Gerenciadores {

        Gerenciador_input* Gerenciador_input::instancia = nullptr;

        Gerenciador_input::Gerenciador_input() {
            keyMap[sf::Keyboard::W] = "W";
            keyMap[sf::Keyboard::A] = "A";
            keyMap[sf::Keyboard::S] = "S";
            keyMap[sf::Keyboard::D] = "D";
            keyMap[sf::Keyboard::Space] = "Space";
            keyMap[sf::Keyboard::Enter] = "Enter";
            keyMap[sf::Keyboard::Escape] = "Escape";
            keyMap[sf::Keyboard::Up] = "Up";
            keyMap[sf::Keyboard::Down] = "Down";
            keyMap[sf::Keyboard::Left] = "Left";
            keyMap[sf::Keyboard::Right] = "Right";
        }

        Gerenciador_input::~Gerenciador_input() {
        }

        Gerenciador_input* Gerenciador_input::getInstancia() {
            if (!instancia)
                instancia = new Gerenciador_input();
            return instancia;
        }

        void Gerenciador_input::handleKeyPressed(sf::Keyboard::Key key) {
            std::string keyString = getKeyasString(key);
            for (it = objObserving.begin(); it != objObserving.end(); ++it)
                (*it)->notifyPressed(keyString);
        }

        void Gerenciador_input::handleKeyReleased(sf::Keyboard::Key key) {
            std::string keyString = getKeyasString(key);
            for (it = objObserving.begin(); it != objObserving.end(); ++it)
                (*it)->notifyReleased(keyString);
        }

        std::string Gerenciador_input::getKeyasString(sf::Keyboard::Key key) {
            if (keyMap.find(key) != keyMap.end())
                return keyMap[key];
            return "";
        }

    }
}
