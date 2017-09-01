#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

template<class T>
void bubbleSort(vector<T> &v){
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j] > v[j+1]){
				T aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}
/*
template<class T>
void preenche(vector<T> &v){
  for(int i = 0; i < v.size(); i++){
    srand((unsigned)time(0));
    v[i] = rand() % 10;
  }
}*/

template<class T>
void printVector(vector<T> v){
  for(int i = 0; i < v.size(); i++){
       cout << v[i] << " ";
  }
  cout << endl;
}


int main(){
  vector<string> v = {"madara","kratos","goku","rugal"};
  //vector<int> v = {90,1,3,2,4};
  //srand((unsigned)time(0));
  //preenche(v);
  printVector(v);
  cout << "----------------\n";
  bubbleSort(v);
  printVector(v);
  return 0;
  
}
