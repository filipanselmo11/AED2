#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

typedef vector<vector<pair<int,int>>> Movements;
typedef vector<pair<int,int>> Horses;
typedef pair<int,int> Pieces;

const int board_size = 9; // Considerando que utilizamos as posições de 1 até 8;

const int NUMBEROFHORSES = 4;
const int MAXGRAPHSIZE = 64;
const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
const int HORSE = 65;
const int KING = 66;
const vector<char> dictionaryChar = {'?', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
const vector<char> dictionaryInt = {'?', '1', '2', '3', '4', '5', '6', '7', '8'};

template <class T>
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
};

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
};

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
};

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
};

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
};

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
};

int main() {
  string h1, h2, h3, h4, k;
  cin >> h1 >> h2 >> h3 >> h4 >> k;
  Chess table(h1,h2,h3,h4,k);
  table.AttackOfTheKnights();
  return 0;
}

/*  ----- Métodos da Fila ----- */

template <class T>
void Queue<T>::toQueue(T element) {
  back->setProx(new Node<T>());
  back = back->getProx();
  back->setElement(element);
  back->setProx(NULL);
}

template <class T>
void Queue<T>::notToQueue(T &element) {
  Node<T> *aux = front;
  front = front->getProx();
  element = front->getElement();
  delete aux;
}

template <class T>
void Queue<T>::showQueue() {
  Node<T> *aux;
  aux = front->getProx();
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
bool Queue<T>::full() {
  Node<T> *aux;
  aux = front->getProx();
  if(aux == NULL) {
    return false;
  } else {
    return true;
  }
}

/*  ----- Métodos da Lista -----  */

template <class T>
int List<T>::getSize() {
  return list.size();
}

template <class T>
void List<T>::insert(T element) {
  list.push_back(element);
}

template <class T>
void List<T>::remove(T element) {
  int position = search(element);
  if(position == -1) {
    cout << "Can't remove!" << endl;
  } else {
    list.erase(list.begin() + position);
  }
}

template <class T>
int List<T>::search(T element) {
  int position = -1;
  for(int i = 0; i < list.size(); i ++) {
    if(element == list[i]) {
      position = i;
      i = list.size();
    }
  }
  return position;
}

template <class T>
void List<T>::show() {
  for(unsigned int i = 0; i < list.size(); i ++) {
    cout << list[i] << " ";
  }
  cout << endl;
}

template <class T>
void List<T>::destroy() {
  list.clear();
  list.shrink_to_fit();
}


template <class T>
T List<T>::getElement(int position) {
  return list[position];
}

template <class T>
void List<T>::changePosition(int position, T element) {
  list[position] = element;
}

/*  ----- Métodos do Grafo -----  */

void Graph::initialize(int order) {
  // if(this->order != 0) {
  //   destroy();
  // }
  this->order = order;
  this->size = 0;
  graph = new List<int>[order+1];
}

void Graph::destroy() {
  for(int i = 0; i <= this->order; i ++ ) {
    graph[i].destroy();
  }
  delete[] graph;
  order = size = 0;
}

void Graph::insertEdge(int vertex1, int vertex2) {
  if(!(repetition(vertex1, vertex2))) {
    graph[vertex1].insert(vertex2);
    graph[vertex2].insert(vertex1);
    size ++;
  }
}
void Graph::show() {
  for(int i = 1; i <= this->order; i ++) {
    cout << "G[" << i <<"] = ";
    graph[i].show();
  }
  cout << endl;
}
void Graph::setOrder(int order) {
  this->order = order;
}
int Graph::getOrder() {
  return order;
}
void Graph::setSize(int size) {
  this->size = size;
}
int Graph::getSize() {
  return size;
}

List<int> Graph::getGraph(int position) {
  return graph[position];
}

bool Graph::repetition(int position, int element) {
  for(int i = 1; i <= graph[position].getSize(); i ++) {
    if(graph[position].getElement(i) == element) {
      return true;
    }
  }
  return false;
}

/*  ----- Métodos do Chess -----  */

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
