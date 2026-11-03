#include <iostream> 
using namespace std;

//cria a função selectionSort que recebe o vetor e seu tamanho
//organiza os elementos encontrando o menor valor a cada passagem
void selectionSort(int vetor[], int tamanho) {

int comparacoes = 0; //inicializa o contador de comparações com zero
int trocas = 0; //inicializa o contador de trocas com zero.

//percorre as posições do vetor que recebera os menores elementos
//última posição não precisa ser verificada porque vai ter apenas um elemento
    for (int i = 0; i < tamanho - 1; i++) {

    int menor = i; // Considera inicialmente que o menor elemento está na posição i.

//percorre os elementos à direita de i para encontrar um valor menor
for (int j = i + 1; j < tamanho; j++) {
comparacoes++; //registra uma comparação entre o elemento atual e o menor encontrado

//verifica se o elemento da posição j é menor que o elemento da posição menor
if (vetor[j] < vetor[menor]) {
 menor = j; //atualiza o índice para guardar a posição do novo menor elemento
 }
}
//verifica se o menor elemento encontrado está em uma posição diferente de i
//se estiver será necessário realizar uma troca
    if (menor != i) {
int auxiliar = vetor[i]; //guarda o valor da posição i antes de modificá-la
vetor[i] = vetor[menor]; //coloca o menor elemento encontrado na posição certa
vetor[menor] = auxiliar; //coloca o valor antigo de i na posição onde estava o menor
trocas++; //conta uma troca ja q dois elementos mudaram de posição
    }
    }

    //exibe o número total de comparações
    cout << "Comparacoes: " << comparacoes << endl;
    //exibe o número total de trocas
    cout << "Trocas: " << trocas << endl;
}

//cria uma função pra mostrar o vetor na tela
void mostrarVetor(int vetor[], int tamanho) {

    //percorre o vetor desde a primeira posição até a última
    for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " "; //mostra o valor armazenado na posição atual
    }

    cout << endl; 
}

int main() { 
int vetor[] = {5, 3, 8, 1, 4}; //cria o vetor 
int tamanho = 5; //vetor possui cinco elementos

    cout << "Vetor inicial: "; 
    mostrarVetor(vetor, tamanho); //,ostra os elementos antes de serem ordenados

    selectionSort(vetor, tamanho); //executa a função que organiza o vetor usando SelectionSort

    cout << "Vetor ordenado: ";
    mostrarVetor(vetor, tamanho); //mostra o vetor já organizado em ordem crescent

    return 0;
}