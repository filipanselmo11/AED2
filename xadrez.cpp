
#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

typedef vector<pair<int,int>> Movements;
typedef vector<pair<int,int>> Horses;
typedef pair<int,int> Pieces;

const int board_size = 9;

const int NUMBEROFHORSES = 4;
const int MAXGRAPHSIZE = 64;
const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;

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
  Node<T> *prim, *ult;
  int size;
public:
  List() {
    prim = new Node<T>();
    prim->setProx(NULL);
    ult = prim;
    size = 0;
  }
  ~List() {}
  int getSize();
  void insert(T element);
  Node<T>* search(T element);
  void show();
  T getElement(int position);
};

class Graph {
private:
  List<int> *graph;
  int order, size;
  void initialize(int order);
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
  bool notRepetition(int position, int element);
};

class BFSAlgorithm {
private:
  int *vertex, *predecessor, *colors, *distances, distance, order;
  void initialize();
public:
  BFSAlgorithm(int order);
  void BFS(Graph *graph, int startupVertex);
  void showResult();
  int returnDistance(int vertex);
  int returnPredecessor(int vertex);
};

class Chess {
private:
  int *board[board_size];
  int *sizeOfPath;
  Pieces king;
  Horses horses;
  Movements movements;
  Graph *graph;
  BFSAlgorithm *bfs;

  void initializeBoard(string h1, string h2, string h3, string h4, string k);
  void addMovements();
  bool validateMove(int deltaX, int deltaY);
  void sizes();
  int minimumPath();
  void showOutput();
  void buildGraph();
  Pieces converter(string input);
  bool sheik(int x, int y);
  void merge(vector<int> &list, int first, int medium, int last);
  void mergeSort(vector<int> &list, int first, int last);
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

void PP1();

int main() {

  PP1();

  return 0;
}

/*  ----- Implementação da chamada de função PP1 -----  */

void PP1() {
  vector<vector<string>> inputs;
  int qtdInputs = 0;
  cin >> qtdInputs;
  for(unsigned int i = 0; (int) i < qtdInputs; i ++) {
      inputs.push_back({});
      for(unsigned int j = 0; j < 5; j ++) {
          string input;
          cin >> input;
          inputs.at(i).push_back(input);
      }
  }
  for(unsigned int i = 0; (int) i < qtdInputs; i ++) {
    string h1 = inputs.at(i).at(0);
    string h2 = inputs.at(i).at(1);
    string h3 = inputs.at(i).at(2);
    string h4 = inputs.at(i).at(3);
    string k = inputs.at(i).at(4);
    Chess *chess = new Chess(h1, h2, h3, h4, k);
    chess->AttackOfTheKnights();
  }
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
  return size;
}

template <class T>
void List<T>::insert(T element) {
  ult->setProx(new Node<T>());
  ult = ult->getProx();
  ult->setProx(NULL);
  ult->setElement(element);
  size ++;
}

template <class T>
Node<T>* List<T>::search(T element) {
  Node<T> *aux = prim->getProx();
  while(aux != NULL && aux->getElement() != element) {
    aux = aux->getProx();
  }
  return aux;
}

template <class T>
void List<T>::show() {
  Node<T> *aux = prim->getProx();
  while (aux != NULL) {
    cout << aux->getElement() << " ";
    aux = aux->getProx();
  }
  cout << endl;
}

template <class T>
T List<T>::getElement(int position) {
  Node<T> *aux = prim->getProx();
  for(unsigned int i = 0; (int) i < size; i ++) {
    if( (int) i == position) {
      break;
    }
    aux = aux->getProx();
  }
  return aux->getElement();
}

/*  ----- Métodos do Grafo -----  */

void Graph::initialize(int order) {
  this->order = order;
  this->size = 0;
  graph = new List<int>[order+1];
}

void Graph::insertEdge(int vertex1, int vertex2) {
  if(notRepetition(vertex1, vertex2)) {
    graph[vertex1].insert(vertex2);
    size ++;
  }
}

void Graph::show() {
  for(unsigned int i = 1; (int) i <= this->order; i ++) {
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

bool Graph::notRepetition(int position, int element) {
  if(graph[position].search(element)) {
    return false;
  } else {
    return true;
  }
}

/*  ----- Métodos do BFS ----- */

void BFSAlgorithm::initialize() {
  for(unsigned int i = 0; (int) i <= order; i ++) {
    vertex[i] = 0;
    predecessor[i] = 0;
    colors[i] = 0;
    distances[i] = 0;
  }
}

BFSAlgorithm::BFSAlgorithm(int order) {
  this->order = order;
  vertex = new int[order+1];
  predecessor = new int[order+1];
  colors = new int[order+1];
  distances = new int[order+1];
  this->distance = 0;
  initialize();
}

void BFSAlgorithm::BFS(Graph *graph, int startupVertex) {
  for(unsigned int i = 0; (int) i <= graph->getOrder(); i ++) {
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
    for(unsigned int i = 0; (int) i < aux.getSize(); i ++) {
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

void BFSAlgorithm::showResult() {
  cout << "Vertex - Predecessor - Distances " << endl;
  for(unsigned int i = 1; (int) i <= order; i ++) {
    cout << vertex[i] << " () " << predecessor[i] << " () " << distances[i] << endl;
  }
}

int BFSAlgorithm::returnDistance(int vertex) {
  return distances[vertex];
}

int BFSAlgorithm::returnPredecessor(int vertex) {
  return predecessor[vertex];
}

/*  ----- Métodos do Chess -----  */

void Chess::initializeBoard(string h1, string h2, string h3, string h4, string k) {
  horses.push_back(converter(h1));
  horses.push_back(converter(h2));
  horses.push_back(converter(h3));
  horses.push_back(converter(h4));
  this->king = converter(k);

  for(unsigned int i = 0; i < board_size; i ++) {
    board[i] = new int[board_size];
  }

  int aux = 1;
  for(unsigned int i = 0; i < board_size; i ++) {
    for(unsigned int j = 0; j < board_size; j ++) {
      if(i > 0 && j > 0) {
        board[i][j] = aux;
        aux ++;
      }
    }
  }
}

void Chess::addMovements() {
  this->movements.push_back(make_pair(-2, 1));
  this->movements.push_back(make_pair(-1, 2));
  this->movements.push_back(make_pair( 1, 2));
  this->movements.push_back(make_pair( 2, 1));
  this->movements.push_back(make_pair(-2, -1));
  this->movements.push_back(make_pair(-1, -2));
  this->movements.push_back(make_pair( 1, -2));
  this->movements.push_back(make_pair( 2, -1));
}

bool Chess::validateMove(int deltaX, int deltaY) {
  if((deltaX > 0 && deltaX < 9) && (deltaY > 0 && deltaY < 9)) {
    return true;
  } else {
    return false;
  }
}

void Chess::sizes() {
  for(unsigned int i = 0; i < horses.size(); i ++) {
    sizeOfPath[i] = bfs->returnDistance(board[horses.at(i).first][horses.at(i).second])-1;
  }
}

int Chess::minimumPath() {
  int minimum = INT_MAX;
  for(unsigned int i = 0; i < NUMBEROFHORSES; i ++) {
    if(sizeOfPath[i] < minimum) {
      minimum = sizeOfPath[i];
    }
  }
  return minimum;
}

void Chess::showOutput() {
  int minimum = minimumPath();
  for(unsigned int i = 0; i < NUMBEROFHORSES; i ++) {
    if(sizeOfPath[i] == minimum) {
      cout << sizeOfPath[i] << " ";
    }
  }
  cout << endl;
}

void Chess::buildGraph() {
  for(unsigned int i = 1; i < board_size; i ++) {
    for(unsigned int j = 1; j < board_size; j ++) {
      int vertex = board[i][j];
      vector<int> aux;
      for(unsigned int k = 0; k < movements.size(); k ++) {
        int xAux = movements.at(k).first;
        int yAux = movements.at(k).second;

        int deltaX = i + xAux;
        int deltaY = j + yAux;
        if(validateMove(deltaX, deltaY)) {
          int vertexAux = board[deltaX][deltaY];
          aux.push_back(vertexAux);
        }
      }
      mergeSort(aux, 0, aux.size()-1);
      for(unsigned int i = 0; i < aux.size(); i ++) {
        graph->insertEdge(vertex, aux.at(i));
      }
    }
  }
  int kingPosition = board[this->king.first][this->king.second];
  bfs->BFS(graph, kingPosition);
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

bool Chess::sheik(int x, int y) {
  for(unsigned int i = 0; i < movements.size(); i ++) {
    int xAux = movements.at(i).first;
    int yAux = movements.at(i).second;
    int deltaX = (x + xAux);
    int deltaY = (y + yAux);
    if(validateMove(deltaX, deltaY)) {
      if(board[deltaX][deltaY] == board[king.first][king.second]) {
        return true;
      }
    }
  }
  return false;
}

void Chess::merge(vector<int> &list, int first, int medium, int last) {
  int pos1 = (medium-first) + 1;
  int pos2 = (last-medium);
  int left[pos1+1], right[pos2+1];
  for(unsigned int i = 1; (int) i <= pos1; i++) {
    left[i] = list[first+(i-1)];
  }
  for(unsigned int j = 1; (int) j <= pos2; j++) {
    right[j] = list[medium+j];
  }
  left[pos1+1] = INT_MAX;
  right[pos2+1] = INT_MAX;
  int i = 1, j = 1;
  for(unsigned int aux = first; (int) aux <= last; aux++) {
    if(left[i] <= right[j]) {
      list[aux]= left[i];
      i ++;
    } else {
      list[aux] = right[j];
      j ++;
    }
  }
}

void Chess::mergeSort(vector<int> &list, int first, int last) {
  if(first < last) {
    int medium = (first + last) / 2;
    mergeSort(list, first, medium);
    mergeSort(list, medium+1, last);
    merge(list, first, medium, last);
  }
}

void Chess::AttackOfTheKnights() {
  buildGraph();
  sizes();
  showOutput();
}
