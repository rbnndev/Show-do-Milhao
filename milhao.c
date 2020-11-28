#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct {
    char nome[100];
    char guild[100];
}Ranking;

typedef struct{
    int n, r, laco, count;
}Menu;

typedef struct{
    char ask[200];
    char answer[200];
}Ask;

void ranking(){
    Ranking rank;
    FILE *f = fopen("rank.bin", "rb");

    if(!f){
        printf("Ninguem ainda entrou no ranking.\n");
    }else{
        printf("Ranking:\n");
        while(fread(&rank, sizeof(Ranking), 1, f)){
            printf("Nome: %s\nGuild: %s\n\n", rank.nome, rank.guild);
        }
        fclose(f);
    }   
}

main(void){
    Menu menu;
    Ranking rank;
    Ask perg[10];
    Ask resp[10];

    int i=0, a = 0, end = 0;
    char r[10];
    menu.laco = 1;
    menu.count = 0;
    

    do{
        strcpy(perg[0].ask, "Qual e o sinal de atribuicao?\n\na: =\nb: ==\nc: ===\nd: ?");
        strcpy(perg[1].ask, "HTML e uma linguagem de ________?\n\na: Atribuicao\nb: Programacao\nc:Marcacao\nd: Boolean");
        strcpy(perg[2].ask, "Um programador está criando o menu principal da página de abertura de um site, que conterá o bloco principal de links de navegação. Considerando os elementos semânticos da linguagem HTML5, estes links devem ficar imediatamente no interior da tag\n\na: <mark>\nb: <progress>\nc: <choose>\nd: <nav>\ne: <navigation>");
        strcpy(perg[3].ask, "Na linguagem HTML, o elemento que é um recipiente para todos os elementos do cabeçalho, em que se podem incluir scripts, instruir o navegador onde encontrar folhas de estilo, fornecer informações de metadados, e muito mais, é a tag:\na: <base>\n b: <doctype>\nc: <link>\nd: <head>\ne: <script>");
        strcpy(perg[4].ask, "Qual das alternativas a seguir apresenta somente tipos de dados básicos da linguagem C?\n\na: char, int e float.\nb: string, double e int,\nc: boolean, string e float.\nd: char, boolean e int.\ne: string, float e int.");
        strcpy(perg[5].ask, "\n\na: \nb: \nc: \nd: \ne: ");
        strcpy(perg[6].ask, "\n\na: \nb: \nc: \nd: \ne: ");
        strcpy(perg[7].ask, "\n\na: \nb: \nc: \nd: \ne: ");
        strcpy(perg[8].ask, "\n\na: \nb: \nc: \nd: \ne: ");
        strcpy(perg[9].ask, "\n\na: \nb: \nc: \nd: \ne: ");
        strcpy(resp[0].answer, "a");
        strcpy(resp[1].answer, "c");
        strcpy(resp[2].answer, "d");
        strcpy(resp[3].answer, "d");
        strcpy(resp[4].answer, "a");
        strcpy(resp[5].answer, "x");
        strcpy(resp[6].answer, "x");
        strcpy(resp[7].answer, "x");
        strcpy(resp[8].answer, "x");
        strcpy(resp[9].answer, "x");


        printf("--------------------------------\n");
        printf("          SHOW DO MILHAO \n\n");
        printf("Escolha uma opcao!\n");
        printf("1- INICIAR JOGO\n");
        printf("2- RANKING\n");
        printf("3- CREDITOS\n");
        printf("4- SAIR\n");
        printf("R-> ");
        scanf("%d", &menu.n);
        system("clear||cls");
        
        switch (menu.n){
            case 1: // INICIAR JOGO
                do{
                    for(i=0; i < 10; i++){
                        int pnum = i + 1;
                        
                        printf("#%d ", pnum);
                        printf("%s\n", perg[i].ask);
                        printf("R-> ");
                        scanf("%s", &r);
                        setbuf(stdin, NULL);

                        if(strcmp(resp[i].answer, r) == 0){
                            printf("\n########## ACERTOU ##########\n");
                            menu.count++;

                            if(menu.count == 10){
                                system("cls||clear");
                                printf("Voce entrou para o ranking!\nDigite seu nome e Guild\n\n");

                                printf("#############################\n");
                                printf("######   PARABEEEEENS  ######\n");
                                printf("######    VOCE ENTROU  ######\n");
                                printf("######   PRO RANKING   ######\n");
                                printf("#############################\n\n");
                                printf("Nome: ");
                                fflush(stdin);
                                gets(rank.nome);
                                printf("Guild: ");
                                fflush(stdin);
                                gets(rank.guild);

                                FILE *f = fopen("rank.bin", "ab"); // Fopen devolve um * por isso *f

                                fwrite(&rank, 200, 1, f);

                                fclose(f);

                            }else{
                                printf("Voce acertou %d perg(s)", menu.count);
                                Sleep(800);
                                system("cls||clear");
                            }
                        }else{
                            printf("\n########## ERROU ##########\n");
                            Sleep(800);
                            system("cls||clear");

                            printf("Voce acertou %d perg(s)", menu.count);
                            i=11;
                            menu.laco = 0;
                        }      
                    }
                    menu.laco = 0;
                }while (menu.laco == 1); //Acertando

                Sleep(1000);
                printf("\nDigite 1 se deseja continuar: ");
                scanf("%d", &end);
                if(end == 1){
                    system("cls||clear");
                }else{
                    system("cls||clear");
                    printf("#############################\n");
                    printf("#############################\n");
                    printf("######   Fim do jogo!  ######\n");
                    printf("#############################\n");
                    printf("#############################\n");
                }
            break;
            case 2: // RANKING
                ranking();
                Sleep(1000);
                printf("\nDigite 1 se deseja continuar: ");
                scanf("%d", &end);
                if(end == 1){
                    system("cls||clear");
                }else{
                    system("cls||clear");
                    printf("#############################\n");
                    printf("#############################\n");
                    printf("######   Fim do jogo!  ######\n");
                    printf("#############################\n");
                    printf("#############################\n");
                }
            
            break;
            case 3: // CREDITOS
                printf("CREDITOS");
                Sleep(1000);
                printf("\nDigite 1 se deseja continuar: ");
                scanf("%d", &end);
                if(end == 1){
                    system("cls||clear");
                }else{
                    system("cls||clear");
                    printf("#############################\n");
                    printf("#############################\n");
                    printf("######   Fim do jogo!  ######\n");
                    printf("#############################\n");
                    printf("#############################\n");
                    end = 0;
                }
            break;
            case 4: // SAIR
                printf("#############################\n");
                printf("#############################\n");
                printf("######   Fim do jogo!  ######\n");
                printf("#############################\n");
                printf("#############################\n");
                end = 0;
            break;
            default:
                printf("Escolha uma opcao valida\n");
                end = 1;
            break;
        }
        

    }while(end == 1);
    
}