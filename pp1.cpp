#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

//typedef vector<vector<pair<int,int>>> Movements;
typedef vector<vector<par<int,int>>> Movimentos;
//typedef vector<pair<int,int>> Horses;
typedef vector<par<int,int>> Cavalos;
//typedef pair<int,int> Pieces;
typedef par<int,int> Pecas;

//const int board_size = 9; // Considerando que utilizamos as posições de 1 até 8;
const int tam_tabuleiro = 9;

//const int NUMBEROFHORSES = 4;
const int NUMCAVALOS = 4;
//const int MAXGRAPHSIZE = 64;
const int TAMMAXGRAFO = 64;
const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
//const int HORSE = 65;
const int CAVALO = 65;
//const int KING = 66;
const int REI = 66;
//const vector<char> dictionaryChar = {'?', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
const vecotr<char> dicionarioChar = {'?','a','b','c','d','e','f','g','h'};
//const vector<char> dictionaryInt = {'?', '1', '2', '3', '4', '5', '6', '7', '8'};
const vector<char> dicionarioInt = {'?','1','2','3','4','5','6','7','8'};
/*template <class T>
class Node {
private:
  T element;
  Node *prox;
public:
  Node() {  this->prox = NULL;  }
  Node(T element) { this->element = element;  this->prox = NULL;  }
  void setProx(Node<T> *prox) { this->prox = prox;  }
  Node<T>* getProx() { return prox;  }
  void setElement(T element) {  this->element = element;  }
  T getElement() {  return element; }
};*/
template <class T>
class No{
private:
    T elem;
    No *prox;
public:
    No() {this->prox = NULL;}
    No(T elem) {this->elem = elem; this->prox = NULL}
    void setProx(No<T> *prox) {this->prox = prox; }
    No<T> *getProx(){
        return prox;
    }
    void setElem(T elem) {this->elem = elem; }
    T getElem() {return elem; }
};
/*
template <class T>
class Queue {
private:
  Node<T> *front, *back;
public:
  Queue() { front = new Node<T>();  front->setProx(NULL);   back = front; }
  void toQueue(T element);
  void notToQueue(T &element);
  void showQueue();
  bool full();
};*/
template <class T>
class Fila{
private:
    No<T> *tras, *frente;
public:
    Fila() {frente = new No<T>; frente->setProx(NULL); tras = frente; }
    void enfileira(T elem);
    void desenfileira(T &elem);
    void mostraFila();
    bool cheia();
};

/*  ----- Métodos da Fila ----- */

template <class T>
void Fila<T>::enfileira(T elem) {
  tras->setProx(new No<T>);
  tras = tras->getProx();
  tras->setElem(elem);
  tras->setProx(NULL);
}

template <class T>
void Fila<T>::desenfileira(T &elem) {
  Node<T> *aux = frente;
  frente = frente->getProx();
  elem = frente->getElement();
  delete aux;
}

template <class T>
void Fila<T>::mostraFila() {
  Node<T> *aux;
  aux = frente->getProx();
  if(aux == NULL) {
    cout << "Fila vazia";
  } else {
    while (aux != NULL) {
      cout << aux->getElem() << " ";
      aux = aux->getProx();
    }
  }
  cout << endl;
}

template <class T>
bool Fila<T>::cheia() {
  Node<T> *aux;
  aux = frente->getProx();
  if(aux == NULL) {
    return false;
  } else {
    return true;
  }
}
/*
template <class T>
class List {
private:
  vector<T> list;
public:
  List() {}
  ~List() {
    destroy();
  }
  int getSize();
  void insert(T element);
  void remove(T element);
  int search(T element);
  void show();
  void destroy();
  T getElement(int position);
  void changePosition(int position, T element);
};*/
template <class T>
class Lista{
private:
    vector<T> lista;
public:
    Lista(){}
    ~Lista(){
        destroy();
    }
    int getTam();
    void insere(T elem);
    void remove(T elem);
    int busca(T elem);
    void mostra();
    void destroy();
    T getElem(int pos);
    void escolhePosicao(int pos, T elem);
};
/*  ----- Métodos da Lista -----  */
template <class T>
int Lista<T>::getTam() {
  return lista.size();
}

template <class T>
void Lista<T>::insere(T elem) {
  lista.push_back(elem);
}

template <class T>
void Lista<T>::remove(T elem) {
  int posicao = busca(elem);
  if(posicao == -1) {
    cout << "Impossível remover!" << endl;
  } else {
    lista.erase(lista.begin() + posicao);
  }
}

template <class T>
int Lista<T>::busca(T elem) {
  int posicao = -1;
  for(int i = 0; i < lista.size(); i ++) {
    if(elem == lista[i]) {
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
T Lista<T>::getElem(int pos) {
  return lista[pos];
}

template <class T>
void Lista<T>::escolhePosicao(int pos, T elem) {
  lista[pos] = elem;
}
/*
class Graph {
private:
  List<int> *graph;
  int order, size;
  void initialize(int order);
  void destroy();
public:
  Graph(int order) {
    initialize(order);
  }
  void insertEdge(int vertex1, int vertex2);
  void show();
  void setOrder(int order);
  int getOrder();
  void setSize(int size);
  int getSize();
  List<int> getGraph(int position);
  bool repetition(int position, int element);
};*/
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
  Lista<int> getAdj(int pos);
  bool repeticao(int pos, int elem);
};


/*  ----- Métodos do Grafo -----  */

void Grafo::inicializa(int n) {
  // if(this->n != 0) {
  //   destroi();
  // }
  this->n = n;
  this->m = 0;
  adj = new Lista<int>[n + 1];
}

void Grafo::destroi() {
  for(int i = 0; i <= this->n; i ++ ) {
    adj[i].destroy();
  }
  delete[] adj;
  n = m = 0;
}

void Grafo::insereAresta(int vertice1, int vertice2) {
    if(!(repeticao(vertice1, vertice2))) {
        grafo[vertice1].insere(vertice2);
        grafo[vertice2].insere(vertice1);
        m++;
    }
}

void Grafo::mostra() {
  for(int i = 1; i <= this->n; i ++) {
       cout << "G[" << i <<"] = ";
       adj[i].mostra();
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
    
Lista<int> Grafo::getAdj(int pos) {
      return adj[pos];
}
    
bool Grafo::repeticao(int pos, int elem) {
  for(int i = 1; i <= adj[pos].getTam(); i ++) {
      if(adj[pos].getElem(i) == elem) {
          return true;
        }
      return false;
    }
  }
/*
class BFSAlgorithm {
private:
  int *vertex, *predecessor, *colors, *distances, distance, order;
  void initialize() {
    for(int i = 0; i <= order; i ++) {
      vertex[i] = 0;
      predecessor[i] = 0;
      colors[i] = 0;
      distances[i] = 0;
    }
  }
public:
  BFSAlgorithm(int order) {
    this->order = order;
    vertex = new int[order+1];
    predecessor = new int[order+1];
    colors = new int[order+1];
    distances = new int[order+1];
    this->distance = 0;
    initialize();
  }
  void BFS(Graph *graph, int startupVertex) {
    for(int i = 0; i <= graph->getSize(); i ++) {
      vertex[i] = i;
      colors[i] = BRANCO;
      distances[i] = INT_MAX;
      predecessor[i] = 0;
    }
    colors[startupVertex] = CINZA;
    distances[startupVertex] = 0;
    predecessor[startupVertex] = -1;
    Queue<int> queue;
    queue.toQueue(startupVertex);
    while(queue.full()) {
      int vertexAux;
      queue.notToQueue(vertexAux);
      List<int> aux = graph->getGraph(vertexAux);
      for(int i = 0; i < aux.getSize(); i ++) {
        if(colors[aux.getElement(i)] == BRANCO) {
          colors[aux.getElement(i)] = CINZA;
          distances[aux.getElement(i)] = (distances[vertexAux] + 1);
          predecessor[aux.getElement(i)] = vertexAux;
          queue.toQueue(aux.getElement(i));
        }
      }
      distance ++;
      colors[vertexAux] = PRETO;
    }
  }
  void showResult() {
    cout << "Vertex - Predecessor - Distances " << endl;
    for(int i = 1; i <= order; i ++) {
      cout << vertex[i] << " () " << predecessor[i] << " () " << distances[i] << endl;
    }
  }
  int returnDistante(int vertex) {
    return distances[vertex];
  }
};*/
class BFS{
private:
  int *vert;
  int *pred;
  int *cor;
  int *distancias;
  int d;
  int n;
  void inicia(){
    for(int i = 0; i <= n; i++){
      vert[i] = 0;
      pred[i] = 0;
      cor[i] = 0;
      distancias[i] = 0;
    }
  }
public:
  BFS(int n){
    this->n = n;
    vert = new int[n + 1];
    pred = new int[n + 1];
    cor = new int[n + 1];
    ds = new int[n + 1];
    this->d = 0;
    inicia();
  }
  void algoritmoBFS(Grafo *grafo, int v ){
    for(int i = 0; i <= grafo->getM(); i++){
      vert[i] = i;
      cor[i] = BRANCO;
      distancias[i] = INT_MAX;
      pred[i] = 0;
    }
    cor[v] = CINZA;
    distancias[v] = INT_MAX;
    pred[v] = -1;
    Fila<int> fila;
    fila.enfileira(v);
    while(fila.cheia()){
      int vaux;
      fila.desenfileira(vaux);
      Lista<int> aux = grafo->getAdj(vaux);
      for(int i = 0; i < aux.getTam(); i++){
        if(cor[aux.getElem(i)] == BRANCO){
           cor[aux.getElem(i)] == CINZA;
           ds[aux.getElem(i)] == (distancias[vaux] + 1);
           pred[aux.getElem(i)] = vaux;
           fila.enfileira(aux.getElem(i));
        }
      }
      d++;
      cor[vaux] = PRETO;
    }

  }
  void mostraResultado(){
    cout << "Vert - Pred - D" << endl;
    for(int i = 0; i <= n; i++){
      cout << vert[i] << "()" << pred[i] << "()" << distancias[i] << endl;

    }
  }
  int retornaDistancia(int vertice){
    return distancias[vertice];
  }
};
/*
class Chess {
private:
  int *board[board_size]; // Tabuleiro do jogo
  int *sizeOfPath;
  Pieces king; // Pares respectivos do Rei e Cavalos
  Horses horses;
  Movements movements, paths; // Possíveis movimentos
  Graph *graph;
  BFSAlgorithm *bfs;

  void initializeBoard(string h1, string h2, string h3, string h4, string k);
  void addMovements();
  bool validateMove(int deltaX, int deltaY);
  void sizes();
  int minimumPath();
  void buildPath();
  void showPaths();
  void buildGraph();
  Pieces converter(string input);
public:
  Chess(string h1, string h2, string h3, string h4, string k) {
    this->graph = new Graph(MAXGRAPHSIZE);
    this->bfs = new BFSAlgorithm(MAXGRAPHSIZE);
    this->sizeOfPath = new int[NUMBEROFHORSES];
    addMovements();
    initializeBoard(h1, h2, h3, h4, k);
  }
  void AttackOfTheKnights();
};*/
class Xadrez{
private:
  int *tabuleiro[tam_tabuleiro];
  int *tamanhoDoCaminho;
  Pecas rei;
  Cavalos cavalos;
  Movimentos movimentos, caminhos;
  Grafo *grafo;
  BFS *bfs;

  void inicializaTabuleiro(string c1, string c2, string c3, string c4, string r);
  void adicionarMovimentos();
  bool validarMovimentos(int deltaX, int deltaY);
  void tamanhos();
  int caminhoMinimo();
  void constroiCaminho();
  void mostraCaminhos();
  void constroiGrafo();
  Pecas converter(string entrada);
public:
  Xadrez(string c1, string c2, string c3, string c4, string r){
    this->grafo = new Grafo(TAMMAXGRAFO);
    this->bfs = new BFS(TAMMAXGRAFO);
    this->tamanhoDoCaminho = new int[NUMCAVALOS];
    adicionarMovimentos();
    incializaTabuleiro(c1, c2, c3 ,c4, r);
  }
  void AtaqueDosCavaleiros();

};
    /*  ----- Métodos do Chess -----  */
void Xadrez::inicializaTabuleiro(string c1, string c2, string c3, string c4, string r){
  cavalos.push_back(converter(c1));
  cavalos.push_back(converter(c2));
  cavalos.push_back(converter(c3));
  cavalos.push_back(converter(c4));

  this->rei = converter(r);
  for(int i = 0; i < tam_tabuleiro; i++){
    tabuleiro[i] = new int[tam_tabuleiro];
  }
  for(int i = 0; i < tam_tabuleiro; i++){
    for(int j = 0; j < tam_tabuleiro; j++){
      tabuleiro[i][j] = 0;
    }
  }
  for(unsigned int j = 0; j < movimentos.at(2).size(); j++){
    int xAux = movimentos.at(2).at(j).first;
    int yAux = movimentos.at(2).at(j).second;
    int deltaX = (rei.first + xAux);
    int deltaY = (rei.second + yAux);
    if(validarMovimentos(deltaX, deltaY) && (tabuleiro[deltaX][deltaY] == 0)){
      tabuleiro[deltaX][deltaY] = -1;
    }
  }
  tabuleiro[rei.first][rei.second] = REI;
  
}

void Xadrez::adicionarMovimentos(){
  this->movimentos.push_back({});
  this->movimentos.push_back({});
  this->movimentos.push_back({});
  
  this->movimentos.at(0).push_back(make_par(-2, 1));
  this->movimentos.at(0).push_back(make_par(-1, 2));
  this->movimentos.at(0).push_back(make_par(1, 2));
  this->movimentos.at(0).push_back(make_par(2, 1));

  this->movimentos.at(1).push_back(make_par(-2, -1));
  this->movimentos.at(1).push_back(make_par(-1, -2));
  this->movimentos.at(1).push_back(make_par(1, -2));
  this->movimentos.at(1).push_back(make_par(2, -1));

  this->movimentos.at(2).push_back(make_par(-2, 0));
  this->movimentos.at(2).push_back(make_par(-1, 0));
  this->movimentos.at(2).push_back(make_par(1, 0));
  this->movimentos.at(2).push_back(make_par(2, 0));
  this->movimentos.at(2).push_back(make_par(0, -2));
  this->movimentos.at(2).push_back(make_par(0, -1));
  this->movimentos.at(2).push_back(make_par(0, 1));
  this->movimentos.at(2).push_back(make_par(0, 2));
  this->movimentos.at(2).push_back(make_par(-1, -1));
}

bool Xadrez::validarMovimentos(int deltaX, int deltaY){

}
/*    
void Chess::initializeBoard(string h1, string h2, string h3, string h4, string k) {
      horses.push_back(converter(h1));
      horses.push_back(converter(h2));
      horses.push_back(converter(h3));
      horses.push_back(converter(h4));
    
      this->king = converter(k);
      for(int i = 0; i < board_size; i ++) {
        board[i] = new int[board_size];
      }
      for(int i = 0; i < board_size; i ++) {
        for(int j = 0; j < board_size; j ++) {
          board[i][j] = 0;
        }
      }
      for(unsigned int j = 0; j < movements.at(2).size(); j ++) {
        int xAux = movements.at(2).at(j).first;
        int yAux = movements.at(2).at(j).second;
        int deltaX = (king.first + xAux);
        int deltaY = (king.second + yAux);
        if(validateMove(deltaX, deltaY) && (board[deltaX][deltaY] == 0)) {
          board[deltaX][deltaY] = -1;
        }
      }
      board[king.first][king.second] = KING;
    }
    
    void Chess::addMovements() {
      this->movements.push_back({});
      this->movements.push_back({});
      this->movements.push_back({});
    
      this->movements.at(0).push_back(make_pair(-2, 1));
      this->movements.at(0).push_back(make_pair(-1, 2));
      this->movements.at(0).push_back(make_pair( 1, 2));
      this->movements.at(0).push_back(make_pair( 2, 1));
    
      this->movements.at(1).push_back(make_pair(-2, -1));
      this->movements.at(1).push_back(make_pair(-1, -2));
      this->movements.at(1).push_back(make_pair( 1, -2));
      this->movements.at(1).push_back(make_pair( 2, -1));
    
      this->movements.at(2).push_back(make_pair(-2,0));
      this->movements.at(2).push_back(make_pair(-1,0));
      this->movements.at(2).push_back(make_pair(1,0));
      this->movements.at(2).push_back(make_pair(2,0));
      this->movements.at(2).push_back(make_pair(0,-2));
      this->movements.at(2).push_back(make_pair(0,-1));
      this->movements.at(2).push_back(make_pair(0,1));
      this->movements.at(2).push_back(make_pair(0,2));
      this->movements.at(2).push_back(make_pair(-1,-1));
      this->movements.at(2).push_back(make_pair(1,1));
      this->movements.at(2).push_back(make_pair(1,-1));
      this->movements.at(2).push_back(make_pair(-1,1));
    }
    
    bool Chess::validateMove(int deltaX, int deltaY) {
      if((deltaX > 0 && deltaX < 9) && (deltaY > 0 && deltaY < 9)) {
        return true;
      } else {
        return false;
      }
    }
    
    void Chess::sizes() {
      for(int i = 0; i < horses.size(); i ++) {
        sizeOfPath[i] = bfs->returnDistante(board[horses.at(i).first][horses.at(i).second]);
      }
    }
    
    int Chess::minimumPath() {
      int minimum = INT_MAX;
      for(int i = 0; i < NUMBEROFHORSES; i ++) {
        if(sizeOfPath[i] < minimum) {
          minimum = sizeOfPath[i];
        }
      }
      return minimum;
    }
    
    void Chess::buildPath() {
      int minimum = minimumPath();
      for(int i = 0; i < NUMBEROFHORSES; i ++) {
        if(sizeOfPath[i] == minimum) {
          paths.push_back({});
          int addTo = paths.size()-1;
          bool notBreak = true;
          int aux = board[horses.at(i).first][horses.at(i).second];
          while(notBreak) {
            for(int i = 1; i < board_size; i ++) {
              for(int j = 1; j < board_size; j ++) {
                if(board[i][j] == aux && aux != 1) {
                  paths.at(addTo).push_back(make_pair(i,j));
                }
              }
            }
            if(aux == 1) {
              notBreak = false;
            }
            aux = graph->getGraph(aux).getElement(0);
          }
        }
      }
    }
    
    void Chess::showPaths() {
      for(int i = 0; i < paths.size(); i ++) {
        cout << paths.at(i).size()-1 << " ";
        for(int j = 0; j < paths.at(i).size(); j ++) {
          cout << dictionaryChar.at(paths.at(i).at(j).first) << paths.at(i).at(j).second << " ";
        }
        cout << endl;
      }
    }
    
    void Chess::buildGraph() {
      int counter = 1;
    
      Queue<Pieces> queue;
    
      queue.toQueue(king);
    
      board[king.first][king.second] = 1;
    
      while(queue.full()) {
    
        Pieces aux;
    
        queue.notToQueue(aux);
    
        for(unsigned int i = 0; i < movements.size()-1; i ++) {
          for(unsigned int j = 0; j < movements.at(i).size(); j ++) {
    
            int xAux = movements.at(i).at(j).first;
            int yAux = movements.at(i).at(j).second;
    
            int deltaX = (aux.first + xAux);
            int deltaY = (aux.second + yAux);
    
            if(validateMove(deltaX, deltaY) && (board[deltaX][deltaY] == 0 && board[deltaX][deltaY] != 1)) {
              counter ++;
              board[deltaX][deltaY] = counter;
              Pieces piece(deltaX, deltaY);
              queue.toQueue(piece);
              graph->insertEdge(board[aux.first][aux.second], board[deltaX][deltaY]);
            }
          }
        }
      }
      bfs->BFS(graph, 1); // Vértice em que a rainha se encontra
    }
    
    Pieces Chess::converter(string input) {
      int first = 0, second = 0;
      for(unsigned int i = 1; i < dictionaryChar.size(); i ++) {
        if(dictionaryChar.at(i) == input[0]) {
          first = i;
        }
        if(dictionaryInt.at(i) == input[1]) {
          second = i;
        }
      }
      return make_pair(first, second);
    }
    
    void Chess::AttackOfTheKnights() {
      buildGraph();
      sizes();
      buildPath();
      showPaths();
    }
*/    

int main() {
  string h1, h2, h3, h4, k;
  cin >> h1 >> h2 >> h3 >> h4 >> k;
  Chess table(h1,h2,h3,h4,k);
  table.AttackOfTheKnights();
  return 0;
}
