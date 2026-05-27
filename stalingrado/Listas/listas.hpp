#pragma once
#include <cstdlib>

namespace Stalingrado {
namespace Listas {

//A SEGUIR IMPLEMENTAÇÃO DA CLASSE LISTA
template <class TL>
class Lista{
private:
    class Elemento{
    private:
        Elemento* pProx;
        TL *pInfo;
    public:
        Elemento() : pProx(NULL), pInfo(NULL){}
        ~Elemento(){pProx = NULL;
        //Talvez liberar a memoria do pInfo
            //delete pInfo;
            //pInfo = NULL;
        }
        void incluir(TL *pI){pInfo = pI;}
        void setProx(Elemento* pElem){pProx = pElem;}

        Elemento* getProx() const {return pProx;}
        TL* getInfo() const {return pInfo;}
    };
    Elemento* Primeiro;
    Elemento* Ultimo;
public:
    Lista() : Primeiro(NULL), Ultimo(NULL){}
    ~Lista(){
        Ultimo = NULL;

        Elemento *t;
        while(Primeiro != NULL){
            t = Primeiro;
            Primeiro = Primeiro->getProx();
            delete t;
        }
        t = NULL;
    }

    void limpar(){
        Ultimo = NULL;

        Elemento *t;
        while(Primeiro != NULL){
            t = Primeiro;
            Primeiro = Primeiro->getProx();
            delete t;
        }
        t = NULL;
    }

    void incluir(TL* p){
        Elemento* paux = NULL;
        paux = new Elemento;
        paux->incluir(p);
        if(Primeiro == NULL){
            Primeiro = paux;
            Ultimo = paux;
            return;
        }
        Ultimo->setProx(paux);
        Ultimo = paux;
    }
    void remover(TL *p){
        Elemento* paux = Primeiro;
        if(paux == NULL) return;
        if(paux->getInfo() == p){
            Primeiro = paux->getProx();
            if(Primeiro == NULL){
                Ultimo = NULL;
            }
            delete paux;
            return;
        }
        while(paux->getProx() != NULL && paux->getProx()->getInfo() != p){
            paux = paux->getProx();
        }
        if(paux->getProx() == NULL) return; // elemento não encontrado
        Elemento* t = paux->getProx();
        paux->setProx(t->getProx());
        if(t == Ultimo) Ultimo = paux;
        delete t;
    }
};

}

} // Fim do namespace Stalingrado
