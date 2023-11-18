#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Num_complexo;

void criarNumComplexo(Num_complexo* z){
    printf("Insira o valor real:");
    scanf("%d", &z->x);
    printf("Insira a parte imaginaria:");
    scanf("%d", &z->y);
}

void destruirNumComplexo(Num_complexo** z){
    if(*z != NULL){
        free(*z);
        *z = NULL;
    }
}


void somaNumCompl(Num_complexo* x, Num_complexo* y){
    int soma1;
    int soma2;

    soma1 = (x->x + y->x);
    soma2 = (x->y + y->y);

    if (soma2 < 0){
        printf("o resultado da soma dos numeros eh %d - %di\n", soma1, soma2*-1);
    }else{
        printf("o resultado da soma dos numeros eh %d + %di\n", soma1, soma2);
    }

}

void subtracaoNumCompl(Num_complexo* x, Num_complexo* y){
    int sub1;
    int sub2;

    sub1 = (x->x - y->x);
    sub2 = (x->y - y->y);

    if (sub2 < 0){
        printf("o resultado da soma dos numeros eh %d - %di\n", sub1, sub2*-1);
    }else{
        printf("o resultado da soma dos numeros eh %d + %di\n", sub1, sub2);
    }
}


void multNumCompl(Num_complexo* x, Num_complexo* y){
    int mult1 = ((x->x*y->x) - (x->y*y->y));
    int mult2 = ((x->x*y->y) + (y->x*x->y));

    if (mult2 < 0){
        printf("o resultado da multiplicacao dos numeros eh %d - %di\n", mult1, mult2*-1);
    }else{
        printf("o resultado da multiplicacao dos numeros eh %d + %di\n", mult1, mult2);
    }
}

void divisaoNumCompl(Num_complexo *x, Num_complexo *y) {
    if (y->x == 0 && y->y == 0) {
        printf("Não é possível dividir por zero.\n");
        return;
    }

    double div1 = (double) (x->x * y->x + x->y * y->y) / (y->x * y->x + y->y * y->y);
    double div2 = (double) (y->x * x->y - x->x * y->y) / (y->x * y->x + y->y * y->y);

    if (div2 < 0) {
        printf("O resultado da divisao dos numeros eh %.2lf - %.2lfi\n", div1, - div2);
    } else {
        printf("O resultado da divisao dos numeros eh %.2lf + %.2lfi\n", div1, div2);
    }
}


int main(){

    Num_complexo* p_x = (Num_complexo*)malloc(sizeof(Num_complexo));
    Num_complexo* p_y = (Num_complexo*)malloc(sizeof(Num_complexo));


    printf("num complexo Z1\n");
    criarNumComplexo(p_x);

    printf("num complexo Z2\n");
    criarNumComplexo(p_y);

    somaNumCompl(p_x, p_y);

    subtracaoNumCompl(p_x, p_y);

    multNumCompl(p_x, p_y);

    divisaoNumCompl(p_x, p_y);

    destruirNumComplexo(&p_x);
    destruirNumComplexo(&p_y);

    return 0;
}