
#include <iostream> 
#include <cstdlib> 
#include <vector> 
#include <climits>

using namespace std;

const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;

template <class T>
class No { 
private:
  T element; 
  No *prox; 
public:
  No() {  this->prox = NULL;  } 
  No(T element) { this->element = element;  this->prox = NULL;  } 
  void setProx(No<T> *prox) { this->prox = prox;  } 
  No<T>* getProx() { return prox;  }
  void setElement(T element) {  this->element = element;  } 
  T getElement() {  return element; }
};

template <class T>
class Fila { 
private:
  Node<T> *frente, *tras; 
public:
  Queue() { frente = new No<T>();  frente->setProx(NULL);   tras = frente; } 
  void enfileira(T element); 
  void desenfileira(T &element);
  void mostraFila(); 
  bool cheia(); 
};


template <class T>
void Fila<T>::enfileira(T element) {
  tras->setProx(new No<T>());
  tras = tras->getProx();
  tras->setElement(element);
  tras->setProx(NULL);
}

template <class T>
void Fila<T>::desenfileira(T &element) {
  No<T> *aux = frente;
  frente = frente->getProx();
  element = frente->getElement();
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
      cout << aux->getElement() << " ";
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


template <class T>
class Lista { 
private:
  No<T> *prim, *ult;
  int tam;
public:
  Lista() { 
    prim = new No<T>();
    prim->setProx(NULL);
    ult = prim;
    tam = 0;
  }
  ~List() {} 
  int getTam(); 
  void insere(T element); 
  No<T>* busca(T element);
  void mostraLista(); 
  T getElement(int position);
};


template <class T>
int Lista<T>::getTam() {
  return tam;
}

template <class T>
void Lista<T>::insere(T element) {
  ult->setProx(new No<T>());
  ult = ult->getProx();
  ult->setProx(NULL);
  ult->setElement(element);
  tam ++;
}

template <class T>
No<T>* Lista<T>::busca(T element) {
  No<T> *aux = prim->getProx();
  while(aux != NULL && aux->getElement() != element) {
    aux = aux->getProx();
  }
  return aux;
}

template <class T>
void Lista<T>::mostraLista() {
  No<T> *aux = prim->getProx();
  while (aux != NULL) {
    cout << aux->getElement() << " ";
    aux = aux->getProx();
  }
  cout << endl;
}

template <class T>
T Lista<T>::getElement(int position) {
  No<T> *aux = prim->getProx();
  for(unsigned int i = 0; (int) i < tam; i ++) {
    if((int) i == position) {
      break;
    }
    aux = aux->getProx();
  }
  return aux->getElement();
}


class Grafo {
private:
  Lista<int> *grafo;
  int n, m;
  void inicializa(int n);
public:
  Grafo(int n) { 
    inicializa(n);
  }
  void insereEdge(int vertex1, int vertex2);
  void mostraGrafo();
  void setN(int n);
  int getN(); 
  void setM(int m);
  int getM();
  Lista<int> getGrafo(int position);
  bool repeticao(int position, int element);
};


void Grafo::inicializa(int n) {
    this->n = n;
    this->m = 0;
    grafo = new Lista<int>[n+1];
}
  
void Grafo::insereEdge(int vertex1, int vertex2) {
    if(repeticao(vertex1, vertex2)) {
      grafo[vertex1].insere(vertex2);
      m++;
    }
}
  
void Grafo::mostraGrafo() {
    for(unsigned int i = 1; (int) i <= this->n; i ++) {
      cout << "G[" << i <<"] = ";
      grafo[i].mostraLista();
    }
    cout << endl;
}
  
void Grafo::setN(int n) {
    this->n = n;
}
  
int Grafo::getN() {
    return n;
}
  
void Grafo::setM(int m) {
    this->m = m;
}
  
int Grafo::getM() {
    return m;
}
  
Lista<int> Grafo::getGrafo(int position) {
    return grafo[position];
}
  
bool Grafo::repeticao(int position, int element) {
    if(grafo[position].busca(element)) {
      return false;
    } else {
      return true;
    }
}

class AlgoritmoBFS {
private:
  int *vertex, *predecessor, *cores, *distancias, distancia, n;
  void inicia();
public:
  AlgoritmoBFS(int n);
  void BFS(Grafo *grafo, int vertexInicial);
  void mostraResultado();
  int retornaDistancia(int vertex);
  int retornaPredecessor(int vertex);
};

void AlgoritmoBFS::inicia() {
    for(unsigned int i = 0; (int) i <= n; i ++) {
      vertex[i] = 0;
      predecessor[i] = 0;
      cores[i] = 0;
      distancias[i] = 0;
    }
}
  
AlgoritmoBFS::AlgoritmoBFS(int n) {
    this->n = n;
    vertex = new int[n+1];
    predecessor = new int[n+1];
    cores = new int[n+1];
    distancias = new int[n+1];
    this->distancia = 0;
    inicia();
}
  
void AlgoritmoBFS::BFS(Grafo *grafo, int vertexInicial) {
    for(unsigned int i = 0; (int) i <= grafo->getN(); i ++) {
      vertex[i] = i;
      cores[i] = BRANCO;
      distancias[i] = INT_MAX;
      predecessor[i] = 0;
    }
    cores[vertexInicial] = CINZA;
    distancias[vertexInicial] = 0;
    predecessor[vertexInicial] = -1;
    Fila<int> fila;
    fila.enfileira(vertexInicial);
    while(fila.full()) {
      int vertexAux;
      fila.desenfileira(vertexAux);
      Lista<int> aux = grafo->getGrafo(vertexAux);
      for(unsigned int i = 0; (int) i < aux.getTam(); i ++) {
        if(cores[aux.getElement(i)] == BRANCO) {
          cores[aux.getElement(i)] = CINZA;
          distancias[aux.getElement(i)] = (distancias[vertexAux] + 1);
          predecessor[aux.getElement(i)] = vertexAux;
          fila.enfileira(aux.getElement(i));
        }
      }
      distancia++;
      cres[vertexAux] = PRETO;
    }
}
  
void AlgoritmoBFS::mostraResultado() {
    cout << "Vertex - Predecessor - Distances " << endl;
    for(unsigned int i = 1; (int) i <= n; i ++) {
      cout << vertex[i] << " () " << predecessor[i] << " () " << distancias[i] << endl;
    }
}
  
int AlgoritmoBFS::retornaDistancia(int vertex) {
    return distancias[vertex];
}
  
int AlgoritmoBFS::retrnaPredecessor(int vertex) {
    return predecessor[vertex];
}
  
