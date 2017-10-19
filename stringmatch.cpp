#include <iostream>

using namespace std;

void stringmatchIngenuo(string text, string padrao){
    int n = text.size();
    int m = padrao.size();
    //int count = 0;
    for(int s = 0; s <= (n - m); s++){
        int count = 0;
        for(int i = 0; i < s; i++){
            if(text[s+i] == padrao[i]){
                count++;
                //cout << "Padrao encontrado com sucesso" << endl;
                //cout << padrao[i] << " ";
                //cout << endl;
            }
        }
        if(count == m){
            cout << "achou" << endl;
        }
    }
 
}

int main(){
	string text, padrao;
    getline(cin, text);
    getline(cin , padrao);
    stringmatchIngenuo(text, padrao);
    /*for(int i = 0; i < text.size()-1; i++){
        cout << i << " ";
        //cout << text[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < text.size()-1; i++){
        //cout << i << " ";
        cout << text[i] << " ";
    }*/
	return 0;
}
