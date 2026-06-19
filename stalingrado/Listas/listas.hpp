#pragma once
#include <cstdlib>

namespace Stalingrado {
namespace Listas {

//A SEGUIR IMPLEMENTAÇÃO DA CLASSE LISTA
template <class TL>
class Lista{
public:
    class Elemento{
    private:
        Elemento* pProx;
        TL *pInfo;
    public:
        Elemento() : pProx(nullptr), pInfo(nullptr){}
        ~Elemento(){pProx = nullptr;
        //Talvez liberar a memoria do pInfo
            //delete pInfo;
            //pInfo = nullptr;
        }
        void incluir(TL *pI){pInfo = pI;}
        void setProx(Elemento* pElem){pProx = pElem;}

        Elemento* getProx() const {return pProx;}
        TL* getInfo() const {return pInfo;}
    };
private:
    Elemento* Primeiro;
    Elemento* Ultimo;
public:
    Lista() : Primeiro(nullptr), Ultimo(nullptr){}
    ~Lista(){
        Ultimo = nullptr;

        Elemento *t;
        while(Primeiro != nullptr){
            t = Primeiro;
            Primeiro = Primeiro->getProx();
            delete t;
        }
        t = nullptr;
    }
    Elemento* getPrimeiro() const { return Primeiro; }
    void limpar(){
        Ultimo = nullptr;

        Elemento *t;
        while(Primeiro != nullptr){
            t = Primeiro;
            Primeiro = Primeiro->getProx();
            delete t;
        }
        t = nullptr;
    }

    void incluir(TL* p){
        Elemento* paux = nullptr;
        paux = new Elemento;
        paux->incluir(p);
        if(Primeiro == nullptr){
            Primeiro = paux;
            Ultimo = paux;
            return;
        }
        Ultimo->setProx(paux);
        Ultimo = paux;
    }
    void remover(TL *p){
        Elemento* paux = Primeiro;
        if(paux == nullptr) return;
        if(paux->getInfo() == p){
            Primeiro = paux->getProx();
            if(Primeiro == nullptr){
                Ultimo = nullptr;
            }
            delete paux;
            return;
        }
        while(paux->getProx() != nullptr && paux->getProx()->getInfo() != p){
            paux = paux->getProx();
        }
        if(paux->getProx() == nullptr) return; // elemento não encontrado
        Elemento* t = paux->getProx();
        paux->setProx(t->getProx());
        if(t == Ultimo) Ultimo = paux;
        delete t;
    }
};

}

} // Fim do namespace Stalingrado
