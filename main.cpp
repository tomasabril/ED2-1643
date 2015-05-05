/// Tomas Abril
/// Willian Drayton Alves
/// Stefany Aoto Rojas Ruiz
/// Yasmin Pegoraro

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <time.h>
#include <math.h>

//using namespace std;

int d=0;            /// 0 saidas de debug. 1 saida padrao

//variaveis globais
int n;              //quantos numeros serao lidos
int km[25000];      //numeros em kms
int kmF[25000];     //km no modo fibonacci
int ml[25000];      //milhas
int mlF[25000];     //milhas em modo fibonacci
int fib[25000];     //a sequencia de fibonacci
int maior=0;        //maior km lido

//funcoes
void lerdist();         //ler distancias
void calculaFibs();
void shiftEsq();
void calculaMilha();    // transforma milhas do formato fibonacci para a quantidade certa
void print();
int intlen(int x);

int main()
{
    scanf("%d", &n);
    for(int i=0; i<=n; i++) {    // zera tudo que precisa ser zerado
        km[i]  = 0;
        kmF[i] = 0;
        ml[i]  = 0;
        mlF[i] = 0;
        fib[i] = 0;
    }
    lerdist();
    calculaFibs();
    shiftEsq();
    calculaMilha();
    print();

    return 0;
}

void lerdist()
{
    int tmp, i;
    for(i=0; i<n; i++) {
        scanf("%d", &tmp);
        km[i] = tmp;
        if(tmp>maior) maior=tmp;
        d? :printf("km[%d]: %d\n", i, km[i]);
    }
    d? :printf("n: %d\n", n);
    d? :printf("maior: %d\n", maior);
}

void calculaFibs()
{
    // calcula todos os fibonaccis necessarios
    int i=1;
    int j;
    fib[0]=1;
    fib[1]=2;
    while(fib[i] <= maior) {
        fib[i+1] = fib[i] + fib[i-1];
        i++;
    }
    //
    for(i=0; i<n; i++) {
        j=0;
        d? :printf("km[%d]: %d\n", i, km[i]);
        while(km[i] > fib[j]) {
            d? :printf("fib[%d]: %d\n", j, fib[j]);
            j++;   // acha o > fibci <= ao numero
        }
        if(km[i] < fib[j]) j--;
        d? :printf("fib[%d]: %d\n", j, fib[j]);
        d? :printf("j: %d\n", j);
        while(km[i]!=0) {
            if(km[i] >= fib[j]) {
                kmF[i] += 1 * ceil(  pow(10,j) );
                km[i] -= fib[j];
            }
            j--;
        }
        d? :printf(" kmF: %d \n", kmF[i]);
    }

}

void shiftEsq()
{
    d? :printf("shift esquerda\n");
    int i;
    for(i=0; i<n; i++) {
        mlF[i] = kmF[i] /10;
        d? :printf(" kmF: %d  mlF: %d \n", kmF[i], mlF[i]);
    }
}

void calculaMilha()         // transforma milhas do formato fibonacci para a quantidade certa
{
    d? :printf("calculando milha\n");
    int i, tam;
    for(i=0; i<n; i++) {
        tam = intlen(mlF[i]);
        while(tam > 0) {
            if( mlF[i] / (int)ceil(pow(10,tam-1)) == 1) {
                ml[i] += fib[tam-1];
            }
            tam--;
        }
    }
}

int intlen(int x)       // retorna quantos digitos o numero tem;
{
    int length = 1;
    while ( x /= 10 )
        length++;
    return length;
}

void print()
{
    int i;
    for(i=0; i<n; i++) {
        printf("%d\n", ml[i]);
    }
}


