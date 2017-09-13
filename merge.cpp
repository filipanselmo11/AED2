#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

template<class T>
void merge(vector<T> &a, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;

	vector<T> L(n1 + 1);
	vector<T> R(n2 + 1);

	for(int i = 1; i <= n1; i++){
		L[i] = a[p + i - 1];
	}
	for(int j = 1; j <= n2; j++){
		R[j] = a[q + j];
	}
	L[n1 + 1] = INT_MAX;
	R[n2 + 1] = INT_MAX;
	int i = 1, j = 1;
	for(int k = p; k <= r; k++){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
	}
}

template<class T>
void mergeSort(vector<T> &a, int p, int r){
	if(p < r){
		int q = floor((p + r) / 2);
		mergeSort(a, p, q);
		mergeSort(a, q + 1, r);
		merge(a , p, q, r);
	}
}

template<class T>
void preencheVector(vector<T> &v){
  const int MAX = 30;
  const int novoTam = (int) (rand()% MAX) + 1;
  const int MAX_VAL = 100;
  int val = 0;
  for(int i = 1; i <= novoTam; i++){
    val = (int) rand()%MAX_VAL;
    v.push_back(val);
  }
}

template<class T>
void printVector(vector<T> v){
	for(int i = 1; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int> A;
	preencheVector(A);
	printVector(A);
	cout << "-------------\n";
	int p = 1, r = A.size()-1;
	mergeSort(A,p,r);
	printVector(A);
	return 0;
}