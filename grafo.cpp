#include <iostream>

using namespace std;

typedef int Vertex;
const int Branco = 0;
const int Cinza = 1;
const int Preto = 2;
int tempo;
//int d,f;
//int cor;

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

template <class T>
class Lista{
private:
	No<T> *prim;
	No<T> *ult;
	bool vazia();
	No<T> *pred(No<T>*);
public:
	Lista(){
		prim = new No<T>;
		prim->setProx(NULL);
		ult = prim;
	}
	void insere(T);
	void mostra();
	void remove(T, No<T>*);
	No<T> *busca(T);
	void destroi();
};

template <class T>
bool Lista<T>::vazia(){
	return prim == ult;
}

template <class T>
No<T>*Lista<T>::pred(No<T> *r){
	No<T> *p = prim->getProx();
	while(p->getProx() != r){
		p = p->getProx();
	}
	return p;
}

template <class T>
void Lista<T>::insere(T it){
	ult->setProx(new No<T>);
	ult = ult->getProx();
	ult->setProx(NULL);
	ult->setIt(it);
}

template <class T>
void Lista<T>::mostra(){
	//cout << "mostra!!" << endl;
	No<T> *nav = prim->getProx();
	while(nav != NULL){
		cout << nav->getIt() << " ";
		nav = nav->getProx();
	}
	cout << endl;
}

template <class T>
No<T>*Lista<T>::busca(T it){
	No<T> *p = prim->getProx();
	while(p != NULL && p->getIt() != it){
		p = p->getProx();
	}
	return p;
}

template <class T>
void Lista<T>::remove(T it, No<T> *r){
	if(vazia() || r == NULL || r == prim){
		cout << "Impossivel remover" << endl;
	}
	else{
		it = r->getIt();
		No<T> *p = pred(r);
		p->setProx(r->getProx());
		if(p->getProx() == NULL){
			ult = p;
		}
	}
	delete r;
}

template <class T>
void Lista<T>::destroi(){
	No<T> *nav = prim->getProx();
	while(nav != NULL){
		delete(nav);
	}
	nav = nav->getProx();
}
/*
template <class T>
class Pilha{
private:
	No<T> *topo;
	No<T> *fundo;
public:
	Pilha(){
		fundo = new No<T>;
		fundo->setProx(NULL);
		topo = fundo;
	}
	void empilha(T);
	void mostra();
	void desempilha(T);
};

template <class T>
void Pilha<T>::empilha(T it){
	No<T> *aux = new No<T>;
	topo->setIt(it);
	aux->setProx(topo);
	topo = aux;
}

template <class T>
void Pilha<T>::mostra(){

}

template <class T>
No<T>*Pilha<T>::desempilha(T it){
	No<T> *aux = topo;
	topo = topo->getProx();
	it = topo->getIt();
	delete aux;
	return it;
}*/

template <class T>
class Grafo{
private:
	Lista<Vertex> *adj;
	//Pilha<>
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
	int getM(){
		return m;
	}
	Grafo(int);
	void inicializa(int);
	void insertEdge(Vertex, Vertex);
	void print();
};


template <class T>
void Grafo<T>::destroy(){
	for(int i = 0; i <= n; i++){
		adj[i].destroi();
	}
	delete adj;
	n = m = 0;
}

template <class T>
Grafo<T>::Grafo(int n){
	inicializa(n);
}

template <class T>
void Grafo<T>::inicializa(int n){
	/*if(this->n != 0){
		destroy();
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
	for(int i = 1; i < n; i++){
		cout << "v[" << i << "]= ";
		adj[i].mostra();
	}
}
/*
void testaGrafo(Grafo<int> &g){
	g.insertEdge(1,2);
	g.insertEdge(2,3);
	g.insertEdge(3,4);
	g.insertEdge(4,5);
	g.print();
}*/

/*
template <class T>
void DFS(Grafo &g){
	T *pred;
	No<T> *p = g.getAdj()[u->Vertex].prim->getProx();
	while(p != NULL){
		u->cor = Branco;
		pred = NULL;
	}
	tempo = 0;
	while(){

	}
}*//*
template <class T>
void dfsVisita(Grafo<int> &g, T *u){
	tempo = tempo + 1;
	u->setD(tempo);
	u->setCor(Cinza);
	T *v;
	No<T> *p = g.getAdj()[u];
	while(p != NULL){
		if(v->getCor() == Branco){
			v->setPred(u);
			dfsVisita(g,v);
		}
		p = p->getProx();
	}
	u->setCor(Preto);
	tempo = tempo + 1;
	u->setF(tempo);
	//for()
}

template <class T>
void DFS(Grafo<int> &g){
	T *u;
	No<T> *p = g.getAdj()[u];
	while(p != NULL){
		u->setCor(Branco);
		u->setPred(NULL);
		p = p->getProx();
	}
	tempo = 0;
	while(p != NULL){
		if(u->getCor() == Branco){
			dfsVisita(g,u);
		}
	}
}*/	
int main(){
	/*Lista<int> l;
	l.insere(1);
	l.insere(2);
	l.insere(3);
	l.insere(4);
	l.insere(5);
	l.mostra();
	
	No<int> *px = l.busca(5);
	if(px == NULL){
		cout << "Numero nao encotrado" << endl;
	}
	else{
		cout << px->getIt() << endl;
	}
	l.remove(6,px);
	l.mostra();*/
	int n,m;
	cout << "ordem: ";
	cin >> n;
	Grafo<int> g(n);
	g.insertEdge(1,2);
	g.insertEdge(2,3);
	g.insertEdge(3,4);
	g.print();
	//dfsVisita(g,)
	//testaGrafo(g);
	DFS(g);
	return 0;
}