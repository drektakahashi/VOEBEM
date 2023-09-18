#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Voo{
    int numVoo;
    char dataVoo[20];
    char horarioVoo[20];
    char aeroportoSaida[30];
    char aeroportoChegada[30];
    char route[30];
    float tempoVoo;
    int passageirosAbordo;
    int remocao;
};

void cadastroVoo(struct Voo *voo, int quantVoo)
{

    printf("\n\n<--Cadastro de Voo empresa VOEBEM<--\n");
    for(int a=0;a<quantVoo;a++){

        printf("Numero do Voo: ");
        scanf("%d", &voo[a].numVoo);

        printf("Data do Voo: ");
        fflush(stdin);
        fgets(voo[a].dataVoo, sizeof(voo[a].dataVoo), stdin);
        voo[a].dataVoo[strcspn(voo[a].dataVoo,"\n")]='\0';

        printf("Horario do Voo: ");
        fflush(stdin);
        fgets(voo[a].horarioVoo, sizeof(voo[a].horarioVoo), stdin);
        voo[a].horarioVoo[strcspn(voo[a].horarioVoo,"\n")]='\0';

        printf("Aeroporto de Saida: ");
        fflush(stdin);
        fgets(voo[a].aeroportoSaida, sizeof(voo[a].aeroportoSaida), stdin);
        voo[a].aeroportoSaida[strcspn(voo[a].aeroportoSaida,"\n")]='\0';

        printf("Aeroporto de Chegada: ");
        fflush(stdin);
        fgets(voo[a].aeroportoChegada, sizeof(voo[a].aeroportoChegada), stdin);
        voo[a].aeroportoChegada[strcspn(voo[a].aeroportoChegada,"\n")]='\0';

        printf("Qual a rota do aviao(Direto ou Escala): ");
        fflush(stdin);
        fgets(voo[a].route, sizeof(voo[a].route), stdin);
        voo[a].route[strcspn(voo[a].route,"\n")]='\0';

        printf("Tempo de Voo (horas): ");
        scanf("%f", &voo[a].tempoVoo);

        printf("Passageiros no Voo: ");
        scanf("%d", &voo[a].passageirosAbordo);

        printf("\n");
    }

}

void consultarVoo(struct Voo *voos, int quantVoo)
{
    int find = 0;
    int consulta;
    printf("Numero do Voo que deseja consultar: ");
    scanf("%d", &consulta);

    for(int a=0;a<quantVoo;a++)
    {
        //
        if(voos[a].numVoo==consulta)
        {
            printf("\nEMPRESA VOEBEM\n");
            printf("Consulta de cadastro do Voo %d \n", consulta);
            printf("Data do Voo: %s\n", voos[a].dataVoo);
            printf("Horario do Voo: %s\n", voos[a].horarioVoo);
            printf("Aeroporto de Saida: %s\n", voos[a].aeroportoSaida);
            printf("Aeroporto de Chegada: %s\n", voos[a].aeroportoChegada);
            printf("Rota do Aviao: %s\n", voos[a].route);
            printf("Tempo de Voo: %.2f horas\n", voos[a].tempoVoo);
            printf("Passageiros no Voo: %d pessoas\n", voos[a].passageirosAbordo);
            find = 1;
            break;
        }
    }
    if(find == 0)
    {
        printf("\nNumero de Voo nao encontrado!\n");
    }
}

void removerVoo(struct Voo *voos, int quantVoo){
    int find = 0;
    int remover;
    printf("Numero do Voo que gostaria de remover: ");
    scanf("%d", &remover);

    for(int a=0;a<quantVoo;a++){
        if(voos[a].numVoo == remover){
            voos[a].numVoo = 0;
            printf("Voo removido com sucesso!\n");
            find = 1;
            break;
        }
    }
    if(find == 0)
    {
        printf("\nNumero de Voo nao encontrado!\n");
    }
}

main()
{
    struct Voo *voos;
    int quantVoo = 0;
    int op;

    while(op!=4){

        printf("\n---->Cadastrar Voos<----\n");
        printf("\n[1] - Cadastrar.................");
        printf("\n[2] - Consultar.................");
        printf("\n[3] - Remover...................");
        printf("\n[3] - Sair......................");

        printf("\n\nEscolha a opcao: ");
        scanf("%d", &op);
        fflush(stdin);

        switch(op)
        {
        case 1:
            printf("\nQuant de Voo que serao cadastrados: ");
            scanf("%d", &quantVoo);

            voos = (struct Voo *)malloc(quantVoo * sizeof(struct Voo));

            if (voos == NULL) {
                printf("Memoria insuficiente :( !! ");
                return 1;
            }
            cadastroVoo(voos, quantVoo);
            break;
        case 2:
            if(quantVoo==0){
                printf("\nNenhum Voo cadastrado\n");
            } else {
                consultarVoo(voos, quantVoo);
            }
            break;
        case 3:
            removerVoo(voos, quantVoo);
            break;
        case 4:
            printf("Leaving software.. ");
            return 0;
        default:
            printf("Opcao invalida, tente novamente.");

        }
    }

    //ultilizando o malloc
    voos = (struct Voo*) malloc(sizeof(struct Voo));

    //tratamento de erro
    if(voos == NULL){
        printf("Memoria insuiciente :( !! ");
        return 1;
    }


}
