#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Lista{
private:
    vector<T> lista;
public:
    Lista(){}
    ~Lista(){
        destroy();
    }
    void insere(T elem);
    void mostra();
    void destroy();
};


template <class T>
void Lista<T>::insere(T elem) {
  lista.push_back(elem);
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



class Grafo{
private:
  Lista<int> *adj;
  int n,m;
  void inicializa(int n);
  void destroi();
public:
  Grafo(int n){
    inicializa(n);
  }
  void insereAresta(int vertice1, int vertice2);
  void mostra();
  void setN(int n);
  int getN();
  void setM(int m);
  int getM();
};

void Grafo::inicializa(int n){
  /*if(this->n != 0){
    destroi();
  }*/
  this->n = n;
  adj = new Lista<int>[n+1];
}

void Grafo::setN(int n){
  this->n = n;
}

int Grafo::getN(){
  return n;
}

void Grafo::setM(int m){
  this->m = m;
}

int Grafo::getM(){
  return m;
}

void Grafo::insereAresta(int vertice1, int vertice2){
  adj[vertice1].insere(vertice2);
  adj[vertice2].insere(vertice1);
  m++;
}

void Grafo::mostra(){
  for(int i = 1; i < this->getN(); i ++) {
       cout << "G[" << i <<"] = ";
       adj[i].mostra();
      }
      cout << endl;
}


void Grafo::destroi() {
  for(int i = 0; i <= this->n; i ++ ) {
    adj[i].destroy();
  }
  delete[] adj;
  n = m = 0;
}


int main(){
  int n,m;
  cout << "Ordem:  ";
  cin >> n;
  Grafo g(n);
  g.insereAresta(1,2);
  g.insereAresta(2,3);
  g.insereAresta(3,4);
  g.mostra();
  return 0;

}
