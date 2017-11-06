#include <iostream>
#include <climits>

using namespace std;

template <class T>
class No{
private:
    T item;
    No *prox;
public:
    No(){
        this->prox = NULL;
    }
    No(T item){
        this->item = item;
        this->prox = NULL;
    }
    void setItem(T item){
        this->item = item;
    }
    T getItem(){
        return item;
    }
    void setProx(No *prox){
        this->prox = prox;
    }
    No *getProx(){
        return prox;
    }
};

template <class T>
class Lista{
private:
    int taml;
    No<T> *prim, *ult;
    bool vazia();
    No<T> *pred(No<T> *r);
public:
    Lista(){
        taml = 0;
        prim = new No<T>();
        prim->setProx(NULL);
        ult = prim;
    }
    int getTam();
    void insere(T item);
    void mostraLista();
    No<T> *busca(T item);
    void remove(No<T> *r, T &item);
};
template <class T>
bool Lista<T>::vazia(){
    return prim == ult;
}

template <class T>
int Lista<T>::getTam(){
    return taml;
}

template <class T>
No<T>*Lista<T>::pred(No<T> *r){
    No<T> *aux = prim->getProx();
    while(aux->getProx() != r){
        aux = aux->getProx();
    }
    return aux;
}

template <class T>
void Lista<T>::insere(T item){
    ult ->setProx(new No<T>());
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setItem(item);
    taml++;
}

template <class T>
void Lista<T>::mostraLista(){
    No<T> *aux = prim->getProx();
    while(aux != NULL){
        cout << aux->getItem() << " ";
        aux = aux->getProx();
    }
    cout << endl;
}

template <class T>
No<T>*Lista<T>::busca(T item){
    No<T> *aux = prim->getProx();
    while(aux != NULL && aux->getItem() != item){
        aux = aux->getProx();
    }
    return aux;
}

template <class T>
void Lista<T>::remove(No<T> *r, T &item){
    if(vazia() || r == NULL || r == prim){
        cout << "Impossível remoção" << endl;
    }
    else{
        item = r->getItem();
        No<T> *aux = pred(r);
        if(aux->getProx() == NULL) ult = aux;
        delete r;
    }
}

class Grafo{
private:
    int ordem, tamanho;
    Lista<int> *grafo;
    void inicializa(int n);
public:
    Grafo(int n){
        inicializa(n);
    }
    void setOrdem(int ordem);
    int getOrdem();
    void setTamanho(int tamanho);
    int getTamanho();
    void insereEdge(int vertice1, int vertice2);
    void mostraGrafo();
};

void Grafo::inicializa(int ordem){
    this->ordem = ordem;
    this-> tamanho = 0;
    grafo = new Lista<int>[ordem + 1];
}

void Grafo::setOrdem(int ordem){
    this->ordem = ordem;
}

int Grafo::getOrdem(){
    return ordem;
}

void Grafo::setTamanho(int tamanho){
    this->tamanho = tamanho;
}

int Grafo::getTamanho(){
    return tamanho;
}

void Grafo::insereEdge(int vertice1, int vertice2){
    grafo[vertice1].insere(vertice2);
    grafo[vertice2].insere(vertice1);
    tamanho++;
}

void Grafo::mostraGrafo(){
    for(int i = 1; i <= ordem; i++){
        cout << "G[" << i << "] = ";
        grafo[i].mostraLista();
    }
    cout << endl;
}

class AlgoritmoMST{
private:
    int ordem;
    int *chave;
    int *pai;
    int *pesos;
    void inicia();

public:
    AlgoritmoMST(int ordem);
    MST(Grafo *g, int *pesos, int verticeInicial);
};

void AlgoritmoMST::inicia(){
    for(int i = 0; i <= ordem; i++){
        chave[i] = 0;
        pai[i] = 0;
        pesos[i] = 0;
    }
}

AlgoritmoMST::AlgoritmoMST(int ordem){
    this->ordem = ordem;
    chave = new int[ordem + 1];
    pai = new int[ordem + 1];
    pesos = new int[ordem + 1];
    inicia();
}

int main(){
    /*Lista<int> l;
    l.insere(1);
    l.insere(2);
    l.insere(3);
    l.insere(4);
    l.mostraLista();*/
    Grafo g(4);
    g.insereEdge(1,2);
    g.insereEdge(2,3);
    g.insereEdge(4,2);
    g.mostraGrafo();
    return 0;
}