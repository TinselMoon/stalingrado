#include "Ente.hpp"
#include <SFML/Graphics.hpp>
using namespace Stalingrado;
using namespace Gerenciadores;

Gerenciador_Grafico* Ente::pGG(NULL);
int Ente::contId(0);

Ente::Ente() : id(contId++), pFig(NULL)

{


}

Ente::~Ente() {


}

void desenhar () {



}

static void setGG (Gerenciador_Grafico* pG) {



}

