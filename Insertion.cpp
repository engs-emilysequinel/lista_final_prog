#include <iostream> 
using namespace std; 

//cria a função insertionSort que recebe o vetor e a quantidade de elementos, o objetivo é inserir cada elemento na posição correta da parte já ordenada
void insertionSort(int vetor[], int tamanho) {

    int comparacoes = 0; //inicializa o contador de comparações com zero
    int trocas = 0; //inicializa o contador de movimentações com zero

    //começa no 1 porque o primeiro elemento sozinho já está ordenado
    //for percorre os elementos que serão inseridos na parte ordenada
    for (int i = 1; i < tamanho; i++) {

int chave = vetor[i]; //guarda o elemento que será colocado em sua posição correta
int j = i - 1; //define j como a posição imediatamente anterior a chave

        //while percorre os elementos anteriores enquanto houver posições para verificar
    while (j >= 0) {
comparacoes++; //conta a comparação entre o elemento da posição j e a chave

    //verifica se o elemento anterior é maior que a chave e se for ele precisa ser deslocado para abrir espaço
 if (vetor[j] > chave) {
    vetor[j + 1] = vetor[j]; //desloca o elemento maior uma posição para a direita
trocas++; //conta esse deslocamento como uma movimentação no vetor
    j--; //retrocede uma posição para continuar procurando o lugar da chave
}
else {
break; //interrompe o while quando encontra um elemento menor ou igual a chave
    }
 }

//verifica se a chave será colocada em uma posição diferente da original
    if (j + 1 != i) {
 vetor[j + 1] = chave; //insere a chave no espaço correto que foi encontrado
trocas++; //conta a inserção da chave como uma movimentação
     }
    }

 //mstra a quantidade total de comparações
    cout << "Comparacoes: " << comparacoes << endl;
 //mostra a quantidade total de movimentações 
    cout << "Movimentacoes: " << trocas << endl;
}

//cria uma função que mostra os elementos do vetor
void mostrarVetor(int vetor[], int tamanho) {

//percorre todas as posições do vetor
 for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " "; // o valor da posição atual 
    }

    cout << endl; 
}

int main() { 

int vetor[] = {5, 3, 8, 1, 4}; //Cria o vetor 
    int tamanho = 5; //quantidade de elementos

    cout << "Vetor inicial: "; 
mostrarVetor(vetor, tamanho); //mostra o vetor antes da ordenação

    insertionSort(vetor, tamanho); //chama a função Insertion Sort para ordenar os elementos

    cout << "Vetor ordenado: "; 
    mostrarVetor(vetor, tamanho); //mostra o vetor depois da ordenação

    return 0;
}