// Merge Sort
// Divide o vetor pela metade recursivamente

#include <iostream>

using namespace std;

void print(int *a, int tam){
     // ====== PRINT =============
    cout << "Array: [";
    for(int i = 0; i < tam; i++){cout << a[i] << ", ";}
    cout << "\b\b]" << endl;
    // ===========================

}

void merge(int *a, int tam)
{
    print(a, tam);
    // Condição de parada
    if(tam <= 1) return;

    // ==== Dividir vetor no meio recursivamente ====
    // -> Descobrir meio do vetor
    int meio = tam / 2;
    
    // -> Chamar a função recursivamente para cada lado (chamda não uso ponteiro)
    // Para lado esquerdo         Para o lado direito
    cout << endl <<  "Esquerda:" << endl;
    merge(a, meio);         
    
    cout << endl << "Direita" << endl;
    merge(a + meio, tam - meio);

    
    // ==== Ordenação ====
    // Criar vetor auxiliar
    int *aux = new int[tam];

    // Ponteiros para localização
    int i = 0; (inicio);
    int j = meio;
    int k = 0;

    // Enquanto as duas metades tem elementos
    while( ( i < meio ) && ( j < tam ) )
    {
        // Se o inicio é menor ou igual oa meio
        if(a[i] <= a[j])
        {
            //Coloca o primeiro valor do vetor no primeiro do aux
            aux[k] = a[i];
            i++;
        } 

        // Se o inicio for maior que o meio (valores invertidos)
        else
        {
            // Coloca o segundo valor (valor maior) no primeiro do auxiliar.
            aux[k] = a[j];
            i++;
        }

        // Passa para o proximo valor do auxiliar
        k++;
    }

    // Como um lado pode acabar antes do outro, precisamos de whiles separados



    // Copia auxiliar para vetor original
    for(int x = 0, i < tam; i++)
    {
        a[x] = aux[x];
    }

    // Por fim, deleta aux da memória
    delete[] aux;


    cout << endl << "a[0] = " <<  a[0] << endl << "a[1] = " <<  a[1] << endl;
    if(a[0] > a[1]) swap(a[0], a[1]);
    cout << "swap";
    cout << endl << "a[0] = " <<  a[0] << endl << "a[1] = " <<  a[1] << endl;
    
    print(a, tam);
}


int main()
{
    int a[] = {9, 8, 7, 6, 5};
    int tam = sizeof(a) / sizeof(a[0]);

   // print(a, tam);
    merge(a, tam);




return 0;
}