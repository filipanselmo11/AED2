#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#define sentinela -1

using namespace std;

int particao(vector<int> &v, int p, int r){

	int x = v[p];
	//cout << "Pivo = " << x << endl;
	int tmp = v[r+1];
	v[r+1] = x;
	int i = p;
	int j = r + 1;
	while(true){
		do i++; while(v[i] < x);
		do j--; while(v[j] > x);
		/*
		do{
			i++;
		}while(v[i] < x);

		do{
			j++;
		}while(v[j] > x);*/
		if(i < j){
			//v[i] = v[j];
			swap(v[i],v[j]);
		}
		else{
			//v[p] = v[j];
			swap(v[p],v[j]);
		}
		v[r+1] = tmp;
		return j;
	}

}

void quickSort(vector<int> &v, int p, int r){
	if(p < r){
		int q = particao(v,p,r);
		quickSort(v,p,r-1);
		quickSort(v,q+1,r);
	}
}

void preencheVector(vector<int> &v){
	//srand((unsigned) time(0));
	//for(int i = 1; i < v.size(); i++){
		//v[i] = rand()%100;
  //}
  const int MAX = 30;
  const int novoTam = (int) (rand()% MAX) + 1;
  const int MAX_VAL = 100;
  int val = 0;
  for(int i = 1; i <= novoTam; i++){
    val = (int) rand()%MAX_VAL;
    v.push_back(val);
  }

}
/*
void printPos(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		cout << i << " ";
	}
}*/
void printVector(vector<int> v){
	for(int i = 1; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int> v;
	preencheVector(v);
	//int q = particao(v,1,v.size()-1);
	//cout << q << endl;
	//printPos(v);
	//cout << endl;
	printVector(v);
	cout << "--------------------" << endl;
	quickSort(v,1,v.size());
	printVector(v);
	return 0;
}
