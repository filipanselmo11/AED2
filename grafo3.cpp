#include <iostream>

using namespace std;

typedef int Vertex;
typedef int Weight;

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
/*void Grafo<T>::print(){
    int k = 3;
    cout << "  ";
    for(int j = 1; j < n; j++){
        //cout << setw(k) << j;
        cout << k << j;
    }
    cout << endl;
    for(int j = 1; j < n * k + 3; j++){
        cout << "-";
    }
    cout << endl;
    for(int i = 1; i < n; i++){
        //cout << setw(1) << i; cout << "|";
        cout << 1 << i; cout << "|";
        for(int j = 1; j < n; j++){
             //cout << setw(k) << mat[i][j];
             cout << k << mat[i][j];
        }
        cout << endl;
    }
}*/

int main(){
    //cout << "Ordem: ";
    //int n;
    //cin >> n;
    Grafo<int> g(3);
    g.insereAresta(1,1,2);
    //g.insereAresta(2,2,2);
    // g.insereAresta(3,3,2);
    g.print();
    return 0;
    
}
