#include "State.hpp"

namespace Stalingrado {
    namespace States {

        State::State(States::stateID id) :
        id(id) { }

        State::~State() { }

        States::stateID State::getID() const {
            return id;
        }

    }
}