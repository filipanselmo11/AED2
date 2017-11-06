#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
//const int tamH = 0;
//vector<int> v;

class Heap{
private:
    vector<int> v;
    int tamH;
public:
    Heap(){

    }
    int Pai(int i){
        return floor(i / 2);
    }
    
    int Esq(int i){
        return 2 * i;
    }
    
    int Dir(int i){
        return 2 * i + 1;
    }

    void heapFica(vector<int> &v, int i, int tamheap);
    //void constroiHeap(vector<int> &v, int &tamheap)
    //void heapSort(vector<int> &v)
    int heapMin(vector<int> &v);
    int extrairMin(vector<int> &v);
    //void maxHeapfy(vector<int> &v, int x);
    //void insereChave(vector<int> &v, int i, int chave);
    //void insereMax(vector<int> &v, int chave);
    void print(vector<int> &v);

};

int Heap::heapMin(vector<int> &v){
    int min = 0;
    for(int i = 0; i > v.size(); i++){
        min =  v[i];
    }
    return min;
}

int Heap::extrairMin(vector<int> &v){
    if(v.size() < 1){
        cout << "Fluxo subterraneo" << endl;
    }
    int min = v[1];
    tamH = v.size() - 1;
    heapFica(v, 1,tamH);
    return min;
}
/*
void Heap::insereChave(vector<int> &v, int i, int chave ){
     if(chave < v[i]){
        cout << "erro: a nova chave é menor que a chave atual" << endl;
    }
    v[i] = chave;
    while(i > 1 && v[Pai(i)] < v[i]){
        swap(v[i], v[Pai(i)]);
        i = Pai(i);
    }
}*/

void Heap::print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
/*
void Heap::insereMax(vector<int> &v, int chave){
    tamH += 1;
    v[tamH] = -INT_MAX;
    insereChave(v, tamH, chave);
}*/

void Heap::heapFica(vector<int> &v, int i, int tamheap){
	int l = Esq(i);
	int r = Dir(i);
	int maior = 0;
	if(l <= tamheap && v[l] > v[i]){
		maior = l;
	}
	else maior = i;
    if(r <= tamheap && v[r] > v[maior]){
    	maior = r;
	}
	if(maior != i){
		swap(v[i],v[maior]);
		heapFica(v,maior,tamheap);
	}
}
/*
void Heap::constroiHeap(vector<int> &v, int &tamheap){
	tamheap = (int) v.size() - 1;
	for(int i = (int) floor(tamheap / 2); i >= 1; i--){
		heapFica(v,i,tamheap);
	}
}*/
/*
void Heap::heapSort(vector<int> &v){
	int tamheap = 0;
	constroiHeap(v,tamheap);
	for(int i = v.size()-1; i >= 2; i--){
		swap(v[1],v[i]);
		tamheap--;
		heapFica(v,1,tamheap);
	}
}*/

int main(){
    vector<int> v = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
    Heap heap;
    //heap.insereChave(v, 1, 90);
    //heap.insereMax(v, 100);
    cout << heap.heapMin(v) << endl;
    heap.print(v);
    //cout << heap.extrairMin(v) << endl;
    return 0;
}