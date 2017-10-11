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
class Fila{
private:
    No<T> *tras, *frente;
public:
    Fila(){
        frente = new No<T>;
        frente->setProx(NULL);
        tras = frente;
    }

    No<T> *getTras(){
        return tras;
    }

    No<T> *getFrente(){
        return frente;
    }
    void enfileira(T);
    void mostra();
    void desenfileira(T);
};

template <class T>
void Fila<T>::enfileira(T it){
    tras->setProx(new No<T>);
    tras = tras->getProx();
    tras->setIt(it);
    tras->setProx(NULL);
}

template <class T>
void Fila<T>::mostra(){
    No<T> *nav = getTras()->getProx();
    cout << "Frente -> ";
    while(nav != NULL){
        cout << nav->getIt();
        nav = nav->getProx();
    }
    cout << " <- Tras" << endl;
}

template <class T>
void Fila<T>::desenfileira(T it){
    No<T> *aux = frente;
    frente = frente->getProx();
    it = frente->getIt();
    delete aux;
}

int main(){
    Fila<int> f;
    f.enfileira(1);
    f.enfileira(2);
    f.enfileira(3);
    f.enfileira(4);
    f.mostra();
    return 0;
}