#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reconhecedor_0x1(char * s);
int reconhecedor_0x1_rec(char * s, int n);

int main (int argc, char ** argv) {

    char w[100];

    if(argc == 1) strcpy(w, "\0");
    else strcpy(w, argv[1]);

    printf("%s\n", reconhecedor_0x1_rec(argv[1], strlen(argv[1])) ? "ACEITA" : "REJEITA" );
    return 0;

}

int reconhecedor_0x1(char * s) {

    int i = 0;
    int n0 = 0; //quantidade de zeros no inicio de s
    int n1 = 0; // quantidade de zeros no final de s

    if (s == NULL) return 1;

    while (s[i] == '0') {
        n0++;
        i++;
    }  // para contar a quantiade de zeros no inicio da palavra

    while (s[i] == '1') {
        n1++;
        i++;
    }  // para contar a quantidade de uns no final da palavra

    if(s[i] != '\0') return 0;
    return n0 == n1;

    int reconhecedor_0x1_rec(char * s, int n){

        if (n == 0) return 1; //palavra vazia
        if (n == 1) return 0; //palavra de tamanhos 1 não pertencem a linguagem
        if (s[0] != 0 || s[n-1] != '1') return 0;
        return reconhecedor_0x1_rec(s + 1, n - 2);
    }    
}