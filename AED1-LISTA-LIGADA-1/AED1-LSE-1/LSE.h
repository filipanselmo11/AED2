//
//  LSE.hpp
//  AED1-LSE-1
//
//  Created by Coelho on 10/04/17.
//  Copyright © 2017 Flavio Jose Mendes Coelho. All rights reserved.
//

#ifndef LSE_hpp
#define LSE_hpp

#include <iostream>

using namespace std;

typedef string Chave ;
typedef string Hora;

// Item
class Tarefa {
public:
    Chave desc;
    Hora hora;
    bool feito;
    Tarefa() {}
    Tarefa(Chave desc, Hora hora, bool feito) {
        this->desc = desc;
        this->hora = hora;
        this->feito = feito;
    }
    void print();
    
};

class No {
public:
    Tarefa tarefa;
    No* prox;
    
    No () {
        prox = NULL;
    }
    
    No (Tarefa tarefa) {
        this->tarefa = tarefa;
        prox = NULL;
    }
};

class LSE {
private:
    No* prim, *ult;
public:
    LSE () {
        prim = new No();
        prim->prox = NULL;
        ult = prim;
    }
    
    void insere(Tarefa);
    No* pred(No*);
    bool vazia();
    No* busca(Tarefa);
    void remove(No*, Tarefa&);
    void print();
};




#endif /* LSE_hpp */
