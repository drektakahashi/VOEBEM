#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Voo{
    int numVoo;
    char dataVoo[20];
    char horarioVoo[20];
    char aeroportoOut[50];
    char aeroportoArrive[50];
    char route[20];
    float timeRoute;
    int passengers;
};

main()
{
    //puxando a variavel p/ uso
    struct Voo *voo;

    //ultilizando o malloc
    voo = (struct Voo*) malloc(sizeof(struct Voo));

    //tratamento de erro
    if(voo == NULL){
        printf("Memoria insuiciente :( !! ");
        return 1;
    }


    //liberando memoria ultilizada
    free(voo);
}
