// Feito por João Viníxius Oliveira Alves
// Turma de POO - SI 2021.2
//Pofessor David Sena
// - FILA DOS ESTRESSADOS-
#include <iostream>
#include <stdbool.h>
#include <vector>
using namespace std;
bool existe(int vet[], int tamanho_vetor, int x) // função de busca de valor X - vet[] corresponde ao nome de um vetor - tamanho_vetor corresponde ao tamanho ou "size" do vetor - x corresponde ao valor ou "value" a ser buscado.
{
    for (int i = 0; i < tamanho_vetor; i++){ // enquanto i for menor que o tamanho do vetor, recebera +1.
        if (x == vet[i]){ // se x existir dentro do vetor, retornara verdadeiro(1).
            return true;
        }
    }
    return false; // se não existir, retornara falso(0).
}

int contar(int vet[], int tamanho_vetor, int x) // Função para descobrir quantas vezes o x aparece dentro do vetor.
{
    int y = 0; // inicializando a variavel y que vai ser usada pra guardar o valor de quantas vezes o x aparece no vetor.
    for (int i = 0; i < tamanho_vetor; i++){
        if (x == vet[i]){
               y++;
           }
           
    }
    return y;
}

int procurar_valor(int vet[], int tamanho_vetor, int x) // Função para descobrir qual posição o valor X está ocupando dentro do vetor.
{
    int i;
    for (i = 0; i < tamanho_vetor; i++){
        if (x == vet[i]){
            break; // Pausa na busca.
        }
    }
    if (i < tamanho_vetor){
        cout << "Posicao do X no vetor: " << i << endl;
        return 0;
    } else {
        return -1; // Se o valor X não estiver presente no vetor, será exibido valor -1.
    }
}

int procurar_valor_apartir(int vet[],int tamanho_vetor, int x, int y) // Função para descobrir em qual posição aparece o X a partir de uma posição Y
{
    int i;
    int j; // contador para posição de X.
    i = y; // Y é a posição a partir de onde sera feita a busca pelo X dentro do vetor.
    j = y; // igualando j e i ao valor da posição no qual será iniciada a busca.
    int result;
    for (i; i < tamanho_vetor; i++){ // estruturas de repetição for usadas para buscar o valor x a partir da posição y dentro do vetor
        for (j; j < tamanho_vetor; j++){
            if (x == vet[j]){
                result = j;
                break; // Pausa na busca.
            }
        }
    }
    if (j < tamanho_vetor){
        cout << "Posicao de " << x << " no vetor a partir da posicao " << y << ": " << result << endl;
        return 0;
    } else {
        return -1; // Se o valor X não estiver presente no vetor, será exibido valor -1.
    }
}

int procurar_menor(int vet[], int tamanho_vetor) // Função para descobrir o menor valor dentro do vetor.
{
    int menor = vet[0]; // variavel que vai armazenar o menor valor dentro do vetor.
    for (int i = 1; i < tamanho_vetor; i++){
        if (vet[i] < menor){ // condição se "valor x" menor que o valor da posição 0, variavel menor receberá o novo valor de dentro do vetor.
            menor = vet[i];
            
        }
    }
    cout << "Menor valor dentro do vetor: " << menor << endl;
    return 0;
}

int procurar_menor_pos(int vet[], int tamanho_vetor) // Função para descobrir a posição do menor valor dentro do vetor.
{
    int posicaomenor = vet[0]; // Variavel que vai armazenar o valor da posição
    for (int i = 1; i < tamanho_vetor; i++){
        if (vet[i] < posicaomenor){
            posicaomenor = i;
            
        }
    }
    cout << "Posicao do menor valor dentro do vetor: " << posicaomenor << endl;
    return 0;
}

int procurar_menor_pos_apartir(int vet[], int tamanho_vetor, int y)
{
    int posicaomenor = vet[0];
    for (int i = y; i < tamanho_vetor; i++){
        if (vet[i] < posicaomenor){
            posicaomenor = i;
        }
    }
    cout << "Posicao do menor valor dentro do vetor a partir da posicao " << y << " : " << posicaomenor << endl;
    return 0;
}

int procurar_melhor_se(int vet[], int tamanho_vetor)
{
    int posicaomenor = vet[0];
    for (int i = 1; i < tamanho_vetor; i++){
        if (vet[i] < posicaomenor && vet[i] > 0){
            posicaomenor = i;
            cout << "Posicao do Homem menos estressado dentro do vetor: " << posicaomenor << endl;
            return 0;
            break;
        } else {
            return -1;
        }
    }
}

int mais_homens_ou_mulheres(int vet[], int tamanho_vetor)
{
    int mulher = 0; // Variavel para armazenar a quantidade de mulheres.
    int homem = 0; // Variavel para armazenar a quantidade de homens.
    for (int i = 0; i < tamanho_vetor; i++){ // Laço de repetição pra contagem de quantas mulheres existem na fila, lembrando que as mulheres são representadas pelos valores negativos.
        if (vet[i] < 0){
            mulher++;
        }
    }
    for (int i = 0; i < tamanho_vetor; i++){ // Laço de repetição pra contagem de quantos Homens existem na fila, lembrando que os Homens são representados pelos valores positivos.
        if (vet[i] > 0){
            homem++;
        }
    }
    if (mulher > homem){
        cout << "Existem " << mulher << " mulheres na fila!" << endl;
        return 0;
    } else if (homem > mulher){
        cout << "Existem " << homem << " Homens na fila!" << endl;
        return 0;
    } else {
        cout << "Houve um empate entre a quantidade de homens e mulheres na fila!" << endl;
        return 0;
    }
}

int main()
{
    int tamanho = 6;
    int fila[tamanho] = {5, 3, -1, -50, -1, -99};
    
    cout << existe(fila, tamanho,5) << endl; //"Verificando se existe um valor X: "
    cout << contar(fila, tamanho, -1) << endl; //"Verificando quantas vezes o valor X aparece dentro do vetor: "
    cout << procurar_valor(fila, tamanho, -50) << endl; //"Verificando em qual posição o valor X aparece dentro do vetor:"
    cout << procurar_valor_apartir(fila, tamanho, -1, 0) << endl; //"Verificando em qual posição o valor X aparece dentro do vetor a partir de uma posição Y".
    cout << procurar_menor(fila, tamanho) << endl; //"Verificando qual o menor valor dentro do vetor".
    cout << procurar_menor_pos(fila, tamanho) << endl; //"Verificando qual a posição do menor valor dentro do vetor".
    cout << procurar_menor_pos_apartir(fila, tamanho, 3) << endl; //"Verificando qual a posição do menor valor dentro do vetor a partir de uma posição Y".
    cout << procurar_melhor_se(fila, tamanho) << endl; //"Verificando a posição do homem mais calmo (menor valor maior que 0) na fila".
    cout << mais_homens_ou_mulheres(fila, tamanho) << endl; //"Verificando quantas mulheres e quantos homens existem na fila".
    return 0;
}