#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void swim (int v[], int k );
void put  (int v[], int* size, int data );
void sink (int v[], int size, int k );
int  get  (int v[], int* size );
void print(int v[], int size, int b, int elem, int sp );
void sort (int v[], int size);


// Subir um elemento recem inserido no heap caso seja maior que seu pai
// v[] -> Vetor que guarda o heap
// k   -> posição do elemento recém inserido
void swim (int v[], int k ) {
    // Enquanto o elemento não estiver na raiz (k = 1)
    // Enquanto o pai (v[k]) é menor que o filho
    while (k>1 && v[k/2]<v[k]) {
        printf("Swap %d with %d\n",v[k], v[k/2]);
        int tmp = v[k]; // Quarda o valor do filho temporarioamente
        v[k] = v[k/2];  // Coloca o valor do pai na posição do filho
        v[k/2] = tmp;   // Coloca o valor antigo do filho na posição do pai
        k = k / 2;      // Atualiza k para posição do pai
    }
}

void put(int v[], int* size, int data ) {
    v[*size] = data;
    swim( v, *size );
    (*size)++;
}

// Desce a posição no heap até a posição correta
void sink (int v[], int size, int k ) {
    // Continua enquanto k ainda tiver um filho
    while (2*k <= size) {
        int j = 2*k;                      // filho esquerdo
        if (j < size && v[j]<v[j+1]) j++; // Se o filho esquerdo é maior que o direito
        if (v[k] >= v[j]) break;         // Se o pai é maior ou igual ao filho, o heap está correto
        int tmp = v[k];                  // Se não, guarda o valor do pai para fazer a troca

        // Faz o swap com o fihlo
        v[k] = v[j];
        v[j] = tmp;
        k = j;
    }
}

// Remove e retorna o maior elemento do heap (raiz)
int get( int v[], int* size ) {
    int res = v[1];                 // Maior elemento fica na raiz
    v[1] = v[--(*size)];            // Reduz o tamanho do heap, levando o ultimo elemento valido para a raiz
    sink( v, *size, 1 );            // Deepois de pegar eese elemento, o heap pode ficar invalido, então faz-se sink() novamente
    return res;
}

void print( int v[], int size, int b, int elem, int sp )  {
    int i, j;

    for( j = 1; j < size; j++ ) printf("%d ", v[j]);
    printf("\n");

    while ( 1 ) {
        for( j = 0; j <= sp / 2; j++ ) printf(" ");
        for( i = b; i < b + elem; i++ ) {
            if ( i == size ) return;
            printf("%d", v[i] );
            for( j = 0; j < sp; j++ ) printf(" ");
        }
        printf("\n");
        b = b + elem;
        elem = 2 * elem;
        sp = sp / 2;
    }
}

// Repetir a remoção do maior elemento (raiz)
// Colocar esse elemento na posição final de um vetor

void sort(int v[], int size)
{
    



}

int main()
{
   // Inicializa gerador aleatorio
   srand(time(0));

   int v[MAX+1];
   v[1] = 0;  // posicao 0 nao e' usada
   int size = 1;

   for(int i=0; i<MAX; i++)
     put(v, &size, rand()%(MAX*10)); // preenche aleatoriamente

//  print(v, size, 1, 1, 64);
//  printf("\n");

   // Ordena
   long start = clock();
   sort(v, size);
   long end = clock();

  printf("\nOrdenado:\n");

  for(int i=1; i<size; i++)
    printf("%d ", v[i]);
  printf("\n");

   printf("Tempo para %d elementos: %ld ns\n", MAX,(end-start));
}

