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
    void insereChave(int i, int chave);
public:
    Heap(){
        v.push_back(NIL);
    }
    void heapFica(int i);
    void constroiHeap();
    int extractMin();
    void insere(int elemento);
    void insereMin(int chave);
    void print();
    void executa();
    int heapMin();
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

int Heap::heapMin(){
    return v[1];
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

int Heap::extractMin(){
    int min;
    if(tamheap < 1){
        //cout << "Heap underflow" << endl;
        cout << "Fluxo subterrâneo" << endl;
    }
    min = v[1];
    v[1] = v[tamheap];
    tamheap = v.size() + 1;
    v.erase(v.begin());
    heapFica(1);
    //v.erase(v.begin());
    return min;
}

void Heap::insere(int elemento){
        v.push_back(elemento);
        heapFica(elemento);
        tamheap += 1;
}

void Heap::insereChave(int i, int chave){
    if(chave < v[i]){
        //cout << "erro : new key is smaller than current key" << endl;
        cout << "erro : nova chave é menor do que a chave atual" << endl;
    }
    v[i] = chave;
    while(i > 1 && v[Pai(i)] < v[i]){
        swap(v[i], v[Pai(i)]);
        i = Pai(i);
    }
}

void Heap::insereMin(int chave){
    tamheap = v.size() + 1;
    v[tamheap] = -INT_MAX;
    insereChave(tamheap,chave);
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
    //cout << "Heap-Mínimo: " << heapMin() << endl;
}

int main(){
    Heap heap;
    heap.insere(15);
    heap.insere(13);
    heap.insere(9);
    heap.insere(5);
    heap.insere(12);
    heap.insere(8);
    heap.insere(7);
    heap.insere(4);
    heap.insere(6);
    heap.insere(2);
    heap.insere(1);
    heap.executa();
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Heap-Mínimo-Extraído: " << heap.extractMin() << endl;
    heap.executa();
    cout << "Heap-Mínimo-Extraído: " << heap.extractMin() << endl;
    heap.executa();
    cout << "Heap-Mínimo-Extraído: " << heap.extractMin() << endl;
    heap.executa();
    cout << "Heap-Mínimo-Extraído: " << heap.extractMin() << endl;
    heap.executa();
    return 0;
}