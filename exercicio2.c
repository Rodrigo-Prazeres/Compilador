#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No {
    char Palavra[100];
    struct No * Esquerda;
    struct No * Direita;
}No;

No * criarNo(char * Palavra, char Letra);

int main(int argc, char ** argv) {
    No * Arvore = criarNo("\0", '\0');

    Arvore->Esquerda = criarNo(Arvore->Palavra, '0');
    Arvore->Direita = criarNo(Arvore->Palavra, '1');

}

No * criarNo(char * Palavra, char Letra){
    No * N = (No *) malloc(sizeof(No));

    if (N == NULL) {
        printf("ERRO: não há memória para um novo nó! \n");
        return NULL;
    }

    strcpy(N->Palavra,Palavra);
    int UP = strlen(Palavra); //UP = ultima posição
    N->Palavra[UP] = Letra; 
    N->Palavra[UP+1] = '\0';

    N->Direita = NULL;
    N->Esquerda = NULL;

    return N;

}

