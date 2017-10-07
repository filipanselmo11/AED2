#include <iostream>

using namespace std;

typedef int Vertex;
const int Branco = 0;
const int Cinza = 1;
const int Preto= 2;
int tempo;

template <class T>
class No{
private:
    T it;
    No *prox;
public:
    No(T it){
        this->it = it;
        this->prox = NULL;
    }
    No(){
       this->prox = NULL;
    }
    
    T getIt(){
        return it;
    }

    void setIt(T it){
        this->it = it;
    }

    No *getProx(){
        return prox;
    }

    void setProx(No *prox){
        this->prox = prox;
    }
};

template <class T>
class Lista{
private:
    No<T> *prim, *ult;
public:
    No<T> *getPrim(){
        return prim;
    }
    
    No<T> *getUlt(){
        return ult;
    }

    Lista(){
        prim = new No<T>;
        prim->setProx(NULL);
        ult = prim;
    }
    void insere(T);
    void mostra();
    void destroi();
};

template <class T>
void Lista<T>::insere(T it){
    ult->setProx(new No<T>);
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setIt(it);
}

template <class T>
void Lista<T>::mostra(){
    No<T> *nav = getPrim()->getProx();
    while(nav != NULL){
        cout << nav->getIt() << " ";
        nav = nav->getProx();
    }
}

template <class T>
void Lista<T>::destroi(){
    No<T> *nav = getPrim()->getProx();
    while(nav != NULL){
        delete(nav);
    }
    nav = nav->getProx();
}


template <class T>
class Grafo{
private:
    Lista<Vertex> *adj;
    int n,m;
    void destroy();
public:
    Lista<Vertex> *getAdj(){
        return adj;
    }

    void setAdj(Lista<Vertex> *adj){
        this->adj = adj;
    }

    int getN(){
        return n;
    }

    void setN(int n){
        this->n = n;
    }

    int getM(){
        return m;
    }

    void setM(int m){
        this->m = m;
    }

    Grafo(int);
    void inicializa(int);
    void insertEdge(Vertex,Vertex);
    void print();
};

template <class T>
Grafo<T>::Grafo(int n){
    inicializa(n);
}

template <class T>
void Grafo<T>::inicializa(int n){
    /*if(this->n == 0){

    }*/
    this->n = n;
    adj = new Lista<Vertex>[n + 1];
}

template <class T>
void Grafo<T>::insertEdge(Vertex u, Vertex v){
    T x = v;
    adj[u].insere(x);
    x = u;
    adj[v].insere(x);
    m++;
}

template <class T>
void Grafo<T>::print(){
    for(int i = 1; i <= getN(); i++){
        cout << "v[" << i <<"] = ";
        adj[i].mostra();
        cout << endl;
    }
    cout << endl;
}

template <class T>
void Grafo<T>::destroy(){
    for(int i = 0; i <= getN(); i++){
        adj[i].destroi();
    }
    delete adj;
    getN() = getM() = 0;
}

class DFS{
private:
    //Grafo<Vertex> g;
    int *cor;
    int *d;//Vetor dinâmico de d//
    int *f;//vetor dinâmico de f//
    int *pred;
public:
    DFS();
    void dfsVisita(Grafo<Vertex>&, Vertex);
    /*DFS(int *cor, int *d, int *f, int *pred, Grafo<Vertex> g){
        this->cor = cor;
        this->d = d;
        this->f = f;
        this->pred = pred;
        this->g = g;
    }*/
    //void setCor(int cor){
        //this->cor = cor;
    //}
    
    int *getCor(){
        return cor;
    }

    //void setD(int d){
        //this->d = d;
    //}

    int *getD(){
        return d;
    }

    //void setF(int f){
        //this->f = f;
    //}

    int *getF(){
        return f;
    }
    void dfsPrincipal(Grafo<Vertex> &);

};
DFS::DFS(){ }

void DFS::dfsVisita(Grafo<Vertex> &g, Vertex u){
    tempo = tempo + 1;
    d[u] = tempo;
    cor[u] = Cinza;/*
    for(Vertex v = 1; v <= g.;v++){
        if(cor[v] == Branco){
            pred[v] = u;
            dfsVisita(g,v);
        }
    }*/
    No<int> *p = g.getAdj()[u].getPrim()->getProx();
    Vertex v;
    while(p != NULL){
        if(cor[v] == Branco){
            pred[v] = u;
            dfsVisita(g,v);
        }
        p = p->getProx();
    }
    cor[u] = Preto;
    tempo = tempo + 1;
    f[u] = tempo;
}

void DFS::dfsPrincipal(Grafo<Vertex> &g){
    //No<int> *p = g.getAdj()[u]
    for(Vertex u = 1; u <= g.getN(); u++){
        cor[u] = Branco;
        pred[u] = 0;
    }
    tempo = 0;
    for(Vertex u = 1; u <= g.getN(); u++){
        if(cor[u] == Branco){
            dfsVisita(g,u);
        }
    }
}


int main(){
    int n,m;
    cout << "Ordem: ";
    cin >> n;
    Grafo<int> g(n);
    g.insertEdge(1,2);
    g.insertEdge(2,3);
    g.insertEdge(3,4);
    g.print();
    DFS d;
    //d.dfsVisita(g,1);
    d.dfsPrincipal(g);
    return 0;
}
