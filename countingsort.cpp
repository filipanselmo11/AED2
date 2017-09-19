#include <vector>
#include <iostream>

using namespace std;
void printVector(vector<int> v);
/*
void maiorValor(vector<int> &v, int maior){
	for(int i = 0; i < v.size(); i++){
		if(v[i] > maior){
			maior = v[i];
		}
	}
}*/


void countingSort(vector<int> a, vector<int> &b, int k){
	vector<int> c(k+1);
	for(int i = 1; i <= k; i++){
		c[i] = 0;
	}
	for(int j = 1; j <= a.size() - 1; j++){
		c[a[j]] = c[a[j]] + 1;
	}
	for(int i = 1; i <= k; i++){
		c[i] = c[i] + c[i - 1];
	}
	for(int j = a.size() - 1; j >= 1; j--){
		b[c[a[j]]] = a[j];
		c[a[j]] = c[a[j]] - 1;
	}
}

/*
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
*/

void printVector(vector<int> v){
	for(int i = 1; i <= v.size() -1; i++){
		cout << v[i] << " ";
	}

	cout << endl;
}

int main(){
	vector<int> a = {-1,8,9,7,6,5,8,3,2,1};
	vector<int> b(a.size());
	//int k = -1;
	//preencheVector(a);
	countingSort(a,b,9);
	printVector(b);
	//maiorValor(a,k);
	//Scout << k << endl;
	return 0;
}