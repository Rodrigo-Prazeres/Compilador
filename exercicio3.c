#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definindo o TAD Árvore

int reconhecedor ( char * Palavra ,int N);


int main(int argc, char ** argv) {

    char * P = (argc == 2 ) ? argv[1] : "";
    int Resposta = reconhecedor(P, strlen(P));
    printf("%s\n", Resposta ? "ACEITA": "REJEITA");
    return 0;


}


int reconhecedor(char * Palavra , int N){

    if (N == 0) return 1;
    if (N == 1) return 0;
    if (Palavra[0] == '0' && Palavra[N -1] == '0') return reconhecedor(Palavra + 1, N - 2); //Regra R1
    if (Palavra[0] == '1' && Palavra[N -1] == '1') return reconhecedor(Palavra + 1, N - 2); //Regra R2
    return 0;

}