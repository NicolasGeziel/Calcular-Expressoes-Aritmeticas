#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
using namespace std;

template <typename T>
struct Nodo{
    T elemento;
    Nodo<T> *Anterior;
};

template <typename T>
struct PilhaDinamica{
    Nodo<T> *Topo;
    int cardinalidade;
};

template <typename T>
void criarpilha(PilhaDinamica<T>&pilha){
    pilha.cardinalidade=0;
    pilha.Topo=NULL;
}

template <typename T>
void DestruirPilha(PilhaDinamica<T>&pilha){
    Nodo<T>*p=pilha.Topo;
    Nodo<T>* deletp;
    while(p!=NULL)
    {
        deletp=p;
        p=p->Anterior;
        delete deletp;
    }
    pilha.cardinalidade=0;
}

template<typename T>
bool verificarPilhaVazia(PilhaDinamica<T>pilha){
    return pilha.cardinalidade==0;
}

template<typename T>
int numeroElemento(PilhaDinamica<T>pilha){
    return pilha.cardinalidade;
}

template <typename T>
bool verificarElemento(PilhaDinamica<T>pilha,T elemento){
    Nodo<T> *p = pilha.Topo;
    while(p!= NULL)
    {
        if(p->elemento==elemento)
            return true;
        p=p->Anterior;

    }
    return false;
}

template <typename T>
T retornaElemento(PilhaDinamica<T>&pilha,int posicao){
    if(posicao < 1 || posicao > pilha.cardinalidade)
        throw "Posicao invalida";
    else
    {
        Nodo<T>* p = pilha.Topo;
        int i=1;
        while(i != posicao)
        {
            p = p->Anterior;
            i++;
        }
         return p->elemento;
    }
}

template<typename T>
T retornaElementoTopo(PilhaDinamica<T> pilha){
return pilha.Topo->elemento;
}

template <typename T>
void empilhar(PilhaDinamica<T>&pilha,T elemento){
    Nodo<T>*p=new Nodo<T>;
    if(p==NULL)
        throw"Sem espaço";
    p->elemento=elemento;
    if(pilha.cardinalidade==0)
        p->Anterior=NULL;
    else
        p->Anterior=pilha.Topo;
    pilha.Topo=p;
    pilha.cardinalidade++;
}

template <typename T>
void Desempilhar(PilhaDinamica<T>&pilha){
    if(!verificarPilhaVazia(pilha)){
        Nodo<T> *p;
        p=pilha.Topo;

        pilha.Topo=pilha.Topo->Anterior;
        delete p;
        pilha.cardinalidade--;
    }
    else{
    throw "Pilha vazia";
    }
}

template <typename T>
void mostrarPilha(PilhaDinamica<T> pilha){
    Nodo<T> *p=pilha.Topo;

    while(p!=NULL)
    {
        cout<<p->elemento<<" ";
        p=p->Anterior;
    }
}
#endif // PILHA_H_INCLUDED