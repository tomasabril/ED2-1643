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

int d=1;            /// 0 saidas de debug. 1 saida padrao

//variaveis globais
unsigned long long n;              //quantos numeros serao lidos
unsigned long long km[25000];      //numeros em kms
unsigned long long kmF[25000];     //km no modo fibonacci
unsigned long long ml[25000];      //milhas
unsigned long long mlF[25000];     //milhas em modo fibonacci
unsigned long long fib[25000];     //a sequencia de fibonacci
unsigned long long maior=0;        //maior km lido

//funcoes
void lerdist();         //ler distancias
void calculaFibs();
void shiftEsq();
void calculaMilha();    // transforma milhas do formato fibonacci para a quantidade certa
void print();
unsigned long long intlen(unsigned long long x);

int main()
{
    scanf("%llu", &n);
    for(unsigned long long i=0; i<=n; i++) {    // zera tudo que precisa ser zerado
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
    unsigned long long tmp, i;
    for(i=0; i<n; i++) {
        scanf("%llu", &tmp);
        km[i] = tmp;
        if(tmp>maior) maior=tmp;
        d? :printf("km[%llu]: %llu\n", i, km[i]);
    }
    d? :printf("n: %llu\n", n);
    d? :printf("maior: %llu\n", maior);
}

void calculaFibs()
{
    // calcula todos os fibonaccis necessarios
    unsigned long long i=1;
    unsigned long long j;
    fib[0]=1;
    fib[1]=2;
    while(fib[i] <= maior) {
        fib[i+1] = fib[i] + fib[i-1];
        i++;
    }
    //
    for(i=0; i<n; i++) {
        j=0;
        d? :printf("km[%llu]: %llu\n", i, km[i]);
        while(km[i] > fib[j]) {
            d? :printf("fib[%llu]: %llu\n", j, fib[j]);
            j++;   // acha o > fibci <= ao numero
        }
        if(km[i] < fib[j]) j--;
        d? :printf("fib[%llu]: %llu\n", j, fib[j]);
        d? :printf("j: %llu\n", j);
        while(km[i]!=0) {
            if(km[i] >= fib[j]) {
                kmF[i] += 1 * ceil(  pow(10,j) );
                km[i] -= fib[j];
            }
            j--;
        }
        d? :printf(" kmF: %llu \n", kmF[i]);
    }

}

void shiftEsq()
{
    d? :printf("shift esquerda\n");
    unsigned long long i;
    for(i=0; i<n; i++) {
        mlF[i] = kmF[i] /10;
        d? :printf(" kmF: %llu  mlF: %llu \n", kmF[i], mlF[i]);
    }
}

void calculaMilha()         // transforma milhas do formato fibonacci para a quantidade certa
{
    d? :printf("calculando milha\n");
    unsigned long long i, tam, j=0;
    for(i=0; i<n; i++) {
            j = 0;
        tam = intlen(mlF[i]);
        while(tam > 0) {
            if ((mlF[i]-1)%10 == 0)
                ml[i] += fib[j];
            tam--;
            mlF[i] = mlF[i]/10;
            j++;
        }

    }
}

unsigned long long intlen(unsigned long long x)       // retorna quantos digitos o numero tem;
{
    unsigned long long length = 1;
    while ( x /= 10 )
        length++;
    return length;
}

void print()
{
    unsigned long long i;
    for(i=0; i<n; i++) {
        printf("%llu\n", ml[i]);
    }
}


