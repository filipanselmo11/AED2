#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Lista {
private:
  vector<T> lista;
public:
  Lista() {}
  ~Lista() {
    destroy();
  }
  int getTAM();
  void insere(T elemento);
  void remove(T elemento);
  int busca(T elemento);
  void mostra();
  void destroy();
  T getElemento(int pos);
  void escolhePos(int pos, T elemento);
};


template <class T>
int Lista<T>::getTAM() {
  return lista.size();
}

template <class T>
void Lista<T>::insere(T elemento) {
  lista.push_back(elemento);
}

template <class T>
void Lista<T>::remove(T elemento) {
  int posicao = busca(elemento);
  if(posicao == -1) {
    cout << "Impossivel remover!" << endl;
  } else {
    lista.erase(lista.begin() + posicao);
  }
}

template <class T>
int Lista<T>::busca(T elemento) {
  int posicao = -1;
  for(int i = 0; i < lista.size(); i ++) {
    if(elemento == lista[i]) {
      posicao = i;
      i = lista.size();
    }
  }
  return posicao;
}

template <class T>
void Lista<T>::mostra() {
  for(unsigned int i = 0; i < lista.size(); i ++) {
    cout << lista[i] << " ";
  }
  cout << endl;
}

template <class T>
void Lista<T>::destroy() {
  lista.clear();
  lista.shrink_to_fit();
}


template <class T>
T Lista<T>::getElemento(int pos) {
  return lista[pos];
}

template <class T>
void Lista<T>::escolhePos(int pos, T elemento) {
  lista[pos] = elemento;
}


template <class T>
class No {
private:
  T elemento;
  No *prox;
public:
  No() {  this->prox = NULL;  }
  No(T elemento) { this->elemento = elemento;  this->prox = NULL;  }
  void setProx(No<T> *prox) { this->prox = prox;  }
  No<T>* getProx() { return prox;  }
  void setElemento(T elemento) {  this->elemento = elemento;  }
  T getElemento() {  return elemento; }
};

template <class T>
class Fila {
private:
  No<T> *frente, *tras;
public:
  Fila() { frente = new No<T>();  frente->setProx(NULL);   tras = frente; }
  void enfileira(T elemento);
  void desenfileira(T &elemento);
  void mostraFila();
  bool cheia();
};


/*  ----- Métodos da Fila ----- */

template <class T>
void Fila<T>::enfileira(T elemento) {
  tras->setProx(new No<T>());
  tras = tras->getProx();
  tras->setElemento(elemento);
  tras->setProx(NULL);
}

template <class T>
void Fila<T>::desenfileira(T &elemento) {
  No<T> *aux = frente;
  frente = frente->getProx();
  elemento = frente->getElemento();
  delete aux;
}

template <class T>
void Fila<T>::mostraFila() {
  No<T> *aux;
  aux = frente->getProx();
  if(aux == NULL) {
    cout << "Fila vazia";
  } else {
    while (aux != NULL) {
      cout << aux->getElemento() << " ";
      aux = aux->getProx();
    }
  }
  cout << endl;
}

template <class T>
bool Fila<T>::cheia() {
  No<T> *aux;
  aux = frente->getProx();
  if(aux == NULL) {
    return false;
  } else {
    return true;
  }
}

class Grafo{
private:
  Lista<int> *grafo;
  int ordem, tam;
  void inicializa(int);
  void destroi();
public:
  Grafo(int ordem){
    inicializa(ordem);
  }
  void insereEdge(int, int);
  void mostraGrafo();
  int getOrdem(){
    return ordem;
  }
  int getTamanho(){
    return tam;
  }
  Lista<int> *getGrafo(){
    return grafo;
  }
};

void Grafo::inicializa(int ordem){
  /*if(this->n == ){
    destroi();
  }*/
  this->ordem = ordem;
  this-> tam = 0;
  grafo = new Lista<int>[ordem + 1];
}

void Grafo::destroi(){
  for(int i = 0; i < this->ordem; i++){
        grafo[i].destroy();
  }
  delete [] grafo;
  ordem = tam = 0;
}

void Grafo::insereEdge(int v1, int v2){
  int x = v2;
  grafo[v1].insere(x);
  x = v1;
  grafo[v2].insere(x);
  /*grafo[v1].insere(v2);
  grafo[v2].insere(v1);
  T x = v;
	adj[u].insere(x);
	x = u;
	adj[v].insere(x);
	m++;*/
  tam++;
}

void Grafo::mostraGrafo(){
  for(int i = 1; i < ordem; i++){
    cout << "G" << "[" << i << "] = ";
    grafo[i].mostra();
  }
  cout << endl;
}


int main(){
	/*Lista<int> l;
	l.insere(1);
	l.insere(12);
	l.insere(133);
	l.insere(1444);
	l.mostra();
	//l.getElemento(3);
	//l.mostra();
	//l.escolhePos(1,12);*/
	/*Fila<int> f;
	f.enfileira(1);
	f.enfileira(2);
	f.enfileira(3);
  f.mostraFila();*/
  //Grafo<int> g(4);
  int n;
  cin >> n;
  Grafo g(n);
  g.insereEdge(1,2);
  g.insereEdge(2,3);
  g.insereEdge(3,4);
  g.insereEdge(2,2);
  g.insereEdge(5,3);
  g.mostraGrafo();
	return 0;
	

}

