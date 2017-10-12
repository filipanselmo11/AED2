//
//  main.cpp
//  AED1-LSE-1
//
//  Created by Coelho on 10/04/17.
//  Copyright © 2017 Flavio Jose Mendes Coelho. All rights reserved.
//

#include <iostream>
#include "LSE.h"




int main(int argc, const char * argv[]) {
    LSE l;
    Tarefa a("Abrir os olhos", "6:00", true);
    Tarefa b("Tomar ovomaltine", "7:00", true);
    Tarefa c("Academia", "8:00", false);
    Tarefa d("Churrascada", "9:00", false);
    Tarefa e("Ioga", "10:00", false);
    l.insere(a);
    l.insere(b);
    l.insere(c);
    l.insere(d);
    l.insere(e);
    l.print();

    
    Tarefa x("Tomar ovomaltine", "", false);
    No* px = l.busca(x);
    if (px == NULL) {
        cout << "Tarefa não encontrada!\n";
    }
    else {
        px->tarefa.print();
    }
    cout << "\n\n";
    cout << "----------------------\n";
    
    Tarefa y;
    l.remove(px, y);
    l.print();
    cout << "removido: ";
    y.print();
    
    cout << "\n\n";
    return 0;
}
