#pragma once

#include "../Gerenciadores/Gerenciador_input.hpp"

namespace Stalingrado {
    namespace Controles {

        class Observer {
        private:
            Gerenciadores::Gerenciador_input* pInput;

        public:
            Observer();
            virtual ~Observer();
            virtual void notifyPressed(std::string key) = 0;
            virtual void notifyReleased(std::string key) = 0;
        };

    }
}