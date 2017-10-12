//
//  LSE.cpp
//  AED1-LSE-1
//
//  Created by Coelho on 10/04/17.
//  Copyright © 2017 Flavio Jose Mendes Coelho. All rights reserved.
//

#include "LSE.h"


void Tarefa::print() {
    cout << desc << " - ";
    cout << hora << " - ";
    cout << (feito?"sim":"não");
}


void LSE::insere(Tarefa tarefa) {
    ult->prox = new No();
    ult = ult->prox;
    ult->prox = NULL;
    ult->tarefa = tarefa;
}


bool LSE::vazia() {
    return prim == ult;
}


No* LSE::pred(No* r) {
    No* p = prim->prox;
    while (p->prox != r) {
        p = p->prox;
    }
    return p;
}

void LSE::remove(No* r, Tarefa& tarefa){
    if (vazia() || r == NULL || r == prim) {
        cout << "impossível remover\n";
    }
    else {
        tarefa = r->tarefa;
        No* p = pred(r);
        p->prox = r->prox;
        if (p->prox == NULL) ult = p;
        delete r;
    }
}



No* LSE::busca(Tarefa tarefa) {
    No* p = prim->prox;
    while (p != NULL && p->tarefa.desc != tarefa.desc) {
        p = p->prox;
    }
    return p;
}

void LSE::print() {
    No* p = prim->prox;
    while (p != NULL) {
        p->tarefa.print();
        p = p->prox;
        cout << endl;
    }
}

