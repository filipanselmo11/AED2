#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

class Heap{
public:
    Heap(){

    }
    void heapMax(vector<int> &v);
    void extrairMax(vector<int> &v);
    void maxHeapfy(vecotr<int> &v, int x);
};

void Heap::heapMax(vector<int> &v){
    return v[1];
}

void Heap::extrairMax(vector<int> &v){
    if(v.size() < 1){
        cout << "Heap underflow" << endl;
    }
    int max = v[1];
    v.size() = v.size() - 1;
    maxHeapfy(v, 1);
    return max;
}