/// Tomas Abril
/// Willian Drayton Alves
/// Stefany Aoto Rojas Ruiz
/// Yasmin Pegoraro

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

int d=0;            /// 0 saidas de debug. 1 saida padrao

//variaveis globais
int n;
int km[25000];
int ml[25000];
int fib[25000];

//funcoes
void lerdist();
void calculaFibs();
void shiftEsq();
void calculaMilha();
void print();

int main()
{

    return 0;
}

void lerdist(){
    scanf("%d", &n);
    int tmp;
    for(int i=0; i<n; i++){
        scanf("%d", &tmp);
        km[i] = tmp;
    }
    d? :printf("%d n:\n", n);
}
