#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float medidaArestas;
}Cubo;

void preencherMedidaCubo(Cubo *p){
    printf("Qual a medida das arestas do cubo? ");
    scanf("%f", &(p->medidaArestas));
}

void imprimirTamanho(Cubo *p){
    printf("\nO tamanho de cada lado do cubo eh de %.2f", p->medidaArestas);
}

void calcArea(Cubo *p){
    float area;

    area = (p->medidaArestas*p->medidaArestas) * 6;

    printf("\nA area total do cubo eh de %.2f", area);
}

void calcVolume(Cubo *p){
    float volume;
    volume = p->medidaArestas*p->medidaArestas*p->medidaArestas;

    printf("\nO volume do cubo eh de %.2f", volume);
}

int main1(){
    Cubo *p_Cubo = (Cubo *)malloc(sizeof(Cubo));

    preencherMedidaCubo(p_Cubo);
    imprimirTamanho(p_Cubo);
    calcArea(p_Cubo);
    calcVolume(p_Cubo);

    free(p_Cubo);

    return 0;
}