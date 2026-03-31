#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(){
    ifstream book("dom_casmurro.txt");
    string palavra;

    if(!book.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
        return 1;
    }

    map<string,int> dic;

    while(book >> palavra){
        // cout << palavra << endl;

        // Se a palavra ainda nao existe, cria com 0; depois incrementa. (da propria biblioteca)
        dic[palavra]++;
    }

    // Impririr
    for(map<string, int>::iterator i = dic.begin(); i != dic.end(); i++){
        cout << i -> first << " | " << i -> second << endl;
    }

    // Mais repetida
    int mais = 0;
    string tmp;
    for(map<string, int>::iterator i = dic.begin(); i != dic.end(); i++){
        if(i -> second > mais){ mais = i -> second; tmp = i -> first; }
    }
    cout << "Mais repetida: " << tmp << " | " << mais << " vezes" << endl;



    book.close();
    return 0;
}