#include "StateMachine.hpp"
#include "State.hpp"

#include <iostream>

namespace Stalingrado {
    namespace States {

        StateMachine::StateMachine() {
            lastStateID = indefinido;
            currentStateID = indefinido;
        }

        StateMachine::~StateMachine() {

            std::map<stateID, State*>::iterator it;

            for (it = mapOfStates.begin(); it != mapOfStates.end(); ++it) {
                delete (it->second);
            }
        }

        void StateMachine::changeCurrentState(States::stateID id) {

            lastStateID = currentStateID;
            currentStateID = id;
            mapOfStates[currentStateID]->resetState();
        }

        void StateMachine::updateCurrentState(const float dt) {
            mapOfStates[currentStateID]->update(dt);
        }

        void StateMachine::desenharCurrentState() {
            mapOfStates[currentStateID]->desenharState();
        }

        stateID StateMachine::getCurrentStateID() const {
            return currentStateID;
        }

        void StateMachine::insertState(States::State* pState) {
            if (pState == nullptr) {
                std::cout << " ERRO: ponteiro nulo." << std::endl;
                exit(1);
            }
            mapOfStates.insert(std::pair<stateID, State*>(pState->getID(), pState));
        }

        States::stateID StateMachine::getLastStateID() const {
            return lastStateID;
        }

    }
}