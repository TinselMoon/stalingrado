#pragma once
#include <cstddef>

namespace Stalingrado {
    namespace States {

        enum stateID {
            menuInicial=0,
            faseUm=1,
            faseDois=2,
            ranking=3,
            indefinido=-1
        };

        class State {

        protected:
            stateID id;

        public:
            State(stateID id=indefinido);
            virtual ~State();
            stateID getID() const;
            virtual void update(const float dt) = 0;
            virtual void resetState() = 0;
            virtual void desenharState() = 0;
        };

    }
}
