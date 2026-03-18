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
    int i = 0; // inicio;
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
            k++;
            i++;
        } 

        // Se o inicio for maior que o meio (valores invertidos)
        else
        {
            cout << "Troca lógica: " << a[i] << " > " << a[j] << endl;
            // Coloca o segundo valor (valor maior) no primeiro do auxiliar.
            aux[k] = a[j];
            k++;
            j++;
        }
    }

    // Possíveis sobras
    // Lado esquerdo
    while(i < meio){
        aux[k] = a[i];
        k++;
        i++;
    }

    // Lado direito
    while(j < tam){
        aux[k] = a[j];
        k++;
        j++;
    }

    // Copia auxiliar para vetor original
    for(int x = 0; x < tam; x++)
    {
        a[x] = aux[x];
    }

    // Por fim, deleta aux da memória
    delete[] aux;

    print(a, tam);
}


int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3};
    int tam = sizeof(a) / sizeof(a[0]);

   // print(a, tam);
    merge(a, tam);




return 0;
}