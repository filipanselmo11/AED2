#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef int Vertex;
typedef int Weight;

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

template <class T>
class Grafo{
private:
    int **mat;
    int n,m;
public:
    Grafo(int n){
        this-> n = n;
        this-> m = 0;
        mat = new int*[n];
        for(int i = 0; i < n; i++){
            mat[i] = new int[n];
        }
        //inicializa();
    }

    int **getMat(){
        return mat;
    }

    int getN(){
        return n;
    }

    int getM(){
        return m;
    }

    void inicializa();
    void insereAresta(Vertex, Vertex, Weight);
    void print();
};

template <class T>
void Grafo<T>::inicializa(){
    for(int i = 0; i < n; i++){
        for(int j = 0; i < n; j++){
            mat[i][j] = 0;
        }
    }
}

template <class T>
void Grafo<T>::insereAresta(Vertex u, Vertex v, Weight w){
    mat[u][v] = w;
    mat[v][u] = w;
    m++;
}

template <class T>
void Grafo<T>::print() {
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

class MST{
private:
  int inicial;//Vértice inicial//
  int *vertice;//Vetor de vértices//
  //Fila<int> f;
  int peso;
  int *pred;//Vetor de predecessor//
public:
  MST(){

  }
  void algoritmoMST(Grafo g, int inicial, int peso);
};

void MST::algoritmoMST(Grafo g, int inicial, int peso){
  for(int i = 0; i <= n; i++){
      vertice[i] = INT_MAX;
      pred[i] = 0;
  }
  inicial = 0;
  Fila<int> f;
  while(){
    
  }

}
*/

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
 /* int n;
  cin >> n;
  Grafo<int> g(n);
  g.insereAresta(1,1,2);
  g.insereAresta(2,1,3); 
  g.insereAresta(1,3,4);
  g.print();*/

	return 0;
	
}

