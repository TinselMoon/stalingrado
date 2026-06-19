#pragma once

#include "State.hpp"
#include <map>

//Fortemente modelado com base na implementacao do ex-monitor Matheus Augusto Burda, assim com as demais classes de tal
//padrao de projeto

namespace Stalingrado {
    namespace States {

        class StateMachine {
        protected:
            States::stateID currentStateID;
            States::stateID lastStateID;

            std::map<stateID, State*> mapOfStates;

        public:
            StateMachine();

            virtual ~StateMachine();

            void changeCurrentState(States::stateID id);

            void updateCurrentState(const float dt);

            void desenharCurrentState();

            States::stateID getCurrentStateID() const;

            void insertState(States::State* pState);

            States::stateID getLastStateID() const;
        };

    }
}