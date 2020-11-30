#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Struct Ranking
typedef struct {
    char nome[100];
    char guild[100];
}Ranking;

// Struct Menu
typedef struct{
    int n, count;
}Menu;

// Struct Pergunta/Resposta
typedef struct{
    char ask[200];
    char answer[200];
}Ask;

// Function Ranking
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
    // Variaveis e Criação de vetor
    Menu menu;
    Ranking rank;
    Ask perg[10];
    Ask resp[10];
    char resposta[10] = {'a', 'c', 'd', 'd', 'a', 'x', 'x', 'x', 'x', 'x'};

    int i=0, a = 0, end = 0;
    char r[10];
    menu.count = 0;

    // Vetores de pergunta e resposta.
    strcpy(perg[0].ask, "Qual e o sinal de atribuicao?\n\n"
                        "a: =\n"
                        "b: ==\n"
                        "c: ===\n"
                        "d: ?\n"
                        "e: !=");
    strcpy(perg[1].ask, "HTML e uma linguagem de ________?\n\n"
                        "a: atribuicao\n"
                        "b: programacao\n"
                        "c: marcacao\n"
                        "d: boolean\n"
                        "e: portugues");
    strcpy(perg[2].ask, "Um programador está criando o menu principal da página de abertura de um site, que conterá o bloco principal de links de navegação."
                        " Considerando os elementos semânticos da linguagem HTML5, estes links devem ficar imediatamente no interior da tag \n\n"
                        "a: <mark>\n"
                        "b: <progress>\n"
                        "c: <choose>\n"
                        "d: <nav>\n"
                        "e: <navigation>");
    strcpy(perg[3].ask, "Na linguagem HTML, o elemento que é um recipiente para todos os elementos do cabeçalho, em que se podem incluir scripts, instruir "
                        "o navegador onde encontrar folhas de estilo, fornecer informações de metadados, e muito mais, é a tag:\n"
                        "a: <base>\n"
                        "b: <doctype>\n"
                        "c: <link>\n"
                        "d: <head>\n"
                        "e: <script>");
    strcpy(perg[4].ask, "Qual das alternativas a seguir apresenta somente tipos de dados básicos da linguagem C?\n\n"
                        "a: char, int e float.\n"
                        "b: string, double e int,\n"
                        "c: boolean, string e float.\n"
                        "d: char, boolean e int.\n"
                        "e: string, float e int.");
    strcpy(perg[5].ask, "Na linguagem C, para manipular um número real com 8 bytes de tamanho que possa assumir valores"
                        " negativos, é preciso declarar uma variável do tipo\n\n"
                        "a: double.\n"
                        "b: signed float\n"
                        "c: unsigned int.\n"
                        "d: long.\n"
                        "e: int.");
    strcpy(perg[6].ask, "Referente a alocação dinâmica de memória em C, é CORRETO afirmar:\n\n"
                        "a: As funções malloc e free e o operador sizeof, são essenciais para a alocação dinâmica de memória.\n"
                        "b: A função malloc usa o número de blocos de memória que serão alocados na memória.\n"
                        "c: As funções calloc e realloc são usadas para liberar arays.\n"
                        "d: A função clear é usada para limpar o conteúdo de um ponteiro.\n"
                        "e: A função free é geralmente usada com o operador sizeof.");
    strcpy(perg[7].ask, "Em C, o tipo de dado long double, tem sua especificação de conversão para printf e scanf respectivamente:\n\n"
                        "a: f e f\n"
                        "b: Lf e Lf\n"
                        "c: d e d\n"
                        "d: Ld e Ld\n"
                        "e: LD e LD");
    strcpy(perg[8].ask, "Acerca de linguagens de programação e ferramentas de desenvolvimento, julgue o item subsecutivo.\n"
                        "Objective-C, linguagem de programação que estende a linguagem C, oferece recursos orientados a objetos,"
                        " em que os métodos são chamados diretamente em um objeto.\n\n"
                        "a: certo\n"
                        "b: errado");
    strcpy(perg[9].ask, "Na linguagem C, o cabeçalho de biblioteca stdio.h possui definições de subrotinas relativas às operações de entrada/saída"
                        " padrão. Uma das funções tratadas na biblioteca, associada a esse cabeçalho, é a função:\n\n"
                        "a: atoi.\n"
                        "b: trunc.\n"
                        "c: scanf.\n"
                        "d: strcpy.\n"
                        "e: locatime.");
    strcpy(resp[0].answer, "a");
    strcpy(resp[1].answer, "c");
    strcpy(resp[2].answer, "d");
    strcpy(resp[3].answer, "d");
    strcpy(resp[4].answer, "a");
    strcpy(resp[5].answer, "a");
    strcpy(resp[6].answer, "a");
    strcpy(resp[7].answer, "b");
    strcpy(resp[8].answer, "b");
    strcpy(resp[9].answer, "c");


    do{
        // MENU INICIAL
        puts("--------------------------------");
        puts("          SHOW DO MILHAO \n");
        puts("Escolha uma opcao!");
        puts("1- INICIAR JOGO");
        puts("2- RANKING");
        puts("3- CREDITOS");
        puts("4- SAIR");
        printf("R-> ");

        // Input de Escolha do menu.
        scanf("%d", &menu.n);
        system("clear||cls");
        
        switch (menu.n){
            case 1: // INICIAR JOGO
                for(i=0; i < 10; i++){
                    int pnum = i + 1; // # Pergunta ( n + 1)
                    
                    // Pegando valor da resposta e Printando a pergunta.
                    printf("#%d ", pnum);
                    printf("%s\n", perg[i].ask);
                    printf("R-> ");

                    // Input da reposta.
                    scanf("%s", &r);
                    setbuf(stdin, NULL);

                    if(strcmp(resp[i].answer, r) == 0){
                        // If de comparação da string resposta com a entrada do input.
                        printf("\n########## ACERTOU ##########\n");
                        menu.count++;

                        if(menu.count == 10){ // Condição se Entrou para o ranking.
                            system("cls||clear");

                            // Mensagem de Congratulations
                            puts("#############################");
                            puts("######   PARABEEEEENS  ######");
                            puts("######    VOCE ENTROU  ######");
                            puts("######   PRO RANKING   ######");
                            puts("#############################\n");

                            // Input nome
                            printf("Nome: ");
                            fflush(stdin);
                            gets(rank.nome);

                            // Input Guild
                            printf("Guild: ");
                            fflush(stdin);
                            gets(rank.guild);

                            //Escrita em binário
                            FILE *f = fopen("rank.bin", "ab"); // Fopen devolve um * por isso *f
                            fwrite(&rank, 200, 1, f); // Escreve o rank
                            fclose(f); // Fecha um ponteiro de arquivo aberto

                        }else{ // Não entrou para o ranking.
                            printf("Voce acertou %d perg(s)", menu.count);
                            Sleep(800);
                            system("cls||clear");
                        }
                    }else{
                        // Condição que errou a resposta.
                        printf("\n########## ERROU ##########\n");
                        printf("Voce acertou %d perg(s)", menu.count);
                        Sleep(800);
                        system("cls||clear");
                        i=11; // PARA SAIR DO FOR
                    }      
                }

                Sleep(1000);
                
                // Condition para abrir o menu novamente.
                printf("\nDigite 1 se deseja continuar: ");
                scanf("%d", &end);
                if(end == 1){
                    // Mostra novamente o menu.
                    system("cls||clear");
                }else{
                    // Fecha o game.
                    system("cls||clear");
                    puts("#############################");
                    puts("#############################");
                    puts("######   Fim do jogo!  ######");
                    puts("#############################");
                    puts("#############################");
                    end = 0;
                }
            break; // END JOGO
            case 2: // RANKING
                ranking();
                Sleep(1000);

                // Condition para abrir o menu novamente.
                printf("\nDigite 1 se deseja continuar: ");
                scanf("%d", &end);
                if(end == 1){
                    // Mostra novamente o menu.
                    system("cls||clear");
                }else{
                    // Fecha o game.
                    system("cls||clear");
                    puts("#############################");
                    puts("#############################");
                    puts("######   Fim do jogo!  ######");
                    puts("#############################");
                    puts("#############################");
                    end = 0;
                }   
            break; // END RANKING
            case 3: // CREDITOS
                puts("######  #####  ######  #####  ##  ######  ####   # # # ");  
                puts("###     ## ##  ###     #  ##  ##    #     #  #    #    ");
                puts("###     ## ##  ###     #  ##  ##    #     #  #      #  ");
                puts("######  ##  #  ######  #####  ##    #     ####   # # # \n");

                puts("Rubens Alexandre Menezes Cordeiro de Melo Filho - 23668385");
                puts("Andre Rodrigo Nobrega Goncalves - 23742372");
                puts("Ashyla Marla Cavalcanti Ferreira - 23241055");


                Sleep(1000);
                printf("\nDigite 1 se deseja continuar: ");
                scanf("%d", &end);
                if(end == 1){
                    system("cls||clear");
                }else{
                    system("cls||clear");
                    puts("#############################");
                    puts("#############################");
                    puts("######   Fim do jogo!  ######");
                    puts("#############################");
                    puts("#############################");
                    end = 0;
                }
            break; // END CREDITOS
            case 4: // SAIR
                puts("#############################");
                puts("#############################");
                puts("######   Fim do jogo!  ######");
                puts("#############################");
                puts("#############################");
                Sleep(3000);
                end = 0;
            break; // END SAIR
            default:
                printf("Escolha uma opcao valida\n");
                end = 1;
            break;
        }
        

    }while(end == 1); // Condition se Continua ou não executando o jogo.
    
}
