#include<iostream>
#include<vector>

typedef int Vertex;
const int Branco = 0;
const int Cinza = 1;
const int Preto = 2;
int tempo;

using namespace std;

template<class T>
class Lista{
private:
    vector<T> lista;
    int tam = 0;
public:
    Lista(){
    }
    ~Lista(){
        destroi();
    }
    void insere(T);
    void mostra();
    void destroi();
    int getTAM(){
        return tam;
    }
    int buscaV(Vertex);
};

template <class T>
void Lista<T>::insere(T it){
    lista.push_back(it);
    tam++;
}

template <class T>
void Lista<T>::mostra(){
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}

template <class T>
void Lista<T>::destroi(){
    lista.clear();
    lista.shrink_to_fit();
}

template <class T>
int Lista<T>::buscaV(Vertex x){
    int p;
    int c = 1;
    Vertex i;
    while(p != 0){
        if(c == x){
            i = p;
        }
        c++;
        p++;
    }

}

template <class T>
class Grafo{
private:
    Lista<Vertex> *adj;
    int n,m;
    void destroy();
public:
    Grafo(int);
    void inicializa(int);
    void insereAresta(Vertex,Vertex);
    void print();

    int getN(){
        return n;
    }

    int getM(){
        return m;
    }

    Lista<Vertex> *getAdj(){
        return adj;
    }
};

template <class T>
Grafo<T>::Grafo(int n){
    inicializa(n);
}

template <class T>
void Grafo<T>::inicializa(int n){
    if(this->n == 0){
        destroy();
    }
    this->n = n;
    adj = new Lista<Vertex>[n + 1];
}

template <class T>
void Grafo<T>::insereAresta(Vertex u, Vertex v){
    Vertex x = v;
    adj[u].insere(x);
    x = u;
    adj[v].insere(x);
    m++;
}

template <class T>
void Grafo<T>::print(){
    for(int i = 1; i <= getN(); i++){
        cout << "v[" << i <<"]= ";
        adj[i].mostra();
    }
}

template <class T>
void Grafo<T>::destroy(){
    for(int i = 0; i <= n; i++){
        adj[i].destroi();
    }
    delete adj;
    //getN() = getM() = 0;
    n = m = 0;
}

class DFS{
private:
    int *cor;
    int *d;
    int *f;
    int *pred;
    void dfsVisita(Grafo<Vertex>&, Vertex);
public:
    DFS();
    void dfsPrincipal(Grafo<Vertex>&);
};

DFS::DFS(){ }

void DFS::dfsVisita(Grafo<Vertex> &g, Vertex u){
    //tempo = tempo + 1;
    tempo += 1;
    d[u] = tempo;
    cor[u] = Cinza;
    Lista<Vertex> adj = g.getAdj()[u];
    for(int i = 1; i <= adj.getTAM(); i++){
        Vertex v;
        if(cor[v] == Branco){
            pred[v] = u;
            dfsVisita(g,v);
        }
    }
    cor[u] = Preto;
    //tempo = tempo + 1;
    tempo += 1;
    f[u] = tempo;
}

void DFS::dfsPrincipal(Grafo<Vertex> &g){
    Vertex v;
    Lista<Vertex> adj = g.getAdj()[v];
    for(int u = 1; u <= adj.getTAM(); u++){
        cor[u] = Branco;
        pred[u] = 0;
    }
    tempo = 0;
    for(int u = 1; u <= adj.getTAM(); u++){
        if(cor[u] == Branco){
            dfsVisita(g,u);
        }
    }
}


int main(){
    int n,m;
    cout << "Ordem: ";
    cin >> n;
    Grafo<Vertex> g(n);
    g.insereAresta(1,2);
    g.insereAresta(1,4);
    g.insereAresta(1,5);
    g.insereAresta(2,3);
    g.insereAresta(2,4);
    g.insereAresta(3,4);
    g.insereAresta(4,5);
    g.print();
    DFS dfs;
    //dfs.dfsVisita(g,1);
    dfs.dfsPrincipal(g);
    return 0;
}