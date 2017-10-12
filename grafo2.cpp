#include <iostream>
#include <vector>

using namespace std;

typedef int Vertex;
const int Branco = 0;
const int Cinza = 1;
const int Preto = 2;
int tempo;


template <class T>
class No{
private:
	T it;
	No *prox;
public:
	No(){
		this->prox = NULL;
	}
	No(T it){
		this->it = it;
		this->prox = NULL;
	}

	void setIt(T it){
		this->it = it;
	}

	T getIt(){
		return it;
	}

	void setProx(No *prox){
		this->prox = prox;
	}

	No *getProx(){
		return prox;
	}
};


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
    /*int getTAM(){
        return tam;
    }
    int buscaV(Vertex);*/
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
/*
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

}*/


template <class T>
class Fila{
private:
    No<T> *tras, *frente;
public:
    Fila(){
        frente = new No<T>;
        frente->setProx(NULL);
        tras = frente;
    }

    No<T> *getTras(){
        return tras;
    }

    No<T> *getFrente(){
        return frente;
    }
    void enfileira(T);
    void mostra();
    void desenfileira(T&);
};

template <class T>
void Fila<T>::enfileira(T it){
    tras->setProx(new No<T>);
    tras = tras->getProx();
    tras->setIt(it);
    tras->setProx(NULL);
}

template <class T>
void Fila<T>::mostra(){
    No<T> *nav = getFrente()->getProx();
    cout << "Frente -> ";
    while(nav != NULL){
        cout << nav->getIt() <<  " ";
        nav = nav->getProx();
    }
    cout << " <- Tras" << endl;
}

template <class T>
void Fila<T>::desenfileira(T &it){
	No<T> *aux = frente;
	frente = frente->getProx();
	it = frente->getIt();
	delete aux;
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

class BFS{
private:
    int *cor;
    int *d;
    int *pred;
public:
    BSF();
    void algoritmoBFS(Grafo<int>&, Vertex);
};

BFS()::BFS(){ }

void BFS::algoritmoBFS(Grafo<int> &g, Vertex s){
    for(Vertex u = 1; u)
}

int main(){
    /*Fila<int> f;
    f.enfileira(1);
    f.enfileira(2);
	f.enfileira(3);
	f.enfileira(4);
	f.enfileira(5);
	f.mostra();
	f.desenfileira(2);
    f.mostra();*/
    int n;
    cout << "Ordem: ";
    cin >> n;
    Grafo<int> g(n);
    g.insereAresta(1,2);
    g.insereAresta(2,3);
    g.insereAresta(3,4);
    g.print();
    return 0;
}
