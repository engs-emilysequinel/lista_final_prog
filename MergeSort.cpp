#include <iostream> 
using namespace std;
// Função responsável por juntar duas partes do vetor que já estão ordenadas
// Recebe o vetor os limites das partes e os contadores por referência
void intercalar(int vetor[], int inicio, int meio, int fim,int &comparacoes, int &movimentacoes) {

 //calcula quantos elementos existem na primeira metade
int tamanho1 = meio - inicio + 1;
//calcula quantos elementos existem na segunda metade
int tamanho2 = fim - meio;
//cria um vetor auxiliar para armazenar temporariamente a metade esquerda
int esquerda[100];
//cria outro vetor auxiliar para armazenar temporariamente a metade direita
int direita[100];
//copia os elementos da primeira metade do vetor original para o auxiliar
for (int i = 0; i < tamanho1; i++) {

esquerda[i] = vetor[inicio + i]; //copia cada elemento para a posição que deve estar
 }

 //copia os elementos da segunda metade do vetor original para o auxiliar
for (int j = 0; j < tamanho2; j++) {
    direita[j] = vetor[meio + 1 + j]; //armazena cada elemento da segunda metade
     }

    int i = 0; //índice para percorrer os elementos da metade esquerda
    int j = 0; //índice para percorrer os elementos da metade direita
    int k = inicio; //define a posição inicial onde os valores serão colocados no vetor original

//continua comparando enquanto existirem elementos nas duas metades
while (i < tamanho1 && j < tamanho2) {
        comparacoes++; //Aumenta o contador porque será feita uma comparação entre dois valores

        //Verifica se o elemento da esquerda é menor ou igual ao elemento da direita
        if (esquerda[i] <= direita[j]) {
        vetor[k] = esquerda[i]; //Coloca o menor elemento da esquerda na posição k
        i++; // Avança para o próximo elemento da metade esquerda
        }
    else {
    vetor[k] = direita[j]; //Coloca o menor elemento da direita na posição k
    j++; // Avança para o próximo elemento da metade direita
     }
       k++; //Avança para a próxima posição disponível no vetor original

        movimentacoes++; //Conta a cópia realizada para o vetor original
    }

    //verifica se ainda existem elementos sobrando na metade esquerda
    while (i < tamanho1) {
    vetor[k] = esquerda[i]; //opia o elemento restante da esquerda para o vetor original
    i++; //Avança para o próximo elemento da esquerda
    k++; //Avança para a próxima posição do vetor
    movimentacoes++; //Conta a movimentação do elemento
    }

//verifica se ainda existem elementos sobrando na metade direita
while (j < tamanho2) {
     vetor[k] = direita[j]; //Copia o elemento restante da direita para o vetor original
 j++; //Avança para o próximo elemento da direita
k++; //Avança para a próximo posição do vetor original
     movimentacoes++; //conta a movimentação
    }
}

//função recursiva que divide o vetor em partes menores e ordena
void mergeSort(int vetor[], int inicio, int fim,int &comparacoes, int &movimentacoes) {

//verifica se a parte do vetor possui mais de um elemento Se inicio for igual a fim ett existe apenas um elemento
if (inicio < fim) {
    //calcula o índice central para dividir o vetor em duas partes
    int meio = inicio + (fim - inicio) / 2;

    //chama a própria função para ordenar a metade esquerda
    mergeSort(vetor, inicio, meio, comparacoes, movimentacoes);

    //chama a própria função para ordenar a metade direita
     mergeSort(vetor, meio + 1, fim, comparacoes, movimentacoes);

    //junta as duas metades que foram ordenadas
    intercalar(vetor, inicio, meio, fim, comparacoes, movimentacoes);

 }
}

//função responsável de exibir os elementos do vetor
void mostrarVetor(int vetor[], int tamanho) {

//percorre todas as posições do vetor
    for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " "; //exibe o elemento da posição atual
}

cout << endl; 
}

int main() {
    int vetor[] = {5, 3, 8, 1, 4}; //Cria o vetor 
    int tamanho = 5; //guarda a quantidade de elementos 
    int comparacoes = 0; //inicializa o contador de comparações com zero
    int movimentacoes = 0; //inicializa o contador de movimentações com zero

cout << "Vetor inicial: "; 
mostrarVetor(vetor, tamanho); //mostra os elementos antes da ordenação

//vhama o Merge Sort passando o primeiro e o último índice do vetor
mergeSort(vetor, 0, tamanho - 1, comparacoes, movimentacoes);

    cout << "Vetor ordenado: "; 
    mostrarVetor(vetor, tamanho); //mostra os elementos depois da ordenação

    //mostra o número total de comparações 
    cout << "Comparacoes: " << comparacoes << endl;

    //MergeSort não realiza trocas diretas entre elementos
    cout << "Trocas: 0" << endl;

    //nostra as movimentaçõesnrealizadas 
    cout << "Movimentacoes: " << movimentacoes << endl;

return 0;
}