#include <iostream>
using namespace std;

//cria uma funcao chamada BubbleSort que recebeo vetor e a quantidade de elementos e os colocar em ordem crescente
void bubbleSort(int vetor[], int tamanho){
    int comparacoes = 0; //contador que começa em 0 para registrar quantas comparacoes serao realizadas
    int trocas = 0; // contador que começa em 0 para registrar quantas trocas serao realizadas

// O primeiro for controla quantas vezes o vetor será percorrido
    // Cada passagem coloca o maior elemento da parte não ordenada no final
    for(int i = 0; i < tamanho - 1; i++) {

        //o segundo for percorre os elementos que ainda precisam ser comparados
        //o - i evita comparar novamente os elementos já ordenados no final
        for (int j = 0; j < tamanho - 1 - i; j++) {
     comparacoes++; // Aumenta o contador porque dois elementos serão comparados nesta etapa

//verifica se o elemento atual é maior que o elemento que está ao seu lado direito
//se for maior significa que eles estão na ordem errada
if (vetor[j] > vetor[j + 1]) {
int auxiliar = vetor[j]; //guarda temporariamente o valor atual para não perdê-lo durante a troca
    vetor[j] = vetor[j + 1]; //coloca o elemento da direita na posição do elemento atual
    vetor[j + 1] = auxiliar; //coloca o valor que estava guardado na posição da direita
trocas++; //aumenta o contador porque dois elementos trocaram de posição
 }
}
}

 //mostra na tela o total de comparações feitas na ordenação
    cout << "Comparacoes: " << comparacoes << endl;

    //mostra na tela o total de trocas realizadas dos elementos
    cout << "Trocas: " << trocas << endl;
}

// função para mostrar os elementos do vetor na tela
void mostrarVetor(int vetor[], int tamanho) {

    // Percorre todas as posições do vetor começando pelo zero
    for (int i = 0; i < tamanho; i++) {
 cout << vetor[i] << " "; //mostra o elemento da posição i

}
cout << endl;
}
int main() {
int vetor[] = {5, 3, 8, 1, 4}; //cria o vetor com cinco números que serão ordenados
    int tamanho = 5; //guarda a quantidade de elementos do vetor

    cout << "Vetor inicial: ";
    mostrarVetor(vetor, tamanho); //chama a função que exibe os valores antes da ordenação

    bubbleSort(vetor, tamanho); //chama a função BubbleSort para ordenar o vetor

    cout << "Vetor ordenado: "; 
    mostrarVetor(vetor, tamanho); //exibe os valores depois que a ordenação foi feita

    return 0;
}