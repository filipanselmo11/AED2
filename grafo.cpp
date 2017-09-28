#include <iostream>

using namespace std;

template <class T>

class No{
private:
	T it;
	No *prox;
public:
	No(){
		this->prox = NULL;
	}
	No(T it){
		this->it = it;
		this->prox = NULL;
	}

	void setIt(T it){
		this->it = it;
	}

	T getIt(){
		return it;
	}

	void setProx(No *prox){
		this->prox = prox;
	}

	No *getProx(){
		return prox;
	}
};

template <class T>
class Lista{
private:
	No<T> *prim;
	No<T> *ult;
	bool vazia();
	No<T> *pred(No<T>*);
public:
	Lista(){
		prim = new No<T>;
		prim->setProx(NULL);
		ult = prim;
	}
	void insere(T);
	void mostra();
	void remove(T, No<T>*);
	No<T> *busca(T);
};

template <class T>
bool Lista<T>::vazia(){
	return prim == ult;
}

template <class T>
No<T>*Lista<T>::pred(No<T> *r){
	No<T> *p = prim->getProx();
	while(p->getProx() != r){
		p = p->getProx();
	}
	return p;
}

template <class T>
void Lista<T>::insere(T it){
	ult->setProx(new No<T>);
	ult = ult->getProx();
	ult->setProx(NULL);
	ult->setIt(it);
}

template <class T>
void Lista<T>::mostra(){
	No<T> *nav = prim->getProx();
	while(nav != NULL){
		cout << nav->getIt() << " ";
		nav = nav->getProx();
	}
	cout << endl;
}

template <class T>
No<T>*Lista<T>::busca(T it){
	No<T> *p = prim->getProx();
	while(p != NULL && p->getIt() != it){
		p = p->getProx();
	}
	return p;
}

template <class T>
void Lista<T>::remove(T it, No<T> *r){
	if(vazia() || r == NULL || r == prim){
		cout << "Impossivel remover" << endl;
	}
	else{
		it = r->getIt();
		No<T> *p = pred(r);
		p->setProx(r->getProx());
		if(p->getProx() == NULL){
			ult = p;
		}
	}
	delete r;
}

int main(){
	Lista<int> l;
	l.insere(1);
	l.insere(2);
	l.insere(3);
	l.insere(4);
	l.insere(5);
	l.mostra();

	No<int> *px = l.busca(5);
	if(px == NULL){
		cout << "Numero nao encotrado" << endl;
	}
	else{
		cout << px->getIt() << endl;
	}
	l.remove(6,px);
	l.mostra();

	return 0;
}
