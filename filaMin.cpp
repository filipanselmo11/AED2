#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#define NIL -1

using namespace std;

class Heap{
private:
    vector<int> v;
    int tamheap;
    int Pai(int i);
    int Esq(int i);
    int Dir(int i);
public:
    Heap(){
        v.push_back(NIL);
    }
    void heapFica(int i);
    void constroiHeap();
    void extractMin();
    void insere(int elemento);
    void print();
    void executa();
};

int Heap::Pai(int i){
    return floor(i / 2);
}

int Heap::Esq(int i){
    return 2 * i;
}

int Heap::Dir(int i){
    return 2 * i + 1;
}

void Heap::heapFica(int i){
    int esq = Esq(i);
	int dir = Dir(i);
	int menor = INT_MAX;
	if(esq < tamheap && v[esq] < v[i]){
		menor = esq;
	}
	else menor = i;
    if(dir < tamheap && v[dir] < v[menor]){
    	menor = dir;
	}
	if(menor != i){
		swap(v[i],v[menor]);
		heapFica(menor);
	}
}

void Heap::constroiHeap(){
    tamheap = (int) v.size();
	for(int i = (int) floor(v.size() / 2); i >= 1; i--){
		heapFica(i);
	}
}

void Heap::insere(int elemento){
        v.push_back(elemento);
        tamheap = v.size();
        heapFica(elemento);
}

void Heap::print(){
    for(int i = 1; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void Heap::executa(){
    constroiHeap();
    print();
}

int main(){
    Heap heap;
    //heap.print();
   // heap.insere(v,3);
    //heap.print(v);
    //heap.constroiHeap();
    //heap.print();
    //heap.insere(1);
    //heap.constroiHeap();
    //heap.print();
    heap.insere(1);
    heap.executa();
    return 0;
}