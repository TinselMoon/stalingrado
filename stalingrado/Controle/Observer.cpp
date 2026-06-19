#include "Observer.hpp"

namespace Stalingrado {
    namespace Controles {

        Observer::Observer() {
            this->pInput = Gerenciadores::Gerenciador_input::getInstancia();
            pInput->Attach(this);
        }

        Observer::~Observer() {
            pInput->Detach(this);
        }

    }
}
