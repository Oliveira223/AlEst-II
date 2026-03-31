#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream book("dom_casmurro.txt");
    string palavra;

    if(!book.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
        return 1;
    }

    struct Map{
        string palavra;
        int freq;
    };

    vector<Map> dic;
    //dic.push_back({"teste", 1});
    //cout << dic[0].palavra << " " << dic[0].freq;

    while(book >> palavra)
    {
        bool existe = 0; 

        for(vector<Map>::iterator i = dic.begin(); i != dic.end(); i++){
            if( palavra == i -> palavra){
                i -> freq += 1;
                existe = 1;
            }   
        }

        // Se não existe, inicializa com 1
        if(!existe){
        dic.push_back({palavra, 1});
        }   
    }

    for(vector<Map>::iterator i = dic.begin(); i != dic.end(); i++){
        cout << i-> palavra << " | " << i -> freq << endl;
    }
 
    // Mais repetido
    int mais = 0;
    string tmp;
    for(vector<Map>::iterator i = dic.begin(); i != dic.end(); i++){
        if(i -> freq > mais){ mais = i -> freq; tmp = i -> palavra; }
    }
    cout << "Mais repetida: " << tmp << " | " << mais << " vezes" << endl;

    book.close();
    return 0;
    }
