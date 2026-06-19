#pragma once

#include "Observer.hpp"

namespace Stalingrado {
    namespace Controles {
    
        class TextInput : public Observer {
        private:
            std::string text;

        public:
            TextInput();
            ~TextInput();
            void notifyPressed(std::string key);
            void notifyReleased(std::string key);
            std::string getString() const;
            void reset();

        };

    }
}
