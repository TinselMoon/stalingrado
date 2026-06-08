#include "Fase_prim.hpp"
#include "../Entidades/Entidade.hpp"
#include "../Entidades/Personagens/Inim_facil.hpp"
#include "../Entidades/Personagens/Jogador.hpp"
#include "../Entidades/Chao.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

namespace Stalingrado{

namespace Fases{

Fase_prim::Fase_prim(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2) :
Fase(pJogador1, pJogador2, "Cenario_fase_um"), maxInimFaceis(8), chao(NULL)
{
    //Aqui eu devo criar a fase, configurar a posição de cada inimigo, jogador e obstáculo
    comprimentoFase = 10000;
    criarCenario();
    criarInimigos();
    //Inclui o jogador na fase
    lista_ents.incluir(static_cast<Entidades::Entidade*>(pJogador1));
    pJogador1->movePos(300.0f, 500.0f);
}

Fase_prim::~Fase_prim(){
    if (pJog1 != NULL) {
        lista_ents.remover(static_cast<Entidades::Entidade*>(pJog1));
    }
    if (pJog2 != NULL) {
        lista_ents.remover(static_cast<Entidades::Entidade*>(pJog2));
    }
}

void Fase_prim::criarInimFaceis(float x, float y){
    Entidades::Personagens::Inim_facil *pEntidade = new Entidades::Personagens::Inim_facil(5, 1);
    GC.incluirInimigo(pEntidade);
    float pos_aleatoria = (rand() % (comprimentoFase - (int)x)) + x;
    pEntidade->movePos(pos_aleatoria, y);
    lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
}
void Fase_prim::criarArame_farp(){

}

void Fase_prim::criarInimigos(){
    const char* caminhoArquivo = "../stalingrado/assets/fase1/Inimigos.txt";
    try{
        std::ifstream arquivo(caminhoArquivo);
        
        if(!arquivo.is_open()){
            string erro = "Não foi possível abrir o arquivo ";
            erro.append(caminhoArquivo);
            throw runtime_error(erro);
        }
        int cont_inim_faceis = 0;
        int cont_inim_medios = 0;
        std::string tipo;
        float x;
        float y;

        // Personagem, pos x, pos y
        // A posição x que será passada será a borda esquerda limite para geração de posição aleatoria do personagem
        while (arquivo >> tipo >> x >> y) {
            if (tipo == "INIM_FACIL") {
                if(cont_inim_faceis == maxInimFaceis){
                    cout << "Máximo de inimigos fáceis atingido, ignorando os próximos" << endl;
                }
                else{
                    criarInimFaceis(x, y);
                    cont_inim_faceis++;
                }
            }
            else if (tipo == "INIM_MEDIO") {
                if(cont_inim_medios == maxInimMedios){
                    cout << "Máximo de inimigos médios atingido, ignorando os próximos" << endl;
                }
                else{
                    criarInimMedios(x, y);
                    cont_inim_medios++;
                }
            }
        }
        arquivo.close();
    }
    catch(const std::exception& erro){
        std::cerr << "Erro: " << erro.what() << std::endl;
    }
}
void Fase_prim::criarObstaculos(){

}

void Fase_prim::criarCenario(){
    //aqui cria o chao e posiciona ele
    chao = new Entidades::Chao(comprimentoFase);
    chao->setPosicao(0.f, 750.f);
    GC.setChao(chao);
    lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));

    //aqui configura o fundo
    personagem.setPosition(0.f, 0.f);
    personagem.setTextureRect(sf::IntRect(0, 0, comprimentoFase, 750));

}

void Fase_prim::executar(){
    lista_ents.percorrer();
    GC.executar();
    desenhar();
    lista_ents.desenhar();
    pGG->desenharTextoCoordAbs("Fase 1", 50, 100.f, 100.f);
    std::stringstream vida;
    vida << "Vida Jogador 1: " << pJog1->getVida();
    pGG->desenharTextoCamera(vida.str(), 20, 50.f, 50.f);
}

}

}
