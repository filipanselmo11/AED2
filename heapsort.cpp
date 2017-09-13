#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

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
void preencheVector(vector<int> &v){
	const int MAX = 30;
  	const int novoTam = (int) (rand()% MAX) + 1;
  	const int MAX_VAL = 100;
  	int val = 0;
  	for(int i = 1; i <= novoTam; i++){
   	 val = (int) rand()%MAX_VAL;
     v.push_back(val);
  }
}

void printVector(vector<int> v){
	for(int i = 1; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	//vector<int> v = {-999,5,3,2,1,4};
	vector<int> v;
	preencheVector(v);
	printVector(v);
	cout << "-------------------------" << endl;
	heapSort(v);
	printVector(v);
	return 0;
}