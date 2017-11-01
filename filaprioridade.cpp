#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

int Pai(int i){
	return floor(i / 2);
}

int Esq(int i){
	return 2 * i;
}

int Dir(int i){
	return 2 * i + 1;
}

void heapFica(vector<int> &v, int i, int tamheap){
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

//for(int i = (int)floor(heapsize/2))

void constroiHeap(vector<int> &v, int &tamheap){
	tamheap = (int) v.size() - 1;
	for(int i = (int) floor(tamheap / 2); i >= 1; i--){
		heapFica(v,i,tamheap);
	}
}

void heapSort(vector<int> &v){
	int tamheap = 0;
	constroiHeap(v,tamheap);
	for(int i = v.size()-1; i >= 2; i--){
		swap(v[1],v[i]);
		tamheap--;
		heapFica(v,1,tamheap);
	}
}

//template <class T>
class FilaP{
    int ult;
    int item;
    int h*;
    int x;

    FilaP(){
        this->ult = 0;
        this->item = item;
        this->x = 0;
    }
    void insere(int item);
};

void FilaP::insere(int item){
    ult += 1;
    item = ult;
    while(item / 2 && x > h[item / 2] 
}

