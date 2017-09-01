#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

template<class T>
void selectionSort(vector<T> &v){
	for(int i = 0; i < v.size() - 1; i++){
		T min = i;
		for(int j = i + 0; j < v.size(); j++){
			if(v[j] < v[min]){
				min = j;
			}
		}
		T aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}
}

template<class T>
void printVector(vector<T> v){
  for(int i = 0; i < v.size(); i++){
       cout << v[i] << " ";
  }
  cout << endl;
}
/*
class Aluno{
private:
	string nome;
	int matricula;
public:
	Aluno(string nome, int matricula){
		this->nome = nome;
		this->matricula = matricula;
	}
	void setNome(string nome){
		this->nome = nome;
	}
	string getNome(){
		return this->nome;
	}
	void setMatricula(int matricula){
		this->matricula = matricula;
	}
	int getMatricula(){
		return this->matricula;
	}
};*/


int main(){
	vector<int> v = {10,9,8,7,6,6};
	printVector(v);
	cout << "------------\n";
	selectionSort(v);
	printVector(v);
	return 0;
}