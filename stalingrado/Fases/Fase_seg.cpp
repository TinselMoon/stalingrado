#include "Fase_seg.hpp"
#include "../Entidades/Entidade.hpp"
#include "../Entidades/Personagens/Inim_medio.hpp"
#include "../Entidades/Personagens/Inim_chefao.hpp"
#include "../Entidades/Personagens/Jogador.hpp"
#include "../Entidades/Chao.hpp"
#include "../Entidades/Projetil.hpp"
#include "../Entidades/Obstaculos/Explosivo.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

namespace Stalingrado {
    namespace Fases {

        Fase_seg::Fase_seg(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2) :
        Fase(pJogador1, pJogador2, "Cenario_fase_dois", "Chao_fase_dois"), maxInimChefoes(10), maxEntulhos(20), maxExplosivos(10)
        {
            //Aqui eu devo criar a fase, configurar a posição de cada inimigo, jogador e obstáculo
            comprimentoFase = 10000;
            criarCenario();
            criarProjeteis();
            criarInimigos();
            //Inclui os jogadores na fase
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pJogador1));
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pJogador2));
            if (pJogador1) pJogador1->movePos(300.0f, 500.0f);
            if (pJogador2) pJogador2->movePos(350.0f, 500.0f);
        }

        Fase_seg::~Fase_seg(){
            if (pJog1 != NULL) {
                lista_ents.remover(static_cast<Entidades::Entidade*>(pJog1));
            }
            if (pJog2 != NULL) {
                lista_ents.remover(static_cast<Entidades::Entidade*>(pJog2));
            }
        }

        void Fase_seg::criarExplosivos(float x1, float x2){

            Entidades::Obstaculos::Explosivo *pEntidade = new Entidades::Obstaculos::Explosivo();
            GC.incluirObstaculo(pEntidade);
            float pos_aleatoria = (rand() % ((int)x2 - (int)x1)) + x1;
            pEntidade->movePos(pos_aleatoria, 900.f);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
        }

        void Fase_seg::criarChefoes(float x, float y) {

            Entidades::Personagens::Inim_chefao *pEntidade = new Entidades::Personagens::Inim_chefao(15, 5);
            GC.incluirInimigo(pEntidade);
            float pos_aleatoria = (rand() % (comprimentoFase - (int)x)) + x;
            pEntidade->movePos(pos_aleatoria, y);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
            pEntidade->setProjetil(GC.getProjetil(pEntidade->getIdChef()));
        }
        
        void Fase_seg::criarProjeteis() {
            for(int i = 0; i < maxInimChefoes; i++){
                Entidades::Projetil *pProjetil = new Entidades::Projetil();
                GC.incluirProjetil(pProjetil);
                lista_ents.incluir(static_cast<Entidades::Entidade*>(pProjetil));
            }
        }

        void Fase_seg::criarInimigos(){
            const char* caminhoArquivo = "../stalingrado/assets/fase2/Inimigos.txt";
            try{
                std::ifstream arquivo(caminhoArquivo);

                if(!arquivo.is_open()){
                    string erro = "Não foi possível abrir o arquivo";
                    erro.append(caminhoArquivo);
                    throw runtime_error(erro);
                }
                int cont_inim_medios = 0;
                int cont_inim_chefoes = 0;
                std::string tipo;
                float x;
                float y;

                // Personagem, pos x, pos y
                // A posição x que será passada será a borda esquerda limite para geração de posição aleatoria do personagem
                while (arquivo >> tipo >> x >> y) {
                    if (tipo == "INIM_MEDIO") {
                        if(cont_inim_medios == maxInimMedios)
                            cout << "Máximo de inimigos médios atingido, ignorando os próximos" << endl;
                        else {
                            criarInimMedios(x, y);
                            cont_inim_medios++;
                        }
                    }
                    else if (tipo == "INIM_CHEFAO") {
                        if (cont_inim_chefoes == maxInimChefoes)
                            cout << "Máximo de inimigos do tipo chefão atingido, ignorando os próximos" << endl;
                        else {
                            criarChefoes(x, y);
                            cont_inim_chefoes++;
                        }
                    }
                }
                arquivo.close();
            }
            catch(const std::exception& erro){
                std::cerr << "Erro: " << erro.what() << std::endl;
            }
        }
        void Fase_seg::criarObstaculos(){
            const char* caminhoArquivo = "../stalingrado/assets/fase2/Obstaculos.txt";
            try{
                std::ifstream arquivo(caminhoArquivo);

                if(!arquivo.is_open()){
                    string erro = "Não foi possível abrir o arquivo ";
                    erro.append(caminhoArquivo);
                    throw runtime_error(erro);
                }
                int cont_entulhos = 0;
                int cont_explosivos = 0;
                std::string tipo;
                float x1;
                float x2;

                // Obstaculo, pos x min, pos x maxima
                // As posições x min e x maxima delimitam o espaço em que será gerado aleatoriamente o entulho
                while (arquivo >> tipo >> x1 >> x2) {
                    if (tipo == "ENTULHO") {
                        if(cont_entulhos == maxEntulhos){
                            cout << "Máximo de entulhos atingido, ignorando os próximos" << endl;
                        }
                        else{
                            criarPlataformas(x1, x2);
                            cont_entulhos++;
                        }
                    }
                    else if (tipo == "EXPLOSIVO") {

                        if (cont_explosivos == maxExplosivos)
                            cout << "Maximo de explosivos atingido, ignorando os proximos" << endl;
                        else {
                            criarExplosivos(x1, x2);
                            cont_explosivos++;
                        }
                    }
                }
                arquivo.close();
            }
            catch(const std::exception& erro){
                std::cerr << "Erro: " << erro.what() << std::endl;
            }

        }

        void Fase_seg::criarCenario(){
            //aqui cria o chao e posiciona ele
            chao = new Entidades::Chao(comprimentoFase, "Chao_fase_dois");
            chao->setPosicao(0.f, 750.f);
            GC.setChao(chao);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));

            //aqui configura o fundo
            personagem.setPosition(0.f, 0.f);
            personagem.setTextureRect(sf::IntRect(0, 0, comprimentoFase, 750));
            criarObstaculos();
            GC.tratarColisoesObsObs();
        }

        void Fase_seg::executar(){
            lista_ents.percorrer();
            GC.executar();
            desenhar();
            lista_ents.desenhar();
            pGG->desenharTextoCoordAbs("Fase 2:\t Rattenkrieg\t", 50, 100.f, 100.f);
            std::stringstream vida1, vida2;
            vida1 << "Vida \tJogador \t1:\t " << pJog1->getVida();
            pGG->desenharTextoCamera(vida1.str(), 20, 50.f, 10.f);
            if(pJog2 != NULL){
                vida2 << "Vida \tJogador \t2:\t " << pJog2->getVida();
                pGG->desenharTextoCamera(vida2.str(), 20, 50.f, 50.f);
            }
        }

    }
}
