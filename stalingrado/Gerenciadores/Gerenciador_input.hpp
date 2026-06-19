#pragma once

#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

namespace Stalingrado {
    namespace Controles {
        class Observer;
    }
}

namespace Stalingrado {
    namespace Gerenciadores {

        class Gerenciador_input {
        private:
            std::list<Controles::Observer*> objObserving;
            std::list<Controles::Observer*>::iterator it;
            std::map<sf::Keyboard::Key, std::string> keyMap;
            static Gerenciador_input* instancia;
            Gerenciador_input();
        public:
            ~Gerenciador_input();

            static Gerenciador_input* getInstancia();

            void Attach(auto* pObserver) {
                objObserving.push_back(pObserver);
            }

            void Detach(auto* pObserver) {
                objObserving.remove(pObserver);
            }

            void handleKeyPressed(sf::Keyboard::Key key);
            void handleKeyReleased(sf::Keyboard::Key key);
            std::string getKeyasString(sf::Keyboard::Key key);
        };

    }
}