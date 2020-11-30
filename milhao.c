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
    char ask[300];
    char answer[300];
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

void fim(){
    system("cls||clear");
    puts("#############################");
    puts("#############################");
    puts("######   Fim do jogo!  ######");
    puts("#############################");
    puts("#############################\n");
}

main(void){
    // Variaveis e Criação de vetor
    Menu menu;
    Ranking rank;
    Ask perg[10];
    Ask resp[10];

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
    strcpy(perg[2].ask, "Um programador esta criando o menu principal da pagina de abertura de um site, que contera o bloco principal de links de navegacao."
                        " Considerando os elementos semanticos da linguagem HTML5, estes links devem ficar imediatamente no interior da tag \n\n"
                        "a: <mark>\n"
                        "b: <progress>\n"
                        "c: <choose>\n"
                        "d: <nav>\n"
                        "e: <navigation>");
    strcpy(perg[3].ask, "Na linguagem HTML, o elemento que e um recipiente para todos os elementos do cabecalho, em que se podem incluir scripts, instruir "
                        "o navegador onde encontrar folhas de estilo, fornecer informacoes de metadados, e muito mais, e a tag:\n"
                        "a: <base>\n"
                        "b: <doctype>\n"
                        "c: <link>\n"
                        "d: <head>\n"
                        "e: <script>");
    strcpy(perg[4].ask, "Qual das alternativas a seguir apresenta somente tipos de dados basicos da linguagem C?\n\n"
                        "a: char, int e float.\n"
                        "b: string, double e int,\n"
                        "c: boolean, string e float.\n"
                        "d: char, boolean e int.\n"
                        "e: string, float e int.");
    strcpy(perg[5].ask, "Na linguagem C, para manipular um numero real com 8 bytes de tamanho que possa assumir valores"
                        " negativos, e preciso declarar uma variavel do tipo\n\n"
                        "a: double.\n"
                        "b: signed float\n"
                        "c: unsigned int.\n"
                        "d: long.\n"
                        "e: int.");
    strcpy(perg[6].ask, "Referente a alocacao dinamica de memoria em C, e CORRETO afirmar:\n\n"
                        "a: As funcoes malloc e free e o operador sizeof, sao essenciais para a alocacao dinamica de memoria.\n"
                        "b: A funcao malloc usa o numero de blocos de memoria que serao alocados na memoria.\n"
                        "c: As funcoes calloc e realloc sao usadas para liberar arays.\n"
                        "d: A funcao clear e usada para limpar o conteudo de um ponteiro.\n"
                        "e: A funcao free e geralmente usada com o operador sizeof.");
    strcpy(perg[7].ask, "Em C, o tipo de dado long double, tem sua especificacao de conversao para printf e scanf respectivamente:\n\n"
                        "a: f e f\n"
                        "b: Lf e Lf\n"
                        "c: d e d\n"
                        "d: Ld e Ld\n"
                        "e: LD e LD");
    strcpy(perg[8].ask, "Acerca de linguagens de programacao e ferramentas de desenvolvimento, julgue o item subsecutivo.\n"
                        "Objective-C, linguagem de programacao que estende a linguagem C, oferece recursos orientados a objetos,"
                        " em que os metodos sao chamados diretamente em um objeto.\n\n"
                        "a: certo\n"
                        "b: errado");
    strcpy(perg[9].ask, "Na linguagem C, o cabecalho de biblioteca stdio.h possui definicoes de subrotinas relativas as operacoes de entrada/saida"
                        " padrao. Uma das funcoes tratadas na biblioteca, associada a esse cabecalho, e a funcao:\n\n"
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
                    fim();
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
                    fim();
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
                    fim();
                    end = 0;
                }
            break; // END CREDITOS
            case 4: // SAIR
                fim();
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
